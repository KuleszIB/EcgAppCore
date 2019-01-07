#ifndef ECG_IO_H
#define ECG_IO_H

#include <QThread>
#include "examination.h"

class Ecg_IO : public QThread
{
    Q_OBJECT
    examination *file;

public:
    Ecg_IO();
    void run();

signals:
    void data_loaded(examination *f);
};

#endif // ECG_IO_H
