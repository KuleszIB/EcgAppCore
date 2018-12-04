#ifndef ECGBASELINE_H
#define ECGBASELINE_H

#include <QWidget>

namespace Ui {
class ECGbaseline_gui;
}

class ECGbaseline_gui : public QWidget
{
    Q_OBJECT

public:
    explicit ECGbaseline_gui(QWidget *parent = 0);
    ~ECGbaseline_gui();

private:
    Ui::ECGbaseline_gui *ui;
};

#endif // ECGBASELINE_H
