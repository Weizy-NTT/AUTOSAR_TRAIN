#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <functional>
class StudentValidator {
public:
    static void validateFullName(const std::string& fullName);
    static void validateDOB(const std::string& doB);
    static void validatePhoneNumber(const std::string& phoneNumber);
    static void validSex(const std::string& Sex);
    static void validUniversityName(const std::string& UniversityName);
    static void validGradeLevel(const std::string& GradeLevel);
    static void validBestRewardName(const std::string& BestRewardName);
    static void validateIntRange(int value);
    static void validateFloatPositive(float value);
    static void validateDoublePositive(double value);
    static void IntRange(int value, int min, int max);
};

#endif // VALIDATOR_H
