#pragma once
#include "Personaje.h"

class Bala : public Personaje { //hereda de caracter
private:
	char direccion; //direccion donde se va a disparar, w a s d

public:
	Bala(int width, int height, int x, int y, char direccion) : Personaje(width, height) {
		this->x = x;
		this->y = y;
		this->direccion = direccion;
		dx = dy = 10; //velocidad
	}

	~Bala() { };
	 
	void dibujar(Graphics^ g, Bitmap^ bmp) { 
		g->DrawImage(bmp, x, y, width * 0.2, height * 0.2); //que dibuje la bala en un menor tamaño (zoom)
	}

	void mover(Graphics^ g) {
		if (direccion == 'S' && y + height * 0.2 <= g->VisibleClipBounds.Height) {
			y += dy;
		}

		if (direccion == 'W' && y >= 0) {
			y -= dy;
		}

		if (direccion == 'D' && x + width * 0.2 <= g->VisibleClipBounds.Width) {
			x += dx;
		}

		if (direccion == 'A' && x >= 0) {
			x -= dx;
		}
	}

	Rectangle getRectangle() { //sobreescribe el metodo que devuelve el rectangulo de la bala, pero mas pequeño
		return Rectangle(x, y, width * 0.2, height * 0.2);
	}

	int getXWidth() { return x + width * 0.2; }
	int getYHeigth() { return y + height * 0.2; }

};
