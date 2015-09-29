#include <math.h>
#include "sinus.h"

const float pi = 3.1415926f;

Sinus::Sinus()
: index(0), amplitude(1)
{}

Sinus::~Sinus()
{
}

float Sinus::getValue(){
    float value = amplitude * sin(2 * pi * index / 100);
    index++;
    return value;
}

void Sinus::setAmplitude(float amplitude){
    this->amplitude = amplitude;
}
