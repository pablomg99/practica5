#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsItem>
#include <fstream>
#include <vector>
#include "escenario.h"
#include "pared.h"
#include "archivo.h"
using namespace std;

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
    archivo DataBase;
    QList<pared*> Paredes;
};
#endif // MAINWINDOW_H
