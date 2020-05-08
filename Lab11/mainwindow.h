#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <list>
#include <deque>
#include <vector>
#include <algorithm>

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
    void on_spin_A_valueChanged(int arg1);

    void on_spin_B_valueChanged(int arg1);

    void on_set_A_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_set_B_clicked();

    void on_insert_clicked();

    void on_sort_A_clicked();

    void on_pushButton_3_clicked();

    void on_fillC_clicked();

    void on_sort_A_2_clicked();

    void on_sort_C_clicked();

    void on_merge_clicked();

    void on_pushButton_4_clicked();

private:
    std::list<int> *A;
    std::list<int> *B;
    std::deque<int> *C;
    std::vector<int> *D;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
