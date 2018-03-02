/*
 * #ifndef SOUND_H
#define SOUND_H

#include "audio.h"
#include <QString>
#include <QMediaPlayer>
//class Audio;

class Sound:public Audio{
    Sound(QString);

    int play();
    int pause();
private:
    QMediaPlayer * mSound;

};
#endif // SOUND_H
*/
