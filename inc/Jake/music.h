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
    void setSound(QString);
public slots:
    void manage();
};

#endif // MUSIC_H

