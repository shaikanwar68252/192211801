#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

// Structure to represent a process
typedef struct {
    int processId;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    bool completed;
} Process;

// Function to swap two processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the processes based on burst time (SJF scheduling)
void sortProcesses(Process processes[], int numProcesses) {
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = 0; j < numProcesses - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

// Function to calculate the average waiting time and average turnaround time
void calculateAverageTimes(Process processes[], int numProcesses, float *avgWaitingTime, float *avgTurnaroundTime) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < numProcesses; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    *avgWaitingTime = (float)totalWaitingTime / numProcesses;
    *avgTurnaroundTime = (float)totalTurnaroundTime / numProcesses;
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses = 3;
    float avgWaitingTime, avgTurnaroundTime;

    // Initialize the processes
    processes[0].processId = 0;
    processes[0].burstTime = 2;
    processes[0].arrivalTime = 0;
    processes[0].completed = false;

    processes[1].processId = 1;
    processes[1].burstTime = 4;
    processes[1].arrivalTime = 0;
    processes[1].completed = false;

    processes[2].processId = 2;
    processes[2].burstTime = 8;
    processes[2].arrivalTime = 0;
    processes[2].completed = false;

    // Sort the processes based on burst time (SJF scheduling)
    sortProcesses(processes, numProcesses);

    // Calculate the average waiting time and average turnaround time
    calculateAverageTimes(processes, numProcesses, &avgWaitingTime, &avgTurnaroundTime);

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
