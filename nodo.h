#ifndef FERNANDEZ_109378_NODO_H
#define FERNANDEZ_109378_NODO_H
typedef int Dato;
class Nodo {
private:

    // ATRIBUTOS
    Dato dato;
    Nodo* siguiente;

public:

    // CONSTRUCTORES

    // pos: construye un Nodo con un dato d y siguiente en nullptr.
    Nodo(Dato d);
    // pos: construye un Nodo con un dato d y siguiente en pn
    Nodo(Dato d, Nodo* pn);

    // METODOS
    Dato obtener_dato();

    Nodo* obtener_siguiente();

    void cambiar_dato(Dato d);

    void cambiar_siguiente(Nodo* pn);
};


#endif //FERNANDEZ_109378_NODO_H
