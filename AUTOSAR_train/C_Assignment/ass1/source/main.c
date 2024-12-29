#include <stdio.h>
#include <ctype.h>
#include "Linkedlist.h"
#include "Userhandling.h"
#include <stdlib.h>

#define CREATE 'c'
#define PRINT 'p'
#define INSERT 'i'
#define DELETE 'd'
#define SORT_ASC 's'
#define SORT_DESC 'x'
#define FIND 't'
#define EXIT 'e'

int main() {
    char option;
    int number_in_list = 0;
    node *head = NULL;

    do {
        printf("\n--- Menu ---\n");
        printf("Press 'c' to create a number array.\n");
        printf("Press 'p' to print the array.\n");
        printf("Press 'i' to add a number at a position.\n");
        printf("Press 'd' to delete a number at a position.\n");
        printf("Press 's' for ascending sort.\n");
        printf("Press 'x' for descending sort.\n");
        printf("Press 't' to find a number.\n");
        printf("Press 'e' to exit.\n");
        printf("Choose an option: ");
        scanf(" %c", &option);
        option = tolower(option);

        switch (option) {
            case CREATE:
                create_array(&head, &number_in_list);
                break;
            case PRINT:
                print_out(head);
                break;
            case INSERT:
                add_number(&head, &number_in_list);
                break;
            case DELETE:
                delete_number(&head, &number_in_list);
                break;
            case SORT_ASC:
                sort(ascend,head);
                break;
            case SORT_DESC:
                sort(descend,head);
                break;
            case FIND:
                find_number(head);
                break;
            case EXIT:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 'e');

    // Free the list before exiting
    if (head != NULL) {
        node *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
}


