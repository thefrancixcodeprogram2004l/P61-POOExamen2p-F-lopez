#include "juego.h"
#include "ui_juego.h"

#include <QPainter>
#include <QFileDialog>

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    m_circulo = new Circulo;
    ui->setupUi(this);
    miImagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    miImagen->fill(Qt::white);
    mPainter = new QPainter(miImagen);
    mPainter->setRenderHint(QPainter::Antialiasing);
    dibujar();

}

Juego::~Juego()
{
    delete ui;
    delete mPainter;
    delete miImagen;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // Dibujar la imagen
    painter.drawImage(0, 0, *miImagen);
}


void Juego::on_btnArriba_released()
{
    miImagen->fill(Qt::white);
    m_circulo->setY(m_circulo->getY()-1);
    dibujar();
}


void Juego::on_btnAbajo_released()
{
    miImagen->fill(Qt::white);
    m_circulo->setY(m_circulo->getY()+1);
    dibujar();
}


void Juego::on_btnIzqueirda_released()
{
    miImagen->fill(Qt::white);
    m_circulo->setX(m_circulo->getX()-1);
    dibujar();
}


void Juego::on_btnDerecha_released()
{
    miImagen->fill(Qt::white);
    m_circulo->setX(m_circulo->getX()+1);
    dibujar();

}

void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{
    Configuracion *color =new Configuracion(this);

    QPen pincel;
    pincel.setWidth(10);
    pincel.setColor(color->m_color);
    pincel.setJoinStyle(Qt::MiterJoin);
    pincel.setColor(color->m_color);
    pincel.setWidth(10);
    // Dibujar una linea
    mPainter->setPen(pincel);
    mPainter->drawEllipse(m_circulo->getX(), m_circulo->getY(), m_circulo->getTamanio(), m_circulo->getTamanio());
    update();
}

void Juego::on_marco_customContextMenuRequested(QPoint const&){
}
