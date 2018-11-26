#include "ecgbaseline.h"
#include "ui_ecgbaseline.h"

ECGbaseline::ECGbaseline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ECGbaseline)
{
    ui->setupUi(this);
}

ECGbaseline::~ECGbaseline()
{
    delete ui;
}
