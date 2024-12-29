#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "Userhandling.h"

#define ADD_ELEMENT 1
#define DELETE_ELEMENT 2
#define DISPLAY 3
#define SORT 4
#define SEARCH 5
#define EXIT_PROGRAM 6

int main() {
    int choice;
    InitArray();

    while (1) {
        printf("\n=== Linked List Operations ===\n");
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Sort List\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case ADD_ELEMENT:
                int value = get_valid_input("Enter a numer to add ", is_number);
                AddElement(value);
                break;

            case DELETE_ELEMENT:
                value = get_valid_input("Enter a number: ", is_number);
                DelElement(value);
                break;

            case DISPLAY:
                printf("Current List:\n");
                DisplayList();
                break;

            case SORT:
                printf("Sorting the list...\n");
                Sort();
                break;

            case SEARCH:
                value = get_valid_input("Enter a number for searching: ", is_number);
                Search(value);
                break;

            case EXIT_PROGRAM:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
