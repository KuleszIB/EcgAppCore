#ifndef NEW_REPORT_H
#define NEW_REPORT_H

//import rendererów do wykresów ??
#include "ecg_renderer.h"
#include "hrv1_plot_renderer.h"

#include "hrv2_histogram_renderer.h"
//#include "hrv2_poincare_renderer.h"
//#include "hrvdfaplot



#include <QPainter>
#include <QPrinter>
#include <QDebug>
#include <QFileDialog>
#include <QWidget>
#include <QFileInfo>



class NewReport{

private:
    // wykresy
    ecgplot * ecg_ptr = nullptr;
    hrv1plot * hrv1_ptr = nullptr;
    hrv2histplot * hrv2hist_ptr = nullptr;
    //hrv2poincareplot * hrv2_poincare_ptr = nullptr;
    //hrvdfaplot * hrv_dfa_ptr = nullptr;
    //qrsplot * qrs_ptr = nullptr;

    //st segment i inne na podstawie qrsplot?


    // obliczone wartości
    //Frequency_Params * frequency_params_ptr = nullptr;
    //Time_Params * time_params_ptr = nullptr;



public:


// settery dla wykresów
    void set_ecgplot(ecgplot * plot){ecg_ptr = plot;}

    void set_hrv1plot(hrv1plot * plot){hrv1_ptr = plot;}

    void set_hrv2histplot(hrv2histplot * plot){hrv2hist_ptr = plot;}

   // void set_hrv2poincareplot(hrv2poincareplot * plot){hrv2_poincare_ptr = plot;}

    //void set_hrvdfaplot(hrvdfaplot * plot){hrv_dfa_ptr = plot;}

    //void set_qrsplot(qrsplot * plot) {qrs_ptr = plot;}


    //całość musi być w jednej funkcji, bo inaczej QPainter umiera
    void print_all();

};


#endif // NEW_REPORT_H
