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

    vector<vector<string>>::iterator it;
    int _x, _y, _ancho, _alto;
    for(it=barreras.vector_barreras.begin(); it!=barreras.vector_barreras.end(); it++)
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
        muros.push_back(new barreras());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

