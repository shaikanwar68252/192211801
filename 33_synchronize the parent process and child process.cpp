#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate the Fibonacci series
void generateFibonacci(int n) {
    int first = 0, second = 1;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        int next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int n = 10; // Number of Fibonacci numbers to generate
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        generateFibonacci(n);
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to complete

        printf("Prime numbers: ");
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
