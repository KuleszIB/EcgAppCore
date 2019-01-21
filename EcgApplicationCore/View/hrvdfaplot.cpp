#include "hrvdfaplot.h"

hrvdfaplot::hrvdfaplot(QWidget *parent) :  QwtPlot(parent)
{
    setMinimumHeight(10);
    setMinimumWidth(10);

    setAxisTitle(QwtPlot::xBottom, "n");
    setAxisTitle(QwtPlot::yLeft, "F(n)");

   // setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
   // setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine);

    signal = new QwtPlotCurve("Curve");
    signal->setStyle(QwtPlotCurve::NoCurve);
    signal->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::black), QSize(5, 5)));
    signal->attach(this);

    signal2 = new QwtPlotCurve("Curve");
    signal2->setStyle(QwtPlotCurve::NoCurve);
    signal2->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::blue), QSize(5, 5)));
    signal2->attach(this);

    vectorshort = new QwtPlotCurve("Short");
    vectorshort->setPen(Qt::red, 0.0, Qt::SolidLine);
    vectorshort->attach(this);

    vectorlong = new QwtPlotCurve("Long");
    vectorlong->setPen(Qt::blue, 0.0, Qt::SolidLine);
    vectorlong->attach(this);

    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);

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

hrvdfaplot::~hrvdfaplot()
{
    delete signal;
    delete signal2;
    delete vectorshort;
    delete vectorlong;
}//
void hrvdfaplot::setDataHRVDFA(QVector<double> x, QVector<double> y, QVector<double> vl, QVector<double> vs)
{
    QVector<QPointF> vs1;

    for (int i = 0; i < vs.size(); i++)
    {
        vs1.push_back(QPointF(float(x[i]), float(vs[i])));
    }

    QVector<QPointF> vl1;
    for (int i = 0; i < vl.size(); i++)
    {
        if(vl[i]!=0)
        vl1.push_back(QPointF(float(x[i+vs.size()]), float(vl[i])));
    }

    signal->setSamples(x,y);
    vectorshort->setSamples(vs1);
    vectorlong->setSamples(vl1);

    replot();
}
