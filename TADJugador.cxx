#include <iostream>
#include "TADJugador.h"
#include "TADTerritorio.h"
#include "TADRisk.h"
using namespace std;

Jugador::Jugador()
{
}

Jugador::Jugador(string id, int nUnidadesDisponibles, std::list<Territorio> listaTerritoriosConquistados, string color, list<Carta> manoCartas, bool estadoTurno)
{

  this->id = id;
  this->nUnidadesDisponibles = nUnidadesDisponibles;
  this->listaTerritoriosConquistados = listaTerritoriosConquistados;
  this->color = color;
  this->manoCartas = manoCartas;
  this->estadoTurno = false;
}

Jugador::Jugador(bool estadoTurno)
{
  this->estadoTurno = estadoTurno;
}

Jugador::~Jugador()
{
}

void Jugador::setId(string id)
{
  this->id = id;
}

std::string Jugador::getId()
{
  return id;
}

list<Territorio> Jugador::getTerritoriosConquistados()
{
  return listaTerritoriosConquistados;
}

void Jugador::setTerritoriosConquistados(Territorio T)
{
  std::list<Territorio>::iterator it;
  for (it = listaTerritoriosConquistados.begin(); it != listaTerritoriosConquistados.end(); it++)
  {
    std::cout << it->getNombre() << std::endl;
  }
  listaTerritoriosConquistados.push_back(T);
}

std::string Jugador::getColor()
{
  return color;
}

void Jugador::setColor(string color)
{
  this->color = color;
}

list<Carta> Jugador::getManoCartas()
{
  return manoCartas;
}

void Jugador::setManoCartas(Carta carta)
{
  manoCartas.push_back(carta);
  this->manoCartas = manoCartas;
}

void Jugador::setnUnidadesDisponibles(int nUnidadesDisponibles2)
{
  this->nUnidadesDisponibles = nUnidadesDisponibles2;
}

int Jugador::getnUnidadesDisponibles()
{
  return nUnidadesDisponibles;
}

bool Jugador::getEstadoTurno()
{
  return estadoTurno;
}

void Jugador::setEstadoTurno(bool estadoTurno)
{
  this->estadoTurno = estadoTurno;
}

void Jugador::setNTerritoriosConquistados(int n)
{

  for (int i = 0; i < n; i++)
  {
    Territorio territorio;
    listaTerritoriosConquistados.push_back(territorio);
  }
}

int Jugador::extraerNTerritoriosConquistados(std::list<Territorio> listaTerritoriosConquistados)
{
  return listaTerritoriosConquistados.size();
}

Jugador Jugador::crearJugador(string id)
{
  Jugador jugadorAux;
  jugadorAux.setId(id);
  jugadorAux.setnUnidadesDisponibles(0);
  return jugadorAux;
}

bool Jugador::saberTerritorioConquistado(Territorio T)
{
std:
  list<Territorio>::iterator it;
  bool estado = false;
  for (it = listaTerritoriosConquistados.begin(); it != listaTerritoriosConquistados.end(); it++)
  {
    if (it->getNombre() == T.getNombre())
    {
      estado = true;
      return estado;
    }
  }

  return estado;
}
