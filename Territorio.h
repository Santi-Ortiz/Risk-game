#ifndef __Territorio__
#define __Territorio__
#include <string>
#include <vector>
using namespace std;
class Territorio
{
private:
  string nombre;
  int cantiUnidades;
  vector<string> vecinos;
  bool estadoTerritorio;

public:
  string getNombre();
  void setNombre(string nombre);
  int getCantiUnidades();
  void setCantiUnidades(int nUnidades);
  void setVecinos(vector<string> TVecino);
  vector<string> getVecinos();
  void setEstadoTerritorio(bool estado);
  bool getEstadoTerritorio();

  void asignarTropasATerritorio(int nUnidades, Territorio t);
  void fortificarTerritorio(int nUnidades, Territorio t1, Territorio t2);
};

#endif