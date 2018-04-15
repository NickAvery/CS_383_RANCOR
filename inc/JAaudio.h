#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QApplication>
#include <QMediaPlayer>
#include "JAaudiosuper.h"

//class Audio;
//class Music;
//class Sound;

class AudioInter: public QObject{
//    Q_OBJECT
 public:
    AudioInter(int sound_choice, QString soundpath);    //1 for a sound 2 for a song.
    int setCharClass(int CharClass);                   //not currently working for the purpose of the demo
                                                      //A typical sound path looks like "qrc:/sounds/Faltering-Circuits.mp3"
    void stressTest();                                           //please inform me if you would like new sounds or music to be added I will then provide you with a string to put in your code to call
    int setVolume(int volume);
    int playSound();  //If you choose a song use this method.
    void setSound(QString);
public slots:
    void musicManage();

 private:

  int mCharClass;                                     //not currently working for the purpose of the demo
  AudioAll* mClass;
  //QMediaPlayer * mSound;                               //holds the sound information

  void delay();
};
#endif
