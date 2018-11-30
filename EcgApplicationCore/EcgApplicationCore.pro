QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    ecg_baseline.cpp \
    r_peaks0.cpp \
    View/mainview.cpp \
    View/heart_class.cpp \
    View/t_alt_class.cpp \
    View/hrv1.cpp \
    View/hrv2.cpp \
    View/st_segment.cpp \
    View/hrv_dfa.cpp \
    View/ecgbaseline.cpp \
    View/r_peaks.cpp \
    test_get_input.cpp \
    hrv2.cpp \
    hrv_dfa.cpp \
    hrv1_.cpp

HEADERS += \
    ecg_baseline.h \
    r_peaks0.h \
    View/mainview.h \
    View/heart_class.h \
    View/t_alt_class.h \
    View/hrv1.h \
    View/hrv2.h \
    View/st_segment.h \
    View/hrv_dfa.h \
    View/ecgbaseline.h \
    View/r_peaks.h \
    examination.h \
    hrv2.h \
    hrv_dfa.h \
    hrv1_.h

FORMS += \
    View/mainview.ui \
    View/heart_class.ui \
    View/t_alt_class.ui \
    View/hrv1.ui \
    View/hrv2.ui \
    View/st_segment.ui \
    View/hrv_dfa.ui \
    View/ecgbaseline.ui \
    View/r_peaks.ui

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
