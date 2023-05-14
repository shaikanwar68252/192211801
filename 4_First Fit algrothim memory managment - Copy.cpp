#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int i, j, allocated;
    int n_partitions = MAX_PARTITIONS;
    int n_processes = MAX_PROCESSES;

    for (i = 0; i < n_processes; i++) {
        allocated = 0;
        for (j = 0; j < n_partitions; j++) {
            if (processes[i] <= partitions[j]) {
                printf("Process %d (size %d KB) is allocated to partition %d (size %d KB)\n",
                       i + 1, processes[i], j + 1, partitions[j]);
                partitions[j] -= processes[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Process %d (size %d KB) cannot be allocated\n", i + 1, processes[i]);
        }
    }

    return 0;
}
