#ifndef CUSTOM_RENDERER_H
#define CUSTOM_RENDERER_H
#include <qwt_plot_renderer.h>
#include <QPrinter>

class CustomRenderer: QwtPlotRenderer
{
public:
    //void renderTo(ecgplot * plot,  QPainter p) const
    void renderTo(ecgplot * plot, QPrinter & printer, QPainter & p) const
    //void renderTo( ReportCreator & report)
    {
        int w = printer.width();
        int h = printer.height();

        QRectF rect( 30, 30, w, h );
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }

};

class Hrv1PlotRenderer: QwtPlotRenderer
{
public:
    void renderTo(hrv1plot * plot, QPrinter & printer, QPainter & p) const
    {
        int w = printer.width();
        int h = printer.height();
        QRectF rect( 100, 100, w, h );
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }
};

class Hrv2PlotRenderer: QwtPlotRenderer
{
public:
    void renderTo(hrv2plot * plot, QPrinter & printer, QPainter & p) const
    {
        int w = printer.width();
        int h = printer.height();
        QRectF rect( 200, 200, w, h );
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }

};

#endif // CUSTOM_RENDERER_H
