/********************************************************************************
** Form generated from reading UI file 'hrv2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRV2_H
#define UI_HRV2_H

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

class Ui_HRV2
{
public:
    QGroupBox *groupBox_HRV2;
    QPushButton *pushButton_RUN;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSD1;
    QLineEdit *lineEditSD1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelSD;
    QLineEdit *lineEditSD2;

    void setupUi(QWidget *HRV2)
    {
        if (HRV2->objectName().isEmpty())
            HRV2->setObjectName(QStringLiteral("HRV2"));
        HRV2->resize(400, 300);
        groupBox_HRV2 = new QGroupBox(HRV2);
        groupBox_HRV2->setObjectName(QStringLiteral("groupBox_HRV2"));
        groupBox_HRV2->setGeometry(QRect(10, 10, 371, 271));
        pushButton_RUN = new QPushButton(groupBox_HRV2);
        pushButton_RUN->setObjectName(QStringLiteral("pushButton_RUN"));
        pushButton_RUN->setGeometry(QRect(40, 20, 75, 23));
        widget = new QWidget(groupBox_HRV2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 61, 162, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelSD1 = new QLabel(widget);
        labelSD1->setObjectName(QStringLiteral("labelSD1"));

        horizontalLayout->addWidget(labelSD1);

        lineEditSD1 = new QLineEdit(widget);
        lineEditSD1->setObjectName(QStringLiteral("lineEditSD1"));

        horizontalLayout->addWidget(lineEditSD1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelSD = new QLabel(widget);
        labelSD->setObjectName(QStringLiteral("labelSD"));

        horizontalLayout_2->addWidget(labelSD);

        lineEditSD2 = new QLineEdit(widget);
        lineEditSD2->setObjectName(QStringLiteral("lineEditSD2"));

        horizontalLayout_2->addWidget(lineEditSD2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(HRV2);

        QMetaObject::connectSlotsByName(HRV2);
    } // setupUi

    void retranslateUi(QWidget *HRV2)
    {
        HRV2->setWindowTitle(QApplication::translate("HRV2", "Form", nullptr));
        groupBox_HRV2->setTitle(QApplication::translate("HRV2", "HRV 2", nullptr));
        pushButton_RUN->setText(QApplication::translate("HRV2", "Run", nullptr));
        label->setText(QApplication::translate("HRV2", "Alterans parameters", nullptr));
        labelSD1->setText(QApplication::translate("HRV2", "SD1", nullptr));
        labelSD->setText(QApplication::translate("HRV2", "SD2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV2: public Ui_HRV2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRV2_H
