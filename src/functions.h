#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

int Verify_Username(char user[], size_t len);
int Verify_Email(char email[], size_t len);
int Verify_Password(char pwd[], size_t len);
int Verify_Passwords_Match(char pwd1[], size_t len1,
                           char pwd2[], size_t len2);

void Get_User_Data(char *message, char *data,
                   const int MAX_LENGTH);

#endif
