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

// A list of ints that stops at 10
int * nextInt(int *p)
{
    *p = *p + 1;
    if(*p > 10)
    {
        return NULL;
    }

    return p;
}

int main(void)
{
   char * myStr = "Hello world!\n";
     
    LazyList<char> myCharList(&nextChar, &printChar, myStr);
    myCharList.show();

    int startInt = 0;

    LazyList<int> myIntList( &nextInt, NULL, &startInt);
    myIntList.show();

    return EXIT_SUCCESS;
}
