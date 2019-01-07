#include "ecg_io.h"

Ecg_IO::Ecg_IO()
{
    file = new examination;
}

void Ecg_IO::set_filename(QString name)
{
    file->filename = name;
}

examination* Ecg_IO::get_file()
{
    return file;
}

void Ecg_IO::run()
{
    qInfo() << "Drugi wątek";
    file->get_data();
    emit data_loaded(file);
}
