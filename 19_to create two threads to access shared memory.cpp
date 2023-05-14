#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SHARED_MEM_SIZE 1

sem_t sem;
int shared_mem[SHARED_MEM_SIZE];

void *thread1(void *arg) {
    while (1) {
        sem_wait(&sem);
        int data = shared_mem[0];
        printf("Thread 1: Read %d from shared memory\n", data);
        data *= 2;
        printf("Thread 1: Doubled value is %d\n", data);
        shared_mem[0] = data;
        sem_post(&sem);
        sleep(1);
    }
    return NULL;
}

void *thread2(void *arg) {
    while (1) {
        sem_wait(&sem);
        int data = shared_mem[0];
        printf("Thread 2: Read %d from shared memory\n", data);
        data *= 5;
        printf("Thread 2: Five times value is %d\n", data);
        shared_mem[0] = data;
        sem_post(&sem);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    sem_init(&sem, 0, 1);
    shared_mem[0] = 5;
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_destroy(&sem);
    return 0;
}
