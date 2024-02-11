#include "nodo.h"

Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = nullptr;
}

Dato Nodo::obtener_dato() {
    return dato;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

void Nodo::cambiar_dato(Dato d) {
    dato = d;
}

void Nodo::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}
