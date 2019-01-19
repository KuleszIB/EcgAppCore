#ifndef HRV2_PLOT_RENDERER_H
#define HRV2_PLOT_RENDERER_H
#include <qwt_plot_renderer.h>
#include <QPrinter>




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
#endif // HRV2_PLOT_RENDERER_H
