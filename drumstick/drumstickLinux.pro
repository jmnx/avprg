INCLUDEPATH += ../drumstick

HEADERS += \
    ../drumstick/midiinput.h\
    ../drumstick/midioutput.h\
    ../drumstick/alsamidiinput.h\
    ../drumstick/alsamidioutput.h\
    ../drumstick/alsaclient.h\
    ../drumstick/alsaport.h\
    ../drumstick/subscription.h\
    ../drumstick/drumstickcommon.h\
    ../drumstick/macros.h\
    ../drumstick/alsaevent.h\
    ../drumstick/rtmidiinput.h\
    ../drumstick/rtmidioutput.h


SOURCES += ../drumstick/alsamidiinput.cpp\
    ../drumstick/alsamidioutput.cpp

#LIBS += -framework CoreMidi -framework CoreFoundation
