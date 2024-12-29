#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

void swap(int *a, int *b);
void create_array(node ** head, int * number_in_list);
void print_out(node * head);
void add_number(node ** head, int *number_in_list);
void delete_number(node ** head, int *number_in_list);
void find_number(node * pointer);
int ascend(int a, int b);
int descend(int a, int b);
void sort(int (*ptr)(int a, int b), node *head);


#endif