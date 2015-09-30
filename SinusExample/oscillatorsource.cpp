#include "oscillatorsource.h"
#include <iostream>
#include "sinus.h"

OscillatorSource::OscillatorSource()
{
    Sinus* sinus = new Sinus;
    currentSource = sinus;
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setChannelCount(2);
    audioFormat.setSampleSize(32);
    audioFormat.setSampleType(QAudioFormat::Float);
    audioFormat.setSampleRate(44100);

}

void OscillatorSource::setSource(Source& source) {
    std::cout << "Changing source\n ... ... \n" ;
    currentSource = &source;
    std::cout << "Done!\n";
}

void OscillatorSource::start(){

}
const QAudioFormat& OscillatorSource::format() const{
    return audioFormat;
}

void OscillatorSource::setVolume(float amplitude){
    currentSource->setVolume(amplitude);
}

void OscillatorSource::setSampleRate(float sample){
    currentSource->setSampleRate(sample);
}

void OscillatorSource::setFrequency(float freq){
    currentSource->setFrequency(freq);
}

qint64 OscillatorSource::read(float** buffer, qint64 numFrames){

    // get audio data for left channel
    for(int i = 0; i < numFrames; i++){
        buffer[0][i] = (float) currentSource->getValue();
    }
    // copy to other channels
    for(int c = 0; c < audioFormat.channelCount(); c++){
        for(int i = 0; i < numFrames; i++){
            buffer[c][i] = buffer[0][i];
        }
    }
    return numFrames;
}
void OscillatorSource::stop(){}
