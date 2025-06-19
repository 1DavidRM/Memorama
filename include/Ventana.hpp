#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ficha.hpp"
#include "Puntaje.hpp"
#include "Tiempo.hpp"
#include "Interfaz.hpp"

class Ventana {
private:
    sf::RenderWindow window;
    sf::Texture fondoTexture;
    sf::Sprite fondo;
    std::vector<sf::Texture> textures;
    std::vector<std::vector<Ficha>> fichas;
    Puntaje puntaje;
    Tiempo tiempo;
    int descubiertas;
    int cantDesbloqueada;
    int iAnt, jAnt;
    sf::Clock esperaClock;
    bool esperando;
    Interfaz interfaz; // <-- Agrega este atributo
    void inicializarFichas();
    void procesarEventos();
    void actualizar();
    void dibujar();
public:
    Ventana();
    void ejecutar();
};