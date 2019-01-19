#include "hrv1_plot_renderer.h"

void Hrv1PlotRenderer::renderTo(hrv1plot * plot, QPrinter & printer, QPainter & p) const
{
        int w = printer.width();
        int h = printer.height();
        QRectF rect( 10, 300, w, h );
        //QRectF rect(x, y, w, h);
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }
