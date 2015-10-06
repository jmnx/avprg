#ifndef ENVELOPE_H
#define ENVELOPE_H


class Envelope
{
public:
    enum State{OFF, ON, RELEASE};
    Envelope();
    void setSampleRate(float sampleRate);
    float process(float input);
    void setState(State state);
    void setReleaseSeconds(float seconds);
private:
    State state;
    float sampleRate;
    float gain;
    float releaseSeconds;
};

#endif // ENVELOPE_H
