#include "hrv1_gui.h"
#include "ui_hrv1_gui.h"

HRV1_gui::HRV1_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV1_gui)
{
    ui->setupUi(this);
}

HRV1_gui::~HRV1_gui()
{
    delete ui;
}
