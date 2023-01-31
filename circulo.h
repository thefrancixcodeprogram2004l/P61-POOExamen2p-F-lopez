#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPoint>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

class Circulo : public QPoint
{
    int y=50;
    int x=50;
    int tamanio=50;
public:
    Circulo();
    Circulo(int xpos, int ypos, int size);
    int getTamanio() const;
    void setTamanio(int value);
    int getY() const;
    void setY(int value);
    int getX() const;
    void setX(int value);
    void getcolor(QColor);
};

#endif // CIRCULO_H
