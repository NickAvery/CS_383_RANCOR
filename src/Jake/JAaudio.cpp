#include "JAaudio.h"

Audio::Audio(int Sound_choice, QString soundpath){
    sound = new QMediaPlayer();
    sound->setMedia(QUrl(soundpath));

}

int Audio::Play_Noise(){ //sound effect that you wish to be played
    sound->play();
    return 0;
}


int Audio::Play_Music(){
    sound->play();

    return 0;
}


int Audio::Set_GameState(int state){
return 0;
}

int Audio::Get_gameState(){

return 0;
}


int Audio::Set_CharClass(int CharClass){

return 0;
}
