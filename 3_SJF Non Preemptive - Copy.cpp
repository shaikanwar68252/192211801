
def sjf(processes):
    n = len(processes)
    //Sort the processes based on their burst time in ascending order
    processes = sorted(processes, key=lambda x: x[1])
    //Initialize the current time to 0 and create arrays to store waiting time and turnaround time
    current_time = 0
    waiting_time = [0] * n
    turnaround_time = [0] * n
    //Calculate waiting time and turnaround time for each process
    for i in range(n):
        waiting_time[i] = current_time
        current_time += processes[i][1]
        turnaround_time[i] = current_time
    //Compute the averages of the waiting time and turnaround time over all processes
    avg_waiting_time = sum(waiting_time) / n
    avg_turnaround_time = sum(turnaround_time) / n
    return avg_waiting_time, avg_turnaround_time

//Define the processes with their burst time
processes = [("P1", 6), ("P2", 8), ("P3", 7), ("P4", 3)]
//Call the sjf function and print the results
avg_waiting_time, avg_turnaround_time = sjf(processes)
print("Average waiting time:", avg_waiting_time)
print("Average turnaround time:", avg_turnaround_time)
