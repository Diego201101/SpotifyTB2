#pragma once
#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Suscripcion {
private:
    string tipo;
    time_t fechaInicio;
    time_t fechaExpiracion;
    bool activa;

public:
    Suscripcion(string t, int meses = 1) : tipo(t) {
        time(&fechaInicio);
        fechaExpiracion = fechaInicio + (meses * 30 * 24 * 60 * 60);
        activa = true;
    }

    void renovar(int meses) {
        time_t ahora;
        time(&ahora);
        fechaExpiracion = max(fechaExpiracion, ahora) + (meses * 30 * 24 * 60 * 60);
        activa = true;
    }

    void mostrar() {
        cout << "\nSUSCRIPCION: " << tipo << "\n";
        cout << "Estado: " << (activa ? "Activa" : "Inactiva") << "\n";
        cout << "Expira: " << ctime(&fechaExpiracion);
    }

    bool estaActiva() {
        time_t ahora;
        time(&ahora);
        return activa && (ahora < fechaExpiracion);
    }
};

#endif
//M
