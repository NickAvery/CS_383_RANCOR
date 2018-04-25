
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

    //pauses the music
    void pause();

    //sets the current sound file to be played
    void setSound(QString);

public slots:
    //does nothing. music need not be managed, And is never called.
    void manage(){}

};

#endif // SOUND_H

