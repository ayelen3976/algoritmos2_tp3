#include <iostream>
#include "lista.h"
int main() {
    Lista lista;

    // Agregando elementos a la lista
    lista.alta('F', 1);  // Agrega el elemento 'F' en la posición 1
    lista.alta('I', 2);  // Agrega el elemento 'I' en la posición 2
    lista.alta('U', 3); // Agrega el elemento 30 en la posición 3

    // Consultando un elemento en la lista
    char elemento_consultado = lista.consulta(2);  // Consulta el elemento en la posición 2
    std::cout << "Elemento en la posicion 2: " << elemento_consultado << std::endl;

    // Eliminando un elemento de la lista
    lista.baja(1);  // Elimina el elemento en la posición 1

    // Consultando la cantidad de elementos en la lista
    int cantidad_elementos = lista.obtener_cantidad();
    std::cout << "Cantidad de elementos en la lista: " << cantidad_elementos << std::endl;

    return 0;
}
