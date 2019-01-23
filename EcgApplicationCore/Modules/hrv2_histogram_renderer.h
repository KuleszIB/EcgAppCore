#ifndef HRV2_HISTOGRAM_RENDERER_H
#define HRV2_HISTOGRAM_RENDERER_H
#include <qwt_plot_renderer.h>
#include "View/hrv2histplot.h"
#include <QPrinter>

class Hrv2HistogramRenderer: QwtPlotRenderer
{
public:
    //void renderTo(ecgplot * plot,  QPainter p) const
    void renderTo(hrv2histplot * plot, QPrinter & printer, QPainter & p) const;
};




#endif // HRV2_HISTOGRAM_RENDERER_H
