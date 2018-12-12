/********************************************************************************
** Form generated from reading UI file 't_alt_class_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_ALT_CLASS_GUI_H
#define UI_T_ALT_CLASS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QPushButton *button;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Alterans;
    QLineEdit *line_ALT1;
    QLineEdit *line_Alt2;
    QWidget *ecgPlot;

    void setupUi(QWidget *T_alt_class_gui)
    {
        if (T_alt_class_gui->objectName().isEmpty())
            T_alt_class_gui->setObjectName(QStringLiteral("T_alt_class_gui"));
        T_alt_class_gui->resize(749, 282);
        groupBox = new QGroupBox(T_alt_class_gui);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 721, 261));
        button = new QPushButton(groupBox);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(50, 20, 75, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 70, 135, 70));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Alterans = new QLabel(layoutWidget);
        label_Alterans->setObjectName(QStringLiteral("label_Alterans"));

        verticalLayout->addWidget(label_Alterans);

        line_ALT1 = new QLineEdit(layoutWidget);
        line_ALT1->setObjectName(QStringLiteral("line_ALT1"));

        verticalLayout->addWidget(line_ALT1);

        line_Alt2 = new QLineEdit(layoutWidget);
        line_Alt2->setObjectName(QStringLiteral("line_Alt2"));

        verticalLayout->addWidget(line_Alt2);

        ecgPlot = new QWidget(groupBox);
        ecgPlot->setObjectName(QStringLiteral("ecgPlot"));
        ecgPlot->setGeometry(QRect(220, 10, 311, 241));

        retranslateUi(T_alt_class_gui);

        QMetaObject::connectSlotsByName(T_alt_class_gui);
    } // setupUi

    void retranslateUi(QWidget *T_alt_class_gui)
    {
        T_alt_class_gui->setWindowTitle(QApplication::translate("T_alt_class_gui", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("T_alt_class_gui", "T_Alterans", nullptr));
        button->setText(QApplication::translate("T_alt_class_gui", "Run", nullptr));
        label_Alterans->setText(QApplication::translate("T_alt_class_gui", "<html><head/><body><p><span style=\" font-size:10pt;\">Alterans</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T_alt_class_gui: public Ui_T_alt_class_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_ALT_CLASS_GUI_H
