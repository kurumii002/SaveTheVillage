#pragma once
#include <vector>
#include "Habitante.h"
#include "Lider.h"
#include "Agente.h"
#include "Bala.h"
#include "Aliado.h"

using namespace std;

class Controlador {
private:
	int time; //temporizador
	Lider* lider;
	vector<Habitante*> habitantes;
	vector<Agente*> agentes;
	vector<Bala*> balas;
	vector<Aliado*> aliados;

public:
	Controlador(Bitmap^ bmpLider, Bitmap^ bmpHabitante, Bitmap^ bmpAgente, Bitmap^ bmpAliado, int tiempo, int hp, int nenemies, int naliados) {
		this->time = tiempo;

		lider = new Lider(bmpLider->Width / 3, bmpLider->Height / 4, hp); //el ancho y el alto se saca de la imagen (bitmap)

		//HABITANTE
		for (int i = 0; i < 8; i++) {  //agrega 7 habitantes 
			habitantes.push_back(new Habitante(bmpHabitante->Width / 4, bmpHabitante->Height / 4, rand() % (1 - 0 + 1)));
		}

		//ALIADOS
		for (int i = 0; i < naliados; i++) { //agrega n aliados con movimientos diferentes
			aliados.push_back(new Aliado(bmpAliado->Width / 4, bmpAliado->Height / 4, 2));
		}

		//AGENTES
		for (int i = 0; i < nenemies; i++) { //agrega n agentes con movimientos diferentes (VER, HOR, PERSECUCION)
			agentes.push_back(new Agente(bmpAgente->Width / 4, bmpAgente->Height / 4, 2)); //numeros aleatorios entre 0 y 1
		}
		
	}

	~Controlador() {}

	void disparar(Bala* v) {
		balas.push_back(v);
	}

	void generarAliado(Aliado* a) {
		aliados.push_back(a);
	}

	void dibujarTodo(Graphics^ g, Bitmap^ bmpLider, Bitmap^ bmpHabitante, Bitmap^ bmpAgente, Bitmap^ bmpAliado, Bitmap^ bmpVacuna) {

		for each (Habitante * h in habitantes) { //recorre cada habitante y hace la misma accion para todos (dibujar)
			h->dibujar(g, bmpHabitante);
		}

		for each (Agente * a in agentes) { //recorre cada agente y hace la misma accion para todos (dibujar)
			a->dibujar(g, bmpAgente);
		}

		for each (Bala * v in balas) { //recorre cada bala y hace la misma accion para todos (dibujar)
			v->dibujar(g, bmpVacuna);
		}

		for each (Aliado * al in aliados) { //dibuja los aliados
			al->dibujar(g, bmpAliado);
		}

		lider->dibujar(g, bmpLider); //dibuja el lider
	}

	void moverTodo(Graphics^ g) { 

		for each (Habitante * h in habitantes) { //mueve los habitantes
			h->mover(g);
		}

		for (int i = 0; i < agentes.size(); i++) { //recorre el vector de agentes y le dice a cada uno que siga a cada aliado
			for (int j = 0; j < aliados.size(); j++) {
				agentes[i]->mover(g, aliados[j]); //se pasa el lider como arguemento para que lo persiga
				
			}
		}

		for (int i = 0; i < aliados.size(); i++) { //recorre el vector de aliados y le dice a cada uno que siga a cada habitante
			for (int j = 0; j < habitantes.size(); j++) {
				aliados[i]->mover(g, habitantes[j]);
			}
		}

		for each (Bala* v in balas) { //mueve las balas
			v->mover(g);
		}
	}

	Lider* getLider() { return lider; }

	void colision(Graphics^ g) {
		//verificar si el lider ha chocado con un agente
		//LIDER-AGENTE
		for (int i = 0; i < agentes.size(); i++) {
			if (lider->getRectangle().IntersectsWith(agentes[i]->getRectangle())) { //si el rectangulo del heroe se intersecta con el rectangulo del enemigo
				agentes[i]->setVisible(false);

				//si choca vuelve la pos inicial
				lider->setX(50);
				lider->setY(50);

				//disminuye la vida
				lider->disminuirHp();
			}
		}

		//BALAS-GRAPHIC
		for (int i = 0; i < balas.size(); i++) { //recorre el vector de balas
			if (balas[i]->getX() <= 0 || balas[i]->getXWidth() >= g->VisibleClipBounds.Width ||
				balas[i]->getY() <= 0 || balas[i]->getYHeigth() >= g->VisibleClipBounds.Height) { //pregunta si la balas esta en el borde limite
				balas[i]->setVisible(false);
			}
		}

		//AGENTES-BALAS
		for (int i = 0; i < agentes.size(); i++) { //recorre los agentes y las balas para comprobar la colision
			for (int j = 0; j < balas.size(); j++) {
				if (agentes[i]->getRectangle().IntersectsWith(balas[j]->getRectangle())) {
					agentes[i]->setVisible(false);
					balas[j]->setVisible(false);

					lider->incrementarScore(10);
				}
			}
		}

		//AGENTES-ALIADOS
		for (int i = 0; i < agentes.size(); i++) { //recorre los agentes y los aliados para comprobar la colision
			for (int j = 0; j < aliados.size(); j++) {
				if (agentes[i]->getRectangle().IntersectsWith(aliados[j]->getRectangle())) {
					aliados[j]->setVisible(false);

					lider->incrementarScore(-5); //baja 5 puntos
				}
			}
		}

		//ALIADOS-HABITANTES
		for (int i = 0; i < aliados.size(); i++) {
			for (int j = 0; j < habitantes.size(); j++) {
				if (aliados[i]->getRectangle().IntersectsWith(habitantes[j]->getRectangle())) {
					habitantes[j]->setVisible(false);
					aliados[i]->setVisible(false);

					lider->incrementarScore(10); //sube 10 puntos
				}
			}
		}

		//ELIMINACION
		for (int i = 0; i < agentes.size(); i++) {
			if (!agentes[i]->getVisible()) { //si el visible de un agente del vector de agentes es false
				agentes.erase(agentes.begin() + i); //agarra al vector de agentes, y elimina al agente con visible false de la posicion i
			}
		}

		for (int i = 0; i < balas.size(); i++) {
			if (!balas[i]->getVisible()) { //si el visible de una bala del vector de balas es false
				balas.erase(balas.begin() + i); //agarra la bala de balas, y elimina a la bala con visible false de la posicion i
			}
		}

		for (int i = 0; i < aliados.size(); i++) {
			if (!aliados[i]->getVisible()) {
				aliados.erase(aliados.begin() + i);
			}
		}

		for (int i = 0; i < habitantes.size(); i++) {
			if (!habitantes[i]->getVisible()) {
				habitantes.erase(habitantes.begin() + i);
			}
		}

	}

	int getTime() { return time; }
	void decreaseTime() { time--; }
};

