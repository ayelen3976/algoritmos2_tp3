#include "lista.h"
#include <string>
#include <iostream>

Lista::Lista() {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (esta_vacia())
        cursor = nuevo;
    if (pos == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
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
        reiniciar_cursor();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }

    if (cursor == borrar)
        siguiente();
    delete borrar;
    cantidad--;
}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool Lista::esta_vacia() {
    return (cantidad == 0);
}

int Lista::obtener_cantidad() {
    return cantidad;
}

bool Lista::hay_siguiente() {
    return (cursor != nullptr);
}

Dato Lista::siguiente() {
    Dato dato = cursor->obtener_dato();
    cursor = cursor->obtener_siguiente();
    return dato;
}

void Lista::reiniciar_cursor() {
    cursor = primero;
}

bool Lista::dato_encontrado(Dato d){
    Nodo* puntero = primero;
    bool encontrado = false;

    while ((puntero != nullptr) && (!encontrado)){
        if (puntero->obtener_dato() == d)
            encontrado = true;
        else
            puntero = puntero->obtener_siguiente();
    }

    return encontrado;
}

Lista* Lista::interseccion(Lista lista){
    Lista* nueva_lista = new Lista;
    Dato en_comun;
    Nodo* puntero = primero;
    while (puntero != nullptr){
        en_comun = puntero->obtener_dato();

        if (lista.dato_encontrado(en_comun))
            nueva_lista->alta( en_comun, nueva_lista->obtener_cantidad() + 1 );
        puntero = puntero->obtener_siguiente();
    }
    return nueva_lista;
}

Lista* Lista::union_sin_orden(Lista lista) {
    Lista* nueva_lista = new Lista;

    Nodo* puntero = primero;
    while (puntero != nullptr) {
        nueva_lista->alta(puntero->obtener_dato(), nueva_lista->obtener_cantidad() + 1);
        puntero = puntero->obtener_siguiente();
    }

    puntero = lista.primero;
    while (puntero != nullptr) {
        nueva_lista->alta(puntero->obtener_dato(), nueva_lista->obtener_cantidad() + 1);
        puntero = puntero->obtener_siguiente();
    }

    return nueva_lista;
}

Lista* Lista::union_conservando_orden(Lista lista) {
    Lista* nueva_lista = new Lista;
    Nodo* punteroA = primero;
    Nodo* punteroB = lista.primero;

    while (punteroA != nullptr && punteroB != nullptr) {
        if (punteroA->obtener_dato() < punteroB->obtener_dato()) {
            nueva_lista->alta(punteroA->obtener_dato(), nueva_lista->obtener_cantidad() + 1);
            punteroA = punteroA->obtener_siguiente();
        } else {
            nueva_lista->alta(punteroB->obtener_dato(), nueva_lista->obtener_cantidad() + 1);
            punteroB = punteroB->obtener_siguiente();
        }
    }

    while (punteroA != nullptr) {
        nueva_lista->alta(punteroA->obtener_dato(), nueva_lista->obtener_cantidad() + 1);
        punteroA = punteroA->obtener_siguiente();
    }

    while (punteroB != nullptr) {
        nueva_lista->alta(punteroB->obtener_dato(), nueva_lista->obtener_cantidad() + 1);
        punteroB = punteroB->obtener_siguiente();
    }

    return nueva_lista;
}

Lista::~Lista() {
    while (!esta_vacia())
        baja(1);
}