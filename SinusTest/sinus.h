#ifndef SINUS_H
#define SINUS_H

class Sinus{
public:
    Sinus();
    ~Sinus();
    float getValue();
    void setAmplitude(float amplitude);
private:
    int index;
    float amplitude;
};

#endif
