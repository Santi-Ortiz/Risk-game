#include "TADTerritorio.h"
#include <iostream>
using namespace std;

string Territorio::getNombre()
{
  return nombre;
}

void Territorio::setNombre(string nombre)
{
  this->nombre = nombre;
}

bool Territorio::getEstadoTerritorio()
{
  return estadoTerritorio;
}

void Territorio::setEstadoTerritorio(bool estado)
{
  this->estadoTerritorio = estado;
}

int Territorio::getCantiUnidades()
{
  return cantiUnidades;
}

void Territorio::setCantiUnidades(int nUnidades)
{
  this->cantiUnidades = nUnidades;
}

void Territorio::setVecinos(vector<string> TVecino)
{
  std::vector<string>::iterator it;
  for (it = TVecino.begin(); it != TVecino.end(); it++)
  {
    vecinos.push_back(*it);
  }
}

vector<string> Territorio::getVecinos()
{
  return vecinos;
}

void Territorio::asignarTropasATerritorio(int nUnidades, Territorio t)
{
  t.cantiUnidades += nUnidades;
}
