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
    QGroupBox *groupBox_HRV1;
    QPushButton *button;
    QWidget *layoutWidget;
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
        HRV1_gui->resize(569, 351);
        groupBox_HRV1 = new QGroupBox(HRV1_gui);
        groupBox_HRV1->setObjectName(QStringLiteral("groupBox_HRV1"));
        groupBox_HRV1->setGeometry(QRect(10, 10, 531, 281));
        button = new QPushButton(groupBox_HRV1);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(10, 20, 75, 23));
        layoutWidget = new QWidget(groupBox_HRV1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 163, 129));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelHF = new QLabel(layoutWidget);
        labelHF->setObjectName(QStringLiteral("labelHF"));

        horizontalLayout_2->addWidget(labelHF);

        lineEditHF = new QLineEdit(layoutWidget);
        lineEditHF->setObjectName(QStringLiteral("lineEditHF"));

        horizontalLayout_2->addWidget(lineEditHF);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelLF = new QLabel(layoutWidget);
        labelLF->setObjectName(QStringLiteral("labelLF"));

        horizontalLayout_3->addWidget(labelLF);

        lineEditLF = new QLineEdit(layoutWidget);
        lineEditLF->setObjectName(QStringLiteral("lineEditLF"));

        horizontalLayout_3->addWidget(lineEditLF);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelVLF = new QLabel(layoutWidget);
        labelVLF->setObjectName(QStringLiteral("labelVLF"));

        horizontalLayout_4->addWidget(labelVLF);

        lineEditVLF = new QLineEdit(layoutWidget);
        lineEditVLF->setObjectName(QStringLiteral("lineEditVLF"));

        horizontalLayout_4->addWidget(lineEditVLF);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelULF = new QLabel(layoutWidget);
        labelULF->setObjectName(QStringLiteral("labelULF"));

        horizontalLayout_5->addWidget(labelULF);

        lineEditULF = new QLineEdit(layoutWidget);
        lineEditULF->setObjectName(QStringLiteral("lineEditULF"));

        horizontalLayout_5->addWidget(lineEditULF);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        hrv1Plot = new QWidget(groupBox_HRV1);
        hrv1Plot->setObjectName(QStringLiteral("hrv1Plot"));
        hrv1Plot->setGeometry(QRect(180, 20, 331, 231));

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
