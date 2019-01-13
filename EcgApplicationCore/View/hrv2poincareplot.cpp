#include "hrv2poincareplot.h"

hrv2poincareplot::hrv2poincareplot(QWidget *parent)
{
    plot = new QwtPlot();
    signal = new QwtPlotCurve("Poincare");
    signal->attach(this);

    setAxisTitle(QwtPlot::yLeft, "RR_n+1 [ms]");
    setAxisTitle(QwtPlot::xBottom, "RR_n [ms]");
    setAxisAutoScale(QwtPlot::xBottom, false);
    setAxisAutoScale(QwtPlot::yLeft, false);
    sd1 = new QwtPlotCurve("S1");
    rr = new QwtPlotCurve("RR");
    sd2 = new QwtPlotCurve("S2");
    signal->setStyle(QwtPlotCurve::NoCurve);
    signal->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::black), QSize(5, 5)));
    sd1->setPen(QPen(Qt::blue, 5));
    sd2->setPen(QPen(Qt::red, 5));
    signal->attach(this);
    sd1->attach(this);
    sd2->attach(this);
    replot();

}
hrv2poincareplot::~hrv2poincareplot()
{

    delete signal;
    delete sd1;
    delete sd2;
}

void hrv2poincareplot::setData2(QVector<double> x, QVector<double> y, float s1, float s2)
{
    int size = x.size();

    float xx = 0.0;
    float yy = 0.0;
    float axx = 0.0;
    float ayy = 0.0;
    float ss1 = s1 ;
    float ss2 = s2 ;
    int minX, maxX, minY, maxY;


    QVector<QPointF> data;
    for (QVector<double>::iterator i = x.begin(); i < x.end(); i++)
    {
        for (QVector<double>::iterator j = y.begin(); j < y.end(); j++)
        {
        xx=float(*i);
        yy=float(*j);
        axx+=xx;
        ayy+=yy;
        data.append(QPointF(xx, yy));
        }
    }
    signal->setSamples(data);
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
    replot();
}

void hrv2poincareplot::setPoincare(QVector<int> &poincarex,QVector<int> &poincarey,float s1, float s2 )
{
    QVector<int> px = poincarex;
    QVector<int> py = poincarey;
    float xx = 0.0;
    float yy = 0.0;
    float axx = 0.0;
    float ayy = 0.0;
    float sd1 = s1 ;
    float sd2 = s2 ;
    int size = px.size();
    int minX, maxX, minY, maxY;

    QVector<QPointF> data;
    for (QVector<int>::iterator i = px.begin(); i < px.end(); ++i)
    {
        for (QVector<int>::iterator j = py.begin(); j < py.end(); ++j)
        {
            xx = float(*i);
            yy = float(*j);
            axx += xx;
            ayy += yy;
            data.push_back(QPointF(xx, yy));
    }
    rr->setSamples(data);

    axx /= float(size);
    ayy /= float(size);
    QVector<QPointF> axes1;
    axes1.push_back(QPointF(axx,ayy));
    axes1.push_back(QPointF(axx-s1,ayy+s1));
    QVector<QPointF> axes2;
    axes2.push_back(QPointF(axx,ayy));
    axes2.push_back(QPointF(axx+s2,ayy+s2));
    replot();
}



//    double start = std::min((double)minX, (double)minY);
//    double end = std::max((double)maxX, (double)maxY);
//    double x_end = start + (canvas()->width() / canvas()->height()) * (end - start);
//    setAxisScale(QwtPlot::yLeft, start, end);
//    setAxisScale(QwtPlot::xBottom, start, x_end);

//    double start = std::min((double)minX, (double)minY);
//  double end = std::max((double)maxX, (double)maxY);
//  double x_end = start + (canvas()->width() / canvas()->height()) * (end - start);
//  setAxisScale(QwtPlot::yLeft, start, end);
//  setAxisScale(QwtPlot::xBottom, start, x_end);
