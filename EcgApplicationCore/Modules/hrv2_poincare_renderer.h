#ifndef HRV2_POINCARE_RENDERER_H
#define HRV2_POINCARE_RENDERER_H

#include <qwt_plot_renderer.h>
#include "View/hrv2poincareplot.h"
#include <QPainter>
#include <QPrinter>

class Hrv2PoincareRenderer : QwtPlotRenderer{
public:
  void renderTo(hrv2poincareplot * plot, QPrinter & printer, QPainter & p) const;
};


#endif // HRV2_POINCARE_RENDERER_H
