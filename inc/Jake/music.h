#ifndef MUSIC_H
#define MUSIC_H

#include <QString>
#include "JAaudiosuper.h"
#include <QString>
#include <QMediaPlayer>


class Music: public AudioAll{
public:
    Music(QString);
    void play(void);
    void pause(void);
    void setVolume(int x);
};

#endif // MUSIC_H

