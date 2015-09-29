#ifndef OSCILLATORSOURCE_H
#define OSCILLATORSOURCE_H

#include <vector>

#include "audiosource.h"
#include "oscillator.h"
class OscillatorSource: public AudioSource
{
public:
    OscillatorSource();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
    virtual void start();
    virtual void stop();
    void setSelectedOscillator(int index);
    void setFrequency(float frequency);
    void setGain(float gain);
private:
    QAudioFormat audioFormat;
    Oscillator oscillator;
};

#endif // OSCILLATORSOURCE_H
