#include "archivo.h"
#include <fstream>
using namespace std;

Archivo::Archivo()
{
    this->datosCrudos="";
    setList();
}

int Archivo::str2int(QString data)
{
    int size=data.size(), resultado=0, potencia;
    for(int i=0; i<size; i++){
        potencia=pot(10, size-i-1);
        QChar _char = data[i];
        resultado=resultado + ((_char.digitValue())*potencia);
    }
    return resultado;
}

int Archivo::pot(int base, int exponente)
{
    int resultado = 1;
        for(int i = 0; i < exponente; i++) {
            resultado *= base;
        }
    return resultado;
}

void Archivo::getDatos()
{
    ifstream myFile;
    int leng;
    char* texto;

    if(myFile.fail()){
    }
    else{
        myFile.open("Barreras.txt", ios_base::in | ios_base::ate);
        leng=myFile.tellg();
        texto=new char[leng];

        myFile.seekg(0);
        myFile.read(texto, leng);
        myFile.close();
    }
    for(int i=0; i<leng; i++){
        datosCrudos=datosCrudos + *(texto+i);
    }
}

void Archivo::setList()
{
    QList<QString> auxList = datosCrudos.split('\n', Qt::SkipEmptyParts);
    QList<QString> auxStrList;
    int i=0;
    QList<QString>::iterator it;

    for(it=auxList.begin(); it<auxList.end(); it++)
    {
        auxStrList = (*it).split(',', Qt::SkipEmptyParts);
        datos[i][0]=str2int(auxStrList[0]);
        datos[i][1]=str2int(auxStrList[1]);
        datos[i][2]=str2int(auxStrList[2]);
        datos[i][3]=str2int(auxStrList[3]);
    }
}
