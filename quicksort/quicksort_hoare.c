#include "quicksort_hoare.h"

void quicksort_h(unsigned long **A, int lo, int hi, bool debug)
{
    int p;

    if(debug)
    {
        printf("lo = %d, hi = %d\n", lo, hi);
        printf("A = [");
        for(int i = lo; i <= hi; i++)
        {
            printf("%lu ", (*A)[i]);
        };
        printf("]\n");
    }
    if(lo < hi && lo >= 0 && hi >= 0)
    {
        p = partition_h(A, lo, hi, debug);

        quicksort_h(A, lo,  p, debug);
        quicksort_h(A, p+1, hi , debug);
    }

}

int  partition_h(unsigned long **A, int lo, int hi, bool debug)
{
    bool enableLoop = true;
    unsigned long pivotValue = (*A)[lo];
    unsigned long tmp;
    int i = lo-1;
    int j = hi+1;

    if(debug)
        printf("pivotValue = %lu\n", pivotValue);

    while(enableLoop)
    {
        do{
            i++;
        }
        while((*A)[i] < pivotValue);

        do{
            j--;
        }
        while((*A)[j] > pivotValue);

        if(i >= j) {
            enableLoop = false;
        }else{
            if(debug)
                printf("i = %d, j = %d\n", i, j);

            tmp = (*A)[i];
            (*A)[i] = (*A)[j];
            (*A)[j] = tmp;
        }
    }

    return j;

}
