#include "pacman.h"

pacman::pacman(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixCol=229;
    pixFila=0;
    pixmap=new QPixmap(":/recursos/PacManSprites.png");
    ancho = 15;
    alto = 15;
    posx=69;
    posy=163;
    velocidad=1;
    timer->start(70);

    connect(timer, &QTimer::timeout, this, &pacman::Actualizacion);
}

void pacman::Actualizacion()
{
    pixFila=0;
    pixCol=229;
    pixFila=filas*(alto+1);
    pixCol=columnas*(ancho+1)+229;

    columnas+=1;
    if(columnas>3){
        columnas=0;
        pixCol=229;
    }
    this->update(-ancho/2, -alto/2 ,ancho,alto);
}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap,pixCol,pixFila,ancho,alto);
}

void pacman::moveUp()
{
    filas=2;
    posy=posy-velocidad;
    setPos(posx,posy);
}

void pacman::moveDown()
{
    filas=3;
    posy=posy+velocidad;
    setPos(posx,posy);
}

void pacman::moveLeft()
{
    filas=1;
    posx=posx-velocidad;
    setPos(posx,posy);
}

void pacman::moveRight()
{
    filas=0;
    posx=posx+velocidad;
    setPos(posx,posy);
}
