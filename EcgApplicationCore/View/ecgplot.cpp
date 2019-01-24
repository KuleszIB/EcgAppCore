#include "ecgplot.h"

ecgplot::ecgplot(QWidget *parent) : QwtPlot(parent)
{   
   plot = new QwtPlot();
    signal = new QwtPlotCurve("Signal");
    signal->attach(this);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Amplitude [mV]");
    setAxisTitle(QwtPlot::xBottom, "Time [s]");
 //   setAxisScale( xBottom, 0.0, 20.0 );
 //   setAxisScale( yLeft, -1.0, 1.0 );
    odd=new QwtPlotCurve("Odd");
    odd->setPen(QPen(Qt::red, 2.0));
    odd->attach(this);
    even=new QwtPlotCurve("Even");
    even->setPen(QPen(Qt::blue, 2.0));
    even->attach(this);

//    QwtLegend *legend = new QwtLegend;
//       legend->setDefaultItemMode( QwtLegendData::Checkable );
//       insertLegend( legend, QwtPlot::RightLegend );

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

    }

ecgplot::~ecgplot()
{
    delete signal;
}



void ecgplot::setData(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    setAxisScale( xBottom, 0.0, 20.0 );
    setAxisScale( yLeft, -1.0, 1.0 );
    replot();
}


void ecgplot::setData2(QVector<double> x, QVector<double> y,  QVector<double> z)
{
    odd->setSamples(x, y);
    even->setSamples(x, z);
    setAxisScale( xBottom, 0.0, 0.23 );
    setAxisScale( yLeft, -0.1, 0.1 );

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


