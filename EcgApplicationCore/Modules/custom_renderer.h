#ifndef CUSTOM_RENDERER_H
#define CUSTOM_RENDERER_H
#include <qwt_plot_renderer.h>

class CustomRenderer: QwtPlotRenderer
{
public:
    void renderTo(ecgplot *, QPrinter &) const;

};

#endif // CUSTOM_RENDERER_H
