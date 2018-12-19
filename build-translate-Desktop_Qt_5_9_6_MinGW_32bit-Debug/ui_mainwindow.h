/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiontranslate;
    QAction *actionexit;
    QWidget *centralWidget;
    QTextEdit *textInput;
    QTextEdit *textOutput;
    QPushButton *ButtonTranslate;
    QComboBox *comboBox;
    QPushButton *buttonEmpty;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(508, 336);
        actiontranslate = new QAction(MainWindow);
        actiontranslate->setObjectName(QStringLiteral("actiontranslate"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textInput = new QTextEdit(centralWidget);
        textInput->setObjectName(QStringLiteral("textInput"));
        textInput->setGeometry(QRect(20, 10, 461, 61));
        textOutput = new QTextEdit(centralWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(20, 110, 461, 201));
        ButtonTranslate = new QPushButton(centralWidget);
        ButtonTranslate->setObjectName(QStringLiteral("ButtonTranslate"));
        ButtonTranslate->setGeometry(QRect(400, 80, 81, 21));
        ButtonTranslate->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/translate.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonTranslate->setIcon(icon);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 80, 81, 21));
        buttonEmpty = new QPushButton(centralWidget);
        buttonEmpty->setObjectName(QStringLiteral("buttonEmpty"));
        buttonEmpty->setGeometry(QRect(310, 80, 81, 21));
        buttonEmpty->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actiontranslate->setText(QApplication::translate("MainWindow", "translate", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        textInput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        textOutput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        ButtonTranslate->setText(QApplication::translate("MainWindow", "\347\277\273\350\257\221", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\350\213\261 -> \344\270\255", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\255 -> \350\213\261", Q_NULLPTR)
        );
        buttonEmpty->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
