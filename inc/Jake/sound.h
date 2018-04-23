
 #ifndef SOUND_H
#define SOUND_H

#include "JAaudiosuper.h"
#include <QString>
#include <QMediaPlayer>

class Sound:public AudioAll{
   public:

    Sound(QString);
    //plays the sound once called. Will start the song over again.
    void play();
    //AudioAll* getInsance(QString y){y;}
    //pauses the music
    void pause();

    //sets the volume for the music
    void setVolume(int x);

    //sets the current sound file to be played
    void setSound(QString);

public slots:
    //does nothing
    void manage(){}

};

#endif // SOUND_H

