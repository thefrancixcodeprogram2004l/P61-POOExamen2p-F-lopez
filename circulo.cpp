#include "circulo.h"
Circulo::Circulo()
{}
Circulo::Circulo(int xpos, int ypos, int size):
    y(ypos),
    x(xpos),
    tamanio(size)
{}

int Circulo::getTamanio() const
{
    return tamanio;
}

void Circulo::setTamanio(int value)
{
    tamanio = value;
}

int Circulo::getY() const
{
    return y;
}

void Circulo::setY(int value)
{
    y = value;
}

int Circulo::getX() const
{
    return x;
}

void Circulo::setX(int value)
{
    x = value;
}




