#include "ecgplot.h"

ecgplot::ecgplot(QWidget *parent) : QwtPlot(parent)
{   
    //setMinimumHeight(20);
    //setMinimumWidth(40);
    plot = new QwtPlot();
    plot->setMinimumHeight(2*(plot->sizeHint().height()) );
    signal = new QwtPlotCurve("Signal");
    signal->attach(this);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Amplituda [mV]");
    setAxisTitle(QwtPlot::xBottom, "Czas [mm:ss.ms]");

    }

ecgplot::~ecgplot()
{
    delete signal;
}



void ecgplot::setData(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    replot();
}
QSize ecgplot::sizeHint() const
{
    return QSize( 540, 400 );
}
//void ecgplot::clear()
//{

//    ecg_x.clear();
//   ecg_y.clear();
  //  replot();
//}


