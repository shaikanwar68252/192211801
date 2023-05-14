#include <stdio.h>

int main() {
    int num_processes = 3;
    int burst_times[] = {24, 3, 3};
    int remaining_burst_times[num_processes], waiting_times[num_processes], turnaround_times[num_processes];

    // Initialize the remaining burst time for each process to its burst time
    for (int i = 0; i < num_processes; i++) {
        remaining_burst_times[i] = burst_times[i];
    }

    // Initialize the waiting time for each process to 0
    for (int i = 0; i < num_processes; i++) {
        waiting_times[i] = 0;
    }

    int time = 0;
    while (1) {
        int done = 1;

        // Traverse all processes one by one repeatedly
        for (int i = 0; i < num_processes; i++) {
            if (remaining_burst_times[i] > 0) {
                done = 0;

                // If burst time is greater than the quantum time, execute for a quantum time
                if (remaining_burst_times[i] > 4) {
                    time += 4;
                    remaining_burst_times[i] -= 4;
                } 
                // If burst time is smaller than or equal to the quantum time, execute for remaining burst time
                else {
                    time += remaining_burst_times[i];
                    waiting_times[i] = time - burst_times[i];
                    remaining_burst_times[i] = 0;
                }
            }
        }
        // When all processes are done, exit the loop
        if (done == 1) {
            break;
        }
    }

    // Calculate the turnaround time for each process
    for (int i = 0; i < num_processes; i++) {
        turnaround_times[i] = waiting_times[i] + burst_times[i];
    }

    // Calculate the average waiting and turnaround times
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turnaround_times[i];
    }
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);

    return 0;
}
