#include "r_peaks_gui.h"
#include "ui_r_peaks_gui.h"

R_peaks_gui::R_peaks_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::R_peaks_gui)
{
    ui->setupUi(this);
    QVBoxLayout *layout;
    layout = new QVBoxLayout;
    qrsPlot2=new qrsplot(this);
    layout->addWidget(qrsPlot2);
    ui->qrsPlot->setLayout(layout);

}

void R_peaks_gui::addRandomGraph() //Przykładowy wykres
{
    QVector<double> x(1001), y(1001); // initialize with entries 0..100
    for (int i=0; i<1001; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    qrsPlot2->setData();
    // create graph and assign data to it:

    // set axes ranges, so we see all data:
    //ui->ecgPlot->xAxis->setRange(-1, 1);
    //ui->ecgPlot->yAxis->setRange(0, 1);
  }
R_peaks_gui::~R_peaks_gui()
{
    delete ui;
}




void R_peaks_gui::prog1()
{


}
void R_peaks_gui::prog2()
{


}

void R_peaks_gui::peakDetection()
{



}

void R_peaks_gui::on_detectPeaksButton_clicked()
{
    if(ui->checkBoxR->isChecked())
    {
        return prog1();
    }
    if(ui->checkBoxQRSonset->isChecked())
    {
        return prog2();
    }

}



void R_peaks_gui::on_checkBoxR_toggled(bool checked)
{
    if(checked)
    {
        addRandomGraph();
    }
}
