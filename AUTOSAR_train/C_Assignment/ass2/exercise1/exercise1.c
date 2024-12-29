#include<stdio.h>
#include<stdlib.h>
#include"Userhandling.h"
int main()
{
    int number = get_valid_input_with_range("How many number you wanna input (between 1 and 255): ",is_digit_in_range,1,255);
    unsigned short * aptr = (unsigned short *)malloc(sizeof(unsigned short)*number);
    if(aptr ==NULL)
    {
        printf("allocation fail");
        return 1;
    }

    for (int i = 0; i < number; i++) {
        printf("Enter the %d number between 0 and 65535: ", i + 1);
        *(aptr + i) = get_valid_input_with_range("", is_digit_in_range, 0, 65535);

    }
    for(int i=number; i>0; i --)
    {
        printf("%p:%u\n",aptr+(i-1),*(aptr+i-1));
    }
    unsigned short * bptr = aptr;
    for (int i=0 ; i<number; i++)
    {
        if(*(aptr +i)>*bptr)
        {
            bptr = aptr +i;
        }
    } 
    
    printf("\nThe largest number is: %u\n", *bptr);
    printf("Located at address: %p\n", bptr);

    free(aptr);
}