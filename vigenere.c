/*
*  2/10/2014
*
*  vigenere.c
*
*  Robert Hill
*  cs50x
*
*  This progrom takes a command line string argument as a key that is 
*  used to encrypt a string of text. The methond in which the text is 
*  encrypted is a vigenere ciphor in which the plaintext characters
*  are rotated by the value of the characters of the key.  
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{   
           
    // validate the number of command-line arguments, i.e argc, equals 2
    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }
    
    // set and initialize variables for the keyword and length of keyword
    string kword = argv[1];
    int klength = strlen(kword);
    
    // validate there are no digits in the command line argument
    // convert keyword characters to represent 0 through 25
    for (int i = 0, n = strlen(kword); i < n; i++)
    {
        if (isdigit(kword[i]))
        {        
            printf("Invalid input\n");
            return 1;
        }
        if (islower(kword[i]))
        {
            kword[i] = (kword[i] % 97);
        }
        else
        {
            kword[i] = (kword[i] % 65);
        }
    } 
    
    // get text input to be enciphered
    string ptext = GetString();
    
    // set counter variable for keyword
    int j = 0;
    
    // loop to encrypt each character and print the cipher text           
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {  
        if (isalpha(ptext[i]))
        {
            if (isupper(ptext[i]))
            {   
                printf("%c", ((ptext[i] % 65 + kword[j % klength]) % 26 + 65)); 
                j++;
            }         
            else if (islower(ptext[i]))
            {
                printf("%c", ((ptext[i] % 97 + kword[j % klength]) % 26 + 97));
                j++;
            }
        }
        else
        {
            printf("%c", ptext[i]);
        }
       }
    printf("\n");
    return 0;
}



