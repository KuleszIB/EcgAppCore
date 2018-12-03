#ifndef ECGBASELINE_H
#define ECGBASELINE_H

#include <QWidget>

namespace Ui {
class ECGbaseline;
}

class ECGbaseline : public QWidget
{
    Q_OBJECT

public:
    explicit ECGbaseline(QWidget *parent = 0);
    ~ECGbaseline();

private:
    Ui::ECGbaseline *ui;
};

#endif // ECGBASELINE_H
