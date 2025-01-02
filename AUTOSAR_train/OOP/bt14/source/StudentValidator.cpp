#include "StudentValidator.h"
#include <regex>
#include <iostream>

void StudentValidator::validateFullName(const std::string& fullName) {
    // Kiểm tra độ dài
    if (fullName.length() < 10 || fullName.length() > 50) {
        throw std::invalid_argument("Full name must be between 10 and 50 characters.");
    }

    // Sử dụng regex để kiểm tra ký tự không hợp lệ
    std::regex validNameRegex("^[a-zA-Z\\s]+$");

    if (!std::regex_match(fullName, validNameRegex)) {
        throw std::invalid_argument("Full name must only contain letters and spaces. No numbers or special characters allowed.");
    }
}

void StudentValidator::validateDOB(const std::string& doB) {
   // Check the length of the string
    if (doB.length() != 10) {
        throw std::invalid_argument("Invalid birth date format. Expected YYYY-MM-DD.");
    }

    // Check the positions of the dashes
    if (doB[4] != '-' || doB[7] != '-') {
        throw std::invalid_argument("Invalid birth date format. Expected YYYY-MM-DD.");
    }

    // Extract year, month, and day as integers
    std::string yearStr = doB.substr(0, 4);
    std::string monthStr = doB.substr(5, 2);
    std::string dayStr = doB.substr(8, 2);

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
    std::cout << "Valid birth date: " << doB << std::endl;
}

void StudentValidator::validatePhoneNumber(const std::string& phoneNumber) {
    // Check if the phone number is exactly 10 digits and starts with valid prefixes
    std::regex phoneRegex("^(090|098|091|031|035|038)\\d{7}$");
    if (!std::regex_match(phoneNumber, phoneRegex)) {
        throw std::invalid_argument("Phone number must be 10 digits and start with 090, 098, 091, 031, 035, or 038.");
    }
}

void StudentValidator::validSex(const std::string& Sex) {
    std::string lowerSex = Sex;
    std::transform(lowerSex.begin(), lowerSex.end(), lowerSex.begin(), ::tolower);
    if (lowerSex != "male" && lowerSex != "female") {
        throw std::invalid_argument("Invalid sex. Must be 'male' or 'female'.");
    }
}

void StudentValidator::validUniversityName(const std::string& UniversityName) {
    if (UniversityName.length() < 10 || UniversityName.substr(UniversityName.length() - 10) != "University") {
        throw std::invalid_argument("Invalid university name. Must end with 'University'.");
    }
}

void StudentValidator::validGradeLevel(const std::string& GradeLevel) {
    std::string lowerGradeLevel = GradeLevel;
    std::transform(lowerGradeLevel.begin(), lowerGradeLevel.end(), lowerGradeLevel.begin(), ::tolower);
    if (lowerGradeLevel != "excellent" && lowerGradeLevel != "very good" && lowerGradeLevel != "good" && lowerGradeLevel != "average") {
        throw std::invalid_argument("Invalid grade level. Must be 'Excellent', 'Very Good', 'Good', or 'Average'.");
    }
}

void StudentValidator::validBestRewardName(const std::string& BestRewardName) {
    if (BestRewardName.length() < 5 || BestRewardName.substr(BestRewardName.length() - 5) != "Award") {
        throw std::invalid_argument("Invalid best reward name. Must end with 'Award'.");
    }
}

void StudentValidator::validateIntRange(int value){
    if (value != 1 && value != 2) {
            throw std::invalid_argument("Student type must be 1 or 2.");
    }
}

void StudentValidator::validateFloatPositive(float value){
    if (value < 0.0f || value > 10.0f) {
        throw std::invalid_argument("Value must be between 0 and 10.");
    }
}

void StudentValidator::validateDoublePositive(double value){
    if (value < 0.0 || value > 10.0) {
        throw std::invalid_argument("Value must be between 0 and 10.");
    }
}

void StudentValidator::IntRange(int value, int min, int max) {
    if (value < min || value > max) {
        throw std::invalid_argument("Value must be between " + std::to_string(min) + " and " + std::to_string(max) + ".");
    }
}