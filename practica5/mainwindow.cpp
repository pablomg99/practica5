#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 226, 250);
    fondo = new escenario();
    scene->addItem(fondo);

    QList<QList<int>>::iterator it;

    for(it=Cdatos.datos.begin(); it != Cdatos.datos.end(); it++){
        Paredes.push_back(new pared((*it)[0], (*it)[1], (*it)[2], (*it)[3]));
        scene->addItem(Paredes.back());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

