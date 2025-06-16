#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Cancion.h"
#include <functional>
#include <memory>

using namespace std;

class ListaEnlazada {
private:
    class Nodo {
    public:
        Cancion dato;
        shared_ptr<Nodo> siguiente;
        Nodo(const Cancion& val) : dato(val), siguiente(nullptr) {}
    };

    shared_ptr<Nodo> cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void agregarCancion(const Cancion& cancion) {
        auto nuevo = make_shared<Nodo>(cancion);
        if (!cabeza) {
            cabeza = nuevo;
        }
        else {
            auto encontrarUltimo = [](shared_ptr<Nodo> nodo) {
                while (nodo->siguiente) nodo = nodo->siguiente;
                return nodo;
                };
            auto ultimo = encontrarUltimo(cabeza);
            ultimo->siguiente = nuevo;
        }
    }

    void filtrarPorGenero(const string& genero) {
        function<void(shared_ptr<Nodo>, shared_ptr<Nodo>)> filtrar =
            [&](shared_ptr<Nodo> actual, shared_ptr<Nodo> anterior) {
            if (!actual) return;

            if (actual->dato.getGenero() != genero) {
                if (anterior) {
                    anterior->siguiente = actual->siguiente;
                }
                else {
                    cabeza = actual->siguiente;
                }
                auto temp = actual;
                filtrar(actual->siguiente, anterior);
            }
            else {
                filtrar(actual->siguiente, actual);
            }
            };

        filtrar(cabeza, nullptr);
    }

    void mostrarCanciones() const {
        auto actual = cabeza;
        while (actual) {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }
};
#endif
//D
