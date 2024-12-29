    #include <stdio.h>
    #include "Userhandling.h"
    #include <stdlib.h>

int get_valid_input(const char *prompt, validator_func validator) {
    char input[100]; 
    while (1) {
        printf("%s", prompt);
        scanf("%s", input); 

        if (validator(input)) {
            return atoi(input); 
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

bool is_digit_positive(const char *value) {
    for (int i = 0; value[i] != '\0'; i++) {
        if (!isdigit(value[i])) {
            return false; 
        }
    }
    return true; 
}


bool is_number(const char *value) {
    int i = 0;

    if (value[0] == '-') {
        i = 1; 
    }

    for (; value[i] != '\0'; i++) {
        if (!isdigit(value[i])) {
            return false; 
        }
    }

    return i > 0; 
}


