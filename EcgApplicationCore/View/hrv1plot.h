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

class hrv1plot : public QwtPlot
{
    Q_OBJECT
public:
    hrv1plot(QWidget *parent = 0);
    ~hrv1plot();
    void setData2(QVector<double> , QVector<double> , double , double , double , double  );

private:
    QwtPlot *plot;
    QwtPlotCurve *signal;
    QwtPlotMarker *ulf;
    QwtPlotMarker *vlf;
    QwtPlotMarker *lf;
    QwtPlotMarker *hf;

};

#endif // HRV1PLOT_H
