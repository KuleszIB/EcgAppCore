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
 }
R_peaks_gui::~R_peaks_gui()
{
    delete ui;
}




void R_peaks_gui::peakDetection()
{



}



void R_peaks_gui::filter1()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = sin(x[i]); // let's plot a quadratic function
        }
        qrsPlot2->setData2(x,y);
      }


void R_peaks_gui::filter2()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = cos(x[i]); // let's plot a quadratic function
        }
        qrsPlot2->setData2(x,y);
      }


void R_peaks_gui::filter3()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = exp(x[i]); // let's plot a quadratic function
        }
        qrsPlot2->setData2(x,y);
      }



void R_peaks_gui::filter4()
    {
        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = (x[i]); // let's plot a quadratic function
        }
        qrsPlot2->setData2(x,y);
     }



void R_peaks_gui::on_pushButton_clicked()
{
    if(ui->checkBoxR->isChecked())
    {
        return filter1();
    }
    if(ui->checkBoxQRSonset->isChecked())
    {
        return filter2();
    }
    if(ui->checkBoxR->isChecked())
    {
        return filter3();
    }
    if(ui->checkBoxQRSend->isChecked())
    {
        return filter4();
    }

}
