#pragma once
#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <iostream>
#include <vector>
#include <string>
#include "Cancion.h"

using namespace std;

class Buscador {
public:
    vector<Cancion> buscar(vector<Cancion>& canciones, string& criterio) {
        vector<Cancion> resultados;

        // Lambda M
        auto contiene = [](string& texto, string& criterio) {
            auto it = search(texto.begin(), texto.end(),
                criterio.begin(), criterio.end(),
                //LAMBDA M
                [](char ch1, char ch2) {
                    return tolower(ch1) == tolower(ch2);
                });
            return it != texto.end();
        };

        for (auto& cancion : canciones) {
            if (contiene(cancion.getTitulo(), criterio) ||
                contiene(cancion.getArtista(), criterio) ||
                contiene(cancion.getGenero(), criterio)) {
                resultados.push_back(cancion);
            }
        }

        return resultados;
    }

    void mostrarResultados(vector<Cancion>& resultados) {
        if (resultados.empty()) {
            cout << "No se encontraron canciones.\n";
            return;
        }

        cout << "Resultados de busqueda (" << resultados.size() << " canciones):\n";
        for (auto& cancion : resultados) {
            cancion.mostrar();
        }
    }
};

#endif
//M