#ifndef __Carta__
#define __Carta__
#include <string>
using namespace std;
class Carta
{

private:
  string tipoCarta;
  string Territorio;

public:
  string getTipoCarta();
  void setTipoCarta(string tipo_carta);
  string getTerritorio();
  void setTerritorio(string territorio);
  Carta devolverCartaInfanteria(string territorio);
  Carta devolverCartaCaballeria(string territorio);
  Carta devolverCartaArtilleria(string territorio);
};

#endif