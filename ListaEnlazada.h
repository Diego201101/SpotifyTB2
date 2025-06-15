#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Cancion.h"
#include <functional>
using namespace std;

template <typename T>
class ListaEnlazada {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(T val) : dato(val), siguiente(nullptr) {}
    };

    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void agregarCancion(T cancion) {
        Nodo* nuevo = new Nodo(cancion);
        if (!cabeza) {
            cabeza = nuevo;
        }
        else {
            auto encontrarUltimo = [](Nodo* nodo) {
                while (nodo->siguiente) nodo = nodo->siguiente;
                return nodo;
                };
            Nodo* ultimo = encontrarUltimo(cabeza);
            ultimo->siguiente = nuevo;
        }
    }

    void mostrarCanciones() {
        Nodo* actual = cabeza;
        while (actual) {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }

    void filtrarPorGenero(string genero) {
        auto criterio = [genero](T cancion) {
            return cancion.getGenero() == genero;
            };

        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;
        while (actual) {
            if (!criterio(actual->dato)) {
                if (anterior) {
                    anterior->siguiente = actual->siguiente;
                }
                else {
                    cabeza = actual->siguiente;
                }
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
            else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
    }
};

#endif
//D