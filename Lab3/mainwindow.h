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
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_actionOpen_file_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionNew_file_triggered();

    void change_headler();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionChange_Mode_triggered();

    void on_actionFind_triggered();

    void on_actionChange_font_triggered();

private:
    Ui::MainWindow *ui;
    QString file_name;
    enum MODES {TEXT, IMAGE};
    bool isSaved;
    QImage image;
    MODES mode;
    bool isFirstTime;
};
#endif // MAINWINDOW_H
