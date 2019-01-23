#ifndef ECG_RENDERER_H
#define ECG_RENDERER_H
#include <qwt_plot_renderer.h>
#include <QPrinter>
#include "View/ecgplot.h"

class EcgRenderer: QwtPlotRenderer
{
public:
    //void renderTo(ecgplot * plot,  QPainter p) const
    void renderTo(ecgplot * plot, QPrinter & printer, QPainter & p) const;


};





#endif // ECG_RENDERER_H
