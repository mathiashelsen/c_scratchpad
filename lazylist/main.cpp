#include <stdio.h>
#include <stdlib.h>
#include "lazy_list.hpp"
#include "mapped_list.hpp"

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

// An infinite list
int * nextInt_inf(int *p)
{
    *p = *p + 1;
    return p;
}

int multiplyByThree(int *p)
{
   return (*p * 3);
}

int main(void)
{
   char * myStr = "Hello world!\n";
     
    LazyList<char> myCharList(&nextChar, &printChar, myStr);
    myCharList.show();

    int startInt = 0;

    LazyList<int> myIntList_a( &nextInt, NULL, &startInt);

    MappedList<int> myMappedList_b( &multiplyByThree, &myIntList_a );
    printf("Going to show list B\n");
    myMappedList_b.show();

    return EXIT_SUCCESS;
}
