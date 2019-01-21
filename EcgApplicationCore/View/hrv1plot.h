#ifndef HRV1PLOT_H
#define HRV1PLOT_H

#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_scale_engine.h>
#include <qwt_abstract_scale.h>
class hrv1plot : public QwtPlot
{
    Q_OBJECT
public:
    hrv1plot(QWidget *parent = 0);
    ~hrv1plot();
    void setDataHRV(QVector<double> , QVector<double>, QVector<double> , QVector<double> , QVector<double> ,QVector<double> );
private:
    QwtPlot *plot;
    QwtPlotCurve *signal;
    QwtPlotCurve *ulf;
    QwtPlotCurve *vlf;
    QwtPlotCurve *lf;
    QwtPlotCurve *hf;

};

#endif // HRV1PLOT_H
