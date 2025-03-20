#include <iostream>
#include <memory>
using namespace std;

struct Nodo {
    int valor;
    unique_ptr<Nodo> next;

};

struct lista_enlazada{
    unique_ptr<Nodo> head; //Unicamente un puntero al primer elemento.
    size_t size = 0;
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

    while(actual){
        if(actual->next.get() == nullptr){
            actual->next = move(nuevo_nodo);
            break;
        }
        actual = actual->next.get();
    }
}

void print_lista(lista_enlazada& lista) {
    Nodo* nodo_actual = lista.head.get();
    while (nodo_actual) {
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
    push_front(lista, 7);
    push_back(lista, 10);
    print_lista(lista);
}