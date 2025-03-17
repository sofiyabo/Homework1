#include <iostream>
#include <memory>
using namespace std;

struct nodo{
    int valor;
    unique_ptr<nodo> next;
};

struct lista_enlazada{
    unique_ptr<nodo> head;
    size_t size;
};

