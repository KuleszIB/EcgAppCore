#include "r_peaks.h"
#include "ui_r_peaks.h"

R_peaks::R_peaks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::R_peaks)
{
    ui->setupUi(this);
}

R_peaks::~R_peaks()
{
    delete ui;
}
