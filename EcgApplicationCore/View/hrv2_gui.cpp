#include "hrv2_gui.h"
#include "ui_hrv2_gui.h"

HRV2_gui::HRV2_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV2_gui)
{
    ui->setupUi(this);
}

HRV2_gui::~HRV2_gui()
{
    delete ui;
}
