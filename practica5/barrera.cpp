#include "barrera.h"

barreras::barreras()
{
    this->dbName="Barreras.txt";
    this->strDb="";
}

QRectF barreras::boundingRect(int _posx, int _posy, int _ancho, int _alto) const
{
    return QRect(_posx, _posy, _ancho, _alto);
}

vector<string> barreras::splitString(string info, char a)
{
    int pos = 0, char_pos;
    vector<string> aux;

    char_pos = info.find(a,pos);

    while (char_pos != -1) {
        aux.push_back(info.substr(pos,char_pos-pos));
        pos = char_pos +1;
        char_pos = info.find(a,pos);
    }
    aux.push_back(info.substr(pos,info.size()-pos));

    return  aux;

}

void barreras::cargar_archivo_barreras()
{
    ifstream db(dbName);
    if(db.fail())
    {
        this->errorArchivo=true;
    }
    else{
        db.open(dbName, ios_base::in | ios_base::ate);
        txtLeng = db.tellg();
        db.seekg(0);
        all_db=new char[txtLeng];
        db.read(all_db, txtLeng);
        db.close();
    }
    for(int i=0; i<txtLeng; i++)
    {
        strDb=strDb+all_db[i];
    }
}

void barreras::setVectorBarreras()
{
    vector<string> aux=splitString(strDb, '\n');
    vector<string>::iterator it;
    int it2=0;

    for(it=aux.begin(); it!=aux.end(); it++)
    {
        vector_barreras[it2]=splitString(*it, ',');
        it2+=1;
    }
}

void barreras::paint_barreras()
{
    QRectF rectangulo;
    QPainter *painter;
    painter->setBrush(Qt::green);

    vector<vector<string>>::iterator it;
    int _x, _y, _ancho, _alto;
    for(it=vector_barreras.begin(); it!=vector_barreras.end(); it++)
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
    }
}

int barreras::pot(int base, int exponente)
{
    int resultado = 1;
    for(int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

int barreras::stringToInt(string str)
{
    int size=str.size(), resultado=0, potencia;
    for(int i=0; i<size; i++)
    {
        potencia=pot(10,size-1-i);
        resultado=resultado+((int (str[i])-48)*potencia);
    }
    return resultado;
}
