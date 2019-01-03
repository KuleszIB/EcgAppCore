#ifndef ST_SEGMENT_H
#define ST_SEGMENT_H

#include <QWidget>
#include "ecgplot.h"
#include <QVBoxLayout>
namespace Ui {
class St_segment_gui;
}

class St_segment_gui : public QWidget
{
    Q_OBJECT

public:
    explicit St_segment_gui(QWidget *parent = 0);
    ~St_segment_gui();
private slots:
    void addRandomGraph();

private:
    Ui::St_segment_gui *ui;
    ecgplot *ecgPlot2;
};

#endif // ST_SEGMENT_H
