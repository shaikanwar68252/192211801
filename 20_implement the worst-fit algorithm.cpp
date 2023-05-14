#include <stdio.h>

int main() {
    int memory_partitions[] = {300, 600, 350, 200, 750, 125};
    int num_partitions = sizeof(memory_partitions) / sizeof(memory_partitions[0]);
    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = sizeof(processes) / sizeof(processes[0]);
    int i, j, largest_index, allocated = 0;
    printf("Worst-fit Memory Allocation:\n");
    for(i = 0; i < num_processes; i++) {
        largest_index = -1;
        for(j = 0; j < num_partitions; j++) {
            if(processes[i] <= memory_partitions[j]) {
                if(largest_index == -1) {
                    largest_index = j;
                } else if(memory_partitions[j] > memory_partitions[largest_index]) {
                    largest_index = j;
                }
            }
        }
        if(largest_index != -1) {
            printf("Process %d allocated to partition %d of size %d\n", i+1, largest_index+1, memory_partitions[largest_index]);
            memory_partitions[largest_index] -= processes[i];
            allocated++;
        } else {
            printf("Process %d cannot be allocated.\n", i+1);
        }
    }
    printf("Memory partitions after allocation:\n");
    for(i = 0; i < num_partitions; i++) {
        printf("%d ", memory_partitions[i]);
    }
    printf("\n");
    return 0;
}
