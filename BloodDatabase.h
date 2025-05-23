
/*
    Clase: BloodDatabase
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: BloodDatabase

    Responsabilidades:
        - Gestionar una base de datos de donantes de sangre, almacenando 
          un conjuto de objetos de tipo `Donor`.
        - Proveer métodos para agregar, eliminar y buscar donantes en la base de datos.
        - Facilitar el manejo de la información almacenada de forma eficiente y 
          adecuada para su consulta y modificación.

    Colaboradores:
        - Colabora directamente con la clase `Donor`, ya que administra una colección 
          de objetos `Donor`.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class BloodDatabase {
private:
    static const std::string Base_datos;
    std::vector<Donor> donors;


public:
    //metodo que usa un puntero para acceder a Base_Datos y retornar su informacion sin modificarla o poder ser modifcada
    static const std::string& getBase_Datos();

    void getDonorDetails();
    void writeDataToFile();
    void searchAndDisplay() const;
    void deleteDonor(const std::string& donorName);
};

#endif // BLOODDATABASE_H
