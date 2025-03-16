/*
En este ejercicio, se pide crear un sistema log que permite agregar entradas a un archivo mediante el llamado a una función logMessage definida en pseudo código de la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente mencionadas.

*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> etiquetas = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

void logMessage(string mensaje, int nivel){
    if(nivel<0 || nivel>= etiquetas.size()){
        cout<< "El nivel de severidad ingresado no es correcto\n";
        return;
    }

    ofstream archivo("registro.txt", ios::app);
    if(archivo.is_open()){
        archivo<< "[" << etiquetas[nivel] << "] <" << mensaje << ">\n";
        archivo.close();
    }
    else{
        cerr<< "Error abriendo archivo\n";
    }
}

int main(){
    logMessage("faltan datos", 1);
}