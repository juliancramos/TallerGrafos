#include "ManejadorArchivos.h"

void ManejadorArchivos::leerArchivo(const std::string& nombreArchivo) const {
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
            std::cout << linea << std::endl; // Mostrar la línea completa en la consola
        }
    }

    archivo.close();  // Cerrar el archivo
}
