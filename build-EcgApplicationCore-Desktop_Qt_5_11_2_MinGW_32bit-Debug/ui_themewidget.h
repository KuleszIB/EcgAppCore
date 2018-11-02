/********************************************************************************
** Form generated from reading UI file 'themewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEWIDGET_H
#define UI_THEMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeWidgetForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *themeLabel;
    QComboBox *themeComboBox;
    QLabel *animatedLabel;
    QComboBox *animatedComboBox;
    QLabel *legendLabel;
    QComboBox *legendComboBox;
    QCheckBox *antialiasCheckBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ThemeWidgetForm)
    {
        if (ThemeWidgetForm->objectName().isEmpty())
            ThemeWidgetForm->setObjectName(QStringLiteral("ThemeWidgetForm"));
        ThemeWidgetForm->resize(900, 600);
        gridLayout = new QGridLayout(ThemeWidgetForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        themeLabel = new QLabel(ThemeWidgetForm);
        themeLabel->setObjectName(QStringLiteral("themeLabel"));

        horizontalLayout->addWidget(themeLabel);

        themeComboBox = new QComboBox(ThemeWidgetForm);
        themeComboBox->setObjectName(QStringLiteral("themeComboBox"));

        horizontalLayout->addWidget(themeComboBox);

        animatedLabel = new QLabel(ThemeWidgetForm);
        animatedLabel->setObjectName(QStringLiteral("animatedLabel"));

        horizontalLayout->addWidget(animatedLabel);

        animatedComboBox = new QComboBox(ThemeWidgetForm);
        animatedComboBox->setObjectName(QStringLiteral("animatedComboBox"));

        horizontalLayout->addWidget(animatedComboBox);

        legendLabel = new QLabel(ThemeWidgetForm);
        legendLabel->setObjectName(QStringLiteral("legendLabel"));

        horizontalLayout->addWidget(legendLabel);

        legendComboBox = new QComboBox(ThemeWidgetForm);
        legendComboBox->setObjectName(QStringLiteral("legendComboBox"));

        horizontalLayout->addWidget(legendComboBox);

        antialiasCheckBox = new QCheckBox(ThemeWidgetForm);
        antialiasCheckBox->setObjectName(QStringLiteral("antialiasCheckBox"));
        antialiasCheckBox->setChecked(false);

        horizontalLayout->addWidget(antialiasCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);


        retranslateUi(ThemeWidgetForm);
        QObject::connect(themeComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));
        QObject::connect(antialiasCheckBox, SIGNAL(toggled(bool)), ThemeWidgetForm, SLOT(updateUI()));
        QObject::connect(legendComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));
        QObject::connect(animatedComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));

        QMetaObject::connectSlotsByName(ThemeWidgetForm);
    } // setupUi

    void retranslateUi(QWidget *ThemeWidgetForm)
    {
        themeLabel->setText(QApplication::translate("ThemeWidgetForm", "Theme:", nullptr));
        animatedLabel->setText(QApplication::translate("ThemeWidgetForm", "Animation:", nullptr));
        legendLabel->setText(QApplication::translate("ThemeWidgetForm", "Legend:", nullptr));
        antialiasCheckBox->setText(QApplication::translate("ThemeWidgetForm", "Anti-aliasing", nullptr));
        Q_UNUSED(ThemeWidgetForm);
    } // retranslateUi

};

namespace Ui {
    class ThemeWidgetForm: public Ui_ThemeWidgetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEWIDGET_H
