#include "../include/Ventana.hpp"
#include <iostream>
#include <ctime>
#include <vector>

#include <cstdlib>

using namespace std;
using namespace sf;
Ventana::Ventana() : window(sf::VideoMode(850, 750), "Memorama"), textures(6), fichas(3, std::vector<Ficha>(4)), descubiertas(0), cantDesbloqueada(0), esperando(false) {
    window.setFramerateLimit(60);
    if (!fondoTexture.loadFromFile("assets/Fondo.png"))
        std::cout << "Error al cargar textura de fondo" << std::endl;
    fondo.setTexture(fondoTexture);
    vector<Texture> textures(6);
    for (int i = 1; i <= 6; i++) {
        sf::Texture tex;
        if (!tex.loadFromFile("assets/" + std::to_string(i) + ".png"))
            std::cout << "Error al cargar la textura " << i << std::endl;
        textures[i - 1] = tex;
    }
    inicializarFichas();
}

void Ventana::inicializarFichas() {
    std::vector<int> cantApariciones(6, 0);
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int tipoRandom;
            do {
                tipoRandom = 1 + (rand() % 6);
            } while (cantApariciones[tipoRandom - 1] == 2);
            cantApariciones[tipoRandom - 1]++;
            fichas[i][j] = Ficha(tipoRandom, 200 * j + (j + 1) * 10, 200 * i + (i + 1) * 10);
            fichas[i][j].asignarTextura(textures[tipoRandom - 1]);
            fichas[i][j].bloquearSprite();
        }
    }
}

void Ventana::procesarEventos() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && cantDesbloqueada < 2 && !esperando) {
            if (descubiertas != 12 && tiempo.restante() >= 0) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (fichas[i][j].contiene(event.mouseButton.x, event.mouseButton.y) && !fichas[i][j].consultarEstado()) {
                            fichas[i][j].desbloquearSprite();
                            if (cantDesbloqueada == 0) {
                                iAnt = i; jAnt = j; cantDesbloqueada++;
                            } else if (fichas[i][j].consultarTipo() == fichas[iAnt][jAnt].consultarTipo()) {
                                fichas[i][j].descubrir();
                                fichas[iAnt][jAnt].descubrir();
                                descubiertas += 2;
                                puntaje.cambiar(15);
                                cantDesbloqueada = 0;
                            } else {
                                cantDesbloqueada++;
                                puntaje.cambiar(-5);
                                esperaClock.restart();
                                esperando = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Ventana::actualizar() {
    if (cantDesbloqueada == 2 && esperando && esperaClock.getElapsedTime() >= sf::seconds(1)) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                if (!fichas[i][j].consultarEstado())
                    fichas[i][j].bloquearSprite();
        cantDesbloqueada = 0;
        esperando = false;
    }
}

void Ventana::dibujar() {
    window.clear();
    window.draw(fondo);

    // Actualiza la interfaz con los valores actuales
    interfaz.setPuntos(puntaje.consultar());
    interfaz.setDescubiertas(descubiertas);
    interfaz.setTiempo(tiempo.restante());

    if (descubiertas != 12 && tiempo.restante() >= 0) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                window.draw(fichas[i][j]);
    }

    // Mensaje de resultado
    if (descubiertas == 12) {
        interfaz.setResultado("¡GANASTE!", sf::Color::Green);
    } else if (tiempo.restante() < 0) {
        interfaz.setResultado("¡PERDISTE!", sf::Color::Red);
    } else {
        interfaz.setResultado("", sf::Color::White); // Sin mensaje
    }

    window.draw(interfaz);
    window.display();
}

void Ventana::ejecutar() {
    while (window.isOpen()) {
        procesarEventos();
        actualizar();
        dibujar();
    }
}