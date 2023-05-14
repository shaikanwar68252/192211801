#include <stdio.h>
#include <stdbool.h>

#define NUM_PARTITIONS 6

int main()
{
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    int allocation[NUM_PARTITIONS] = {0};
    bool allocated;

    printf("Memory Partitions:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++)
        printf("%d KB\t", partitions[i]);
    printf("\n\n");

    for (int i = 0; i < num_processes; i++)
    {
        allocated = false;
        int best_fit_index = -1;
        for (int j = 0; j < NUM_PARTITIONS; j++)
        {
            if (partitions[j] >= processes[i])
            {
                if (!allocated)
                {
                    best_fit_index = j;
                    allocated = true;
                }
                else if (partitions[j] < partitions[best_fit_index])
                {
                    best_fit_index = j;
                }
            }
        }
        if (allocated)
        {
            allocation[best_fit_index] = processes[i];
            partitions[best_fit_index] -= processes[i];
        }
    }

    printf("Process\t\tAllocated Memory\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d KB\t\t", processes[i]);
        if (allocation[i] != 0)
            printf("%d KB\n", allocation[i]);
        else
            printf("Not Allocated\n");
    }

    printf("\nRemaining Memory:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++)
        printf("%d KB\t", partitions[i]);
    printf("\n");

    return 0;
}
