#include "hrv1plot.h"

hrv1plot::hrv1plot(QWidget *parent) :  QwtPlot(parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Power");
  //  signal->setStyle(QwtPlotCurve::);
   signal->setOrientation(Qt::Orientation::Vertical);
    signal->attach(this);

    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);

    hf = new QwtPlotCurve();
   // hf->setStyle(QwtPlotCurve::Sticks);
    hf->setPen(QPen(Qt::green, 0, Qt::DashLine));
    hf->attach(this);
    ulf = new QwtPlotCurve();
  //  ulf->setStyle(QwtPlotCurve::Sticks);
    ulf->setPen(QPen(Qt::darkGray, 0, Qt::DashLine));
    ulf->attach(this);

    vlf = new QwtPlotCurve();
    //vlf->setStyle(QwtPlotCurve::Sticks);
    vlf->setPen(QPen(Qt::red, 0, Qt::DashLine));
    vlf->attach(this);

    lf = new QwtPlotCurve();
    //lf->setStyle(QwtPlotCurve::Sticks);
    lf->setPen(QPen(Qt::blue, 0, Qt::DashLine));
    lf->attach(this);



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

 //   setAxisScale( xBottom, 0.0, 20.0 );
 //   setAxisScale( yLeft, -1.0, 10.0 );


    setAxisTitle(QwtPlot::xBottom, "Frequency [Hz]");
    setAxisTitle(QwtPlot::yLeft, "Power [dB/Hz]");
    setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine());
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
hrv1plot::~hrv1plot()
{

    delete signal;
    delete ulf;
    delete vlf;
    delete lf;
    delete hf;
}

void hrv1plot::setDataHRV(QVector<double> x, QVector<double>y,QVector<double>ulff , QVector<double> vlff,QVector<double> lff, QVector<double> hff  )
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
    signal->setSamples(x,y);
    QVector<double> yhf(hff);
    QVector<double> yulf(ulff);
    QVector<double> yvlf(vlff);
    QVector<double> ylf(lff);



    QVector<QPointF> ulf2;

    for (int i = 0; i < ulff.size(); i++)
    {
        ulf2.push_back(QPointF(float(ulff[i]), float(y[i])));
    }
    QVector<QPointF> vlf2;
    for (int i = 0; i < vlff.size(); i++)
    {
        vlf2.push_back(QPointF(float(vlff[i]), float(y[i+ulff.size()])));
    }
    QVector<QPointF> lf2;
    for (int i = 0; i < lff.size(); i++)
    {
        lf2.push_back(QPointF(float(lff[i]), float(y[i+ulff.size()+vlff.size()])));
    }
    QVector<QPointF> hf2;
    for (int i = 0; i < hff.size(); i++)
    {
        hf2.push_back(QPointF(float(hff[i]), float(y[i+lff.size()+ulff.size()+vlff.size()])));
    }



//    for(int i=0; i<hff.size() ; i++){
//        yhf[i]=y[i];
//    }
//    for(int j=0;j<hff.size();j++)
//    {
//    for(int i=hff.size(); i<(ulff.size()+hff.size()) ; i++){
//        yulf[j]=y[i];
//    }
//    }
//    for(int j=0;j<vlff.size();j++)
//    {
//    for(int i=ulff.size()+hff.size(); i<(hff.size()+ulff.size()+vlff.size()) ; i++){
//        yvlf[j]=y[i];
//    }
//    }
//    for(int j=0;j<lff.size();j++)
//    {
//    for(int i=(ulff.size()+hff.size()+vlff.size()) ; i<(hff.size()+ulff.size()+vlff.size()+lff.size()) ; i++){
//        ylf[j]=y[i];
//    }
//    }
//    for(int i=0;i<hff.size();i++)
//    yhf[i]=y[i];


    ulf->setSamples(ulf2);
    vlf->setSamples(vlf2);
    lf->setSamples(lf2);
    hf->setSamples(hf2);

//    int minX, maxX, minY, maxY;
//    minX=*std::min_element(x.constBegin(), x.constEnd());
//    maxX=*std::max_element(x.constBegin(), x.constEnd());

//    minY=*std::min_element(y.constBegin(), y.constEnd());
//    maxY=*std::max_element(y.constBegin(), y.constEnd());

//    double start = std::min((double)minX, (double)minY);
//    double end = std::max((double)maxX, (double)maxY);
//    double x_end = start + (canvas()->width() / canvas()->height()) * (end - start);
//    setAxisScale(QwtPlot::yLeft, start, end);
//    setAxisScale(QwtPlot::xBottom, start, x_end);

    replot();
}



