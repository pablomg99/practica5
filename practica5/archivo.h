#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <QList>

class Archivo
{
    QString datosCrudos;

public:
    Archivo();
    QList<QList<int>> datos;
    bool fallaLectura;
    int str2int(QString data);
    int pot(int base, int exponente);
    void getDatos();
    void setList();
};

#endif // ARCHIVO_H
