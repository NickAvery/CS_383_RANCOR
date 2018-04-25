#ifndef JAAUDIO_H
#define JAAUDIO_H

#include <QDebug>
#include <QString>
#include <QMediaPlayer>
class AudioAll{
public:

    AudioAll(QString x);
    //constructor only initializes the name variable in this class


    //The Functions below are to be overrided by the subclass that derive from it
    virtual void play()= 0;    
    virtual void pause() = 0;

    //sets the volume for the music
    void setVolume(int x);

    virtual void setSound(QString) = 0;
public slots:
    virtual void manage() = 0;

protected:
    QString name;
        //holds the string path for the audio file

    QMediaPlayer * mSound;
        //Holds the audio player information
};
#endif // JAAUDIO_H



