#pragma once
#ifndef CANCION_HPP
#define CANCION_HPP

#include <string>
#include <iostream>
using namespace std;

class Cancion {
private:
    string titulo;
    string artista;
    float duracion;
    string genero;

public:
    Cancion(string t, string a, float d, string g = "")
        : titulo(t), artista(a), duracion(d), genero(g) {
    }

    string getTitulo() { return titulo; }
    string getArtista() { return artista; }
    float getDuracion() { return duracion; }
    string getGenero() { return genero; }

    void mostrar() {
        cout << titulo << " - " << artista << " (" << duracion << " min)";
        if (!genero.empty()) cout << " [" << genero << "]";
        cout << endl;
    }
};

#endif
//A