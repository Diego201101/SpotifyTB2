#include <iostream>
#include "ListaDoble.hpp"
using namespace std;

int main() {
    ListaDoble<string> lista;
    lista.agregarInicio("Bad Bunny");
    lista.agregarInicio("Shakira");
    lista.agregarInicio("Adele");

    cout << "Lista de artistas (orden inverso): ";
    lista.mostrar();

    return 0;
}