#ifndef MANEJADORARCHIVOS_H
#define MANEJADORARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

class ManejadorArchivos {
public:
    // Método para leer el archivo y mostrar su contenido
    void leerArchivo(const std::string& nombreArchivo) const;
};

#endif // MANEJADORARCHIVOS_H
