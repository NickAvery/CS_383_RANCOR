#include "JAaudio.h"
#include "music.h"
#include "sound.h"
#include "audio.h"

AudioInter::AudioInter(int Sound_choice, QString soundpath){
    /*if(Sound_choice == 1){
        mClass = new Sound(soundpath);
    }
    else{
        mClass = new Music(soundpath);
    }*/
    Sound_choice++;
    mSound = new QMediaPlayer;
    mSound->setMedia(QUrl(soundpath));
}



int AudioInter::PlaySound(){ //sound effect that you wish to be played
    mSound->play();
    //mClass->play();
    return 0;
}



int AudioInter::Set_CharClass(int CharClass){
    mCharClass = CharClass;
    return 0;
}
