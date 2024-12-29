#include "library.h"
#include <stdio.h>
#include <stdlib.h>

// 1. Initialize the Array
void InitArray(Array *arr, int *buffer, int capacity) {
    arr->Address = buffer;
    arr->Capacity = capacity;
    arr->Size = 0; 
    printf("Array initialized with capacity %d.\n", capacity);
}

// 2. Add 
void AddElement(Array *arr, int value, int position) {
    if (position < 0 || position > arr->Size) {
        printf("Invalid position. Cannot add element. Because the size is %d it must be less or equal this value\n",arr->Size);
        return;
    }
    if (arr->Size >= arr->Capacity) {
        printf("Array is full. Cannot add element.\n");
        return;
    }
    
    for (int i = arr->Size; i > position; i--) {
        arr->Address[i] = arr->Address[i - 1];
    }
    arr->Address[position] = value;
    arr->Size++;
    printf("Added element %d at position %d. Current size: %d.\n", value, position, arr->Size);
}

// 3. Delete 
void DelElement(Array *arr, int index) {
    if (index < 0 || index >= arr->Size) {
        printf("Invalid index. Cannot delete element.\n");
        return;
    }
    for (int i = index; i < arr->Size - 1; i++) {
        arr->Address[i] = arr->Address[i + 1]; 
    }
    arr->Size--; 
    printf("Deleted element at index %d. Current size: %d.\n", index, arr->Size);
}

// 4. Sort the Array (Ascending Order)
void Sort(Array *arr) {
    for (int i = 0; i < arr->Size - 1; i++) {
        for (int j = i + 1; j < arr->Size; j++) {
            if (arr->Address[i] > arr->Address[j]) {
                
                int temp = arr->Address[i];
                arr->Address[i] = arr->Address[j];
                arr->Address[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

// 5. Search 
void Search( Array *arr, int value) {
    for (int i = 0; i < arr->Size; i++) {
        if (arr->Address[i] == value) {
            printf("Element %d found at index %d.\n", value, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", value);
}


void PrintArray(Array *arr) {
    printf("Array elements: ");
    for (int i = 0; i < arr->Size; i++) {
        printf("%d ", arr->Address[i]);
    }
    printf("\n");
}

