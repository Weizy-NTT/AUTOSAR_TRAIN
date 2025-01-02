#include <iostream>
#include <string>
#include <stdexcept>

class Validator {
public:
    static void validLocation(const std::string& Location);
};

void Validator::validLocation(const std::string& Location) {
    const std::string validLocations[] = {"TPHCM", "DA NANG", "HA NOI"};

    for (const std::string& valid : validLocations) {
        if (Location == valid) {
            std::cout << "Location is valid: " << Location << std::endl;
            return;
        }
    }

    // In ra thông báo lỗi nếu không hợp lệ
    throw std::invalid_argument("Invalid location (It must be TPHCM, DA NANG, HA NOI): " + Location);
}

int main() {
    // Test cases
    const std::string testLocations[] = {"TPHCM", "DA NANG", "HA NOI", "HUE", "123", "TPHCM "};

    for (const auto& testLocation : testLocations) {
        std::cout << "Testing location: " << testLocation << std::endl;
        try {
            Validator::validLocation(testLocation);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
