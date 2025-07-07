//LEYENDA:
//A: Hecho por Abigail
//M: Hecho por Maria Rosa
//D: Hecho por Diego

#include "SpotifyClone.h"

// Árbol Binario para canciones por ID
struct NodoArbol {
    int id;
    Cancion cancion;
    NodoArbol* izquierda;
    NodoArbol* derecha;
    NodoArbol(int id, const Cancion& c) : id(id), cancion(c), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolCanciones {
private:
    NodoArbol* raiz;

    NodoArbol* insertar(NodoArbol* nodo, int id, const Cancion& c) {
        if (!nodo) return new NodoArbol(id, c);
        if (id < nodo->id) nodo->izquierda = insertar(nodo->izquierda, id, c);
        else nodo->derecha = insertar(nodo->derecha, id, c);
        return nodo;
    }

    void inOrden(NodoArbol* nodo) {
        if (!nodo) return;
        inOrden(nodo->izquierda);
        cout << "ID " << nodo->id << ": ";
        nodo->cancion.mostrar();
        inOrden(nodo->derecha);
    }

    void preOrden(NodoArbol* nodo) {
        if (!nodo) return;
        cout << "ID " << nodo->id << ": ";
        nodo->cancion.mostrar();
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }

    void postOrden(NodoArbol* nodo) {
        if (!nodo) return;
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        cout << "ID " << nodo->id << ": ";
        nodo->cancion.mostrar();
    }

    void simularExportacion(NodoArbol* nodo, string recorrido, vector<string>& exportado) {
        if (!nodo) return;

        if (recorrido == "pre") exportado.push_back(nodo->cancion.getTitulo());
        simularExportacion(nodo->izquierda, recorrido, exportado);
        if (recorrido == "in") exportado.push_back(nodo->cancion.getTitulo());
        simularExportacion(nodo->derecha, recorrido, exportado);
        if (recorrido == "post") exportado.push_back(nodo->cancion.getTitulo());
    }

public:
    ArbolCanciones() : raiz(nullptr) {}

    void insertarCancion(int id, const Cancion& c) {
        raiz = insertar(raiz, id, c);
    }

    void mostrarEnOrden() {
        cout << "\n🎵 Mostrando canciones ordenadas por ID (Inorden - ideal para listar en el catálogo):\n";
        inOrden(raiz);
    }

    void mostrarPreOrden() {
        cout << "\n🎶 Mostrando canciones en orden de prioridad (Preorden - útil para cargar favoritos):\n";
        preOrden(raiz);
    }

    void mostrarPostOrden() {
        cout << "\n🧹 Mostrando canciones en postorden (ideal para eliminar de manera segura):\n";
        postOrden(raiz);
    }

    void exportarSimulado(string tipo) {
        vector<string> exportado;
        simularExportacion(raiz, tipo, exportado);
        cout << "\n📄 Exportación simulada (" << tipo << "orden): ";
        for (const auto& titulo : exportado) {
            cout << "\"" << titulo << "\" ";
        }
        cout << "\n";
    }
};

void SpotifyClone::mostrarCancionesPorRecorrido() {
    ArbolCanciones arbol;
    for (int i = 0; i < biblioteca.size(); ++i) {
        arbol.insertarCancion(i, biblioteca[i]);
    }

    int opcion;
    do {
        limpiarPantalla();
        cout << "🔁 Recorridos del Árbol de Canciones (simulan distintos usos):\n";
        cout << "1. Inorden (orden por ID / catálogo)\n";
        cout << "2. Preorden (favoritos / carga rápida)\n";
        cout << "3. Postorden (eliminación segura)\n";
        cout << "4. Exportar (simulado)\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            arbol.mostrarEnOrden();
            break;
        case 2:
            arbol.mostrarPreOrden();
            break;
        case 3:
            arbol.mostrarPostOrden();
            break;
        case 4: {
            int tipo;
            cout << "\nExportar recorrido:\n1. Inorden\n2. Preorden\n3. Postorden\nOpción: ";
            cin >> tipo;
            if (tipo == 1) arbol.exportarSimulado("in");
            else if (tipo == 2) arbol.exportarSimulado("pre");
            else if (tipo == 3) arbol.exportarSimulado("post");
            else cout << "Opción inválida.\n";
            break;
        }
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}






SpotifyClone::SpotifyClone() :
    usuario("Usuario Demo", "demo@spotify.com", "password123"),
    suscripcion("Premium", 12) { // Suscripción premium por 12 meses

    inicializarDataset();
    inicializarArtistasYAlbumes();

    // Agregar algunas canciones iniciales a favoritos
    likedSongs.agregarCancion(biblioteca[0]); // Blinding Lights
    likedSongs.agregarCancion(biblioteca[5]); // Bohemian Rhapsody
    likedSongs.agregarCancion(biblioteca[15]); // Despacito

    // Configurar géneros preferidos del usuario
    string pop = "Pop", rock = "Rock";
    usuario.agregarGeneroPreferido(pop);
    usuario.agregarGeneroPreferido(rock);

    // Crear una playlist por defecto
    Playlist pl("Favoritas 2023", "Mis canciones favoritas de este año");
    pl.agregarCancion(biblioteca[0]);
    pl.agregarCancion(biblioteca[5]);
    pl.agregarCancion(biblioteca[10]);
    playlists.push_back(pl);

    // Agregar notificación de bienvenida
    notificaciones.agregarNotificacion("Bienvenido a Spotify!");
    notificaciones.agregarNotificacion("Tu suscripcion Premium esta activa");
}

void SpotifyClone::inicializarArtistasYAlbumes() {
    // Crear artistas y agregar sus canciones
    Artista theWeeknd("The Weeknd", "Pop");
    theWeeknd.agregarCancion(biblioteca[0]);
    artistas.push_back(theWeeknd);

    Artista queen("Queen", "Rock");
    queen.agregarCancion(biblioteca[5]);
    artistas.push_back(queen);

    Artista luisFonsi("Luis Fonsi", "Reggaeton");
    luisFonsi.agregarCancion(biblioteca[15]);
    artistas.push_back(luisFonsi);

    // Crear álbumes
    Album afterHours("After Hours", "The Weeknd", 2020);
    afterHours.agregarCancion(biblioteca[0]);
    albumes.push_back(afterHours);

    Album nightAtTheOpera("A Night at the Opera", "Queen", 1975);
    nightAtTheOpera.agregarCancion(biblioteca[5]);
    albumes.push_back(nightAtTheOpera);

    Artista blondie("Blondie", "New Wave");
    Album parallelLines("Parallel Lines", "Blondie", 1978);
    Album noExit("No Exit", "Blondie", 1999);

    for (auto& cancion : biblioteca) {
        if (cancion.getArtista() == "Blondie") {
            blondie.agregarCancion(cancion);

            if (cancion.getTitulo() == "Maria") {
                noExit.agregarCancion(cancion);
            }
            else {
                parallelLines.agregarCancion(cancion);
            }
        }
    }
    artistas.push_back(blondie);
	albumes.push_back(parallelLines);
	albumes.push_back(noExit);
}
//DATASET
void SpotifyClone::inicializarDataset() {
    // Dataset expandido de canciones
    biblioteca = {
        // Pop
        Cancion("Blinding Lights", "The Weeknd", 3.3, "Pop", 95),
        Cancion("Watermelon Sugar", "Harry Styles", 2.9, "Pop", 88),
        Cancion("Levitating", "Dua Lipa", 3.4, "Pop", 92),
        Cancion("Good 4 U", "Olivia Rodrigo", 2.9, "Pop", 85),
        Cancion("Stay", "The Kid LAROI", 2.2, "Pop", 90),

        // Rock
        Cancion("Bohemian Rhapsody", "Queen", 5.9, "Rock", 98),
        Cancion("Sweet Child O' Mine", "Guns N' Roses", 5.6, "Rock", 95),
        Cancion("Hotel California", "Eagles", 6.5, "Rock", 97),
        Cancion("Stairway to Heaven", "Led Zeppelin", 8.0, "Rock", 99),
        Cancion("Smells Like Teen Spirit", "Nirvana", 5.0, "Rock", 92),

        // Hip-Hop
        Cancion("God's Plan", "Drake", 3.2, "Hip-Hop", 87),
        Cancion("HUMBLE.", "Kendrick Lamar", 2.9, "Hip-Hop", 89),
        Cancion("Sicko Mode", "Travis Scott", 5.1, "Hip-Hop", 84),
        Cancion("Old Town Road", "Lil Nas X", 2.6, "Hip-Hop", 93),
        Cancion("Lucid Dreams", "Juice WRLD", 4.0, "Hip-Hop", 82),

        // Reggaeton
        Cancion("Despacito", "Luis Fonsi", 3.7, "Reggaeton", 96),
        Cancion("Con Altura", "Rosalía", 2.8, "Reggaeton", 78),
        Cancion("Tusa", "Karol G", 3.2, "Reggaeton", 81),
        Cancion("Dakiti", "Bad Bunny", 3.2, "Reggaeton", 88),
        Cancion("La Botella", "Ozuna", 3.5, "Reggaeton", 75),

        // Electronic
        Cancion("Titanium", "David Guetta", 4.1, "Electronic", 86),
        Cancion("Clarity", "Zedd", 4.5, "Electronic", 83),
        Cancion("Animals", "Martin Garrix", 5.1, "Electronic", 79),
        Cancion("Wake Me Up", "Avicii", 4.1, "Electronic", 91),
        Cancion("Bangarang", "Skrillex", 3.5, "Electronic", 77),

        // Indie
        Cancion("Somebody That I Used to Know", "Gotye", 4.0, "Indie", 89),
        Cancion("Pumped Up Kicks", "Foster the People", 4.0, "Indie", 85),
        Cancion("Take Me to Church", "Hozier", 4.0, "Indie", 87),
        Cancion("Radioactive", "Imagine Dragons", 3.1, "Indie", 88),
        Cancion("Stressed Out", "Twenty One Pilots", 3.5, "Indie", 84),

		//New Wave Blondie
        Cancion("Hanging on the Telephone", "Blondie", 2.22, "New Wave", 85),
        Cancion("One Way or Another", "Blondie", 3.37, "New Wave", 92),
        Cancion("Picture This", "Blondie", 2.58, "New Wave", 80),
        Cancion("Fade Away and Radiate", "Blondie", 3.57, "New Wave", 75),
        Cancion("Pretty Baby", "Blondie", 3.16, "New Wave", 78),
        Cancion("I Know But I Don't Know", "Blondie", 3.53, "New Wave", 70),
        Cancion("11:59", "Blondie", 3.19, "New Wave", 73),
        Cancion("Will Anything Happen?", "Blondie", 2.55, "New Wave", 68),
        Cancion("Sunday Girl", "Blondie", 3.01, "New Wave", 83),
        Cancion("Heart of Glass", "Blondie", 3.54, "Disco", 95),
        Cancion("I'm Gonna Love You Too", "Blondie", 2.03, "New Wave", 65),
        Cancion("Just Go Away", "Blondie", 3.21, "New Wave", 72),

        Cancion("Maria", "Blondie", 4.51, "New Wave", 88)
    };

    // Dataset de podcasts
    podcasts = {
        Podcasts("The Joe Rogan Experience", "Joe Rogan", 180.0, "Entrevistas"),
        Podcasts("Serial", "Sarah Koenig", 45.0, "Crimen Real"),
        Podcasts("This American Life", "Ira Glass", 60.0, "Narrativa"),
        Podcasts("Conan O'Brien Needs a Friend", "Conan O'Brien", 90.0, "Comedia"),
        Podcasts("How I Built This", "Guy Raz", 50.0, "Negocios"),
        Podcasts("The Daily", "The New York Times", 25.0, "Noticias"),
        Podcasts("Radiolab", "Jad Abumrad", 55.0, "Ciencia"),
        Podcasts("My Favorite Murder", "Karen Kilgariff", 75.0, "Crimen Real"),
        Podcasts("Planet Money", "NPR", 30.0, "Economía"),
        Podcasts("Stuff You Should Know", "Josh Clark", 40.0, "Educativo")
    };

    // Inicializar grafo de recomendaciones
    inicializarGrafoRecomendaciones();
}

void SpotifyClone::mostrarMenuPrincipal() {
    cout << "\n ____________________________________________________________\n";
	cout << "|                                                              |\n";
    cout << "|                           SPOTIFY                            |\n";
    cout << "|____________________________________________________________|\n";
    cout << "|  1. Mostrar perfil de usuario                                |\n";
    cout << "|  2. Explorar biblioteca musical                              |\n";
    cout << "|  3. Gestionar Liked Songs                                    |\n";
    cout << "|  4. Reproducir musica                                        |\n";
    cout << "|  5. Buscar canciones                                         |\n";
    cout << "|  6. Explorar podcasts                                        |\n";
    cout << "|  7. Ver estadísticas                                         |\n";
    cout << "|  8. Obtener recomendaciones                                  |\n";
    cout << "|  9. Configuración                                            |\n";
    cout << "| 10. Gestionar playlists                                      |\n";
    cout << "| 11. Ver artistas                                             |\n";
    cout << "| 12. Ver albumes                                              |\n";
    cout << "| 13. Ver suscripcion                                          |\n";
    cout << "| 14. Vista estructurada de canciones                          |\n";
    cout << "|  0. Salir                                                    |\n";
    cout << "|____________________________________________________________|\n";
    cout << "Seleccione una opcion: ";
}
//OPCION 2
void SpotifyClone::explorarBiblioteca() {
    int opcion;
    do {
        cout << "\nBIBLIOTECA MUSICAL\n";
        cout << "1. Ver todas las canciones\n";
        cout << "2. Filtrar por genero\n";
        cout << "3. Ordenar por popularidad\n";
        cout << "4. Ver top 10 mas populares\n";
		cout << "5. Ordenar por duracion\n";
        cout << "0. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarTodasLasCanciones();
            break;
        case 2:
            filtrarPorGenero();
            break;
        case 3:
            ordenarPorPopularidad();
            break;
        case 4:
            mostrarTop10();
            break;
		case 5:
            ordenarPorDuracion();
			break;
        }
    } while (opcion != 0);
}

void SpotifyClone::mostrarTodasLasCanciones() {
    cout << "\nTodas las canciones (" << biblioteca.size() << "):\n";
    for (auto& cancion : biblioteca) {
        cancion.mostrar();
    }
}
//metodo ordenar A
void SpotifyClone::filtrarPorGenero() {
    cout << "\nGeneros disponibles:\n";
    map<string, int> generos;
    for (auto& cancion : biblioteca) {
        generos[cancion.getGenero()]++;
    }

    for (auto& par : generos) {
        cout << "• " << par.first << " (" << par.second << " canciones)\n";
    }

    cout << "\nIngrese el genero: ";
    string genero;
    cin.ignore();
    getline(cin, genero);

    // Lambda A
    auto filtroGenero = [](Cancion& c, string& genero) {
        return c.getGenero() == genero;
    };

    cout << "\nCanciones de " << genero << ":\n";
    for (auto& cancion : biblioteca) {
        if (filtroGenero(cancion, genero)) {
            cancion.mostrar();
        }
    }
}

void SpotifyClone::ordenarPorPopularidad() {
    auto bibliotecaCopia = biblioteca;
    sort(bibliotecaCopia.begin(), bibliotecaCopia.end(),
		//Lambda A
        [](Cancion& a, Cancion& b) {
            return a.getPopularidad() > b.getPopularidad();
        });

    cout << "\nCanciones ordenadas por popularidad:\n";
    for (auto& cancion : bibliotecaCopia) {
        cancion.mostrar();
    }
}

void SpotifyClone::mostrarTop10() {
    auto bibliotecaCopia = biblioteca;
    sort(bibliotecaCopia.begin(), bibliotecaCopia.end(),
        [](Cancion& a, Cancion& b) {
            return a.getPopularidad() > b.getPopularidad();
        });

    // Lambda M 
    auto formatoTop10 = [](Cancion& c, int posicion) {
        cout << "+" << posicion << ". " << c.getTitulo()
            << " (" << c.getPopularidad() << "%)\n";
    };

    cout << "\nTOP 10 canciones más populares:\n";
    for (int i = 0; i < min(10, (int)bibliotecaCopia.size()); i++) {
        formatoTop10(bibliotecaCopia[i], i + 1);
    }
}

// Algoritmo avanzado (QuickSort)
void SpotifyClone::ordenarPorDuracionQuickSort(vector<Cancion>& canciones, int izquierda, int derecha) {
    if (izquierda < derecha) {
        auto particion = [](vector<Cancion>& c, int l, int r) {
            float pivote = c[r].getDuracion();
            int i = l - 1;
            for (int j = l; j < r; j++) {
                if (c[j].getDuracion() <= pivote) {
                    i++;
                    swap(c[i], c[j]);
                }
            }
            swap(c[i + 1], c[r]);
            return i + 1;
            };

        int indicePivote = particion(canciones, izquierda, derecha);
        ordenarPorDuracionQuickSort(canciones, izquierda, indicePivote - 1);
        ordenarPorDuracionQuickSort(canciones, indicePivote + 1, derecha);
    }
}

// Método de interfaz para llamar al QuickSort
void SpotifyClone::ordenarPorDuracion() {
    vector<Cancion> copia = biblioteca;
    ordenarPorDuracionQuickSort(copia, 0, copia.size() - 1);

    cout << "\nCanciones ordenadas por duración:\n";
    for (auto& cancion : copia) {
        cancion.mostrar();
    }
}

//OPCION 3
void SpotifyClone::gestionarLikedSongs() {
    int opcion;
    do {
        cout << "\nLIKED SONGS (" << likedSongs.getTamanio() << " canciones)\n";
        cout << "1. Ver mis canciones favoritas\n";
        cout << "2. Agregar cancion a favoritos\n";
        cout << "3. Reproducir aleatorio\n";
        cout << "0. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            likedSongs.mostrar();
            break;
        case 2:
            agregarAFavoritos();
            break;
        case 3:
            reproducirAleatorio();
            break;
        }
    } while (opcion != 0);
}

void SpotifyClone::agregarAFavoritos() {
    mostrarTodasLasCanciones();
    cout << "\nIngrese el numero de canción a agregar (0 para cancelar): ";
    int indice;
    cin >> indice;

    if (indice > 0 && indice <= biblioteca.size()) {
        likedSongs.agregarCancion(biblioteca[indice - 1]);
        cout << "Canción agregada a Liked Songs!\n";
    }
}

void SpotifyClone::reproducirAleatorio() {
    try {
        generador.cargarCanciones(likedSongs.obtenerTodas());
        Cancion cancion = generador.reproducirAleatorio();
        cout << "\nReproduciendo aleatorio:\n";
        cancion.mostrar();
        historial.agregarReproduccion(cancion);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}
//OPCION 4
void SpotifyClone::menuReproduccion() {
    int opcion;
    do {
        cout << "\nMENÚ DE REPRODUCCIÓN\n";
        cout << "1. Agregar cancion a cola\n";
        cout << "2. Reproducir siguiente\n";
        cout << "3. Ver cola de reproduccion\n";
        cout << "4. Ver historial\n";
        cout << "0. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarACola();
            break;
        case 2:
            reproducirSiguiente();
            break;
        case 3:
            cola.mostrarCola();
            break;
        case 4:
            historial.mostrarRecientes();
            break;
        }
    } while (opcion != 0);
}

void SpotifyClone::agregarACola() {
    mostrarTodasLasCanciones();
    cout << "\nIngrese el numero de cancion a agregar a cola (0 para cancelar): ";
    int indice;
    cin >> indice;

    if (indice > 0 && indice <= biblioteca.size()) {
        cola.encolarCancion(biblioteca[indice - 1]);
        cout << "Canción agregada a la cola!\n";
    }
}

void SpotifyClone::reproducirSiguiente() {
    try {
        Cancion cancion = cola.reproducirSiguiente();
        cout << "\nReproduciendo:\n";
        cancion.mostrar();
        historial.agregarReproduccion(cancion);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}
//OPCION 5
void SpotifyClone::buscarCanciones() {
    cout << "\nBuscar canciones\n";
    cout << "Ingrese termino de busqueda: ";
    string criterio;
    cin.ignore();
    getline(cin, criterio);

    vector<Cancion> resultados = buscador.buscar(biblioteca, criterio);
    buscador.mostrarResultados(resultados);
}
//OPCION 6
void SpotifyClone::explorarPodcasts() {
    int opcion;
    do {
        cout << "\nPODCASTS\n";
        cout << "1. Ver todos los podcasts\n";
        cout << "2. Filtrar por categoria\n";
        cout << "3. Buscar podcast\n";
		cout << "4. Reproducir podcast\n";
        cout << "0. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarTodosLosPodcasts();
            break;
        case 2:
            filtrarPodcastsPorCategoria();
            break;
        case 3:
            buscarPodcast();
            break;
		case 4:
            cout << "Ingrese número de podcast: ";
            int numPodcast;
            cin >> numPodcast;
            if (numPodcast > 0 && numPodcast <= podcasts.size()) {
                podcasts[numPodcast - 1].reproducir();
            }
            break;
        }
    } while (opcion != 0);
}

void SpotifyClone::mostrarTodosLosPodcasts() {
    cout << "\nTodos los podcasts (" << podcasts.size() << "):\n";
    for (auto& podcast : podcasts) {
        podcast.mostrar();
    }
}

void SpotifyClone::filtrarPodcastsPorCategoria() {
    cout << "\nCategorias disponibles:\n";
    map<string, int> categorias;
    for (auto& podcast : podcasts) {
        categorias[podcast.getCategoria()]++;
    }

    for (auto& par : categorias) {
        cout << "• " << par.first << " (" << par.second << " podcasts)\n";
    }

    cout << "\nIngrese la categoria: ";
    string categoria;
    cin.ignore();
    getline(cin, categoria);

    cout << "\nPodcasts de " << categoria << ":\n";
    for (auto& podcast : podcasts) {
        if (podcast.getCategoria() == categoria) {
            podcast.mostrar();
        }
    }
}

void SpotifyClone::buscarPodcast() {
    cout << "\nBuscar podcasts\n";
    cout << "Ingrese termino de busqueda: ";
    string criterio;
    cin.ignore();
    getline(cin, criterio);

    cout << "\nResultados de busqueda:\n";
    for (auto& podcast : podcasts) {
        if (podcast.getTitulo().find(criterio) != string::npos ||
            podcast.getAnfitrion().find(criterio) != string::npos ||
            podcast.getCategoria().find(criterio) != string::npos) {
            podcast.mostrar();
        }
    }
}
//OPCION 7
void SpotifyClone::verEstadisticas() {
    // Lambda D
    auto calcularDuracionTotal = [](vector<Cancion>& canciones) {
        float total = 0;
        for (auto& c : canciones) total += c.getDuracion();
        return total;
    };

    cout << "\nESTADÍSTICAS\n";
    cout << "• Canciones en biblioteca: " << biblioteca.size() << endl;
    cout << "• Duracion total: " << calcularDuracionTotal(biblioteca) << " min\n";
    cout << "• Podcasts disponibles: " << podcasts.size() << endl;
    cout << "• Canciones en Liked Songs: " << likedSongs.getTamanio() << endl;
    cout << "• Canciones en cola: " << cola.getTamanio() << endl;
}
//OPCION 8
void SpotifyClone::obtenerRecomendaciones() {
    if (historial.estaVacia()) {
        cout << "\nNo hay canciones recientes para generar recomendaciones.\n";
        return;
    }

    Cancion ultima = historial.obtenerUltima();
    cout << "\nRECOMENDACIONES basadas en:\n";
    ultima.mostrar();

    vector<string> recomendaciones = grafoRecomendaciones.obtenerRecomendaciones(ultima.getTitulo());

    cout << "\nTe recomendamos:\n";
    for (auto& titulo : recomendaciones) {
        auto it = find_if(biblioteca.begin(), biblioteca.end(),
            [&titulo](Cancion& c) { return c.getTitulo() == titulo; });
        if (it != biblioteca.end()) {
            it->mostrar();
        }
    }
}

void SpotifyClone::inicializarGrafoRecomendaciones() {
    // Conectar canciones similares por género y popularidad
    map<string, vector<string>> generoACanciones;

    for (auto& cancion : biblioteca) {
        generoACanciones[cancion.getGenero()].push_back(cancion.getTitulo());
    }

    // Crear conexiones dentro del mismo género
    for (auto& par : generoACanciones) {
        vector<string>& canciones = par.second;
        for (int i = 0; i < canciones.size(); i++) {
            for (int j = i + 1; j < canciones.size(); j++) {
                grafoRecomendaciones.agregarConexion(canciones[i], canciones[j], 3);
            }
        }
    }

    // Agregar algunas conexiones cruzadas entre géneros
    string bl = "Blinding Lights", lev = "Levitating";
    string br = "Bohemian Rhapsody", sth = "Stairway to Heaven";
    string des = "Despacito", dak = "Dákiti";
    string gp = "God's Plan", sm = "Sicko Mode";

    grafoRecomendaciones.agregarConexion(bl, lev, 2);
    grafoRecomendaciones.agregarConexion(br, sth, 5);
    grafoRecomendaciones.agregarConexion(des, dak, 4);
    grafoRecomendaciones.agregarConexion(gp, sm, 3);
}
//OPCION 9
void SpotifyClone::configuracion() {
    int opcion;
    do {
        cout << "\nCONFIGURACIÓN\n";
        cout << "1. Editar perfil\n";
        cout << "2. Gestionar géneros preferidos\n";
        cout << "3. Ver estadísticas avanzadas\n";
        cout << "0. Volver al menú principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            editarPerfil();
            break;
        case 2:
            gestionarGenerosPreferidos();
            break;
        case 3:
            estadisticasAvanzadas();
            break;
        }
    } while (opcion != 0);
}

void SpotifyClone::editarPerfil() {
    cout << "\nEDITAR PERFIL\n";
    cout << "Nombre actual: " << usuario.getNombre() << endl;
    cout << "Nuevo nombre: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    if (!nombre.empty()) {
        usuario = Usuario(nombre, usuario.getCorreo(), "password123");
        cout << "Perfil actualizado!\n";
    }
}

void SpotifyClone::gestionarGenerosPreferidos() {
    int opcion;
    do {
        cout << "\nGÉNEROS PREFERIDOS\n";
        cout << "1. Ver mis generos\n";
        cout << "2. Agregar genero\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            vector<string> generos = usuario.getGenerosPreferidos();
            cout << "\nTus generos preferidos:\n";
            for (auto& genero : generos) {
                cout << "• " << genero << endl;
            }
            break;
        }
        case 2: {
            cout << "\nGeneros disponibles:\n";
            map<string, int> generos;
            for (auto& cancion : biblioteca) {
                generos[cancion.getGenero()]++;
            }

            for (auto& par : generos) {
                cout << "• " << par.first << endl;
            }

            cout << "\nIngrese el genero a agregar: ";
            string genero;
            cin.ignore();
            getline(cin, genero);
            usuario.agregarGeneroPreferido(genero);
            cout << "Genero agregado!\n";
            break;
        }
        }
    } while (opcion != 0);
}

void SpotifyClone::estadisticasAvanzadas() {
    cout << "\nESTADISTICAS AVANZADAS\n";

    // Géneros más escuchados
    map<string, int> generosCount;
    for (auto& cancion : likedSongs.obtenerTodas()) {
        generosCount[cancion.getGenero()]++;
    }

    if (!generosCount.empty()) {
        cout << "\nTus generos favoritos:\n";
        for (auto& par : generosCount) {
            cout << "• " << par.first << ": " << par.second << " canciones\n";
        }
    }

    // Duración total de liked songs
    float duracionTotal = 0;
    for (auto& cancion : likedSongs.obtenerTodas()) {
        duracionTotal += cancion.getDuracion();
    }
    cout << "\nDuración total de Liked Songs: " << duracionTotal << " minutos\n";
}
//OPCION 10
void SpotifyClone::gestionarPlaylists() {
    int opcion;
    do {
        cout << "\nPLAYLISTS (" << playlists.size() << ")\n";
        cout << "1. Ver todas las playlists\n";
        cout << "2. Crear nueva playlist\n";
        cout << "3. Ver detalles de playlist\n";
        cout << "0. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nTus playlists:\n";
            for (auto& pl : playlists) {
                cout << "• " << pl.getNombre() << "\n";
            }
            pausar();
            break;
        case 2:
            crearPlaylist();
            break;
        case 3:
            if (!playlists.empty()) {
                cout << "\nSeleccione una playlist:\n";
                for (int i = 0; i < playlists.size(); i++) {
                    cout << i + 1 << ". " << playlists[i].getNombre() << "\n";
                }
                int idx;
                cin >> idx;
                if (idx > 0 && idx <= playlists.size()) {
                    int subOpcion;
                    do {
                        playlists[idx - 1].mostrar();
                        cout << "\n1. Reproducir playlist\n";
                        cout << "2. Reproducir aleatorio\n";
                        cout << "3. Agregar canción\n";
                        cout << "4. Eliminar canción\n";
                        cout << "0. Volver\n";
                        cout << "Opción: ";
                        cin >> subOpcion;

                        switch (subOpcion) {
                            case 1:
                                playlists[idx - 1].reproducir();
                                pausar();
                                break;
                            case 2:
                                playlists[idx - 1].reproducirAleatorio();
                                pausar();
                                break;
                            case 3:
                                playlists[idx - 1].agregarCancionDesdeBiblioteca(biblioteca);
                                pausar();
                                break;
                            case 4:
                                cout << "Ingrese el número de canción a eliminar: ";
                                int numCancion;
                                cin >> numCancion;
                                playlists[idx - 1].eliminarCancion(numCancion - 1);
                                cout << "Canción eliminada.\n";
                                pausar();
                                break;
                        }
                        
                    } while (subOpcion != 0);
                }
            }
            else {
                cout << "No tienes playlists creadas.\n";
            }
            pausar();
            break;
        }
    } while (opcion != 0);
}

void SpotifyClone::crearPlaylist() {
    cout << "\nCrear nueva playlist\n";
    cout << "Nombre: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    cout << "Descripcion (opcional): ";
    string desc;
    getline(cin, desc);

    Playlist nueva(nombre, desc);
    playlists.push_back(nueva);
    cout << "Playlist creada con exito!\n";
    notificaciones.agregarNotificacion("Nueva playlist creada: " + nombre);
    pausar();
}
//OPCION 11
void SpotifyClone::verArtistas() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nARTISTAS (" << artistas.size() << ")\n";
        for (int i = 0; i < artistas.size(); i++) {
            cout << i + 1 << ". ";
            artistas[i].mostrar();
        }

        cout << "\nSeleccione un artista (0 para volver): ";
        cin >> opcion;

        if (opcion > 0 && opcion <= artistas.size()) {
            Artista& artista = artistas[opcion - 1];
            int subOpcion;
            do {
                limpiarPantalla();
                artista.mostrar();
                cout << "\n1. Reproducir todas las canciones\n";
                cout << "2. Reproducir aleatorio\n";
                cout << "0. Volver\n";
                cout << "Opcion: ";
                cin >> subOpcion;

                switch (subOpcion) {
                case 1: {
                    cout << "\nReproduciendo todas las canciones de " << artista.getNombre() << ":\n";
                    for (auto& cancion : artista.getCanciones()) {
                        cancion.mostrar();
                        historial.agregarReproduccion(cancion);
                    }
                    pausar();
                    break;
                }
                case 2: {
                    vector<Cancion> canciones = artista.getCanciones();
                    if (!canciones.empty()) {
                        int indice = rand() % canciones.size();
                        cout << "\nReproduciendo aleatorio:\n";
                        canciones[indice].mostrar();
                        historial.agregarReproduccion(canciones[indice]);
                    }
                    else {
                        cout << "No hay canciones disponibles.\n";
                    }
                    pausar();
                    break;
                }
                }
            } while (subOpcion != 0);
        }
    } while (opcion != 0);
}
//OPCION 12
void SpotifyClone::verAlbumes() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nALBUMES (" << albumes.size() << ")\n";
        for (int i = 0; i < albumes.size(); i++) {
            cout << i + 1 << ". ";
            albumes[i].mostrar();
        }

        cout << "\nSeleccione un album (0 para volver): ";
        cin >> opcion;

        if (opcion > 0 && opcion <= albumes.size()) {
            Album& album = albumes[opcion - 1];
            int subOpcion;
            do {
                limpiarPantalla();
                album.mostrar();
                cout << "\n1. Reproducir todo el álbum\n";
                cout << "2. Reproducir canción específica\n";
                cout << "3. Reproducir aleatorio\n";
                cout << "0. Volver\n";
                cout << "Opcion: ";
                cin >> subOpcion;

                switch (subOpcion) {
                case 1: {
                    cout << "\nReproduciendo album " << album.getTitulo() << ":\n";
                    album.mostrar(); // Esto ya muestra todas las canciones
                    // Agregar todas al historial
                    for (auto& cancion : album.getCanciones()) {
                        historial.agregarReproduccion(cancion);
                    }
                    pausar();
                    break;
                }
                case 2: {
                    cout << "\nSeleccione cancion (1-" << album.getCanciones().size() << "): ";
                    int numCancion;
                    cin >> numCancion;
                    if (numCancion > 0 && numCancion <= album.getCanciones().size()) {
                        Cancion cancion = album.getCanciones()[numCancion - 1];
                        cout << "\nReproduciendo:\n";
                        cancion.mostrar();
                        historial.agregarReproduccion(cancion);
                    }
                    else {
                        cout << "Número de canción invalido.\n";
                    }
                    pausar();
                    break;
                }
                case 3: {
                    vector<Cancion> canciones = album.getCanciones();
                    if (!canciones.empty()) {
                        int indice = rand() % canciones.size();
                        cout << "\nReproduciendo aleatorio:\n";
                        canciones[indice].mostrar();
                        historial.agregarReproduccion(canciones[indice]);
                    }
                    else {
                        cout << "No hay canciones disponibles.\n";
                    }
                    pausar();
                    break;
                }
                }
            } while (subOpcion != 0);
        }
    } while (opcion != 0);
}
//OPCION 13
void SpotifyClone::verSuscripcion() {
    suscripcion.mostrar();
    if (!suscripcion.estaActiva()) {
        cout << "Tu suscripcion ha expirado. Renueva para disfrutar de todas las funciones.\n";
    }
    pausar();
}

void SpotifyClone::limpiarPantalla() {
    system("cls || clear");
}

void SpotifyClone::pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}



void SpotifyClone::ejecutar() {
    notificaciones.mostrarNotificaciones();
    pausar();

    int opcion;
    do {
        limpiarPantalla();
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            usuario.mostrarPerfil();
            pausar();
            break;
        case 2:
            explorarBiblioteca();
            break;
        case 3:
            gestionarLikedSongs();
            break;
        case 4:
            menuReproduccion();
            break;
        case 5:
            buscarCanciones();
            pausar();
            break;
        case 6:
            explorarPodcasts();
            break;
        case 7:
            verEstadisticas();
            pausar();
            break;
        case 8:
            obtenerRecomendaciones();
            pausar();
            break;
        case 9:
            configuracion();
            break;
        case 10:
            gestionarPlaylists();
            break;
        case 11:
            verArtistas();
            break;
        case 12:
            verAlbumes();
            break;
        case 13:
            verSuscripcion();
            break;
        case 14:
            mostrarCancionesPorRecorrido();
            break;

    

        case 0:
            cout << "\n¡Hasta pronto!\n";
            break;
        default:
            cout << "Opcion no valida\n";
            pausar();
        }
    } while (opcion != 0);
}

int main() {
    SpotifyClone app;
    app.ejecutar();
    return 0;
}
//AMD (Todos hicimos parte del codigo)