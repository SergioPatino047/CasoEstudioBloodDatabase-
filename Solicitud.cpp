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
#include "Solicitud.h"
#include "General.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <fstream>

const std::string Solicitud::Solicitudes = "solicitantes.txt";
const std::string& Solicitud::getSolicitudes(){
    return Solicitudes;
}


void Solicitud::DatosReceptor() {
    General::clearConsole();
    std::cout << "Ingrese los detalles del receptor\n";

    Solicitud newreceptor;
    newreceptor.receptorId = General::getValidatedInput("Id: ");

    std::cout << "Nombre: ";
    std::getline(std::cin, newreceptor.name);

    std::cout << "Dirección: ";
    std::getline(std::cin, newreceptor.address);

    General::displayProvinces();
    newreceptor.district = General::getValidatedInput("departamento (ingrese el número correspondiente): ");

    std::cout << "Tipo de sangre: \n";
    General::escogerSangre(newreceptor.tipoDeSangre);

    std::cout << "Numero de telefono: ";
    std::getline(std::cin, newreceptor.number);

    std::string opcion;
    std::cout << "¿Desea solicitar un tipo de sangre específico? (s/n): ";
    std::getline(std::cin, opcion);

    if (opcion == "s" || opcion == "S") {
        General::escogerSangre(newreceptor.solicitudDeSangre);
    } else if (opcion == "n" || opcion == "N") {
        newreceptor.solicitudDeSangre = "";
    } else {
        std::cout << "Opción inválida. No se asignará tipo de sangre específico.\n";
        newreceptor.solicitudDeSangre = "";
    }

    receptores.push_back(newreceptor);
}


void Solicitud::guardarSolicitud(){

    std::ofstream outfile(Solicitudes, std::ios::app);

    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    Solicitud newreceptor = receptores.back();
    outfile << newreceptor.receptorId << "," << trim(newreceptor.name) << "," << trim(newreceptor.address) << "," << newreceptor.district << "," << trim(newreceptor.tipoDeSangre) << "," << trim(newreceptor.number) << "," << trim(newreceptor.solicitudDeSangre) << std::endl;

    outfile.close();

}


Solicitud Solicitud::parseLine(const std::string& line) {
    Solicitud s;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); s.receptorId = std::stof(trim(token));
    getline(ss, token, ','); s.name = trim(token);
    getline(ss, token, ','); s.address = trim(token);
    getline(ss, token, ','); s.district = std::stof(trim(token));
    getline(ss, token, ','); s.tipoDeSangre = trim(token);
    getline(ss, token, ','); s.number = trim(token);
    getline(ss, token, ','); s.solicitudDeSangre = trim(token);

    return s;
}

std::string Solicitud::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}