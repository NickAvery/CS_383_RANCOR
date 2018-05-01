#ifndef JTDOOR_H
#define JTDOOR_H

#include <QGraphicsItem>
#include <QObject>
#include <QString>

class Door: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    Door * mDoor;
public:
    QString mName;
    Door(bool sides, QString doorName);
};

#endif // JTDOOR_H
