#ifndef ECGPLOT_H
#define ECGPLOT_H

//#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>

class ecgplot : public QwtPlot
{
    Q_OBJECT

public:
    explicit ecgplot(QWidget *parent);
    ~ecgplot();
    void setData(QVector<double> x, QVector<double> y);
    void setData2(QVector<double> x, QVector<double> y, QVector<double> z);
    void clear();
    QSize sizeHint() const;
signals:

public slots:

private:
    QwtPlotCurve *signal;
    QwtPlotCurve *odd;
    QwtPlotCurve *even;
    QwtPlot *plot;

};

#endif // ECGPLOT_H
