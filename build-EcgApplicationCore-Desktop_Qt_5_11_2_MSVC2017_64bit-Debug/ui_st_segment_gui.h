/********************************************************************************
** Form generated from reading UI file 'st_segment_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ST_SEGMENT_GUI_H
#define UI_ST_SEGMENT_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_St_segment_gui
{
public:
    QGroupBox *groupBox_STSegment;
    QPushButton *pushButton;

    void setupUi(QWidget *St_segment_gui)
    {
        if (St_segment_gui->objectName().isEmpty())
            St_segment_gui->setObjectName(QStringLiteral("St_segment_gui"));
        St_segment_gui->resize(400, 300);
        groupBox_STSegment = new QGroupBox(St_segment_gui);
        groupBox_STSegment->setObjectName(QStringLiteral("groupBox_STSegment"));
        groupBox_STSegment->setGeometry(QRect(20, 30, 361, 241));
        pushButton = new QPushButton(groupBox_STSegment);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 75, 23));

        retranslateUi(St_segment_gui);

        QMetaObject::connectSlotsByName(St_segment_gui);
    } // setupUi

    void retranslateUi(QWidget *St_segment_gui)
    {
        St_segment_gui->setWindowTitle(QApplication::translate("St_segment_gui", "Form", nullptr));
        groupBox_STSegment->setTitle(QApplication::translate("St_segment_gui", "ST segment", nullptr));
        pushButton->setText(QApplication::translate("St_segment_gui", "Run", nullptr));
    } // retranslateUi

};

namespace Ui {
    class St_segment_gui: public Ui_St_segment_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ST_SEGMENT_GUI_H
