#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Cancion {
private:
    string titulo;
    string artista;
    float duracion;

public:
    Cancion(string t, string a, float d) : titulo(t), artista(a), duracion(d) {}

    string getTitulo() { return titulo; }

    void mostrar() {
        cout << titulo << " - " << artista << " (" << duracion << " min)" << endl;
    }
};