#include "hrvdfaplot.h"

hrvdfaplot::hrvdfaplot(QWidget *parent) :  QwtPlot(parent)
{
    setMinimumHeight(10);
    setMinimumWidth(10);

    setAxisTitle(QwtPlot::xBottom, "F(n)");
    setAxisTitle(QwtPlot::yLeft, "n");

   // setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
   // setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine);

    signal = new QwtPlotCurve("Curve");
    signal->setStyle(QwtPlotCurve::NoCurve);
    signal->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::blue), QSize(5, 5)));
    signal->attach(this);


    vectorshort = new QwtPlotCurve("Short");
   // vectorshort->setStyle(QwtPlotCurve::NoCurve);
   // vectorshort->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::red), QSize(5, 5)));
    vectorshort->attach(this);

    vectorlong = new QwtPlotCurve("Long");
  //  vectorlong->setStyle(QwtPlotCurve::CurveStyle());
  //  vectorlong->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::yellow), QSize(5, 5)));
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


replot();
}

hrvdfaplot::~hrvdfaplot()
{
    delete signal;
}//,QVector<double> vs, QVector<double> vl
void hrvdfaplot::setDataHRVDFA(QVector<double> x, QVector<double> y )
{
//    int sizevs=vs.size();
//    int sizevl=vl.size();
//    QVector<double>x1(sizevs);
//    QVector<double>x2(sizevl);
//    for(int i=0;i<sizevs;i++)
//    {
//        x1[i]=x[i];
//    }

//    for(int i=sizevs;i<(sizevs+sizevl);i++)
//    {
//        x2[i]=x[i];
//    }

//    vectorshort->setSamples(x1,vs);
//    vectorlong->setSamples(x2,vl);
    signal->setSamples(x,y);
    replot();
}
