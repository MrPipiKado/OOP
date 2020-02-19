/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lbResult;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btAnswer;
    QPushButton *btUndo;
    QPushButton *btClear;
    QGridLayout *gridLayout_3;
    QPushButton *btAbs;
    QPushButton *btSin;
    QPushButton *btTan;
    QPushButton *btCot;
    QPushButton *btLog2;
    QPushButton *btLn;
    QPushButton *btPow;
    QPushButton *btSqrt;
    QPushButton *btCos;
    QPushButton *btLog10;
    QGridLayout *gridLayout_2;
    QPushButton *btLeft;
    QPushButton *btMinus;
    QPushButton *btDevide;
    QPushButton *btRight;
    QPushButton *btPlus;
    QPushButton *btMultiplay;
    QGridLayout *gridLayout_4;
    QPushButton *bt4;
    QPushButton *bt5;
    QPushButton *bt1;
    QPushButton *bt9;
    QPushButton *bt2;
    QPushButton *bt8;
    QPushButton *bt6;
    QPushButton *bt3;
    QPushButton *bt7;
    QPushButton *bt0;
    QPushButton *btPoint;
    QPushButton *pbExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(821, 555);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbResult = new QLabel(centralwidget);
        lbResult->setObjectName(QString::fromUtf8("lbResult"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbResult->sizePolicy().hasHeightForWidth());
        lbResult->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(25);
        lbResult->setFont(font);

        verticalLayout->addWidget(lbResult);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btAnswer = new QPushButton(centralwidget);
        btAnswer->setObjectName(QString::fromUtf8("btAnswer"));
        sizePolicy.setHeightForWidth(btAnswer->sizePolicy().hasHeightForWidth());
        btAnswer->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(btAnswer);

        btUndo = new QPushButton(centralwidget);
        btUndo->setObjectName(QString::fromUtf8("btUndo"));
        sizePolicy.setHeightForWidth(btUndo->sizePolicy().hasHeightForWidth());
        btUndo->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(btUndo);

        btClear = new QPushButton(centralwidget);
        btClear->setObjectName(QString::fromUtf8("btClear"));
        sizePolicy.setHeightForWidth(btClear->sizePolicy().hasHeightForWidth());
        btClear->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(btClear);


        gridLayout->addLayout(verticalLayout_3, 1, 6, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btAbs = new QPushButton(centralwidget);
        btAbs->setObjectName(QString::fromUtf8("btAbs"));
        sizePolicy.setHeightForWidth(btAbs->sizePolicy().hasHeightForWidth());
        btAbs->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btAbs, 4, 0, 1, 1);

        btSin = new QPushButton(centralwidget);
        btSin->setObjectName(QString::fromUtf8("btSin"));
        sizePolicy.setHeightForWidth(btSin->sizePolicy().hasHeightForWidth());
        btSin->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btSin, 0, 1, 1, 1);

        btTan = new QPushButton(centralwidget);
        btTan->setObjectName(QString::fromUtf8("btTan"));
        sizePolicy.setHeightForWidth(btTan->sizePolicy().hasHeightForWidth());
        btTan->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btTan, 1, 0, 1, 1);

        btCot = new QPushButton(centralwidget);
        btCot->setObjectName(QString::fromUtf8("btCot"));
        sizePolicy.setHeightForWidth(btCot->sizePolicy().hasHeightForWidth());
        btCot->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btCot, 1, 1, 1, 1);

        btLog2 = new QPushButton(centralwidget);
        btLog2->setObjectName(QString::fromUtf8("btLog2"));
        sizePolicy.setHeightForWidth(btLog2->sizePolicy().hasHeightForWidth());
        btLog2->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btLog2, 3, 1, 1, 1);

        btLn = new QPushButton(centralwidget);
        btLn->setObjectName(QString::fromUtf8("btLn"));
        sizePolicy.setHeightForWidth(btLn->sizePolicy().hasHeightForWidth());
        btLn->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btLn, 2, 0, 1, 1);

        btPow = new QPushButton(centralwidget);
        btPow->setObjectName(QString::fromUtf8("btPow"));
        sizePolicy.setHeightForWidth(btPow->sizePolicy().hasHeightForWidth());
        btPow->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btPow, 2, 1, 1, 1);

        btSqrt = new QPushButton(centralwidget);
        btSqrt->setObjectName(QString::fromUtf8("btSqrt"));
        sizePolicy.setHeightForWidth(btSqrt->sizePolicy().hasHeightForWidth());
        btSqrt->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btSqrt, 4, 1, 1, 1);

        btCos = new QPushButton(centralwidget);
        btCos->setObjectName(QString::fromUtf8("btCos"));
        sizePolicy.setHeightForWidth(btCos->sizePolicy().hasHeightForWidth());
        btCos->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btCos, 0, 0, 1, 1);

        btLog10 = new QPushButton(centralwidget);
        btLog10->setObjectName(QString::fromUtf8("btLog10"));
        sizePolicy.setHeightForWidth(btLog10->sizePolicy().hasHeightForWidth());
        btLog10->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btLog10, 3, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 1, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btLeft = new QPushButton(centralwidget);
        btLeft->setObjectName(QString::fromUtf8("btLeft"));
        sizePolicy.setHeightForWidth(btLeft->sizePolicy().hasHeightForWidth());
        btLeft->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btLeft, 0, 0, 1, 1);

        btMinus = new QPushButton(centralwidget);
        btMinus->setObjectName(QString::fromUtf8("btMinus"));
        sizePolicy.setHeightForWidth(btMinus->sizePolicy().hasHeightForWidth());
        btMinus->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btMinus, 1, 0, 1, 1);

        btDevide = new QPushButton(centralwidget);
        btDevide->setObjectName(QString::fromUtf8("btDevide"));
        sizePolicy.setHeightForWidth(btDevide->sizePolicy().hasHeightForWidth());
        btDevide->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btDevide, 2, 0, 1, 1);

        btRight = new QPushButton(centralwidget);
        btRight->setObjectName(QString::fromUtf8("btRight"));
        sizePolicy.setHeightForWidth(btRight->sizePolicy().hasHeightForWidth());
        btRight->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btRight, 0, 1, 1, 1);

        btPlus = new QPushButton(centralwidget);
        btPlus->setObjectName(QString::fromUtf8("btPlus"));
        sizePolicy.setHeightForWidth(btPlus->sizePolicy().hasHeightForWidth());
        btPlus->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btPlus, 1, 1, 1, 1);

        btMultiplay = new QPushButton(centralwidget);
        btMultiplay->setObjectName(QString::fromUtf8("btMultiplay"));
        sizePolicy.setHeightForWidth(btMultiplay->sizePolicy().hasHeightForWidth());
        btMultiplay->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btMultiplay, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 5, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        bt4 = new QPushButton(centralwidget);
        bt4->setObjectName(QString::fromUtf8("bt4"));
        sizePolicy.setHeightForWidth(bt4->sizePolicy().hasHeightForWidth());
        bt4->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt4, 1, 0, 1, 1);

        bt5 = new QPushButton(centralwidget);
        bt5->setObjectName(QString::fromUtf8("bt5"));
        sizePolicy.setHeightForWidth(bt5->sizePolicy().hasHeightForWidth());
        bt5->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt5, 1, 1, 1, 1);

        bt1 = new QPushButton(centralwidget);
        bt1->setObjectName(QString::fromUtf8("bt1"));
        sizePolicy.setHeightForWidth(bt1->sizePolicy().hasHeightForWidth());
        bt1->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt1, 2, 0, 1, 1);

        bt9 = new QPushButton(centralwidget);
        bt9->setObjectName(QString::fromUtf8("bt9"));
        sizePolicy.setHeightForWidth(bt9->sizePolicy().hasHeightForWidth());
        bt9->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt9, 0, 2, 1, 1);

        bt2 = new QPushButton(centralwidget);
        bt2->setObjectName(QString::fromUtf8("bt2"));
        sizePolicy.setHeightForWidth(bt2->sizePolicy().hasHeightForWidth());
        bt2->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt2, 2, 1, 1, 1);

        bt8 = new QPushButton(centralwidget);
        bt8->setObjectName(QString::fromUtf8("bt8"));
        sizePolicy.setHeightForWidth(bt8->sizePolicy().hasHeightForWidth());
        bt8->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt8, 0, 1, 1, 1);

        bt6 = new QPushButton(centralwidget);
        bt6->setObjectName(QString::fromUtf8("bt6"));
        sizePolicy.setHeightForWidth(bt6->sizePolicy().hasHeightForWidth());
        bt6->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt6, 1, 2, 1, 1);

        bt3 = new QPushButton(centralwidget);
        bt3->setObjectName(QString::fromUtf8("bt3"));
        sizePolicy.setHeightForWidth(bt3->sizePolicy().hasHeightForWidth());
        bt3->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt3, 2, 2, 1, 1);

        bt7 = new QPushButton(centralwidget);
        bt7->setObjectName(QString::fromUtf8("bt7"));
        sizePolicy.setHeightForWidth(bt7->sizePolicy().hasHeightForWidth());
        bt7->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt7, 0, 0, 1, 1);

        bt0 = new QPushButton(centralwidget);
        bt0->setObjectName(QString::fromUtf8("bt0"));
        sizePolicy.setHeightForWidth(bt0->sizePolicy().hasHeightForWidth());
        bt0->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(bt0, 3, 0, 1, 2);

        btPoint = new QPushButton(centralwidget);
        btPoint->setObjectName(QString::fromUtf8("btPoint"));
        sizePolicy.setHeightForWidth(btPoint->sizePolicy().hasHeightForWidth());
        btPoint->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(btPoint, 3, 2, 1, 1);


        gridLayout->addLayout(gridLayout_4, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pbExit = new QPushButton(centralwidget);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));

        verticalLayout->addWidget(pbExit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 821, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbResult->setText(QString());
        btAnswer->setText(QCoreApplication::translate("MainWindow", "ANSWER", nullptr));
        btUndo->setText(QCoreApplication::translate("MainWindow", "UNDO", nullptr));
        btClear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        btAbs->setText(QCoreApplication::translate("MainWindow", "abs(x)", nullptr));
        btSin->setText(QCoreApplication::translate("MainWindow", "sin(x)", nullptr));
        btTan->setText(QCoreApplication::translate("MainWindow", "tan(x)", nullptr));
        btCot->setText(QCoreApplication::translate("MainWindow", "cot(x)", nullptr));
        btLog2->setText(QCoreApplication::translate("MainWindow", "log2(x)", nullptr));
        btLn->setText(QCoreApplication::translate("MainWindow", "ln(x)", nullptr));
        btPow->setText(QCoreApplication::translate("MainWindow", "x^y", nullptr));
        btSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt(x)", nullptr));
        btCos->setText(QCoreApplication::translate("MainWindow", "cos(x)", nullptr));
        btLog10->setText(QCoreApplication::translate("MainWindow", "log10(x)", nullptr));
        btLeft->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        btMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btDevide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btRight->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        btPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btMultiplay->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        bt4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        bt5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        bt1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        bt9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        bt2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        bt8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        bt6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        bt3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        bt7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        bt0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btPoint->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pbExit->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
