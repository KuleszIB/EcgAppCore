#include "hrv_dfa_gui.h"
#include "ui_hrv_dfa_gui.h"

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
