#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <QGraphicsItem>
#include <QPainter>
#include <fstream>
#include <vector>
using namespace std;

class archivo
{
    int txtLeng;
    char* all_db;
    bool errorArchivo=false;
    string dbName, strDb;
public:
    archivo();
    archivo(string _txtName);
    vector<string> splitString(string info, char a);
    void cargar_archivo_barreras();
    void setVectorBarreras();
    int pot(int base, int exponente);
    int stringToInt(string str);
    vector<vector<string>> vector_barreras;
};

#endif // ARCHIVO_H
