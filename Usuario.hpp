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

public:
    Usuario(string n, string c, string p) : nombre(n), correo(c), contrasena(p) {}

    void actualizarPerfil(string nuevoNombre, string nuevoCorreo) {
        nombre = nuevoNombre;
        correo = nuevoCorreo;
    }

    string getNombre() { return nombre; }
    string getCorreo() { return correo; }

    void mostrarPerfil() {
        cout << "Usuario: " << nombre << " | Correo: " << correo << endl;
    }
};