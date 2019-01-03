QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

# TARGET = TapBar
TEMPLATE = app
include ( $$PWD/../3rdparty/Qwt-6.1.3/features/qwt.prf )
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
    Modules/test_get_input.cpp \
    Modules/ecg_baseline_module.cpp \
    Modules/r_peaks_module.cpp \
    Modules/hrv1_module.cpp \
    Modules/hrv2_module.cpp \
    Modules/hrv_dfa_module.cpp \
    Modules/waves_module.cpp \
    View/ecgbaseline_gui.cpp \
    View/heart_class_gui.cpp \
    View/hrv1_gui.cpp \
    View/hrv2_gui.cpp \
    View/hrv_dfa_gui.cpp \
    View/r_peaks_gui.cpp \
    View/st_segment_gui.cpp \
    View/t_alt_class_gui.cpp \
    View/ecgplot.cpp \
    View/qrsplot.cpp \
    View/hrv1plot.cpp \
    View/hrv2poincareplot.cpp \
    View/hrv2histplot.cpp \
    Modules/t_wave_alt_module.cpp \
    Modules/t_peaks.cpp

HEADERS += \
    View/mainview.h \
    Modules/examination.h \
    Modules/ecg_baseline_module.h \
    Modules/r_peaks_module.h \
    Modules/hrv1_module.h \
    Modules/hrv2_module.h \
    Modules/hrv_dfa_module.h \
    Modules/waves_module.h \
    View/ecgbaseline_gui.h \
    View/heart_class_gui.h \
    View/hrv1_gui.h \
    View/hrv2_gui.h \
    View/hrv_dfa_gui.h \
    View/r_peaks_gui.h \
    View/st_segment_gui.h \
    View/t_alt_class_gui.h \
    View/qrsplot.h \
    View/ecgplot.h \
    View/hrv1plot.h \
    View/hrv2poincareplot.h \
    View/hrv2histplot.h \
    Modules/t_wave_alt_module.h \
    Modules/t_peaks.h

FORMS += \
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
               $$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/include \
               $$PWD/../3rdparty/sgsmooth-master/include/sgsmooth \
               $$PWD/../3rdparty/alglib/src \
               $$PWD/../3rdparty/Qwt-6.1.3/include

DEPENDPATH += $$PWD/../3rdparty/armadillo/include \
              $$PWD/../3rdparty/sigpack/include \
              $$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/include \
              $$PWD/../3rdparty/sgsmooth-master/include/sgsmooth \
              $$PWD/../3rdparty/alglib/src \
              $$PWD/../3rdparty/Qwt-6.1.3/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3rdparty/sgsmooth-master/build/release/ -lsgsmooth \
                                              -L$$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/Builds/VisualStudio2017/release/ -lDSPFilters \
                                              -L$$PWD/../3rdparty/Qwt-6.1.3/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3rdparty/sgsmooth-master/build/debug/ -lsgsmooth \
                                                 -L$$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/Builds/VisualStudio2017/debug/ -lDSPFilters \
                                                 -L$$PWD/../3rdparty/Qwt-6.1.3/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../3rdparty/sgsmooth-master/build/ -lsgsmooth \
                   -L$$PWD/../3rdparty/DSPFilters-master/shared/DSPFilters/Builds/VisualStudio2017/ -lDSPFilters \
                   -L$$PWD/../3rdparty/Qwt-6.1.3/lib/ -lqwt
