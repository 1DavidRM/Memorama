#pragma once
#include <SFML/Graphics.hpp>

class Ficha : public sf::Drawable {
private:
    sf::Texture texture, textureBlock;
    sf::Sprite sprite;
    bool descubierta = false;
    int tipo;
public:
    Ficha();
    Ficha(int tip, int x, int y);
    void asignarTextura(const sf::Texture& tex);
    void bloquearSprite();
    void desbloquearSprite();
    int consultarTipo() const;
    bool consultarEstado() const;
    void descubrir();
    virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override;
    bool contiene(int x, int y) const;
};