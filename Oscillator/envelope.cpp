#include <QDebug>
#include <math.h>
#include "envelope.h"
const float MIN_GAIN_DB = -100;

Envelope::Envelope()
    : sampleRate(0), gain(0), state(OFF), releaseSeconds(0)
    , attackSeconds(0), decaySeconds(0), sustain_dB(MIN_GAIN_DB)
{
    setReleaseSeconds(0.5);
    setAttackSeconds(1);
}
void Envelope::setSampleRate(float sampleRate){
    this->sampleRate = sampleRate;
}
void Envelope::setReleaseSeconds(float seconds){
    this->releaseSeconds = seconds;
}
void Envelope::setAttackSeconds(float seconds){
    this->attackSeconds = seconds;
}
void Envelope::setDecaySeconds(float seconds){
    this->decaySeconds = seconds;
}
void Envelope::setSustain_dB(float sustain_dB){
    this->sustain_dB = sustain_dB;
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
    // avoid division by zero
    if (state == ATTACK && attackSeconds == 0){
        setState(ON);
    }
    if (state == RELEASE && releaseSeconds == 0){
        setState(OFF);
    }
}

float Envelope::process(float input){
    if(state == ATTACK){
        gain *= pow(10, -MIN_GAIN_DB / (attackSeconds * sampleRate));
        if (gain >= 1){
            setState(DECAY);
            gain = 1;
        }
    }
    if (state == DECAY){
        gain /= pow(10, -sustain_dB / (decaySeconds * sampleRate));
        if (gain)
    }

    if(state == RELEASE){
        gain /= pow(10, -MIN_GAIN_DB/(sampleRate * releaseSeconds));
        if (gain <= MIN_GAIN_DB){
            setState(OFF);
        }
    }

    return gain * input;
}
