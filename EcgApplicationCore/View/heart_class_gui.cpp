#include "heart_class_gui.h"
#include "ui_heart_class_gui.h"

Heart_class_gui::Heart_class_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Heart_class_gui)
{
    ui->setupUi(this);
}

Heart_class_gui::~Heart_class_gui()
{
    delete ui;
}
