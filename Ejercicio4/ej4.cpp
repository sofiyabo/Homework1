#include <iostream>
#include <chrono>

using namespace std;
// Para comparar dos cadenas de texto: uso const char* porque string usa memoria dinamica y no puede usarse para ejecucion en tiempo de compilacion.
//const char* si permite realizar las operaciones en tiempo de compilacion.


bool textos_iguales(const char* texto1, const char* texto2){
    //Fin de la cadena: cuando el llamado recursivo llega al final, tiene que cortar. 
    if(*texto1 == '\0' && *texto2 == '\0') return true;
    //Caso base: comparacion caracter a caracter
    if(*texto1 != *texto2) return false;

    //Llamado recursivo
    return textos_iguales(texto1 + 1, texto2 +1); //El +1 agarra el proximo caracter
}

constexpr bool textos_iguales_comp(const char* texto1, const char* texto2){
    //Mismo codigo que textos_iguales()
    
    if(*texto1 == '\0' && *texto2 == '\0') return true;
    
    if(*texto1 != *texto2) return false;

    return textos_iguales_comp(texto1 + 1, texto2 +1);
}

int main(){
    
    //Tiempo de primera funcion: usando textos_iguales()
    auto startTime = chrono::high_resolution_clock::now();
    bool iguales = textos_iguales("Homework 1 I102 Paradigmas de Programación Fecha límite de entrega: Jueves 21", "Homework 1 I102 Paradigmas de Programación Fecha límite de entrega: Jueves 21");
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>( endTime - startTime);
    cout << "En tiempo de ejecucion tomó:" << elapsedTime.count() << "nanosegundos" << endl;
    if(iguales){
        cout<< "Los textos son iguales.\n";
    }
    else{
        cout << "Los textos no son iguales";
    }

    //Tiempo de segunda funcion: usando textos_iguales_comp() que lo hace en tiempo de compilacion
    auto startTime1 = chrono::high_resolution_clock::now();
    bool iguales_compilacion = textos_iguales_comp("Homework 1 I102 Paradigmas de Programación Fecha límite de entrega: Jueves 21", "Homework 1 I102 Paradigmas de Programación Fecha límite de entrega: Jueves 21");
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>( endTime1 - startTime1);
    cout << "En tiempo de compilacion tomó:" << elapsedTime1.count() << "nanosegundos" << endl;
    
    if(iguales_compilacion){
        cout<< "Los textos son iguales.\n";
    }
    else{
        cout << "Los textos no son iguales";
    }
}

/*La diferencia entre las dos funciones es que el uso del calificador constexpr
hace que el compilador pueda realizar las operaciones en tiempo de compilacion si los parametros 
que se pasan son cadenas de textos fijas y no variables.
*/