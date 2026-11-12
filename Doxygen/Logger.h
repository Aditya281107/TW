/**
 * @file Logger.h
 * @brief Defines a simple logging utility class and log severity levels.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

/**
 * @enum LogLevel
 * @brief Represents the severity level of a log message.
 */
enum class LogLevel {
    INFO,    /**< Informational messages highlighting normal application progress. */
    WARNING, /**< Potentially harmful situations that do not stop execution. */
    ERROR    /**< Error events that might still allow the application to continue running. */
};

/**
 * @class Logger
 * @brief A simple logging class to output timestamped or leveled messages to the console.
 */
class Logger {
private:
    std::string prefix;
    LogLevel minLevel;

public:
    /**
     * @brief Constructs a new Logger object.
     * @param logPrefix A string prefix prepended to every log message (e.g., "[Engine]").
     * @param level The minimum LogLevel threshold required for a message to be printed.
     */
    Logger(const std::string& logPrefix, LogLevel level = LogLevel::INFO)
        : prefix(logPrefix), minLevel(level) {}

    /**
     * @brief Logs a message with a given severity level.
     * @param level The severity level of the message.
     * @param message The text content to be logged.
     */
    void log(LogLevel level, const std::string& message) const {
        if (level < minLevel) return;
        std::string levelStr = (level == LogLevel::INFO) ? "[INFO] " :
                               (level == LogLevel::WARNING) ? "[WARNING] " : "[ERROR] ";
        std::cout << prefix << " " << levelStr << message << std::endl;
    }
};

#endif // LOGGER_H