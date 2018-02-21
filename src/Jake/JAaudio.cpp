#include "JAaudio.h"

Audio::Audio(int Sound_choice, string soundpath){
    sound = new QMediaPlayer();
    sound->setMedia(QUrl(soundpath));

}

int Audio::Play_Noise(){ //sound effect that you wish to be played
    sound->play();
}


int Audio::Play_Music(){
    sound->play();


}


int Audio::Set_GameState(int state){

}

int Audio::Get_gameState(){


}


int Audio::Set_CharClass(int CharClass){


}
