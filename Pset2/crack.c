#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// https://github.com/mareksuscak/cs50/blob/master/pset2/crack/crack.c
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s hash\n", argv[0]);
        return 1;
    }
    
    int totalCount = 53;
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];
    
    char candidate[6] = "\0\0\0\0\0\0";
    
    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';
    
    for (int five = 0; five<totalCount; five++)
    {
        for (int four = 0; four<totalCount; four++)
        {
            for (int three = 0; three<totalCount; three++)
            {
                for (int two = 0; two<totalCount; two++)
                {
                    for (int one = 0; one<totalCount; one++)
                    {
                        candidate[0] = letters[one];
                        candidate[1] = letters[two];
                        candidate[2] = letters[three];
                        candidate[3] = letters[four];
                        candidate[4] = letters[five];
                        if (strcmp(hash , crypt(candidate, salt)) == 0)
                        {
                            printf("%s\n", candidate);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Password cannot be cracked.\n");
    return 2;
}
