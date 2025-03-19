#include <iostream>
#include <memory>
using namespace std;

struct nodo{
    int valor;
    unique_ptr<nodo> next;
};

struct lista_enlazada{
    unique_ptr<nodo> head; //Unicamente un puntero al primer elemento.
    size_t size;
};

unique_ptr<nodo> create_node(int valor){
    return make_unique<nodo>(valor);

}

void push_front(lista_enlazada& lista, int valor){
    //El nodo pasa a ser el nuevo head y su next es el head actual.
    unique_ptr<nodo> nuevo_nodo = create_node(valor);
    nuevo_nodo.next = move(lista.head);
    lista.head = move(nuevo_nodo);
    lista.size++;
    return;
}