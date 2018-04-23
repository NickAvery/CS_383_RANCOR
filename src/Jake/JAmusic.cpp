#include <QTimer>
#include "music.h"
#include <QMediaPlayer>
Music* Music::sUniqueInstance;

Music::Music(QString songName) :AudioAll(songName){
    name = songName;
    mSound = new QMediaPlayer();
    mSound->setMedia(QUrl(songName));

}

Music* Music::getInstance(QString passedString)
{
   if(!sUniqueInstance)
      return sUniqueInstance = new Music(passedString);
   else
       return sUniqueInstance;

}


void Music::setVolume(int vol){
    mSound->setVolume(vol);

}

void Music::setSound(QString nextSongString){
    mSound->setMedia(QUrl(nextSongString));
}

void Music::play(void)
{
    mSound->play();
}

void Music::pause(void)
{
    mSound->pause();
}

void Music::manage(){
    if(!(mSound->state() == QMediaPlayer::PlayingState)){
        mSound->play();
    }
}
