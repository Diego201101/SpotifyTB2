#pragma once
#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>
#include <iostream>
using namespace std;

class Comentario {
private:
    string usuario;
    string texto;

public:
    Comentario(string u, string t) : usuario(u), texto(t) {}

    void editarComentario(string nuevoTexto) {
        texto = nuevoTexto;
    }

    void mostrar() {
        cout << usuario << " comento: " << texto << endl;
    }
};

#endif
//A