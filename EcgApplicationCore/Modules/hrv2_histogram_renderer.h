#ifndef HRV2_HISTOGRAM_RENDERER_H
#define HRV2_HISTOGRAM_RENDERER_H


class Hrv2HistogramRenderer: QwtPlotRenderer
{
public:
    //void renderTo(ecgplot * plot,  QPainter p) const
    void renderTo(hrv2histplot * plot, QPrinter & printer, QPainter & p) const;
};




#endif // HRV2_HISTOGRAM_RENDERER_H
