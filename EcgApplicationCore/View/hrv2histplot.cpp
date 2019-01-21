#include "hrv2histplot.h"


hrv2histplot::hrv2histplot(QWidget *parent)
{
    plot = new QwtPlot();
    plot->setTitle("Histogram");
 //   signal = new QwtPlotCurve("Frequency");
   // signal->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Numbers of RR intervals");
    setAxisTitle(QwtPlot::xBottom, "RR [s]");

    histogram = new QwtPlotHistogram();
    histogram->attach( this );
//  rr = new QwtPlotCurve("RR");
//	rr->setStyle(QwtPlotCurve::Sticks);
//	rr->setOrientation(Qt::Orientation::Vertical);
//	rr->attach(this);
    signal = new QwtPlotCurve("RR");
    signal->setStyle(QwtPlotCurve::Sticks);
    signal->setOrientation(Qt::Orientation::Vertical);
    signal->attach(this);

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



//void hrv2histplot::setValues( int numValues, const QwtIntervalData  &values22 )
//{
//    double min = *std::min_element(values.constBegin(), values.constEnd());
//    double max = *std::max_element(values.constBegin(), values.constEnd());
//    QVector<QwtIntervalSample> samples( numValues );
//    for ( uint i = 0; i < numValues; i++ )
//    {
//        QwtInterval interval(min,max );
//        interval.setBorderFlags( QwtInterval::IncludeBorders );

//        samples[i] = QwtIntervalSample( values[i], interval );
//    }

//    histogram->setData(new QwtIntervalSeriesData(samples));
//    replot();


//    QwtArray<QwtDoubleInterval> intervals(numValues);
//        QwtArray<double> values1(numValues);

//        double pos = 0.0;
//        for ( int i = 0; i < (int)intervals.size(); i++ )
//        {
//            const int width = 5 + rand() % 15;
//            //const int value = rand() % 100;
//            //int width=bins;
//            intervals[i] = QwtDoubleInterval(pos, pos + double(width));
//         //   values1[i] = int(values22[i]);

//            pos += width;
//        }

   //     histogram->setData(QwtIntervalData(intervals, values1));
      //  histogram->attach();


//}



void hrv2histplot::setValues2( QVector<double> a,QVector<double>b )
{
        signal->setSamples(a,b);
        replot();

}
