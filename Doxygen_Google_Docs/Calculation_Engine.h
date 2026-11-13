/**
 * @file Calculation_Engine.h
 * @brief Defines the CalculationEngine class for performing mathematical operations.
 */

#ifndef CALCULATION_ENGINE_H
#define CALCULATION_ENGINE_H

#include "Logger.h"
#include <cmath>

/**
 * @class CalculationEngine
 * @brief Performs core mathematical computations with integrated logging.
 * @details The CalculationEngine class wraps standard arithmetic and exponential
 *          operations while recording execution steps and edge-case warnings
 *          through an internal Logger instance.
 */
class CalculationEngine {
private:
    Logger logger;

public:
    /**
     * @brief Constructs a CalculationEngine with a configured Logger.
     */
    CalculationEngine() : logger("[CalcEngine]", LogLevel::INFO) {}

    /**
     * @brief Calculates the result of raising a base to an exponent.
     * @details Computes \f$ \text{base}^{\text{exponent}} \f$ using standard floating-point
     *          arithmetic and logs the operation.
     * @param base The base value to be raised.
     * @param exponent The power to which the base is raised.
     * @return The calculated result of base raised to the power of exponent.
     * @todo Add overflow checks and handle negative base with fractional exponents.
     */
    double power_calculation(double base, double exponent) {
        logger.log(LogLevel::INFO, "Performing power calculation.");
        if (base == 0.0 && exponent < 0.0) {
            logger.log(LogLevel::ERROR, "Division by zero in power_calculation.");
            return INFINITY;
        }
        return std::pow(base, exponent);
    }
};

#endif // CALCULATION_ENGINE_H