#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct thread_arg {
    float (*f) (float);
    float start;
    float step_sz;
    int num_steps;
    float result;
} thread_arg;
float midpoint_intergration(float a, float b, int num_steps, int num_threads, float (*f) (float));
void* midpoint_intergration_thread(void* args);