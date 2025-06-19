#include "../include/Interfaz.hpp"
#include <iostream>

Interfaz::Interfaz() : puntos(0), descubiertas(0), tiempoRestante(45) {
    if (!font.loadFromFile("assets/Oswald-Bold.ttf"))
        std::cout << "Error al cargar la fuente de texto" << std::endl;

    puntosText.setFont(font);
    descubiertasText.setFont(font);
    tiempoText.setFont(font);
    resultadoText.setFont(font);

    puntosText.setPosition(400, 685);
    descubiertasText.setPosition(715, 695);
    tiempoText.setPosition(30, 695);
    resultadoText.setPosition(300, 350);

    puntosText.setScale(1.5, 1.5);
    descubiertasText.setScale(1.25, 1.25);
    tiempoText.setScale(1.25, 1.25);
    resultadoText.setScale(2,2);

    actualizarTextos();
}

void Interfaz::setPuntos(int p) {
    puntos = p;
    actualizarTextos();
}

void Interfaz::setDescubiertas(int d) {
    descubiertas = d;
    actualizarTextos();
}

void Interfaz::setTiempo(int t) {
    tiempoRestante = t;
    actualizarTextos();
}

void Interfaz::setResultado(const std::string& msg, sf::Color color) {
    resultadoText.setString(msg);
    resultadoText.setFillColor(color);
}

void Interfaz::actualizarTextos() {
    puntosText.setString((puntos > 9 ? "" : "0") + std::to_string(puntos));
    descubiertasText.setString((descubiertas > 9 ? "" : "0") + std::to_string(descubiertas) + "/12");
    tiempoText.setString((tiempoRestante > 9 ? "" : "0") + std::to_string(std::max(0, tiempoRestante)));
}

void Interfaz::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
    rt.draw(puntosText, rs);
    rt.draw(descubiertasText, rs);
    rt.draw(tiempoText, rs);
    if (!resultadoText.getString().isEmpty())
        rt.draw(resultadoText, rs);
}