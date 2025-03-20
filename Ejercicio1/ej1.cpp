
#include <iostream>
#include <vector>

using Matriz = std::vector<std::vector<int>>;

//Funcion que devuelve una matriz cuadrada, punto 1.a.
Matriz matriz_cuadrada(int n){
    Matriz matriz_cuad(n, std::vector<int>(n));
    int valor = 1; //Contador para valores consecutivos en la matriz.

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz_cuad[i][j] = valor;
            valor ++;
        }
    }
    return matriz_cuad;

}

//Funcion para imprimir una matriz cuadrada, punto 1.b.
void imprimir(Matriz matriz, int n){
    int indice_columna = n -1;
    int indice_fila = n-1;

    for(int i = 0; i<n*n; i++){ // El loop lo uso solo para permutaciones, la variable i no se usa. 
        std::cout << "M["<< indice_fila<< "][" << indice_columna<< "] = " << matriz[indice_fila][indice_columna]<< std::endl;
        indice_columna--; // Se recorre la matriz de izquierda a derecha, desde la ultima fila.
        if(indice_columna == -1){ 
            indice_fila--; // Cuando se recorren todas las columnas de una fila, se pasa a la fila de arriba.
            indice_columna = n-1; //Se reestablece indice_columna a la ultima columna.
        }
    }
}

int main(){
    int n = 3; 
    Matriz matriz = matriz_cuadrada(n);
    imprimir(matriz, n);
    return 0;
}