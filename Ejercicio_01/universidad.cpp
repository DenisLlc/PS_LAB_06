#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "universidad.h"

using namespace std;

string nombre, auxnombre, semestre, edad;
int clave=0, auxclave=0;
char opca;
bool encontrado = false;

void universidad::altas(){
    ///Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ifstream consulta;

    do{
    escritura.open("alumnos.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
    consulta.open("alumnos.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico alumnos.txt

    if (escritura.is_open() && consulta.is_open()){


            bool repetido=false;

            cout<<"\n";
            cout<<"\tIngresa la clave del alumno:    ";
            cin>>auxclave;
            
            ///A continuación se aplica el tipo de lectura de archivos secuencial
            consulta>>clave;
            while (!consulta.eof()){
                consulta>>nombre>>semestre>>grupo>>edad;
                if (auxclave==clave){
                    cout<<"\t\tYa existe la clave del alumno...\n";
                    repetido=true;
                    break;
                }
                consulta>>clave;
            }

            if (repetido==false){
                cout<<"\tIngresa el nombre del alumno:   ";
                cin>>nombre;
                cout<<"\tIngresa el semestre del alumno: ";
                cin>>semestre;
                cout<<"\tIngresa el grupo del alumno:    ";
                cin>>grupo;
                cout<<"\tIngresa la edad del alumno:     ";
                cin>>edad;
                //ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
                escritura<<auxclave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                cout<<"\n\tRegistro agregado...\n";
            }

            cout<<"\n\tDeseas ingresar otro alumno? (S/N): ";
            cin>>opca;

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    escritura.close();
    consulta.close();

    }while (opca=='S' or opca=='s');
}

void universidad::bajas(){
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas eliminar: ";
        cin>>auxclave;
            
            ///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
            ///hasta llegar al final del archivo gracias a la función .eof()
            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>semestre>>grupo>>edad;
                if (auxclave==clave){
                        encontrado=true;
                        cout<<"\n";
                        cout<<"\tClave:    "<<clave<<endl;
                        cout<<"\tNombre:   "<<nombre<<endl;
                        cout<<"\tSemestre: "<<semestre<<endl;
                        cout<<"\tGrupo:    "<<grupo<<endl;
                        cout<<"\tEdad:     "<<edad<<endl;
                        cout<<"\t________________________________\n\n";
                        cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                        cin>>opca;

                        if (opca=='S' or opca=='s'){
                            cout<<"\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
                        }else{
                            aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                        }

                    }else{
                        aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}

void universidad::consultas(){
    //Lectura de archivos

    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>clave;
       while (!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tSemestre: "<<semestre<<endl;
            cout<<"\tGrupo:    "<<grupo<<endl;
            cout<<"\tEdad:     "<<edad<<endl;
            lectura>>clave;
            cout<<"\t________________________________\n";
       }

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
}

void universidad::buscar(){
    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);

    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tIngresa la clave del alumno que deseas buscar: ";
        cin>>auxclave;

        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
        //comparar cada registro para ver si es encontrado

        if(auxclave==clave){
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tSemestre: "<<semestre<<endl;
            cout<<"\tGrupo:    "<<grupo<<endl;
            cout<<"\tEdad:     "<<edad<<endl;
            cout<<"\t________________________________\n";
            encontrado=true;
            break;
        }//fin del if mostrar encontrado

        //lectura adelantada
        lectura>>clave;
        }//fin del while
        if (encontrado==false){
            cout<<"\n\n\tNo hay registros con la clave: "<<auxclave<<"\n\n\t\t\t";
        }
    }else{
        cout<<"\n\tAun no se pudo abrir el archivo...";
    }

    lectura.close();
}

void universidad::modificar(){
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas modificar: ";
        cin>>auxclave;

            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>semestre>>grupo>>edad;
                if (auxclave==clave){
                    encontrado=true;
                    cout<<"\n";
                    cout<<"\tClave:    "<<clave<<endl;
                    cout<<"\tNombre:   "<<nombre<<endl;
                    cout<<"\tSemestre: "<<semestre<<endl;
                    cout<<"\tGrupo:    "<<grupo<<endl;
                    cout<<"\tEdad:     "<<edad<<endl;
                    cout<<"\t________________________________\n\n";
                    cout<<"\tIngresa el nuevo nombre del alumno con la clave: "<<auxclave<<"\n\n\t---> ";
                    cin>>auxnombre;

                    aux<<clave<<" "<<auxnombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                    cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
                    }else{
                    aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}