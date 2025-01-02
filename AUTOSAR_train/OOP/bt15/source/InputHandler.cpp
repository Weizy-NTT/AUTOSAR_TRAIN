#include <iostream>
#include <functional>
#include <string>
#include <stdexcept>
#include <limits>
#include "InputHandler.h"

std::string InputHandler::getValidatedInput(const std::string& prompt, const std::function<void(const std::string&)>& validator) {
    std::string input;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, input);
            validator(input); // Validate input
            return input;     // Return if valid
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

// Method to get integer input
int InputHandler::getValidatedIntInput(const std::string& prompt, const std::function<void(int)>& validator) {
    std::string input;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, input); // Read the entire input line

            // Check if the string is a valid integer
            size_t pos;
            int value = std::stoi(input, &pos); // Convert the string to an integer

            // Check if there are remaining invalid characters after the integer
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Validate the integer value
            validator(value);
            return value; // Return valid integer value
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

// Method to get float input
float InputHandler::getValidatedFloatInput(const std::string& prompt, const std::function<void(float)>& validator) {
    std::string input;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, input); // Read the entire input line

            // Check if the string is a valid float
            size_t pos;
            float value = std::stof(input, &pos); // Convert the string to a float

            // Check if there are remaining invalid characters after the float
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Validate the float value
            validator(value);
            return value; // Return valid float value
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

// Method to get double input
double InputHandler::getValidatedDoubleInput(const std::string& prompt, const std::function<void(double)>& validator) {
    std::string input;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, input); // Read the entire input line

            // Check if the string is a valid double
            size_t pos;
            double value = std::stod(input, &pos); // Convert the string to a double

            // Check if there are remaining invalid characters after the double
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Validate the double value
            validator(value);
            return value; // Return valid double value
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

int InputHandler::getValidatedIntInputRange(const std::string& prompt, const std::function<void(int, int, int)>& validator, int min, int max) {
    std::string input;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, input); // Read the entire input line

            // Convert the string to an integer
            size_t pos;
            int value = std::stoi(input, &pos);

            // Check if there are remaining invalid characters after the integer
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Call the validator with `value`, `min`, and `max`
            validator(value, min, max);
            return value; // Return valid value
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}
