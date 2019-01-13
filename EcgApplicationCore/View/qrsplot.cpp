#include "qrsplot.h"

qrsplot::qrsplot(QWidget *parent) :
    QwtPlot(parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Signal");
    signal->attach(this);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Amplitude [mV]");
    setAxisTitle(QwtPlot::xBottom, "Time [mm:ss.ms]");

    setAxisScale( xBottom, 0.0, 20.0 );
    setAxisScale( yLeft, -1.0, 1.0 );


    // canvas
    QwtPlotCanvas *canvas = new QwtPlotCanvas();
    canvas->setLineWidth( 1 );
    canvas->setFrameStyle( QFrame::Box | QFrame::Plain );
    canvas->setBorderRadius( 15 );

    QPalette canvasPalette( Qt::white );
    canvasPalette.setColor( QPalette::Foreground, QColor( 133, 190, 232 ) );
    canvas->setPalette( canvasPalette );

    setCanvas( canvas );

    // panning with the left mouse button
    ( void ) new QwtPlotPanner( canvas );

    // zoom in/out with the wheel
    ( void ) new QwtPlotMagnifier( canvas );


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

void qrsplot::setData2(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    replot();
}
//void qrsplot::setWave(QwtPlotMarker *Marko, QVector<double> x, QVector<double> y, QVector<double> peaks)
//{
   

  
//        QVector<QPointF> peak;
//        for (QVector<double>::iterator i = x.begin(); i < x.end(); i++)
//        {
//            for(QVector<double>::iterator j = y.begin(); j < y.end(); j++)
//            {
//                for (QVector<double>::iterator k = peaks.begin(); k < peaks.end(); k++)
//                {
//                    if(*i == *j)
//                    {
//                        peak.append(QPointF(float(*k), float(*j)));
//                    }
//                }
//            }
//        }
//        Marko->setValue(float(peaks), );
    
    
    
//    replot();
//}

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
