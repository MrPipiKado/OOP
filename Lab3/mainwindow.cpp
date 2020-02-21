#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QCloseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isSaved = true;
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(change_headler()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{    
    QString file = QFileDialog::getOpenFileName(this,
            tr("Open File"));
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
        }
        else
        {
            QMessageBox::information(this, tr("Unable to open file"),
            FILE.errorString());
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
    }
    else
    {
        QMessageBox::information(this, tr("It is new file, try save as"), "ERROR");
    }
}

void MainWindow::on_actionNew_file_triggered()
{
    this->file_name = "";
    this->ui->textEdit->setPlainText("");

}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,
            tr("Open File"));
    if (!file.isEmpty())
    {
        this->file_name = file;
        on_actionSave_triggered();
    }
}

void MainWindow::change_headler()
{
    this->isSaved = false;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!this->isSaved)
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "NotePade",
                                                                tr("Exit without saving?\n"),
                                                                QMessageBox::Cancel | QMessageBox::Save | QMessageBox::Yes,
                                                                QMessageBox::Save);
        if (resBtn == QMessageBox::No)
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
