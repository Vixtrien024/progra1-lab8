/********************************************************************************
** Form generated from reading UI file 'lab8.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB8_H
#define UI_LAB8_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab8Class
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *lab8Class)
    {
        if (lab8Class->objectName().isEmpty())
            lab8Class->setObjectName("lab8Class");
        lab8Class->resize(600, 400);
        centralwidget = new QWidget(lab8Class);
        centralwidget->setObjectName("centralwidget");
        lab8Class->setCentralWidget(centralwidget);
        menubar = new QMenuBar(lab8Class);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 21));
        lab8Class->setMenuBar(menubar);
        toolBar = new QToolBar(lab8Class);
        toolBar->setObjectName("toolBar");
        lab8Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(lab8Class);
        statusbar->setObjectName("statusbar");
        lab8Class->setStatusBar(statusbar);

        retranslateUi(lab8Class);

        QMetaObject::connectSlotsByName(lab8Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab8Class)
    {
        lab8Class->setWindowTitle(QCoreApplication::translate("lab8Class", "lab8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab8Class: public Ui_lab8Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB8_H
