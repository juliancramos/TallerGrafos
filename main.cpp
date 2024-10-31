#include "ManejadorArchivos.h"
#include "Grafo.h"
#include <string>

int main() {
    ManejadorArchivos manejadorArchivos;
    std::string nombreArchivo = "in01.txt"; 

    manejadorArchivos.leerArchivo(nombreArchivo);

}
