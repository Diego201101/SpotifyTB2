#pragma once
#ifndef PILA_REPRODUCCION_H
#define PILA_REPRODUCCION_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Cancion.h"

using namespace std;

class PilaReproduccion {
private:
    vector<Cancion> canciones;

public:
    void agregarReproduccion(Cancion& cancion) {
        canciones.push_back(cancion);
    }

    Cancion obtenerUltima() {
        if (canciones.empty()) throw runtime_error("No hay canciones recientes");
        Cancion ultima = canciones.back();
        canciones.pop_back();
        return ultima;
    }

    void mostrarRecientes() {
        cout << "\nUltimas canciones reproducidas:\n";
        for (auto it = canciones.rbegin(); it != canciones.rend(); ++it) {
            it->mostrar();
        }
    }

    bool estaVacia() { return canciones.empty(); }
};

#endif
//D