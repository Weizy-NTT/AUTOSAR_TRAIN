#include <stdint.h>  
#include <stdbool.h>  
#include "Allocate.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    uint8_t *ptr = NULL; 
    if (allocate10Bytes((uint8_t *)&ptr)) { 
        printf("Memory allocated successfully. Address: %p\n", ptr);

        // testing with 10 number
        for (int i = 0; i < 10; i++) {
            ptr[i] = i; 
        }

        printf("Allocated memory contents: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");

        free(ptr);
        printf("Memory freed.\n");
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}