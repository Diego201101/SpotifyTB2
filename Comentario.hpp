#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
        cout << usuario << " comentó: " << texto << endl;
    }
};