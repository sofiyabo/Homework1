
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

vector<string> etiquetas = {"[DEBUG]", "[INFO]", "[WARNING]", "[ERROR]", "[CRITICAL]"};




//Funcion de log del punto 2.a
void logMessage(string mensaje, int nivel){
    if(nivel<0 || nivel>4){
        cout<< "El nivel de severidad ingresado no es correcto\n";
        return;
    }

    ofstream archivo("registro.txt", ios::app);
    if(archivo.is_open()){
        archivo<< etiquetas[nivel] << " <" << mensaje << ">\n";
        archivo.close();
    }
    else{
        cerr<< "Error abriendo archivo\n";
    }
}

//Funcion de log de errores en archivos.
void logMessage(string mensaje_error, string archivo_input, int linea){
    
    ofstream archivo("registro.txt", ios::app);
    if(archivo.is_open()){
        archivo<< etiquetas[3]<< mensaje_error << " Archivo:" << archivo_input << ", Linea:" << linea << "\n";
        archivo.close();
    }
    else{
        cerr<< "Error abriendo archivo\n";
    }
}

//Funcion de log de accesos.
void logMessage(string mensaje_acceso, string usuario){
    ofstream archivo("registro.txt", ios::app);
    if(archivo.is_open()){
        archivo<< "[SECURITY]" << mensaje_acceso << " " << usuario<< "\n";
        archivo.close();
    }
    else{
        cerr<< "Error abriendo archivo\n";
    }

}

int main(){ 
    try{
        logMessage("Error en el software", 0);
        logMessage("Sistema iniciado correctamente", 1);
        logMessage("Fuga de memoria", 2);
        logMessage("No se pudo acceder", 3);
        logMessage("Alerta critica", 4);
        logMessage("Access Granted", "Sofia Yabo");

        throw runtime_error("Error de sistema");
    } catch (const runtime_error& e){
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
    
    return 0;
}