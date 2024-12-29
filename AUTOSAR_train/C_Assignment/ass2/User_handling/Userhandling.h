#ifndef USER_HANDLING_H
#define USER_HANDLING_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef bool (*validator_func)(const char *);
typedef bool (*validator_func_with_range)(const char *, int, int);


int get_valid_input(const char *prompt, validator_func validator);
int get_valid_input_with_range(const char *prompt, validator_func_with_range validator, int min, int max);


bool is_digit_only(const char *value);
bool is_digit_in_range(const char *value, int min, int max);

#endif // USER_HANDLING_H
