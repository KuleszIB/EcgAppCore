/********************************************************************************
** Form generated from reading UI file 't_alt_class_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_ALT_CLASS_GUI_H
#define UI_T_ALT_CLASS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T_alt_class_gui
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *Button_Run;
    QVBoxLayout *verticalLayout;
    QLabel *label_Alterans;
    QLineEdit *line_ALT1;
    QLineEdit *line_Alt2;

    void setupUi(QWidget *T_alt_class_gui)
    {
        if (T_alt_class_gui->objectName().isEmpty())
            T_alt_class_gui->setObjectName(QStringLiteral("T_alt_class_gui"));
        T_alt_class_gui->resize(749, 243);
        groupBox = new QGroupBox(T_alt_class_gui);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 157, 134));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Button_Run = new QPushButton(groupBox);
        Button_Run->setObjectName(QStringLiteral("Button_Run"));

        gridLayout->addWidget(Button_Run, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Alterans = new QLabel(groupBox);
        label_Alterans->setObjectName(QStringLiteral("label_Alterans"));

        verticalLayout->addWidget(label_Alterans);

        line_ALT1 = new QLineEdit(groupBox);
        line_ALT1->setObjectName(QStringLiteral("line_ALT1"));

        verticalLayout->addWidget(line_ALT1);

        line_Alt2 = new QLineEdit(groupBox);
        line_Alt2->setObjectName(QStringLiteral("line_Alt2"));

        verticalLayout->addWidget(line_Alt2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(T_alt_class_gui);

        QMetaObject::connectSlotsByName(T_alt_class_gui);
    } // setupUi

    void retranslateUi(QWidget *T_alt_class_gui)
    {
        T_alt_class_gui->setWindowTitle(QApplication::translate("T_alt_class_gui", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("T_alt_class_gui", "T_Alterans", nullptr));
        Button_Run->setText(QApplication::translate("T_alt_class_gui", "Run", nullptr));
        label_Alterans->setText(QApplication::translate("T_alt_class_gui", "<html><head/><body><p><span style=\" font-size:10pt;\">Alterans</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T_alt_class_gui: public Ui_T_alt_class_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_ALT_CLASS_GUI_H
