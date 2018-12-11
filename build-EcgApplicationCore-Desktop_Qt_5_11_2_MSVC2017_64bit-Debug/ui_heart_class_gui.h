/********************************************************************************
** Form generated from reading UI file 'heart_class_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEART_CLASS_GUI_H
#define UI_HEART_CLASS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Heart_class_gui
{
public:
    QGroupBox *groupBox_HeartClass;
    QPushButton *Button_Run;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_QRSClass;
    QLineEdit *edit_QRS_CLASS_MONITOR;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_QRSMORPHOLOGY;
    QLineEdit *edit_QRS_MORPHOLOGY_MONITOR;

    void setupUi(QWidget *Heart_class_gui)
    {
        if (Heart_class_gui->objectName().isEmpty())
            Heart_class_gui->setObjectName(QStringLiteral("Heart_class_gui"));
        Heart_class_gui->resize(754, 375);
        groupBox_HeartClass = new QGroupBox(Heart_class_gui);
        groupBox_HeartClass->setObjectName(QStringLiteral("groupBox_HeartClass"));
        groupBox_HeartClass->setGeometry(QRect(10, 10, 701, 311));
        Button_Run = new QPushButton(groupBox_HeartClass);
        Button_Run->setObjectName(QStringLiteral("Button_Run"));
        Button_Run->setGeometry(QRect(20, 30, 75, 23));
        layoutWidget = new QWidget(groupBox_HeartClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 241, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_QRSClass = new QLabel(layoutWidget);
        label_QRSClass->setObjectName(QStringLiteral("label_QRSClass"));

        horizontalLayout->addWidget(label_QRSClass);

        edit_QRS_CLASS_MONITOR = new QLineEdit(layoutWidget);
        edit_QRS_CLASS_MONITOR->setObjectName(QStringLiteral("edit_QRS_CLASS_MONITOR"));

        horizontalLayout->addWidget(edit_QRS_CLASS_MONITOR);

        layoutWidget1 = new QWidget(groupBox_HeartClass);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 110, 241, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_QRSMORPHOLOGY = new QLabel(layoutWidget1);
        label_QRSMORPHOLOGY->setObjectName(QStringLiteral("label_QRSMORPHOLOGY"));

        horizontalLayout_3->addWidget(label_QRSMORPHOLOGY);

        edit_QRS_MORPHOLOGY_MONITOR = new QLineEdit(layoutWidget1);
        edit_QRS_MORPHOLOGY_MONITOR->setObjectName(QStringLiteral("edit_QRS_MORPHOLOGY_MONITOR"));

        horizontalLayout_3->addWidget(edit_QRS_MORPHOLOGY_MONITOR);


        retranslateUi(Heart_class_gui);

        QMetaObject::connectSlotsByName(Heart_class_gui);
    } // setupUi

    void retranslateUi(QWidget *Heart_class_gui)
    {
        Heart_class_gui->setWindowTitle(QApplication::translate("Heart_class_gui", "Form", nullptr));
        groupBox_HeartClass->setTitle(QApplication::translate("Heart_class_gui", "Heart Class", nullptr));
        Button_Run->setText(QApplication::translate("Heart_class_gui", "Run", nullptr));
        label_QRSClass->setText(QApplication::translate("Heart_class_gui", "<html><head/><body><p><span style=\" font-size:10pt;\">QRS Class:</span></p></body></html>", nullptr));
        label_QRSMORPHOLOGY->setText(QApplication::translate("Heart_class_gui", "<html><head/><body><p><span style=\" font-size:10pt;\">QRS Morphology:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Heart_class_gui: public Ui_Heart_class_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEART_CLASS_GUI_H
