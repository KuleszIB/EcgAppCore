#include "hrv2poincareplot.h"

hrv2poincareplot::hrv2poincareplot(QWidget *parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Sygnał");
    signal->attach(this);

    setAxisTitle(QwtPlot::yLeft, "RR_n+1 [ms]");
    setAxisTitle(QwtPlot::xBottom, "RR_n [ms]");

}
hrv2poincareplot::~hrv2poincareplot()
{

    delete signal;
}

void hrv2poincareplot::setData2(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    replot();
}
