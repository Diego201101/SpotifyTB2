#pragma once
#ifndef NOTIFICACIONES_H
#define NOTIFICACIONES_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Notificaciones {
private:
    vector<string> mensajes;

public:
    void agregarNotificacion(string mensaje) {
        mensajes.push_back(mensaje);
    }

    void mostrarNotificaciones() {
        if (mensajes.empty()) {
            cout << "No hay notificaciones nuevas.\n";
            return;
        }

        cout << "\nNOTIFICACIONES (" << mensajes.size() << ")\n";
        for (auto& msg : mensajes) {
            cout << "• " << msg << "\n";
        }
        mensajes.clear();
    }
};

#endif
//D
