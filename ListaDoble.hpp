#ifndef LISTADOBLE_HPP
#define LISTADOBLE_HPP

#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(T val) : dato(val), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    void agregarInicio(T val) {
        Nodo<T>* nuevo = new Nodo<T>(val);
        if (!cabeza) {
            cabeza = cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
    }

    void mostrar() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

#endif