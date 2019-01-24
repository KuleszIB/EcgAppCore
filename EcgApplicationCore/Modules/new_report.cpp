#include "new_report.h"


//cały print razem, inaczej painter umiera

void NewReport::print_all()
{
    qInfo() << "printall";

    qreal x_cur = 10; //do zmiany położenia 'kursora'
    qreal y_cur = 5;

    // jeśli jest już taki plik, to będzie błąd paintera
    //QString filename = "C:/Users/Dominika/Desktop/test_new_report_set2.pdf";

    //odkomentować, żeby pokazywało się okno do wyboru nazwy pliku
    QString filename = QFileDialog::getSaveFileName((QWidget* )0, "Save report", QString(), "*.pdf");
    if (QFileInfo(filename).suffix().isEmpty()) { filename.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);
    printer.setPageMargins(25, 25, 25, 25, QPrinter::Millimeter);
    QPainter painter(&printer);
    painter.drawText(10, 5, "DADM, 2018/2019, AGH Kraków");
    painter.setFont(QFont("arial", 14));
    painter.drawText(10, 20, "Analysis report");
    //painter.drawText(10,15, "");
    qDebug() << ecg_ptr;

    // sygnał po filtracji
    if (ecg_ptr!=nullptr){
        painter.drawText(10, 35, "Signal after filtration");
        EcgRenderer renderer;
        renderer.renderTo(ecg_ptr, printer, painter);
        //x_cur = 10;
       // y_cur = 300;
    }else{painter.drawText(10,25, "After-filtration plot not passed!");}

    // hrv1
    //

    //QString temp;
    //temp = QString::number(freq_params_ptr->tp);

    //if (freq_params_ptr!=nullptr){
     //   painter.drawText(10, 320, "TP");
      //  painter.drawText(10, 350, temp);
    //}
//painter.drawText(10, 320, "TP");
//painter.drawText(10, 350, *sth_ptr);
    if (hrv1_ptr!=nullptr){
        painter.drawText(10, 380, "HRV1");
        Hrv1PlotRenderer hrv1_renderer;
        hrv1_renderer.renderTo(hrv1_ptr, printer, painter);
        y_cur = 500;
    }else{painter.drawText(10, 345, "HRV1 plot not available");}

    printer.newPage();
    painter.setFont(QFont("arial", 10));
    painter.drawText(10, 5, "DADM, 2018/2019, AGH Kraków");
    painter.setFont(QFont("arial", 14));
    // co z wyświetlaniem wartości?
    // hrv2
    if (hrv2hist_ptr!=nullptr){
        painter.drawText(10, 20, "Histogram from HRV2 module");
        Hrv2HistogramRenderer hrv2hist_renderer;
        hrv2hist_renderer.renderTo(hrv2hist_ptr, printer, painter);
    }else{painter.drawText(10, 360, "HRV2 histogram not available");}

    //hrv_poincare
    if (hrv2_poincare_ptr!=nullptr){
        painter.drawText(10, 380, "HRV2 Poincare module");
        Hrv2PoincareRenderer hrv2poincare_renderer;
        hrv2poincare_renderer.renderTo(hrv2_poincare_ptr, printer, painter);
    }else{
        painter.drawText(10, 370, "Poincare plot not available");
    }

    printer.newPage();
    painter.setFont(QFont("arial", 10));
    painter.drawText(10, 5, "DADM, 2018/2019, AGH Kraków");
    painter.setFont(QFont("arial", 14));

    // hrv_dfa
    if (hrv_dfa_ptr!=nullptr){
        painter.drawText(10, 380, "DFA module");
        HrvDfaRenderer hrv_dfa_renderer;
       hrv_dfa_renderer.renderTo(hrv_dfa_ptr, printer, painter);

    }else{painter.drawText(10, 710, "DFA plot not available");}


    //
    if (qrs_ptr!=nullptr){
        painter.drawText(10, 25, "R peaks module");
        qInfo() << "w qrs if";
        QrsRenderer qrs_renderer;
        qrs_renderer.renderTo(qrs_ptr, printer, painter);

    }else{painter.drawText(10, 730, "QRS plot not available");}

    printer.newPage();
    painter.setFont(QFont("arial", 10));
    painter.drawText(10, 5, "DADM, 2018/2019, AGH Kraków");
    painter.setFont(QFont("arial", 14));

    if (twave_ptr!=nullptr){
        painter.drawText(10, 25, "T wave alternans module");
        TWaveRenderer twave_renderer;
        twave_renderer.renderTo(twave_ptr, printer, painter);
    }else{painter.drawText(10, 750, "T wave plot not available");}


    //qrs








    //painter.drawText(10, 400, "DADM, 2018/2019, AGH Kraków");
    painter.drawText(300, 750, "Report finished");
    painter.end();
}
