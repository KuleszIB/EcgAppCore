/********************************************************************************
** Form generated from reading UI file 't_alt_class.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_ALT_CLASS_H
#define UI_T_ALT_CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T_alt_class
{
public:
    QGroupBox *groupBox;
    QPushButton *Button_Run;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Alterans;
    QLineEdit *line_ALT1;
    QLineEdit *line_Alt2;

    void setupUi(QWidget *T_alt_class)
    {
        if (T_alt_class->objectName().isEmpty())
            T_alt_class->setObjectName(QStringLiteral("T_alt_class"));
        T_alt_class->resize(749, 243);
        groupBox = new QGroupBox(T_alt_class);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 721, 221));
        Button_Run = new QPushButton(groupBox);
        Button_Run->setObjectName(QStringLiteral("Button_Run"));
        Button_Run->setGeometry(QRect(50, 20, 75, 23));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 70, 135, 70));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Alterans = new QLabel(widget);
        label_Alterans->setObjectName(QStringLiteral("label_Alterans"));

        verticalLayout->addWidget(label_Alterans);

        line_ALT1 = new QLineEdit(widget);
        line_ALT1->setObjectName(QStringLiteral("line_ALT1"));

        verticalLayout->addWidget(line_ALT1);

        line_Alt2 = new QLineEdit(widget);
        line_Alt2->setObjectName(QStringLiteral("line_Alt2"));

        verticalLayout->addWidget(line_Alt2);


        retranslateUi(T_alt_class);

        QMetaObject::connectSlotsByName(T_alt_class);
    } // setupUi

    void retranslateUi(QWidget *T_alt_class)
    {
        T_alt_class->setWindowTitle(QApplication::translate("T_alt_class", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("T_alt_class", "T_Alterans", nullptr));
        Button_Run->setText(QApplication::translate("T_alt_class", "Run", nullptr));
        label_Alterans->setText(QApplication::translate("T_alt_class", "<html><head/><body><p><span style=\" font-size:10pt;\">Alterans</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T_alt_class: public Ui_T_alt_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_ALT_CLASS_H
