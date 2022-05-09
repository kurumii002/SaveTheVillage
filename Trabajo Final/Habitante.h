#pragma once
#include"Personaje.h"

class Habitante : public Personaje {
private:
	int index;

public:
	Habitante(int width, int height, int index) : Personaje(width, height) {
		this->index = index;
		//this->x = x;
		//this->y = y;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
		dx = dy = 5; //desplazamiento despacio
	}

	void mover(Graphics^g) {
		switch (index) { //numero aleatorio entre el 0 y 1
		case 0: //mov horizontal
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0)dx *= -1; //SI CHOCA ALA DERECHA O LA IZQUIERA, ENTONCES CAMBIA DE MOVIMIENTO

			//si el dx es + se va la DER, si es - se va la IZQ
			if (dx > 0) {
				idy = 2; //sprite DER
			}
			else {
				idy = 1; //sprite IZQ
			}
			x += dx; //movimiento constante, AUTO
			break;

		case 1: //VERTICAL
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0)dy *= -1;

			if (dy > 0) {
				idy = 0; //sprite abajo
			}
			else { //entra en la otra direccion
				idy = 3; //sprite arriba
			}
			y += dy;
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}
};