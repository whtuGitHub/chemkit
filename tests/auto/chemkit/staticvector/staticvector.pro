QT += testlib
CONFIG += console
INCLUDEPATH += ../../../../include/
LIBS = -L../../../../lib -lchemkit -llapack -lblas
SOURCES += staticvectortest.cpp