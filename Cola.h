#pragma once
#pragma once
#ifndef COLA_H
#define COLA_H

#include "Cancion.h"
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

class ColaReproduccion {
private:
    deque<Cancion> canciones;

public:
    void encolarCancion(Cancion cancion) {
        canciones.push_back(cancion);
    }

    Cancion reproducirSiguiente() {
        if (canciones.empty()) throw runtime_error("No hay canciones en cola");
        Cancion siguiente = canciones.front();
        canciones.pop_front();
        return siguiente;
    }

    void mostrarCola() {
        cout << "\nCola de reproduccion:\n";
        auto mostrar = [](Cancion& c) { c.mostrar(); };
        for_each(canciones.begin(), canciones.end(), mostrar);
    }

    void ordenarPorDuracion() {
        auto comparador = [](Cancion& a, Cancion& b) {
            return a.getDuracion() < b.getDuracion();
            };
        sort(canciones.begin(), canciones.end(), comparador);
    }
};

#endif
//D