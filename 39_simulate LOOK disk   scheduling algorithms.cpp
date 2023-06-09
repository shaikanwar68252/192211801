#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

// Function to find the absolute difference between two track positions
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to calculate the total head movement using the LOOK algorithm
int calculateHeadMovement(int tracks[], int numTracks, int startTrack, int direction) {
    int currentPosition = startTrack;
    int totalMovement = 0;

    while (1) {
        // Check if the current track exists in the given tracks
        int i;
        for (i = 0; i < numTracks; i++) {
            if (tracks[i] == currentPosition) {
                tracks[i] = -1;
                break;
            }
        }

        // If current track not found, break the loop
        if (i == numTracks) {
            break;
        }

        // Update the total movement
        totalMovement += absDiff(currentPosition, tracks[i]);

        // Update the current position based on the direction
        if (direction == 1) {
            currentPosition++;
        } else {
            currentPosition--;
        }
    }

    return totalMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int startTrack = 50;
    int direction = 1; // 1 for moving towards higher tracks, -1 for moving towards lower tracks
    int totalMovement;

    totalMovement = calculateHeadMovement(tracks, numTracks, startTrack, direction);

    printf("Average head movement: %f\n", (float)totalMovement / numTracks);

    return 0;
}
