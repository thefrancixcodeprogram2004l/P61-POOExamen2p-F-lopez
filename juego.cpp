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

    m_circulo->setY(m_circulo->getY()-1);

}


void Juego::on_btnAbajo_released()
{

    m_circulo->setY(m_circulo->getY()+1);

}


void Juego::on_btnIzqueirda_released()
{

    m_circulo->setX(m_circulo->getX()-1);

}


void Juego::on_btnDerecha_released()
{

    m_circulo->setX(m_circulo->getX()+1);

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
}

void Juego::on_marco_customContextMenuRequested(QPoint const&){

}
