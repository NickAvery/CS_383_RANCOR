#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QApplication>
#include <QMediaPlayer>
#include "JAaudiosuper.h"

class AudioInter: public QObject{
    Q_OBJECT
 public:
    AudioInter(int sound_choice, QString soundpath, QObject *parent = NULL);
    //1 for a sound 2 for a song.
    //please inform me if you would like new sounds or music to be added I will then provide you with a string to put in your code to call

    int setCharClass(int CharClass);

    void stressTest();
    //Call this to run the stresstes for the audio portion of the code.

    int setVolume(int volume);
    //integer bewteen 1-100 to define the volume for the audio

    int playSound();
    //If you choose a song use this method.

    void setSound(QString);
     //A typical sound path looks like "qrc:/sounds/Faltering-Circuits.mp3"

public slots:
    void musicManage();
    //manages music by restarting the song when it stops

 private:

  int mCharClass;
  //not currently working for the purpose of the demo

  AudioAll* mClass;
  //The superClass that holds the information

  void delay();
  //delays for 1 second after being called.
  //CAUTION PUASES ALL TIMERS AND ALL MOVEMENT

};
#endif
