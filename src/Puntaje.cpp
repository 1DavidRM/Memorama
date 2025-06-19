#include "../include/Puntaje.hpp"

Puntaje::Puntaje() : puntos(0) {}

void Puntaje::cambiar(int mod) {
    puntos += mod;
    if (puntos < 0) puntos = 0;
}

int Puntaje::consultar() const {
    return puntos;
}