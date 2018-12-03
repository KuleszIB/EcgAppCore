/********************************************************************************
** Form generated from reading UI file 'ui_ecg_baseline.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_ECG_BASELINE_H
#define UI_UI_ECG_BASELINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECGbaseline
{
public:
    QGroupBox *groupBox_ECGbaseline;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *ECGbaseline)
    {
        if (ECGbaseline->objectName().isEmpty())
            ECGbaseline->setObjectName(QStringLiteral("ECGbaseline"));
        ECGbaseline->resize(597, 413);
        groupBox_ECGbaseline = new QGroupBox(ECGbaseline);
        groupBox_ECGbaseline->setObjectName(QStringLiteral("groupBox_ECGbaseline"));
        groupBox_ECGbaseline->setGeometry(QRect(10, 10, 491, 331));
        pushButton = new QPushButton(groupBox_ECGbaseline);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        widget = new QWidget(groupBox_ECGbaseline);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 70, 131, 41));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);


        retranslateUi(ECGbaseline);

        QMetaObject::connectSlotsByName(ECGbaseline);
    } // setupUi

    void retranslateUi(QWidget *ECGbaseline)
    {
        ECGbaseline->setWindowTitle(QApplication::translate("ECGbaseline", "Form", nullptr));
        groupBox_ECGbaseline->setTitle(QApplication::translate("ECGbaseline", "ECG Baseline", nullptr));
        pushButton->setText(QApplication::translate("ECGbaseline", "Run", nullptr));
        label->setText(QApplication::translate("ECGbaseline", "Filtration method", nullptr));
        comboBox->setItemText(0, QApplication::translate("ECGbaseline", "lowpass_filter", nullptr));
        comboBox->setItemText(1, QApplication::translate("ECGbaseline", "bandpass_filter", nullptr));
        comboBox->setItemText(2, QApplication::translate("ECGbaseline", "Butterworth_filter", nullptr));
        comboBox->setItemText(3, QApplication::translate("ECGbaseline", "Chebyshev_filter", nullptr));
        comboBox->setItemText(4, QApplication::translate("ECGbaseline", "Savitzky\342\200\231_Golay_filter", nullptr));
        comboBox->setItemText(5, QApplication::translate("ECGbaseline", "Keiser_filter", nullptr));
        comboBox->setItemText(6, QApplication::translate("ECGbaseline", "LSM_algorithm", nullptr));
        comboBox->setItemText(7, QApplication::translate("ECGbaseline", "Moving_average", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ECGbaseline: public Ui_ECGbaseline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_ECG_BASELINE_H
