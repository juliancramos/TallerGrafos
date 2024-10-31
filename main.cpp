#include "ManejadorArchivos.h"
#include "Grafo.h"
#include <string>
#include <iostream>

int main() {
    
    Grafo<std::string> grafoPersonas;

    ManejadorArchivos manejadorArchivos;
    std::string nombreArchivoConexiones, nombreArchivoCasos;
    int opcion=0; 

    
    
    std::cout<<"Bienvenido al sistema"<<std::endl;
    while(opcion != 2){
        std::cout<<"Ingrese una opcion"<<std::endl;
        std::cout<<"1.Evaluar la teoría de los 6 grados de separación"<<std::endl;
        std::cout<<"2.Salir"<<std::endl;
        std::cin>>opcion;
        if(opcion == 1){
            std::cout<<"Ingrese el nombre del archivo que contiene las relaciones entre personas (conexiones)"<<std::endl;
            std::cin>>nombreArchivoConexiones;
            std::cout<<"Ingrese el nombre del archivo que contiene los casos a probar"<<std::endl;
            std::cin>>nombreArchivoCasos;
            manejadorArchivos.guardarConexiones(nombreArchivoConexiones, grafoPersonas);
            manejadorArchivos.leerArchivo(nombreArchivoCasos, grafoPersonas);
            std::cout<<"Los resultados se guardaron correctamente en el archivo: Salida"<<nombreArchivoCasos<<std::endl;
        }else{
            std::cout<<"Saliendo del sistema..."<<std::endl;
            break;
        }
    }
  

}
