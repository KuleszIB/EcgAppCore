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

private slots:

    void on_comboBox_filter_currentTextChanged(const QString &arg1);

private:
    Ui::ECGbaseline_gui *ui;
};

#endif // ECGBASELINE_H
