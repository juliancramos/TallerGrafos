#include "ManejadorArchivos.h"
#include "Grafo.h" // Asegúrate de incluir el encabezado de Grafo

void ManejadorArchivos::guardarConexiones(const std::string& nombreArchivo, Grafo<std::string>& grafo) const {
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




void ManejadorArchivos::leerArchivo(const std::string& nombreArchivo, Grafo<std::string>& grafo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;

    
    std::getline(archivo, linea);
    int numeroDeLineas = std::stoi(linea); 
    
    std::string nombreArchivoSalida = "Salida" + nombreArchivo ;
    std::ofstream archivoSalida(nombreArchivoSalida); // Crea el archivo y escribe el numero de lineas
    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida: " << nombreArchivoSalida << std::endl;
        return;
    }
    archivoSalida<<numeroDeLineas<<std::endl;

    int contador = 0; //Para numero de lineas

    while (contador < numeroDeLineas && std::getline(archivo, linea)) {
        std::string nombre1, nombre2; 
        std::istringstream stream(linea);
        stream >> nombre1 >> nombre2; 

        // Verificar que ambos nombres se leyeron 
        if (!nombre1.empty() && !nombre2.empty()) {
            bool cumple = grafo.seisGradosDeSeparacion(nombre1, nombre2);
            // Para cada linea del archivo se llama al metodo que escribe su resultado
            escribirResultado(nombre1, nombre2, cumple, nombreArchivoSalida);
        }

        contador++; 
    }

    archivo.close();  
}



void ManejadorArchivos::escribirResultado(const std::string& nombre1, const std::string& nombre2, bool cumple,const std::string& nombreArchivo) const {
    
    //ios::app para append, osea añadir
    std::ofstream archivoSalida(nombreArchivo, std::ios::app); // Abre el archivo en modo append
    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida: " << nombreArchivo << std::endl;
        return;
    }

    // Escribir los nombres y el resultado en el archivo de salida
    archivoSalida << nombre1 << " " << nombre2 << " " << (cumple ? "Cumple" : "No cumple") << std::endl;

    archivoSalida.close();  // Cerrar el archivo
}
