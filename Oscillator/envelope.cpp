#include <QDebug>
#include "envelope.h"

Envelope::Envelope()
    : sampleRate(0), gain(0), state(OFF), releaseSeconds(0)
{
    setReleaseSeconds(0.5);
}
void Envelope::setSampleRate(float sampleRate){
    this->sampleRate = sampleRate;
}
void Envelope::setReleaseSeconds(float seconds){
    this->releaseSeconds = seconds;
}

void Envelope::setState(State state){
    this->state = state;

    if (state == OFF){
        gain = 0;
        qDebug() << "OFF";
    }
    if (state == ON){
        gain = 1;
        qDebug() << "ON";
    }
}

float Envelope::process(float input){
    if(state == RELEASE){
        gain -= 1/(sampleRate * releaseSeconds);
        if (gain <= 0){
            setState(OFF);
        }
    }

    float output = gain * input;
    return output;
}
