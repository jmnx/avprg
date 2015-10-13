INCLUDEPATH += ../drumstick/
         ../drumstick/include/

HEADERS += \
    ../drumstick/midiinput.h\
    ../drumstick/midioutput.h\
    ../drumstick/alsamidiinput.h\
    ../drumstick/alsamidioutput.h

SOURCES += ../drumstick/alsamidiinput.cpp\
    ../drumstick/alsamidioutput.cpp

LIBS += -framework CoreMidi -framework CoreFoundation
