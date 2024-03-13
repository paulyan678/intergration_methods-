#include "parallel_midpoint.h"


void* midpoint_intergration_thread(void* args) {
    thread_arg *mig = (thread_arg *)args;
    float result = 0;
    int num_steps = mig->num_steps;
    int step_sz = mig->step_sz;
    float (*f) (float) = mig->f;
    float start = mig->start;
    
    for (int i = 0; i < num_steps; i++) {
        result += f(start + i*step_sz + step_sz/2);
    }
    mig->result = result;
    pthread_exit(0);
}

float midpoint_intergration(float a, float b, int num_steps, int num_threads, float (*f) (float)) {
    float step_sz = (b - a) / num_steps;
    pthread_t* threads = (pthread_t*)malloc(num_threads*sizeof(pthread_t));
    thread_arg* thread_args = (thread_arg*)malloc(num_threads*sizeof(thread_arg));
    int num_steps_per_thread = (int) num_steps/num_threads;
    float result = 0.0;
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].start = a + i*num_steps_per_thread*step_sz;
        thread_args[i].num_steps = (num_steps_per_thread + num_steps % num_threads) ? i == num_threads - 1 : num_steps_per_thread;
        thread_args[i].step_sz = step_sz;
        thread_args[i].f = f;
        pthread_create(threads + i, NULL, midpoint_intergration_thread, thread_args + i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        result += thread_args[i].result;
    }
    free(threads);
    free(thread_args);
    return result * step_sz;
}