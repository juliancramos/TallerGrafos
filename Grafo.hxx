#include "Grafo.h"

// Añadir arista entre dos nodos
template <typename T>
void Grafo<T>::agregarArista(const T& nodo1, const T& nodo2) {
    listaAdyacencia[nodo1].push_back(nodo2);      // Agregar nodo2 a la lista de nodo1
    listaAdyacencia[nodo2].push_back(nodo1);      // Agregar nodo1 a la lista de nodo2. Solo para grafos no dirigidos
}

// Mostrar el grafo
template <typename T>
void Grafo<T>::mostrarGrafo() const {
    for (const auto& entry : listaAdyacencia) {
        const auto& nodo = entry.first;
        const auto& vecinos = entry.second;
        std::cout << "Nodo: " << nodo << " -> ";
        for (const auto& vecino : vecinos) {
            std::cout << vecino << " ";
        }
        std::cout << std::endl;
    }
}



//DFS, este es recursivo
template <typename T>
void Grafo<T>::dfs(const T& nodo, std::set<T>& visitados) const {
    visitados.insert(nodo);
    std::cout << nodo << " "; // Imprimir el nodo visitado

    for (const auto& vecino : listaAdyacencia.at(nodo)) {
        if (visitados.find(vecino) == visitados.end()) {
            dfs(vecino, visitados);
        }
    }
}

// Inicia el DFS y llama a la función para implementar recursión
template <typename T>
void Grafo<T>::iniciarDFS(const T& nodoInicial) const {
    std::set<T> visitados; // Se usa para llevar registro de los nodos que ya se visitaron
    dfs(nodoInicial, visitados); //Arranca con el nodo inicial (como si fuera la raiz)
}


template <typename T>
void Grafo<T>::bfs(const T& nodoInicial) const {
    //Se usa set para simplificar, ya que asegura que no hayan elementos duplicados, lo que nos asegura que un nodo solo se visite una vez
    //Basicamente no se necesita comprobar si un nodo fue visitado o no, porque si ya fue visitado, no se podrá insertar    
    std::set<T> visitados; 
    std::queue<T> cola; // Nodos a visitar

    visitados.insert(nodoInicial); 
    cola.push(nodoInicial); // Añade el nodo inicial a la cola

    while (!cola.empty()) {
        T nodo = cola.front(); 
        cola.pop(); 
        std::cout << nodo << " "; 

        for (const auto& vecino : listaAdyacencia.at(nodo)) {
            if (visitados.find(vecino) == visitados.end()) {
                visitados.insert(vecino); // Marca como visitado
                cola.push(vecino); // Añade el vecino a la cola
            }
        }
    }
}
