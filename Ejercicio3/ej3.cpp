#include <iostream>
#include <memory>
using namespace std;

struct Nodo {
    int valor;
    unique_ptr<Nodo> next;

};

struct lista_enlazada{
    unique_ptr<Nodo> head; //Unicamente un puntero al primer elemento.
    int size = 0;
};

unique_ptr<Nodo> create_node(int valor){
    unique_ptr<Nodo> nodo = make_unique<Nodo>();
    nodo->valor = valor;
    nodo->next = nullptr;
    return nodo;
}

void push_front(lista_enlazada& lista, int valor){ //Pasar lista por referencia

    //El nodo pasa a ser el nuevo head y su next es el head actual.
    unique_ptr<Nodo> nuevo_nodo = create_node(valor);
    nuevo_nodo->next = move(lista.head);
    lista.head = move(nuevo_nodo);
    lista.size++;
    return;
}


void push_back(lista_enlazada& lista, int valor){

    unique_ptr<Nodo> nuevo_nodo = create_node(valor);
    Nodo* actual = lista.head.get();

    //Recorro toda la lista hasta llegar al ultimo nodo, que es el unico que tiene su puntero a next como nullptr.
    while(actual){
        if(actual->next.get() == nullptr){
            actual->next = move(nuevo_nodo);
            break;
        }
        actual = actual->next.get();
    }
    lista.size++;
}

void insert(lista_enlazada& lista, int indice, int valor){
    //Los indices de la lista se consideran de {0, ... n-1}
    if(!lista.head){
        cout<< "La lista esta vacia.\n";
        return;
    }
    else if(indice == 0){
        push_front(lista, valor);
        return;
    }
    else if(indice == lista.size -1){
        push_back(lista, valor);
        return;
    }
    else if(indice >= lista.size){
        cout<< "El indice ingresado excede los indices del tamaño de la lista. El nodo fue agregado al final de la lista. \n";
        push_back(lista, valor);
        return;
    }
    else{
        
        int contador = 0;
        Nodo* actual = lista.head.get();

        //Recorrer la lista hasta llegar al indice anterior al indicado
        while(true){
            if(contador == indice -1){
                unique_ptr<Nodo> nuevo_nodo = create_node(valor);
                nuevo_nodo->next = move(actual->next);
                actual->next = move(nuevo_nodo);
                lista.size++;
                return;
            }
            actual = actual->next.get();
            contador++;
        }

    }

}

void erase(lista_enlazada& lista, int indice){
    
    if(!lista.head){
        cout<< "La lista esta vacia.\n";
        return;
    }
    else if(indice >= lista.size){
        //Uso un contador para avanzar en la lista hasta el ultimo elemento.
    
        cout << "El indice ingresado excede los elementos de la lista. Se borró el ultimo elemento.\n";
        int contador = 0;
        Nodo* actual = lista.head.get();
        while(contador< lista.size-1){
            actual= actual->next.get();
            contador++;
        }
        actual->next = nullptr;
        lista.size--;
        return;
    }
    else{
        //Recorro la lista hasta el indice anterior al que quiero eliminar

        int contador = 0;
        Nodo* actual = lista.head.get();
        while(contador != indice - 1){
            actual = actual->next.get();
            contador++;
        }
        actual->next = move(actual->next->next);
        lista.size--;
        return;
    }

}


void print_list(lista_enlazada& lista) {
    Nodo* nodo_actual = lista.head.get();
    while (nodo_actual) { //Mientras hayan nodos, imprimir
        cout << nodo_actual->valor << " ";
        if(nodo_actual->next != nullptr){ 
            cout << "-> ";
        }
        nodo_actual = nodo_actual->next.get();
    }
    cout <<"\n";

}

int main(){
    lista_enlazada lista;

    push_front(lista, 5);

    push_back(lista, 10);

    push_front(lista, 7);

    push_front(lista, 9);

    insert(lista, 1, 17);

    insert(lista, 15, 2);

    erase(lista, 14);

    print_list(lista);
}