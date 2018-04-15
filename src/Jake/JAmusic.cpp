
#include "music.h"
#include <QMediaPlayer>

Music::Music(QString x) : AudioAll(x){
    name = x;
    mSound = new QMediaPlayer();
    mSound->setMedia(QUrl(x));

}


void Music::setVolume(int x){
    mSound->setVolume(x);

}

void Music::play(void)
{
    mSound->play();
}

void Music::pause(void)
{
    mSound->pause();
}

