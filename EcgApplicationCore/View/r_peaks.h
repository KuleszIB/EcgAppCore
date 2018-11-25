#ifndef R_PEAKS_H
#define R_PEAKS_H

#include <QWidget>

namespace Ui {
class R_peaks;
}

class R_peaks : public QWidget
{
    Q_OBJECT

public:
    explicit R_peaks(QWidget *parent = 0);
    ~R_peaks();

private:
    Ui::R_peaks *ui;
};

#endif // R_PEAKS_H
