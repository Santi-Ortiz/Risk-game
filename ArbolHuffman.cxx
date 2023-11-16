#include "ArbolHuffman.h"
#include "Risk.h"
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <bitset> //Cambiar de base 10 a 2

using namespace std;

// Asigna un nuevo nodo en el arbol
Nodo *Nodo::getNodo(char simbolo, int frecuencia, Nodo *izq, Nodo *der)
{
  Nodo *nodo = new Nodo();

  nodo->simbolo = simbolo;
  nodo->frecuencia = frecuencia;
  nodo->izq = izq;
  nodo->der = der;

  return nodo;
}

// Comparación que sera usada para ordenar la pila
struct comparacion
{
  bool operator()(Nodo *i, Nodo *e)
  {
    return i->frecuencia > e->frecuencia;
  }
};

// Revisa Arbol de Huffman y guarda los códigos en un mapa
void Nodo::codificar(Nodo *raiz, string str, unordered_map<char, string> &CodigoHuffman)
{
  if (raiz == nullptr)
  {
    return;
  }
  if (!raiz->izq && !raiz->der)
  {
    CodigoHuffman[raiz->simbolo] = str;
  }
  codificar(raiz->izq, str + "0", CodigoHuffman);
  codificar(raiz->der, str + "1", CodigoHuffman);
}

// Revisar el arbol y decodificar los simbolos codificados
void Nodo::decodificar(Nodo *raiz, int &indice, string str)
{
  if (raiz == nullptr)
  {
    return;
  }
  if (!raiz->izq && !raiz->der)
  {
    cout << raiz->simbolo;
    return;
  }
  indice++;
  if (str[indice] == '0')
  {
    decodificar(raiz->izq, indice, str);
  }
  else
  {
    decodificar(raiz->der, indice, str);
  }
}

void Nodo::decodificarEnArchivo(Nodo *raiz, int &indice, string str, ofstream &archivoCodigosHuffmanDecimales)
{
  if (raiz == nullptr)
  {
    return;
  }
  if (!raiz->izq && !raiz->der)
  {
    archivoCodigosHuffmanDecimales << raiz->simbolo;
    return;
  }
  indice++;
  if (str[indice] == '0')
  {
    decodificarEnArchivo(raiz->izq, indice, str, archivoCodigosHuffmanDecimales);
  }
  else
  {
    decodificarEnArchivo(raiz->der, indice, str, archivoCodigosHuffmanDecimales);
  }
}

// Crea el Arbol de Huffman y decodifica los simbolos dados
bool Nodo::crearArbol(string texto, string nombreArchivo)
{
  // Cuenta la candidad de veces que aparece un simbolo y la guarda en el mapa
  unordered_map<char, int> frecuencia;
  for (char simbolo : texto)
  {
    frecuencia[simbolo]++;
  }
  // Se crea una cola de prioridad para guardar los nodos del arbol
  priority_queue<Nodo *, vector<Nodo *>, comparacion> pq;
  // Agrega a la cola de prioridad los nodos de cada simbolo
  for (auto pair : frecuencia)
  {
    pq.push(getNodo(pair.first, pair.second, nullptr, nullptr));
  }
  // Hace todo el proceso hasta que haya más de 1 nodo en la cola
  while (pq.size() != 1)
  {
    Nodo *izq = pq.top();
    pq.pop();
    Nodo *der = pq.top();
    pq.pop();
    int suma = izq->frecuencia + der->frecuencia;
    pq.push(getNodo('\0', suma, izq, der));
  }
  Nodo *raiz = pq.top();
  // Se imprimen los códigos de cada simbolo
  unordered_map<char, string> CodigoHuffman;
  codificar(raiz, "", CodigoHuffman);
  // cout << "Los códigos de Huffman son: " << endl;
  ofstream archivoCodigosHuffman(nombreArchivo);
  if (archivoCodigosHuffman.fail())
  {
    return false;
  }
  else
  {
    // archivoCodigosHuffman << "Los códigos de Huffman son: ";
    for (auto pair : CodigoHuffman)
    {
      // cout << pair.first << " " << pair.second << endl;
      archivoCodigosHuffman << pair.first << ": " << pair.second << ", ";
    }
    // archivoCodigosHuffman.close();
    // Se imprime el mensaje original que se ingreso (codificado)
    // Decodifica el el mensaje codificado y lo imprime de nuevo
    // ofstream archivoTextoCodificado("textoCodificado.txt");
    // archivoCodigosHuffman << "El mensaje original era: " << texto << endl;
    string str = "";
    for (char simbolo : texto)
    {
      str += CodigoHuffman[simbolo];
    }
    archivoCodigosHuffman << endl
                          << str << endl;
    archivoCodigosHuffman.close();
    // archivoTextoCodificado << "El texto codificado es: " << str <<endl;
    // archivoTextoCodificado.close();
    return true;
  }
}

bool Nodo::crearArbolFrecuenciaDecimal(string texto, string nombreArchivo)
{
  // Cuenta la candidad de veces que aparece un simbolo y la guarda en el mapa
  unordered_map<char, int> frecuencia;
  for (char simbolo : texto)
  {
    frecuencia[simbolo]++;
  }
  // Se crea una cola de prioridad para guardar los nodos del arbol
  priority_queue<Nodo *, vector<Nodo *>, comparacion> pq;
  // Agrega a la cola de prioridad los nodos de cada simbolo
  for (auto pair : frecuencia)
  {
    pq.push(getNodo(pair.first, pair.second, nullptr, nullptr));
  }
  // Hace todo el proceso hasta que haya más de 1 nodo en la cola
  while (pq.size() != 1)
  {
    Nodo *izq = pq.top();
    pq.pop();
    Nodo *der = pq.top();
    pq.pop();
    int suma = izq->frecuencia + der->frecuencia;
    pq.push(getNodo('\0', suma, izq, der));
  }
  Nodo *raiz = pq.top();
  // Se imprimen los códigos de cada simbolo
  unordered_map<char, string> CodigoHuffman;
  codificar(raiz, "", CodigoHuffman);
  // cout << "Los códigos de Huffman son: " << endl;
  ofstream archivoCodigosHuffmanDecimales(nombreArchivo);
  // archivoCodigosHuffman << "Los códigos de Huffman son: ";
  for (auto pair : CodigoHuffman)
  {
    // cout << pair.first << " " << pair.second << endl;
    int decimales = std::stoi(pair.second, nullptr, 2);
    archivoCodigosHuffmanDecimales << pair.first << ":" << decimales << ", ";
  }
  // archivoCodigosHuffman.close();
  // Se imprime el mensaje original que se ingreso (codificado)
  // Decodifica el el mensaje codificado y lo imprime de nuevo
  // cout << "El mensaje original era: " << texto << endl;
  // ofstream archivoTextoCodificado("textoCodificado.txt");
  // archivoCodigosHuffman << "El mensaje original era: " << texto << endl;
  string str = "";
  for (char simbolo : texto)
  {
    str += CodigoHuffman[simbolo];
  }
  // cout << "El texto codificado es: " << str << endl;
  archivoCodigosHuffmanDecimales << endl
                                 << str << endl;
  // archivoCodigosHuffmanDecimales.close();
  int indice = -1;
  string menDec = "";
  // cout << "El texto decodificado es: " << endl;
  while (indice < (int)str.size() - 2)
  {
    decodificarEnArchivo(raiz, indice, str, archivoCodigosHuffmanDecimales);
  }
  cout << endl;
  archivoCodigosHuffmanDecimales.close();
}

string Nodo::cargarPartida(string nombreArchivo)
{
  ifstream archivoCodigosDecimales(nombreArchivo);
  string frecuencias, mensaje, decodificacion;
  getline(archivoCodigosDecimales, frecuencias); // Lee la primera línea
  getline(archivoCodigosDecimales, mensaje);     // Lee la segunda linea
  getline(archivoCodigosDecimales, decodificacion);
  if (archivoCodigosDecimales.is_open())
  {
    return decodificacion;
  }
  else
  {
    cout << "No se pudo abrir el archivo" << endl;
    return "";
  }
}