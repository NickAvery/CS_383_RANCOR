#include "sound.h"

Sound::Sound(QString soundPath):AudioAll(soundPath){
    name = soundPath;
    mSound = new QMediaPlayer();
    mSound->setMedia(QUrl(name));
}


void Sound::play()
{
    //randomizes damage sounds to not be all the same;

    if((name == QString("qrc:/sounds/Sounds/damage1.wav"))|| (name == QString("qrc:/sounds/Sounds/damage2.wav")) ||( name == QString("qrc:/sounds/Sounds/damage3.wav"))){
        int x = rand()%3;
        if(x == 0)
            setSound(QString("qrc:/sounds/Sounds/damage1.wav"));
        if(x == 1)
            setSound(QString("qrc:/sounds/Sounds/damage2.wav"));
        if(x == 2)
            setSound(QString("qrc:/sounds/Sounds/damage3.wav"));
    }
    if(mSound->state()==QMediaPlayer::PlayingState){
         mSound->setPosition(0);
    }
    else if(mSound->state() == QMediaPlayer::StoppedState){
        mSound->play();
    }
    mSound->play();




}
void Sound::setSound(QString soundPath){
    name = soundPath;
    mSound->setMedia(QUrl(soundPath));
}

void Sound::pause()
{
    mSound->pause();
}

