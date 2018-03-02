#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QApplication>
#include <QMediaPlayer>
#include "audio.h"

//class Audio;
//class Music;
//class Sound;

class AudioInter{
 public:
  AudioInter(int sound_choice, QString soundpath);    //1 for a sound 2 for a song.
  int Set_CharClass(int CharClass);                   //not currently working for the purpose of the demo
                                                      //A typical sound path looks like "qrc:/sounds/Faltering-Circuits.mp3"
                                                      //please inform me if you would like new sounds or music to be added I will then provide you with a string to put in your code to call

  int PlaySound();                                         //If you choose a song use this method.

 private:

  int mCharClass;                                     //not currently working for the purpose of the demo
  //Audio* mClass;
  QMediaPlayer * mSound;                               //holds the sound information

};
#endif
