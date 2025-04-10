/*
    Clase: Solicitud
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: Solicitud

    Responsabilidades:
        - Hace una solicitud de sangre es decir guarda a un paciente que requiere un tipo de sangre, 
        almacena sus datos y los guarda en un archivo solicitud.txt.

    Colaboradores:
        - Colabora directamente con la clase `General` por sus metodos

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
#ifndef SOLICITUD_H
#define SOLICITUD_H
#include <string>
#include <vector>


class Solicitud{

    private:

        static const std::string Solicitudes;

        std::vector <Solicitud> receptores;

        static std::string trim(const std::string& str);

    public:

        float receptorId, district;
        std::string name, address, tipoDeSangre, solicitudDeSangre, number;

        //metodo que usa un puntero para acceder a Solicitudes y retornar su informacion sin modificarla o poder ser modificada
        static const std::string& getSolicitudes();

        void DatosReceptor();
        static Solicitud parseLine(const std::string& line);
        void guardarSolicitud();


};

#endif