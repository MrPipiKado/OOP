#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include "mypb.h"
#include <QMessageBox>
#include <QImage>
bool MainWindow::is_legal(unsigned int move)
{
    return (board_vect[move]==this->EMPTY);
}

char MainWindow::opponent(char piece)
{
    if(piece==X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

char MainWindow::winner()
{
    const unsigned int WINNING_ROWS[8][3] =
                {
                 {0, 1, 2},
                 {3, 4, 5},
                 {6, 7, 8},
                 {0, 3, 6},
                 {1, 4, 7},
                 {2, 5, 8},
                 {0, 4, 8},
                 {2, 4, 6}
                };
        const unsigned int TOTAL_ROWS = 8;
        for (unsigned int row = 0;row<TOTAL_ROWS; ++row)
        {
            if((board_vect[WINNING_ROWS[row][0]]!=(EMPTY))&&
               (board_vect[WINNING_ROWS[row][0]]==board_vect[WINNING_ROWS[row][1]])&&
               (board_vect[WINNING_ROWS[row][1]]==board_vect[WINNING_ROWS[row][2]]))
            {
                return board_vect[WINNING_ROWS[row][0]];
            }
        }
        if(count(board_vect.begin(), board_vect.end(), EMPTY)==0)
        {
            return TIE;
        }
        return NO_ONE;
}

unsigned int MainWindow::computer_move()
{
    unsigned int move = 0;
        bool found = false;
        while (!found&&(move<board_vect.size()))
        {
            if(is_legal(move))
            {
                board_vect[move] = computer;
                found = winner()==computer;
                board_vect[move] = EMPTY;
            }
            if(!found)
            {
                ++move;
            }
        }

        if(!found)
        {
            move = 0;
            char human = opponent(computer);
            while (!found&&(move<board_vect.size()))
            {
                if(is_legal(move))
                {
                    board_vect[move] = human;
                    found = winner()==human;
                    board_vect[move] = EMPTY;
                }
                if(!found)
                {
                    ++move;
                }
            }
        }

        if(!found)
        {
            move = 0;
            unsigned int i = 0;
            const unsigned int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
            while (!found && i<board_vect.size())
            {
                move = BEST_MOVES[i];
                if(is_legal(move))
                {
                    found = true;
                }
                ++i;
            }
        }
        return move;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->board[0] = ui->label_0;
    this->board[1] = ui->label_1;
    this->board[2] = ui->label_2;
    this->board[3] = ui->label_3;
    this->board[4] = ui->label_4;
    this->board[5] = ui->label_5;
    this->board[6] = ui->label_6;
    this->board[7] = ui->label_7;
    this->board[8] = ui->label_8;
    this->buttons[0] = ui->pushButton_0;
    this->buttons[1] = ui->pushButton_1;
    this->buttons[2] = ui->pushButton_2;
    this->buttons[3] = ui->pushButton_3;
    this->buttons[4] = ui->pushButton_4;
    this->buttons[5] = ui->pushButton_5;
    this->buttons[6] = ui->pushButton_6;
    this->buttons[7] = ui->pushButton_7;
    this->buttons[8] = ui->pushButton_8;

    this->ui->line->setVisible(false);
    this->ui->line_2->setVisible(false);
    this->ui->line_3->setVisible(false);
    this->ui->line_4->setVisible(false);
    this->ui->line_5->setVisible(false);
    this->ui->line_6->setVisible(false);
    this->ui->line_7->setVisible(false);
    this->ui->line_8->setVisible(false);
    this->ui->line_9->setVisible(false);
    this->ui->line_10->setVisible(false);
    this->ui->line_11->setVisible(false);
    this->ui->line_12->setVisible(false);
    for(int i = 0; i<9; ++i)
    {
        buttons[i]->setVisible(false);
        board[i]->setVisible(false);
        buttons[i]->number = i;
        connect(this->buttons[i], SIGNAL(clicked()), this, SLOT(label_clicked()));
    }
    connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int MainWindow::label_clicked()
{
    bool human_move = false;
    QImage image;
    MYPB *button = (MYPB*)sender();
    button->setVisible(false);
    unsigned int move = button->number;
    board[move]->setVisible(true);
                    if(is_legal(move))
                    {
                        board_vect[move] = human;
                        if(human==O)
                            image.load(":/Images/Zero.png");
                        else
                            image.load(":/Images/Cross.png");

                        image = image.scaledToWidth(board[move]->width(), Qt::SmoothTransformation);
                        board[move]->setPixmap(QPixmap::fromImage(image));
                        human_move = true;
                    }
                    else
                    {
                        return 2;
                    }
                    if (winner()==human)
                    {
                        QMessageBox::StandardButton resBtn =
                        QMessageBox::question( this, "WINNER",
                                               tr( "You win\n"
                                                   "Do you want to play again?\n"),
                                               QMessageBox::Yes | QMessageBox::No,
                                               QMessageBox::Yes);
                        if (resBtn == QMessageBox::No)
                        {
                            this->close();
                        }
                        else if(resBtn == QMessageBox::Yes)
                        {
                            start();
                            return 2;
                        }

                    }
                    else if(winner()==computer)
                         {
                              QMessageBox::StandardButton resBtn =
                              QMessageBox::question( this, "WINNER",
                                             tr( "Computer wins\n"
                                             "Do you want to play again?\n"),
                                             QMessageBox::Yes | QMessageBox::No,
                                             QMessageBox::Yes);
                                    if (resBtn == QMessageBox::No)
                                    {
                                        this->close();
                                    }
                                    else if(resBtn == QMessageBox::Yes)
                                    {
                                        start();
                                        return 2;
                                    }
                           }
                    else if(winner()==TIE)
                           {
                                    QMessageBox::StandardButton resBtn =
                                    QMessageBox::question( this, "TIE",
                                                           tr( "It's a tie\n"
                                                               "Do you want to play again?\n"),
                                                           QMessageBox::Yes | QMessageBox::No,
                                                           QMessageBox::Yes);
                                    if (resBtn == QMessageBox::No)
                                    {
                                        this->close();
                                    }
                                    else if(resBtn == QMessageBox::Yes)
                                    {
                                        start();
                                        return 2;
                                    }
                    }
                    if(human_move)
                    {
                        move = computer_move();
                        board_vect[move] = computer;
                        if(computer==O)
                            image.load(":/Images/Zero.png");
                        else
                            image.load(":/Images/Cross.png");
                        buttons[move]->setVisible(false);
                        board[move]->setVisible(true);
                        image = image.scaledToWidth(board[move]->width(), Qt::SmoothTransformation);
                        board[move]->setPixmap(QPixmap::fromImage(image));
                        if(winner()==computer)
                        {
                             QMessageBox::StandardButton resBtn =
                                     QMessageBox::question( this, "WINNER",
                                                   tr( "Computer wins\n"
                                                       "Do you want to play again?\n"),
                                                   QMessageBox::Yes | QMessageBox::No,
                                                   QMessageBox::Yes);
                            if (resBtn == QMessageBox::No)
                            {
                                this->close();
                            }
                            else if(resBtn == QMessageBox::Yes)
                            {
                                start();
                                return 2;
                            }
                        }else if(winner()==TIE)
                        {
                            QMessageBox::StandardButton resBtn =
                            QMessageBox::question( this, "TIE",
                                                   tr( "It's a tie\n"
                                                       "Do you want to play again?\n"),
                                                   QMessageBox::Yes | QMessageBox::No,
                                                   QMessageBox::Yes);
                            if (resBtn == QMessageBox::No)
                            {
                                this->close();
                            }
                            else if(resBtn == QMessageBox::Yes)
                            {
                                start();
                                return 2;
                            }
                        }
                    }

}

void MainWindow::start()
{
    if(this->ui->pushButton->isVisible())
    {
        this->ui->pushButton->setVisible(false);
        this->ui->line->setVisible(true);
        this->ui->line_2->setVisible(true);
        this->ui->line_3->setVisible(true);
        this->ui->line_4->setVisible(true);
        this->ui->line_5->setVisible(true);
        this->ui->line_6->setVisible(true);
        this->ui->line_7->setVisible(true);
        this->ui->line_8->setVisible(true);
        this->ui->line_9->setVisible(true);
        this->ui->line_10->setVisible(true);
        this->ui->line_11->setVisible(true);
        this->ui->line_12->setVisible(true);
    }

    board_vect.clear();
    for(int i = 0; i<9; ++i)
    {
        board[i]->setVisible(false);
        buttons[i]->setVisible(true);
    }
    QImage image;
    image.load(":/Images/Square.png");
    for(int i = 0; i<9; ++i)
    {

        board_vect.push_back(' ');
        image = image.scaledToWidth(board[i]->width(), Qt::SmoothTransformation);
        board[i]->setPixmap(QPixmap::fromImage(image));
        connect(this->buttons[i], SIGNAL(clicked()), this, SLOT(label_clicked()));
    }
        QMessageBox::StandardButton resBtn =
                QMessageBox::question( this, "Hello",
                                       tr("Do you require the first move?\n"),
                                       QMessageBox::Yes | QMessageBox::No,
                                       QMessageBox::Yes);
        if (resBtn == QMessageBox::No)
        {
            unsigned int move;
            QImage image;
            human = O;
            computer = X;
            move = computer_move();
            board[move]->setVisible(true);
            buttons[move]->setVisible(false);
            board_vect[move] = computer;
            image.load(":/Images/Cross.png");
            image = image.scaledToWidth(board[move]->width(), Qt::SmoothTransformation);
            board[move]->setPixmap(QPixmap::fromImage(image));
        }
        else if(resBtn == QMessageBox::Yes)
        {
            human = X;
            computer = O;   
        }
}
