#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 3

// Shared variables
int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int in = 0; // Index of next empty position in the buffer
int out = 0; // Index of next full position in the buffer

// Semaphores
sem_t mutex; // Protects access to shared variables
sem_t full; // Counts number of full slots in the buffer
sem_t empty; // Counts number of empty slots in the buffer

// Producer thread function
void *producer(void *arg)
{
    int item;
    
    for (int i = 0; i < 4; i++) {
        item = rand(); // Produce random item
        
        sem_wait(&empty); // Wait for empty slot
        sem_wait(&mutex); // Enter critical section
        
        buffer[in] = item; // Insert item into buffer
        in = (in + 1) % BUFFER_SIZE; // Increment index, wrap around if necessary
        count++; // Increment count of items in buffer
        
        printf("Produced item: %d\n", item);
        
        sem_post(&mutex); // Leave critical section
        sem_post(&full); // Signal that a slot is now full
    }
    
    return NULL;
}

// Consumer thread function
void *consumer(void *arg)
{
    int item;
    
    for (int i = 0; i < 1; i++) {
        sem_wait(&full); // Wait for full slot
        sem_wait(&mutex); // Enter critical section
        
        item = buffer[out]; // Remove item from buffer
        out = (out + 1) % BUFFER_SIZE; // Increment index, wrap around if necessary
        count--; // Decrement count of items in buffer
        
        printf("Consumed item: %d\n", item);
        
        sem_post(&mutex); // Leave critical section
        sem_post(&empty); // Signal that a slot is now empty
    }
    
    return NULL;
}

int main()
{
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    
    // Create producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    // Clean up semaphores
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    
    return 0;
}
