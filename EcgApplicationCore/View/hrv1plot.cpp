#include "hrv1plot.h"

hrv1plot::hrv1plot(QWidget *parent) :  QwtPlot(parent)
{   
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Sygnał");
    signal->attach(this);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->attach(this);
    setAxisTitle(QwtPlot::yLeft, "PSD [db/Hz]");
    setAxisTitle(QwtPlot::xBottom, "Częstotliwość [Hz]");

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

hrv1plot::~hrv1plot()
{

    delete signal;
}

void hrv1plot::setData2(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    replot();
}
