#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

class Person : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Person(QString name, QPixmap pix, QObject *parent = nullptr);

    QString getName() const;
    void highlight(bool on);

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

private:
    QString name;
    bool isHighlighted = false;
};

#endif