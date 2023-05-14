#include<stdio.h>
#include<stdlib.h>

#define P 3  // Number of processes
#define R 3  // Number of resource types

void detectDeadlock(int max[][R], int allocation[][R], int available[]) {
    int i, j, k;
    int work[R], finish[P];
    int need[P][R];

    // Initializing work vector
    for(i=0; i<R; i++) {
        work[i] = available[i];
    }

    // Initializing finish vector
    for(i=0; i<P; i++) {
        finish[i] = 0;
    }

    // Initializing need matrix
    for(i=0; i<P; i++) {
        for(j=0; j<R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Checking for deadlock
    for(i=0; i<P; i++) {
        if(finish[i] == 0) {
            int canFinish = 1;
            for(j=0; j<R; j++) {
                if(need[i][j] > work[j]) {
                    canFinish = 0;
                    break;
                }
            }
            if(canFinish) {
                finish[i] = 1;
                for(k=0; k<R; k++) {
                    work[k] += allocation[i][k];
                }
                i = -1;
            }
        }
    }

    // Printing the result
    int deadlock = 0;
    for(i=0; i<P; i++) {
        if(finish[i] == 0) {
            printf("Deadlock detected!\n");
            deadlock = 1;
            break;
        }
    }
    if(deadlock == 0) {
        printf("No deadlock detected.\n");
    }
}

int main() {
    int max[P][R] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[P][R] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[R] = {2, 2, 2};
    
    detectDeadlock(max, allocation, available);

    return 0;
}
