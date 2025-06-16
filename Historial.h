#pragma once
#ifndef HISTORIAL_HPP
#define HISTORIAL_HPP

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Historial {
private:
    vector<T> reproducciones;

public:
    void agregarEntrada(T cancion) {
        reproducciones.push_back(cancion);
    }

    void mostrarHistorial() {
        for (auto& c : reproducciones) {
            c.mostrar();
        }
    }
};
#endif
//A