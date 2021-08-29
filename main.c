#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_rng.h>

int main(int argc, char **argv)
{
    gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);

    int i = 0;
    int N = 10000;
    long unsigned int *A = malloc(sizeof(long unsigned int)*N);

    printf("[");
    for(i = 0; i < N; i++)
    {
        A[i] = gsl_rng_get(r);
        printf("%lu ", A[i]);
    }
    printf("]\n");

    free(A);
    gsl_rng_free(r);
    return EXIT_SUCCESS;
}
