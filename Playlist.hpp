#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include "Cancion.hpp"
using namespace std;

class Playlist {
private:
    string nombre;
    vector<Cancion> canciones;

public:
    Playlist(string n) : nombre(n) {}

    void agregarCancion(Cancion c) {
        canciones.push_back(c);
    }

    void eliminarCancion(string titulo) {
        canciones.erase(remove_if(canciones.begin(), canciones.end(),
            [titulo](Cancion& c) { return c.getTitulo() == titulo; }), canciones.end());
    }

    void mostrarPlaylist() {
        cout << "Playlist: " << nombre << endl;
        for (auto& c : canciones) {
            c.mostrar();
        }
    }
};

#endif