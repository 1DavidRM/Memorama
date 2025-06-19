#include "../include/Ficha.hpp"
#include <iostream>

Ficha::Ficha() : tipo(0) {}

Ficha::Ficha(int tip, int x, int y) : tipo(tip) {
    sprite.setPosition(x, y);
    if (!textureBlock.loadFromFile("assets/0.png"))
        std::cout << "Error al cargar textura Block" << std::endl;
    bloquearSprite();
}

void Ficha::asignarTextura(const sf::Texture& tex) {
    texture = tex;
}

void Ficha::bloquearSprite() {
    sprite.setTexture(textureBlock);
}

void Ficha::desbloquearSprite() {
    sprite.setTexture(texture);
}

int Ficha::consultarTipo() const {
    return tipo;
}

bool Ficha::consultarEstado() const {
    return descubierta;
}

void Ficha::descubrir() {
    descubierta = true;
}

void Ficha::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
    rt.draw(sprite, rs);
}

bool Ficha::contiene(int x, int y) const {
    return sprite.getGlobalBounds().contains(x, y);
}