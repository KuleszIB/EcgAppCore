/********************************************************************************
** Form generated from reading UI file 'ecgbaseline_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECGBASELINE_GUI_H
#define UI_ECGBASELINE_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECGbaseline_gui
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_ECGbaseline;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_filter;
    QPlainTextEdit *plainTextEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *loHighFreq;
    QLabel *label_highFreq;
    QSpinBox *spinBox_highFreq;
    QHBoxLayout *hloLowFreq;
    QLabel *label_lowFreq;
    QSpinBox *spinBox_lowFreq;
    QHBoxLayout *loFilterOrder;
    QLabel *label_filOrder;
    QSpinBox *spinBox_filOrder;
    QHBoxLayout *loFilterLength;
    QLabel *label_filLenght;
    QSpinBox *spinBox_filLength;
    QHBoxLayout *loStepSize;
    QLabel *label_stepSize;
    QSpinBox *spinBox_stepSize;
    QWidget *ecgPlot;

    void setupUi(QWidget *ECGbaseline_gui)
    {
        if (ECGbaseline_gui->objectName().isEmpty())
            ECGbaseline_gui->setObjectName(QStringLiteral("ECGbaseline_gui"));
        ECGbaseline_gui->resize(1024, 713);
        gridLayout = new QGridLayout(ECGbaseline_gui);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_ECGbaseline = new QGroupBox(ECGbaseline_gui);
        groupBox_ECGbaseline->setObjectName(QStringLiteral("groupBox_ECGbaseline"));
        pushButton = new QPushButton(groupBox_ECGbaseline);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        layoutWidget = new QWidget(groupBox_ECGbaseline);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 141, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox_filter = new QComboBox(layoutWidget);
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->setObjectName(QStringLiteral("comboBox_filter"));

        verticalLayout->addWidget(comboBox_filter);

        plainTextEdit = new QPlainTextEdit(groupBox_ECGbaseline);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(260, 10, 281, 201));
        layoutWidget1 = new QWidget(groupBox_ECGbaseline);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 140, 152, 136));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        loHighFreq = new QHBoxLayout();
        loHighFreq->setObjectName(QStringLiteral("loHighFreq"));
        label_highFreq = new QLabel(layoutWidget1);
        label_highFreq->setObjectName(QStringLiteral("label_highFreq"));

        loHighFreq->addWidget(label_highFreq);

        spinBox_highFreq = new QSpinBox(layoutWidget1);
        spinBox_highFreq->setObjectName(QStringLiteral("spinBox_highFreq"));

        loHighFreq->addWidget(spinBox_highFreq);


        verticalLayout_2->addLayout(loHighFreq);

        hloLowFreq = new QHBoxLayout();
        hloLowFreq->setObjectName(QStringLiteral("hloLowFreq"));
        label_lowFreq = new QLabel(layoutWidget1);
        label_lowFreq->setObjectName(QStringLiteral("label_lowFreq"));

        hloLowFreq->addWidget(label_lowFreq);

        spinBox_lowFreq = new QSpinBox(layoutWidget1);
        spinBox_lowFreq->setObjectName(QStringLiteral("spinBox_lowFreq"));

        hloLowFreq->addWidget(spinBox_lowFreq);


        verticalLayout_2->addLayout(hloLowFreq);

        loFilterOrder = new QHBoxLayout();
        loFilterOrder->setObjectName(QStringLiteral("loFilterOrder"));
        label_filOrder = new QLabel(layoutWidget1);
        label_filOrder->setObjectName(QStringLiteral("label_filOrder"));

        loFilterOrder->addWidget(label_filOrder);

        spinBox_filOrder = new QSpinBox(layoutWidget1);
        spinBox_filOrder->setObjectName(QStringLiteral("spinBox_filOrder"));

        loFilterOrder->addWidget(spinBox_filOrder);


        verticalLayout_2->addLayout(loFilterOrder);

        loFilterLength = new QHBoxLayout();
        loFilterLength->setObjectName(QStringLiteral("loFilterLength"));
        label_filLenght = new QLabel(layoutWidget1);
        label_filLenght->setObjectName(QStringLiteral("label_filLenght"));

        loFilterLength->addWidget(label_filLenght);

        spinBox_filLength = new QSpinBox(layoutWidget1);
        spinBox_filLength->setObjectName(QStringLiteral("spinBox_filLength"));

        loFilterLength->addWidget(spinBox_filLength);


        verticalLayout_2->addLayout(loFilterLength);

        loStepSize = new QHBoxLayout();
        loStepSize->setObjectName(QStringLiteral("loStepSize"));
        label_stepSize = new QLabel(layoutWidget1);
        label_stepSize->setObjectName(QStringLiteral("label_stepSize"));

        loStepSize->addWidget(label_stepSize);

        spinBox_stepSize = new QSpinBox(layoutWidget1);
        spinBox_stepSize->setObjectName(QStringLiteral("spinBox_stepSize"));

        loStepSize->addWidget(spinBox_stepSize);


        verticalLayout_2->addLayout(loStepSize);

        ecgPlot = new QWidget(groupBox_ECGbaseline);
        ecgPlot->setObjectName(QStringLiteral("ecgPlot"));
        ecgPlot->setGeometry(QRect(10, 280, 780, 310));

        gridLayout->addWidget(groupBox_ECGbaseline, 0, 0, 1, 1);


        retranslateUi(ECGbaseline_gui);

        QMetaObject::connectSlotsByName(ECGbaseline_gui);
    } // setupUi

    void retranslateUi(QWidget *ECGbaseline_gui)
    {
        ECGbaseline_gui->setWindowTitle(QApplication::translate("ECGbaseline_gui", "Form", nullptr));
        groupBox_ECGbaseline->setTitle(QApplication::translate("ECGbaseline_gui", "ECG Baseline", nullptr));
        pushButton->setText(QApplication::translate("ECGbaseline_gui", "Run", nullptr));
        label->setText(QApplication::translate("ECGbaseline_gui", "Filtration method", nullptr));
        comboBox_filter->setItemText(0, QApplication::translate("ECGbaseline_gui", "select filtration method", nullptr));
        comboBox_filter->setItemText(1, QApplication::translate("ECGbaseline_gui", "lowpass_filter", nullptr));
        comboBox_filter->setItemText(2, QApplication::translate("ECGbaseline_gui", "bandpass_filter", nullptr));
        comboBox_filter->setItemText(3, QApplication::translate("ECGbaseline_gui", "Butterworth_filter", nullptr));
        comboBox_filter->setItemText(4, QApplication::translate("ECGbaseline_gui", "Chebyshev_filter", nullptr));
        comboBox_filter->setItemText(5, QApplication::translate("ECGbaseline_gui", "Savitzky\342\200\231_Golay_filter", nullptr));
        comboBox_filter->setItemText(6, QApplication::translate("ECGbaseline_gui", "Keiser_filter", nullptr));
        comboBox_filter->setItemText(7, QApplication::translate("ECGbaseline_gui", "LSM_algorithm", nullptr));
        comboBox_filter->setItemText(8, QApplication::translate("ECGbaseline_gui", "Moving_average", nullptr));

        label_highFreq->setText(QApplication::translate("ECGbaseline_gui", "High cutoff frequency", nullptr));
        label_lowFreq->setText(QApplication::translate("ECGbaseline_gui", "Low cutoff frequency", nullptr));
        label_filOrder->setText(QApplication::translate("ECGbaseline_gui", "Filter order", nullptr));
        label_filLenght->setText(QApplication::translate("ECGbaseline_gui", "filter length", nullptr));
        label_stepSize->setText(QApplication::translate("ECGbaseline_gui", "Step size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ECGbaseline_gui: public Ui_ECGbaseline_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECGBASELINE_GUI_H
