#include "TADCarta.h"
#include "TADRisk.h"

string Carta::getTipoCarta()
{
  return tipoCarta;
}

void Carta::setTipoCarta(string tipo_carta)
{
  this->tipoCarta = tipoCarta;
}

string Carta::getTerritorio()
{
  return Territorio;
}

void Carta::setTerritorio(string territorio)
{
  this->Territorio = Territorio;
}

Carta Carta::devolverCartaInfanteria(string territorio)
{
  Carta c;
  c.setTipoCarta("Infanteria");
  c.setTerritorio(territorio);
  return c;
}

Carta Carta::devolverCartaCaballeria(string territorio)
{
  Carta c;
  c.setTipoCarta("Caballeria");
  c.setTerritorio(territorio);
  return c;
}

Carta Carta::devolverCartaArtilleria(string territorio)
{
  Carta c;
  c.setTipoCarta("Artilleria");
  c.setTerritorio(territorio);
  return c;
}