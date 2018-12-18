/********************************************************************************
** Form generated from reading UI file 'hrv_dfa_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRV_DFA_GUI_H
#define UI_HRV_DFA_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HRV_dfa_gui
{
public:
    QGroupBox *groupBoxHRV_DFA;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *HRV_dfa_gui)
    {
        if (HRV_dfa_gui->objectName().isEmpty())
            HRV_dfa_gui->setObjectName(QStringLiteral("HRV_dfa_gui"));
        HRV_dfa_gui->resize(1024, 713);
        groupBoxHRV_DFA = new QGroupBox(HRV_dfa_gui);
        groupBoxHRV_DFA->setObjectName(QStringLiteral("groupBoxHRV_DFA"));
        groupBoxHRV_DFA->setGeometry(QRect(10, 10, 1001, 681));
        pushButton = new QPushButton(groupBoxHRV_DFA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        label = new QLabel(groupBoxHRV_DFA);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 101, 16));

        retranslateUi(HRV_dfa_gui);

        QMetaObject::connectSlotsByName(HRV_dfa_gui);
    } // setupUi

    void retranslateUi(QWidget *HRV_dfa_gui)
    {
        HRV_dfa_gui->setWindowTitle(QApplication::translate("HRV_dfa_gui", "Form", nullptr));
        groupBoxHRV_DFA->setTitle(QApplication::translate("HRV_dfa_gui", "HRV DFA", nullptr));
        pushButton->setText(QApplication::translate("HRV_dfa_gui", "Run", nullptr));
        label->setText(QApplication::translate("HRV_dfa_gui", "Analysis paremeters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV_dfa_gui: public Ui_HRV_dfa_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRV_DFA_GUI_H
