#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/md5.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        return EXIT_FAILURE;
    }else{
        char *inputString       = argv[1];
        int  N                  = strlen(inputString);

        const unsigned char *d  = (const unsigned char *) inputString;
        unsigned char md[16];

        MD5(d, N, md);

        printf("You have entered: %s, which has length %d.\n", inputString, N);
        printf("The hash of this text is: ");
        for(int i = 0; i < 16; i++)
        {
            printf("%x", md[i]); 
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
