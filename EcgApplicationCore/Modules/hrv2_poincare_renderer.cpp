#include "hrv2_poincare_renderer.h"

void Hrv2PoincareRenderer::renderTo(hrv2poincareplot * plot, QPrinter & printer, QPainter & p) const
{
    {
        int w = printer.width();
        int h = printer.height();

        QRectF rect( 10, 400, w, h );
        double aspect = rect.width() / rect.height();
        if ( ( aspect < 1.0 ) )
            rect.setHeight( aspect * rect.width() );

       // QPainter p2( &printer );
        render( plot, &p, rect );
    }
}
