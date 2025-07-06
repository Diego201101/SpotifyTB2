#pragma once
#ifndef GRAFO_RECOMENDACIONES_H
#define GRAFO_RECOMENDACIONES_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class GrafoRecomendaciones {
private:
    unordered_map<string, unordered_set<string>> adyacencias;
    unordered_map<string, int> pesos;

public:
    void agregarConexion(string& cancion1, string& cancion2, int peso = 1) {
        adyacencias[cancion1].insert(cancion2);
        adyacencias[cancion2].insert(cancion1);
        pesos[cancion1 + "-" + cancion2] = peso;
        pesos[cancion2 + "-" + cancion1] = peso;
    }

    vector<string> obtenerRecomendaciones(string& cancionActual, int limite = 5) {
        vector<string> recomendaciones;

        if (adyacencias.find(cancionActual) != adyacencias.end()) {
            vector<pair<string, int>> candidatos;

            for (auto& vecino : adyacencias[cancionActual]) {
                string clave = cancionActual + "-" + vecino;
                int peso = pesos[clave];
                candidatos.push_back({ vecino, peso });
            }
            // MergeSort D
            sort(candidatos.begin(), candidatos.end(),
                //Lambda D
                [](pair<string, int>& a, pair<string, int>& b) {
                    return a.second > b.second;
                });

            for (int i = 0; i < min(limite, (int)candidatos.size()); i++) {
                recomendaciones.push_back(candidatos[i].first);
            }
        }

        return recomendaciones;
    }

    void mostrarGrafo() {
        cout << "\nGrafo de Recomendaciones:\n";
        for (auto& nodo : adyacencias) {
            cout << nodo.first << " -> ";
            for (auto& vecino : nodo.second) {
                cout << vecino << " ";
            }
            cout << endl;
        }
    }
};

#endif
//D