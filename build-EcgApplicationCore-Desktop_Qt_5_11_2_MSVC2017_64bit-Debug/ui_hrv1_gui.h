/********************************************************************************
** Form generated from reading UI file 'hrv1_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRV1_GUI_H
#define UI_HRV1_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HRV1_gui
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_HRV1;
    QFormLayout *formLayout;
    QPushButton *button;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelHF;
    QLineEdit *lineEditHF;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelLF;
    QLineEdit *lineEditLF;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelVLF;
    QLineEdit *lineEditVLF;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelULF;
    QLineEdit *lineEditULF;
    QWidget *hrv1Plot;

    void setupUi(QWidget *HRV1_gui)
    {
        if (HRV1_gui->objectName().isEmpty())
            HRV1_gui->setObjectName(QStringLiteral("HRV1_gui"));
        HRV1_gui->resize(1024, 713);
        horizontalLayout = new QHBoxLayout(HRV1_gui);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_HRV1 = new QGroupBox(HRV1_gui);
        groupBox_HRV1->setObjectName(QStringLiteral("groupBox_HRV1"));
        formLayout = new QFormLayout(groupBox_HRV1);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        button = new QPushButton(groupBox_HRV1);
        button->setObjectName(QStringLiteral("button"));

        formLayout->setWidget(0, QFormLayout::LabelRole, button);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox_HRV1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelHF = new QLabel(groupBox_HRV1);
        labelHF->setObjectName(QStringLiteral("labelHF"));

        horizontalLayout_2->addWidget(labelHF);

        lineEditHF = new QLineEdit(groupBox_HRV1);
        lineEditHF->setObjectName(QStringLiteral("lineEditHF"));

        horizontalLayout_2->addWidget(lineEditHF);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelLF = new QLabel(groupBox_HRV1);
        labelLF->setObjectName(QStringLiteral("labelLF"));

        horizontalLayout_3->addWidget(labelLF);

        lineEditLF = new QLineEdit(groupBox_HRV1);
        lineEditLF->setObjectName(QStringLiteral("lineEditLF"));

        horizontalLayout_3->addWidget(lineEditLF);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelVLF = new QLabel(groupBox_HRV1);
        labelVLF->setObjectName(QStringLiteral("labelVLF"));

        horizontalLayout_4->addWidget(labelVLF);

        lineEditVLF = new QLineEdit(groupBox_HRV1);
        lineEditVLF->setObjectName(QStringLiteral("lineEditVLF"));

        horizontalLayout_4->addWidget(lineEditVLF);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelULF = new QLabel(groupBox_HRV1);
        labelULF->setObjectName(QStringLiteral("labelULF"));

        horizontalLayout_5->addWidget(labelULF);

        lineEditULF = new QLineEdit(groupBox_HRV1);
        lineEditULF->setObjectName(QStringLiteral("lineEditULF"));

        horizontalLayout_5->addWidget(lineEditULF);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout_2);

        hrv1Plot = new QWidget(groupBox_HRV1);
        hrv1Plot->setObjectName(QStringLiteral("hrv1Plot"));

        formLayout->setWidget(2, QFormLayout::LabelRole, hrv1Plot);


        horizontalLayout->addWidget(groupBox_HRV1);


        retranslateUi(HRV1_gui);

        QMetaObject::connectSlotsByName(HRV1_gui);
    } // setupUi

    void retranslateUi(QWidget *HRV1_gui)
    {
        HRV1_gui->setWindowTitle(QApplication::translate("HRV1_gui", "Form", nullptr));
        groupBox_HRV1->setTitle(QApplication::translate("HRV1_gui", "HRV 1", nullptr));
        button->setText(QApplication::translate("HRV1_gui", "Run", nullptr));
        label->setText(QApplication::translate("HRV1_gui", "Periodogram paremeters", nullptr));
        labelHF->setText(QApplication::translate("HRV1_gui", "HF", nullptr));
        labelLF->setText(QApplication::translate("HRV1_gui", "LF", nullptr));
        labelVLF->setText(QApplication::translate("HRV1_gui", "VLF", nullptr));
        labelULF->setText(QApplication::translate("HRV1_gui", "ULF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV1_gui: public Ui_HRV1_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRV1_GUI_H
