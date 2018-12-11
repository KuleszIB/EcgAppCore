#ifndef QRSPLOT_H
#define QRSPLOT_H

#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_marker.h>

class qrsplot: public QwtPlot
{
    Q_OBJECT
public:
    explicit qrsplot(QWidget *parent = 0);
    ~qrsplot();

private:
    QwtPlotCurve *signal;
    QwtPlotMarker *qrs_onset;
    QwtPlotMarker *qrs_end;
    QwtPlotMarker *t_end;
    QwtPlotMarker *p_onset;
    QwtPlotMarker *p_end;
    QwtPlotMarker *t_wave;
public slots:
    void setData();
};

class VectorInt
{
public:
 VectorInt (QVector<int> * signal = NULL);
  ~VectorInt ();

  int get(size_t it);
  void set(size_t it, int value);

  QVector<int> * signal;
};
#endif // QRSPLOT_H
