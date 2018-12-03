#include "hrv2.h"
#include "ui_hrv2.h"

HRV2::HRV2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV2)
{
    ui->setupUi(this);
}

HRV2::~HRV2()
{
    delete ui;
}
