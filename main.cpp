#include <iostream>
#include "Usuario.hpp"
#include "Cancion.hpp"
#include "Playlist.hpp"
#include "Historial.hpp"

int main() {
    Usuario u1("Abigail", "abi@email.com", "1234");
    u1.mostrarPerfil();

    Cancion c1("Corazón Partío", "Alejandro Sanz", 4.3);
    Cancion c2("Rolling in the Deep", "Adele", 3.8);
    Cancion c3("Tusa", "Karol G", 3.5);

    Playlist miPlaylist("Favoritas");
    miPlaylist.agregarCancion(c1);
    miPlaylist.agregarCancion(c2);
    miPlaylist.agregarCancion(c3);

    cout << "\n--- Playlist actual ---" << endl;
    miPlaylist.mostrarPlaylist();

    miPlaylist.eliminarCancion("Tusa");
    cout << "\n--- Playlist después de eliminar 'Tusa' ---" << endl;
    miPlaylist.mostrarPlaylist();

    Historial<Cancion> historial;
    historial.agregarEntrada(c1);
    historial.agregarEntrada(c3);

    cout << "\n--- Historial de reproducción ---" << endl;
    historial.mostrarHistorial();

    return 0;
}