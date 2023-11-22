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
int Grafo<T>::CantidadVertices()
{
    return vertices.size();
}

template <typename T>
int Grafo<T>::CantidadAristas()
{
    int count = 0;
    for (const auto &fila : matrizAdyacencia)
    {
        for (int costo : fila)
        {
            if (costo != 0)
            {
                count++;
            }
        }
    }
    return count;
}

template <typename T>
void Grafo<T>::InsertarVertice(const T &vertice)
{
    if (!BuscarVertice(vertice))
    {
        vertices.push_back(vertice);
        for (auto &fila : matrizAdyacencia)
        {
            fila.push_back(0);
        }
        matrizAdyacencia.push_back(vector<int>(vertices.size(), 0));
    }
}

template <typename T>
void Grafo<T>::InsertarArista(const T &origen, const T &destino, int costo)
{
    int idxOrigen = BuscarVerticeIndice(origen);
    int idxDestino = BuscarVerticeIndice(destino);
    if (idxOrigen != -1 && idxDestino != -1)
    {
        if (matrizAdyacencia[idxOrigen][idxDestino] == 0)
        {
            matrizAdyacencia[idxOrigen][idxDestino] = costo;
        }
    }
}

template <typename T>
bool Grafo<T>::BuscarVertice(const T &vertice)
{
    return BuscarVerticeIndice(vertice) != -1;
}

template <typename T>
int Grafo<T>::BuscarVerticeIndice(const T &vertice)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == vertice)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool Grafo<T>::BuscarArista(const T &origen, const T &destino)
{
    int idxOrigen = BuscarVerticeIndice(origen);
    int idxDestino = BuscarVerticeIndice(destino);
    if (idxOrigen != -1 && idxDestino != -1)
    {
        return matrizAdyacencia[idxOrigen][idxDestino] != 0;
    }
    return false;
}

template <typename T>
void Grafo<T>::ImprimirAristas()
{
    for (int i = 0; i < matrizAdyacencia.size(); i++)
    {
        for (int j = 0; j < matrizAdyacencia[i].size(); j++)
        {
            if (i != -1 && j != -1)
                cout << matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Grafo<T>::EliminarVertice(const T &vertice)
{
    int idx = BuscarVerticeIndice(vertice);
    if (idx != -1)
    {
        vertices.erase(vertices.begin() + idx);
        for (auto &fila : matrizAdyacencia)
        {
            fila.erase(fila.begin() + idx);
        }
        matrizAdyacencia.erase(matrizAdyacencia.begin() + idx);
    }
}

template <typename T>
void Grafo<T>::EliminarArista(const T &origen, const T &destino)
{
    int idxOrigen = BuscarVerticeIndice(origen);
    int idxDestino = BuscarVerticeIndice(destino);
    if (idxOrigen != -1 && idxDestino != -1)
    {
        matrizAdyacencia[idxOrigen][idxDestino] = 0;
    }
}

template <typename T>
void Grafo<T>::Dijkstra(const T &origen)
{
    int n = vertices.size(), distanciaAux, posicionAux;
    int idxOrigen = BuscarVerticeIndice(origen);
    if (idxOrigen == -1)
    {
        cout << "ID del pais no encontrado." << endl;
        return;
    }

    vector<int> distancia(n, INT_MAX);
    vector<bool> visitado(n, false);

    distancia[idxOrigen] = 0;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = -1;
        int distanciaMinima = INT_MAX;

        for (int v = 0; v < n; ++v)
        {
            if (!visitado[v] && distancia[v] <= distanciaMinima)
            {
                u = v;
                distanciaMinima = distancia[v];
            }
        }

        visitado[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (!visitado[v] && matrizAdyacencia[u][v] && distancia[u] != INT_MAX &&
                distancia[u] + matrizAdyacencia[u][v] < distancia[v])
            {
                distancia[v] = distancia[u] + matrizAdyacencia[u][v];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (distanciaAux > distancia[i] && distancia[i] != 0 && distanciaAux != 0)
        {
            distanciaAux = distancia[i];
            posicionAux = i + 1;
            cout << "-------------------------------------------" << endl;
            cout << "- ID pais: " << posicionAux << " distancia minima con: " << distanciaAux << endl;
            cout << "-------------------------------------------" << endl;
        }
        else
        {
            cout << "- ID pais: " << i + 1 << " distancia: " << distancia[i] << endl;
        }
    }
}

template <typename T>
void Grafo<T>::CaminoMasCorto(const T &origen)
{
    int n = vertices.size(), distanciaAux, posicionAux;
    int idxOrigen = BuscarVerticeIndice(origen);
    if (idxOrigen == -1)
    {
        cout << "ID del pais no encontrado." << endl;
        return;
    }

    vector<int> distancia(n, INT_MAX);
    vector<bool> visitado(n, false);

    distancia[idxOrigen] = 0;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = -1;
        int distanciaMinima = INT_MAX;

        for (int v = 0; v < n; ++v)
        {
            if (!visitado[v] && distancia[v] <= distanciaMinima)
            {
                u = v;
                distanciaMinima = distancia[v];
            }
        }

        visitado[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (!visitado[v] && matrizAdyacencia[u][v] && distancia[u] != INT_MAX &&
                distancia[u] + matrizAdyacencia[u][v] < distancia[v])
            {
                distancia[v] = distancia[u] + matrizAdyacencia[u][v];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (distanciaAux > distancia[i] && distancia[i] != 0 && distanciaAux != 0)
        {
            distanciaAux = distancia[i];
            posicionAux = i + 1;
        }
    }

    if(posicionAux > 42 || distanciaAux > 10000)
        cout << "No existe una conquista mas barata..."<<endl;
    else    
        cout << "La conquista mas barata es con ID pais: " << posicionAux << " con " << distanciaAux << " unidades" << endl;
}
