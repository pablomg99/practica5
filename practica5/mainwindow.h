#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QWidget>
#include <QRectF>
#include <QDebug>
#include <QGraphicsItem>
#include <QPainter>
#include "escenario.h"
#include "pared.h"
#include "archivo.h"
#include "pacman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    escenario *fondo;
    Archivo Cdatos;
    QList<pared*> Paredes;
    pacman *personaje;
};
#endif // MAINWINDOW_H
