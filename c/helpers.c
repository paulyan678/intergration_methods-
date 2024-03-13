#include "helpers.h"

float monte_carlo_integration(float (*f)(float), float a, float b, int n) {
    float sum = 0;
    srand(time(NULL)); // Initialize the random number generator.
    for (int i = 0; i < n; i++) {
        // Corrected the division to ensure it's not an integer division.
        float x = a + (b - a) * ((float)rand() / RAND_MAX);
        sum += f(x);
    }
    return (b - a) * sum / n;
}

float my_sin(float x) {
    return sin(x);
}