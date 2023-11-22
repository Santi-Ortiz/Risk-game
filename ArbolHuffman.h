#ifndef __ArbolHuffman__
#define __ArbolHuffman__
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <fstream>

using namespace std;
class Nodo
{
public:
    char simbolo;
    int frecuencia;
    Nodo *izq, *der;

public:
    Nodo *getNodo(char simbolo, int frecuencia, Nodo *izq, Nodo *der);
    void codificar(Nodo *raiz, string str, unordered_map<char, string> &CodigoHuffman);
    void decodificar(Nodo *raiz, int &indice, string str);
    void decodificarEnArchivo(Nodo *raiz, int &indice, string str, ofstream &archivoCodigosHuffmanDecimales);
    bool crearArbol(string texto, string nombreArchivo); // Cambiar texto por datos de la partida
    bool crearArbolFrecuenciaDecimal(string texto, string nombreArchivo);
    bool leerDecodificacion(string texto, string nombreArchivo);
    string cargarPartida(string nombreArchivo);
};

#endif