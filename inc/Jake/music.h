#ifndef MUSIC_H
#define MUSIC_H

#include <QString>
#include "JAaudiosuper.h"
#include <QString>
#include <QMediaPlayer>


class Music: public AudioAll{
private:
    Music(QString);
    static Music* sUniqueInstance;
    ~Music(){}

public:

     static Music *getInstance(QString passedString);

    Music(const Music&);
    Music& operator=(const Music&);

    //plays the music once called. Will start the song over again.
    void play(void);

    //pauses the music
    void pause(void);

    //sets the volume for the music
    void setVolume(int x);

    //sets the current sound file to be played
    void setSound(QString);

public slots:
    //restarts the music once it finds the song has stopped playing
    void manage();


};

#endif // MUSIC_H

