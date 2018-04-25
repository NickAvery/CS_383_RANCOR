#ifndef MUSIC_H
#define MUSIC_H

#include <QString>
#include "JAaudiosuper.h"
#include <QString>
#include <QMediaPlayer>
/*
 * Music was taken Royalty-Free online from www.soundimage.org
 * Music by Eric Matyas
 * In order to legally have this video game be public, this must be properly attriubuted by displaying
 * "Music by Eric Matya"
 * "www.soundimage.org"
 * This must be displayed somewhere on the credits screne which we currently do not have.
 */



class Music: public AudioAll{
private:
    Music(QString);
    //private constructor because this is te implementation of the singleton class

    static Music* sUniqueInstance;
    //This is a pointer to the only object of the music class taht should exist


public:

     static Music *getInstance(QString passedString);

    Music(const Music&);
    Music& operator=(const Music&);

    //plays the music once called. Will start the song over again.
    void play(void);

    //pauses the music
    void pause(void);

    //sets the current sound file to be played
    void setSound(QString);

public slots:
    //restarts the music once it finds the song has stopped playing
    void manage();


};

#endif // MUSIC_H

