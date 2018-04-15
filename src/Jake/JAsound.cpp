
#include "sound.h"

Sound::Sound(QString x):AudioAll(x){
    name = x;
    mSound = new QMediaPlayer();
    mSound->setMedia(QUrl(x));
}

void Sound::setVolume(int x){
    mSound->setVolume(x);

}

void Sound::play()
{
    mSound->play();
}

void Sound::pause()
{
    mSound->pause();
}

