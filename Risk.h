#ifndef __Risk__
#define __Risk__
#include <list>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Territorio.h"
#include "Continente.h"
#include "Risk.h"

using namespace std;
class Risk
{
private:
  vector<Jugador> jugadoresActivos;
  Continente C1, C2, C3, C4, C5, C6;
  Territorio T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42;
  list<Territorio> G1, G2, G3, G4, G5, G6, lterritorios;
  list<list<Territorio>> territorios;
  list<Continente> continentes;

public:
  vector<Jugador> getjugadoresActivos();

  Continente getContinente1();
  Continente getContinente2();
  Continente getContinente3();
  Continente getContinente4();
  Continente getContinente5();
  Continente getContinente6();

  Territorio getTerritorio1();
  Territorio getTerritorio2();
  Territorio getTerritorio3();
  Territorio getTerritorio4();
  Territorio getTerritorio5();
  Territorio getTerritorio6();
  Territorio getTerritorio7();
  Territorio getTerritorio8();
  Territorio getTerritorio9();
  Territorio getTerritorio10();
  Territorio getTerritorio11();
  Territorio getTerritorio12();
  Territorio getTerritorio13();
  Territorio getTerritorio14();
  Territorio getTerritorio15();
  Territorio getTerritorio16();
  Territorio getTerritorio17();
  Territorio getTerritorio18();
  Territorio getTerritorio19();
  Territorio getTerritorio20();
  Territorio getTerritorio21();
  Territorio getTerritorio22();
  Territorio getTerritorio23();
  Territorio getTerritorio24();
  Territorio getTerritorio25();
  Territorio getTerritorio26();
  Territorio getTerritorio27();
  Territorio getTerritorio28();
  Territorio getTerritorio29();
  Territorio getTerritorio30();
  Territorio getTerritorio31();
  Territorio getTerritorio32();
  Territorio getTerritorio33();
  Territorio getTerritorio34();
  Territorio getTerritorio35();
  Territorio getTerritorio36();
  Territorio getTerritorio37();
  Territorio getTerritorio38();
  Territorio getTerritorio39();
  Territorio getTerritorio40();
  Territorio getTerritorio41();
  Territorio getTerritorio42();
  Territorio getTerritorios();

  list<Territorio> getListaTerritorio1();
  list<Territorio> getListaTerritorio2();
  list<Territorio> getListaTerritorio3();
  list<Territorio> getListaTerritorio4();
  list<Territorio> getListaTerritorio5();
  list<Territorio> getListaTerritorio6();

  list<Continente> getContinentes();
  void setNJugadoresActivos(int n);
  void setjugadorActivo(Jugador jugador);
  void setidActiva(string id);
  void setListaTerritorio1(list<Territorio> listaTerritorios, Territorio T);
  void setListaTerritorio2(list<Territorio> listaTerritorios, Territorio T);
  void setListaTerritorio3(list<Territorio> listaTerritorios, Territorio T);
  void setListaTerritorio4(list<Territorio> listaTerritorios, Territorio T);
  void setListaTerritorio5(list<Territorio> listaTerritorios, Territorio T);
  void setListaTerritorio6(list<Territorio> listaTerritorios, Territorio T);
  void setContinentes(Continente continente);
  vector<string> getidActivas();

  // Crear mapa
  bool crearJugadores();
  void crearTerritorios();
  void crearContinentes();
  void continentesAcontinente();
  void imprimirMapa();
  void imprimirVecinos(Territorio territorio);

  // Inicializar
  list<Territorio> actualizarTerritoriosDisponibles(list<Territorio> territoriosDisponibles, string nombre);
  list<Territorio> territoriosDisponibles();
  bool buscarTerritorio(string nombreTerritorio);
  bool territorioRepetido(string territorio);
  void asignarTerritoriosAContinente();
  bool asignarTerritoriosAJugador();
  int revisarTerritorioXContinente(Continente C, list<Territorio> listaTerritoriosConquistados);

  // Turno
  void pruebaJugadores();
  void inicializarTurno();
  bool turnoJugador(string jugador);
  bool obtenerUnidades(Jugador J);
  void adicionarUnidadesXTerritorio(Jugador J);
  void adicionarUnidadesXContinente(list<Territorio> listaTerritoriosConquistados);
  bool territorioPerteneciente(Jugador J1, string territorio);
  // void atacarTerritorio(vector<string> vecinos, Jugador J1, Jugador J2, Territorio T1, Territorio T2);
  bool atacarTerritorio(Territorio T1, Territorio T2, Jugador &J1, Jugador &J2);
  int dadosDefensor(Jugador J);
  int dadosAtacante(Jugador J);
  bool fortificarTerritorio(Jugador J, Territorio T1, Territorio T2, int nUnidades);
  void modosDeJuego(Jugador J1, Jugador J2, vector<string> vecinos);
  bool verificarVecinos(Territorio T1, Territorio T2);

  // Cartas
  int calcularUnidadesAdicionales(int nGrupos);
  void combinacionesCartasValidas(Jugador jugador);
  void verificarTerritoriosJugador(list<Carta> cartas);
  void adicionarUnidadesXCartas();
};

#endif