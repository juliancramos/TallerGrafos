#include "ManejadorArchivos.h"
#include "Grafo.h" // Asegúrate de incluir el encabezado de Grafo

void ManejadorArchivos::leerArchivo(const std::string& nombreArchivo, Grafo<std::string>& grafo) const {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    int numeroLineas;

    // Leer el número de conexiones (primera línea)
    if (std::getline(archivo, linea)) {
        numeroLineas = std::stoi(linea);  // Convertir la línea a un entero
    }

    for (int i = 0; i < numeroLineas; ++i) {
        // Leer cada línea que contiene dos nombres
        if (std::getline(archivo, linea)) {
            // Separar los nombres
            std::istringstream stream(linea);
            std::string nombre1, nombre2;
            stream >> nombre1 >> nombre2;

            // Añadir la conexión al grafo
            grafo.agregarArista(nombre1, nombre2);
        }
    }

    archivo.close();  // Cerrar el archivo
}
