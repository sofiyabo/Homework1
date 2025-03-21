#include <iostream>
#include <chrono>

using namespace std;
// funcion recursiva de ejecucion en tiempo de compilacion
// comparar dos cadenas de texto: char* o string? uso const char* porque string usa memoria dinamica y no puede usarse para ejecucion en tiempo de compilacion
// PREGUNTAR SI SE NECESITA OTRA FUNCION O COMO HACER LA COMPARACION


bool textos_iguales(const char* texto1, const char* texto2){
    //Fin de la cadena: cuando el llamado recursivo llega al final, tiene que cortar. 
    if(*texto1 == '\0' && *texto2 == '\0') return true;
    //Caso base: comparacion caracter a caracter
    if(*texto1 != *texto2) return false;

    //Llamado recursivo
    return textos_iguales(texto1 + 1, texto2 +1); //El +1 agarra el proximo caracter
}

constexpr bool textos_iguales_comp(const char* texto1, const char* texto2){
    if(*texto1 == '\0' && *texto2 == '\0') return true;
    if(*texto1 != *texto2) return false;
    return textos_iguales_comp(texto1 + 1, texto2 +1);
}

int main(){
    
    auto startTime = chrono::high_resolution_clock::now();
    textos_iguales("porque yo no quiero trabajar, no quiero ir a estudiar, no me quiero casar. Quiero tocar la guitarra todo el dia, y que la gente se enamore de mi voz.", "porque yo no quiero trabajar, no quiero ir a estudiar, no me quiero casar. Quiero tocar la guitarra todo el dia, y que la gente se enamore de mi voz.");
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>( endTime - startTime);
    cout << "A miProcesoAMedir le tomó:" << elapsedTime.count() << "nanosegundos" << endl;
    

    auto startTime1 = chrono::high_resolution_clock::now();
    textos_iguales_comp("porque yo no quiero trabajar, no quiero ir a estudiar, no me quiero casar. Quiero tocar la guitarra todo el dia, y que la gente se enamore de mi voz.", "porque yo no quiero trabajar, no quiero ir a estudiar, no me quiero casar. Quiero tocar la guitarra todo el dia, y que la gente se enamore de mi voz.");
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>( endTime1 - startTime1);
    cout << "A miProcesoAMedir le tomó:" << elapsedTime1.count() << "nanosegundos" << endl;
    
}

//La diferencia 