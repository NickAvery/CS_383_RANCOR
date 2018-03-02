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


#endif // AUDIO_H
