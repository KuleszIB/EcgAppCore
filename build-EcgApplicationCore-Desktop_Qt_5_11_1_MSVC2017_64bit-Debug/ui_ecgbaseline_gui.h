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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECGbaseline_gui
{
public:
    QGroupBox *groupBox_ECGbaseline;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *ECGbaseline_gui)
    {
        if (ECGbaseline_gui->objectName().isEmpty())
            ECGbaseline_gui->setObjectName(QStringLiteral("ECGbaseline_gui"));
        ECGbaseline_gui->resize(597, 413);
        groupBox_ECGbaseline = new QGroupBox(ECGbaseline_gui);
        groupBox_ECGbaseline->setObjectName(QStringLiteral("groupBox_ECGbaseline"));
        groupBox_ECGbaseline->setGeometry(QRect(10, 10, 491, 331));
        pushButton = new QPushButton(groupBox_ECGbaseline);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        layoutWidget = new QWidget(groupBox_ECGbaseline);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 131, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
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


        retranslateUi(ECGbaseline_gui);

        QMetaObject::connectSlotsByName(ECGbaseline_gui);
    } // setupUi

    void retranslateUi(QWidget *ECGbaseline_gui)
    {
        ECGbaseline_gui->setWindowTitle(QApplication::translate("ECGbaseline_gui", "Form", nullptr));
        groupBox_ECGbaseline->setTitle(QApplication::translate("ECGbaseline_gui", "ECG Baseline", nullptr));
        pushButton->setText(QApplication::translate("ECGbaseline_gui", "Run", nullptr));
        label->setText(QApplication::translate("ECGbaseline_gui", "Filtration method", nullptr));
        comboBox->setItemText(0, QApplication::translate("ECGbaseline_gui", "lowpass_filter", nullptr));
        comboBox->setItemText(1, QApplication::translate("ECGbaseline_gui", "bandpass_filter", nullptr));
        comboBox->setItemText(2, QApplication::translate("ECGbaseline_gui", "Butterworth_filter", nullptr));
        comboBox->setItemText(3, QApplication::translate("ECGbaseline_gui", "Chebyshev_filter", nullptr));
        comboBox->setItemText(4, QApplication::translate("ECGbaseline_gui", "Savitzky\342\200\231_Golay_filter", nullptr));
        comboBox->setItemText(5, QApplication::translate("ECGbaseline_gui", "Keiser_filter", nullptr));
        comboBox->setItemText(6, QApplication::translate("ECGbaseline_gui", "LSM_algorithm", nullptr));
        comboBox->setItemText(7, QApplication::translate("ECGbaseline_gui", "Moving_average", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ECGbaseline_gui: public Ui_ECGbaseline_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECGBASELINE_GUI_H
