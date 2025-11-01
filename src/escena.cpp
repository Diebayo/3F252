#include "escena.hpp"

Escena::Escena(int ancho, int alto)
    : ancho(ancho), alto(alto), buffer(alto, std::string(ancho, ' ')),
      gato_x(ancho / 2), gato_derecha(true), nube_x(0) {

    gotas.resize(ancho);
    for (int i = 0; i < ancho; i++) {
        gotas[i] = rand() % alto;
    }
}

void Escena::Lluvia() {
    for (int x = 0; x < ancho; x++) {
        if (rand() % 3 == 0)
            buffer[gotas[x] % alto][x] = '|';
        gotas[x] = (gotas[x] + 1) % alto;
    }
}

void Escena::DibujarGato() {
    std::string cuerpo1 = " /\\_/\\ ";
    std::string cuerpo2 = "( o.o )";
    std::string cuerpo3 = " > ^ < ";

    int y = alto - 4;
    for (int i = 0; i < (int)cuerpo1.size(); i++)
        if (gato_x + i < ancho)
            buffer[y][gato_x + i] = cuerpo1[i];
    for (int i = 0; i < (int)cuerpo2.size(); i++)
        if (gato_x + i < ancho)
            buffer[y + 1][gato_x + i] = cuerpo2[i];
    for (int i = 0; i < (int)cuerpo3.size(); i++)
        if (gato_x + i < ancho)
            buffer[y + 2][gato_x + i] = cuerpo3[i];

    // Movimiento
    gato_x += (gato_derecha ? 1 : -1);
    if (gato_x <= 2 || gato_x + 8 >= ancho)
        gato_derecha = !gato_derecha;
}

void Escena::DibujarArbol() {
    int base_x = 6;
    int base_y = alto - 6;

    // Copa del árbol
    std::vector<std::string> copa = {
        "   ^^^   ",
        "  ^^^^^  ",
        " ^^^^^^^ ",
        "  ^^^^^  ",
        "   ^^^   "
    };

    for (int i = 0; i < (int)copa.size(); i++)
        for (int j = 0; j < (int)copa[i].size(); j++)
            if (base_x + j < ancho && base_y - 7 + i >= 0)
                buffer[base_y - 7 + i][base_x + j] = copa[i][j];

    // Tronco
    buffer[base_y - 2][base_x + 4] = '|';
    buffer[base_y - 1][base_x + 4] = '|';
    buffer[base_y][base_x + 4] = '|';
}

void Escena::DibujarCasa() {
    int x = ancho - 22;
    int y = alto - 6;

    std::vector<std::string> casa = {
        "     /\\     ",
        "    /  \\    ",
        "   /____\\   ",
        "  | .--. |  ",
        "  | |__| |  ",
        "  |______|  "
    };

    for (int i = 0; i < (int)casa.size(); i++)
        for (int j = 0; j < (int)casa[i].size(); j++)
            if (x + j < ancho && y - 6 + i < alto)
                buffer[y - 6 + i][x + j] = casa[i][j];
}

void Escena::DibujarNubes() {
    int y = 2;

    std::vector<std::string> nube = {
        "      .--.    ",
        "   .-(    ).  ",
        "  (___.__)__) "
    };

    for (int i = 0; i < (int)nube.size(); i++)
        for (int j = 0; j < (int)nube[i].size(); j++) {
            int x = (nube_x + j) % ancho;
            if (x < ancho && y + i < alto)
                buffer[y + i][x] = nube[i][j];
        }

    // Mueve las nubes lentamente
    nube_x = (nube_x + 1) % ancho;
}

void Escena::Dibujar() {
    system("clear"); // Linux/macOS
    for (auto &linea : buffer)
        std::cout << linea << "\n";
}

void Escena::Actualizar() {
    buffer.assign(alto, std::string(ancho, ' '));
    DibujarNubes();
    Lluvia();
    DibujarArbol();
    DibujarCasa();
    DibujarGato();
    Dibujar();
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
}
