#include "InputHandler.h"

// General method to get input with validation
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