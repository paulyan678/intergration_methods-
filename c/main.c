#include "main.h"
#include "helpers.h"


// Corrected the function name to "monte_carlo_integration"


int main(int argc, char *argv[]) {
    float res;
    // Corrected the function name in the call.
    float upper, lower;
    int num_steps;
    if (argc == 4) {
        upper = atof(argv[1]);
        lower = atof(argv[2]);
        num_steps = atoi(argv[3]);

    } else {
        //raise error
        return 1;
    }
    res = monte_carlo_integration(my_sin, lower, upper, num_steps);
    printf("res = %f\n", res);
    return 0;
}
