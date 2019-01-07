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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *lo_patients_data;
    QLabel *label_age;
    QLineEdit *lE_age;
    QLabel *label_gender;
    QLineEdit *lE_gender;
    QTabWidget *tabWidget;
    QWidget *ECGBASE;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *loECGBaseline;
    QWidget *RPEAKS;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *loRpeaks;
    QWidget *HRV1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *lo_HRV1;
    QWidget *HRV2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *lo_HRV2;
    QWidget *HRF_DFA;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *loHRVdfa;
    QWidget *ST_SEGMENT;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *loSTSegment;
    QWidget *HEART_CLASS;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *loHeartClass;
    QWidget *T_WAVE_ALT;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *loTAltClass;
    QMenuBar *menuBar;
    QMenu *menuSignal;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(751, 481);
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/images/Images/ECG-img.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainView->setWindowIcon(icon);
        actionOpen = new QAction(MainView);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainView);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lo_patients_data = new QHBoxLayout();
        lo_patients_data->setSpacing(6);
        lo_patients_data->setObjectName(QStringLiteral("lo_patients_data"));
        label_age = new QLabel(centralWidget);
        label_age->setObjectName(QStringLiteral("label_age"));

        lo_patients_data->addWidget(label_age);

        lE_age = new QLineEdit(centralWidget);
        lE_age->setObjectName(QStringLiteral("lE_age"));

        lo_patients_data->addWidget(lE_age);

        label_gender = new QLabel(centralWidget);
        label_gender->setObjectName(QStringLiteral("label_gender"));

        lo_patients_data->addWidget(label_gender);

        lE_gender = new QLineEdit(centralWidget);
        lE_gender->setObjectName(QStringLiteral("lE_gender"));

        lo_patients_data->addWidget(lE_gender);


        gridLayout->addLayout(lo_patients_data, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        ECGBASE = new QWidget();
        ECGBASE->setObjectName(QStringLiteral("ECGBASE"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ECGBASE->sizePolicy().hasHeightForWidth());
        ECGBASE->setSizePolicy(sizePolicy1);
        ECGBASE->setAutoFillBackground(true);
        verticalLayout_4 = new QVBoxLayout(ECGBASE);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        loECGBaseline = new QVBoxLayout();
        loECGBaseline->setSpacing(6);
        loECGBaseline->setObjectName(QStringLiteral("loECGBaseline"));

        verticalLayout_4->addLayout(loECGBaseline);

        tabWidget->addTab(ECGBASE, QString());
        RPEAKS = new QWidget();
        RPEAKS->setObjectName(QStringLiteral("RPEAKS"));
        verticalLayout_2 = new QVBoxLayout(RPEAKS);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        loRpeaks = new QVBoxLayout();
        loRpeaks->setSpacing(6);
        loRpeaks->setObjectName(QStringLiteral("loRpeaks"));
        loRpeaks->setSizeConstraint(QLayout::SetNoConstraint);

        verticalLayout_2->addLayout(loRpeaks);

        tabWidget->addTab(RPEAKS, QString());
        HRV1 = new QWidget();
        HRV1->setObjectName(QStringLiteral("HRV1"));
        verticalLayout_3 = new QVBoxLayout(HRV1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lo_HRV1 = new QVBoxLayout();
        lo_HRV1->setSpacing(6);
        lo_HRV1->setObjectName(QStringLiteral("lo_HRV1"));

        verticalLayout_3->addLayout(lo_HRV1);

        tabWidget->addTab(HRV1, QString());
        HRV2 = new QWidget();
        HRV2->setObjectName(QStringLiteral("HRV2"));
        verticalLayoutWidget_2 = new QWidget(HRV2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 10, 691, 351));
        lo_HRV2 = new QVBoxLayout(verticalLayoutWidget_2);
        lo_HRV2->setSpacing(6);
        lo_HRV2->setContentsMargins(11, 11, 11, 11);
        lo_HRV2->setObjectName(QStringLiteral("lo_HRV2"));
        lo_HRV2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(HRV2, QString());
        HRF_DFA = new QWidget();
        HRF_DFA->setObjectName(QStringLiteral("HRF_DFA"));
        verticalLayout_5 = new QVBoxLayout(HRF_DFA);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        loHRVdfa = new QVBoxLayout();
        loHRVdfa->setSpacing(6);
        loHRVdfa->setObjectName(QStringLiteral("loHRVdfa"));

        verticalLayout_5->addLayout(loHRVdfa);

        tabWidget->addTab(HRF_DFA, QString());
        ST_SEGMENT = new QWidget();
        ST_SEGMENT->setObjectName(QStringLiteral("ST_SEGMENT"));
        verticalLayout_6 = new QVBoxLayout(ST_SEGMENT);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        loSTSegment = new QVBoxLayout();
        loSTSegment->setSpacing(6);
        loSTSegment->setObjectName(QStringLiteral("loSTSegment"));

        verticalLayout_6->addLayout(loSTSegment);

        tabWidget->addTab(ST_SEGMENT, QString());
        HEART_CLASS = new QWidget();
        HEART_CLASS->setObjectName(QStringLiteral("HEART_CLASS"));
        verticalLayout_7 = new QVBoxLayout(HEART_CLASS);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        loHeartClass = new QVBoxLayout();
        loHeartClass->setSpacing(6);
        loHeartClass->setObjectName(QStringLiteral("loHeartClass"));

        verticalLayout_7->addLayout(loHeartClass);

        tabWidget->addTab(HEART_CLASS, QString());
        T_WAVE_ALT = new QWidget();
        T_WAVE_ALT->setObjectName(QStringLiteral("T_WAVE_ALT"));
        verticalLayout_8 = new QVBoxLayout(T_WAVE_ALT);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        loTAltClass = new QHBoxLayout();
        loTAltClass->setSpacing(6);
        loTAltClass->setObjectName(QStringLiteral("loTAltClass"));

        verticalLayout_8->addLayout(loTAltClass);

        tabWidget->addTab(T_WAVE_ALT, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 21));
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

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "Front Panel Controller", nullptr));
        actionOpen->setText(QApplication::translate("MainView", "Open", nullptr));
        actionExit->setText(QApplication::translate("MainView", "Exit", nullptr));
        label_age->setText(QApplication::translate("MainView", "Age", nullptr));
        label_gender->setText(QApplication::translate("MainView", "Gender", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ECGBASE), QApplication::translate("MainView", "ECG Baseline", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RPEAKS), QApplication::translate("MainView", "R-peaks", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRV1), QApplication::translate("MainView", "HRV 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRV2), QApplication::translate("MainView", "HRV 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HRF_DFA), QApplication::translate("MainView", "HRV DFA", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ST_SEGMENT), QApplication::translate("MainView", "ST Segment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HEART_CLASS), QApplication::translate("MainView", "Heart Class", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(T_WAVE_ALT), QApplication::translate("MainView", "T Wave Alt", nullptr));
        menuSignal->setTitle(QApplication::translate("MainView", "Signal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
