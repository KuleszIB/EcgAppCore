#include "t_alt_class.h"
#include "ui_t_alt_class.h"

T_alt_class::T_alt_class(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::T_alt_class)
{
    ui->setupUi(this);
}

T_alt_class::~T_alt_class()
{
    delete ui;
}
