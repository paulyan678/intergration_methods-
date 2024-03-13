#include <stdio.h>
#include <stdlib.h>
#include "parallel_midpoint.h"
#include <math.h>

float my_sin(float x) {
    return sin(x);
}

int main(int nargs, char **args) {
    int a, b, n, num_threads;
    if (nargs == 5) {
        a = atof(args[1]);
        b = atof(args[2]);
        n = atoi(args[3]);
        num_threads = atoi(args[4]);
    } else {
        printf("Usage: %s a b n num_threads\n", args[0]);
        return 1;
    }
    float result = midpoint_intergration(a, b, n, num_threads, my_sin);
    printf("Result: %f\n", result);
    return 0;
}