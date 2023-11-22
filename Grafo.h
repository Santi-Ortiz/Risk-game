#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class Grafo {
private:
  vector<T> vertices;
  vector<vector<int>> matrizAdyacencia;

public:
  Grafo();
  int CantidadVertices();
  int CantidadAristas();
  void InsertarVertice(const T& vertice);
  void InsertarArista(const T& origen, const T& destino, int costo);
  bool BuscarVertice(const T& vertice);
  int BuscarVerticeIndice(const T& vertice);
  bool BuscarArista(const T& origen, const T& destino);
  void ImprimirAristas();
  void EliminarVertice(const T& vertice);
  void EliminarArista(const T& origen, const T& destino);
  void Dijkstra(const T& origen);
  void CaminoMasCorto(const T& origen);
};

#include "Grafo.hxx"

#endif