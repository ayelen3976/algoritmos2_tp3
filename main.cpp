#include <iostream>
#include "lista.h"
int main() {
    Lista listaA, listaB;

    // Agregar elementos a la lista A
    listaA.alta(1, 1);
    listaA.alta(3, 2);
    listaA.alta(7, 3);

    // Agregar elementos a la lista B
    listaB.alta(2, 1);
    listaB.alta(4, 2);
    listaB.alta(3, 3);

    // Calcular la unión conservando el orden entre las listas A y B
    Lista* unionConOrden = listaA.union_conservando_orden(listaB);

    // Imprimir la unión conservando el orden
    std::cout << "Unión conservando el orden entre lista A y lista B: ";
    while (unionConOrden->hay_siguiente()) {
        std::cout << unionConOrden->siguiente() << " ";
    }
    std::cout << std::endl;

    // Liberar la memoria de la lista unión conservando el orden
    delete unionConOrden;

    // Calcular la intersección entre las listas A y B
    Lista* interseccionAB = listaA.interseccion(listaB);

    // Imprimir la intersección
    std::cout << "Intersección entre lista A y lista B: ";
    while (interseccionAB->hay_siguiente()) {
        std::cout << interseccionAB->siguiente() << " ";
    }
    std::cout << std::endl;

    // Liberar la memoria de la lista intersección
    delete interseccionAB;

    return 0;
}

