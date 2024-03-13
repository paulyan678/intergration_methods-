
#include "parallel_mci.h"


void *monte_carlo_integration_thread(void *args) {
    struct monte_carlo_args *mca = (struct monte_carlo_args *)args;
    float x;
    for (int i = 0; i < mca->n; i++) {
        x = (float)rand() / (float)RAND_MAX * (mca->b - mca->a) + mca->a;
        mca->result += mca->f(x);
    }
    pthread_exit(0);
}

float monte_carlo_integration(float (*f)(float), float a, float b, int n, int num_threads) {
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    struct monte_carlo_args* mca = (struct monte_carlo_args*)malloc(num_threads * sizeof(struct monte_carlo_args));
    float result = 0;
    for (int i = 0; i < num_threads; i++) {
        mca[i].a = a;
        mca[i].b = b;
        mca[i].n = n / num_threads;
        mca[i].f = f;
        mca[i].result = 0;
        pthread_create(&threads[i], NULL, monte_carlo_integration_thread, &mca[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        result += mca[i].result;
    }
    free(threads);
    free(mca);
    return result / n * (b - a);
}