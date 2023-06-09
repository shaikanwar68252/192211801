#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

// Function to find the absolute difference between two track positions
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to calculate the total head movement using the CLOOK algorithm
int calculateHeadMovement(int tracks[], int numTracks, int startTrack) {
    int currentPosition = startTrack;
    int totalMovement = 0;

    // Sort the track positions in ascending order
    for (int i = 0; i < numTracks - 1; i++) {
        for (int j = 0; j < numTracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the index of the start track
    int startTrackIndex = -1;
    for (int i = 0; i < numTracks; i++) {
        if (tracks[i] >= startTrack) {
            startTrackIndex = i;
            break;
        }
    }

    // Calculate the total movement
    for (int i = startTrackIndex; i < numTracks; i++) {
        totalMovement += absDiff(currentPosition, tracks[i]);
        currentPosition = tracks[i];
    }
    for (int i = 0; i < startTrackIndex; i++) {
        totalMovement += absDiff(currentPosition, tracks[i]);
        currentPosition = tracks[i];
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
