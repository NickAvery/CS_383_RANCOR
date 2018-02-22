#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QApplication>
#include <QMediaPlayer>


class Audio{
 public:
  Audio(int sound_choice, QString soundpath);    //1 for a sound 2 for a song.
                                                //A typical sound path looks like "qrc:/sounds/Faltering-Circuits.mp3"
                                                //please inform me if you would like new sounds or music to be added I will then provide you with a string to put in your code to call


  int Play_Noise();                             //If you choose a sound use this method.
  int Play_Music();                             //If you choose a song use this method.



  int Set_GameState(int state);                 //not currently working for the purpose of the demo
  int Get_gameState();                          //not currently working for the purpose of the demo
  int Set_CharClass(int CharClass);             //not currently working for the purpose of the demo
  
 private:
  int mCharClass;       //not currently working for the purpose of the demo
  int mGameState;       //not currently working for the purpose of the demo
  QMediaPlayer * sound; //holds the sound information
};
#endif
