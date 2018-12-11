#include "qrsplot.h"

qrsplot::qrsplot(QWidget *parent) :
    QwtPlot(parent)
{
    setAxisTitle(QwtPlot::xBottom, "czas [s]");
    setAxisTitle(QwtPlot::yLeft, "Amplituda [mV]");

    signal = new QwtPlotCurve("Sygnał");
    signal->attach(this);


    qrs_onset = new QwtPlotMarker();
    qrs_onset->attach(this);

    qrs_end = new QwtPlotMarker();
    qrs_end->attach(this);

    t_end = new QwtPlotMarker();
    t_end->attach(this);



}

qrsplot::~qrsplot()
{
    delete signal;
    delete qrs_onset;
    delete qrs_end;
    delete t_end;
    delete p_onset;
    delete p_end;
    delete t_wave;
}

void qrsplot::setData()
{
    QVector<QPointF> data;
    QVector<double> signal;
    size_t signal_size=signal.size();

//   for (int i = 0; i < signal_size; ++i)
//	{
//        data.push_back(...)
//	}
    replot();
}
