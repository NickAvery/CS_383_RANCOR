#ifndef JAAUDIO_H
#define JAAUDIO_H

#include <QDebug>
#include <QString>
#include <QMediaPlayer>
class AudioAll{
public:
    AudioAll(QString);
    virtual void play()= 0;
    virtual void pause() = 0;
    virtual void setVolume(int x) = 0;
    virtual void setSound(QString) = 0;
public slots:
    virtual void manage() = 0;

protected:
    QString name;
    QMediaPlayer * mSound;
};
#endif // JAAUDIO_H


