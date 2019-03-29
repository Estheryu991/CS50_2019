#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Create function
int shift(char c);
int main(int argc, string argv[])
{
    // argc needs to be two
    if (argc != 2) 
    {
        printf("Usage %s keyword\n", argv[0]);
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
        // If character is digit, print wrong message, and return
        // It has to be alphabet
        if (isdigit(str[i])) 
        {
            printf("Usage %s keyword\n", argv[0]);
            return 1;
        }
    }
    
    // Create spaces int, due to adding the spaces 
    int spaces = 0;
    // Create current key, it'll later depend on index of character
    int key;

    // Get plaintext
    string plain = get_string("plaintext: ");

    // Print ciphertext, later loop through characters
    printf("ciphertext: ");
    
    for (int i=0, length = strlen(plain); i<length; i++)
    {
        // Add spaces for calculation
        if (isspace(plain[i]) || ispunct(plain[i]))
        {
            spaces += 1;
        }
        int index = (i-spaces) % strlen(argv[1]);

        // Set key depend on upper or lower
        key = shift(argv[1][index]);
        
        // Add key to text
        if (isupper(plain[i]))
        {
            printf("%c", ( ((plain[i]-65) + key) % 26 + 65) );
        } 
        else if (islower(plain[i]))
        {
            printf("%c", ( ((plain[i]-97) + key) % 26 + 97) );
        }
        else 
        {
            printf("%c", plain[i]);
        }
    }
    // Finish looping through and priint characters, print \n
    printf("\n");
    
    
}
// Shift function
int shift(char c)
{
    if (isupper(c))
    {
        return (c-65) % 26;
    }
    else
    {
        return (c-97) % 26;
    }
}
