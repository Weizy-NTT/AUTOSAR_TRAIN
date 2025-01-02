#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <string>
#include <functional>
#include <iostream>

class InputHandler{
    public:
    static std::string getValidatedInput(const std::string& prompt, const std::function<void(const std::string&)>& validator);
    static int getValidatedIntInputRange(const std::string& prompt, const std::function<void(int, int, int)>& validator, int min, int max);

};

#endif