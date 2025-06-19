#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Interfaz : public sf::Drawable {
private:
    int puntos;
    int descubiertas;
    int tiempoRestante;
    sf::Font font;
    sf::Text puntosText;
    sf::Text descubiertasText;
    sf::Text tiempoText;
    sf::Text resultadoText;
    void actualizarTextos();
public:
    Interfaz();
    void setPuntos(int p);
    void setDescubiertas(int d);
    void setTiempo(int t);
    void setResultado(const std::string& msg, sf::Color color);
    virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override;
};