#include "st_segment.h"
#include "ui_st_segment.h"

St_segment::St_segment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::St_segment)
{
    ui->setupUi(this);
}

St_segment::~St_segment()
{
    delete ui;
}
