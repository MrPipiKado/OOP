#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "set.h"
#include "complex.h"
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
    void on_num_a_valueChanged(int arg1);

    void on_num_b_valueChanged(int arg1);

    void on_set_a_clicked();

    void on_set_b_clicked();

    void on_plus_clicked();

    void on_pushButton_5_clicked();

    void on_div_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    SET::Set<Complex> *A;
    SET::Set<Complex> *B;
    SET::Set<Complex> *R;
};
#endif // MAINWINDOW_H
