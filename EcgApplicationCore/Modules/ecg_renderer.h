#ifndef ECG_RENDERER_H
#define ECG_RENDERER_H
#include <qwt_plot_renderer.h>
#include <QPrinter>

class EcgRenderer: QwtPlotRenderer
{
public:
    //void renderTo(ecgplot * plot,  QPainter p) const
    void renderTo(ecgplot * plot, QPrinter & printer, QPainter & p) const
    //void renderTo( ReportCreator & report)
    {
        int w = printer.width();
        int h = printer.height();

        QRectF rect( 10, 35, w, h );
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }

};





#endif // ECG_RENDERER_H
