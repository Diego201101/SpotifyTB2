#pragma once
#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Usuario {
private:
    string nombre;
    string correo;
    string contrasena;
    vector<string> generosPreferidos;

public:
    Usuario(string n, string c, string p) : nombre(n), correo(c), contrasena(p) {}
    //metodo agregar A
    void agregarGeneroPreferido(string& genero) {
        // Lambda A
        auto normalizarGenero = [](string& genero) {
            genero.erase(remove_if(genero.begin(), genero.end(), ::isspace), genero.end());
            transform(genero.begin(), genero.end(), genero.begin(), ::tolower);
            return genero;
        };

        genero = normalizarGenero(genero);
        if (find(generosPreferidos.begin(), generosPreferidos.end(), genero) == generosPreferidos.end()) {
            generosPreferidos.push_back(genero);
        }
    }

    vector<string> getGenerosPreferidos() { return generosPreferidos; }
    string getNombre() { return nombre; }
    string getCorreo() { return correo; }
    //OPCION 1
    void mostrarPerfil() {
        cout << "Usuario: " << nombre << " | Correo: " << correo << endl;
        cout << "Generos preferidos: ";
        for (auto& genero : generosPreferidos) {
            cout << genero << " ";
        }
        cout << endl;
    }
};

#endif
//A