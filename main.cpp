#include <iostream>
#include <string.h>
//Moisés Eduardo Mora López 2°P
//22110131 - Programación Orientado a objetos.


using namespace std;

class date
{
    private:
        int dia, mes, anio, bisiesto, fecha_valida = 0;
        string fecha;

    public:
        date(string);
        int valida();

};

date::date(string pfecha){fecha = pfecha;}

int date::valida()
{
    fecha_valida = 0;

    if(fecha.length() != 8)
    {
        cout<<"longitud de fecha erronea!!!\n";
        return fecha_valida;
    };

    anio = stoi(fecha.substr(0,4));
    mes = stoi(fecha.substr(4,2));
    dia = stoi(fecha.substr(6,2));

    bisiesto = 0;

    if(anio %400 == 0 || (anio %4 == 0 && anio %100 != 0))
    {
        cout<<endl<<anio<<"anio Bisiesto"<<endl;
        bisiesto = 1;
    };

    if(mes < 1 || mes > 12)
    {
        cout<<"Mes Erroneo!!! debe ser del 01 al 12\n";
        return fecha_valida;
    };

    int mdias = 31;

    if(mes = 2)
    {
        mdias = 28;

        if(bisiesto == 1)
        {
            mdias = 29;
        };
    }

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){mdias = 30;};

    if(dia < 1 || dia > mdias)
    {
        cout<<"dias Erroneo!!! debe ser del 01 al "<<mdias<<"\n";
        return fecha_valida;
    };

    fecha_valida = 1;

    cout<<"fecha correcta \n"<<fecha.length()<<" anio:"<<anio<<" mes:"<<mes<<" dia:"<<dia<<endl;
    return fecha_valida;
}


int main()
{

    date *ofecha;
    string cadena;

    cout << "introduce una fecha" << endl;
    cin>>cadena;

    ofecha = new date(cadena);
    ofecha->valida();

    return 0;
}
