#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <functional>

class Validator {
public:
    // Method to validate birth date format (YYYY-MM-DD)
    static void validateBirthDay(const std::string& birthDay);

    // Method to validate phone number (only digits, 9-10 digits)
    static void validatePhone(const std::string& phone);

    // Method to validate email format
    static void validateEmail(const std::string& email);

    // Method to validate full name (must contain at least two words)
    static void validateFullName(const std::string& fullName);

    // Method to validate ID 
    static void validateID(const std::string& ID);

    static void IntRange(int value, int min, int max) ;

    static void validProskill(const std::string& proskill);

    static void validGradeLevel(const std::string& GradeLevel);

    static void validEducationLevel(const std::string& education);

    static void validMajor(const std::string& Major);

    static void validSemester(const std::string& Semester);

    static void validUniversity(const std::string& Semester);

    static void validateIDnew(const std::string& ID);


};

#endif // VALIDATOR_H
