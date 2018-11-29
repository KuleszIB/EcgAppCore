/********************************************************************************
** Form generated from reading UI file 'hrv1.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRV1_H
#define UI_HRV1_H

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

class Ui_HRV1
{
public:
    QGroupBox *groupBox_HRV1;
    QPushButton *pushButton_RUN;
    QWidget *widget;
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

    void setupUi(QWidget *HRV1)
    {
        if (HRV1->objectName().isEmpty())
            HRV1->setObjectName(QStringLiteral("HRV1"));
        HRV1->resize(569, 351);
        groupBox_HRV1 = new QGroupBox(HRV1);
        groupBox_HRV1->setObjectName(QStringLiteral("groupBox_HRV1"));
        groupBox_HRV1->setGeometry(QRect(10, 10, 481, 281));
        pushButton_RUN = new QPushButton(groupBox_HRV1);
        pushButton_RUN->setObjectName(QStringLiteral("pushButton_RUN"));
        pushButton_RUN->setGeometry(QRect(10, 20, 75, 23));
        widget = new QWidget(groupBox_HRV1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 50, 163, 129));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelHF = new QLabel(widget);
        labelHF->setObjectName(QStringLiteral("labelHF"));

        horizontalLayout_2->addWidget(labelHF);

        lineEditHF = new QLineEdit(widget);
        lineEditHF->setObjectName(QStringLiteral("lineEditHF"));

        horizontalLayout_2->addWidget(lineEditHF);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelLF = new QLabel(widget);
        labelLF->setObjectName(QStringLiteral("labelLF"));

        horizontalLayout_3->addWidget(labelLF);

        lineEditLF = new QLineEdit(widget);
        lineEditLF->setObjectName(QStringLiteral("lineEditLF"));

        horizontalLayout_3->addWidget(lineEditLF);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelVLF = new QLabel(widget);
        labelVLF->setObjectName(QStringLiteral("labelVLF"));

        horizontalLayout_4->addWidget(labelVLF);

        lineEditVLF = new QLineEdit(widget);
        lineEditVLF->setObjectName(QStringLiteral("lineEditVLF"));

        horizontalLayout_4->addWidget(lineEditVLF);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelULF = new QLabel(widget);
        labelULF->setObjectName(QStringLiteral("labelULF"));

        horizontalLayout_5->addWidget(labelULF);

        lineEditULF = new QLineEdit(widget);
        lineEditULF->setObjectName(QStringLiteral("lineEditULF"));

        horizontalLayout_5->addWidget(lineEditULF);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(HRV1);

        QMetaObject::connectSlotsByName(HRV1);
    } // setupUi

    void retranslateUi(QWidget *HRV1)
    {
        HRV1->setWindowTitle(QApplication::translate("HRV1", "Form", nullptr));
        groupBox_HRV1->setTitle(QApplication::translate("HRV1", "HRV 1", nullptr));
        pushButton_RUN->setText(QApplication::translate("HRV1", "Run", nullptr));
        label->setText(QApplication::translate("HRV1", "Periodogram paremeters", nullptr));
        labelHF->setText(QApplication::translate("HRV1", "HF", nullptr));
        labelLF->setText(QApplication::translate("HRV1", "LF", nullptr));
        labelVLF->setText(QApplication::translate("HRV1", "VLF", nullptr));
        labelULF->setText(QApplication::translate("HRV1", "ULF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV1: public Ui_HRV1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRV1_H
