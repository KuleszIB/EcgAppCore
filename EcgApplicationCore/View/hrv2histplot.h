#ifndef HRV2HISTPLOT_H
#define HRV2HISTPLOT_H
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>

class hrv2histplot : public QwtPlot
{
    Q_OBJECT
public:
    hrv2histplot(QWidget *parent=0);
    ~hrv2histplot();

public slots:

private:
    QwtPlot *plot;
    QwtPlotCurve *signal;

};

#endif // HRV2HISTPLOT_H
