#ifndef HRV2POINCAREPLOT_H
#define HRV2POINCAREPLOT_H
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_marker.h>
#include <qwt_symbol.h>
#include <algorithm>
#include "math.h"

class hrv2poincareplot : public QwtPlot
{
    Q_OBJECT
public:
    hrv2poincareplot(QWidget *parent = 0);
    ~hrv2poincareplot();
    void setDataHRVPOINCARE(QVector<double> x, QVector<double> y,double,  double , double, double);
//QVector<double>, QVector<double>,  QVector<double>, QVector<double>,
public slots:

private:
    QwtPlot *plot;
    QwtPlotCurve *signal;
    QwtPlotCurve *elipsa;
    QwtPlotCurve *sd1;
    QwtPlotCurve *sd2;
    QwtPlotMarker *centroid;

};

#endif // HRV2POINCAREPLOT_H
