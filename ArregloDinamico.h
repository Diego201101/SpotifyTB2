#pragma once
#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include "Cancion.h"
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class BibliotecaMusica {
private:
    vector<Cancion> canciones;

public:
    void agregarCancion(Cancion cancion) {
        canciones.push_back(cancion);
    }

    void buscarPorTitulo(string titulo) {
        auto criterio = [titulo](Cancion& c) {
            return c.getTitulo() == titulo;
            };

        auto it = find_if(canciones.begin(), canciones.end(), criterio);
        if (it != canciones.end()) {
            cout << "Cancion encontrada:\n";
            it->mostrar();
        }
        else {
            cout << "Cancion no encontrada\n";
        }
    }

    void mostrarBiblioteca() {
        cout << "\nBiblioteca de musica (" << canciones.size() << " canciones):\n";
        for (auto& cancion : canciones) {
            cancion.mostrar();
        }
    }

    void ordenarPorArtista() {
        auto comparador = [](Cancion& a, Cancion& b) {
            return a.getArtista() < b.getArtista();
            };
        sort(canciones.begin(), canciones.end(), comparador);
    }
};

#endif
//D