#include "lista.h"

Lista::Lista() {
    cantidad = 0;
    primero = 0;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

int Lista::obtener_cantidad() {
    return cantidad;
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);

    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista::baja(int pos) {
    Nodo* borrar = primero;

    if (pos == 1) {
        primero = borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar =  anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    cantidad--;
    delete borrar;
}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

Lista::~Lista() {
    while (! vacia()) {
        baja(1);
    }
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    for (int i = 1; i < pos; i++) {
        aux = aux->obtener_siguiente();
    }
    return aux;
}