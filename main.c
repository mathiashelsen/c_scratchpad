#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <gsl/gsl_rng.h>

#include "quicksort/quicksort_lomuto.h"

int main(int argc, char **argv)
{
    gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);
    struct timespec begin, end;

    int i = 0;
    int iters = 15;
    int N = 128;
    for(int j = 0; j < iters; j++)
    {
        long unsigned int *A = malloc(sizeof(long unsigned int)*N);

        for(i = 0; i < N; i++)
        {
            //A[i] = gsl_rng_uniform_int(r, 100); // Limit the upper value of the RNG (debug)
            A[i] = gsl_rng_get(r);
        };

        clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

        quicksort_l(&A, 0, N-1);

        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        printf ("%d %e\n", N,
            (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec));
        free(A);

        N *= 2;
    }

    gsl_rng_free(r);
    return EXIT_SUCCESS;
}
