#ifndef R_PEAKS_H
#define R_PEAKS_H

#include <QWidget>

namespace Ui {
class R_peaks_gui;
}

class R_peaks_gui : public QWidget
{
    Q_OBJECT

public:
    explicit R_peaks_gui(QWidget *parent = 0);
    ~R_peaks_gui();

private:
    Ui::R_peaks_gui *ui;
};

#endif // R_PEAKS_H
