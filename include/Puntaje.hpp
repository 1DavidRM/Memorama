#pragma once

class Puntaje {
private:
    int puntos;
public:
    Puntaje();
    void cambiar(int mod);
    int consultar() const;
};