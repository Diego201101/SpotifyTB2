#pragma once
#ifndef PILA_H
#define PILA_H

#include "Cancion.h"
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class PilaReproduccion {
private:
    vector<Cancion> canciones;

public:
    void agregarReproduccion(Cancion cancion) {
        canciones.push_back(cancion);
    }

    Cancion obtenerUltima() {
        if (canciones.empty()) throw runtime_error("No hay canciones recientes");
        Cancion ultima = canciones.back();
        canciones.pop_back();
        return ultima;
    }

    void mostrarRecientes() {
        cout << "\nUltimas canciones reproducidas (más reciente primero):\n";
        auto mostrar = [](Cancion& c) { c.mostrar(); };
        for_each(canciones.rbegin(), canciones.rend(), mostrar);
    }
};

#endif
//D