#ifndef FERNANDEZ_109378_LISTA_H
#define FERNANDEZ_109378_LISTA_H

#include "nodo.h"

class Lista {
// atributos
private:
    Nodo* primero;
    int cantidad;

// Metodos
public:
    // constructor
    // pre: -
    // pos: construye una Lista vacia
    Lista();

    // pre: 0 < pos <= obtener_cantidad() + 1
    // pos: agrega d a la Lista en la posicion pos
    void alta(Dato d, int pos);


    // pre: 0 < pos <= obtener_cantidad()
    // pos: saca de la Lista el elemento que esta en la posicion pos
    void baja(int pos);

    // pre: -
    // pos: devuelve true si la Lista esta vacia, false si no
    bool vacia();

    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento que esta en la posicion pos
    Dato consulta(int pos);

    // POS: devuelve la cantidad de elementos de la Lista
    int obtener_cantidad();

    // Destructor
    ~Lista();

private:
    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve un puntero al Nodo que esta en la posicion pos
    Nodo* obtener_nodo(int pos);
};


#endif //FERNANDEZ_109378_LISTA_H
