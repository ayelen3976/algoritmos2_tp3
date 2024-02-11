#ifndef FERNANDEZ_109378_NODO_H
#define FERNANDEZ_109378_NODO_H
typedef char Dato;

class Nodo {
    // atributos
private:
    Dato dato;
    Nodo* siguiente;

    // metodos
public:
    // constructor
    // pos: construye un Nodo con dato = d y siguiente en NULL
    Nodo(Dato d);

    Dato obtener_dato();

    Nodo* obtener_siguiente();

    void cambiar_dato(Dato d);

    void cambiar_siguiente(Nodo* pn);
};

#endif //FERNANDEZ_109378_NODO_H
