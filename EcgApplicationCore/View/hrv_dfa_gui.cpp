#include "hrv_dfa_gui.h"
#include "ui_hrv_dfa_gui.h"
#include "Modules/hrv_dfa_module.h"

HRV_dfa_gui::HRV_dfa_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV_dfa_gui)
{
    ui->setupUi(this);
}

HRV_dfa_gui::~HRV_dfa_gui()
{
    delete ui;
}

void HRV_dfa_gui::on_pushButton_clicked()
{
    int deltaMaxValue = ui->deltaMax->value();
    int deltaMinValue = ui->deltaMin->value();
    QTableWidgetItem *theItem = new QTableWidgetItem();
    theItem->setData(Qt::EditRole, deltaMaxValue);
    ui->tableWidget->setItem(1, 0, theItem);
    QTableWidgetItem *theItem1 = new QTableWidgetItem();
    theItem1->setData(Qt::EditRole, deltaMinValue);
    ui->tableWidget->setItem(1, 1, theItem1);

}
