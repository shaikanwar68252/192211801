#include <stdio.h>
#include <stdlib.h>

#define NUM_TRACKS 9

// Function to sort the tracks in ascending order
void sortTracks(int tracks[], int numTracks) {
    int i, j, temp;
    for (i = 0; i < numTracks - 1; i++) {
        for (j = 0; j < numTracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
}

// Function to find the index of the track where head is located
int findHeadIndex(int tracks[], int numTracks, int headPosition) {
    int i;
    for (i = 0; i < numTracks; i++) {
        if (tracks[i] >= headPosition) {
            return i;
        }
    }
    return numTracks - 1;
}

// Function to calculate the total head movement
int calculateHeadMovement(int tracks[], int numTracks, int headPosition) {
    int headIndex = findHeadIndex(tracks, numTracks, headPosition);
    int i, totalMovement = 0;

    // Calculate head movement while moving towards the higher tracks
    for (i = headIndex; i < numTracks; i++) {
        totalMovement += abs(tracks[i] - headPosition);
        headPosition = tracks[i];
    }

    // Calculate head movement while moving towards the lower tracks
    totalMovement += abs(headPosition - tracks[numTracks - 1]);
    headPosition = tracks[numTracks - 1];

    for (i = numTracks - 2; i >= 0; i--) {
        totalMovement += abs(tracks[i] - headPosition);
        headPosition = tracks[i];
    }

    return totalMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int numTracks = NUM_TRACKS;
    int headPosition = 50;
    int totalMovement;

    sortTracks(tracks, numTracks);
    totalMovement = calculateHeadMovement(tracks, numTracks, headPosition);

    printf("Average head movement: %f\n", (float)totalMovement / numTracks);

    return 0;
}
