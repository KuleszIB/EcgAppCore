#include "hrv2_histogram_renderer.h"

void  Hrv2HistogramRenderer::renderTo(hrv2histplot * plot, QPrinter & printer, QPainter & p) const
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
