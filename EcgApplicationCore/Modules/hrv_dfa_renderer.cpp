#include "hrv_dfa_renderer.h"



void HrvDfaRenderer::renderTo(hrvdfaplot * plot, QPrinter & printer, QPainter & p) const
{
        int w = printer.width();
        int h = printer.height();
        QRectF rect( 10, 400, w, h );
        //QRectF rect(x, y, w, h);
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }
