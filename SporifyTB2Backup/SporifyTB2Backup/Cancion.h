#pragma once
#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include <string>

using namespace std;

class Cancion {
private:
    string titulo;
    string artista;
    float duracion;
    string genero;
    int popularidad; // 0-100

public:
    Cancion(string t, string a, float d, string g = "", int p = 50)
        : titulo(t), artista(a), duracion(d), genero(g), popularidad(p) {
    }

    string getTitulo() { return titulo; }
    string getArtista() { return artista; }
    float getDuracion() { return duracion; }
    string getGenero() { return genero; }
    int getPopularidad() { return popularidad; }

    void mostrar() {
        cout << "+ " << titulo << " - " << artista << " (" << duracion << " min) ";
        cout << "[" << genero << "] " << popularidad << endl;
    }

    bool operator==(Cancion& other) {
        return titulo == other.titulo && artista == other.artista;
    }
};

#endif
//A 