/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jun 7 17:07:27 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionAdd_File;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *action_Exit;
    QAction *action_Play_Pause;
    QAction *actionSkip_Forward;
    QAction *actionSkip_Backward;
    QAction *action_Stop;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menu_Controls;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(600, 400);
        MainWindowClass->setWindowTitle(QString::fromUtf8("ACDJ"));
        MainWindowClass->setUnifiedTitleAndToolBarOnMac(false);
        actionAdd_File = new QAction(MainWindowClass);
        actionAdd_File->setObjectName(QString::fromUtf8("actionAdd_File"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHelp = new QAction(MainWindowClass);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        action_Exit = new QAction(MainWindowClass);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Play_Pause = new QAction(MainWindowClass);
        action_Play_Pause->setObjectName(QString::fromUtf8("action_Play_Pause"));
        actionSkip_Forward = new QAction(MainWindowClass);
        actionSkip_Forward->setObjectName(QString::fromUtf8("actionSkip_Forward"));
        actionSkip_Backward = new QAction(MainWindowClass);
        actionSkip_Backward->setObjectName(QString::fromUtf8("actionSkip_Backward"));
        action_Stop = new QAction(MainWindowClass);
        action_Stop->setObjectName(QString::fromUtf8("action_Stop"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menu_Controls = new QMenu(menuBar);
        menu_Controls->setObjectName(QString::fromUtf8("menu_Controls"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu_Controls->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionAdd_File);
        menuFile->addAction(action_Exit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);
        menu_Controls->addAction(action_Play_Pause);
        menu_Controls->addAction(actionSkip_Forward);
        menu_Controls->addAction(actionSkip_Backward);
        menu_Controls->addAction(action_Stop);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        actionAdd_File->setText(QApplication::translate("MainWindowClass", "Add File", 0, QApplication::UnicodeUTF8));
        actionAdd_File->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowClass", "&About", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindowClass", "&Help", 0, QApplication::UnicodeUTF8));
        action_Exit->setText(QApplication::translate("MainWindowClass", "E&xit", 0, QApplication::UnicodeUTF8));
        action_Exit->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Play_Pause->setText(QApplication::translate("MainWindowClass", "&Play / Pause", 0, QApplication::UnicodeUTF8));
        action_Play_Pause->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionSkip_Forward->setText(QApplication::translate("MainWindowClass", "Skip &Forward", 0, QApplication::UnicodeUTF8));
        actionSkip_Forward->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionSkip_Backward->setText(QApplication::translate("MainWindowClass", "Skip &Backward", 0, QApplication::UnicodeUTF8));
        actionSkip_Backward->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        action_Stop->setText(QApplication::translate("MainWindowClass", "&Stop", 0, QApplication::UnicodeUTF8));
        action_Stop->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "&File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "&Help", 0, QApplication::UnicodeUTF8));
        menu_Controls->setTitle(QApplication::translate("MainWindowClass", "&Controls", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindowClass);
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
