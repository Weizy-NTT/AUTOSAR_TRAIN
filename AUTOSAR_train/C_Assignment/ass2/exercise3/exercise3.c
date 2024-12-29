#include <stdio.h>
#include <stdint.h>  
#include "Userhandling.h"
typedef unsigned char uint8_t;
void absoluteValue(uint8_t *data)
{
    if(*(data + 1)>*data)
    {
        *(data + 2) = *(data + 1) - *data;
    }
    else
    {
        *(data + 2) = *data - *(data + 1);
    }
}
int main()
{
    char option;
    do
    {
        uint8_t number[3];
        printf("Enter two number to calculate absolution between them: \n");
        number[0]=get_valid_input_with_range("Enter the first number between 0 and 255: ",is_digit_in_range,0,255);
        number[1]=get_valid_input_with_range("Enter the second number between 0 and 255: ",is_digit_in_range,0,255);
        absoluteValue(number);

        printf("The first number you input: %hhu\n",number[0]);
        printf("The second number you input: %hhu\n",number[1]);
        printf("The absolute value is: %hhu\n",number[2]);

        option = get_valid_input_with_range("Do you want to continue or stop (1: Yes  / 2: No) ",is_digit_in_range,1,2);

    }while (option!=2);
    printf("\n Program terminated!!!");
}