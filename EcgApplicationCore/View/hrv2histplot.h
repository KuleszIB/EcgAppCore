#ifndef HRV2HISTPLOT_H
#define HRV2HISTPLOT_H
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_histogram.h>
#include <qwt_series_data.h>
#include "qwt_painter.h"
#include "qwt_column_symbol.h"
#include "qwt_scale_map.h"
#include <qpainter.h>
#include <algorithm>
#include <qwt_plot_item.h>
#include <qwt_interval.h>
#include <qwt_compat.h>


class hrv2histplot : public QwtPlot
{
    Q_OBJECT
public:
    hrv2histplot(QWidget *parent=0);
    ~hrv2histplot();
//    void setDataHISTOGRAM(const QVector<QwtIntervalSample> &samples);
    void setValues(int, const QwtIntervalData &values );
    void setValues2(QVector<double>, QVector<double>);

public slots:

private:
    QwtPlot *plot;
    QwtPlotCurve *signal;
    QwtPlotHistogram *histogram;

};

#endif // HRV2HISTPLOT_H
