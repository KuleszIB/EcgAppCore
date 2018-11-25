#include "hrv_dfa.h"
#include "ui_hrv_dfa.h"

HRV_dfa::HRV_dfa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV_dfa)
{
    ui->setupUi(this);
}

HRV_dfa::~HRV_dfa()
{
    delete ui;
}
