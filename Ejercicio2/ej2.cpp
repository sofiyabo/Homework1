/*
En este ejercicio, se pide crear un sistema log que permite agregar entradas a un archivo mediante el llamado a una función logMessage definida en pseudo código de la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente mencionadas.

*/
#include <iostream>
#include <fstream>
using namespace std;


void logMessage(string mensaje, string nivel){
    ofstream archivo("registro.txt", ios::app);
    if(archivo.is_open()){
        archivo<< "[" << nivel << "] <" << mensaje << ">\n";
        archivo.close();
    }
    else{
        cerr<< "Error abriendo archivo\n";
    }
}

int main(){
    logMessage("faltan datos", "INFO");
}