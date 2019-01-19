#include "qrsplot.h"

qrsplot::qrsplot(QWidget *parent) :
    QwtPlot(parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Signal");
    signal->attach(this);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);
    setAxisTitle(QwtPlot::yLeft, "Amplitude [mV]");
    setAxisTitle(QwtPlot::xBottom, "Time [mm:ss.ms]");


//    qrs_onset = new QwtPlotMarker();
//    qrs_onset->setLineStyle(QwtPlotMarker::NoLine);
//    qrs_onset->setSymbol(new QwtSymbol(QwtSymbol::Ellipse));
//    qrs_onset->setLabel(tr("QRS onset"));
//    qrs_onset->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    qrs_onset->attach(this);

//    qrs_end = new QwtPlotMarker();
//    qrs_end->setLineStyle(QwtPlotMarker::NoLine);
//    qrs_end->setSymbol(new QwtSymbol(QwtSymbol::Ellipse));
//    qrs_end->setLabel(tr("QRS end"));
//    qrs_end->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    qrs_end->attach(this);

//    t_end = new QwtPlotMarker();
//    t_end->setLineStyle(QwtPlotMarker::NoLine);
//    t_end->setSymbol(new QwtSymbol(QwtSymbol::Ellipse));
//    t_end->setLabel(tr("T end"));
//    t_end->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    t_end->attach(this);

//    p_onset = new QwtPlotMarker();
//    p_onset->setLineStyle(QwtPlotMarker::NoLine);
//    p_onset->setSymbol(new QwtSymbol(QwtSymbol::Ellipse));
//    p_onset->setLabel(tr("P onset"));
//    p_onset->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    p_onset->attach(this);

//    p_end = new QwtPlotMarker();
//    p_end->setLineStyle(QwtPlotMarker::NoLine);
//    p_end->setSymbol(new QwtSymbol(QwtSymbol::Ellipse));
//    p_end->setLabel(tr("P end"));
//    p_end->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    p_end->attach(this);

//    t_wave = new QwtPlotMarker();
//    t_wave->setLineStyle(QwtPlotMarker::NoLine);
//    t_wave->setSymbol(new QwtSymbol(QwtSymbol::Ellipse));
//    t_wave->setLabel(tr("T Wave Alt"));
//    t_wave->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
//    t_wave->attach(this);
    qrsOnSetCurve = new QwtPlotCurve("qrsOnSet");
    qrsOnSetCurve->setYAxis(QwtPlot::yLeft);
    qrsOnSetCurve->setStyle(QwtPlotCurve::Sticks);
    qrsOnSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,255,0), QColor(0,255,0), QSize(6, 6)));
    qrsOnSetCurve->attach(this);


    qrsEndSetCurve = new QwtPlotCurve("qrsEndSet");
    qrsEndSetCurve->setYAxis(QwtPlot::yLeft);
    qrsEndSetCurve->setStyle(QwtPlotCurve::Sticks);
    qrsEndSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,150,0), QColor(0,150,0), QSize(6, 6)));
    qrsEndSetCurve->attach(this);

    pOnSetCurve = new QwtPlotCurve("pOnSet");
    pOnSetCurve->setYAxis(QwtPlot::yLeft);
    pOnSetCurve->setStyle(QwtPlotCurve::Sticks);
    pOnSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,0,255), QColor(0,0,255), QSize(6, 6)));
    pOnSetCurve->attach(this);

    pEndSetCurve = new QwtPlotCurve("pEndSet");
    pEndSetCurve->setYAxis(QwtPlot::yLeft);
    pEndSetCurve->setStyle(QwtPlotCurve::Sticks);
    pEndSetCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,94,185), QColor(0,94,185), QSize(6, 6)));
    pEndSetCurve->attach(this);

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

replot();
}

qrsplot::~qrsplot()
{
    delete signal;
//    delete qrs_onset;
//    delete qrs_end;
//    delete t_end;
//    delete p_onset;
//    delete p_end;
//    delete t_wave;

    delete qrsOnSetCurve;
    delete qrsEndSetCurve;
    delete pOnSetCurve;
    delete pEndSetCurve;
}

void qrsplot::setData2(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    replot();
}


void qrsplot::setData3(QVector<double> x, QVector<double> y,QVector<double> xponset,QVector<double> xpend,QVector<double> xqrsonset,QVector<double> xqrsend,double freq)
{
    QVector<double>yponset(xponset.size());
    QVector<double>yqrsonset(xqrsonset.size());
    QVector<double>ypend(xpend.size());
    QVector<double>yqrsend(xqrsend.size());

    signal->setSamples(x, y);
//    for(int i=0;i<qrsonset.size();i++){
//        if(qrsonset[i]==x[i]){
//    qrs_onset->setXValue(qrsonset[i]);
//    qrs_onset->setYValue(y[i]);}
//    }
//    for(int i=0;i<ponest.size();i++){
//        if(ponest[i]==x[i]){
//    p_onset->setXValue(ponest[i]);
//    p_onset->setYValue(y[i]);}
//    }
//    for(int i=0;i<pend.size();i++){
//        if(pend[i]==x[i]){
//    p_end->setXValue(pend[i]);
//    p_end->setYValue(y[i]);}
//    }
//    for(int i=0;i<qrsend.size();i++){
//        if(qrsend[i]==x[i]){
//    qrs_end->setXValue(qrsend[i]);
//    qrs_end->setYValue(y[i]);}
//    }

    for(int i=0;i<xqrsonset.size();i++)
        xqrsonset[i]=xqrsonset[i]/freq;

    for(int i=0;i<xqrsend.size();i++)
        xqrsend[i]=xqrsend[i]/freq;

    for(int i=0;i<xponset.size();i++)
        xponset[i]=xponset[i]/freq;

    for(int i=0;i<xpend.size();i++)
        xpend[i]=xpend[i]/freq;

    for(int i=0;i<xpend.size();i++)
        ypend[i]=y[xpend[i]];
    for(int i=0;i<xponset.size();i++)
        yponset[i]=y[xponset[i]];
    for(int i=0;i<xpend.size();i++)
        ypend[i]=y[xpend[i]];
    for(int i=0;i<xqrsonset.size();i++)
        yqrsonset[i]=y[xqrsonset[i]];
    for(int i=0;i<xqrsend.size();i++)
        yqrsend[i]=y[xqrsend[i]];

    qrsOnSetCurve->setSamples(xqrsonset,yqrsonset);
    qrsEndSetCurve->setSamples(xqrsend,yqrsend);;
    pOnSetCurve->setSamples(xponset,yponset);;
    pEndSetCurve->setSamples(xpend,ypend);;
    replot();

 //   QVector<QPointF> data;

//    for (QVector<double>::iterator i = x.begin(); i < x.end(); i++)
//        {
//        for (QVector<double>::iterator j = ponest.begin(); i < ponest.end(); j++)
//            {
//            for (QVector<double>::iterator k = y.begin(); i < y.end(); k++)
//                {
//                if(i==j)
//                {
//                  data.append(QPointF(float(*j), float(*k)));
//                }
//                }
//            }
//        }
//    int current_i=0;
//    qrs_onset ->setValue(ponset,0.0);

//   for (int i = 0; i < signal_size; ++i)
//	{
//        data.push_back(...)
//	}



//    replot();
}
