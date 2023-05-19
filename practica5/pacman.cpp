#include "pacman.h"

pacman::pacman(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 1;
    columnas = 0;
    pixCol=229;
    pixFila=0;
    pixmap=new QPixmap(":/recursos/PacManSprites.png");
    ancho = 15;
    alto = 15;
    timer->start(500);

    connect(timer, &QTimer::timeout, this, &pacman::Actualizacion);
}

void pacman::Actualizacion()
{
    pixCol=pixCol+((columnas*ancho)+columnas);
    pixFila=pixFila+((filas*alto)+filas);
    columnas+=1;
    if(columnas>=3){
        columnas=0;
        pixCol=229;
    }
    this->update(-ancho/2, -alto/2 ,ancho,alto); //revisar
}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,*pixmap,pixCol,pixFila,ancho,alto);
}

/*pacman::pacman(int x, int y)
{

}

QRectF pacman::boundingRect() const
{

}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void pacman::moveUp()
{

}

void pacman::moveDown()
{

}

void pacman::moveLeft()
{

}

void pacman::moveRight()
{

}*/
