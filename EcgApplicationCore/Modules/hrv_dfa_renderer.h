#ifndef HRV_DFA_RENDERER_H
#define HRV_DFA_RENDERER_H
#include <qwt_plot_renderer.h>
#include "View/hrvdfaplot.h"
#include <QPainter>
#include <QPrinter>


class HrvDfaRenderer: QwtPlotRenderer
{
public:


    void renderTo(hrvdfaplot * plot, QPrinter & printer, QPainter & p) const;

};

#endif // HRV_DFA_RENDERER_H
