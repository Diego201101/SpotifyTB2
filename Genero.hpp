#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Genero {
private:
    string nombre;
    string descripcion;

public:
    Genero(string n, string d) : nombre(n), descripcion(d) {}

    void mostrarGenero() {
        cout << "Género: " << nombre << " - " << descripcion << endl;
    }

    string getNombre() { return nombre; }
};
