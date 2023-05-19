#ifndef PACMAN_H
#define PACMAN_H
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QObject>
#include <QPainter>

class pacman: public QObject, public QGraphicsItem
{
    //int posx, posy, dimension, velocidad;

    Q_OBJECT
public:
    explicit pacman(QObject *parent=nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas, ancho, alto, pixCol, pixFila;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    /*pacman();
    pacman(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();*/

signals:

public slots:
    void Actualizacion();
};

#endif // PACMAN_H
