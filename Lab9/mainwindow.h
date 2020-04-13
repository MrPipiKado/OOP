#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "account.h"
#include <QMainWindow>

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
    void on_set_clicked();

private:
    Ui::MainWindow *ui;
    Account *buffer[3];
};
#endif // MAINWINDOW_H
