#include <stdio.h>

int main() {
    int n = 3; // number of processes
    int burst_times[] = {2, 4, 8}; // burst times of processes
    int waiting_times[n], turnaround_times[n];
    int i;
    float total_waiting_time = 0, total_turnaround_time = 0;
  
    // waiting time for the first process is always 0
    waiting_times[0] = 0;
  
    // calculate waiting time and turnaround time for each process
    for (i = 1; i < n; i++) {
        waiting_times[i] = waiting_times[i-1] + burst_times[i-1];
        turnaround_times[i-1] = waiting_times[i-1] + burst_times[i-1];
    }
    turnaround_times[n-1] = waiting_times[n-1] + burst_times[n-1];

    // calculate total waiting time and turnaround time
    for (i = 0; i < n; i++) {
        total_waiting_time += waiting_times[i];
        total_turnaround_time += turnaround_times[i];
    }

    // calculate average waiting time and average turnaround time
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
