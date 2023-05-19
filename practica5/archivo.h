#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <QList>

class Archivo
{
    QString datosCrudos;

public:
    QList<QList<int>> datos;
    Archivo();
    int str2int(QString data);
    int pot(int base, int exponente);
    void getDatos();
    void setList();
};

#endif // ARCHIVO_H
