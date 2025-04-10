/*
    Clase: Entrega
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: Entrega

    Responsabilidades:
        - Entregar los donadores con respecto al tipo de sangre del receptor y guardarlos en historial

    Colaboradores:
        - Colabora directamente con la clase `Pasarela`, ya utiliza un objeto de esa clase para 
        poder administrar los datos de los donadores y receptores.

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
#ifndef ENTREGA_H
#define ENTREGA_H
#include "Pasarela.h"
#include <string>

class Entrega{
    private:
        std::string nombre_donador;
        std::string id_donador;
        std::string sangre_donador;
    public:
        void EntregarDonantes(const Pasarela& pasarela);
    
};

#endif