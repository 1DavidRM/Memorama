#pragma once
#include <SFML/System.hpp>

class Tiempo {
private:
    sf::Clock clock;
public:
    Tiempo();
    void reiniciar();
    int restante() const; // segundos restantes
};