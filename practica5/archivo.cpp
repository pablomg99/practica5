#include "archivo.h"

archivo::archivo()
{
}

archivo::archivo(string _txtName)
{
    this->dbName=_txtName;
    this->strDb="";

    cargar_archivo_barreras();
    setVectorBarreras();
}

vector<string> archivo::splitString(string info, char a)
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

void archivo::cargar_archivo_barreras()
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

void archivo::setVectorBarreras()
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

int archivo::pot(int base, int exponente)
{
    int resultado = 1;
    for(int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

int archivo::stringToInt(string str)
{
    int size=str.size(), resultado=0, potencia;
    for(int i=0; i<size; i++)
    {
        potencia=pot(10,size-1-i);
        resultado=resultado+((int (str[i])-48)*potencia);
    }
    return resultado;
}
