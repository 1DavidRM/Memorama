#include "../include/Tiempo.hpp"

Tiempo::Tiempo() { clock.restart(); }
void Tiempo::reiniciar() { clock.restart(); }
int Tiempo::restante() const { return 45 - static_cast<int>(clock.getElapsedTime().asSeconds()); }