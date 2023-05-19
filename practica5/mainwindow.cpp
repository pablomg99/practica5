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

    DataBase=archivo("Barreras.txt");

    vector<vector<string>>::iterator it;
    int x=0, y=0, w=0, h=0;
    string aux;
    for(it=DataBase.vector_barreras.begin(); it!=DataBase.vector_barreras.end(); it++){
        aux = *it;
        this->x = DataBase.stringToInt(aux[0]);
        this->y = DataBase.stringToInt(aux[1]);
        this->w = DataBase.stringToInt(aux[2]);
        this->h = DataBase.stringToInt(aux[3]);

        Paredes.push_back(new pared(x,y,w,h));
        scene->addItem(Paredes.back());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

