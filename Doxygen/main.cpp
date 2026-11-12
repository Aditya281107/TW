/**
 * @file main.cpp
 * @brief Application entry point demonstrating CalculationEngine and Logger.
 *
 * @mainpage Calculation Engine & Logger Documentation
 *
 * @section intro_sec Introduction
 * Welcome to the official documentation for the multi-file C++ Calculation Engine project.
 * This project demonstrates modular C++ design paired with automated documentation
 * generation using Doxygen.
 *
 * @section modules_sec Key Components
 * - **Logger (`Logger.h`)**: Handles severity-based console logging (`INFO`, `WARNING`, `ERROR`).
 * - **CalculationEngine (`Calculation_Engine.h`)**: Executes mathematical functions such as
 *   exponentiation while logging operational status.
 *
 * @section usage_sec Building & Running
 * Compile the project using `g++`:
 * @code
 * g++ -std=c++17 main.cpp -o calc_app
 * ./calc_app
 * @endcode
 */

#include <iostream>
#include "Calculation_Engine.h"

/**
 * @brief Main entry point of the application.
 * @return Exit status code (0 on success).
 */
int main() {
    CalculationEngine engine;
    double result = engine.power_calculation(2.0, 8.0);
    std::cout << "2^8 = " << result << std::endl;
    return 0;
}