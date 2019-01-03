#include "t_alt_class_gui.h"
#include "ui_t_alt_class_gui.h"

T_alt_class_gui::T_alt_class_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::T_alt_class_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    ecgPlot2 = new ecgplot(this);
    layout->addWidget(ecgPlot2);
    ui->ecgPlot->setLayout(layout);
    connect(ui->button, SIGNAL(clicked()),this, SLOT(addRandomGraph()));

}

T_alt_class_gui::~T_alt_class_gui()
{
    delete ui;
}
void T_alt_class_gui::addRandomGraph() //Przykładowy wykres
{
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = cos(x[i]); // let's plot a quadratic function
    }
    ecgPlot2->setData(x,y);
  }
