#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion();

    const QColor &color() const;
    int dimension() const;

    void setColor(const QColor &newColor);
    void setDimension(int newDimension);
    QColor m_color;
    int m_dimension;

private slots:
    void on_btnColor_released();

    void on_btnColor_clicked();

    void on_inDimension_actionTriggered(int action);

private:
    Ui::Configuracion *ui;


    void setWidgetColor();
};

#endif // CONFIGURACION_H
