#pragma once
#ifndef COLA_REPRODUCCION_H
#define COLA_REPRODUCCION_H

#include <iostream>
#include <deque>
#include <stdexcept>
#include "Cancion.h"

using namespace std;

class ColaReproduccion {
private:
    deque<Cancion> canciones;

public:
    void encolarCancion(Cancion& cancion) {
        canciones.push_back(cancion);
    }

    Cancion reproducirSiguiente() {
        if (canciones.empty()) throw runtime_error("No hay canciones en cola");
        Cancion siguiente = canciones.front();
        canciones.pop_front();
        return siguiente;
    }

    void mostrarCola() {
        // Lambda D
        auto mostrarCancion = [](Cancion& c) { c.mostrar(); };

        cout << "\nCola de reproducción (" << canciones.size() << " canciones):\n";
        for (auto& cancion : canciones) {
            mostrarCancion(cancion);  // Llama al lambda
        }
    }

    bool estaVacia() { return canciones.empty(); }
    int getTamanio() { return canciones.size(); }
};

#endif
//D