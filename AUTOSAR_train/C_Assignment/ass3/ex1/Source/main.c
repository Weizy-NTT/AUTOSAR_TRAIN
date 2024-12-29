#include <stdio.h>
#include <stdlib.h>
#include "library.h" 
#include "Userhandling.h"
#define MAX 100 

#define ADD_ELEMENT 1
#define DELETE_ELEMENT 2
#define SORT_ARRAY 3
#define SEARCH_ELEMENT 4
#define PRINT_ARRAY 5
#define EXIT_PROGRAM 6

int main() {
    int buffer[MAX];     
    Array arr;           
    int choice;          
    InitArray(&arr, buffer, MAX);

    while (1) {
        printf("\n--- Array Management Program ---\n");
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Sort Array\n");
        printf("4. Search Element\n");
        printf("5. Print Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case ADD_ELEMENT:
                int value = get_valid_input("Enter a number: ", is_number);
                int position= get_valid_input("Enter a position(positive number): ", is_digit_positive);
                AddElement(&arr, value, position );
                break;

            case DELETE_ELEMENT:
                int index  = get_valid_input("Enter a position: ", is_digit_positive);
                DelElement(&arr, index);
                break;

            case SORT_ARRAY:
                Sort(&arr);
                break;

            case SEARCH_ELEMENT:
                int number = get_valid_input("Enter a positive number for searching: ", is_number);
                Search(&arr, number);
                break;

            case PRINT_ARRAY:
                PrintArray(&arr);
                break;

            case EXIT_PROGRAM:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
