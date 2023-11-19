#include <iostream>
#include "Grafo.h"
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits> 

template <typename T>
Grafo<T>::Grafo() {}

template <typename T>
int Grafo<T>::CantidadVertices() {
  return vertices.size();
}

template <typename T>
int Grafo<T>::CantidadAristas() {
  int count = 0;
  for (const auto& fila : matrizAdyacencia) {
    for (int costo : fila) {
      if (costo != 0) {
        count++;
      }
    }
  }
  return count;
}


template <typename T>
void Grafo<T>::InsertarVertice(const T& vertice) {
    if (!BuscarVertice(vertice)) {
        vertices.push_back(vertice);
        for (auto& fila : matrizAdyacencia) {
            fila.push_back(0);
        }
        matrizAdyacencia.push_back(vector<int>(vertices.size(), 0));
    }
}


template <typename T>
void Grafo<T>::InsertarArista(const T& origen, const T& destino, int costo) {
    int idxOrigen = BuscarVerticeIndice(origen);
    int idxDestino = BuscarVerticeIndice(destino);
    if (idxOrigen != -1 && idxDestino != -1) {
        if (matrizAdyacencia[idxOrigen][idxDestino] == 0) {
            matrizAdyacencia[idxOrigen][idxDestino] = costo;
        }
    }
}


template <typename T>
bool Grafo<T>::BuscarVertice(const T& vertice) {
    return BuscarVerticeIndice(vertice) != -1;
}

template <typename T>
int Grafo<T>::BuscarVerticeIndice(const T& vertice) {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == vertice) {
            return i;
        }
    }
    return -1;
}


template <typename T>
bool Grafo<T>::BuscarArista(const T& origen, const T& destino) {
    int idxOrigen = BuscarVerticeIndice(origen);
    int idxDestino = BuscarVerticeIndice(destino);
    if (idxOrigen != -1 && idxDestino != -1) {
        return matrizAdyacencia[idxOrigen][idxDestino] != 0;
    }
    return false;
}


template <typename T>
void Grafo<T>::EliminarVertice(const T& vertice) {
    int idx = BuscarVerticeIndice(vertice);
    if (idx != -1) {
        vertices.erase(vertices.begin() + idx);
        for (auto& fila : matrizAdyacencia) {
            fila.erase(fila.begin() + idx);
        }
        matrizAdyacencia.erase(matrizAdyacencia.begin() + idx);
    }
}


template <typename T>
void Grafo<T>::EliminarArista(const T& origen, const T& destino) {
    int idxOrigen = BuscarVerticeIndice(origen);
    int idxDestino = BuscarVerticeIndice(destino);
    if (idxOrigen != -1 && idxDestino != -1) {
        matrizAdyacencia[idxOrigen][idxDestino] = 0;
    }
}

template <typename T>
void Grafo<T>::Dijkstra(const T& origen) {
    int n = vertices.size();
    int idxOrigen = BuscarVerticeIndice(origen);
    if (idxOrigen == -1) {
        cout << "ID del país no encontrado." << endl;
        return;
    }

    vector<int> distancia(n, INT_MAX);
    vector<bool> visitado(n, false);

    distancia[idxOrigen] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = -1;
        int distanciaMinima = INT_MAX;

        for (int v = 0; v < n; ++v) {
            if (!visitado[v] && distancia[v] <= distanciaMinima) {
                u = v;
                distanciaMinima = distancia[v];
            }
        }

        visitado[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visitado[v] && matrizAdyacencia[u][v] && distancia[u] != INT_MAX &&
                distancia[u] + matrizAdyacencia[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + matrizAdyacencia[u][v];
            }
        }
    }

    cout << "Distancias mínimas desde el país con ID " << vertices[idxOrigen] << " a los demás paises con ID:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "ID país: " << vertices[i] << " - Distancia mínima: " << distancia[i] << endl;
    }
}