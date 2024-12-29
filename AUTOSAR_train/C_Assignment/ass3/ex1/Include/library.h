#ifndef LIBRARY_H
#define LIBRARY_H


typedef struct {
    int *Address;    
    int Capacity;    
    int Size;        
} Array;


void InitArray(Array *arr, int *buffer, int capacity);
void AddElement(Array *arr, int value, int position);
void DelElement(Array *arr, int index);
void Sort(Array *arr);
void Search(Array *arr, int value);
void PrintArray(Array *arr);
#endif
