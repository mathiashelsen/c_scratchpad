#include <stdio.h>
#include <stdlib.h>
#include "lazy_list.hpp"

void printChar(char * c)
{
    printf("%c", *c);
}

char * nextChar(char *c)
{
    char *nc = c+1;
    if(*nc == '\0')
        return NULL;

    return nc;

}

int main(void)
{
    char * myStr = "Hello world!\n";
     
    LazyList<char> myList(&nextChar, &printChar, myStr);
    myList.show();

    return EXIT_SUCCESS;
}
