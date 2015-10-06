#ifndef ENVELOPE_H
#define ENVELOPE_H


class Envelope
{
public:
    enum State{OFF, ON};
    Envelope();
    void setSampleRate(float sampleRate);
    float process(float input);
    void setState(State state);
private:
    State state;
    float sampleRate;
    float gain;
};

#endif // ENVELOPE_H
