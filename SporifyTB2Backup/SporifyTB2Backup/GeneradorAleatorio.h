#pragma once
#ifndef GENERADOR_ALEATORIO_H
#define GENERADOR_ALEATORIO_H

#include <vector>
#include <random>
#include <ctime>
#include <stdexcept>
#include "Cancion.h"

using namespace std;

class GeneradorAleatorio {
private:
    vector<Cancion> likedSongs;
    mt19937 rng;

public:
    GeneradorAleatorio() : rng(time(nullptr)) {}

    void cargarCanciones(vector<Cancion>& canciones) {
        likedSongs = canciones;
    }

    Cancion reproducirAleatorio() {
        if (likedSongs.empty()) throw runtime_error("No hay canciones para reproducir");
        uniform_int_distribution<int> dist(0, likedSongs.size() - 1);
        return likedSongs[dist(rng)];
    }
};

#endif
//M