#pragma once
#ifndef LISTADOBLE_HPP
#define LISTADOBLE_HPP

#include <iostream>
using namespace std;

template <typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(T val) : dato(val), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    void agregarInicio(T val) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(val);
        if (!cabeza) {
            cabeza = cola = nuevo;
        }
        else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
    }

    void mostrar() {
        NodoDoble<T>* actual = cabeza;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

#endif
//A