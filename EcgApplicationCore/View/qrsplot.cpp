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
    setAxisTitle(QwtPlot::xBottom, "Time [s]");


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

    rPeak = new QwtPlotCurve("rPeak");
    rPeak->setYAxis(QwtPlot::yLeft);
    rPeak->setStyle(QwtPlotCurve::Sticks);
    rPeak->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(255,0,0), QColor(255,0,0), QSize(6, 6)));
    rPeak->attach(this);

    qrsOnSet = new QwtPlotCurve("qrsOnSet");
    qrsOnSet->setYAxis(QwtPlot::yLeft);
    qrsOnSet->setStyle(QwtPlotCurve::Sticks);
    qrsOnSet->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,255,0), QColor(0,255,0), QSize(6, 6)));
    qrsOnSet->attach(this);


    qrsEndSet = new QwtPlotCurve("qrsEndSet");
    qrsEndSet->setYAxis(QwtPlot::yLeft);
    qrsEndSet->setStyle(QwtPlotCurve::Sticks);
    qrsEndSet->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,150,0), QColor(0,150,0), QSize(6, 6)));
    qrsEndSet->attach(this);

    pOnSet = new QwtPlotCurve("pOnSet");
    pOnSet->setYAxis(QwtPlot::yLeft);
    pOnSet->setStyle(QwtPlotCurve::Sticks);
    pOnSet->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,0,255), QColor(0,0,255), QSize(6, 6)));
    pOnSet->attach(this);

    pEndSet = new QwtPlotCurve("pEndSet");
    pEndSet->setYAxis(QwtPlot::yLeft);
    pEndSet->setStyle(QwtPlotCurve::Sticks);
    pEndSet->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,94,185), QColor(0,94,185), QSize(6, 6)));
    pEndSet->attach(this);

    tEnd = new QwtPlotCurve("tEndSet");
    tEnd->setYAxis(QwtPlot::yLeft);
    tEnd->setStyle(QwtPlotCurve::Sticks);
    tEnd->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(185,94,0), QColor(185,94,0), QSize(6, 6)));
    tEnd->attach(this);



    tend = new QwtPlotCurve("tEnd1");
    tend->setYAxis(QwtPlot::yLeft);
    tend->setStyle(QwtPlotCurve::Sticks);
    tend->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(185,93,0), QColor(185,93,0), QSize(6, 6)));
    tend->attach(this);

    ton = new QwtPlotCurve("tOn");
    ton->setYAxis(QwtPlot::yLeft);
    ton->setStyle(QwtPlotCurve::Sticks);
    ton->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,0,254), QColor(0,0,254), QSize(6, 6)));
    ton->attach(this);

    qon = new QwtPlotCurve("qOn");
    qon->setYAxis(QwtPlot::yLeft);
    qon->setStyle(QwtPlotCurve::Sticks);
    qon->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,93,185), QColor(0,93,185), QSize(6, 6)));
    qon->attach(this);


    qend = new QwtPlotCurve("qEnd");
    qend->setYAxis(QwtPlot::yLeft);
    qend->setStyle(QwtPlotCurve::Sticks);
    qend->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(0,150,0), QColor(0,150,0), QSize(6, 6)));
    qend->attach(this);

    tpeak = new QwtPlotCurve("tPeak");
    tpeak->setYAxis(QwtPlot::yLeft);
    tpeak->setStyle(QwtPlotCurve::Sticks);
    tpeak->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor(255,0,0), QColor(255,0,0), QSize(6, 6)));
    tpeak->attach(this);




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

    delete qrsOnSet;
    delete qrsEndSet;
    delete pOnSet;
    delete pEndSet;
    delete tEnd;
    delete rPeak;
    delete tpeak;
    delete ton;
    delete tend;
    delete qon;
    delete qend;
}

void qrsplot::setData2(QVector<double> x, QVector<double> y)
{
    signal->setSamples(x, y);
    replot();
}


void qrsplot::setData3(QVector<double> x, QVector<double> y,QVector<double> xponset,QVector<double> xpend,QVector<double> xqrsonset,QVector<double> xrpeak,QVector<double> xqrsend,QVector<double> xtend,double freq)
{
//    QVector<double>yponset(xponset.size());
//    QVector<double>yqrsonset(xqrsonset.size());
//    QVector<double>ypend(xpend.size());
//    QVector<double>yqrsend(xqrsend.size());

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
    QVector<double> tponset = xponset;
    QVector<double> tpend = xpend;
    QVector<double> tqrsonset = xqrsonset;
    QVector<double> trpeak = xrpeak;
    QVector<double> tqrsend = xqrsend;
    QVector<double> ttend = xtend;

    for(int i=0;i<xqrsonset.size();i++)
        tqrsonset[i]=xqrsonset[i]/freq;

    for(int i=0;i<xqrsend.size();i++)
        tqrsend[i]=xqrsend[i]/freq;

    for(int i=0;i<xponset.size();i++)
        tponset[i]=xponset[i]/freq;

    for(int i=0;i<xpend.size();i++)
        tpend[i]=xpend[i]/freq;

    for(int i=0;i<xtend.size();i++)
        ttend[i]=xtend[i]/freq;

    for(int i=0;i<xrpeak.size();i++)
        trpeak[i]=xrpeak[i]/freq;
QVector<QPointF> pend;
for(int i=0; i<xpend.size();i++)
{pend.append(QPointF(tpend[i], y[xpend[i]]));}
    QVector<QPointF> ponset;
for(int i=0; i<xponset.size();i++)
{ponset.append(QPointF(tponset[i], y[xponset[i]]));}
QVector<QPointF> qrsend;
for(int i=0; i<xqrsend.size();i++)
{qrsend.append(QPointF(tqrsend[i], y[xqrsend[i]]));}
QVector<QPointF> qrsonset;
for(int i=0; i<xqrsonset.size();i++)
{qrsonset.append(QPointF(tqrsonset[i], y[xqrsonset[i]]));
}
QVector<QPointF> tend;
for(int i=0; i<xtend.size();i++)
{tend.append(QPointF(ttend[i], y[int(xtend[i])]));
}
QVector<QPointF> rpeak;
for(int i=0; i<xrpeak.size();i++)
{rpeak.append(QPointF(trpeak[i], y[int(xrpeak[i])]));
}

    qrsOnSet ->setSamples(qrsonset);
    qrsEndSet->setSamples(qrsend);
    pOnSet->setSamples(ponset);
    pEndSet->setSamples(pend);
    tEnd->setSamples(tend);
    rPeak->setSamples(rpeak);

    setAxisScale( xBottom, 0.0, 20.0);
    setAxisScale( yLeft, -1.0, 1.0 );

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

void qrsplot::setData4(QVector<double> x, QVector<double> y,QVector<double> Tpeak,QVector<double> Qon,QVector<double> Qend,QVector<double> Ton,QVector<double> Tend,double freq)
{
//    QVector<double> xx = x;
//    QVector<QPointF> xy;
//    for(int i=0; i<x.size();i++)
//    {xy.append(QPointF(xx[y[i]], y[i]));}


    signal->setSamples(x,y);

    QVector<double> tTpeak = Tpeak;
    QVector<double> tQon = Qon;
    QVector<double> tQend = Qend;
    QVector<double> tTon = Ton;
    QVector<double> tTend = Tend;


    for(int i=0;i<Tpeak.size();i++)
        tTpeak[i]=Tpeak[i]/freq;

    for(int i=0;i<Qon.size();i++)
        tQon[i]=Qon[i]/freq;

    for(int i=0;i<Qend.size();i++)
        tQend[i]=Qend[i]/freq;

    for(int i=0;i<Ton.size();i++)
        tTon[i]=Ton[i]/freq;

    for(int i=0;i<Tend.size();i++)
        tTend[i]=Tend[i]/freq;

QVector<QPointF> TPEAK;
for(int i=0; i<Tpeak.size();i++)
{TPEAK.append(QPointF(tTpeak[i], y[Tpeak[i]]));}
QVector<QPointF> QON;
for(int i=0; i<Qon.size();i++)
{QON.append(QPointF(tQon[i], y[Qon[i]]));}
QVector<QPointF> QEND;
for(int i=0; i<Qend.size();i++)
{QEND.append(QPointF(tQend[i], y[Qend[i]]));}
QVector<QPointF> TON;
for(int i=0; i<Ton.size();i++)
{TON.append(QPointF(tTon[i], y[Ton[i]]));}
QVector<QPointF> TEND;
for(int i=0; i<Tend.size();i++)
{TEND.append(QPointF(tTend[i], y[Tend[i]]));}

    qon ->setSamples(QON);
    qend->setSamples(QEND);
    ton->setSamples(TON);
    tend->setSamples(TEND);
    tpeak->setSamples(TPEAK);
  //  setAxisScale( xBottom, 0.0, 2.0);
  //  setAxisScale( yLeft, -1.0, 1.0 );
//    setAxisScale( xBottom, -1e-63, 0.0);
//    setAxisScale( yLeft, -0.15, 0.15 );

    setAxisScale( xBottom, 0.0, 20.0);
    setAxisScale( yLeft, -1.0, 1.0 );

    replot();

}

