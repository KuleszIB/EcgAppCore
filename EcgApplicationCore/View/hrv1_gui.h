#ifndef HRV1_H
#define HRV1_H

#include <QWidget>
#include "hrv1plot.h"
#include <QVBoxLayout>
namespace Ui {
class HRV1_gui;
}

class HRV1_gui : public QWidget
{
    Q_OBJECT

public:
    explicit HRV1_gui(QWidget *parent = 0);
    ~HRV1_gui();

private slots:
    void addRandomGraph();


private:
    Ui::HRV1_gui *ui;
    hrv1plot *hrv1Plot2;
};

#endif // HRV1_H
