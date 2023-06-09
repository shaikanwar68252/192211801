#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

// Function to check if a page exists in the page frames
bool isPageExists(int pageFrames[], int numFrames, int page) {
    for (int i = 0; i < numFrames; i++) {
        if (pageFrames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the index of the page that will not be used for the longest period of time
int findOptimalPage(int pageFrames[], int numFrames, int pages[], int numPages, int currentPageIndex) {
    int farthestIndex = -1;
    int farthestDistance = -1;

    for (int i = 0; i < numFrames; i++) {
        int page = pageFrames[i];
        int j;
        for (j = currentPageIndex + 1; j < numPages; j++) {
            if (pages[j] == page) {
                if (j - currentPageIndex > farthestDistance) {
                    farthestIndex = i;
                    farthestDistance = j - currentPageIndex;
                }
                break;
            }
        }
        if (j == numPages) {
            return i;
        }
    }

    return farthestIndex;
}

// Function to simulate the Optimal page replacement algorithm
int optimalPageReplacement(int pageFrames[], int numFrames, int pages[], int numPages) {
    int numFaults = 0;

    for (int i = 0; i < numPages; i++) {
        if (!isPageExists(pageFrames, numFrames, pages[i])) {
            int optimalIndex = findOptimalPage(pageFrames, numFrames, pages, numPages, i);
            pageFrames[optimalIndex] = pages[i];
            numFaults++;
        }
    }

    return numFaults;
}

int main() {
    int pageFrames[MAX_FRAMES] = {0};
    int numFrames = 3;
    int pages[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);

    int numFaults = optimalPageReplacement(pageFrames, numFrames, pages, numPages);

    printf("Number of page faults: %d\n", numFaults);

    return 0;
}
