#include "new_report.h"


//cały print razem, inaczej painter umiera

void NewReport::print_all()
{
    qInfo() << "printall";

    qreal x_cur = 10; //do zmiany położenia 'kursora'
    qreal y_cur = 5;

    // jeśli jest już taki plik, to będzie błąd paintera
    QString filename = "C:/Users/Dominika/Desktop/test_new_report_set2.pdf";

    //odkomentować, żeby pokazywało się okno do wyboru nazwy pliku
    //QString filename = QFileDialog::getSaveFileName((QWidget* )0, "Save report", QString(), "*.pdf");
    //if (QFileInfo(filename).suffix().isEmpty()) { filename.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);
    printer.setPageMargins(25, 25, 25, 25, QPrinter::Millimeter);
    QPainter painter(&printer);
    painter.drawText(10, 5, "Analysis report");
    //painter.drawText(10,15, "");
    qDebug() << ecg_ptr;

    // sygnał po filtracji
    if (ecg_ptr!=nullptr){
        painter.drawText(10, 25, "Signal after filtration");
        EcgRenderer renderer;
        renderer.renderTo(ecg_ptr, printer, painter);
        //x_cur = 10;
       // y_cur = 300;
    }else{painter.drawText(10,25, "After-filtration plot not passed!");}

    // hrv1
    if (hrv1_ptr!=nullptr){
        painter.drawText(10, 310, "HRV1");
        Hrv1PlotRenderer hrv1_renderer;
        hrv1_renderer.renderTo(hrv1_ptr, printer, painter);
        y_cur = 500;
    }else{painter.drawText(10, 45, "HRV1 plot not available");}

    // co z wyświetlaniem wartości?
    // hrv2
    if (hrv2hist_ptr!=nullptr){
        painter.drawText(10, 510, "Histogram of HRV2");
        Hrv2HistogramRenderer hrv2hist_renderer;
        hrv2hist_renderer.renderTo(hrv2hist_ptr, printer, painter);
    }else{painter.drawText(10, 60, "HRV2 histogram not available");}

    // hrv_dfa
    if (hrv2_poincare_ptr!=nullptr){
        painter.drawText(10, 710, "Poincare plot");
        Hrv2PoincareRenderer hrv2poincare_renderer;
        hrv2poincare_renderer.renderTo(hrv_poincare_ptr, printer, painter);

    }else{painter.drawText(10, 710, "Poincare plot not available");}

    //qrs
    // kiedy podział strony?







    painter.drawText(10, 400, "DADM, 2018/2019, AGH Kraków");
    painter.end();
}
