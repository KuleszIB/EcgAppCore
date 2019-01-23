#ifndef HRV1_PLOT_RENDERER_H
#define HRV1_PLOT_RENDERER_H
#include <qwt_plot_renderer.h>
#include "View/hrv1plot.h"
#include <QPrinter>

class Hrv1PlotRenderer: QwtPlotRenderer
{
public:
    //void renderTo(hrv1plot * plot, QPrinter & printer, QPainter & p, qreal x, qreal y) const

void renderTo(hrv1plot * plot, QPrinter & printer, QPainter & p) const;

};



#endif // HRV1_PLOT_RENDERER_H
