#include"Userhandling.h"

bool is_numb(char c) {
    return (c >= '0' && c <= '9');
}

int getNumberOfItems() {
    char input[256];
    int valid_input = 0;

    while (!valid_input) {
        printf("Enter your number: ");
        if (scanf("%s", input) == 1) {
            valid_input = 1;  
            for (int i = 0; i < strlen(input); i++) {
                if (!is_numb(input[i])) {
                    valid_input = 0;
                    break;
                }
            }
            if (valid_input) {
                return atoi(input);
            } else {
                printf("Invalid input. Please enter a valid number.\n");
            }
        } else {
            printf("Error reading input.\n");
            
            while (getchar() != '\n');
        }
    }

    return 0;  // Return 0 if input is invalid
}