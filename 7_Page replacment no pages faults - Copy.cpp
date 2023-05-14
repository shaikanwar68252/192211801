#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int pageFaults(int pages[], int n, int capacity) {
    int i, j, k, faults = 0;
    int frame[capacity], counter[capacity];
    for(i=0; i<capacity; i++) {
        frame[i] = -1;  // Initializing frame with -1
        counter[i] = 0; // Initializing counter with 0
    }
    for(i=0; i<n; i++) {
        for(j=0; j<capacity; j++) {
            if(frame[j] == pages[i]) {
                counter[j] = 0;
                break;
            }
        }
        if(j == capacity) {
            int lru = 0;
            for(k=1; k<capacity; k++) {
                if(counter[k] > counter[lru]) {
                    lru = k;
                }
            }
            frame[lru] = pages[i];
            counter[lru] = 0;
            faults++;
        }
        for(j=0; j<capacity; j++) {
            if(frame[j] != -1) {
                counter[j]++;
            }
        }
    }
    return faults;
}

int main() {
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    int faults = pageFaults(pages, n, capacity);
    printf("Number of page faults: %d\n", faults);
    return 0;
}
