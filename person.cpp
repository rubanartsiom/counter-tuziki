#include "person.h"

Person::Person(QString name, QPixmap pix, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(pix), name(name)
{
}

QString Person::getName() const
{
    return name;
}

void Person::highlight(bool on)
{
    isHighlighted = on;
    update();
}

void Person::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);

    if (isHighlighted)
    {
        QPen pen(Qt::red);
        pen.setWidth(4);

        painter->setPen(pen);
        painter->setBrush(Qt::NoBrush);

        painter->drawRect(boundingRect());
    }
}