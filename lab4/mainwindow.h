#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <vector>
#include "mylabel.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    unsigned int label_clicked();

    void start();

private:
    Ui::MainWindow *ui;
    MyLabel *board[9];
    vector<char> board_vect;
    char human;
    char computer;
    char turn;
    bool want_to_play;
    char winner();
    inline bool is_legal(unsigned int);
    inline char opponent(char);
    unsigned int computer_move();

    const char X = 'X';
    const char O = 'O';
    const char EMPTY = ' ';
    const char TIE = 'T';
    const char NO_ONE = 'N';
    const unsigned int NUM_SQUARES = 9;
};
#endif // MAINWINDOW_H
