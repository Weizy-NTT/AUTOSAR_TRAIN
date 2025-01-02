#include "ValidationExceptions.h"
#include <regex>
#include <stdexcept>
#include <iostream>

// Validate birthday format (YYYY-MM-DD)
void Validator::validateBirthDay(const std::string& birthDay) {
    // Check the length of the string
    if (birthDay.length() != 10) {
        throw std::invalid_argument("Invalid birth date format. Expected YYYY-MM-DD.");
    }

    // Check the positions of the dashes
    if (birthDay[4] != '-' || birthDay[7] != '-') {
        throw std::invalid_argument("Invalid birth date format. Expected YYYY-MM-DD.");
    }

    // Extract year, month, and day as integers
    std::string yearStr = birthDay.substr(0, 4);
    std::string monthStr = birthDay.substr(5, 2);
    std::string dayStr = birthDay.substr(8, 2);

    // Ensure all characters are digits
    for (char c : yearStr + monthStr + dayStr) {
        if (!std::isdigit(c)) {
            throw std::invalid_argument("Invalid birth date format. Expected numeric values in YYYY-MM-DD.");
        }
    }

    int year = std::stoi(yearStr);
    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);

    // Validate month
    if (month < 1 || month > 12) {
        throw std::invalid_argument("Invalid date: Month must be between 1 and 12.");
    }

    // Validate day based on the month
    if (day < 1) {
        throw std::invalid_argument("Invalid date: Day must be greater than 0.");
    }

    if (month == 2) { // February
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeapYear)) {
            throw std::invalid_argument("Invalid date: February 29 is only valid in leap years.");
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // Months with 30 days
        if (day > 30) {
            throw std::invalid_argument("Invalid date: This month has only 30 days.");
        }
    } else { // Months with 31 days
        if (day > 31) {
            throw std::invalid_argument("Invalid date: This month has only 31 days.");
        }
    }

    // If everything passes, the date is valid
    std::cout << "Valid birth date: " << birthDay << std::endl;
}


// Validate phone number (only digits, 10-15 digits)
void Validator::validatePhone(const std::string& phone) {
    // Regex to validate phone numbers starting with 0 and having 10 or 11 digits
    std::regex phoneRegex("^0\\d{9,10}$");
    if (!std::regex_match(phone, phoneRegex)) {
        throw std::invalid_argument("Invalid phone number. Must start with '0' and have 10 or 11 digits.");
    }
}

// Validate email format
void Validator::validateEmail(const std::string& email) {
    std::regex emailRegex("^[\\w.%+-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    if (!std::regex_match(email, emailRegex)) {
        throw std::invalid_argument("Invalid email format.");
    }
}

void Validator::validateFullName(const std::string& fullName) {
    // Check if the full name is empty or does not contain at least two words
    if (fullName.empty() || fullName.find(' ') == std::string::npos) {
        throw std::invalid_argument("Invalid full name. Full name must contain at least two words.");
    }

    // Check if the full name contains only alphabetic characters and spaces
    for (char c : fullName) {
        if (!isalpha(c) && c != ' ') { // Allow only letters and spaces
            throw std::invalid_argument("Invalid full name. Full name must contain only alphabetic characters and spaces.");
        }
    }
}

void Validator::validateID(const std::string& ID){
    for (char c : ID) {
        if (!isalnum(c)) {
            throw std::invalid_argument("Invalid ID: ID must contain only alphanumeric characters with no spaces or special characters.");
        }
    }
}


void Validator::IntRange(int value, int min, int max) {
    if (value < min || value > max) {
        throw std::invalid_argument("Value must be between " + std::to_string(min) + " and " + std::to_string(max) + ".");
    }
}

void Validator::validProskill(const std::string& proskill) {
    static const std::vector<std::string> validSkills = {"C", "C++", "Python", "Java", "C#"};
    if (std::find(validSkills.begin(), validSkills.end(), proskill) == validSkills.end()) {
        throw std::invalid_argument("Invalid professional skill. Must be one of: C, C++, Python, Java, C#.");
    }
}

void Validator::validGradeLevel(const std::string& GradeLevel) {
    std::string lowerGradeLevel = GradeLevel;
    std::transform(lowerGradeLevel.begin(), lowerGradeLevel.end(), lowerGradeLevel.begin(), ::tolower);
    if (lowerGradeLevel != "excellent" && lowerGradeLevel != "very good" && lowerGradeLevel != "good" && lowerGradeLevel != "average") {
        throw std::invalid_argument("Invalid grade level. Must be 'Excellent', 'Very Good', 'Good', or 'Average'.");
    }
}

void Validator::validEducationLevel(const std::string& education) {
    static const std::vector<std::string> validEducationLevels = {"Bachelor", "Master", "PhD", "Associate", "Diploma"};
    if (std::find(validEducationLevels.begin(), validEducationLevels.end(), education) == validEducationLevels.end()) {
        throw std::invalid_argument("Invalid education level. Must be one of: Bachelor, Master, PhD, Associate, Diploma.");
    }
}

void Validator::validMajor(const std::string& Major) {
    const std::string validMajors[] = {"CS", "IT", "ME"};
    for (const std::string& valid : validMajors) {
        if (Major == valid) {
            return; // Valid Major
        }
    }
    throw std::invalid_argument("Invalid Major (It must be one of: CS(Computer Science), IT(Information Technology), MEMechanical Engineering).");
}

void Validator::validSemester(const std::string& Semester) {
    const std::regex pattern("^Semester ([1-9]|1[0-2])$");
    if (!std::regex_match(Semester, pattern)) {
        throw std::invalid_argument("Invalid Semester (It must be in the format: Semester n, where n is 1 to 12).");
    }
}

void Validator::validUniversity(const std::string& University) {
    const std::regex pattern("^[A-Za-z0-9 ]+University$");
    if (University.length() > 30) {
        throw std::invalid_argument("Invalid University (It must not exceed 30 characters).");
    }
    if (!std::regex_match(University, pattern)) {
        throw std::invalid_argument("Invalid University (It must end with 'University' and contain no special characters).");
    }
}

void Validator::validateIDnew(const std::string& ID) {
    for (char c : ID) {
        // Kiểm tra nếu ký tự không phải là chữ cái, số hoặc khoảng trắng
        if (!isalnum(c) && c != ' ') {
            throw std::invalid_argument("Invalid ID: ID must contain only alphanumeric characters and spaces, with no special characters.");
        }
    }
}