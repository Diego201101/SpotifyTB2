#pragma once
#ifndef LIKED_SONGS_H
#define LIKED_SONGS_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class LikedSongs {
private:
    class NodoLiked {
    public:
        T dato;
        shared_ptr<NodoLiked> siguiente;
        shared_ptr<NodoLiked> anterior;

        NodoLiked(T d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
    };

    shared_ptr<NodoLiked> actual;
    int tamanio;

public:
    LikedSongs() : actual(nullptr), tamanio(0) {}
	//Metodo Buscar M
    void agregarCancion(T& cancion) {
        auto nuevo = make_shared<NodoLiked>(cancion);
        if (!actual) {
            actual = nuevo;
            actual->siguiente = actual;
            actual->anterior = actual;
        }
        else {
            nuevo->anterior = actual->anterior;
            nuevo->siguiente = actual;
            actual->anterior->siguiente = nuevo;
            actual->anterior = nuevo;
        }
        tamanio++;
    }

    void mostrar() {
        if (!actual) {
            cout << "No hay canciones en 'Liked Songs'\n";
            return;
        }

        cout << "Liked Songs (" << tamanio << " canciones):\n";
        auto inicio = actual;
        auto temp = actual;
        do {
            temp->dato.mostrar();
            temp = temp->siguiente;
        } while (temp != inicio);
    }

    vector<T> obtenerTodas() {
        vector<T> canciones;
        if (!actual) return canciones;

        auto inicio = actual;
        auto temp = actual;
        do {
            canciones.push_back(temp->dato);
            temp = temp->siguiente;
        } while (temp != inicio);

        return canciones;
    }

    int getTamanio() { return tamanio; }
};

#endif
//M