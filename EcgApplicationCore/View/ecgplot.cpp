#include "ecgplot.h"

ecgplot::ecgplot(QWidget *parent) : QwtPlot(parent)
{   

    plot = new QwtPlot();
    signal = new QwtPlotCurve("Sygnał");
    signal->attach(this);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Amplituda [mV]");
    setAxisTitle(QwtPlot::xBottom, "Czas [mm:ss.ms]");
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


