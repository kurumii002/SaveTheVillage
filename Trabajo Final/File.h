#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite; //escribir dentro del archivo
	ifstream fileRead; //leer u obtener datos del archivo
	string text;

	//lo que se quiere guardar
	int time;
	int hp;

public:
	File() {}
	~File() {}

	void readData() {
		fileRead.open("config.txt", ios::in /* de afuera, para adentro. entrar al archivo*/); //busca el archivo y lo abre

		if (fileRead.fail()) { //si ha fallado la apertura del archivo
			fileRead.close(); //cierra

			//crea un nuevo archivo
			fileWrite.open("config.txt", ios::out /*de dentro, para afuera. entrar al archivo*/);
			fileWrite << "25" << endl; //25 segundos
			fileWrite << "3" << endl; //3 vidas x defecto

			fileRead.close();
			fileRead.open("config.txt", ios::in); //ahora si abre el archivo creado
		}

		//LEE TIEMPO
		getline(fileRead, text); //obtiene la 1ra linea del txt y lo pega en la variable text
		time = atoi(text.c_str()); //trnasforma el texto a int

		//LEE VIDAS
		getline(fileRead, text); 
		hp = atoi(text.c_str());

		fileRead.close();
	}

	int getTime() { return time; }
	int getHp() { return hp; }
};
