#include "Continente.h"
#include "Territorio.h"
#include "Risk.h"
#include <list>
using namespace std;

std::string Continente::getNombre()
{
  return nombre;
}

void Continente::setNombre(string nombre)
{
  this->nombre = nombre;
}

list<Territorio> Continente::getListaTerritorio()
{
  return listaTerritorio;
}

void Continente::setListaTerritorio(list<Territorio> listT)
{
  std::list<Territorio>::iterator it;
  for (it = listT.begin(); it != listT.end(); it++)
  {
    listaTerritorio.push_back(*it);
  }
}

Continente Continente::crearContinente(string nombre)
{
  Continente c;
  c.setNombre(nombre);
  return c;
}
