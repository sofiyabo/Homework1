/* a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva una matriz cuadrada con valores como 
en los siguientes ejemplos para n=2 y n=3:*/

//container std::array
#include <iostream>
#include <vector>

using Matriz = std::vector<std::vector<int>>;

Matriz matriz_cuadrada(int n){
    Matriz matriz_cuad(n, std::vector<int>(n));
    int valor = 1;

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz_cuad[i][j] = valor;
            valor ++;
        }
    }
    return matriz_cuad;

}



int main(){
    Matriz matriz = matriz_cuadrada(4);
    return 0;
}