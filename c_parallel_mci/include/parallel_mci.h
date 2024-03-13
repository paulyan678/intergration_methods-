#pragma once
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct monte_carlo_args {
    float (*f)(float);
    float a;
    float b;
    int n;
    float result;
};

// write a parallel version of the monte carlo integration
float monte_carlo_integration(float (*f)(float), float a, float b, int n, int num_threads);
float my_sin(float x);
void *monte_carlo_integration_thread(void *args);
