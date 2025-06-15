#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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