/********************************************************************************
** Form generated from reading UI file 'r_peaks.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_R_PEAKS_H
#define UI_R_PEAKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_R_peaks
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxR;
    QCheckBox *checkBoxQRSonset;
    QCheckBox *checkBoxQRSend;
    QCheckBox *checkBoxTend;
    QCheckBox *checkBoxPonset;
    QCheckBox *checkBoxPend;

    void setupUi(QWidget *R_peaks)
    {
        if (R_peaks->objectName().isEmpty())
            R_peaks->setObjectName(QStringLiteral("R_peaks"));
        R_peaks->resize(448, 323);
        groupBox = new QGroupBox(R_peaks);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 351, 231));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 75, 23));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 60, 76, 134));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxR = new QCheckBox(widget);
        checkBoxR->setObjectName(QStringLiteral("checkBoxR"));

        verticalLayout->addWidget(checkBoxR);

        checkBoxQRSonset = new QCheckBox(widget);
        checkBoxQRSonset->setObjectName(QStringLiteral("checkBoxQRSonset"));

        verticalLayout->addWidget(checkBoxQRSonset);

        checkBoxQRSend = new QCheckBox(widget);
        checkBoxQRSend->setObjectName(QStringLiteral("checkBoxQRSend"));

        verticalLayout->addWidget(checkBoxQRSend);

        checkBoxTend = new QCheckBox(widget);
        checkBoxTend->setObjectName(QStringLiteral("checkBoxTend"));

        verticalLayout->addWidget(checkBoxTend);

        checkBoxPonset = new QCheckBox(widget);
        checkBoxPonset->setObjectName(QStringLiteral("checkBoxPonset"));

        verticalLayout->addWidget(checkBoxPonset);

        checkBoxPend = new QCheckBox(widget);
        checkBoxPend->setObjectName(QStringLiteral("checkBoxPend"));

        verticalLayout->addWidget(checkBoxPend);


        retranslateUi(R_peaks);

        QMetaObject::connectSlotsByName(R_peaks);
    } // setupUi

    void retranslateUi(QWidget *R_peaks)
    {
        R_peaks->setWindowTitle(QApplication::translate("R_peaks", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("R_peaks", "R Peaks", nullptr));
        pushButton->setText(QApplication::translate("R_peaks", "Run", nullptr));
        checkBoxR->setText(QApplication::translate("R_peaks", "R peaks", nullptr));
        checkBoxQRSonset->setText(QApplication::translate("R_peaks", "QRS onset", nullptr));
        checkBoxQRSend->setText(QApplication::translate("R_peaks", "QRS end", nullptr));
        checkBoxTend->setText(QApplication::translate("R_peaks", "T end", nullptr));
        checkBoxPonset->setText(QApplication::translate("R_peaks", "P onset", nullptr));
        checkBoxPend->setText(QApplication::translate("R_peaks", "P end", nullptr));
    } // retranslateUi

};

namespace Ui {
    class R_peaks: public Ui_R_peaks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R_PEAKS_H
