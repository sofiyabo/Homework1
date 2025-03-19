#include <iostream>
#include <chrono>

using namespace std;
// funcion recursiva de ejecucion en tiempo de compilacion
// comparar dos cadenas de texto: char* o string? uso const char* porque string usa memoria dinamica y no puede usarse para ejecucion en tiempo de compilacion
// las constantes si se "procesan" en tiempo de compilacion?


bool textos_iguales(const char* texto1, const char* texto2){
    //Fin de la cadena:
    if(*texto1 == '\0' && *texto2 == '\0') return true;
    //Caso base: comparacion caracter a caracter
    if(*texto1 != *texto2) return false;

    //Llamado recursivo
    return textos_iguales(texto1 + 1, texto2 +1);
}

int main(){
    
    auto startTime = chrono::high_resolution_clock::now();
    textos_iguales("hola", "hola");
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
    cout << "A miProcesoAMedir le tomó:" << elapsedTime.count() << "nanosegundos" << endl;
    

}
/*

auto startTime = chrono::high_resolution_clock::now();
textos_iguales('hola', 'Hola');
auto endTime = chrono::high_resolution_clock::now();
auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
cout << "A miProcesoAMedir le tomó:" << elapsedTime.count() << "nanosegundos" << endl;

*/