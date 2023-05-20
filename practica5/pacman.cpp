#include "pacman.h"

pacman::pacman(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixCol=229;
    pixFila=0;
    pixmap=new QPixmap(":/recursos/PacManSprites.png");
    ancho = 16;
    alto = 16;
    timer->start(70);

    connect(timer, &QTimer::timeout, this, &pacman::Actualizacion);
}

void pacman::Actualizacion()
{
    pixFila=0;
    pixCol=229;
    pixFila=pixFila+(alto*filas);
    pixCol=pixCol+(ancho*columnas);

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
}

void pacman::moveDown()
{
    filas=3;
}

void pacman::moveLeft()
{
    filas=1;
}

void pacman::moveRight()
{
    filas=0;
}
