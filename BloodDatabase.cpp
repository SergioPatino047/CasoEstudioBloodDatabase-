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
#include "BloodDatabase.h"
#include "General.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;

const std::string BloodDatabase::Base_datos ="data.txt";
const std::string& BloodDatabase::getBase_Datos(){
    return Base_datos;
}

void BloodDatabase::getDonorDetails() {

    General::clearConsole();
    std::cout << "Ingrese los detalles del donante\n";

    Donor newDonor;
    newDonor.donorId = General::getValidatedInput("Id: ");
    std::cout << "Nombre: ";
    std::getline(std::cin, newDonor.name);
    std::cout << "Dirección: ";
    std::getline(std::cin, newDonor.address);

    General::displayProvinces();
    newDonor.district = General::getValidatedInput("departamento (ingrese el número correspondiente): ");
    std::cout << "Tipo de sangre: \n";
    General::escogerSangre(newDonor.bloodType);


    std::cout << "Numero de telefono: ";
    std::getline(std::cin, newDonor.number);

    donors.push_back(newDonor);
}

void BloodDatabase::writeDataToFile() {
    std::ofstream outfile(Base_datos, std::ios::app);

    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    Donor newDonor = donors.back();
    outfile << newDonor.donorId << ",    " << newDonor.name << ",    " << newDonor.address << ",    " << newDonor.district << ",    " << newDonor.bloodType << ",    " << newDonor.number << std::endl;

    outfile.close();
}

void BloodDatabase::searchAndDisplay() const {
    General::clearConsole();
    General::displayProvinces();
    int provinceName = General::getValidatedInput("Ingrese el número de la departamento: ");

    std::cout << "Ingrese la dirección (dejar en blanco para omitir): ";
    std::string addressFilter;
    std::getline(std::cin, addressFilter);

    std::cout << "Ingrese el tipo de sangre (dejar en blanco para omitir): ";
    std::string bloodTypeFilter;
    std::getline(std::cin, bloodTypeFilter);

    std::ifstream inFile(Base_datos);

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> donors;
    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        bool match = d.district == provinceName &&
            (addressFilter.empty() || d.address.find(addressFilter) != std::string::npos) &&
            (bloodTypeFilter.empty() || d.bloodType == bloodTypeFilter);

        if (match) {
            donors.push_back(d);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No se encontraron personas de la departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        if (!bloodTypeFilter.empty()) {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
        }
        std::cout << "." << std::endl;
    } else {
        std::cout << "Personas de la departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        if (!bloodTypeFilter.empty()) {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
        }
        std::cout << ":" << std::endl;
        for (const auto& d : donors) {
            std::cout << "Nombre: " << d.name << std::endl;
            std::cout << "Dirección: " << d.address << std::endl;
            std::cout << "departamento: " << d.district << std::endl;
            std::cout << "Tipo de sangre: " << d.bloodType << std::endl;
            std::cout << "Número de móvil: " << d.number << std::endl;
            std::cout << std::endl;
        }
    }

    inFile.close();
    General::waitForKeyPress();
}

void BloodDatabase::deleteDonor(const std::string& donorName) {
    std::ifstream inFile(Base_datos);
    std::ofstream tempFile("temp.txt");

    if (!inFile) {
        std::cerr << "Error al abrir el archivo " << Base_datos << std::endl;
        return;
    }

    if (!tempFile) {
        std::cerr << "Error al crear el archivo temporal" << std::endl;
        return;
    }

    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.name == donorName) {
            found = true;
            std::cout << "Nombre: " << d.name << std::endl;
            std::cout << "Dirección: " << d.address << std::endl;
            std::cout << "Tipo de sangre: " << d.bloodType << std::endl;
            std::cout << "Número de móvil: " << d.number << std::endl;
            std::cout << std::endl;
            std::cout << "¿Está seguro de que desea eliminar al donante? [s/n]: ";
            char sureChoice;
            std::cin >> sureChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

            if (sureChoice == 's' || sureChoice == 'S') {
                continue;
            }
        }

        tempFile << d.donorId << ",    " << d.name << ",    " << d.address << ",    " << d.district << ",    " << d.bloodType << ",    " << d.number << std::endl;
    }

    inFile.close();
    tempFile.close();

    if (std::remove(Base_datos.c_str()) != 0) {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    if (std::rename("temp.txt", Base_datos.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
        return;
    }

    if (!found) {
        std::cout << "No se encontró ningún donante con el nombre " << donorName << std::endl;
    }
}
