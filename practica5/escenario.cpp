#include "escenario.h"

escenario::escenario()
{
    this->posx=0;
    this->posy=0;
    this->ancho=224;
    this->alto=248;
}

QRectF escenario::boundingRect() const
{
    return QRect(posx, posy, ancho, alto);
}

void escenario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/recursos/MapaVacio.png");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}
