#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>
#include <set>
#include <queue>

template <typename T>
class Grafo {
private:
    std::unordered_map<T, std::list<T>> listaAdyacencia;  // Lista de adyacencia

    //(Depth-First Search) Profundidad o preorden
    void dfs(const T& nodo, std::set<T>& visitados) const; //Este metodo solo puede ser llamado directamente por iniciarDFS

public:
    Grafo() = default;

    // Añadir arista entre dos nodos
    void agregarArista(const T& nodo1, const T& nodo2);
    void mostrarGrafo() const;

    // Iniciar DFS (se llama desde el main)
    void iniciarDFS(const T& nodoInicial) const;

    // (Breadth-First Search) //Anchura 
    void bfs(const T& nodoInicial) const;
};

#include "Grafo.hxx"

#endif // GRAFO_H
