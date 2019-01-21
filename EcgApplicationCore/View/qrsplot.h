#ifndef QRSPLOT_H
#define QRSPLOT_H

#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
class qrsplot: public QwtPlot
{
    Q_OBJECT
public:
    explicit qrsplot(QWidget *parent = 0);
    ~qrsplot();
    void setData2(QVector<double> x, QVector<double> y);
    void setData3(QVector<double> x, QVector<double> y ,QVector<double> ,QVector<double> ,QVector<double> ,QVector<double>,QVector<double>, double );


public slots:

private:
    QwtPlot *plot;
    QwtPlotCurve *signal;
    QwtPlotMarker *qrs_onset;
//    QwtPlotMarker *qrs_end;
//    QwtPlotMarker *t_end;
//    QwtPlotMarker *p_onset;
//    QwtPlotMarker *p_end;
//    QwtPlotMarker *t_wave;

    QwtPlotCurve* qrsOnSet;
    QwtPlotCurve* qrsEndSet;
    QwtPlotCurve* pOnSet;
    QwtPlotCurve* pEndSet;
    QwtPlotCurve* tEnd;
};

#endif // QRSPLOT_H
