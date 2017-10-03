TEMPLATE = app
TARGET = trie-test

CONFIG += c++14 debug_and_release

INCLUDEPATH += ../../include
SOURCES += ../../tests/main.cpp

#CONFIG debug and release must be
DESTDIR = ../../bin

HEADERS += \
    ../../include/trie/trie.h
