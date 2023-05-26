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

    if(Cdatos.fallaLectura==true)
    {
        ui->lblError->setText("Error de lectura del archivo");
    }

    else{
        ui->lblError->setText("Archivo leido correctamente");
        QList<QList<int>>::iterator it;
        for(it=Cdatos.datos.begin(); it != Cdatos.datos.end(); it++){
            Paredes.push_back(new pared((*it)[0], (*it)[1], (*it)[2], (*it)[3]));
            scene->addItem(Paredes.back());
        }
    }

    scene->addItem(fondo);


    personaje=new pacman();
    scene->addItem(personaje);
    personaje->setPos(personaje->posx,personaje->posy);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_W){
        if(!evaluarColision()){
            personaje->moveUp();
        }
        else{
            personaje->moveDown();
        }
    }
    else if(evento->key() == Qt::Key_S){
        if(!evaluarColision()){
            personaje->moveDown();
        }
        else{
            personaje->moveUp();
        }
    }
    else if(evento->key() == Qt::Key_A){
        if(!evaluarColision()){
            personaje->moveLeft();
        }
        else{
            personaje->moveRight();
        }
    }
    else if(evento->key() == Qt::Key_D){
        if(!evaluarColision()){
            personaje->moveRight();
        }
        else{
            personaje->moveLeft();
        }
    }
}

bool MainWindow::evaluarColision()
{
    QList<pared*>::Iterator iterator;
    for(iterator= Paredes.begin(); iterator!=Paredes.end(); iterator++)
    {
        if((*iterator)->collidesWithItem(personaje))
        {
            return true;
        }
    }
    return false;
}

