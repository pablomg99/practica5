#include "pared.h"

pared::pared()
{
}

pared::pared(int x, int y, int w, int h)
{
    this->posx=x;
    this->posy=y;
    this->h=h;
    this->w=w;
}

QRectF pared::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}

/*void pared::paint_barreras()
{
    QRectF rectangulo;
    QPainter *painter;
    painter->setBrush(Qt::green);

    vector<vector<string>>::iterator it;
    int _x, _y, _ancho, _alto;
    for(it=vector_barreras.begin(); it!=vector_barreras.end(); it++)
    {
        _x=0;
        _y=0;
        _ancho=0;
        _alto=0;

        for(int i = 0; i<4; i++)
        {
            if(i==0) _x=stringToInt((*it)[i]);
            else if(i==1) _y=stringToInt((*it)[i]);
            else if(i==2) _ancho=stringToInt((*it)[i]);
            else if(i==3) _alto=stringToInt((*it)[i]);
        }
    }
}*/
