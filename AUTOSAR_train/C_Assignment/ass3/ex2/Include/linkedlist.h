#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#define MAX 100


typedef struct Node {
    int data;
    struct Node *next;
} Node;


extern Node Array[MAX]; 
extern Node *head;     
extern int usedNodes;   

void InitArray();
void AddElement(int value);
void DelElement(int value);
void Sort();
void Search(int value);
void DisplayList();

#endif 
