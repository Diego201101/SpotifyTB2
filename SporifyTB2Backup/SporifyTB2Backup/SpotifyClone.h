#pragma once
#ifndef SPOTIFY_CLONE_H
#define SPOTIFY_CLONE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <functional>

#include "Cancion.h"
#include "Podcasts.h"
#include "Usuario.h"
#include "GrafoRecomendaciones.h"
#include "LikedSongs.h"
#include "ColaReproduccion.h"
#include "PilaReproduccion.h"
#include "GeneradorAleatorio.h"
#include "Buscador.h"
#include "Playlist.h"
#include "Notificaciones.h"
#include "Artista.h"
#include "Album.h"
#include "Suscripcion.h"

using namespace std;

class SpotifyClone {
private:
    Usuario usuario;
    vector<Cancion> biblioteca;
    vector<Podcasts> podcasts;
    vector<Artista> artistas;
    vector<Album> albumes;
    vector<Playlist> playlists;
    LikedSongs<Cancion> likedSongs;
    ColaReproduccion cola;
    PilaReproduccion historial;
    GeneradorAleatorio generador;
    Buscador buscador;
    GrafoRecomendaciones grafoRecomendaciones;
    Notificaciones notificaciones;
    Suscripcion suscripcion;

    void ordenarPorDuracionQuickSort(vector<Cancion>& canciones, int izquierda, int derecha);
    void ordenarPorDuracion();
    void inicializarDataset();
    void inicializarArtistasYAlbumes();
    void inicializarGrafoRecomendaciones();
    void mostrarMenuPrincipal();
    void explorarBiblioteca();
    void mostrarTodasLasCanciones();
    void filtrarPorGenero();
    void ordenarPorPopularidad();
    void mostrarTop10();
    void gestionarLikedSongs();
    void agregarAFavoritos();
    void reproducirAleatorio();
    void menuReproduccion();
    void agregarACola();
    void reproducirSiguiente();
    void buscarCanciones();
    void explorarPodcasts();
    void mostrarTodosLosPodcasts();
    void filtrarPodcastsPorCategoria();
    void buscarPodcast();
    void verEstadisticas();
    void obtenerRecomendaciones();
    void configuracion();
    void editarPerfil();
    void gestionarGenerosPreferidos();
    void estadisticasAvanzadas();
    void gestionarPlaylists();
    void crearPlaylist();
    void verArtistas();
    void verAlbumes();
    void verSuscripcion();
    void limpiarPantalla();
    void pausar();

public:
    SpotifyClone();
    void ejecutar();
};

#endif
//D