/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *ECGBASE;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *loECGBaseline;
    QWidget *RPEAKS;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *loRpeaks;
    QWidget *HRV1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *lo_HRV1;
    QWidget *HRV2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *lo_HRV2;
    QWidget *HRF_DFA;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *loHRVdfa;
    QWidget *ST_SEGMENT;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *loSTSegment;
    QWidget *HEART_CLASS;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *loHeartClass;
    QWidget *T_WAVE_ALT;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *loTAltClass;
    QWidget *layoutWidget;
    QHBoxLayout *lo_patients_data;
    QLabel *label_age;
    QLineEdit *lE_age;
    QLabel *label_gender;
    QLineEdit *lE_gender;
    QPushButton *pushButton_report;
    QMenuBar *menuBar;
    QMenu *menuSignal;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(1024, 713);
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/images/Images/ECG-img.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainView->setWindowIcon(icon);
        actionOpen = new QAction(MainView);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainView);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(false);
        tabWidget->setGeometry(QRect(10, 40, 1001, 621));
        ECGBASE = new QWidget();
        ECGBASE->setObjectName(QStringLiteral("ECGBASE"));
        verticalLayoutWidget_4 = new QWidget(ECGBASE);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 971, 581));
        loECGBaseline = new QVBoxLayout(verticalLayoutWidget_4);
        loECGBaseline->setSpacing(6);
        loECGBaseline->setContentsMargins(11, 11, 11, 11);
        loECGBaseline->setObjectName(QStringLiteral("loECGBaseline"));
        loECGBaseline->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(ECGBASE, QString());
        RPEAKS = new QWidget();
        RPEAKS->setObjectName(QStringLiteral("RPEAKS"));
        verticalLayoutWidget_6 = new QWidget(RPEAKS);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 10, 971, 571));
        loRpeaks = new QVBoxLayout(verticalLayoutWidget_6);
        loRpeaks->setSpacing(6);
        loRpeaks->setContentsMargins(11, 11, 11, 11);
        loRpeaks->setObjectName(QStringLiteral("loRpeaks"));
        loRpeaks->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(RPEAKS, QString());
        HRV1 = new QWidget();
        HRV1->setObjectName(QStringLiteral("HRV1"));
        verticalLayoutWidget = new QWidget(HRV1);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 971, 571));
        lo_HRV1 = new QVBoxLayout(verticalLayoutWidget);
        lo_HRV1->setSpacing(6);
        lo_HRV1->setContentsMargins(11, 11, 11, 11);
        lo_HRV1->setObjectName(QStringLiteral("lo_HRV1"));
        lo_HRV1->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(HRV1, QString());
        HRV2 = new QWidget();
        HRV2->setObjectName(QStringLiteral("HRV2"));
        verticalLayoutWidget_2 = new QWidget(HRV2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 971, 571));
        lo_HRV2 = new QVBoxLayout(verticalLayoutWidget_2);
        lo_HRV2->setSpacing(6);
        lo_HRV2->setContentsMargins(11, 11, 11, 11);
        lo_HRV2->setObjectName(QStringLiteral("lo_HRV2"));
        lo_HRV2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(HRV2, QString());
        HRF_DFA = new QWidget();
        HRF_DFA->setObjectName(QStringLiteral("HRF_DFA"));
        verticalLayoutWidget_5 = new QWidget(HRF_DFA);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 971, 581));
        loHRVdfa = new QVBoxLayout(verticalLayoutWidget_5);
        loHRVdfa->setSpacing(6);
        loHRVdfa->setContentsMargins(11, 11, 11, 11);
        loHRVdfa->setObjectName(QStringLiteral("loHRVdfa"));
        loHRVdfa->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(HRF_DFA, QString());
        ST_SEGMENT = new QWidget();
        ST_SEGMENT->setObjectName(QStringLiteral("ST_SEGMENT"));
        verticalLayoutWidget_3 = new QWidget(ST_SEGMENT);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 971, 571));
        loSTSegment = new QVBoxLayout(verticalLayoutWidget_3);
        loSTSegment->setSpacing(6);
        loSTSegment->setContentsMargins(11, 11, 11, 11);
        loSTSegment->setObjectName(QStringLiteral("loSTSegment"));
        loSTSegment->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(ST_SEGMENT, QString());
        HEART_CLASS = new QWidget();
        HEART_CLASS->setObjectName(QStringLiteral("HEART_CLASS"));
        horizontalLayout_2 = new QHBoxLayout(HEART_CLASS);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loHeartClass = new QVBoxLayout();
        loHeartClass->setSpacing(6);
        loHeartClass->setObjectName(QStringLiteral("loHeartClass"));

        horizontalLayout_2->addLayout(loHeartClass);

        tabWidget->addTab(HEART_CLASS, QString());
        T_WAVE_ALT = new QWidget();
        T_WAVE_ALT->setObjectName(QStringLiteral("T_WAVE_ALT"));
        horizontalLayout_4 = new QHBoxLayout(T_WAVE_ALT);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        loTAltClass = new QHBoxLayout();
        loTAltClass->setSpacing(6);
        loTAltClass->setObjectName(QStringLiteral("loTAltClass"));

        horizontalLayout_4->addLayout(loTAltClass);

        tabWidget->addTab(T_WAVE_ALT, QString());
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 201, 22));
        lo_patients_data = new QHBoxLayout(layoutWidget);
        lo_patients_data->setSpacing(6);
        lo_patients_data->setContentsMargins(11, 11, 11, 11);
        lo_patients_data->setObjectName(QStringLiteral("lo_patients_data"));
        lo_patients_data->setContentsMargins(0, 0, 0, 0);
        label_age = new QLabel(layoutWidget);
        label_age->setObjectName(QStringLiteral("label_age"));

        lo_patients_data->addWidget(label_age);

        lE_age = new QLineEdit(layoutWidget);
        lE_age->setObjectName(QStringLiteral("lE_age"));
        lE_age->setEnabled(false);

        lo_patients_data->addWidget(lE_age);

        label_gender = new QLabel(layoutWidget);
        label_gender->setObjectName(QStringLiteral("label_gender"));

        lo_patients_data->addWidget(label_gender);

        lE_gender = new QLineEdit(layoutWidget);
        lE_gender->setObjectName(QStringLiteral("lE_gender"));
        lE_gender->setEnabled(false);

        lo_patients_data->addWidget(lE_gender);

        pushButton_report = new QPushButton(centralWidget);
        pushButton_report->setObjectName(QStringLiteral("pushButton_report"));
        pushButton_report->setGeometry(QRect(910, 10, 75, 23));
        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuSignal = new QMenu(menuBar);
        menuSignal->setObjectName(QStringLiteral("menuSignal"));
        MainView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainView->setStatusBar(statusBar);

        menuBar->addAction(menuSignal->menuAction());
        menuSignal->addAction(actionOpen);
        menuSignal->addAction(actionExit);

        retranslateUi(MainView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "Front Panel Controller", nullptr));
        actionOpen->setText(QApplication::translate("MainView", "Open", nullptr));
        actionExit->setText(QApplication::translate("MainView", "Exit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ECGBASE), QApplication::translate("MainView", "ECG Baseline", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RPEAKS), QApplication::translate("MainView", "R-peaks", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRV1), QApplication::translate("MainView", "HRV 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRV2), QApplication::translate("MainView", "HRV 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRF_DFA), QApplication::translate("MainView", "HRV DFA", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ST_SEGMENT), QApplication::translate("MainView", "ST Segment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HEART_CLASS), QApplication::translate("MainView", "Heart Class", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(T_WAVE_ALT), QApplication::translate("MainView", "T Wave Alt", nullptr));
        label_age->setText(QApplication::translate("MainView", "Age", nullptr));
        label_gender->setText(QApplication::translate("MainView", "Gender", nullptr));
        pushButton_report->setText(QApplication::translate("MainView", "Report", nullptr));
        menuSignal->setTitle(QApplication::translate("MainView", "Signal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
