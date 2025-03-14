/* a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva una matriz cuadrada con valores como 
en los siguientes ejemplos para n=2 y n=3:*/

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

void imprimir(Matriz matriz, int n){
    int indice_columna = n -1;
    int indice_fila = n-1;
    //cada vez que i + 1 es multiplo de n tengo que subir fila (indice_fila -1)
    //y el indice columna vuelve a ser n-1
    for(int i = 0; i<n*n; i++){
        std::cout << "M["<< indice_fila<< "][" << indice_columna<< "] = " << matriz[indice_fila][indice_columna]<< std::endl;
        indice_columna--;
        if(indice_columna == -1){
            indice_fila--;
            indice_columna = n-1;
        }
    }
}

int main(){
    int n = 3; //ver si decide el usuario o entregar fijo
    Matriz matriz = matriz_cuadrada(n);
    imprimir(matriz, n);
    return 0;
}