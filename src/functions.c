/******************************************************************************
 * @file: functions.c
 * @creator: lexwaldoch
 *****************************************************************************/
#include <stdio.h>
#include "functions.h"

// Some macros
#define MAX_USERNAME_LEN    32
#define MAX_EMAIL_LEN       32
#define MAX_DOMAIN_LEN      64
#define MIN_PASSWORD_LEN    8
#define MAX_PASSWORD_LEN    16
#define NEW_LINE_CHAR       10

// Set this to 1 to enable dbgprintf statements
#define DEBUG               0
#define dbgprintf(...)      if (DEBUG) { printf(__VA_ARGS__); }



/******************************************************************************
 * Verification functions
 *****************************************************************************/

/*
 * A username must begin with a letter [A-Z, a-z], contain 32 characters
 * or less, and  may only consist of letters, underscores, or
 * digits [A-Z, a-z, _, 0-9]. An error message is displayed if any of
 * these conditions are not met. Only print the first applicable error
 * message.
 *
 * @param user : The username string
 * @param len : Size of the username input buffer
 * @return 1 if valid, 0 if not
 */
int Verify_Username(char user[], size_t len) {

    dbgprintf("This line only prints if DEBUG is set to 1\n");

    if (*user < 'A' || (*user > 'Z' && *user < 'a') || *user > 'z'){
        printf("Username must begin with a letter.\n");
        return 0;
        }
    int count = 0;
    while (user[count] != 0){
        count++;
    }
    if (count > 32){
        printf("Username must be 32 characters or less.\n");
        return 0;
    }
    int valid = 0;
    for (int i = 0; i < count; i++){

        if (user[i] >= 48 && user[i] <= 57){
            valid = 1;
        }
        if (user[i] >= 65 && user[i] <= 90){
            valid = 1;
        }
        if (user[i] >= 97 && user[i] <= 122){
            valid = 1;
        }
        if (user[i] == 95){
            valid = 1;
        }
        else if (valid == 0) {
            printf("Username may only consist of letters, underscores, or digits.\n");
            return 0;
        }
        valid = 0;
    }

    printf("Username is valid.\n");
    return 1;
}

/*
 * An email address has four parts:
 *      name
 *          exists
 *          must start with letter
 *          max 32 characters
 *          may contain only letters and digits
 *      @ symbol
 *          exists
 *      domain name
 *          exists
 *          max of 64 characters
 *          composed of one or more subdomains separated by .
 *          subdomain must begin with a letter
 *          subdomains may contain only letters and digits
 *      top-level domain
 *          must be [.edu, .com, .net]
 *
 * If the email address contains one or more errors print only the first
 * applicable error from the list.
 *
 * Note this task is based on a real world problem and may not be the best
 * order to approach writing the code.
 *
 * @param email : The email string
 * @param len : Size of the email input buffer
 * @return 1 if valid, 0 if not
 */
int Verify_Email(char email[], size_t len) {

    // Email addresses have 4 parts.  The name, the @ symbol, the domain, and the top-level domain.
    // everything before the @ is the name, everything after the @ and before the top level is the domain, etc.
    // The top-level domain is the last 4 characters and must be “.com”, “.edu”, or “.net” for this project.
    // The domain is all the characters between the @ symbol and the top-level domain.
    // Note the domain does not include the top-level domain.
    // If both the @ symbol and the top-level domain are missing, test the entire string as the username


    if (email[0] == 64){
        printf("Email is missing name.\n");
        return 0;
        }

    if (*email < 65 || (*email > 90 && *email < 97) || *email > 122){
        printf("Email start is invalid.\n");
        return 0;
    }
    int count = 0;
    while (email[count] != 0){
        count++;
    }

    int count_point = 0;
    for (int i = 0; i < count; i++){
        if (email[i] == 64){
            break;
        }
        count_point++;
    }

    if (count_point > 32){
        printf("Email name length is invalid.\n");
        return 0;
    }
    int valid = 0;
    for (int i = 0; i < count_point; i++){
        if (email[i] >= 48 && email[i] <= 57){
            valid = 1;
        }
        if (email[i] >= 65 && email[i] <= 90){
            valid = 1;
        }
        if (email[i] >= 97 && email[i] <= 122){
            valid = 1;
        }
        if (email[i] == 95){
           valid = 1;
        }
        else if (valid == 0){
            printf("Email name characters are invalid.\n");
            return 0;
        }
        valid = 0;
   }
    if (email[count_point] != 64){
         printf("Email is missing @ symbol.\n"); 
         return 0;
    }

   if (email[count_point + 1] == 46){
    if (email[count_point + 2] == 101){
        if (email[count_point + 3] == 100){
            if (email[count_point + 4] == 117){
                printf("Email is missing domain."\n);
                return 0;
            }
        }
    }
   }
  if (email[count_point + 1] == 46){
   if (email[count_point + 2] == 99){
        if (email[count_point + 3] == 111){
            if (email[count_point + 4] == 109){
                printf("Email is missing domain.\n");
                return 0;
            }
        }
    }
  }
   if (email[count_point + 1] == 46){
    if (email[count_point + 2] == 110){
        if (email[count_point + 3] == 101){
            if (email[count_point + 4] == 116){
                printf("Email is missing domain.\n");
                return 0;
            }
        }
     }
   }

    int domain_size = count - count_point - 4;
    if (domain_size > 64){
        printf("Email domain length is invalid.\n");
        return 0;
    }

    if (email[count_point + 2] < 65 || (email[count_point + 2] > 90 && email[count_point + 2] < 97) || email[count_point + 2] > 122){
        printf("Email domain start is invalid.\n");
        return 0;
    }

    for (int i = count_point++; i < count; i++){
        if ((email[i] >= 48 && email[i] <= 57) || (email[i] >= 65 && email[i] <= 90) || (email[i] >= 97 && email[i] <= 122) || email[i] == 46){
            break;
        }
        else{
            printf("Email domain characters are invalid.\n");
            return 0;
        }
    }
    int edu = 0;
    if (email[count - 4] == 46){
        if (email[count - 3] == 101){
            if (email[count - 2] == 100){
                if (email[count - 1] == 117){
                    edu = 1;
                }
            }
        }
    }

    int net = 0;
    if (email[count - 4] == 46){
        if (email[count - 3] == 110){
            if (email[count - 2] == 101){
                if (email[count - 1] == 116){
                    net = 1;
                }
            }
        }
    }
    int com = 0;
    if (email[count - 4] == 46){
        if (email[count - 3] == 99){
            if (email[count - 2] == 111){
               if (email[count - 1] == 109) {
                   com = 1;
               }
            }
        }
    }
    else if (edu == 0 && net == 0 && com == 0) {
        printf("Top level domain is invalid.\n");
        return 0;
    }

    printf("Email is valid.\n");
    return 1;
}

/*
 * The following password requirements must be verified:
 *  - May use any character except spaces (i.e., "my password" is invalid)
 *  - Must contain at least 8 characters (i.e., "Password" has 8 characters
 *    and is valid)
 *  - May have at most 16 characters (i.e., "1234567890Abcdef" has 16
 *    characters and is valid)
 *  - Must contain at least one upper case character [A-Z]
 *  - Must contain at least one lower case character [a-z]
 *
 *
 * @param pwd : The original password string
 * @param len : Size of the original password input buffer
 * @return 1 if valid, 0 if not
 */
int Verify_Password(char pwd[], size_t len) {

    int count = 0;
    while (pwd[count] != 0){
        count++;
    }
    for (int i = 0; i < count; i++){
        if (pwd[i] == 32){
            printf("Password may not contain spaces.\n");
            return 0;
        }
    }

    if (count < 8){
        printf("Password length is invalid.\n");
        return 0;
    }

    if (count > 16){
        printf("Password length is invalid.\n");
        return 0;
    }
    int upper = 0;
    for (int i = 0; i < count; i++){
        if (pwd[i] >= 65 || pwd[i] <= 90){
            upper = 1;
        }
        else if (upper == 0){
            printf("Password must contain an uppercase character.\n");
            return 0;
        }
        upper = 0;
    }
    int lower = 0;
    for (int i = 0; i < count; i++){
        if (pwd[i] >= 97 || pwd[i] <= 122){
            break;
        }
        else if (lower == 0){
            printf("Password must contain a lowercase character.\n");
            return 0;
        }
        lower = 0;
    }

    printf("Password is valid.\n");
    return 1;
}
/*
 * Original Password and the Reentered Password must match
 *
 * @param pwd1 : The original password string
 * @param len1 : Size of the original password input buffer
 * @param pwd2 : The reentered password string
 * @param len2 : Size of the renetered password input buffer
 * @return 1 if valid, 0 if not
 */
int Verify_Passwords_Match(char pwd1[], size_t len1, char pwd2[], size_t len2) {

    int count1 = 0;
    int count2 = 0;
    while (pwd1[count1] != 0){
        count1++;
    }
    while (pwd2[count2] != 0){
        count2++;
    }

    for (int i = 0; i < count1; i++){
        if (count1 != count2){
            printf("Password does not match.\n");
            return 0;
        }
        if (pwd1[i] != pwd2[i]){
            printf("Password does not match.\n");
            return 0;
        }
    }

    printf("Passwords match.\n");
    return 1;
}

/******************************************************************************
 * I/O functions
 *****************************************************************************/

/*
 * Prompts user with an input and reads response from stdin
 *
 * @param message : Prompt displayed to the user
 * @param data : char array to hold user repsonse
 * @param MAX_LENGTH : Size of user response input buffer
 */
void Get_User_Data(char *message, char *data, const int MAX_LENGTH) {
    printf("%s", message);
    fgets(data, MAX_LENGTH, stdin);
    int count = 0;
    while (data[count] != 0){
        count++;
    }

    for (int i = 0; i < count; i++){
        if (data[i] == 10){
            data[i] = 0;
        }
    }
    // search string for \n and replace with \0
    return;
}
