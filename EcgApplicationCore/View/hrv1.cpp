#include "hrv1.h"
#include "ui_hrv1.h"

HRV1::HRV1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV1)
{
    ui->setupUi(this);
}

HRV1::~HRV1()
{
    delete ui;
}
