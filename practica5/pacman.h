#ifndef PACMAN_H
#define PACMAN_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class pacman
{
    int posx, posy, dimension, velocidad;
public:
    pacman();
    pacman(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // PACMAN_H
