#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 10

// Structure to represent a memory partition
typedef struct {
    int size;
    bool allocated;
} Partition;

// Function to allocate memory using worst-fit algorithm
void worstFit(Partition partitions[], int numPartitions, int processSize) {
    int worstIndex = -1;
    int worstSize = -1;

    // Find the worst-fit partition
    for (int i = 0; i < numPartitions; i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            if (worstIndex == -1 || partitions[i].size > worstSize) {
                worstIndex = i;
                worstSize = partitions[i].size;
            }
        }
    }

    // Allocate the memory partition
    if (worstIndex != -1) {
        partitions[worstIndex].allocated = true;
        printf("Allocated Process with size %d KB to Partition %d\n", processSize, worstIndex + 1);
    } else {
        printf("Failed to allocate Process with size %d KB\n", processSize);
    }
}

// Function to print the memory allocation status
void printMemoryStatus(Partition partitions[], int numPartitions) {
    printf("\nMemory Status:\n");
    for (int i = 0; i < numPartitions; i++) {
        printf("Partition %d: Size %d KB, %s\n", i + 1, partitions[i].size, partitions[i].allocated ? "Allocated" : "Free");
    }
    printf("\n");
}

int main() {
    Partition partitions[MAX_PARTITIONS] = {{40, false}, {10, false}, {30, false}, {60, false}};
    int numPartitions = 4;
    int processSizes[] = {100, 50, 30, 120, 35};
    int numProcesses = 5;

    // Allocate memory for each process
    for (int i = 0; i < numProcesses; i++) {
        worstFit(partitions, numPartitions, processSizes[i]);
        printMemoryStatus(partitions, numPartitions);
    }

    return 0;
}
