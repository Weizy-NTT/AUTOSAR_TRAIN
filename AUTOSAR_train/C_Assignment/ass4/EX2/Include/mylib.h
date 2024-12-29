#ifndef MYLIB_H
#define MYLIB_H
#include <stdio.h>
#include <stdbool.h>
typedef unsigned char uint8_t;

typedef enum _statetype  
{  
    CORRECT,  
    CHAR_INVALID,  
    LENGHT_INVALID  
}status_enum_t; 

typedef void (*func) (status_enum_t );

extern status_enum_t User_status ;  
extern func Register_Callback ; 

bool isalpha_numb(char c);
void RegisterCallback(func func_add);
void Check_Account(char *ptr, uint8_t length);

#endif  // MYLIB_Hs