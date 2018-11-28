/********************************************************************************
** Form generated from reading UI file 'ui_st_segment.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_ST_SEGMENT_H
#define UI_UI_ST_SEGMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_St_segment
{
public:
    QGroupBox *groupBox_STSegment;
    QPushButton *pushButton;

    void setupUi(QWidget *St_segment)
    {
        if (St_segment->objectName().isEmpty())
            St_segment->setObjectName(QStringLiteral("St_segment"));
        St_segment->resize(400, 300);
        groupBox_STSegment = new QGroupBox(St_segment);
        groupBox_STSegment->setObjectName(QStringLiteral("groupBox_STSegment"));
        groupBox_STSegment->setGeometry(QRect(20, 30, 361, 241));
        pushButton = new QPushButton(groupBox_STSegment);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 75, 23));

        retranslateUi(St_segment);

        QMetaObject::connectSlotsByName(St_segment);
    } // setupUi

    void retranslateUi(QWidget *St_segment)
    {
        St_segment->setWindowTitle(QApplication::translate("St_segment", "Form", nullptr));
        groupBox_STSegment->setTitle(QApplication::translate("St_segment", "ST segment", nullptr));
        pushButton->setText(QApplication::translate("St_segment", "Run", nullptr));
    } // retranslateUi

};

namespace Ui {
    class St_segment: public Ui_St_segment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_ST_SEGMENT_H
