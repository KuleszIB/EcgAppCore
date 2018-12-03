/********************************************************************************
** Form generated from reading UI file 'ui_hrv_dfa.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_HRV_DFA_H
#define UI_UI_HRV_DFA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HRV_dfa
{
public:
    QGroupBox *groupBoxHRV_DFA;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *HRV_dfa)
    {
        if (HRV_dfa->objectName().isEmpty())
            HRV_dfa->setObjectName(QStringLiteral("HRV_dfa"));
        HRV_dfa->resize(400, 300);
        groupBoxHRV_DFA = new QGroupBox(HRV_dfa);
        groupBoxHRV_DFA->setObjectName(QStringLiteral("groupBoxHRV_DFA"));
        groupBoxHRV_DFA->setGeometry(QRect(10, 30, 301, 211));
        pushButton = new QPushButton(groupBoxHRV_DFA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        label = new QLabel(groupBoxHRV_DFA);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 101, 16));

        retranslateUi(HRV_dfa);

        QMetaObject::connectSlotsByName(HRV_dfa);
    } // setupUi

    void retranslateUi(QWidget *HRV_dfa)
    {
        HRV_dfa->setWindowTitle(QApplication::translate("HRV_dfa", "Form", nullptr));
        groupBoxHRV_DFA->setTitle(QApplication::translate("HRV_dfa", "HRV DFA", nullptr));
        pushButton->setText(QApplication::translate("HRV_dfa", "Run", nullptr));
        label->setText(QApplication::translate("HRV_dfa", "Analysis paremeters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV_dfa: public Ui_HRV_dfa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_HRV_DFA_H
