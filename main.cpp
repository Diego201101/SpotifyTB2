#include <iostream>
#include <conio.h>
#include "Usuario.h"
#include "Cancion.h"
#include "Playlist.h"
#include "Historial.h"
#include "ListaDoble.h"
#include "ListaEnlazada.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaDobleCircular.h"
#include "ArregloDinamico.h"

int main() {
    // Configuración inicial (original)
    Usuario u1("Abigail", "abi@email.com", "1234");
    u1.mostrarPerfil();

    Cancion c1("Corazon Partio", "Alejandro Sanz", 4.3, "Pop");
    Cancion c2("Rolling in the Deep", "Adele", 3.8, "Pop");
    Cancion c3("Tusa", "Karol G", 3.5, "Reggaeton");
    Cancion c4("Bohemian Rhapsody", "Queen", 5.55, "Rock");

    // Nuevas estructuras de datos
    ListaEnlazada<Cancion> listaFavoritos;
    listaFavoritos.agregarCancion(c1);
    listaFavoritos.agregarCancion(c2);
    listaFavoritos.agregarCancion(c3);

    cout << "\n--- Lista de favoritos ---" << endl;
    listaFavoritos.mostrarCanciones();

    cout << "\n--- Favoritos de Pop ---" << endl;
    listaFavoritos.filtrarPorGenero("Pop");
    listaFavoritos.mostrarCanciones();

    PilaReproduccion pila;
    pila.agregarReproduccion(c1);
    pila.agregarReproduccion(c2);
    pila.agregarReproduccion(c3);
    pila.mostrarRecientes();

    ColaReproduccion cola;
    cola.encolarCancion(c1);
    cola.encolarCancion(c2);
    cola.encolarCancion(c3);
    cola.ordenarPorDuracion();
    cola.mostrarCola();

    ListaReproduccionCircular listaCircular;
    listaCircular.agregarCancion(c1);
    listaCircular.agregarCancion(c2);
    listaCircular.agregarCancion(c3);
    listaCircular.mostrarLista();

    BibliotecaMusica biblioteca;
    biblioteca.agregarCancion(c1);
    biblioteca.agregarCancion(c2);
    biblioteca.agregarCancion(c3);
    biblioteca.agregarCancion(c4);
    biblioteca.ordenarPorArtista();
    biblioteca.mostrarBiblioteca();
    biblioteca.buscarPorTitulo("Tusa");

    _getch();
    return 0;
}
