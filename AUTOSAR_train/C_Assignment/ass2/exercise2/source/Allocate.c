#include"Allocate.h"
#include <stdlib.h>
bool allocate10Bytes(uint8_t *outPtr)
{
    if (outPtr == NULL) {
        return false; 
    }
    uint8_t *allocatedMemory = (uint8_t *)malloc(10 * sizeof(uint8_t));

    if(allocatedMemory == NULL)
    {
        return false;
    }
    *(uint8_t **)outPtr = allocatedMemory;
    return true;
}