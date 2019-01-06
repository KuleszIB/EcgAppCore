#ifndef HRV2POINCAREPLOT_H
#define HRV2POINCAREPLOT_H
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>

class hrv2poincareplot : public QwtPlot
{
    Q_OBJECT
public:
    hrv2poincareplot(QWidget *parent = 0);
    ~hrv2poincareplot();
    void setData2(QVector<double> x, QVector<double> y);

public slots:

private:
    QwtPlot *plot;
    QwtPlotCurve *signal;



};

#endif // HRV2POINCAREPLOT_H
