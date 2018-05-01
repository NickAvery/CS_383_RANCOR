#ifndef JTCOLLIDABLE_H
#define JTCOLLIDABLE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Collidable: public QObject, public QGraphicsPixmapItem
{
public:
    Collidable(QPixmap *pic);
};

#endif // JTCOLLIDABLE_H
