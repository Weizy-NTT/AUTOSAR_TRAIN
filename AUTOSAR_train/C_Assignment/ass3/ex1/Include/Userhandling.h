#ifndef USER_HANDLING_H
#define USER_HANDLING_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef bool (*validator_func)(const char *);
int get_valid_input(const char *prompt, validator_func validator);
bool is_digit_positive(const char *value);
bool is_number(const char *value);

#endif // USER_HANDLING_H
