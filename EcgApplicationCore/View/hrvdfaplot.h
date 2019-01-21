#ifndef HRVDFAPLOT_H
#define HRVDFAPLOT_H

#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_scale_engine.h>
#include <qwt_symbol.h>

class hrvdfaplot : public QwtPlot
{
    Q_OBJECT
public:
    hrvdfaplot(QWidget *parent = 0);
    ~hrvdfaplot();
    void setDataHRVDFA(QVector<double>, QVector<double>,QVector<double>, QVector<double>);
private:
    QwtPlot *plot;
    QwtPlotCurve *signal;
    QwtPlotCurve *signal2;
    QwtPlotCurve *vectorshort;
    QwtPlotCurve *vectorlong;

};

#endif // HRVDFAPLOT_H
