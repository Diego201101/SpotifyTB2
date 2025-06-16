#pragma once
#ifndef GENERO_HPP
#define GENERO_HPP

#include <string>
#include <iostream>
using namespace std;

class Genero {
private:
    string nombre;
    string descripcion;

public:
    Genero(string n, string d) : nombre(n), descripcion(d) {}

    void mostrarGenero() {
        cout << "Genero: " << nombre << " - " << descripcion << endl;
    }

    string getNombre() { return nombre; }
};

#endif
//A