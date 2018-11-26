#include "heart_class.h"
#include "ui_heart_class.h"

Heart_class::Heart_class(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Heart_class)
{
    ui->setupUi(this);
}

Heart_class::~Heart_class()
{
    delete ui;
}
