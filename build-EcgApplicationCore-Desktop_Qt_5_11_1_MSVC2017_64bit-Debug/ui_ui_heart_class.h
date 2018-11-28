/********************************************************************************
** Form generated from reading UI file 'ui_heart_class.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_HEART_CLASS_H
#define UI_UI_HEART_CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Heart_class
{
public:
    QGroupBox *groupBox_HeartClass;
    QPushButton *Button_Run;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_QRSClass;
    QLineEdit *edit_QRS_CLASS_MONITOR;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_QRSMORPHOLOGY;
    QLineEdit *edit_QRS_MORPHOLOGY_MONITOR;

    void setupUi(QWidget *Heart_class)
    {
        if (Heart_class->objectName().isEmpty())
            Heart_class->setObjectName(QStringLiteral("Heart_class"));
        Heart_class->resize(754, 375);
        groupBox_HeartClass = new QGroupBox(Heart_class);
        groupBox_HeartClass->setObjectName(QStringLiteral("groupBox_HeartClass"));
        groupBox_HeartClass->setGeometry(QRect(10, 10, 701, 311));
        Button_Run = new QPushButton(groupBox_HeartClass);
        Button_Run->setObjectName(QStringLiteral("Button_Run"));
        Button_Run->setGeometry(QRect(20, 30, 75, 23));
        widget = new QWidget(groupBox_HeartClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 80, 241, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_QRSClass = new QLabel(widget);
        label_QRSClass->setObjectName(QStringLiteral("label_QRSClass"));

        horizontalLayout->addWidget(label_QRSClass);

        edit_QRS_CLASS_MONITOR = new QLineEdit(widget);
        edit_QRS_CLASS_MONITOR->setObjectName(QStringLiteral("edit_QRS_CLASS_MONITOR"));

        horizontalLayout->addWidget(edit_QRS_CLASS_MONITOR);

        widget1 = new QWidget(groupBox_HeartClass);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 110, 241, 22));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_QRSMORPHOLOGY = new QLabel(widget1);
        label_QRSMORPHOLOGY->setObjectName(QStringLiteral("label_QRSMORPHOLOGY"));

        horizontalLayout_3->addWidget(label_QRSMORPHOLOGY);

        edit_QRS_MORPHOLOGY_MONITOR = new QLineEdit(widget1);
        edit_QRS_MORPHOLOGY_MONITOR->setObjectName(QStringLiteral("edit_QRS_MORPHOLOGY_MONITOR"));

        horizontalLayout_3->addWidget(edit_QRS_MORPHOLOGY_MONITOR);


        retranslateUi(Heart_class);

        QMetaObject::connectSlotsByName(Heart_class);
    } // setupUi

    void retranslateUi(QWidget *Heart_class)
    {
        Heart_class->setWindowTitle(QApplication::translate("Heart_class", "Form", nullptr));
        groupBox_HeartClass->setTitle(QApplication::translate("Heart_class", "Heart Class", nullptr));
        Button_Run->setText(QApplication::translate("Heart_class", "Run", nullptr));
        label_QRSClass->setText(QApplication::translate("Heart_class", "<html><head/><body><p><span style=\" font-size:10pt;\">QRS Class:</span></p></body></html>", nullptr));
        label_QRSMORPHOLOGY->setText(QApplication::translate("Heart_class", "<html><head/><body><p><span style=\" font-size:10pt;\">QRS Morphology:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Heart_class: public Ui_Heart_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_HEART_CLASS_H
