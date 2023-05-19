#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class escenario: public QGraphicsItem
{
    int posx, posy, ancho, alto;

public:
    escenario();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // ESCENARIO_H
