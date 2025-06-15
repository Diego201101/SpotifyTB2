#pragma once
#pragma once
#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

#include "Cancion.h"
#include <functional>
using namespace std;

class ListaReproduccionCircular {
private:
    struct Nodo {
        Cancion cancion;
        Nodo* anterior;
        Nodo* siguiente;
        Nodo(Cancion c) : cancion(c), anterior(nullptr), siguiente(nullptr) {}
    };

    Nodo* actual;

public:
    ListaReproduccionCircular() : actual(nullptr) {}

    void agregarCancion(Cancion cancion) {
        Nodo* nuevo = new Nodo(cancion);
        if (!actual) {
            actual = nuevo;
            actual->anterior = actual;
            actual->siguiente = actual;
        }
        else {
            nuevo->anterior = actual->anterior;
            nuevo->siguiente = actual;
            actual->anterior->siguiente = nuevo;
            actual->anterior = nuevo;
        }
    }

    Cancion reproducirSiguiente() {
        if (!actual) throw runtime_error("Lista vacia");
        Cancion cancion = actual->cancion;
        actual = actual->siguiente;
        return cancion;
    }

    void mostrarLista() {
        if (!actual) {
            cout << "Lista vacia\n";
            return;
        }

        cout << "\nLista de reproduccion circular:\n";
        Nodo* inicio = actual;
        do {
            actual->cancion.mostrar();
            actual = actual->siguiente;
        } while (actual != inicio);
    }
};

#endif
//D