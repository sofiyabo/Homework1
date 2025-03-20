#include <iostream>
#include <chrono>

using namespace std;
// funcion recursiva de ejecucion en tiempo de compilacion
// comparar dos cadenas de texto: char* o string? uso const char* porque string usa memoria dinamica y no puede usarse para ejecucion en tiempo de compilacion
// las constantes si se "procesan" en tiempo de compilacion?


bool textos_iguales(const char* texto1, const char* texto2){
    //Fin de la cadena: cuando el llamado recursivo llega al final, tiene que cortar. 
    if(*texto1 == '\0' && *texto2 == '\0') return true;
    //Caso base: comparacion caracter a caracter
    if(*texto1 != *texto2) return false;

    //Llamado recursivo
    return textos_iguales(texto1 + 1, texto2 +1); //El +1 agarra el proximo caracter
}

int main(){
    
    auto startTime = chrono::high_resolution_clock::now();
    textos_iguales("porque yo no quiero trabajar, no quiero ir a estudiar", "porque yo no quiero trabajar, no quiero ir a estudiar");
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>( endTime - startTime);
    cout << "A miProcesoAMedir le tomó:" << elapsedTime.count() << "nanosegundos" << endl;
    

}
