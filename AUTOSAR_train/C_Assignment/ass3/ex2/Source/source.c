#include <stdio.h>
#include "linkedlist.h"


Node Array[MAX];
Node *head = NULL;
int usedNodes = 0;


void InitArray() {
    head = NULL;
    usedNodes = 0;
    printf("List initialized.\n");
}


void AddElement(int value) {
    if (usedNodes >= MAX) {
        printf("Array is full. Can't add more!\n");
        return;
    }

    Node *newNode = &Array[usedNodes++]; 
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode; 
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next; 
        }
        curr->next = newNode; 
    }
    printf("Added: %d\n", value);
}

void DelElement(int value) {
    if (head == NULL) {
        printf("List empty, can't delete.\n");
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    bool found = false; 

    while (curr != NULL) {
        if (curr->data == value) {
            found = true; 

            if (prev == NULL) {
           
                head = curr->next;
                curr = head;
            } else {
              
                prev->next = curr->next;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    if (found) {
        printf("Deleted all nodes with value: %d\n", value);
    } else {
        printf("Couldn't find %d in the list.\n", value);
    }
}



void Sort() {
    if (head == NULL || head->next == NULL) {
        printf("List too short, nothing to sort.\n");
        return; 
    }

    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted!\n");
}


void Search(int value) {
    Node *curr = head;
    while (curr != NULL) {
        if (curr->data == value) {
            printf("Found %d at %p\n", value, (void *)curr);
            return;
        }
        curr = curr->next;
    }

    printf("Not found: %d\n", value);
}


void DisplayList() {
    Node *curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
