#include <stdio.h>

#define MAX_PROCESSES 4

int main() {
    int arrival_time[MAX_PROCESSES] = {0, 1, 2, 4};
    int burst_time[MAX_PROCESSES] = {5, 3, 3, 1};
    int remaining_time[MAX_PROCESSES];
    int completion_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];
    int i, time, shortest, finish_time, total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    for (i = 0; i < MAX_PROCESSES; i++) {
        remaining_time[i] = burst_time[i];
    }

    for (time = 0; ; time++) {
        shortest = -1;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0 && (shortest == -1 || remaining_time[i] < remaining_time[shortest])) {
                shortest = i;
            }
        }
        if (shortest == -1) {
            continue;
        }
        remaining_time[shortest]--;
        if (remaining_time[shortest] == 0) {
            completion_time[shortest] = time + 1;
            waiting_time[shortest] = completion_time[shortest] - arrival_time[shortest] - burst_time[shortest];
            if (waiting_time[shortest] < 0) {
                waiting_time[shortest] = 0;
            }
            turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
            total_waiting_time += waiting_time[shortest];
            total_turnaround_time += turnaround_time[shortest];
        }
        if (time == 100) {
            printf("Time quantum reached 100ms\n");
            break;
        }
    }

    avg_waiting_time = (float) total_waiting_time / MAX_PROCESSES;
    avg_turnaround_time = (float) total_turnaround_time / MAX_PROCESSES;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2fms\n", avg_waiting_time);
    printf("Average turnaround time: %.2fms\n", avg_turnaround_time);

    return 0;
}
