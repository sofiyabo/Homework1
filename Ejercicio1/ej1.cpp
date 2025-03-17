
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
    int n = 3; 
    Matriz matriz = matriz_cuadrada(n);
    imprimir(matriz, n);
    return 0;
}