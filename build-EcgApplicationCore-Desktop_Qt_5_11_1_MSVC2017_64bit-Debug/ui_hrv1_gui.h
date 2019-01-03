/********************************************************************************
** Form generated from reading UI file 'hrv1_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_HRV1;
    QPushButton *button;
    QWidget *hrv1Plot;
    QLabel *label;
    QLabel *label_17;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_18;
    QLineEdit *lineEdit_14;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_19;
    QLineEdit *lineEdit_15;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_20;
    QLineEdit *lineEdit_16;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_21;
    QLineEdit *lineEdit_17;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_22;
    QLineEdit *lineEdit_18;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QLineEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLineEdit *lineEdit_12;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    QLineEdit *lineEdit_13;

    void setupUi(QWidget *HRV1_gui)
    {
        if (HRV1_gui->objectName().isEmpty())
            HRV1_gui->setObjectName(QStringLiteral("HRV1_gui"));
        HRV1_gui->resize(1024, 713);
        horizontalLayout = new QHBoxLayout(HRV1_gui);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_HRV1 = new QGroupBox(HRV1_gui);
        groupBox_HRV1->setObjectName(QStringLiteral("groupBox_HRV1"));
        button = new QPushButton(groupBox_HRV1);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(10, 23, 75, 23));
        hrv1Plot = new QWidget(groupBox_HRV1);
        hrv1Plot->setObjectName(QStringLiteral("hrv1Plot"));
        hrv1Plot->setGeometry(QRect(10, 187, 16, 16));
        label = new QLabel(groupBox_HRV1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 121, 16));
        label_17 = new QLabel(groupBox_HRV1);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 260, 121, 16));
        layoutWidget_10 = new QWidget(groupBox_HRV1);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(20, 290, 161, 136));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_18 = new QLabel(layoutWidget_10);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_19->addWidget(label_18);

        lineEdit_14 = new QLineEdit(layoutWidget_10);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        horizontalLayout_19->addWidget(lineEdit_14);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_19 = new QLabel(layoutWidget_10);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_20->addWidget(label_19);

        lineEdit_15 = new QLineEdit(layoutWidget_10);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        horizontalLayout_20->addWidget(lineEdit_15);


        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_20 = new QLabel(layoutWidget_10);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_21->addWidget(label_20);

        lineEdit_16 = new QLineEdit(layoutWidget_10);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        horizontalLayout_21->addWidget(lineEdit_16);


        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_21 = new QLabel(layoutWidget_10);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_22->addWidget(label_21);

        lineEdit_17 = new QLineEdit(layoutWidget_10);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));

        horizontalLayout_22->addWidget(lineEdit_17);


        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_22 = new QLabel(layoutWidget_10);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_23->addWidget(label_22);

        lineEdit_18 = new QLineEdit(layoutWidget_10);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));

        horizontalLayout_23->addWidget(lineEdit_18);


        verticalLayout_2->addLayout(horizontalLayout_23);

        widget = new QWidget(groupBox_HRV1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 100, 161, 136));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_15->addWidget(label_4);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_15->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_16->addWidget(label_14);

        lineEdit_11 = new QLineEdit(widget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        horizontalLayout_16->addWidget(lineEdit_11);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_15 = new QLabel(widget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_17->addWidget(label_15);

        lineEdit_12 = new QLineEdit(widget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        horizontalLayout_17->addWidget(lineEdit_12);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_18->addWidget(label_16);

        lineEdit_13 = new QLineEdit(widget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        horizontalLayout_18->addWidget(lineEdit_13);


        verticalLayout->addLayout(horizontalLayout_18);


        horizontalLayout->addWidget(groupBox_HRV1);


        retranslateUi(HRV1_gui);

        QMetaObject::connectSlotsByName(HRV1_gui);
    } // setupUi

    void retranslateUi(QWidget *HRV1_gui)
    {
        HRV1_gui->setWindowTitle(QApplication::translate("HRV1_gui", "Form", nullptr));
        groupBox_HRV1->setTitle(QApplication::translate("HRV1_gui", "HRV 1", nullptr));
        button->setText(QApplication::translate("HRV1_gui", "Run", nullptr));
        label->setText(QApplication::translate("HRV1_gui", "Frequency parameters:", nullptr));
        label_17->setText(QApplication::translate("HRV1_gui", "Time parameters:", nullptr));
        label_18->setText(QApplication::translate("HRV1_gui", "MEAN", nullptr));
        label_19->setText(QApplication::translate("HRV1_gui", "SDNN", nullptr));
        label_20->setText(QApplication::translate("HRV1_gui", "RMSSD", nullptr));
        label_21->setText(QApplication::translate("HRV1_gui", "NN50", nullptr));
        label_22->setText(QApplication::translate("HRV1_gui", "PNN50", nullptr));
        label_3->setText(QApplication::translate("HRV1_gui", "ULF", nullptr));
        label_4->setText(QApplication::translate("HRV1_gui", "VLF", nullptr));
        label_14->setText(QApplication::translate("HRV1_gui", "HF", nullptr));
        label_15->setText(QApplication::translate("HRV1_gui", "LF", nullptr));
        label_16->setText(QApplication::translate("HRV1_gui", "TP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV1_gui: public Ui_HRV1_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRV1_GUI_H
