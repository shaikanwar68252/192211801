#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_REQUESTS 100

int main()
{
    int requests[MAX_REQUESTS];
    int num_requests;

    printf("Enter the number of requests: ");
    scanf("%d", &num_requests);

    printf("Enter the track positions: ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    int head_position;
    printf("Enter the head position: ");
    scanf("%d", &head_position);

    int total_head_movement = 0;

    for (int i = 0; i < num_requests; i++) {
        total_head_movement += abs(requests[i] - head_position);
        head_position = requests[i];
    }

    float average_head_movement = (float)total_head_movement / num_requests;
    printf("Average head movement: %f\n", average_head_movement);

    return 0;
}
