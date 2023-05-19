#ifndef BARRERA_H
#define BARRERA_H
#include <QGraphicsItem>
#include <QPainter>
#include <fstream>
#include <vector>

using namespace std;

class barreras: public QGraphicsItem
{
    int txtLeng;
    char* all_db;
    bool errorArchivo=false;
    string dbName, strDb;
    vector<vector<string>> vector_barreras;

public:
    barreras();
    QRectF boundingRect(int _posx, int _posy, int _ancho, int _alto) const;
    vector<string> splitString(string info, char a);
    void cargar_archivo_barreras();
    void setVectorBarreras();
    void paint_barreras();
    int pot(int base, int exponente);
    int stringToInt(string str);
};

#endif // BARRERA_H
