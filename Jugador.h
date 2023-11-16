#ifndef __Jugador__
#define __Jugador__
#include <string>
#include <list>
#include "Territorio.h"
#include "Carta.h"
using namespace std;

class Jugador
{
private:
    string id;
    int nUnidadesDisponibles;
    std::list<Territorio> listaTerritoriosConquistados;
    string color;
    list<Carta> manoCartas;
    bool estadoTurno;

public:
    Jugador();
    Jugador(string id, int nUnidadesDisponibles, std::list<Territorio> listaTerritoriosConquistados, string color, list<Carta> manoCartas, bool estadoTurno);
    Jugador(bool estadoTurno);
    ~Jugador();
    void setId(string id);
    string getId();
    void setnUnidadesDisponibles(int nUnidadesDisponibles);
    int getnUnidadesDisponibles();
    void setColor(string color);
    string getColor();
    list<Territorio> getTerritoriosConquistados();
    void setTerritoriosConquistados(Territorio T);
    list<Carta> getManoCartas();
    void setManoCartas(Carta carta);
    void setNManoCartas(int n);
    bool getEstadoTurno();
    void setEstadoTurno(bool estadoTurno);

    bool saberTerritorioConquistado(Territorio T);
    void setNTerritoriosConquistados(int n);
    int extraerNTerritoriosConquistados(std::list<Territorio> listaTerritoriosConquistados);
    Jugador crearJugador(string id);
};

#endif