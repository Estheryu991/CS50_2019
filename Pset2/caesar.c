#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // argc needs to be two
    if (argc != 2) 
    {
        printf("Usage %s key\n", argv[0]);
        return 1;
    };
    
    // Create array of char with size of 50
    // Create len for length of str
    char str[50];
    int len;
    // Copy argv[1] to str
    // Get length of str
    strcpy(str, argv[1]);
    len = strlen(str);
    
    // Loop through str
    for (int i=0; i<len; i++)
    {
        // If character is alphabet, print wrong message, and return
        // It has to be number
        if (isalpha(str[i])) 
        {
            printf("Usage %s key\n", argv[0]);
            return 1;
        }
    }
    
    // Change str to int
    int k = atoi(argv[1]);
    // k has to be greater or equal to zero
    if (k<0) 
    {
        printf("Usage %s key\n", argv[0]);
        return 1;
    } 
    
    // Get plaintext
    string plain = get_string("plaintext: ");
    
    // Print ciphertext, later loop through characters
    printf("ciphertext: ");

    // Loop through characters and transform by ASCII
    for (int i=0, length = strlen(plain); i<length; i++)
    {
        if (isupper(plain[i]))
        {
            printf("%c", ( ((plain[i]-65) + k) % 26 + 65) );
        } 
        else if (islower(plain[i]))
        {
            printf("%c", ( ((plain[i]-97) + k) % 26 + 97) );
        }
        else 
        {
            printf("%c", plain[i]);
        }
    }

    // Finish looping through and priint characters, print \n
    printf("\n");
    
    
}