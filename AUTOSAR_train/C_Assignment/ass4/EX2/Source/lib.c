#include <stdio.h>
#include "mylib.h"

status_enum_t User_status = CORRECT;  
func Register_Callback = NULL; 

bool isalpha_numb(char c){
    return ((c >= 'a' && c <= 'z') ||  
            (c >= 'A' && c <= 'Z') ||  
            (c >= '0' && c <= '9')); 
}

void RegisterCallback(func func_add) {
    Register_Callback = func_add;
}

void Check_Account(char *ptr, uint8_t length) {
    int check_error_flag = 0;

    if (length > 10) {
        Register_Callback(LENGHT_INVALID);
    } else {
        for (int i = 0; i < length; i++) {
            if (!isalpha_numb(*(ptr + i))) {
                check_error_flag++;
            }
        }
        if (check_error_flag) {
            Register_Callback(CHAR_INVALID);
        } else {
            Register_Callback(CORRECT);
        }
    }
}
