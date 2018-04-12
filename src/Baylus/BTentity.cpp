
#include "BTentity.h"

Entity::Entity(QPixmap p)
{
    //mGraphic = p;
    setPixmap(p);
}

void Entity::move()
{

}

void Entity::update()
{

}

void Entity::setGraphic(const QPixmap &graphic)
{
    //mGraphic = graphic;
    setPixmap(graphic);
}
