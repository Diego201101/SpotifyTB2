#pragma once
#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <iostream>
#include <vector>
#include <string>
#include "Cancion.h"
#include "Hash.h"

using namespace std;

class Buscador {
public:
    vector<Cancion> buscar(vector<Cancion>& canciones, string& criterio) {
        vector<Cancion> resultados;
        transform(criterio.begin(), criterio.end(), criterio.begin(), ::tolower);
    
        for (auto& cancion : canciones) {
            string titulo = cancion.getTitulo();
            string artista = cancion.getArtista();
            string genero = cancion.getGenero();
    
            transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
            transform(artista.begin(), artista.end(), artista.begin(), ::tolower);
            transform(genero.begin(), genero.end(), genero.begin(), ::tolower);
    
            if (titulo.find(criterio) != string::npos ||
                artista.find(criterio) != string::npos ||
                genero.find(criterio) != string::npos) {
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
