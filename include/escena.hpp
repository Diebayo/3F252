#ifndef ESCENA_HPP
#define ESCENA_HPP

#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

class Escena {
private:
    int ancho;
    int alto;
    std::vector<std::string> buffer;
    std::vector<int> gotas; // posiciones de la lluvia
    int gato_x;
    bool gato_derecha;
    int nube_x;

public:
    Escena(int ancho, int alto);
    void Dibujar();
    void Actualizar();
    void Lluvia();
    void DibujarGato();
    void DibujarArbol();
    void DibujarCasa();
    void DibujarNubes();
};

#endif
