#ifndef HRV2_POINCARE_RENDERER_H
#define HRV2_POINCARE_RENDERER_H

#include <QPainter>
#include <QPrinter>


class Hrv2PoincareRenderer: QwtPlotRenderer
{
public:
    void renderTo(hrv2poincare * plot, QPrinter & printer, QPainter & p) const;
};



#endif // HRV2_POINCARE_RENDERER_H
