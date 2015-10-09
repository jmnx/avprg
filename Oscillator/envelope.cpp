#include <QDebug>
#include <math.h>
#include "envelope.h"
const float MIN_GAIN_DB = -100;

Envelope::Envelope()
    : sampleRate(0), gain(0), state(OFF), releaseSeconds(0)
    , attackSeconds(0), decaySeconds(0)
    , sustain_dB(MIN_GAIN_DB), minGain_dB(MIN_GAIN_DB)
{
    sustainGain = minGain = pow(10, MIN_GAIN_DB/20);
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
    this->sustainGain = pow(10, sustain_dB/20);
    this->sustain_dB = sustain_dB;
}

void Envelope::setState(State state){
    this->state = state;
    // avoid division by zero
    if (state == ATTACK && attackSeconds == 0){
        setState(ON);
    }
    else if (state == RELEASE && releaseSeconds == 0){
        setState(OFF);
    }
    else {
        if (state == OFF){
            gain = 0;
            qDebug() << "OFF";
        }
        if (state == ATTACK){
            gainChange = pow(10, fabs(MIN_GAIN_DB) / (attackSeconds * sampleRate));
        }
        if (state == DECAY){
            gainChange = 1/pow(10, fabs(sustain_dB) / (decaySeconds * sampleRate));
        }
        if (state == RELEASE){
            gainChange =  1/pow(10, (fabs(sustain_dB) - fabs(MIN_GAIN_DB))/(sampleRate * releaseSeconds));
        }
        if (state == ON){
            gain = 1;
            qDebug() << "ON";
        }
    }
}


float Envelope::process(float input){
    if(state == ATTACK && gain >= 1){
        setState(DECAY);
    }
    if (state == DECAY && gain < sustainGain){
        setState(ON);
    }
    if (state == RELEASE && gain < minGain){
        setState(OFF);
    }
    gain *= gainChange;

    return gain * input;
}
