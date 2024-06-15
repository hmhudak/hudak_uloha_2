/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonFactorial;
    QProgressBar *progressFactorial;
    QPushButton *buttonPrimes;
    QProgressBar *progressPrimes;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        buttonFactorial = new QPushButton(centralwidget);
        buttonFactorial->setObjectName("buttonFactorial");

        verticalLayout->addWidget(buttonFactorial);

        progressFactorial = new QProgressBar(centralwidget);
        progressFactorial->setObjectName("progressFactorial");
        progressFactorial->setMinimum(0);
        progressFactorial->setMaximum(100);
        progressFactorial->setValue(0);

        verticalLayout->addWidget(progressFactorial);

        buttonPrimes = new QPushButton(centralwidget);
        buttonPrimes->setObjectName("buttonPrimes");

        verticalLayout->addWidget(buttonPrimes);

        progressPrimes = new QProgressBar(centralwidget);
        progressPrimes->setObjectName("progressPrimes");
        progressPrimes->setMinimum(0);
        progressPrimes->setMaximum(100);
        progressPrimes->setValue(0);

        verticalLayout->addWidget(progressPrimes);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonFactorial->setText(QCoreApplication::translate("MainWindow", "Start Factorial Calculation", nullptr));
        buttonPrimes->setText(QCoreApplication::translate("MainWindow", "Start Primes Calculation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
