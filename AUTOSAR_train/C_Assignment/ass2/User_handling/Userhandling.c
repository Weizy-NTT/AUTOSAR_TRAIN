    #include <stdio.h>
    #include "Userhandling.h"
    #include <stdlib.h>

    int get_valid_input_with_range(const char *prompt, validator_func_with_range validator, int min, int max) {
    char input[100]; 
    while (1) {
        printf("%s", prompt);
        scanf("%s", input);

       
        if (validator(input, min, max)) {
            return atoi(input); 
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

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

    bool is_digit_only(const char *value) {
        for (int i = 0; value[i] != '\0'; i++) {
            if (!isdigit(value[i])) {
                return false; 
            }
        }
        return true; 
    }

    bool is_digit_in_range(const char *value, int min, int max) {
    if (!is_digit_only(value)) {
        return false; 
    }
    int number = atoi(value); 
    return number >= min && number <= max; 
}



