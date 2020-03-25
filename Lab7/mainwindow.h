#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"
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
    void on_set_1_clicked();

    void on_set_2_clicked();

    void on_enter_1_clicked();

    void on_enter_2_clicked();

    void on_add_clicked();

    void on_mul_clicked();

    void on_add_num_1_clicked();

    void on_mil_num_1_clicked();

    void on_add_num_2_clicked();

    void on_mul_num_2_clicked();

private:
    Ui::MainWindow *ui;
    Matrix op1;
    Matrix op2;
    Matrix res;
};
#endif // MAINWINDOW_H
