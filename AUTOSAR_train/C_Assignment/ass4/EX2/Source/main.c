#include <stdio.h>
#include <string.h>
#include "mylib.h"

void Respond_User (status_enum_t status)
{
    User_status = status;
    switch (status) 
    {
        case 0: 
        {
            printf("Right syntax format\n");
            break;
        }
        case 1: 
        {
            printf("Account contain invalid character!!!");
            break;
        }
        case 2: 
        {
            printf("Account contain invalid length!!!");
            break;
        }
            
    }
}

int main()
{
    char account[20] ;
    RegisterCallback(Respond_User);
    do
    {
        printf("Enter your account number (It must be less than 10 characters and it must be number or character): ");
        scanf("%s", account);

        Check_Account(account, strlen(account) );
    }while(User_status!=CORRECT);
}