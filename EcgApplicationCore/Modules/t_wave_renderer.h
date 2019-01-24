#ifndef T_WAVE_RENDERER_H
#define T_WAVE_RENDERER_H
#include <qwt_plot_renderer.h>
#include <QPrinter>
#include <QPainter>
#include "View/ecgplot.h"

class TWaveRenderer : QwtPlotRenderer
{
  public:
    void renderTo(ecgplot * plot, QPrinter & printer, QPainter & p) const;
};



#endif // T_WAVE_RENDERER_H
