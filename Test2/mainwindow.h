#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <iterator>
#include <QMainWindow>
#include <string>
using namespace std;

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
    void on_actiontools_triggered();

    void on_actionKeep_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_lineEdit_customContextMenuRequested(const QPoint &pos);

public slots:

        void contextMenuEvent(QContextMenuEvent *event);
private:
    Ui::MainWindow *ui;

    vector<string> buffer;
    int current;
};
#endif // MAINWINDOW_H
