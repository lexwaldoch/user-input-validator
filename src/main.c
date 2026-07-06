#include <stdio.h>
#include "functions.h"

#define MAX_INPUT 128

int main(void)
{
    char username[MAX_INPUT];
    char email[MAX_INPUT];
    char password[MAX_INPUT];
    char confirm[MAX_INPUT];

    Get_User_Data("Username: ", username, MAX_INPUT);
    Verify_Username(username, MAX_INPUT);

    Get_User_Data("Email: ", email, MAX_INPUT);
    Verify_Email(email, MAX_INPUT);

    Get_User_Data("Password: ", password, MAX_INPUT);
    Verify_Password(password, MAX_INPUT);

    Get_User_Data("Confirm Password: ", confirm, MAX_INPUT);
    Verify_Passwords_Match(password, MAX_INPUT,
                           confirm, MAX_INPUT);

    return 0;
}
