/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionStart;
    QWidget *centralWidget;
    QSlider *slider;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QFrame *line;
    QLabel *label2;
    QFrame *line_2;
    QLabel *label3;
    QLabel *label_3;
    QLabel *calTime;
    QSlider *morphslider;
    QSlider *errodslider;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1197, 588);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        slider = new QSlider(centralWidget);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setGeometry(QRect(10, 400, 1161, 61));
        slider->setValue(0);
        slider->setOrientation(Qt::Horizontal);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 60, 1191, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(horizontalLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));
        QFont font;
        font.setPointSize(16);
        label1->setFont(font);
        label1->setLayoutDirection(Qt::LeftToRight);
        label1->setFrameShape(QFrame::NoFrame);
        label1->setScaledContents(true);
        label1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label1);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label2 = new QLabel(horizontalLayoutWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setFont(font);
        label2->setFrameShape(QFrame::NoFrame);
        label2->setScaledContents(true);
        label2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label2);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        label3 = new QLabel(horizontalLayoutWidget);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setFont(font);
        label3->setMouseTracking(true);
        label3->setAutoFillBackground(false);
        label3->setFrameShape(QFrame::NoFrame);
        label3->setLineWidth(1);
        label3->setScaledContents(true);
        label3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label3);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 900, 231, 41));
        calTime = new QLabel(centralWidget);
        calTime->setObjectName(QStringLiteral("calTime"));
        calTime->setGeometry(QRect(260, 910, 241, 25));
        morphslider = new QSlider(centralWidget);
        morphslider->setObjectName(QStringLiteral("morphslider"));
        morphslider->setGeometry(QRect(20, 480, 160, 22));
        morphslider->setMaximum(20);
        morphslider->setOrientation(Qt::Horizontal);
        errodslider = new QSlider(centralWidget);
        errodslider->setObjectName(QStringLiteral("errodslider"));
        errodslider->setGeometry(QRect(1010, 470, 160, 22));
        errodslider->setMaximum(20);
        errodslider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 1201, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::Panel);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 460, 131, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 460, 121, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1050, 500, 81, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 510, 81, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1197, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionStart);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
        label1->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Input Video</span></p></body></html>", 0));
        label2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Filtered Video</span></p></body></html>", 0));
#ifndef QT_NO_ACCESSIBILITY
        label3->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        label3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Output Video</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "CalculationTime/frame", 0));
        calTime->setText(QApplication::translate("MainWindow", "time", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">Pedestrian detection System</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Open", 0));
        label_2->setText(QApplication::translate("MainWindow", "filtering type 2", 0));
        label_4->setText(QApplication::translate("MainWindow", "filtering type 1", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
