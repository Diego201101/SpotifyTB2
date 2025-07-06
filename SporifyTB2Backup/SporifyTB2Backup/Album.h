#pragma once
#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <vector>
#include "Cancion.h"

using namespace std;

class Album {
private:
    string titulo;
    string artista;
    int anio;
    vector<Cancion> canciones;

public:
    Album(string t, string a, int y) : titulo(t), artista(a), anio(y) {}

    void agregarCancion(Cancion cancion) {
        canciones.push_back(cancion);
    }

    void mostrar() {
        cout << "\n+ " << titulo << " - " << artista << " (" << anio << ")\n";
        for (int i = 0; i < canciones.size(); i++) {
            cout << i + 1 << ". ";
            canciones[i].mostrar();
        }
    }
    vector<Cancion>& getCanciones() { return canciones; }
    string getTitulo() { return titulo; }
    string getArtista() { return artista; }
};

#endif
//A
