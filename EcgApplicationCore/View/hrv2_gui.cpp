#include "hrv2_gui.h"
#include "ui_hrv2_gui.h"

HRV2_gui::HRV2_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HRV2_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    hrv2poincarePlot2 = new hrv2poincareplot(this);
    layout->addWidget(hrv2poincarePlot2);
    ui->hrv2poincarePlot->setLayout(layout);

    QVBoxLayout *layout2;
    layout2 = new QVBoxLayout;
    hrv2histPlot2 = new hrv2histplot(this);
    layout2->addWidget(hrv2histPlot2);
    ui->hrv2histPlot->setLayout(layout2);



}

HRV2_gui::~HRV2_gui()
{
    delete ui;
}
