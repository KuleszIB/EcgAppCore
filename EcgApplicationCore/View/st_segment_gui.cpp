#include "st_segment_gui.h"
#include "ui_st_segment_gui.h"

St_segment_gui::St_segment_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::St_segment_gui)
{
    ui->setupUi(this);
}

St_segment_gui::~St_segment_gui()
{
    delete ui;
}
