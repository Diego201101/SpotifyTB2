#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>
using namespace std;

template <typename T>
class NodoEnlazado {
public:
    T dato;
    NodoEnlazado* siguiente;

    NodoEnlazado(T d) : dato(d), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    NodoEnlazado<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void agregarCancion(T cancion) {
        NodoEnlazado<T>* nuevoNodo = new NodoEnlazado<T>(cancion);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void mostrarCanciones() {
        NodoEnlazado<T>* actual = cabeza;
        while (actual) {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }

    void filtrarPorGenero(string genero) {
        NodoEnlazado<T>* actual = cabeza;
        while (actual) {
            if (actual->dato.getGenero() == genero) {
                actual->dato.mostrar();
            }
            actual = actual->siguiente;
        }
    }
};

#endif
//D