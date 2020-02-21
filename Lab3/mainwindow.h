#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

private slots:
    void on_actionOpen_file_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionNew_file_triggered();

private:
    Ui::MainWindow *ui;
    QString file_name;
};
#endif // MAINWINDOW_H
