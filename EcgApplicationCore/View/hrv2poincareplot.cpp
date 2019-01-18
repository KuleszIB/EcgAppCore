#include "hrv2poincareplot.h"

hrv2poincareplot::hrv2poincareplot(QWidget *parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Poincare");
    signal->attach(this);
    elipsa = new QwtPlotCurve("Ellipse");
    elipsa->attach(this);



    setAxisTitle(QwtPlot::yLeft, "RR_n+1 [ms]");
    setAxisTitle(QwtPlot::xBottom, "RR_n [ms]");
    setAxisAutoScale(QwtPlot::xBottom, false);
    setAxisAutoScale(QwtPlot::yLeft, false);
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);
    sd1 = new QwtPlotCurve("S1");
    sd2 = new QwtPlotCurve("S2");
    signal->setStyle(QwtPlotCurve::NoCurve);
    signal->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::black), QSize(5, 5)));
    sd1->setPen(QPen(Qt::blue, 5));
    sd2->setPen(QPen(Qt::red, 5));
    signal->attach(this);
    sd1->attach(this);
    sd2->attach(this);

    centroid = new QwtPlotMarker();
    centroid->setLineStyle(QwtPlotMarker::NoLine);
    centroid->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,Qt::NoBrush,QPen(Qt::black), QSize(5, 5)));
    centroid->setLabel(tr("Centroid"));
    centroid->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
    centroid->attach(this);


//    setAxisTitle(QwtPlot::yLeft, "Amplitude [mV]");
//    setAxisTitle(QwtPlot::xBottom, "Time [mm:ss.ms]");
//    setAxisScale( xBottom, 0.0, 20.0 );
//    setAxisScale( yLeft, -1.0, 1.0 );


    // canvas
//    QwtPlotCanvas *canvas = new QwtPlotCanvas();
//    canvas->setLineWidth( 1 );
//    canvas->setFrameStyle( QFrame::Box | QFrame::Plain );
//    canvas->setBorderRadius( 15 );

//    QPalette canvasPalette( Qt::white );
//    canvasPalette.setColor( QPalette::Foreground, QColor( 133, 190, 232 ) );
//    canvas->setPalette( canvasPalette );

//    setCanvas( canvas );

//    // panning with the left mouse button
//    ( void ) new QwtPlotPanner( canvas );

//    // zoom in/out with the wheel
//    ( void ) new QwtPlotMagnifier( canvas );

   replot();

}
hrv2poincareplot::~hrv2poincareplot()
{

    delete signal;
    delete sd1;
    delete sd2;
    delete elipsa;
}//QVector<double> sd1axisx, QVector<double> sd1axisy,QVector<double> sd2axisx, QVector<double> sd2axisy

void hrv2poincareplot::setDataHRVPOINCARE(QVector<double> x, QVector<double> y, double s1, double s2, double centroidx, double centroidy)
{
  //  signal->setSamples(x, y);
    int size = x.size();

    float xx = 0.0;
    float yy = 0.0;
    float axx = 0.0;
    float ayy = 0.0;
    float ss1 = s1 * 1.414;
    float ss2 = s2 * 1.414;
//    int minX, maxX, minY, maxY;
//    minX=*std::min_element(x.constBegin(), x.constEnd());
//    maxX=*std::max_element(x.constBegin(), x.constEnd());

//    minY=*std::min_element(y.constBegin(), y.constEnd());
//    maxY=*std::max_element(y.constBegin(), y.constEnd());

    QVector<QPointF> points;
//    for (QVector<double>::iterator i = x.begin(); i < x.end(); i++)
//    {
//        for (QVector<double>::iterator j = y.begin(); j < y.end(); j++)
//        {
//        xx=float(*i);
//        yy=float(*j);
//        axx+=xx;
//        ayy+=yy;
//        points.append(QPointF(xx, yy));
//        }
//    }

    for(int i=0;i<size;++i)
    {
        xx=float(x[i]);
        yy=float(y[i]);
        axx+=xx;
        ayy+=yy;
        points.push_back(QPointF(xx,yy));

    }
signal->setSamples(points);
//    signal->setSamples(points);
    axx /= float(size);
    ayy /= float(size);

    QVector<QPointF> axes1;
    axes1.push_back(QPointF(axx,ayy));
    axes1.push_back(QPointF(axx-ss1,ayy+ss1));

    QVector<QPointF> axes2;
    axes2.push_back(QPointF(axx,ayy));
    axes2.push_back(QPointF(axx+ss2,ayy+ss2));
    sd1->setSamples(axes1);
    sd2->setSamples(axes2);
    //sd1->setSamples(sd1axisx,sd1axisy);
    //sd2->setSamples(sd2axisx,sd2axisy);
    centroid->setXValue(centroidx);
    centroid->setYValue(centroidy);

//    //Kąt obrócenia elipsy - 45 st. - zgodnie z prosta x=y
//    double angle = 3.14/4;
//    //rx = SD2; //promieñ wzgl x
//   // ry = SD1; //%promieñ wzgl y
//    int n = 20;
//    float a=0;
//    float b=2*3.14;


//    // Wzory parametryczne na elipsê
//    QVector<double>x_ellipse(n); //= x_centre + rx*cos(th)*cos(angle) - ry*sin(th)*sin(angle);
//    QVector<double>y_ellipse(n); //= y_centre + rx*cos(th)*sin(angle) + ry*sin(th)*cos(angle);
//for(int k=0;k<n;k++){
//    for(int i=a; i<b;i+3.14){
//        for(int j=angle;j<angle; i+3.14){
//        x_ellipse[k]=centroidx+s1*cos(i)*cos(angle)-s2*sin(angle)*sin(angle);
//        y_ellipse[k]=centroidx+s1*cos(i)*sin(angle)-s2*sin(angle)*cos(angle);
//         }
//     }
//}

//elipsa->setSamples(x_ellipse, y_ellipse);


//    double start = std::min((double)minX, (double)minY);
//    double end = std::max((double)maxX, (double)maxY);
//    double x_end = start + (canvas()->width() / canvas()->height()) * (end - start);
//    setAxisScale(QwtPlot::yLeft, start, end);
//    setAxisScale(QwtPlot::xBottom, start, x_end);


    replot();
}
