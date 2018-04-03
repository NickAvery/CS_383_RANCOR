 #ifndef AUDIO_H
#define AUDIO_H

#include <QDebug>
#include <QString>

class Audio{
public:
    void saySomething(){ qDebug() << "something";
                       name = "string";}
    virtual void play(void)= 0;
    virtual void pause(void) = 0;
private:
    Qstring name;
};

/*

class Music: public Audio{
public:
    Music(QString);
    void play(void);
    void pause(void);
private:
    QMediaPlayer * mSound;

};


class Sound:public Audio{
    Sound(QString);

    int play();
    int pause();
private:
    QMediaPlayer * mSound;

};

*/
#endif // AUDIO_H
