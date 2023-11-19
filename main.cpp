#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <fstream>
#include <cstring>
#include "Carta.h"
#include "Continente.h"
#include "Jugador.h"
#include "Risk.h"
#include "ArbolHuffman.h"
#include "Grafo.h"

#include <vector>
using namespace std;

void introducirComando(string c1, string c2, string c3, string comando, Risk R, Jugador J1, Jugador J2, int nUnidades)
{

    while (c1 != "salir")
    {
        c1 = "";
        c2 = "";
        c3 = "";

        cout << "$ ";
        getline(cin, comando);
        // Conocer posición de cada uno de los espacios del comando
        size_t space = comando.find(" ");
        size_t space2 = comando.find_first_of(" ", space + 1);

        // Segmentar cada subcomando en una variable
        c1 = comando.substr(0, space);
        if (space != string::npos)
            c2 = comando.substr(space + 1, space2 - space);
        if (space2 != string::npos)
            c3 = comando.substr(space2 + 1);

        // -----------------------------------------------------------------------------------------------------------------
        //                                           Comandos de Ayuda
        // -----------------------------------------------------------------------------------------------------------------

        if (c1 == "help" && c2 == "")
        {

            cout << " Comando ejecutado exitosamente" << endl
                 << endl;
            cout << " \t inicializar - Realiza las operaciones necesarias para "
                    "inicializar el juego, de acuerdo a las instrucciones entregadas."
                 << endl
                 << endl;
            cout << " \t help - Este comando permite obtener la informacion de los "
                    "demas comandos disponibles dependiendo de las pantallas."
                 << endl
                 << endl;
            cout
                << " \t inicializar <nombre_archivo> - Inicializa el juego con los "
                   "datos contenidos en el archivo identificado por <nombre_archivo>."
                << endl
                << endl;
            cout << " \t turno <id_jugador>: Realiza las operaciones descritas "
                    "dentro del turno de un jugador (obtener nuevas unidades, atacar "
                    "y fortificar)"
                 << endl
                 << endl;
            cout << " \t costo_conquista <territorio> - Calcula el costo y la "
                    "secuencia de territorios a ser conquistados para lograr "
                    "controlar el territorio dado por el usuario"
                 << endl
                 << endl;
            cout << " \t conquista_mas_barata - Calcular aquel que pueda implicar un "
                    "menor número de unidades de ejército perdidas"
                 << endl
                 << endl;
            cout << " \t guardar <nombre_archivo> - El estado del juego es guardado "
                    "en un archivo de texto, el archivo debe almacenar los datos del "
                    "jugador, la informacion del ejercito y otras piezas del juego"
                 << endl
                 << endl;
            cout << " \t guardar_comprimido<nombre_archivo> - El estado actual del "
                    "juego es guardado en un archivo binario conteniendo la "
                    "informacion del jugador, los informacion del ejercito y otras "
                    "piezas de juego la informacion comprimida"
                 << endl
                 << endl;
            cout << " \t salir - Este comando permite la finalizacion del programa"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "inicializar")
        {

            cout << "Comando ejecutado exitosamente" << endl
                 << endl;
            cout << " \t inicializar: Realiza las operaciones necesarias para "
                    "inicializar el juego, de acuerdo a las instrucciones entregadas"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "inicializar<nombre_archivo>")
        {

            cout << "Comando ejecutado exitosamente" << endl
                 << endl;
            cout << " \t inicializar: Realiza las operaciones necesarias para "
                    "inicializar el juego, de acuerdo a las instrucciones entregadas"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "help")
        {

            cout << "Comando ejecutado exitosamente" << endl
                 << endl;
            cout << "Proporciona información de ayuda para los comandos de Risk"
                 << endl
                 << endl;
            cout << "help [comando]" << endl
                 << endl;
            cout << "\t"
                 << "comando: Muestra información de ayuda del comando especificado."
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "turno")
        {

            cout << " \t turno <id_jugador>: Realiza las operaciones descritas "
                    "dentro del turno de un jugador (obtener nuevas unidades, atacar "
                    "y fortificar)"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "guardar")
        {
            cout << " \t guardar <nombre_archivo>: El estado del juego es guardado "
                    "en un archivo de texto, el archivo debe almacenar los datos del "
                    "jugador, la informacion del ejercito y otras piezas del juego"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "guardar_comprimido")
        {
            cout << " \t guardar_comprimido <nombre_archivo>: El estado actual del "
                    "juego es guardado en un archivo binario conteniendo la "
                    "informacion del jugador, los informacion del ejercito y otras "
                    "piezas de juego la informacion comprimida"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "costo_conquista")
        {
            cout
                << " \t costo_conquista <territorio>: Calcula el costo y la "
                   "secuencia de territorios a ser conquistados para lograr "
                   "controlar el territorio dado por el usuario. El territorio desde "
                   "donde debe atacar debe ser aquel que el jugador tenga controlado "
                   "más cerca al dado por el jugador. Esta información se analiza "
                   "desde el punto de vista del jugador que tiene el turno de juego"
                << endl
                << endl;
        }
        else if (c1 == "help" && c2 == "conquista_mas_barata")
        {
            cout << " \t conquista_mas_barata: De todos los territorios posibles, "
                    "calcular aquel que pueda implicar un menor número de unidades "
                    "de ejército perdidas. Esta información se analiza desde el "
                    "punto de vista del jugador que tiene el turno de juego"
                 << endl
                 << endl;
        }
        else if (c1 == "help" && c2 == "salir")
        {
            cout << " \t Finaliza la introduccion de comandos" << endl;
        }

        // -----------------------------------------------------------------------------------------------------------------
        //                                           Comandos Funcionales
        // -----------------------------------------------------------------------------------------------------------------

        else if (c1 == "inicializar" && c2 == "" && c3 == "")
        {

            if ((!R.getjugadoresActivos().empty()))
            {

                cout << " \t El juego ya ha sido inicializado." << endl;
            }
            else
            {
                cout << " \t El juego se ha inicializado correctamente, iniciando juego..." << endl
                     << endl;

                cout << "--------------- Bienvenido a Risk ---------------" << endl
                     << endl;

                if (R.crearJugadores())
                {
                    cin.ignore();
                    R.crearContinentes();
                    R.crearTerritorios();
                    R.asignarTerritoriosAContinente();
                    R.continentesAcontinente();
                    R.imprimirMapa();
                    R.territoriosDisponibles();
                    R.asignarTerritoriosAJugador();
                    cin.ignore();
                    // R.imprimirMapa();
                    R.inicializarTurno();
                }
            }
        }
        else if (c1 == "inicializar" && c2 != "" && c3 == "")
        {
            if (!R.getjugadoresActivos().empty())
            {
                cout << "El juego ya ha sido inicializado." << endl
                     << endl;
            }
            else
            {
                cout << " \t Comando valido para inicializar juego ya guardado..." << endl
                     << endl;

                R.crearContinentes();
                R.crearTerritorios();
                R.asignarTerritoriosAContinente();
                R.continentesAcontinente();
                R.getjugadoresActivos().clear();
                char *token;
                Nodo ArbolHuffman;
                string s = ArbolHuffman.cargarPartida(c2);
                char *contenidoArchivo = &s[0];
                token = strtok(contenidoArchivo, "   ");
                R.setNJugadoresActivos(atoi(token));
                token = strtok(NULL, "   ");
                // cout << "Cantidad de jugadores:" << R.getjugadoresActivos().size() << endl;
                std::vector<Jugador>::iterator it;
                std::list<Territorio>::iterator it2;
                for (it = R.getjugadoresActivos().begin(); it != R.getjugadoresActivos().end(); it++)
                {
                    it->setId(token);
                    token = strtok(NULL, "   ");
                    cout << "Id jugador: " << it->getId() << endl;
                    it->setColor(token);
                    token = strtok(NULL, "   ");
                    cout << "Color: " << it->getColor() << endl;
                    it->setNManoCartas(atoi(token));
                    token = strtok(NULL, "   ");
                    cout << "Numero cartas: " << it->getManoCartas().size() << endl;
                    it->setNTerritoriosConquistados(atoi(token));
                    token = strtok(NULL, "   ");
                    cout << "Numero territorios: " << it->extraerNTerritoriosConquistados(it->getTerritoriosConquistados()) << endl;
                    std::list<Territorio> listaAuxTerritorios = it->getTerritoriosConquistados();
                    for (it2 = it->getTerritoriosConquistados().begin(); it2 != it->getTerritoriosConquistados().end(); it2++)
                    {
                        it2->setNombre(token);
                        token = strtok(NULL, "   ");
                        cout << "Nombre territorio: " << it2->getNombre() << endl;
                        it2->setCantiUnidades(atoi(token));
                        token = strtok(NULL, "   ");
                        cout << "Numero de tropas: " << it2->getCantiUnidades() << " para el territorio " << it2->getNombre() << endl;
                    }
                }
                R.imprimirJugadores();
                R.inicializarTurno();
            }
        }
        else if (c1 == "turno" && c2 != "" && c3 == "")
        {
            J1.setId(c2);
            if (R.turnoJugador(J1.getId()))
            {
                R.modosDeJuego(J1, J2);
                cin.ignore();
            }
        }
        else if (c1 == "guardar" && c2 != "" && c3 == "")
        {
            Nodo ArbolHuffman;
            int numJugadores = R.getjugadoresActivos().size();
            std::string texto = std::to_string(numJugadores) + " ";
            std::vector<Jugador>::iterator it;
            std::list<Territorio>::iterator it2;
            std::vector<Jugador> auxJugadores = R.getjugadoresActivos();
            for (it = auxJugadores.begin(); it != auxJugadores.end(); it++)
            {
                texto += it->getId() + " ";
                texto += it->getColor() + " ";
                texto += std::to_string(it->getManoCartas().size()) + " ";
                int numTerritorios = it->extraerNTerritoriosConquistados(it->getTerritoriosConquistados());
                texto += std::to_string(numTerritorios) + " ";
                std::list<Territorio> listaAuxTerritorios = it->getTerritoriosConquistados();
                for (it2 = listaAuxTerritorios.begin(); it2 != listaAuxTerritorios.end(); it2++)
                {
                    texto += it2->getNombre() + " ";
                    texto += std::to_string(it2->getCantiUnidades()) + " ";
                    // cout << "Cantidad de tropas: " << it2->getCantiUnidades() << " para el territorio " << it2->getNombre() << endl;
                }
            }
            if (ArbolHuffman.crearArbolFrecuenciaDecimal(texto, c2))
            {
                cout << " \t Partida guardada exitosamente bajo nombre: " << c2 << endl
                     << endl;
            }
            else
            {
                cout << "No se pudo guardar la partida, intentelo nuevamente" << endl;
            }
        }
        else if (c1 == "guardar_comprimido" && c2 != "" && c3 == "")
        {
            Nodo ArbolHuffman;
            int numJugadores = R.getjugadoresActivos().size();
            std::string texto = std::to_string(numJugadores) + " ";
            std::vector<Jugador>::iterator it;
            std::list<Territorio>::iterator it2;
            std::vector<Jugador> auxJugadores = R.getjugadoresActivos();
            for (it = auxJugadores.begin(); it != auxJugadores.end(); it++)
            {
                std::list<Territorio> listaAuxTerritorios = it->getTerritoriosConquistados();
                texto += it->getId() + " ";
                texto += it->getColor() + " ";
                texto += std::to_string(it->getManoCartas().size()) + " ";
                int numTerritorios = it->extraerNTerritoriosConquistados(it->getTerritoriosConquistados());
                texto += std::to_string(numTerritorios) + " ";
                for (it2 = listaAuxTerritorios.begin(); it2 != listaAuxTerritorios.end(); it2++)
                {
                    texto += it2->getNombre() + " ";
                    texto += std::to_string(it2->getCantiUnidades()) + " ";
                }
            }
            if (ArbolHuffman.crearArbol(texto, c2))
            {
                cout << " \t Partida guardada exitosamente bajo nombre: " << c2 << endl
                     << endl;
            }
            else
            {
                cout << "No se pudo guardar la partida, intentelo nuevamente" << endl;
            }
        }
        else if (c1 == "costo_conquista" && c2 != "" && c3 == "")
        {
            cout << " \t Costo conquista del territorio: " << c2 << endl
                 << endl;
            int costoArsita;
            //CostoArsita debe utilizar el idPais y con los for llegar a las unidades del terriotrio y asignarlas
            Grafo<int> GrafoRisk;
            int idPais = std::stoi(c2);
            GrafoRisk.InsertarVertice(1);
            GrafoRisk.InsertarVertice(2);
            GrafoRisk.InsertarVertice(3);
            GrafoRisk.InsertarVertice(4);
            GrafoRisk.InsertarVertice(5);
            GrafoRisk.InsertarVertice(6);
            GrafoRisk.InsertarVertice(7);
            GrafoRisk.InsertarVertice(8);
            GrafoRisk.InsertarVertice(9);
            GrafoRisk.InsertarVertice(10);
            GrafoRisk.InsertarVertice(11);
            GrafoRisk.InsertarVertice(12);
            GrafoRisk.InsertarVertice(13);
            GrafoRisk.InsertarVertice(14);
            GrafoRisk.InsertarVertice(15);/*
            GrafoRisk.InsertarVertice(16);
            GrafoRisk.InsertarVertice(17);
            GrafoRisk.InsertarVertice(18);
            GrafoRisk.InsertarVertice(19);
            GrafoRisk.InsertarVertice(20);
            GrafoRisk.InsertarVertice(21);
            GrafoRisk.InsertarVertice(22);
            GrafoRisk.InsertarVertice(23);
            GrafoRisk.InsertarVertice(24);
            GrafoRisk.InsertarVertice(25);
            GrafoRisk.InsertarVertice(26);
            GrafoRisk.InsertarVertice(27);
            GrafoRisk.InsertarVertice(28);
            GrafoRisk.InsertarVertice(29);
            GrafoRisk.InsertarVertice(30);
            GrafoRisk.InsertarVertice(31);
            GrafoRisk.InsertarVertice(32);
            GrafoRisk.InsertarVertice(33);
            GrafoRisk.InsertarVertice(34);
            GrafoRisk.InsertarVertice(35);
            GrafoRisk.InsertarVertice(36);
            GrafoRisk.InsertarVertice(37);
            GrafoRisk.InsertarVertice(38);
            GrafoRisk.InsertarVertice(39);
            GrafoRisk.InsertarVertice(40);
            GrafoRisk.InsertarVertice(41);
            GrafoRisk.InsertarVertice(42);*/
            GrafoRisk.InsertarArista(1,2,32);
            GrafoRisk.InsertarArista(1,6,54);
            GrafoRisk.InsertarArista(1,32,34);
            GrafoRisk.InsertarArista(2,1,65);
            GrafoRisk.InsertarArista(2,4,13);
            GrafoRisk.InsertarArista(2,6,65);
            GrafoRisk.InsertarArista(2,7,12);
            GrafoRisk.InsertarArista(2,9,64);
            GrafoRisk.InsertarArista(3,4,23);
            GrafoRisk.InsertarArista(3,9,54);
            GrafoRisk.InsertarArista(3,13,52);
            GrafoRisk.InsertarArista(4,3,65);
            GrafoRisk.InsertarArista(4,7,23);
            GrafoRisk.InsertarArista(4,8,64);
            GrafoRisk.InsertarArista(4,9,32);
            GrafoRisk.InsertarArista(5,6,54);
            GrafoRisk.InsertarArista(5,7,13);
            GrafoRisk.InsertarArista(5,8,25);
            GrafoRisk.InsertarArista(5,15,12);
            GrafoRisk.InsertarArista(6,1,43);
            GrafoRisk.InsertarArista(6,2,12);
            GrafoRisk.InsertarArista(6,5,43);
            GrafoRisk.InsertarArista(6,7,23);
            GrafoRisk.InsertarArista(7,2,65);
            GrafoRisk.InsertarArista(7,4,34);
            GrafoRisk.InsertarArista(7,5,65);
            GrafoRisk.InsertarArista(7,6,43);
            GrafoRisk.InsertarArista(7,8,53);
            GrafoRisk.InsertarArista(7,9,23);
            GrafoRisk.InsertarArista(8,4,53);
            GrafoRisk.InsertarArista(8,5,45);
            GrafoRisk.InsertarArista(8,7,23);
            GrafoRisk.InsertarArista(9,2,43);
            GrafoRisk.InsertarArista(9,3,23);
            GrafoRisk.InsertarArista(9,4,43);
            GrafoRisk.InsertarArista(9,7,12);
            if (idPais>=1 && idPais<=42){
                GrafoRisk.Dijkstra(idPais);
            }
            else {
                cout << "Ingrese un ID de país correcto" << endl;
            }
        }
        else if (c1 == "conquista_mas_barata" && c2 == "" && c3 == "")
        {
            cout << " \t Comando de conquista mas barata inicializado correctamente"
                 << endl
                 << endl;
        }
        else if (c1 == "salir" && c2 == "" && c3 == "")
        {
            cout << " \t Salida exitosa!" << endl;
        }
        else
        {
            cout << " \t Ingrese un comando valido..." << endl;
        }
    }
}

int main()
{
    string comando = "";
    string c1 = "";
    string c2 = "";
    string c3 = "";
    Risk R;
    Jugador J1, J2;
    int nUnidades;

    introducirComando(c1, c2, c3, comando, R, J1, J2, nUnidades);
    return 0;
}
