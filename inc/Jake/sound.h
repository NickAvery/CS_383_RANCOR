
 #ifndef SOUND_H
#define SOUND_H

#include "JAaudiosuper.h"
#include <QString>
#include <QMediaPlayer>

class Sound:public AudioAll{
   public:

    Sound(QString);

    void play();
    void pause();
    void setVolume(int x);
};

#endif // SOUND_H

