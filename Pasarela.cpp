/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.

    Ademas se crearon nuevos modulos con la capacidad de realizar una solicitud y entrega

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024

    Autores: 
    María José Gonzalez Rosero – 2439500  
    Sara Alejandra Villota - (2437438)
    Sergio Ernesto Patiño Rodríguez - (2440051)

    Fecha: Abril 2025
*/
#include "Pasarela.h"
#include "Solicitud.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>

void Pasarela::ReceptorYSolicitud() {
    std::ifstream inFile(Solicitud::getSolicitudes());

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::string line;
    std::string respuesta;

    while (std::getline(inFile, line)) {
        Solicitud d = Solicitud::parseLine(line);

        std::cout << "Id: " << d.receptorId << std::endl;
        std::cout << "Nombre: " << d.name << std::endl;
        std::cout << "Dirección: " << d.address << std::endl;
        std::cout << "departamento: " << d.district << std::endl;
        std::cout << "Tipo de sangre: " << d.tipoDeSangre << std::endl;
        std::cout << "Número de móvil: " << d.number << std::endl;
        std::cout << "Tipo de sangre solicitada: " << d.solicitudDeSangre << std::endl;

        std::cout << "\n¿Deseas trabajar con esta solicitud? (s/n): ";
        std::getline(std::cin, respuesta);

        if (respuesta == "s" || respuesta == "S") {
            std::cout << "Guardando datos importantes...\n";
            float tempId = d.receptorId;
            id_receptor = tempId;
            nombre_receptor = d.name;
            sangre_receptor = d.tipoDeSangre;
            sangre_solicitada = d.solicitudDeSangre;
            break;
        }

        std::cout << "\nPasando a la siguiente solicitud...\n\n";
    }

    inFile.close();
}

std::vector<std::string> Pasarela::verificarCompatibilidad() const {
    std::vector<std::string> compatibles;

    if (sangre_receptor == "AB+") {
        compatibles = {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"};
    } else if (sangre_receptor == "AB-") {
        compatibles = {"AB-", "A-", "B-", "O-"};
    } else if (sangre_receptor == "A+") {
        compatibles = {"A+", "A-", "O+", "O-"};
    } else if (sangre_receptor == "A-") {
        compatibles = {"A-", "O-"};
    } else if (sangre_receptor == "B+") {
        compatibles = {"B+", "B-", "O+", "O-"};
    } else if (sangre_receptor == "B-") {
        compatibles = {"B-", "O-"};
    } else if (sangre_receptor == "O+") {
        compatibles = {"O+", "O-"};
    } else if (sangre_receptor == "O-") {
        compatibles = {"O-"};
    }

    return compatibles;
}




