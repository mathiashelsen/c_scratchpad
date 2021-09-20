#include "quicksort_lomuto.h"


void quicksort_l(unsigned long **A, int lo, int hi)
{
    int p;

    if(lo < hi && lo >= 0 && hi >= 0)
    {
        p = partition_l(A, lo, hi);

        quicksort_l(A, lo,  p-1);
        quicksort_l(A, p+1, hi );
    }
}

int partition_l(unsigned long **A, int lo, int hi)
{
    unsigned long pivotValue;   // The value of the pivot
    unsigned long tmp;
    int indexSmall;             // The last smaller value than the pivotValue
    int indexLoop;              // The index of where we are in the array

    indexSmall = lo;
    pivotValue = (*A)[hi];

    for(indexLoop = lo; indexLoop <= hi; indexLoop++)
    {
        if((*A)[indexLoop] <= pivotValue)
        {
            tmp = (*A)[indexSmall];
            (*A)[indexSmall] = (*A)[indexLoop];
            (*A)[indexLoop]  = tmp;
            indexSmall++;
        }
    }

    return (indexSmall-1);
}
