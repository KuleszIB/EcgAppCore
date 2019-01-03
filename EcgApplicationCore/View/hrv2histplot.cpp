#include "hrv2histplot.h"

hrv2histplot::hrv2histplot(QWidget *parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Sygnał");
    signal->attach(this);

    setAxisTitle(QwtPlot::yLeft, "L. wystąpień");
    setAxisTitle(QwtPlot::xBottom, "Czas [ms]");

}

hrv2histplot::~hrv2histplot()
{
    delete signal;
}
