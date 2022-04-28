TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fileinfo.cpp \
        main.cpp \
        observable.cpp \
        observer.cpp

HEADERS += \
    fileinfo.h \
    observable.h \
    observer.h
