#include "pared.h"

pared::pared()
{
}

pared::pared(int x, int y, int _w, int _h)
{
    this->posx=x;
    this->posy=y;
    this->h=_h;
    this->w=_w;
}

QRectF pared::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());
}
