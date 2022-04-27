TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        observable.cpp \
        observer.cpp

HEADERS += \
    observable.h \
    observer.h
