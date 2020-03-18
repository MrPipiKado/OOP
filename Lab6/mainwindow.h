#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mycomplex.h"
#include "mylineedit.h"
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

    void on_add_clicked();

    void on_sub_clicked();

    void on_mul_clicked();

    void on_div_clicked();

    void on_pow_1_clicked();

    void on_algebra_1_clicked();

    void on_trigono_1_clicked();

    void on_algebra_2_clicked();

    void on_trigonom_2_clicked();

    void on_algebrs_3_clicked();

    void on_trigonom_3_clicked();

    void on_root_1_clicked();

    void on_pow_2_clicked();

    void on_root_2_clicked();

    void on_compare_clicked();

private:
    Ui::MainWindow *ui;
    Complex op1;
    Complex op2;
    Complex res;
};
#endif // MAINWINDOW_H
