#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
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
    void event_headler();
    void undo();
    void answer();
    void clear();
    void unar_func_h();
    void exit();

private:
    std::string result;
    QString toShow;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
