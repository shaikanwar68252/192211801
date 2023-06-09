#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the absolute difference between two numbers
int absDiff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

// Function to simulate the CSCAN disk scheduling algorithm
void cscanDiskScheduling(int tracks[], int numTracks, int initialPosition) {
    int i, currentPos, totalHeadMovement = 0;
    int start, end, direction;

    // Sort the tracks in ascending order
    sortArray(tracks, numTracks);

    // Find the start and end points of the disk
    for (i = 0; i < numTracks; i++) {
        if (tracks[i] > initialPosition) {
            start = i;
            end = numTracks - 1;
            break;
        }
    }

    // Calculate the head movement towards the end of the disk
    printf("Head Movement Sequence: %d ", initialPosition);
    for (i = start; i < numTracks; i++) {
        printf("%d ", tracks[i]);
        totalHeadMovement += absDiff(currentPos, tracks[i]);
        currentPos = tracks[i];
    }

    // Calculate the head movement towards the start of the disk
    printf("0 ");
    totalHeadMovement += absDiff(currentPos, 0);
    currentPos = 0;

    for (i = 0; i <= end; i++) {
        printf("%d ", tracks[i]);
        totalHeadMovement += absDiff(currentPos, tracks[i]);
        currentPos = tracks[i];
    }

    printf("\n");

    // Calculate and print the average head movement
    float averageHeadMovement = (float)totalHeadMovement / numTracks;
    printf("Average Head Movement: %.2f\n", averageHeadMovement);
}

int main() {
    int numTracks = 5;
    int tracks[] = {55, 58, 60, 70, 18};
    int initialPosition = 55;

    printf("Track Positions: ");
    for (int i = 0; i < numTracks; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    printf("Initial Position: %d\n", initialPosition);

    cscanDiskScheduling(tracks, numTracks, initialPosition);

    return 0;
}