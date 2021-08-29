#ifndef _QUICKSORT_HOARE_H
#define _QUICKSORT_HOARE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quicksort_h(unsigned long **A, int lo, int hi, bool debug);
int  partition_h(unsigned long **A, int lo, int hi, bool debug);

#endif
