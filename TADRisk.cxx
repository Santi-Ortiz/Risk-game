
#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include "TADRisk.h"
#include "TADJugador.h"
#include "TADTerritorio.h"
#include "TADContinente.h"
using namespace std;

//--------------------------------------------------------------------------------
//                             Getter & Setter
//--------------------------------------------------------------------------------

vector<Jugador> Risk::getjugadoresActivos()
{
  return jugadoresActivos;
}

Continente Risk::getContinente1()
{
  return C1;
}

Continente Risk::getContinente2()
{
  return C2;
}

Continente Risk::getContinente3()
{
  return C3;
}

Continente Risk::getContinente4()
{
  return C4;
}

Continente Risk::getContinente5()
{
  return C5;
}

Continente Risk::getContinente6()
{
  return C6;
}

Territorio Risk::getTerritorio1()
{
  return T1;
}

Territorio Risk::getTerritorio2()
{
  return T2;
}

Territorio Risk::getTerritorio3()
{
  return T3;
}

Territorio Risk::getTerritorio4()
{
  return T4;
}

Territorio Risk::getTerritorio5()
{
  return T5;
}

Territorio Risk::getTerritorio6()
{
  return T6;
}

Territorio Risk::getTerritorio7()
{
  return T7;
}

Territorio Risk::getTerritorio8()
{
  return T8;
}

Territorio Risk::getTerritorio9()
{
  return T9;
}

Territorio Risk::getTerritorio10()
{
  return T10;
}

Territorio Risk::getTerritorio11()
{
  return T11;
}

Territorio Risk::getTerritorio12()
{
  return T12;
}

Territorio Risk::getTerritorio13()
{
  return T13;
}

Territorio Risk::getTerritorio14()
{
  return T14;
}

Territorio Risk::getTerritorio15()
{
  return T15;
}

Territorio Risk::getTerritorio16()
{
  return T16;
}

Territorio Risk::getTerritorio17()
{
  return T17;
}

Territorio Risk::getTerritorio18()
{
  return T18;
}

Territorio Risk::getTerritorio19()
{
  return T19;
}

Territorio Risk::getTerritorio20()
{
  return T20;
}

Territorio Risk::getTerritorio21()
{
  return T21;
}

Territorio Risk::getTerritorio22()
{
  return T22;
}

Territorio Risk::getTerritorio23()
{
  return T23;
}

Territorio Risk::getTerritorio24()
{
  return T24;
}

Territorio Risk::getTerritorio25()
{
  return T25;
}

Territorio Risk::getTerritorio26()
{
  return T26;
}

Territorio Risk::getTerritorio27()
{
  return T27;
}

Territorio Risk::getTerritorio28()
{
  return T28;
}

Territorio Risk::getTerritorio29()
{
  return T29;
}

Territorio Risk::getTerritorio30()
{
  return T30;
}

Territorio Risk::getTerritorio31()
{
  return T31;
}

Territorio Risk::getTerritorio32()
{
  return T32;
}

Territorio Risk::getTerritorio33()
{
  return T33;
}

Territorio Risk::getTerritorio34()
{
  return T34;
}

Territorio Risk::getTerritorio35()
{
  return T35;
}

Territorio Risk::getTerritorio36()
{
  return T36;
}

Territorio Risk::getTerritorio37()
{
  return T37;
}

Territorio Risk::getTerritorio38()
{
  return T38;
}

Territorio Risk::getTerritorio39()
{
  return T39;
}

Territorio Risk::getTerritorio40()
{
  return T40;
}

Territorio Risk::getTerritorio41()
{
  return T41;
}

Territorio Risk::getTerritorio42()
{
  return T42;
}

/*
list<list<Territorio>> Risk::getContinentes()
{
  return continentes;
}
*/

list<Continente> Risk::getContinentes()
{
  return continentes;
}

void Risk::setNJugadoresActivos(int n)
{
  for (int i = 0; i < n; i++)
  {
    Jugador jugador;
    jugadoresActivos.push_back(jugador);
  }
}

void Risk::setjugadorActivo(Jugador jugador)
{
  jugadoresActivos.push_back(jugador);
  // this->jugadoresActivos = jugadoresActivos;
}

void Risk::setContinentes(Continente continente)
{
  continentes.push_back(continente);
}

//--------------------------------------------------------------------------------
//                             Creación del mapa
//--------------------------------------------------------------------------------
bool Risk::crearJugadores()
{

  vector<Jugador>::iterator it;
  int nJugadores = 0;
  bool status = true;
  std::cout << "Cuantos jugadores van a jugar?" << endl;
  cin >> nJugadores;
  cin.ignore();
  if (nJugadores > 6)
  {
    std::cout << "Muchos jugadores, 6 es el numero máximo de jugadores" << endl;
    status = false;
    return status;
  }
  else if (nJugadores <= 2)
  {
    std::cout << "Muy pocos jugadores, debe haber mas de dos" << endl;
    status = false;
    return status;
  }
  else
  {
    for (int i = 1; i <= nJugadores; i++)
    {
      string idAux = "", color = "";

      std::cout << "Cual es su id? Jugador: " << i << endl;
      cin >> idAux;
      std::cout << "Cual es su color? Jugador: " << i << endl;
      cin >> color;

      Jugador jugadorEntrada;

      jugadorEntrada.setId(idAux);
      jugadorEntrada.setnUnidadesDisponibles(0);
      jugadorEntrada.setEstadoTurno(false);
      jugadorEntrada.setColor(color);
      jugadoresActivos.push_back(jugadorEntrada);
    }
    int tropasAasignar;
    if (nJugadores == 3)
    {
      tropasAasignar = 35;
      for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
      {
        it->setnUnidadesDisponibles(tropasAasignar);
      }
    }
    else if (nJugadores == 4)
    {
      tropasAasignar = 30;
      for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
      {
        it->setnUnidadesDisponibles(tropasAasignar);
      }
    }
    else if (nJugadores == 5)
    {
      tropasAasignar = 25;
      for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
      {
        it->setnUnidadesDisponibles(tropasAasignar);
      }
    }
    else if (nJugadores == 6)
    {
      tropasAasignar = 20;
      for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
      {
        it->setnUnidadesDisponibles(tropasAasignar);
      }
    }
    else
    {
      std::cout << "No hay suficientes jugadores" << endl;
    }

    return status;
  }
}

void Risk::crearContinentes()
{
  C1.setNombre("America_del_norte");
  C2.setNombre("America_del_sur");
  C3.setNombre("Europa");
  C4.setNombre("Africa");
  C5.setNombre("Asia");
  C6.setNombre("Australia");
}

void Risk::crearTerritorios()
{
  vector<string> V1 = {"Alberta", "Territorio_Noroccidental", "Kamchatka"};
  vector<string> V2 = {"Alaska", "Territorio_Noroccidental", "Ontario", "Estados_Unidos_Occidentales"};
  vector<string> V3 = {"Estados_Unidos_Orientales", "Estados_Unidos_Occidentales", "Venezuela"};
  vector<string> V4 = {"America_Central", "Ontario", "Quebec", "Estados_Unidos_Occidentales"};
  vector<string> V5 = {"Territorio_Noroccidental", "Ontario", "Quebec", "Islandia"};
  vector<string> V6 = {"Alaska", "Alberta", "Ontario", "Groenlandia"};
  vector<string> V7 = {"Alberta", "Estados_Unidos_Orientales", "Groenlandia", "Territorio_Noroccidental", "Quebec"};
  vector<string> V8 = {"Estados_Unidos_Orientales", "Groenlandia", "Ontario"};
  vector<string> V9 = {"Alberta", "America_Central", "Estados_Unidos_Orientales"};
  vector<string> V10 = {"Brasil", "Peru"};
  vector<string> V11 = {"Argentina", "Peru", "Venezuela", "Africa_del_Norte"};
  vector<string> V12 = {"Argentina", "Brasil", "Venezuela"};
  vector<string> V13 = {"America_Central", "Brasil", "Peru"};
  vector<string> V14 = {"Islandia", "Europa_Del_Norte", "Escandinavia", "Europa_Occidental"};
  vector<string> V15 = {"Groenlandia", "Gran_Bretana", "Escandinavia"};
  vector<string> V16 = {"Gran_Bretana", "Escandinavia", "Europa_Del_Sur", "Ucrania", "Europa_Occidental"};
  vector<string> V17 = {"Gran_Bretana", "Islandia", "Europa_Del_Norte", "Ucrania"};
  vector<string> V18 = {"Egipto", "Africa_del_Norte", "Medio_Oriente", "Europa_Del_Norte", "Ucrania", "Europa_Occidental"};
  vector<string> V19 = {"Medio_Oriente", "Afghanistan", "Ural", "Europa_Del_Norte", "Escandinavia", "Europa_Del_Sur"};
  vector<string> V20 = {"Africa_del_Norte", "Gran_Bretana", "Europa_Del_Norte", "Europa_Del_Sur"};
  vector<string> V21 = {"Africa_del_Norte", "Africa Oriental", "Africa del Sur"};
  vector<string> V22 = {"Congo", "Egipto", "Madagascar", "Africa_del_Norte", "Africa del Sur"};
  vector<string> V23 = {"Europa_Del_Sur", "Medio_Oriente", "Africa_del_Norte", "Africa Oriental"};
  vector<string> V24 = {"Africa Oriental", "Africa del Sur"};
  vector<string> V25 = {"Brasil", "Europa_Occidental", "Europa_Del_Sur", "Egipto", "Africa Oriental", "Congo"};
  vector<string> V26 = {"Congo", "Africa Oriental", "Madagascar"};
  vector<string> V27 = {"Ucrania", "Ural", "China", "India", "Medio_Oriente"};
  vector<string> V28 = {"Siam", "India", "Afghanistan", "Ural", "Siberia", "Mongolia"};
  vector<string> V29 = {"Medio_Oriente", "Afghanistan", "China", "Siam"};
  vector<string> V30 = {"Siberia", "Yakutsk", "Kamchatka", "Mongolia"};
  vector<string> V31 = {"Kamchatka", "Mongolia"};
  vector<string> V32 = {"Alaska", "Yakutsk", "Irkutsk", "Mongolia", "Japon"};
  vector<string> V33 = {"Egipto", "Europa_Del_Sur", "Ucrania", "Afghanistan", "India"};
  vector<string> V34 = {"China", "Irkutsk", "Japon", "Kamchatka", "Siberia"};
  vector<string> V35 = {"Indonesia", "China", "India"};
  vector<string> V36 = {"China", "Irkutsk", "Mongolia", "Ural", "Yakutsk"};
  vector<string> V37 = {"Afghanistan", "China", "Siberia", "Ucrania"};
  vector<string> V38 = {"Siberia", "Irkutsk", "Kamchatka"};
  vector<string> V39 = {"Nueva_Guinea", "Australia_Occidental"};
  vector<string> V40 = {"Siam", "Australia_Oriental", "Nueva_Guinea", "Australia_Occidental"};
  vector<string> V41 = {"Australia_Oriental", "Indonesia", "Australia_Occidental"};
  vector<string> V42 = {"Australia_Oriental", "Indonesia", "Nueva_Guinea"};

  T1.setNombre("Alaska");
  T1.setVecinos(V1);
  T1.setEstadoTerritorio(false);
  T1.setCantiUnidades(0);

  T2.setNombre("Alberta");
  T2.setVecinos(V2);
  T2.setEstadoTerritorio(false);
  T2.setCantiUnidades(0);

  T3.setNombre("America_Central");
  T3.setVecinos(V3);
  T3.setEstadoTerritorio(false);
  T3.setCantiUnidades(0);

  T4.setNombre("Estados_Unidos_Orientales");
  T4.setVecinos(V4);
  T4.setEstadoTerritorio(false);
  T4.setCantiUnidades(0);

  T5.setNombre("Groenlandia");
  T5.setVecinos(V5);
  T5.setEstadoTerritorio(false);
  T5.setCantiUnidades(0);

  T6.setNombre("Territorio_Noroccidental");
  T6.setVecinos(V6);
  T6.setEstadoTerritorio(false);
  T6.setCantiUnidades(0);

  T7.setNombre("Ontario");
  T7.setVecinos(V7);
  T7.setEstadoTerritorio(false);
  T7.setCantiUnidades(0);

  T8.setNombre("Quebec");
  T8.setVecinos(V8);
  T8.setEstadoTerritorio(false);
  T8.setCantiUnidades(0);

  T9.setNombre("Estados_Unidos_Occidentales");
  T9.setVecinos(V9);
  T9.setEstadoTerritorio(false);
  T9.setCantiUnidades(0);

  T10.setNombre("Argentina");
  T10.setVecinos(V10);
  T10.setEstadoTerritorio(false);
  T10.setCantiUnidades(0);

  T11.setNombre("Brasil");
  T11.setVecinos(V11);
  T11.setEstadoTerritorio(false);
  T11.setCantiUnidades(0);

  T12.setNombre("Peru");
  T12.setVecinos(V12);
  T12.setEstadoTerritorio(false);
  T12.setCantiUnidades(0);

  T13.setNombre("Venezuela");
  T13.setVecinos(V13);
  T13.setEstadoTerritorio(false);
  T13.setCantiUnidades(0);

  T14.setNombre("Gran_Bretana");
  T14.setVecinos(V14);
  T14.setEstadoTerritorio(false);
  T14.setCantiUnidades(0);

  T15.setNombre("Islandia");
  T15.setVecinos(V15);
  T15.setEstadoTerritorio(false);
  T15.setCantiUnidades(0);

  T16.setNombre("Europa_del_Norte");
  T16.setVecinos(V16);
  T16.setEstadoTerritorio(false);
  T16.setCantiUnidades(0);

  T17.setNombre("Escandinavia");
  T17.setVecinos(V17);
  T17.setEstadoTerritorio(false);
  T17.setCantiUnidades(0);

  T18.setNombre("Europa_del_Sur");
  T18.setVecinos(V18);
  T18.setEstadoTerritorio(false);
  T18.setCantiUnidades(0);

  T19.setNombre("Ucrania");
  T19.setVecinos(V19);
  T19.setEstadoTerritorio(false);
  T19.setCantiUnidades(0);

  T20.setNombre("Europa_Occidental");
  T20.setVecinos(V20);
  T20.setEstadoTerritorio(false);
  T20.setCantiUnidades(0);

  T21.setNombre("Congo");
  T21.setVecinos(V21);
  T21.setEstadoTerritorio(false);
  T21.setCantiUnidades(0);

  T22.setNombre("Africa_Oriental");
  T22.setVecinos(V22);
  T22.setEstadoTerritorio(false);
  T22.setCantiUnidades(0);

  T23.setNombre("Egipto");
  T23.setVecinos(V23);
  T23.setEstadoTerritorio(false);
  T23.setCantiUnidades(0);

  T24.setNombre("Madagascar");
  T24.setVecinos(V24);
  T24.setEstadoTerritorio(false);
  T24.setCantiUnidades(0);

  T25.setNombre("Africa_del_Norte");
  T25.setVecinos(V25);
  T25.setEstadoTerritorio(false);
  T25.setCantiUnidades(0);

  T26.setNombre("Africa_del_Sur");
  T26.setVecinos(V26);
  T26.setEstadoTerritorio(false);
  T26.setCantiUnidades(0);

  T27.setNombre("Afghanistan");
  T27.setVecinos(V27);
  T27.setEstadoTerritorio(false);
  T27.setCantiUnidades(0);

  T28.setNombre("China");
  T28.setVecinos(V28);
  T28.setEstadoTerritorio(false);
  T28.setCantiUnidades(0);

  T29.setNombre("India");
  T29.setVecinos(V29);
  T29.setEstadoTerritorio(false);
  T29.setCantiUnidades(0);

  T30.setNombre("Irkutsk");
  T30.setVecinos(V30);
  T30.setEstadoTerritorio(false);
  T30.setCantiUnidades(0);

  T31.setNombre("Japon");
  T31.setVecinos(V31);
  T31.setEstadoTerritorio(false);
  T31.setCantiUnidades(0);

  T32.setNombre("Kamchatka");
  T32.setVecinos(V32);
  T32.setEstadoTerritorio(false);
  T32.setCantiUnidades(0);

  T33.setNombre("Medio_Oriente");
  T33.setVecinos(V33);
  T33.setEstadoTerritorio(false);
  T33.setCantiUnidades(0);

  T34.setNombre("Mongolia");
  T34.setVecinos(V34);
  T34.setEstadoTerritorio(false);
  T34.setCantiUnidades(0);

  T35.setNombre("Siam");
  T35.setVecinos(V35);
  T35.setEstadoTerritorio(false);
  T35.setCantiUnidades(0);

  T36.setNombre("Siberia");
  T36.setVecinos(V36);
  T36.setEstadoTerritorio(false);
  T36.setCantiUnidades(0);

  T37.setNombre("Ural");
  T37.setVecinos(V37);
  T37.setEstadoTerritorio(false);
  T37.setCantiUnidades(0);

  T38.setNombre("Yakutsk");
  T38.setVecinos(V38);
  T38.setEstadoTerritorio(false);
  T38.setCantiUnidades(0);

  T39.setNombre("Australia_Oriental");
  T39.setVecinos(V39);
  T39.setEstadoTerritorio(false);
  T39.setCantiUnidades(0);

  T40.setNombre("Indonesia");
  T40.setVecinos(V40);
  T40.setEstadoTerritorio(false);
  T40.setCantiUnidades(0);

  T41.setNombre("Nueva_Guinea");
  T41.setVecinos(V41);
  T41.setEstadoTerritorio(false);
  T41.setCantiUnidades(0);

  T42.setNombre("Australia_Occidental");
  T42.setVecinos(V42);
  T42.setEstadoTerritorio(false);
  T42.setCantiUnidades(0);

  G1.push_back(T1);
  G1.push_back(T2);
  G1.push_back(T3);
  G1.push_back(T4);
  G1.push_back(T5);
  G1.push_back(T6);
  G1.push_back(T7);
  G1.push_back(T8);
  G1.push_back(T9);

  G2.push_back(T10);
  G2.push_back(T11);
  G2.push_back(T12);
  G2.push_back(T13);

  G3.push_back(T14);
  G3.push_back(T15);
  G3.push_back(T16);
  G3.push_back(T17);
  G3.push_back(T18);
  G3.push_back(T19);
  G3.push_back(T20);

  G4.push_back(T20);
  G4.push_back(T21);
  G4.push_back(T22);
  G4.push_back(T23);
  G4.push_back(T24);
  G4.push_back(T25);
  G4.push_back(T26);

  G5.push_back(T27);
  G5.push_back(T28);
  G5.push_back(T29);
  G5.push_back(T30);
  G5.push_back(T31);
  G5.push_back(T32);
  G5.push_back(T33);
  G5.push_back(T34);
  G5.push_back(T35);
  G5.push_back(T36);
  G5.push_back(T37);
  G5.push_back(T38);

  G6.push_back(T39);
  G6.push_back(T40);
  G6.push_back(T41);
  G6.push_back(T42);

  territorios.push_back(G1);
  territorios.push_back(G2);
  territorios.push_back(G3);
  territorios.push_back(G4);
  territorios.push_back(G5);
  territorios.push_back(G6);
}

void Risk::continentesAcontinente()
{
  setContinentes(C1);
  setContinentes(C2);
  setContinentes(C3);
  setContinentes(C4);
  setContinentes(C5);
  setContinentes(C6);
}

void Risk::imprimirMapa()
{
  std::list<Continente>::iterator it;
  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::cout << "\nContinente: " << it->getNombre() << endl;
    std::cout << "----------------------" << endl;
    std::list<Territorio>::iterator it2;
    std::list<Territorio> territorios = it->getListaTerritorio();
    std::cout << "Cantidad de territorios: " << it->getListaTerritorio().size() << endl
              << endl;
    for (it2 = territorios.begin(); it2 != territorios.end(); it2++)
    {
      std::cout << "- " << it2->getNombre() << endl;
    }
  }
}

void Risk::imprimirVecinos(Territorio territorio)
{
  std::list<Continente>::iterator it;
  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio>::iterator it2;
    std::list<Territorio> territorios = it->getListaTerritorio();
    for (it2 = territorios.begin(); it2 != territorios.end(); it2++)
    {
      if (it2->getNombre() == territorio.getNombre())
      {
        std::vector<string> vecinos = it2->getVecinos();
        std::vector<string>::iterator it3;
        std::cout << "Vecinos: ";
        for (it3 = vecinos.begin(); it3 != vecinos.end(); it3++)
        {
          std::cout << *it3 << ", ";
        }
        std::cout << endl;
      }
    }
  }
}
//--------------------------------------------------------------------------------
//                             Inicializar
//--------------------------------------------------------------------------------

list<Territorio> Risk::territoriosDisponibles()
{
  std::list<Continente>::iterator it;
  std::list<Territorio> listAux;
  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio>::iterator it2;
    std::list<Territorio> territorios = it->getListaTerritorio();
    for (it2 = territorios.begin(); it2 != territorios.end(); it2++)
    {
      if (!it2->getEstadoTerritorio())
      {
        listAux.push_back(*it2);
      }
    }
  }

  return listAux;
}

bool Risk::buscarTerritorio(string nombreTerritorio)
{
  std::list<Continente>::iterator it;
  std::list<Territorio>::iterator it2;
  std::list<Territorio> listAux;

  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio> territorios = it->getListaTerritorio();
    for (it2 = territorios.begin(); it2 != territorios.end(); it2++)
    {
      if (it2->getNombre() == nombreTerritorio)
      {
        std::cout << "\nEl territorio: " << nombreTerritorio << " existe." << endl;
        return true;
      }
    }
  }
  std::cout << "\nEl territorio NO existe." << endl;
  return false;
}

bool Risk::territorioRepetido(string nombreTerritorio)
{
  std::list<Continente>::iterator it;
  std::list<Territorio>::iterator it2;
  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio> territorios = it->getListaTerritorio();
    for (it2 = territorios.begin(); it2 != territorios.end(); it2++)
    {
      if (it2->getNombre() == nombreTerritorio)
      {
        if (it2->getEstadoTerritorio() == true)
        {
          std::cout << "El territorio: " << nombreTerritorio << " ya se encuentra conquistado." << endl;
          return true;
        }
      }
    }
  }
  return false;
}

bool Risk::asignarTerritoriosAJugador()
{
  std::vector<Jugador>::iterator it;
  std::list<Continente>::iterator it2;
  std::list<Territorio>::iterator it3;
  string territorioElegido;

  for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
  {
    do
    {
      std::cout << "\nEn cual territorio desea empezar? Jugador: " << it->getId() << endl;
      cin >> territorioElegido;
    } while (!buscarTerritorio(territorioElegido) && !territorioRepetido(territorioElegido)); // Agregar territorio repetido

    for (it2 = continentes.begin(); it2 != continentes.end(); it2++)
    {
      std::list<Territorio> territorios = it2->getListaTerritorio();
      for (it3 = territorios.begin(); it3 != territorios.end(); it3++)
      {
        if (territorioElegido == it3->getNombre())
        {
          if (jugadoresActivos.size() == 3)
          {
            Carta carta;
            for (int i = 0; i < 35; i++)
              it->setManoCartas(carta.devolverCartaInfanteria(it3->getNombre()));
          }
          else if (jugadoresActivos.size() == 4)
          {
            Carta carta;
            for (int i = 0; i < 30; i++)
              it->setManoCartas(carta.devolverCartaInfanteria(it3->getNombre()));
          }
          else if (jugadoresActivos.size() == 5)
          {
            Carta carta;
            for (int i = 0; i < 25; i++)
              it->setManoCartas(carta.devolverCartaInfanteria(it3->getNombre()));
          }
          else if (jugadoresActivos.size() == 6)
          {
            Carta carta;
            for (int i = 0; i < 20; i++)
              it->setManoCartas(carta.devolverCartaInfanteria(it3->getNombre()));
          }

          it3->setEstadoTerritorio(true);
          it->setTerritoriosConquistados(*it3);
          it3->setCantiUnidades(it->getnUnidadesDisponibles());
          std::cout << "Unidades disponibles en territorio " << it3->getNombre() << " :" << it3->getCantiUnidades() << endl;
          // actualizarTerritoriosDisponibles(lterritorios, it2->getNombre());
          std::cout << "\n------------------------------------------" << endl;
          std::cout << "Territorio: " << it3->getNombre() << " ,con estado: " << it3->getEstadoTerritorio() << ",agregado al jugador: " << it->getId() << endl;
          std::cout << "El jugador " << it->getId() << " tiene: " << it->extraerNTerritoriosConquistados(it->getTerritoriosConquistados()) << " territorio(s) conquistados" << endl;
          std::cout << "El jugador " << it->getId() << " tiene: " << it->getManoCartas().size() << " cartas" << endl;
          std::cout << "------------------------------------------" << endl;
        }
      }
    }
  }
  return false;
}

bool Risk::territorioPerteneciente(Jugador J1, string territorio)
{

  std::vector<Jugador>::iterator it;
  std::list<Territorio>::iterator it2;
  std::list<Territorio> T;

  for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
  {
    T = it->getTerritoriosConquistados();
    for (it2 = T.begin(); it2 != T.end(); it2++)
    {
      if (it->getId() == J1.getId())
      {
        if (it2->getNombre() == territorio)
        {
          std::cout << "El territorio " << territorio << " pertenece al jugador: " << it->getId() << endl;
          return true;
        }
      }
    }
  }
  return false;
}

void Risk::adicionarUnidadesXTerritorio(Jugador jugador)
{
  std::vector<Jugador>::iterator it;
  std::list<Territorio>::iterator it2;
  std::list<Territorio>::iterator itTerritorio;
  std::list<Territorio> T;

  string nombreTerritorio;
  int unidades = 0, numeroTerritorios = 0, nUnidadesAPasar = 0;

  std::cout << "------------------------------------------" << endl;
  for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
  {
    if (it->getId() == jugador.getId())
    {

      std::cout << "El jugador " << it->getId() << " tiene: " << endl;
      T = it->getTerritoriosConquistados();
      for (itTerritorio = T.begin(); itTerritorio != T.end(); itTerritorio++)
      {
        std::cout << "- " << itTerritorio->getNombre() << endl;
        imprimirVecinos(*itTerritorio);
      }
      // Extrae el número de territorios que tiene conquistado el jugador
      numeroTerritorios = it->extraerNTerritoriosConquistados(it->getTerritoriosConquistados());

      unidades = numeroTerritorios / 3;
      std::cout << "Puede reclamar " << unidades << " unidades adicionales." << endl;
      it->setnUnidadesDisponibles(it->getnUnidadesDisponibles() + unidades);
      std::cout << "Unidades disponibles: " << it->getnUnidadesDisponibles() << endl;

      if (unidades > 0)
      {
        do
        {
          std::cout << "A que territorio desea anadir unidades?" << endl;
          cin >> nombreTerritorio;
        } while (!buscarTerritorio(nombreTerritorio) && !territorioPerteneciente(jugador, nombreTerritorio));

        std::list<Territorio> lterritorios;
        lterritorios = it->getTerritoriosConquistados();
        for (it2 = lterritorios.begin(); it2 != lterritorios.end(); it2++)
        {
          if (it2->getNombre() == nombreTerritorio)
          {
            std::cout << "Cuantas unidades desea pasar a: " << nombreTerritorio << " ?" << endl;
            cin >> nUnidadesAPasar;
            it2->asignarTropasATerritorio(nUnidadesAPasar, *it2);
          }
        }
      }
      else if (unidades <= 0)
      {
        std::cout << "No se pueden adicionar tropas debido a que no tiene disponibles." << endl;
      }
    }
  }
  std::cout << "------------------------------------------" << endl;
}

int Risk::revisarTerritorioXContinente(Continente C, list<Territorio> listaTerritoriosConquistados)
{
  std::list<Territorio>::iterator it;
  std::list<Territorio>::iterator it2;
  std::list<Territorio> T = C.getListaTerritorio();
  int counter = 0;

  for (it = T.begin(); it != T.end(); it++)
  {
    for (it2 = listaTerritoriosConquistados.begin(); it2 != listaTerritoriosConquistados.end(); it2++)
    {
      if (it2->getNombre() == it->getNombre())
      {
        counter++;
      }
    }
  }
  return counter;
}

void Risk::adicionarUnidadesXContinente(list<Territorio> listaTerritoriosConquistados)
{
  std::vector<Jugador>::iterator it;
  std::list<Territorio>::iterator it2;
  int c1, c2, c3, c4, c5, c6;

  for (it = jugadoresActivos.begin(); it != jugadoresActivos.end(); it++)
  {
    for (it2 = listaTerritoriosConquistados.begin(); it2 != listaTerritoriosConquistados.end(); it2++)
    {

      c1 = revisarTerritorioXContinente(C1, listaTerritoriosConquistados);
      c2 = revisarTerritorioXContinente(C2, listaTerritoriosConquistados);
      c3 = revisarTerritorioXContinente(C3, listaTerritoriosConquistados);
      c4 = revisarTerritorioXContinente(C4, listaTerritoriosConquistados);
      c5 = revisarTerritorioXContinente(C5, listaTerritoriosConquistados);
      c6 = revisarTerritorioXContinente(C6, listaTerritoriosConquistados);

      if (c2 == C2.getListaTerritorio().size() || c6 == C6.getListaTerritorio().size())
      {
        it->setnUnidadesDisponibles(it->getnUnidadesDisponibles() + 2);
        std::cout << "2 unidades adicionales por tener conquistado: " << C2.getNombre() << " o " << C6.getNombre() << endl;
      }
      if (c4 == C4.getListaTerritorio().size())
      {
        it->setnUnidadesDisponibles(it->getnUnidadesDisponibles() + 3);
        std::cout << "3 unidades adicionales por tener conquistado: " << C4.getNombre() << endl;
      }
      if (c1 == C1.getListaTerritorio().size() || c3 == C3.getListaTerritorio().size())
      {
        it->setnUnidadesDisponibles(it->getnUnidadesDisponibles() + 5);
        std::cout << "5 unidades adicionales por tener conquistado: " << C1.getNombre() << " o " << C3.getNombre() << endl;
      }
      if (c5 == C5.getListaTerritorio().size())
      {
        it->setnUnidadesDisponibles(it->getnUnidadesDisponibles() + 7);
        std::cout << "7 unidades adicionales por tener conquistado: " << C5.getNombre() << endl;
      }
    }
  }
}

//--------------------------------------------------------------------------------

int Risk::calcularUnidadesAdicionales(int nGrupos)
{
  int unidadesBase = 4;       // Unidades base para el primer grupo
  int incrementoUnidades = 2; // Incremento de unidades por cada grupo adicional
  return unidadesBase + (nGrupos - 1) * incrementoUnidades;
}

void Risk::combinacionesCartasValidas(Jugador jugador)
{
  // Verifica si las combinaciones de las cartas son válidas para el intercambio de unidades
}

void Risk::verificarTerritoriosJugador(list<Carta> cartas)
{
  // verifica si las cartas incluyen territorios ocupados por el jugador
}

void Risk::adicionarUnidadesXCartas()
{
}

//--------------------------------------------------------------------------------

void Risk::asignarTerritoriosAContinente()
{
  C1.setListaTerritorio(G1);
  C2.setListaTerritorio(G2);
  C3.setListaTerritorio(G3);
  C4.setListaTerritorio(G4);
  C5.setListaTerritorio(G5);
  C6.setListaTerritorio(G6);
}

list<Territorio> Risk::actualizarTerritoriosDisponibles(list<Territorio> territoriosDisponibles, string nombre)
{
  std::list<Territorio>::iterator it;
  std::list<Territorio> listAux = territoriosDisponibles;
  for (it = listAux.begin(); it != listAux.end(); it++)
  {
    if (nombre == it->getNombre())
    {
      it = listAux.erase(it);
    }
  }
  return listAux;
}

//--------------------------------------------------------------------------------
//                             Turno
//--------------------------------------------------------------------------------

void Risk::inicializarTurno()
{
  jugadoresActivos[0].setEstadoTurno(true);
}

bool Risk::turnoJugador(string jugador)
{
  bool status = false;
  int numJugadores = jugadoresActivos.size();

  for (int i = 0; i < numJugadores; i++)
  {
    int indice = i % numJugadores;
    if (jugadoresActivos[indice].getId() == jugador && jugadoresActivos[indice].getEstadoTurno())
    {
      cout << "\n------------------------------------------";
      status = true;
      jugadoresActivos[indice].setEstadoTurno(false);
      std::cout << "\nTurno del jugador: " << jugadoresActivos[indice].getId() << endl;
      if (indice == numJugadores - 1)
      {
        jugadoresActivos[0].setEstadoTurno(true);
        std::cout << "Siguiente jugador: " << jugadoresActivos[0].getId() << endl;
      }
      else
      {
        jugadoresActivos[indice + 1].setEstadoTurno(true);
        std::cout << "Siguiente jugador: " << jugadoresActivos[indice + 1].getId() << endl;
      }
      cout << "------------------------------------------" << endl
           << endl;

      return status;
    }
  }
  cout << "\n------------------------------------------" << endl;
  std::cout << "No es el turno del jugador: " << jugador << endl;
  cout << "------------------------------------------" << endl;
  return status;
}

bool Risk::obtenerUnidades(Jugador J)
{
  adicionarUnidadesXTerritorio(J);
  adicionarUnidadesXContinente(J.getTerritoriosConquistados());
  return true;
}

int Risk::dadosDefensor(Jugador J)
{
  int resultadoDado = 0;
  for (int i = 0; i < 2; i++)
  {
    resultadoDado = rand() % 6 + 1;
  }
  return resultadoDado;
}

int Risk::dadosAtacante(Jugador J)
{
  int resultadoDado = 0;
  for (int i = 0; i < 3; i++)
  {
    resultadoDado = rand() % 6 + 1;
  }
  return resultadoDado;
}

bool Risk::verificarVecinos(Territorio T1, Territorio T2)
{
  std::list<Continente>::iterator it;
  std::list<Territorio>::iterator it2;
  std::vector<string>::iterator it3;

  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio> lterritorios = it->getListaTerritorio();
    for (it2 = lterritorios.begin(); it2 != lterritorios.end(); it2++)
    {
      if (it2->getNombre() == T1.getNombre())
      {
        std::vector<string> lvecinosT1 = it2->getVecinos();
        for (it3 = lvecinosT1.begin(); it3 != lvecinosT1.end(); it3++)
        {
          if (*it3 == T2.getNombre())
          {
            std::cout << "El territorio " << T2.getNombre() << " es vecino de: " << T1.getNombre() << endl;
            return true;
          }
        }
      }
    }
  }
  std::cout << "El territorio " << T2.getNombre() << " NO es vecino de: " << T1.getNombre() << endl;
  return false;
}

bool Risk::atacarTerritorio(Territorio T1, Territorio T2, Jugador &J1, Jugador &J2)
{
  std::list<Continente>::iterator it;
  std::list<Territorio>::iterator it2, it3;
  bool A1 = false, A2 = false;
  Territorio Atacante, Atacado;
  int resulAtacante[3], resulDefensor[2], perdidasAtacante = 0, perdidasDefensor = 0;

  // Buscar los territorios en la lista de territorios
  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio> lterritoriosAtacado = it->getListaTerritorio();
    for (it2 = lterritoriosAtacado.begin(); it2 != lterritoriosAtacado.end(); it2++)
    {
      std::list<Territorio> lterritoriosAtacante = it->getListaTerritorio();
      for (it3 = lterritoriosAtacante.begin(); it3 != lterritoriosAtacante.end(); it3++)
      {
        if (it3->getNombre() == T1.getNombre())
        {
          Atacante = *it3;
          A1 = true;
        }
        if (it2->getNombre() == T2.getNombre())
        {
          Atacado = *it2;
          A2 = true;
        }

        if (A1 && A2)
        {
          // Verificar que el territorio atacante pertenezca al jugador que está atacando
          if (!territorioPerteneciente(J1, Atacante.getNombre()))
          {
            std::cout << "El territorio atacante no pertenece al jugador que está atacando" << std::endl;
            return false;
          }

          // Verificar que el territorio a atacar no pertenezca al mismo jugador
          if (territorioPerteneciente(J1, Atacado.getNombre()))
          {
            std::cout << "El territorio a atacar pertenece al mismo jugador que está atacando" << std::endl;
            return false;
          }

          // Verificar que los territorios sean vecinos
          if (!verificarVecinos(Atacante, Atacado))
          {
            std::cout << "Los territorios no son vecinos" << std::endl;
            return false;
          }

          // Realizar las tiradas de dados
          for (int i = 0; i < 3; i++)
          {
            resulAtacante[i] = rand() % 6 + 1;
          }
          std::sort(resulAtacante, resulAtacante + 3, std::greater<int>());

          for (int i = 0; i < 2; i++)
          {
            resulDefensor[i] = rand() % 6 + 1;
          }
          std::sort(resulDefensor, resulDefensor + 2, std::greater<int>());

          // Calcular las pérdidas de unidades de ejército
          for (int i = 0; i < 2; i++)
          {
            if (resulAtacante[i] > resulDefensor[i])
            {
              perdidasDefensor++;
            }
            else
            {
              perdidasAtacante++;
            }
          }
          cout << "Perdida defensor: " << perdidasDefensor << endl;
          cout << "Perdida atacante: " << perdidasAtacante << endl;
          cout << "Cantidad de unidades de atacante: " << it3->getCantiUnidades() << endl;
          cout << "Cantidad de unidades de defensor: " << it2->getCantiUnidades() << endl;

          if (perdidasAtacante >= Atacante.getCantiUnidades())
          {
            std::cout << "El ataque ha fallado" << std::endl;
            it3->setEstadoTerritorio(false);
            J1.getTerritoriosConquistados().erase(it3);
            return true;
          }
          else if (perdidasDefensor >= Atacado.getCantiUnidades())
          {
            std::cout << "El territorio " << Atacado.getNombre() << " ha sido conquistado por el jugador " << J1.getId() << std::endl;
            Atacado.setCantiUnidades(Atacante.getCantiUnidades() - perdidasAtacante);
            Atacante.setCantiUnidades(Atacante.getCantiUnidades() - perdidasAtacante);
            J1.setTerritoriosConquistados(Atacado);
            J2.getTerritoriosConquistados().erase(it2);
            return true;
          }
          else
          {
            std::cout << "El defensor ha ganado y el territorio " << Atacante.getNombre() << " no ha podido ser conquistado" << std::endl;
            Atacante.setCantiUnidades(Atacante.getCantiUnidades() - perdidasAtacante);
            return true;
          }
        }
      }
    }
  }

  std::cout << "Uno o ambos territorios no existen" << std::endl;
  return false;
}

bool Risk::fortificarTerritorio(Jugador J, Territorio T1, Territorio T2, int nUnidades)
{
  bool estado = false;
  std::list<Continente>::iterator it;
  std::list<Territorio>::iterator it2;

  for (it = continentes.begin(); it != continentes.end(); it++)
  {
    std::list<Territorio> lterritorios = it->getListaTerritorio();
    for (it2 = lterritorios.begin(); it2 != lterritorios.end(); it2++)
    {
      if (it2->getNombre() == T1.getNombre())
      {
        if (J.saberTerritorioConquistado(T1))
        {
          if (J.saberTerritorioConquistado(T2))
          {
            if (it2->getCantiUnidades() > 1)
            {
              it2->setCantiUnidades(it2->getCantiUnidades() - nUnidades);
              T2.setCantiUnidades(it2->getCantiUnidades() + nUnidades);
              std::cout << "Se pasaron " << nUnidades << " del territorio " << T1.getNombre() << " al territorio " << T2.getNombre() << endl;
              estado = true;
              return estado;
            }
            else
            {
              std::cout << "No tiene suficientes unidades para extraer del territorio " << T1.getNombre() << endl;
              return estado;
            }
          }
          else
          {
            std::cout << "El territorio " << T2.getNombre() << " no se encuentra conquistado. " << endl;
            return estado;
          }
        }
        else
        {
          std::cout << "El territorio " << T1.getNombre() << " no se encuentra conquistado. " << endl;
          return estado;
        }
      }
      else
      {
        std::cout << "El territorio no existe." << endl;
        return estado;
      }
    }
  }
}

void Risk::modosDeJuego(Jugador J1, Jugador J2, vector<string> vecinos)
{
  string atacar, fortificar, territorioAtacar, territorioAtacante, territorioExtraccion, territorioAdicion;
  int nUnidades;
  Territorio tAtacar, tAtacado, tFortificar, tFortificante;
  if (obtenerUnidades(J1))
  {
    std::cout << "\nSalto a la siguiente fase." << endl;
    std::cout << "Siguiente fase: Atacar..." << endl
              << endl;
  }
  do
  {
    std::cout << "Desea atacar? Si/No" << endl;
    cin >> atacar;
  } while (atacar != "Si" && atacar != "No");

  if (atacar == "Si")
  {

    do
    {
      std::cout << "Desde que territorio va a atacar?: " << endl;
      cin >> territorioAtacante;
      tAtacar.setNombre(territorioAtacante);
    } while (!territorioPerteneciente(J1, territorioAtacante));

    do
    {
      std::cout << "Que territorio desea atacar?" << endl;
      cin >> territorioAtacar;
      tAtacado.setNombre(territorioAtacar);
    } while (!verificarVecinos(tAtacar, tAtacado) && !territorioPerteneciente(J2, territorioAtacar));
    // atacarTerritorio(vecinos, J1, J2, tAtacar, tAtacado);
    std::cout << "\n------------------------------------------" << endl;
    atacarTerritorio(tAtacar, tAtacado, J1, J2);
    std::cout << "------------------------------------------" << endl;
    std::cout << "\nSalto a la siguiente fase." << endl;
    std::cout << "Siguiente fase: fortificacion..." << endl
              << endl;
  }
  else
  {
    std::cout << "\n------------------------------------------" << endl;
    std::cout << "Salto a la siguiente fase." << endl;
    std::cout << "Siguiente fase: fortificacion..." << endl;
    std::cout << "------------------------------------------" << endl
              << endl;
  }

  do
  {
    std::cout << "Desea fortificar? Si/No" << endl;
    cin >> fortificar;
  } while (fortificar != "Si" && fortificar != "No");

  if (fortificar == "Si")
  {

    do
    {
      std::cout << "De que territorio desea extraer tropas?" << endl;
      cin >> territorioExtraccion;
      tFortificar.setNombre(territorioExtraccion);
    } while (!territorioPerteneciente(J1, territorioExtraccion));

    do
    {
      std::cout << "Cuantas unidades quiere pasar?" << endl;
      cin >> nUnidades;
    } while (J1.getnUnidadesDisponibles() < nUnidades);

    do
    {
      std::cout << "A cual territorio desea agregar esa tropas?" << endl;
      cin >> territorioAdicion;
      tFortificante.setNombre(territorioAdicion);
    } while (!territorioPerteneciente(J1, territorioAdicion) && !verificarVecinos(tFortificar, tFortificante));

    if (J1.extraerNTerritoriosConquistados(J1.getTerritoriosConquistados()) < 2)
    {
      std::cout << "\n------------------------------------------" << endl;
      std::cout << "No se puede fortificar debido a que no tiene suficientes territorios conquistados." << endl;
      std::cout << "Turno terminado para el jugador: " << J1.getId() << endl;
      std::cout << "------------------------------------------" << endl;
    }
    else
    {
      std::cout << "\n------------------------------------------" << endl;
      fortificarTerritorio(J1, tFortificar, tFortificante, nUnidades);
      cin.ignore();
      std::cout << "Turno terminado para el jugador: " << J1.getId() << endl;
      std::cout << "------------------------------------------" << endl;
    }
  }
  else
  {
    if (J1.extraerNTerritoriosConquistados(J1.getTerritoriosConquistados()) == 42)
    {
      std::cout << "¡El jugador: " << J1.getId() << " ha ganado la partida!" << endl;
    }
    std::cout << "\n------------------------------------------" << endl;
    std::cout << "Turno terminado para el jugador: " << J1.getId() << endl;
    std::cout << "------------------------------------------" << endl;
  }
}