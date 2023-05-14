#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int n = 5;
    int tracks[] = {55, 58, 60, 70, 18};
    int head, i, distance = 0;
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    for(i=0; i<n; i++) {
        distance += abs(tracks[i] - head);
        head = tracks[i];
    }
    printf("Average head movement: %f\n", (float)distance / n);
    return 0;
}
