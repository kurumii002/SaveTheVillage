#pragma once
#include "Personaje.h"
#include "Aliado.h"

class Agente : public Personaje {
private:
	int index;

public:
	Agente(int width, int height, int index) : Personaje(width, height) {
		this->index = index;

		//posiciones aleatorias
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;

		dx = dy = 2; //desplazamiento lento
	}

	~Agente() {}

	void mover(Graphics^ g, Aliado* aliado) { //valida que no se salga de la pantalla

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

		case 2: //PERSECUCION
			//comparar al enemigo con las coordenadas del aliado
			if (x == aliado->getX()) {
				x += 0; //no se va a mover
			}
			else if (x > aliado->getX()) { //si el x es mayor, entonces resta hasta la coordenada x del heroe
				x -= dx;
				idy = 1;
			}
			else if (x < aliado->getX()) {
				x += dx;
				idy = 2;
			}

			if (y == aliado->getY()) {
				y += 0; //no se va a mover
			}
			else if (y > aliado->getY()) { //si el x es mayor, entonces resta hasta la coordenada x del heroe
				y -= dy;
				idy = 3; //sprite arriba
			}
			else if (y < aliado->getY()) {
				y += dy;
				idy = 0; //sprite abajo
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}

};
