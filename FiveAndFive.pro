#-------------------------------------------------
#
# Project created by QtCreator 2014-04-07T10:05:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = FiveAndFive
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    FiveAndFive.cpp

HEADERS += \
    FiveAndFive.h \
    FileError.h \
    FileOpenError.h \
    FileReadError.h \
    FileWriteError.h \
    LogicError.h \
    InvalidArgument.h \
    OutOfRange.h
