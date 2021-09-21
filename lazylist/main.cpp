#include <stdio.h>
#include <stdlib.h>

#include "List.hpp"
#include "AllocatedList.hpp"
#include "InfiniteList.hpp"
#include "TransformedList.hpp"

void incrementInt(int *p, void *args)
{
    *p += 1;
}

int* takeFive(List<int>* L, int* elem, void *args)
{
    int * intArgs = (int *) args;
    int ctr = *intArgs;
    if(ctr > 5)
        return NULL;

    (*intArgs) = ctr+1;
    return L->next();
}

int main(void)
{
    int myInts[10] = {0,1,2,3,4,5,6,7,8,9};

    AllocatedList myList_A = AllocatedList(myInts, 10);
    myList_A.show();
    myList_A.show();

    int myInt = 0;
    InfiniteList myList_B = InfiniteList(&incrementInt, NULL, &myInt);
    //myList_B.show();

    int ctr = 0;
    TransformedList myList_C = TransformedList(&myList_B, &takeFive, (void *)&ctr);
    myList_C.show();

    return EXIT_SUCCESS;
}
