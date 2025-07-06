#pragma once
#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <string>
#include <vector>
#include "Cancion.h"

using namespace std;

class Artista {
private:
    string nombre;
    string genero;
    vector<Cancion> canciones;

public:
    Artista(string n, string g) : nombre(n), genero(g) {}

    void agregarCancion(Cancion cancion) {
        canciones.push_back(cancion);
    }

    void mostrar() {
        cout << "\n+ " << nombre << " (" << genero << ") - "
            << canciones.size() << " canciones\n";
        for (auto& cancion : canciones) {
            cout << "   ";
            cancion.mostrar();
        }
    }
    string getNombre() { return nombre; }
    vector<Cancion>& getCanciones() { return canciones; }
};

#endif
//A
