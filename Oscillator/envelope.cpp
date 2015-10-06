#include <QDebug>
#include "envelope.h"

Envelope::Envelope()
    : sampleRate(0), gain(0), state(OFF)
{

}
void Envelope::setSampleRate(float sampleRate){
    this->sampleRate = sampleRate;
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
    float output = gain * input;
    return output;
}
