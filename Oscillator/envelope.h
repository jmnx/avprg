#ifndef ENVELOPE_H
#define ENVELOPE_H


class Envelope
{
public:
    enum State{OFF, ON, ATTACK, RELEASE};
    Envelope();
    void setSampleRate(float sampleRate);
    float process(float input);
    void setState(State state);
    void setReleaseSeconds(float seconds);
    void setAttackSeconds(float seconds);
private:
    State state;
    float sampleRate;
    float gain;
    float releaseSeconds;
    float attackSeconds;
};

#endif // ENVELOPE_H
