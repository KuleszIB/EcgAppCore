#include "hrv2histplot.h"

hrv2histplot::hrv2histplot(QWidget *parent)
{
    plot = new QwtPlot();
    plot->setTitle("Histogram");
 //   signal = new QwtPlotCurve("Frequency");
   // signal->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Number of intervals");
    setAxisTitle(QwtPlot::xBottom, "RR [s]");

    histogram = new QwtPlotHistogram();
    histogram->attach( this );
//  rr = new QwtPlotCurve("RR");
//	rr->setStyle(QwtPlotCurve::Sticks);
//	rr->setOrientation(Qt::Orientation::Vertical);
//	rr->attach(this);



replot();


}

hrv2histplot::~hrv2histplot()
{
    delete signal;
    delete histogram;
}

//void hrv2histplot::setDataHISTOGRAM(const QVector<QwtIntervalSample> &samples )
//    {

//    histogram->setData(new QwtIntervalSeriesData(samples));


//}



void hrv2histplot::setValues( int numValues, QVector<double> values )
{

    QVector<QwtIntervalSample> samples( numValues );
    for ( uint i = 0; i < numValues; i++ )
    {
        QwtInterval interval( double( i ), i + 1.0 );
        interval.setBorderFlags( QwtInterval::ExcludeMaximum );

        samples[i] = QwtIntervalSample( values[i], interval );
    }

    histogram->setData(new QwtIntervalSeriesData(samples));
    replot();
}
