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
#include "Entrega.h"
#include "Pasarela.h"
#include "BloodDatabase.h"
#include "Donor.h"
#include "General.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void Entrega::EntregarDonantes(const Pasarela& p) {


    std::vector<std::string> posibles_donadores;
    if (p.sangre_solicitada.empty()) {
        posibles_donadores = p.verificarCompatibilidad();
    } else {
        posibles_donadores = std::vector<std::string>{p.sangre_solicitada};
    }

    std::vector<Donor> donors;
    std::string line;
    std::ifstream inFile(BloodDatabase::getBase_Datos());

    if (!inFile) {
        std::cout << "No se pudo abrir la base de datos de donadores.\n";
        General::waitForKeyPress();
        return;
    }

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        bool match = std::find(posibles_donadores.begin(), posibles_donadores.end(), d.bloodType) != posibles_donadores.end();
        if (match) {
            donors.push_back(d);
        }
    }
    inFile.close();

    std::ofstream outFile("historial.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error al abrir el archivo historial.txt para escribir.\n";
    }

    if (donors.empty()) {
        std::cout << "No se encontraron donantes compatibles para el receptor " << p.nombre_receptor << " (ID: " << p.id_receptor << ") con tipo de sangre solicitado: " << (p.sangre_solicitada.empty() ? p.sangre_receptor : p.sangre_solicitada) << ".\n";
        if (outFile.is_open()) {
            outFile << "No Donación - Receptor: " << p.nombre_receptor << " (ID: " << p.id_receptor << "), Sangre Solicitada: " << (p.sangre_solicitada.empty() ? p.sangre_receptor : p.sangre_solicitada) << "\n";
        }
    } else {
        std::cout << "Se encontraron " << donors.size() << " donante(s) compatible(s) para el receptor " << p.nombre_receptor << " (ID: " << p.id_receptor << ") con tipo de sangre solicitado: " << (p.sangre_solicitada.empty() ? p.sangre_receptor : p.sangre_solicitada) << ":\n";

        for (const auto& d : donors) {
            std::cout << "  - Donante: " << d.name << " (ID: " << d.donorId << "), Tipo de sangre: " << d.bloodType << "\n";
            if (outFile.is_open()) {
                outFile << "Receptor: " << p.nombre_receptor << " (ID: " << p.id_receptor << ") recibió de Donante: " << d.name << " (ID: " << d.donorId << "), Sangre: " << d.bloodType << "\n";
            }
        }
    }

    if (outFile.is_open()) {
        outFile.close();
    }

    General::waitForKeyPress();
}