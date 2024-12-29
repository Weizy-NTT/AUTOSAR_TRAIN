#include "Linkedlist.h"
#include "Userhandling.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void create_array(node ** head, int * number_in_list)
{
    if(*head != NULL)
    {
        node *current = *head;
        while (current != NULL)
        {
            node *temp =current;
            current = current->next;
            free(temp);
        }      
        *head = NULL; // Ensure the list head is reset
    }

    printf("How many numbers in the list you want to create.\n");
    *number_in_list = getNumberOfItems();

    node* temp = NULL;
    *head = NULL;
    for (int i=0; i<*number_in_list;i++)
    {
        node *new = (node *)malloc(sizeof(node));

        new->data = getNumberOfItems();
        new->next = NULL;

        if(*head == NULL)
        {
            *head = new;
            temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }

        
    }

}

void print_out(node * head) 
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node * temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void add_number(node ** head, int *number_in_list) 
{
    int position, number;
    printf("number you wanna add: \n");
    number = getNumberOfItems();

    printf("position you wanna add: \n");
    position = getNumberOfItems();

    while (position <0 || position >*number_in_list)
    {
        printf("invalid position \n");
        printf("position you wanna add: ");
        scanf("%d", &position);
    }
    node* new = (node *)malloc(sizeof(node));
    new->data = number;
    if (position ==0)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        node* temp = *head;
        for (int i = 0; i< position-1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }

    (*number_in_list)++;
    printf("Number added successfully.\n");
    
}

void delete_number(node ** head, int *number_in_list) 
{
    int position;
    if (*head == NULL)
    {
        printf("This array dont have any number for delete");
    }

    printf("position you want to delete\n");
    position = getNumberOfItems();

    if (position > *number_in_list||position<0)
    {
        printf(" Dont have any value at this position");
        return;
    }
    node * temp = *head;
    if(position == 0)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        node* current = *head;
        for (int i=0 ; i<position -1;i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = temp ->next;

        free(temp);
    }
    (*number_in_list)--;
    printf("Number deleted successfully.\n");
    

}

int ascend(int a, int b)
{
    return b-a;
}

int descend(int a, int b)
{
    return a-b;
}

void sort(int (*ptr)(int a, int b), node *head)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (ptr == NULL) {
        printf("Function pointer is NULL.\n");
        return;
    }

    node *temp , *curr;
    
    for (temp= head; temp !=NULL; temp = temp->next)
    {
        for (curr=temp->next; curr !=NULL; curr = curr->next)
        {
            if(ptr(temp->data, curr->data) <0)
            {
                swap(&temp->data, &curr->data);
            }
        }
    }
}



void find_number(node * pointer) 
{
    int number;
    printf("Enter your number to find\n");
    number = getNumberOfItems();
    while(pointer != NULL)
    {
        if(number == pointer->data)
        {
            printf("Number %d found in the list.\n", number);
            return;
        }
        pointer = pointer->next;
    }
    printf("Number %d not found in the list.\n", number);
}