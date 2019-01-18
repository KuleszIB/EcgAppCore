#ifndef NEW_REPORT_H
#define NEW_REPORT_H
#include "custom_renderer.h"
//#include "Modules/new_report.h"
#include <QPainter>
#include <QPrinter>

class NewReport{

public:
    ecgplot * ecg_ptr;
    hrv1plot * hrv1_ptr;
    hrv2plot * hrv2_ptr;

    void set_ecgplot(ecgplot * plot){
        ecg_ptr = plot;
    }

    void set_hrv1plot(hrv1plot * plot){
        hrv1_ptr = plot;
    }

    void set_hrv2plot(hrv2plot * plot){
        hrv2_ptr = plot;
    }

    void print_all()
    {
        QString filename = "C:/Users/Dominika/Desktop/test_new_report_set.pdf";
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(filename);
        printer.setPageMargins(25, 25, 25, 25, QPrinter::Millimeter);
        QPainter painter(&printer);
        painter.drawText(10, 5, "Raport z przeprowadzonej analizy");
        painter.drawText(10,10, "test");
        CustomRenderer renderer;
        renderer.renderTo(ecg_ptr, printer, painter);
        painter.drawText(10, 400, "Koniec");
        painter.end();
    }
};


#endif // NEW_REPORT_H
