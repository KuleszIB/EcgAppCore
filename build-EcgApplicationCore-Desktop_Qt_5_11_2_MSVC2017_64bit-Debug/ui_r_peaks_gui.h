/********************************************************************************
** Form generated from reading UI file 'r_peaks_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_R_PEAKS_GUI_H
#define UI_R_PEAKS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_R_peaks_gui
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxR;
    QCheckBox *checkBoxQRSonset;
    QCheckBox *checkBoxQRSend;
    QCheckBox *checkBoxTend;
    QCheckBox *checkBoxPonset;
    QCheckBox *checkBoxPend;
    QWidget *qrsPlot;

    void setupUi(QWidget *R_peaks_gui)
    {
        if (R_peaks_gui->objectName().isEmpty())
            R_peaks_gui->setObjectName(QStringLiteral("R_peaks_gui"));
        R_peaks_gui->resize(1024, 713);
        groupBox = new QGroupBox(R_peaks_gui);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 991, 681));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 75, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 20, 76, 134));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxR = new QCheckBox(layoutWidget);
        checkBoxR->setObjectName(QStringLiteral("checkBoxR"));

        verticalLayout->addWidget(checkBoxR);

        checkBoxQRSonset = new QCheckBox(layoutWidget);
        checkBoxQRSonset->setObjectName(QStringLiteral("checkBoxQRSonset"));

        verticalLayout->addWidget(checkBoxQRSonset);

        checkBoxQRSend = new QCheckBox(layoutWidget);
        checkBoxQRSend->setObjectName(QStringLiteral("checkBoxQRSend"));

        verticalLayout->addWidget(checkBoxQRSend);

        checkBoxTend = new QCheckBox(layoutWidget);
        checkBoxTend->setObjectName(QStringLiteral("checkBoxTend"));

        verticalLayout->addWidget(checkBoxTend);

        checkBoxPonset = new QCheckBox(layoutWidget);
        checkBoxPonset->setObjectName(QStringLiteral("checkBoxPonset"));

        verticalLayout->addWidget(checkBoxPonset);

        checkBoxPend = new QCheckBox(layoutWidget);
        checkBoxPend->setObjectName(QStringLiteral("checkBoxPend"));

        verticalLayout->addWidget(checkBoxPend);

        qrsPlot = new QWidget(groupBox);
        qrsPlot->setObjectName(QStringLiteral("qrsPlot"));
        qrsPlot->setGeometry(QRect(10, 200, 780, 310));

        retranslateUi(R_peaks_gui);

        QMetaObject::connectSlotsByName(R_peaks_gui);
    } // setupUi

    void retranslateUi(QWidget *R_peaks_gui)
    {
        R_peaks_gui->setWindowTitle(QApplication::translate("R_peaks_gui", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("R_peaks_gui", "R Peaks", nullptr));
        pushButton->setText(QApplication::translate("R_peaks_gui", "Run", nullptr));
        checkBoxR->setText(QApplication::translate("R_peaks_gui", "R peaks", nullptr));
        checkBoxQRSonset->setText(QApplication::translate("R_peaks_gui", "QRS onset", nullptr));
        checkBoxQRSend->setText(QApplication::translate("R_peaks_gui", "QRS end", nullptr));
        checkBoxTend->setText(QApplication::translate("R_peaks_gui", "T end", nullptr));
        checkBoxPonset->setText(QApplication::translate("R_peaks_gui", "P onset", nullptr));
        checkBoxPend->setText(QApplication::translate("R_peaks_gui", "P end", nullptr));
    } // retranslateUi

};

namespace Ui {
    class R_peaks_gui: public Ui_R_peaks_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R_PEAKS_GUI_H
