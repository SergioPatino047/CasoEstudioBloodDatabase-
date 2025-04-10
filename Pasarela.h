/*
    Clase: Pasarela
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: Pasarela

    Responsabilidades:
        - Guarda los datos del receptor y la sangre que solicita asi como verificar la compatibilidad
        de la sangre del receptor

    Colaboradores:
        - Colabora directamente con la clase  `Solicitud` pues el acceso al 
        archivo que este usa y objetos de esta clase para poder almacenar la informacion.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.
    
    Autores: 
    María José Gonzalez Rosero – 2439500  
    Sara Alejandra Villota - (2437438)
    Sergio Ernesto Patiño Rodríguez - (2440051)

    Fecha: Abril 2025
*/
#ifndef PASARELA_H
#define PASARELA_H
#include <string>
#include <vector>


class Pasarela{
    private:
        std::string nombre_donador;
        std::string id_donador;
        std::string sangre_donador;

    public:

        std::vector<std::string> Posibles_donadores;
        std::string sangre_solicitada;
        std::string sangre_receptor;
        std::string nombre_receptor;
        float id_receptor; // Cambiar a float (o int si los IDs son siempre enteros)
        void ReceptorYSolicitud();
        std::vector<std::string> verificarCompatibilidad() const;

};

#endif