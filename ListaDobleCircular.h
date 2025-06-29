#pragma once
#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

#include "Cancion.h"
#include <memory>
#include <functional>
#include <algorithm>

using namespace std;

class ListaDobleCircular {
private:
    class NodoDobleCircular {
    public:
        Cancion dato;
        shared_ptr<NodoDobleCircular> anterior;
        shared_ptr<NodoDobleCircular> siguiente;
        NodoDobleCircular(const Cancion& val) : dato(val), anterior(nullptr), siguiente(nullptr) {}
    };

    shared_ptr<NodoDobleCircular> actual;

public:
    ListaDobleCircular() : actual(nullptr) {}

    void agregarCancion(const Cancion& cancion) {
        auto nuevo = make_shared<NodoDobleCircular>(cancion);
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

    void reproducirSiguiente() {
        if (actual) {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }

    void mostrarLista() {
        if (!actual) {
            cout << "Lista vac�a\n";
            return;
        }

        auto inicio = actual;
        do {
            actual->dato.mostrar();
            actual = actual->siguiente;
        } while (actual != inicio);
    }

    void ordenarPorDuracion() {
        if (!actual) return;

        vector<Cancion> canciones;
        auto inicio = actual;
        do {
            canciones.push_back(actual->dato);
            actual = actual->siguiente;
        } while (actual != inicio);

        sort(canciones.begin(), canciones.end(),
            [](Cancion& a, Cancion& b) {
                return a.getDuracion() < b.getDuracion();
            });

        actual = nullptr;
        for (const auto& cancion : canciones) {
            agregarCancion(cancion);
        }
    }
};

using ListaReproduccionCircular = ListaDobleCircular;

#endif