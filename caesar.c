/*
*  2/6/2014
*  caesar.c
*  
*  Robert Hill
*  cs50x
*  
*  This program takes an integer key from the command line, tests for the 
*  key's validity, then gets a string from the user and encrypts the 
*  string by rotating the characters by the value of the key. 
*   
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{   
    // validate number of command line arguments
    while (argc != 2 || atoi(argv[1]) <= 0)   
    {
        printf("Input is not valid\n"); 
        return 1;       
    }    
    
    // convert command argument string to integer 
    int key = atoi(argv[1]); 
          
    // get string from user to encrypt
    string user_string = GetString();
        
    // loop to test for alpha, uppper or lower, and print encrypted text
    for (int count = 0, number = strlen(user_string); count < number; count++)
    {
        if (isalpha(user_string[count]))
        {
            if (isupper(user_string[count]))
            {
                // encipher and print uppercase characters
                printf("%c", ((user_string[count] - 65 + key) % 26) + 65);
            }
            else            
            {            
                // encipher and print lowercase characters
                printf("%c", ((user_string[count] - 97 + key) % 26) + 97);
            }
        }
        else
        {
            // print all other characters
            printf("%c", user_string[count]); 
        }        
     }
    
    printf("\n");
       
    return 0;
}  

 
    
    
    
    
        


