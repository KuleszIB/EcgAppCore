QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

<<<<<<< HEAD
# TARGET = TapBar
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    View/mainview.cpp \
    test_get_input.cpp \
    ecg_baseline_module.cpp \
    r_peaks_module.cpp \
    hrv1_module.cpp \
    hrv2_module.cpp \
    hrv_dfa_module.cpp \
    waves_module.cpp \
    qcustomplot.cpp \
    View/ecgbaseline_gui.cpp \
    View/heart_class_gui.cpp \
    View/hrv1_gui.cpp \
    View/hrv2_gui.cpp \
    View/hrv_dfa_gui.cpp \
    View/r_peaks_gui.cpp \
    View/st_segment_gui.cpp \
    View/t_alt_class_gui.cpp
=======
HEADERS += \
    themewidget.h \
    ecg_baseline.h \
    r_peaks.h

SOURCES += \
    main.cpp \
    themewidget.cpp \
    ecg_baseline.cpp \
    r_peaks.cpp
>>>>>>> 9c75e337befa4b78811cae32a2841c66c063fdf0

HEADERS += \
    View/mainview.h \
    examination.h \
    ecg_baseline_module.h \
    r_peaks_module.h \
    hrv1_module.h \
    hrv2_module.h \
    hrv_dfa_module.h \
    waves_module.h \
    qcustomplot.h \
    View/ecgbaseline_gui.h \
    View/heart_class_gui.h \
    View/hrv1_gui.h \
    View/hrv2_gui.h \
    View/hrv_dfa_gui.h \
    View/r_peaks_gui.h \
    View/st_segment_gui.h \
    View/t_alt_class_gui.h

FORMS += \
<<<<<<< HEAD
    View/mainview.ui \
    View/ecgbaseline_gui.ui \
    View/heart_class_gui.ui \
    View/hrv1_gui.ui \
    View/hrv2_gui.ui \
    View/hrv_dfa_gui.ui \
    View/r_peaks_gui.ui \
    View/st_segment_gui.ui \
    View/t_alt_class_gui.ui

RESOURCES += \
    tapbarresource.qrc

INCLUDEPATH += $$PWD/../3rdparty/armadillo/include \
               $$PWD/../3rdparty/sigpack/include \
               $$PWD/../3rdparty/wfdb/lib \
               $$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/include \
               $$PWD/../3rdparty/sgsmooth-master/include/sgsmooth \
               $$PWD/../3rdparty/alglib/src

DEPENDPATH += $$PWD/../3rdparty/armadillo/include \
              $$PWD/../3rdparty/sigpack/include \
              $$PWD/../3rdparty/wfdb/lib \
              $$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/include \
              $$PWD/../3rdparty/sgsmooth-master/include/sgsmooth \
              $$PWD/../3rdparty/alglib/src

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3rdparty/sgsmooth-master/build/release/ -lsgsmooth \
                                              -L$$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/Builds/VisualStudio2017/release/ -lDSPFilters
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3rdparty/sgsmooth-master/build/debug/ -lsgsmooth \
                                                 -L$$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/Builds/VisualStudio2017/debug/ -lDSPFilters
else:unix: LIBS += -L$$PWD/../3rdparty/sgsmooth-master/build/ -lsgsmooth \
                   -L$$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/Builds/VisualStudio2017/ -lDSPFilters
=======
    themewidget.ui

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../liquid-dsp/lib/' -lliqui
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../liquid-dsp/lib/' -lliquid

INCLUDEPATH += $$PWD/'../liquid-dsp/include' \
               $$PWD/'../3rdparty/armadillo-9.200.4/include' \
               $$PWD/'../3rdparty/sigpack-1.2.4/sigpack' \
               $$PWD/'../3rdparty/wfdb-10.6.0/lib' \
               $$PWD/'../3rdparty/DSPFilters-master/shared/DSPFilters/include' \
               $$PWD/'../3rdparty/sgsmooth-master/include/sgsmooth'

DEPENDPATH += $$PWD/'../liquid-dsp/include' \
              $$PWD/'../3rdparty/armadillo-9.200.4/include' \
              $$PWD/'../3rdparty/sigpack-1.2.4/sigpack' \
              $$PWD/'../3rdparty/wfdb-10.6.0/lib' \
              $$PWD/'../3rdparty/DSPFilters-master/shared/DSPFilters/include' \
              $$PWD/'../3rdparty/sgsmooth-master/include/sgsmooth'
>>>>>>> 9c75e337befa4b78811cae32a2841c66c063fdf0
