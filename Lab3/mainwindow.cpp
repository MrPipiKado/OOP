#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QCloseEvent>
#include <QImage>
#include <QPixmap>
#include <QInputDialog>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isSaved = true;
    file_name = "";
    setWindowTitle("Simple Editor");

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(change_headler()));
    ui->Image->setVisible(false);
    this->ui->actionSave->setEnabled(false);
    this->ui->statusbar->showMessage("Text mode");
    mode = TEXT;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionOpen_file_triggered()
{
    if(!this->isSaved)
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Simple Editor",
                                                                tr("Continue without saving?\n"),
                                                                QMessageBox::Save | QMessageBox::Yes,
                                                                QMessageBox::Save);
       if(resBtn == QMessageBox::Save)
        {
            this->on_actionSave_as_triggered();
        }
       else
           QApplication::quit();

    }
    if(this->mode==TEXT)
    {
        QString file = QFileDialog::getOpenFileName(this,
                tr("Open File"),"/home", "Text file(*.txt)");
        if (!file.isEmpty())
        {
            QFile FILE(file);
            if(FILE.open(QFile::ReadOnly | QFile::Text))
            {
                this->file_name = file;
                QTextStream input(&FILE);
                QString text = input.readAll();
                this->ui->textEdit->setPlainText(text);
                FILE.close();
                this->ui->actionSave->setEnabled(true);
                this->setWindowTitle(this->file_name);
            }
            else
            {
                QMessageBox::information(this, tr("Unable to open file"),
                FILE.errorString());
                return;
            }
        }
    }
    else
    {
        QString file = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),"/home",
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
        if(!file.isEmpty())
        {
            bool valid = image.load(file);
            if(valid)
            {
                image = image.scaledToWidth(ui->Image->width(), Qt::SmoothTransformation);
                ui->Image->setPixmap(QPixmap::fromImage(image));
            }
        }
        else
        {
            QMessageBox::information(this, tr("Unable to open file"),
            file);
            return;
        }
    }

}

void MainWindow::on_actionSave_triggered()
{
    QFile FILE(this->file_name);
    if(FILE.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream output(&FILE);
        output << ui->textEdit->toPlainText();
        FILE.flush();
        FILE.close();

        this->setWindowTitle(this->file_name);
        this->isSaved = true;
    }
    else
    {
        QMessageBox::information(this, tr("It is new file, try save as"), "ERROR");
    }
}

void MainWindow::on_actionNew_file_triggered()
{

    this->file_name = "New.txt";
    this->ui->textEdit->setPlainText("");
    this->setWindowTitle(this->file_name);
    this->ui->actionSave->setEnabled(false);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,
            tr("Open File"));
    if (!file.isEmpty())
    {
        if(mode==TEXT)
        {
            this->file_name = file;
            on_actionSave_triggered();
        }
        else
        {
            image.save(file);
        }
    }
    this->setWindowTitle(this->file_name);
}

void MainWindow::change_headler()
{
    this->isSaved = false;
    this->setWindowTitle((this->file_name + "*"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!this->isSaved)
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Simple Editor",
                                                                tr("Exit without saving?\n"),
                                                                QMessageBox::Cancel | QMessageBox::Save | QMessageBox::Yes,
                                                                QMessageBox::Save);
        if (resBtn == QMessageBox::Cancel)
        {
            event->ignore();
        }
        else if(resBtn == QMessageBox::Save)
        {
            this->on_actionSave_as_triggered();
            event->accept();
        }
        else
        {
            event->accept();
        }
    }
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this, "Help", "\"New file\" Ctrl+N to create new\n"
                             "\"Open file\" Ctrl+O to open file\n"
                             "\"Save\" Ctrl+S to save with current name\n"
                             "\"Save as\" Ctrl+Shift+S to save file in a different location\n"
                             "\"Find\" Ctrl+F to find word or sentence in the text\n"
                             "\"Change mode\" Ctrl+Shift+A switch to other mode\n"
                             "\"About\" Ctrl+A information about product and developer\n");
}

void MainWindow::on_actionAbout_triggered()
{
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();

}

void MainWindow::on_actionCopy_triggered()
{
    this->ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    this->ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    this->ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    this->ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    this->ui->textEdit->redo();
}

void MainWindow::on_actionChange_Mode_triggered()
{
    if(this->ui->textEdit->isVisible())
    {
        this->ui->textEdit->setVisible(false);
        this->ui->Image->setVisible(true);
        this->ui->actionNew_file->setEnabled(false);
        this->ui->actionCut->setEnabled(false);
        this->ui->actionCopy->setEnabled(false);
        this->ui->actionPaste->setEnabled(false);
        this->ui->actionUndo->setEnabled(false);
        this->ui->actionRedo->setEnabled(false);
        this->ui->actionFind->setEnabled(false);
        this->ui->actionSave->setEnabled(true);
        this->mode = IMAGE;
        this->ui->statusbar->showMessage("Image mode");
    }
    else
    {
        this->ui->textEdit->setVisible(true);
        this->ui->Image->setVisible(false);
        this->ui->actionNew_file->setEnabled(true);
        this->ui->actionCut->setEnabled(true);
        this->ui->actionCopy->setEnabled(true);
        this->ui->actionPaste->setEnabled(true);
        this->ui->actionUndo->setEnabled(true);
        this->ui->actionRedo->setEnabled(true);
        this->ui->actionFind->setEnabled(true);
        this->ui->actionSave->setEnabled(false);
        this->mode = TEXT;
        this->ui->statusbar->showMessage("Text mode");
    }
}

void MainWindow::on_actionFind_triggered()
{
    QString search = QInputDialog::getText(this, "Find in text", "Value:");
    QTextDocument *document = ui->textEdit->document();

    bool found = false;

    if (isFirstTime == false)
         document->undo();
    if (search.isEmpty())
    {
        QMessageBox::information(this, tr("Empty Search Field"),
            "The search field is empty.");
    }
    else
    {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd())
        {
            highlightCursor = document->find(search, highlightCursor, QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull())
            {
                 found = true;
                 highlightCursor.movePosition(QTextCursor::WordRight,
                                              QTextCursor::KeepAnchor);
                 highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        isFirstTime = false;

        if (found == false)
        {
            QMessageBox::information(this, tr("Word Not Found"),
                       "No maching.");
        }
    }
}
