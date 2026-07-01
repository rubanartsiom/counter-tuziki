/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *nextWordButton;
    QLabel *label;
    QPushButton *randomPoemButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(950, 801);
        MainWindow->setMaximumSize(QSize(1000, 1000));
        QIcon icon;
        icon.addFile(QString::fromUtf8("build/Desktop_Qt_6_11_0_MinGW_64_bit-u041eu0442u043bu0430u0434u043au0430/debug/\320\274\320\265\320\273\320\273\321\201\321\202\321\200\320\276\320\271.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(130, 80, 700, 601));
        graphicsView->setMaximumSize(QSize(700, 700));
        nextWordButton = new QPushButton(centralwidget);
        nextWordButton->setObjectName("nextWordButton");
        nextWordButton->setGeometry(QRect(600, 680, 231, 71));
        QFont font;
        font.setPointSize(20);
        nextWordButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 20, 431, 51));
        QFont font1;
        font1.setPointSize(24);
        label->setFont(font1);
        randomPoemButton = new QPushButton(centralwidget);
        randomPoemButton->setObjectName("randomPoemButton");
        randomPoemButton->setGeometry(QRect(10, 30, 161, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 950, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\320\225\320\233\320\230\320\232\320\220\320\257 \320\241\320\247\320\230\320\242\320\220\320\233\320\236\320\247\320\232\320\220 \320\240\320\243\320\221\320\220\320\235\320\220", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        nextWordButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        label->setText(QString());
        randomPoemButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\203\321\216\n"
"\320\241\320\247\320\230\320\242\320\220\320\233\320\232\320\243", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
