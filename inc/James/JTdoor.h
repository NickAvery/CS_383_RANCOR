#ifndef JTDOOR_H
#define JTDOOR_H

#include <QGraphicsItem>
#include <QObject>
#include <QString>

//add identifying member to this class
class Door: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Door * door;
    QString name;
    //int direction;
    Door(bool sides, QString n);
};

#endif // JTDOOR_H
