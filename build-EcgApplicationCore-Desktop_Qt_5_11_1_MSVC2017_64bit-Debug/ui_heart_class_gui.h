/********************************************************************************
** Form generated from reading UI file 'heart_class_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEART_CLASS_GUI_H
#define UI_HEART_CLASS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_HeartClass;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *Button_Run;
    QHBoxLayout *horizontalLayout;
    QLabel *label_QRSClass;
    QLineEdit *edit_QRS_CLASS_MONITOR;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_QRSMORPHOLOGY;
    QLineEdit *edit_QRS_MORPHOLOGY_MONITOR;

    void setupUi(QWidget *Heart_class_gui)
    {
        if (Heart_class_gui->objectName().isEmpty())
            Heart_class_gui->setObjectName(QStringLiteral("Heart_class_gui"));
        Heart_class_gui->resize(281, 132);
        horizontalLayout_2 = new QHBoxLayout(Heart_class_gui);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_HeartClass = new QGroupBox(Heart_class_gui);
        groupBox_HeartClass->setObjectName(QStringLiteral("groupBox_HeartClass"));
        gridLayout_2 = new QGridLayout(groupBox_HeartClass);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Button_Run = new QPushButton(groupBox_HeartClass);
        Button_Run->setObjectName(QStringLiteral("Button_Run"));

        gridLayout->addWidget(Button_Run, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_QRSClass = new QLabel(groupBox_HeartClass);
        label_QRSClass->setObjectName(QStringLiteral("label_QRSClass"));

        horizontalLayout->addWidget(label_QRSClass);

        edit_QRS_CLASS_MONITOR = new QLineEdit(groupBox_HeartClass);
        edit_QRS_CLASS_MONITOR->setObjectName(QStringLiteral("edit_QRS_CLASS_MONITOR"));

        horizontalLayout->addWidget(edit_QRS_CLASS_MONITOR);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_QRSMORPHOLOGY = new QLabel(groupBox_HeartClass);
        label_QRSMORPHOLOGY->setObjectName(QStringLiteral("label_QRSMORPHOLOGY"));

        horizontalLayout_3->addWidget(label_QRSMORPHOLOGY);

        edit_QRS_MORPHOLOGY_MONITOR = new QLineEdit(groupBox_HeartClass);
        edit_QRS_MORPHOLOGY_MONITOR->setObjectName(QStringLiteral("edit_QRS_MORPHOLOGY_MONITOR"));

        horizontalLayout_3->addWidget(edit_QRS_MORPHOLOGY_MONITOR);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_HeartClass);


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
