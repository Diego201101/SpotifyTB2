#pragma once
#ifndef PODCASTS_H
#define PODCASTS_H

#include <iostream>
#include <string>

using namespace std;

class Podcasts {
private:
    string titulo;
    string anfitrion;
    float duracion;
    string categoria;

public:
    Podcasts(string t, string a, float d, string c = "General")
        : titulo(t), anfitrion(a), duracion(d), categoria(c) {
    }

    void mostrar() {
        cout << "+ " << titulo << " | Anfitrion: " << anfitrion
            << " (" << duracion << " min) [" << categoria << "]" << endl;
    }

    void reproducir() {
        cout << "Reproduciendo: " << titulo << " - " << anfitrion << "\n";
    }

    string getTitulo() { return titulo; }
    string getAnfitrion() { return anfitrion; }
    string getCategoria() { return categoria; }
};

#endif
//M