#ifndef TADJugador
#define TADJugador
#include <string>
#include <list>
#include "TADTerritorio.h"
#include "TADCarta.h"
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
    bool getEstadoTurno();
    void setEstadoTurno(bool estadoTurno);

    bool saberTerritorioConquistado(Territorio T);
    void Jugador::setNTerritoriosConquistados(int n);
    int extraerNTerritoriosConquistados(std::list<Territorio> listaTerritoriosConquistados);
    Jugador crearJugador(string id);
};

#endif