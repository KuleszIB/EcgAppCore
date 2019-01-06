#include "ecg_io.h"

Ecg_IO::Ecg_IO()
{
    file = new examination;
}

void Ecg_IO::run()
{
//    qInfo() << "Drugi wątek";
    file->get_data();
    emit data_loaded(file);
}
