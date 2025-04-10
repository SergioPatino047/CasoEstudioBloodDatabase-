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
#include "General.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>


void General::displayProvinces() {
    std::cout << "Elige el departamento:\n";
    std::cout << "1. Putumayo\n";
    std::cout << "2. Cauca\n";
    std::cout << "3. Valle del Cauca\n";
    std::cout << "4. Amazonas\n";
    std::cout << "5. Risaralda\n";
    std::cout << "6. Antioquia\n";
    std::cout << "7. Norte de Santander\n";
}

void General::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void General::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int General::getValidatedInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                throw std::invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = std::stoi(input);
            break; // si la conversión es exitosa, salir del bucle
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
        }
    }
    return value;
}
void General::escogerSangre(std::string& sangre) {
    int choice;
    int condicion = 0;

    while (condicion == 0) {
        std::cout << "1. AB+\n";
        std::cout << "2. AB-\n";
        std::cout << "3. A+\n";
        std::cout << "4. A-\n";
        std::cout << "5. B+\n";
        std::cout << "6. B-\n";
        std::cout << "7. O+\n";
        std::cout << "8. O-\n";
        std::cout << "Ingrese el tipo de sangre: ";
        
        // Validación de la entrada
        std::cin >> choice;

        
        if (std::cin.fail() || choice < 1 || choice > 8) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Opción inválida. Intente nuevamente.\n";
            continue; 
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1:
                sangre = "AB+";
                condicion++;
                break;
            case 2:
                sangre = "AB-";
                condicion++;
                break;
            case 3:
                sangre = "A+";
                condicion++;
                break;
            case 4:
                sangre = "A-";
                condicion++;
                break;
            case 5:
                sangre = "B+";
                condicion++;
                break;
            case 6:
                sangre = "B-";
                condicion++;
                break;
            case 7:
                sangre = "O+";
                condicion++;
                break;
            case 8:
                sangre = "O-";
                condicion++;
                break;
            default:
                std::cout << "Opción inválida. Tipo de sangre no asignado.\n";
                break;
        }
    }
}