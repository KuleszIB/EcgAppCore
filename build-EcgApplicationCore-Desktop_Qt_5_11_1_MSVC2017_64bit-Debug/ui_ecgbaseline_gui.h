/********************************************************************************
** Form generated from reading UI file 'ecgbaseline_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_ECGbaseline;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_filter;
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

    void setupUi(QWidget *ECGbaseline_gui)
    {
        if (ECGbaseline_gui->objectName().isEmpty())
            ECGbaseline_gui->setObjectName(QStringLiteral("ECGbaseline_gui"));
        ECGbaseline_gui->resize(624, 306);
        horizontalLayout = new QHBoxLayout(ECGbaseline_gui);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_ECGbaseline = new QGroupBox(ECGbaseline_gui);
        groupBox_ECGbaseline->setObjectName(QStringLiteral("groupBox_ECGbaseline"));
        groupBox_ECGbaseline->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(groupBox_ECGbaseline);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(groupBox_ECGbaseline);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_ECGbaseline);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 1, 3, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_ECGbaseline);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox_filter = new QComboBox(groupBox_ECGbaseline);
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


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        loHighFreq = new QHBoxLayout();
        loHighFreq->setObjectName(QStringLiteral("loHighFreq"));
        label_highFreq = new QLabel(groupBox_ECGbaseline);
        label_highFreq->setObjectName(QStringLiteral("label_highFreq"));

        loHighFreq->addWidget(label_highFreq);

        spinBox_highFreq = new QSpinBox(groupBox_ECGbaseline);
        spinBox_highFreq->setObjectName(QStringLiteral("spinBox_highFreq"));

        loHighFreq->addWidget(spinBox_highFreq);


        verticalLayout_2->addLayout(loHighFreq);

        hloLowFreq = new QHBoxLayout();
        hloLowFreq->setObjectName(QStringLiteral("hloLowFreq"));
        label_lowFreq = new QLabel(groupBox_ECGbaseline);
        label_lowFreq->setObjectName(QStringLiteral("label_lowFreq"));

        hloLowFreq->addWidget(label_lowFreq);

        spinBox_lowFreq = new QSpinBox(groupBox_ECGbaseline);
        spinBox_lowFreq->setObjectName(QStringLiteral("spinBox_lowFreq"));

        hloLowFreq->addWidget(spinBox_lowFreq);


        verticalLayout_2->addLayout(hloLowFreq);

        loFilterOrder = new QHBoxLayout();
        loFilterOrder->setObjectName(QStringLiteral("loFilterOrder"));
        label_filOrder = new QLabel(groupBox_ECGbaseline);
        label_filOrder->setObjectName(QStringLiteral("label_filOrder"));

        loFilterOrder->addWidget(label_filOrder);

        spinBox_filOrder = new QSpinBox(groupBox_ECGbaseline);
        spinBox_filOrder->setObjectName(QStringLiteral("spinBox_filOrder"));

        loFilterOrder->addWidget(spinBox_filOrder);


        verticalLayout_2->addLayout(loFilterOrder);

        loFilterLength = new QHBoxLayout();
        loFilterLength->setObjectName(QStringLiteral("loFilterLength"));
        label_filLenght = new QLabel(groupBox_ECGbaseline);
        label_filLenght->setObjectName(QStringLiteral("label_filLenght"));

        loFilterLength->addWidget(label_filLenght);

        spinBox_filLength = new QSpinBox(groupBox_ECGbaseline);
        spinBox_filLength->setObjectName(QStringLiteral("spinBox_filLength"));

        loFilterLength->addWidget(spinBox_filLength);


        verticalLayout_2->addLayout(loFilterLength);

        loStepSize = new QHBoxLayout();
        loStepSize->setObjectName(QStringLiteral("loStepSize"));
        label_stepSize = new QLabel(groupBox_ECGbaseline);
        label_stepSize->setObjectName(QStringLiteral("label_stepSize"));

        loStepSize->addWidget(label_stepSize);

        spinBox_stepSize = new QSpinBox(groupBox_ECGbaseline);
        spinBox_stepSize->setObjectName(QStringLiteral("spinBox_stepSize"));

        loStepSize->addWidget(spinBox_stepSize);


        verticalLayout_2->addLayout(loStepSize);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_ECGbaseline);


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
