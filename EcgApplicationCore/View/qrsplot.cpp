#include "qrsplot.h"

qrsplot::qrsplot(QWidget *parent) :
    QwtPlot(parent)
{
    plot = new QwtPlot();
    signalCurve = new QwtPlotCurve("Sygnał");
    signalCurve->attach(this);
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


    signalCurve = new QwtPlotCurve("signal");
    signalCurve->setYAxis(QwtPlot::yLeft);
    signalCurve->attach(this);
    peaksCurve = new QwtPlotCurve("r-peaks");
    peaksCurve->setYAxis(QwtPlot::yLeft);
    peaksCurve->setStyle(QwtPlotCurve::NoCurve);
    peaksCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(Qt::red), QColor(Qt::red), QSize(6, 6)));
    peaksCurve->setPen(QPen(Qt::red, 5));
    peaksCurve->attach(this);

    qrsOnSetCurve = new QwtPlotCurve("qrsOnSet");
    qrsOnSetCurve->setYAxis(QwtPlot::yLeft);
    qrsOnSetCurve->setStyle(QwtPlotCurve::NoCurve);
    qrsOnSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,255,0), QColor(0,255,0), QSize(6, 6)));
    qrsOnSetCurve->attach(this);

    qrsEndSetCurve = new QwtPlotCurve("qrsEndSet");
    qrsEndSetCurve->setYAxis(QwtPlot::yLeft);
    qrsEndSetCurve->setStyle(QwtPlotCurve::NoCurve);
    qrsEndSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,150,0), QColor(0,150,0), QSize(6, 6)));
    qrsEndSetCurve->attach(this);

    pOnSetCurve = new QwtPlotCurve("pOnSet");
    pOnSetCurve->setYAxis(QwtPlot::yLeft);
    pOnSetCurve->setStyle(QwtPlotCurve::NoCurve);
    pOnSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,0,255), QColor(0,0,255), QSize(6, 6)));
    pOnSetCurve->attach(this);

    pEndSetCurve = new QwtPlotCurve("pEndSet");
    pEndSetCurve->setYAxis(QwtPlot::yLeft);
    pEndSetCurve->setStyle(QwtPlotCurve::NoCurve);
    pEndSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,94,185), QColor(0,94,185), QSize(6, 6)));
    pEndSetCurve->attach(this);

    tEndSetCurve = new QwtPlotCurve("tEndSet");
    tEndSetCurve->setYAxis(QwtPlot::yLeft);
    tEndSetCurve->setStyle(QwtPlotCurve::NoCurve);
    tEndSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(116,11,11), QColor(116,11,11), QSize(6, 6)));
    tEndSetCurve->attach(this);

    vCurve = new QwtPlotCurve("V");
    vCurve->setYAxis(QwtPlot::yLeft);
    vCurve->setStyle(QwtPlotCurve::NoCurve);
    vCurve->setSymbol(new QwtSymbol(QwtSymbol::Triangle,QColor(Qt::red), QColor(Qt::red), QSize(6, 6)));
    vCurve->attach(this);
    vCurve->setVisible(false);

    svCurve = new QwtPlotCurve("SV");
    svCurve->setYAxis(QwtPlot::yLeft);
    svCurve->setStyle(QwtPlotCurve::NoCurve);
    svCurve->setSymbol(new QwtSymbol(QwtSymbol::Star1,QColor(Qt::red), QColor(Qt::red), QSize(6, 6)));
    svCurve->attach(this);
    svCurve->setVisible(false);

     replot();
}

qrsplot::~qrsplot()
{
    delete signalCurve;
    delete peaksCurve;
    delete qrsOnSetCurve;
    delete qrsEndSetCurve;
    delete pOnSetCurve;
    delete pEndSetCurve;
    delete tEndSetCurve;
    delete svCurve;
    delete vCurve;
}

void qrsplot::setData2(QVector<double> x, QVector<double> y)
{
    signalCurve->setSamples(x, y);
    replot();
}

void qrsplot::setRpeaks(QVector<double> x, QVector<double> y,  QVector<double> r)
{



//    int size = y.size();
//    int t_wave1;
//    for (int i=0; i<size;++i)
//    QVector<QPointF> points;
//if(x==r){
//    t_wave->setSamples(r,y);
//}


//plot(t(t_wave(:,1)),abr(sub2ind(size(abr),1:L,t_wave(:,1)')),'go','markerfacecolor','g');

    //signal->setSamples(x, y);
//    replot();
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
