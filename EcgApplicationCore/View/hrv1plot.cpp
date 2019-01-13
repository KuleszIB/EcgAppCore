#include "hrv1plot.h"

hrv1plot::hrv1plot(QWidget *parent) :  QwtPlot(parent)
{   
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Power");
    signal->setStyle(QwtPlotCurve::Sticks);
    signal->setOrientation(Qt::Orientation::Vertical);
    signal->attach(this);

    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->attach(this);

    ulf = new QwtPlotCurve();
    ulf->setStyle(QwtPlotCurve::Sticks);
    ulf->setPen(QPen(Qt::darkGray, 0, Qt::DashLine));
    ulf->attach(this);

    vlf = new QwtPlotCurve();
    vlf->setStyle(QwtPlotCurve::Sticks);
    vlf->setPen(QPen(Qt::red, 0, Qt::DashLine));
    vlf->attach(this);

    lf = new QwtPlotCurve();
    lf->setStyle(QwtPlotCurve::Sticks);
    lf->setPen(QPen(Qt::blue, 0, Qt::DashLine));
    lf->attach(this);

    hf = new QwtPlotCurve();
    hf->setStyle(QwtPlotCurve::Sticks);
    hf->setPen(QPen(Qt::green, 0, Qt::DashLine));
    hf->attach(this);

//    vlf = new QwtPlotMarker();
//    vlf->setLineStyle(QwtPlotMarker::VLine);
//    vlf->setLabel(tr("VLF"));
//    vlf->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    vlf->setLinePen(QPen(Qt::red, 0, Qt::DashLine));
//    vlf->attach(this);

//    lf = new QwtPlotMarker();
//    lf->setLineStyle(QwtPlotMarker::VLine);
//    lf->setLabel(tr("LF"));
//    lf->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    lf->setLinePen(QPen(Qt::red, 0, Qt::DashLine));
//    lf->attach(this);

//    hf = new QwtPlotMarker();
//    hf->setLineStyle(QwtPlotMarker::VLine);
//    hf->setLabel(tr("HF"));
//    hf->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    hf->setLinePen(QPen(Qt::red, 0, Qt::DashLine));
//    hf->attach(this);

//    setAxisTitle(QwtPlot::yLeft, "PSD [db/Hz]");
//    setAxisTitle(QwtPlot::xBottom, "Częstotliwość [Hz]");

    setAxisScale( xBottom, 0.0, 20.0 );
    setAxisScale( yLeft, -1.0, 1.0 );


    setAxisTitle(QwtPlot::xBottom, "Frequency [Hz]");
    setAxisTitle(QwtPlot::yLeft, "Power [db/Hz]");


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
    delete ulf;
    delete vlf;
    delete lf;
    delete hf;
}

void hrv1plot::setData2(QVector<double> x, QVector<double> y, QVector<double> hff, QVector<double> ulff,QVector<double> vlff, QVector<double> lff )
{
//    QVector<QPointF> peaks;
//    for (QVector<double>::iterator i = x.begin(); i < x.end(); i++)
//    {
//        for(QVector<double>::iterator j = y.begin(); j < y.end(); j++)
//        {
//           peaks.append(QPointF(float(*i), float(*j)));
//        }
//    }

//    QVector<QPointF> peaks2;
 //   for (QVector<double>::iterator i = hff.begin(); i < hff.end(); i++)
 //   {
//
//        peaks2.append(QPointF(float(*i), 0));
//
//    }

//    signal->setSamples(x,y);
//    ulf->setSamples(ulff,y);
//    vlf->setSamples(vlff,y);
//    lf->setSamples(lff,y);
//    hf->setSamples(hff,y);
    signal->setSamples(x,y);
    ulf->setSamples(ulff,y);
    vlf->setSamples(vlff,y);
    lf->setSamples(lff,y);
    hf->setSamples(hff,y);
    replot();
}


