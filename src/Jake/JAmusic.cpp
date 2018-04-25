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
    //plays next song once current one finishes
    if(!(mSound->state() == QMediaPlayer::PlayingState)){
        static int x =0;
        if(!x){
            setSound(QString("qrc:/sounds/Sounds/Light-Years_v001.mp3"));
            x++;
            setVolume(20);
        }
        else if( x == 1){
            setSound(QString("qrc:/sounds/Sounds/The-Creeping-Blob.mp3"));
            setVolume(70);
            x++;
        }else if(x == 2){
            setSound(QString("qrc:/sounds/Sounds/Break-Down.mp3"));
            setVolume(20);
            x =0;
        }
      mSound->play();
    }
}
