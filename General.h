/*
    Clase: General
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: General

    Responsabilidades:
        - Ser un repertorio de metodos que se usan constantemente por todos los demas modulos

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
#ifndef GENERAL_H
#define GENERAL_H
#include <string>

class General{
    public:
        static void displayProvinces();
        static void clearConsole();
        static void waitForKeyPress();
        static int getValidatedInput(const std::string& prompt);
        static void escogerSangre(std::string& sangre);
};
#endif