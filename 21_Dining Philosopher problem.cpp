#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define constants for states of philosopher
#define THINKING 0
#define HUNGRY 1
#define EATING 2

// Define the number of philosophers and forks
#define N 5

// Define a mutex lock for accessing the forks
pthread_mutex_t forks[N];

// Define a condition variable for each philosopher
pthread_cond_t cond_vars[N];

// Define a list to store the state of each philosopher
int state[N] = {THINKING};

// Define a function for a philosopher to pick up forks
void pick_forks(int i) {
    pthread_mutex_lock(&forks[i]);
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry.\n", i);
    pthread_cond_wait(&cond_vars[i], &forks[i]);
    pthread_mutex_unlock(&forks[i]);
}

// Define a function for a philosopher to release forks
void release_forks(int i) {
    pthread_mutex_lock(&forks[i]);
    state[i] = THINKING;
    printf("Philosopher %d is thinking.\n", i);
    if (state[(i + N - 1) % N] == HUNGRY && state[(i + N - 2) % N] != EATING) {
        state[(i + N - 1) % N] = EATING;
        pthread_cond_signal(&cond_vars[(i + N - 1) % N]);
    }
    if (state[(i + 1) % N] == HUNGRY && state[(i + 2) % N] != EATING) {
        state[(i + 1) % N] = EATING;
        pthread_cond_signal(&cond_vars[(i + 1) % N]);
    }
    pthread_mutex_unlock(&forks[i]);
}

// Define a function for a philosopher to run
void *philosopher(void *arg) {
    int i = *((int *) arg);
    while (1) {
        printf("Philosopher %d is thinking.\n", i);
        sleep(rand() % 5 + 1);
        pick_forks(i);
        printf("Philosopher %d is eating.\n", i);
        sleep(rand() % 5 + 1);
        release_forks(i);
    }
}

int main() {
    int i;
    pthread_t threads[N];
    int ids[N];
    srand(time(NULL));

    // Initialize the mutex locks and condition variables
    for (i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&cond_vars[i], NULL);
    }

    // Create the threads for the philosophers
    for (i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
