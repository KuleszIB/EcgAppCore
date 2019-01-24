#include "ecg_renderer.h"

void EcgRenderer::renderTo(ecgplot * plot, QPrinter & printer, QPainter & p) const
//void renderTo( ReportCreator & report)
{
    int w = printer.width();
    int h = printer.height();

    QRectF rect( 10, 55, w, h );
    double aspect = rect.width() / rect.height();
    if ( ( aspect < 1.0 ) )
        rect.setHeight( aspect * rect.width() );

   // QPainter p2( &printer );
    render( plot, &p, rect );
}
