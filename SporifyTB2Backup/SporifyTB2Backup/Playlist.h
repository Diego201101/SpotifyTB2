#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Cancion.h"

using namespace std;

class Playlist {
private:
    string nombre;
    string descripcion;
    vector<Cancion> canciones;

public:
    Playlist(string n, string d = "") : nombre(n), descripcion(d) {}

    void agregarCancion(Cancion& cancion) {
        canciones.push_back(cancion);
    }

    void eliminarCancion(int indice) {
        if (indice >= 0 && indice < canciones.size()) {
            canciones.erase(canciones.begin() + indice);
        }
    }

    void agregarCancionDesdeBiblioteca(vector<Cancion>& biblioteca) {
        cout << "\nBiblioteca de canciones:\n";
        for (int i = 0; i < biblioteca.size(); i++) {
            cout << i + 1 << ". ";
            biblioteca[i].mostrar();
        }
        cout << "Ingrese el numero de la cancion a agregar (0 para cancelar): ";
        int indice;
        cin >> indice;
        if (indice > 0 && indice <= biblioteca.size()) {
            canciones.push_back(biblioteca[indice - 1]);
            cout << "Cancion agregada a la playlist '" << nombre << "'!\n";
        }
    }

    void reproducir() {
        if (canciones.empty()) {
            cout << "La playlist está vacia.\n";
            return;
        }
        cout << "\nReproduciendo playlist '" << nombre << "':\n";
        for (auto& cancion : canciones) {
            cout << "- ";
            cancion.mostrar();
        }
    }

    void reproducirAleatorio() {
        if (canciones.empty()) {
            cout << "La playlist está vacia.\n";
            return;
        }
        int indice = rand() % canciones.size();
        cout << "\nReproduciendo aleatorio en '" << nombre << "':\n";
        cout << "- ";
        canciones[indice].mostrar();
    }

    void mostrar() {
        cout << "\n+ " << nombre << " (" << canciones.size() << " canciones)";
        if (!descripcion.empty()) {
            cout << "\n- " << descripcion << "\n";
        }
        for (int i = 0; i < canciones.size(); i++) {
            cout << i + 1 << ". ";
            canciones[i].mostrar();
        }
    }

    string getNombre() { return nombre; }
    vector<Cancion>& getCanciones() { return canciones; }
};

#endif
//A
