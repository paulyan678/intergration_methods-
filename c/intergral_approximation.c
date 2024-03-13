#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Corrected the function name to "monte_carlo_integration"
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

int main() {
    float res;
    // Corrected the function name in the call.
    res = monte_carlo_integration(my_sin, 0, M_PI, 1000000);
    printf("res = %f\n", res);
    return 0;
}
