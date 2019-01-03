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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HRV_dfa_gui
{
public:
    QGroupBox *groupBoxHRV_DFA;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *HRV_dfa_gui)
    {
        if (HRV_dfa_gui->objectName().isEmpty())
            HRV_dfa_gui->setObjectName(QStringLiteral("HRV_dfa_gui"));
        HRV_dfa_gui->resize(1024, 713);
        groupBoxHRV_DFA = new QGroupBox(HRV_dfa_gui);
        groupBoxHRV_DFA->setObjectName(QStringLiteral("groupBoxHRV_DFA"));
        groupBoxHRV_DFA->setGeometry(QRect(0, 10, 1001, 681));
        label = new QLabel(groupBoxHRV_DFA);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 130, 101, 16));
        layoutWidget = new QWidget(groupBoxHRV_DFA);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 231, 71));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(4);
        spinBox->setMaximum(64);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(4);
        spinBox_2->setMaximum(64);

        horizontalLayout_2->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        tableWidget = new QTableWidget(groupBoxHRV_DFA);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 160, 541, 81));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);
        tableWidget->verticalHeader()->setMinimumSectionSize(28);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(true);

        retranslateUi(HRV_dfa_gui);

        QMetaObject::connectSlotsByName(HRV_dfa_gui);
    } // setupUi

    void retranslateUi(QWidget *HRV_dfa_gui)
    {
        HRV_dfa_gui->setWindowTitle(QApplication::translate("HRV_dfa_gui", "Form", nullptr));
        groupBoxHRV_DFA->setTitle(QApplication::translate("HRV_dfa_gui", "HRV DFA", nullptr));
        label->setText(QApplication::translate("HRV_dfa_gui", "Analysis paremeters", nullptr));
        label_3->setText(QApplication::translate("HRV_dfa_gui", "Min delta_m", nullptr));
        label_2->setText(QApplication::translate("HRV_dfa_gui", "Max delta_m", nullptr));
        pushButton->setText(QApplication::translate("HRV_dfa_gui", "Run", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("HRV_dfa_gui", "Short-term analysis alfa", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("HRV_dfa_gui", "Long-term analysis alfa", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("HRV_dfa_gui", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HRV_dfa_gui: public Ui_HRV_dfa_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRV_DFA_GUI_H
