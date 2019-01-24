#ifndef QRS_RENDERER_H
#define QRS_RENDERER_H
#include <qwt_plot_renderer.h>
#include <QPrinter>
#include <QPainter>
#include "View/qrsplot.h"



class QrsRenderer : QwtPlotRenderer{
public:
    void renderTo(qrsplot * plot, QPrinter & printer, QPainter & p) const;
};



#endif // QRS_RENDERER_H
