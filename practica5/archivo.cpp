#include "archivo.h"

Archivo::Archivo()
{
    this->datosCrudos="";
    this->fallaLectura=false;
    setList();
}

int Archivo::str2int(QString data) //Convierte un número en formato string al mismo número en formato int
{
    int size=data.size(), resultado=0, potencia;
    for(int i=0; i<size; i++){
        potencia=pot(10, size-i-1);
        QChar _char = data[i];
        resultado=resultado + ((_char.digitValue())*potencia);
    }
    return resultado;
}

int Archivo::pot(int base, int exponente) //Potenciacion
{
    int resultado = 1;
        for(int i = 0; i < exponente; i++) {
            resultado *= base;
        }
    return resultado;
}

void Archivo::getDatos() //Carga los datos del archivo de barreras en un arreglo de caracteres
{
    ifstream myFile;
    int leng;
    char* texto;

    myFile.open("Barreras.txt", ios_base::in | ios_base::ate);

    if(myFile.is_open()){
        fallaLectura=false;
        leng=myFile.tellg();
        texto=new char[leng];

        myFile.seekg(0);
        myFile.read(texto, leng);
        myFile.close();
    }
    else fallaLectura=true;

    for(int i=0; i<leng; i++){
        datosCrudos=datosCrudos + *(texto+i);
    }
}

void Archivo::setList() //Convierte los datos almacenados en una cadena de caracteres en una lista de datos individuales
{
    getDatos();

    QList<QString> auxList = datosCrudos.split('\n', Qt::SkipEmptyParts);
    QList<QString> auxStrList;
    int i=0;
    QList<QString>::iterator it1, it2;

    for(it1=auxList.begin(); it1<auxList.end(); it1++)
    {
        auxStrList = (*it1).split(',', Qt::SkipEmptyParts);
        it2=auxStrList.begin();
        QList<int> h;
        datos.push_back(h);
        datos[i].push_back(str2int(*it2));
        datos[i].push_back(str2int(*(it2+1)));
        datos[i].push_back(str2int(*(it2+2)));
        datos[i].push_back(str2int(*(it2+3)));
        i++;
    }
    datos[49][3]=8;
}
