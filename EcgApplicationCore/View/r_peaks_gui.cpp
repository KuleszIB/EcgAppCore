#include "r_peaks_gui.h"
#include "ui_r_peaks_gui.h"

R_peaks_gui::R_peaks_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::R_peaks_gui)
{
    ui->setupUi(this);
}

R_peaks_gui::~R_peaks_gui()
{
    delete ui;
}
