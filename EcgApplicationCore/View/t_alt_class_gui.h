#ifndef T_ALT_CLASS_H
#define T_ALT_CLASS_H

#include <QWidget>
#include "ecgplot.h"
#include <QVBoxLayout>
namespace Ui {
class T_alt_class_gui;
}

class T_alt_class_gui : public QWidget
{
    Q_OBJECT

public:
    explicit T_alt_class_gui(QWidget *parent = 0);
    ~T_alt_class_gui();


private slots:
    void addRandomGraph();

private:
    Ui::T_alt_class_gui *ui;
    ecgplot *ecgPlot2;
};

#endif // T_ALT_CLASS_H
