#pragma once
#include<iostream>

using namespace System::Drawing;

class Personaje {
protected:
	int x, y; //coordenadas
	int dx, dy; //movimiento - desplazamiento
	int width, height; //ancho y alto
	int idx, idy; //indices
	bool visible; //indica si el pj esta en pantalla o existe, si es false ya no existe

public:
	Personaje(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true; //todos los pj se muestran
	}

	~Personaje() {}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		//Pen^ p = gcnew Pen(Color::Red, 3); //lapiz para dibujar el "rectangulo imaginario"

		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

		//g->DrawRectangle(p, x, y, width * 1.0, height * 1.0); //dibuja el rectangulo
	}

	//VIRTUAL: NO SE VA A IMPLEMENTAR EN LA CLASE PADRE, SINO EN LOS HIJOS
	virtual void mover() {}

	int getX() { return x; }
	int getY() { return y; }

	//SETTER: para cuando el heroe choque con el enemigo vuelva a la pos inicial
	void setX(int v) { x = v; }
	void setY(int v) { y = v; }

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	Rectangle getRectangle() { //metodo para obtener el rectangulo imaginario de un pj
		return Rectangle(x, y, width * 1.0, height * 1.0); //retorna el "rectangulo imaginario
	}
};