#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TRACKS 100

// Function to find the absolute difference between two track positions
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to find the index of the track with the shortest seek time from the current position
int findShortestSeekTime(int tracks[], int numTracks, int currentPosition) {
    int shortestIndex = -1;
    int shortestSeekTime = -1;

    for (int i = 0; i < numTracks; i++) {
        if (tracks[i] != -1) {
            int seekTime = absDiff(tracks[i], currentPosition);
            if (shortestIndex == -1 || seekTime < shortestSeekTime) {
                shortestIndex = i;
                shortestSeekTime = seekTime;
            }
        }
    }

    return shortestIndex;
}

// Function to calculate the total head movement using the SSTF algorithm
int calculateHeadMovement(int tracks[], int numTracks, int startTrack) {
    int currentPosition = startTrack;
    int totalMovement = 0;

    for (int i = 0; i < numTracks; i++) {
        int shortestIndex = findShortestSeekTime(tracks, numTracks, currentPosition);
        totalMovement += absDiff(tracks[shortestIndex], currentPosition);
        currentPosition = tracks[shortestIndex];
        tracks[shortestIndex] = -1;
    }

    return totalMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int startTrack = 50;
    int totalMovement;

    totalMovement = calculateHeadMovement(tracks, numTracks, startTrack);

    printf("Average head movement: %f\n", (float)totalMovement / numTracks);

    return 0;
}
