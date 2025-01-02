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
            std::getline(std::cin, input); // Đọc toàn bộ dòng nhập

            // Kiểm tra chuỗi có phải số nguyên không
            size_t pos;
            int value = std::stoi(input, &pos); // Chuyển chuỗi thành số nguyên

            // Kiểm tra nếu còn ký tự dư thừa sau số nguyên
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Xác thực giá trị số nguyên
            validator(value);
            return value; // Trả về số nguyên hợp lệ
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
            std::getline(std::cin, input); // Đọc toàn bộ dòng nhập

            // Kiểm tra chuỗi có phải số thực (float) không
            size_t pos;
            float value = std::stof(input, &pos); // Chuyển chuỗi thành số thực

            // Kiểm tra nếu còn ký tự dư thừa sau số thực
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Xác thực giá trị số thực
            validator(value);
            return value; // Trả về số thực hợp lệ
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
            std::getline(std::cin, input); // Đọc toàn bộ dòng nhập

            // Kiểm tra chuỗi có phải số thực (double) không
            size_t pos;
            double value = std::stod(input, &pos); // Chuyển chuỗi thành số thực

            // Kiểm tra nếu còn ký tự dư thừa sau số thực
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Xác thực giá trị số thực
            validator(value);
            return value; // Trả về số thực hợp lệ
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
            std::getline(std::cin, input); // Đọc toàn bộ dòng nhập

            // Chuyển chuỗi thành số nguyên
            size_t pos;
            int value = std::stoi(input, &pos);

            // Kiểm tra nếu còn ký tự dư thừa sau số nguyên
            if (pos < input.size()) {
                throw std::invalid_argument("Input contains invalid characters.");
            }

            // Gọi validator với `value`, `min`, và `max`
            validator(value, min, max);
            return value; // Trả về giá trị hợp lệ
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}