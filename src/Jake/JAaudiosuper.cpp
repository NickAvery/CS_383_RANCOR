#include "JAaudiosuper.h"


AudioAll::AudioAll(QString x){
    name = x;
}

void AudioAll::setVolume(int vol){
    mSound->setVolume(vol);

}



