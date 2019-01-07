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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HRV_dfa_gui
{
public:
    QGroupBox *groupBoxHRV_DFA;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *HRV_dfa_gui)
    {
        if (HRV_dfa_gui->objectName().isEmpty())
            HRV_dfa_gui->setObjectName(QStringLiteral("HRV_dfa_gui"));
        HRV_dfa_gui->resize(400, 300);
        groupBoxHRV_DFA = new QGroupBox(HRV_dfa_gui);
        groupBoxHRV_DFA->setObjectName(QStringLiteral("groupBoxHRV_DFA"));
        groupBoxHRV_DFA->setGeometry(QRect(10, 30, 119, 77));
        gridLayout_2 = new QGridLayout(groupBoxHRV_DFA);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(groupBoxHRV_DFA);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        label = new QLabel(groupBoxHRV_DFA);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


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
