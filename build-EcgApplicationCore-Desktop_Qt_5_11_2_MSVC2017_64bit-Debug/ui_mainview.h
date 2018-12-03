/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(751, 385);
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/images/Images/ECG-img.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainView->setWindowIcon(icon);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        ECGBASE = new QWidget();
        ECGBASE->setObjectName(QStringLiteral("ECGBASE"));
        verticalLayoutWidget_4 = new QWidget(ECGBASE);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(9, 9, 691, 271));
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
        verticalLayoutWidget_6->setGeometry(QRect(30, 20, 641, 251));
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
        verticalLayoutWidget->setGeometry(QRect(10, 10, 591, 271));
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
        verticalLayoutWidget_2->setGeometry(QRect(9, 9, 591, 271));
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
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 681, 271));
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
        verticalLayoutWidget_3->setGeometry(QRect(0, 10, 601, 271));
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

        horizontalLayout->addWidget(tabWidget);

        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 21));
        MainView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainView->setStatusBar(statusBar);

        retranslateUi(MainView);

        tabWidget->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "Front Panel Controller", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ECGBASE), QApplication::translate("MainView", "ECG Baseline", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RPEAKS), QApplication::translate("MainView", "R-peaks", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRV1), QApplication::translate("MainView", "HRV 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRV2), QApplication::translate("MainView", "HRV 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRF_DFA), QApplication::translate("MainView", "HRV DFA", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ST_SEGMENT), QApplication::translate("MainView", "ST Segment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HEART_CLASS), QApplication::translate("MainView", "Heart Class", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(T_WAVE_ALT), QApplication::translate("MainView", "T Wave Alt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
