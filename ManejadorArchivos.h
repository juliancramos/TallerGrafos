#ifndef MANEJADORARCHIVOS_H
#define MANEJADORARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
#include <sstream>

class ManejadorArchivos {
public:
    // Para leer el archivo de conexiones y guardar en el grafo
    void guardarConexiones(const std::string& nombreArchivo, Grafo<std::string>& grafo) const;
    void escribirResultado(const std::string& nombre1, const std::string& nombre2, bool cumple,const std::string& nombreArchivo) const;
    //En este se lee el archivo de personas para probar teoría de los 6 grados
    void leerArchivo(const std::string& nombreArchivo, Grafo<std::string>& grafo);
};

#endif // MANEJADORARCHIVOS_H
