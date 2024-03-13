
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float monte_carlo_integration(float (*f)(float), float a, float b, int n);
float my_sin(float x);