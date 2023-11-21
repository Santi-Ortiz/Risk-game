#ifndef __Continente__
#define __Continente__
#include "Territorio.h"
#include <string>
#include <list>
using namespace std;
class Continente
{
private:
	// Atributos
	string nombre;
	list<Territorio> listaTerritorio;

public:
	// Métodos
	string getNombre();
	void setNombre(string nombre);
	list<Territorio> &getListaTerritorio();
	void setListaTerritorio(list<Territorio> listT);
	Continente crearContinente(string nombre);
};

#endif