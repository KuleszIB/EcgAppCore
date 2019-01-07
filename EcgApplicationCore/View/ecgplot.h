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
    void clear();
 //   QSize sizeHint() const;
signals:

public slots:

private:
    QwtPlotCurve *signal;
    QwtPlot *plot;

};

#endif // ECGPLOT_H
