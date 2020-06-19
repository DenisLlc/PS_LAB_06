#include <stdio.h>
#include <iostream>
#include <string>
#include "universidad.h"

using namespace std;

universidad uni;

int main()
{
    int opc;

    do{
    // system("cls");

    cout<<"\n\tManejo de archivos en c++\n\n";
    cout<<"\n\t1.-Altas";
    cout<<"\n\t2.-Bajas";
    cout<<"\n\t3.-Consultas";
    cout<<"\n\t4.-Buscar un registro";
    cout<<"\n\t5.-Modificaciones";
    cout<<"\n\t6.-Salir";
    cout<<"\n\n\tElige una opcion:  ";
    cin>>opc;
    switch (opc)
    {
        case 1:{
            system("clear");
            uni.altas();
            cout<<"\n\t\t";
            break;
        }
        case 2:{
            system("clear");
            uni.bajas();
            cout<<"\n\t\t";
            break;
        }

        case 3:{
            system("clear");
            uni.consultas();
            cout<<"\n\t\t";
            break;
        }
        case 4:{
            system("clear");
            uni.buscar();
            cout<<"\n\t\t";
            break;
        }
        case 5:{
            system("clear");
            uni.modificar();
            cout<<"\n\t\t";
            break;
        }
        case 6:{
            cout<<"\n\n\tHa elegido salir...\n\n\t\t";
            break;
        }
        default:{
            cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t";
            break;
        }
    }//fin switch

    }while (opc!=6);

    return 0;
}

