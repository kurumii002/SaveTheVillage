#pragma once
#include "Personaje.h"

class Lider : public Personaje { //indica que es hijo de Character
private:
	int hp;
	int score;
	char direccion;

public:
	Lider(int width, int height, int hp) : Personaje(width, height) { //constructro del padre
		x = 50;
		y = 50;
		dx = dy = 15;
		direccion = 'S'; //direccion x defecto, mira abajo (S)
		this->hp = hp; //vidas
		score = 0;
	}

	~Lider() { };

	void mover(Graphics^ g, char i) { //para que el pj no se salga del form y el indice
		switch (i) {
		case 'A':
			if (x > 0) { //si hay esacio para mover a la izq
				x -= dx;
				idy = 1;
				direccion = 'A';
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) { //si hay esacio para mover a la DER
				x += dx;
				idy = 2; //sprite derecha
				direccion = 'D';
			}
			break;

		case 'W':
			if (y > 0) { //si hay esacio para mover a la DER
				y -= dy;
				idy = 3; //sprite arriba
				direccion = 'W';
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) { //es 1.0, pq se valida la imagen en 100%
				y += dy;
				idy = 0; //sprite arriba
				direccion = 'S';
			}
			break;
		}

		idx++;
		if (idx > 2)idx = 0;
	}

	int getHp() { return hp; }
	int getScore() { return score; }

	void incrementarScore(int v) { score += v; }
	void disminuirHp() { hp--; }

	char getDireccion() { return direccion; }
};
