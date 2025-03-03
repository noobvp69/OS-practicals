#include<stdio.h>

struct process {
    int id, at, bt, wt, tat, ct;  // Use abbreviations for Arrival Time (at), Burst Time (bt), Waiting Time (wt), Turnaround Time (tat), Completion Time (ct)
};

void main() {
    int i, n;
    float avg_wt = 0, avg_tat = 0;

    // Take input for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    // Input process details (ID, arrival time, and burst time)
    for(i = 0; i < n; i++) {
        p[i].id = i + 1;  // Process IDs start from 1
        printf("\nEnter arrival time for process %d (at): ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d (bt): ", p[i].id);
        scanf("%d", &p[i].bt);
    }

    // Calculate completion time, waiting time, and turnaround time for the first process
    p[0].ct = p[0].at + p[0].bt;  // First process completes after its burst time
    p[0].tat = p[0].ct - p[0].at;  // Turnaround time = Completion Time - Arrival Time
    p[0].wt = p[0].tat - p[0].bt;  // Waiting time = Turnaround time - Burst time

    // Calculate for other processes
    for(i = 1; i < n; i++) {
        p[i].ct = p[i-1].ct + p[i].bt;  // Completion time of the current process
        p[i].tat = p[i].ct - p[i].at;  // Turnaround time = Completion Time - Arrival Time
        p[i].wt = p[i].tat - p[i].bt;  // Waiting time = Turnaround time - Burst time
    }

    // Calculate averages
    for(i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    avg_wt /= n;  // Average waiting time
    avg_tat /= n;  // Average turnaround time

    // Display process details
    printf("\nProcess ID\tArrival Time (at)\tBurst Time (bt)\tWaiting Time (wt)\tTurnaround Time (tat)\tCompletion Time (ct)\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tat, p[i].ct);
    }

    // Display average times
    printf("\nAverage Waiting Time (wt): %.2f", avg_wt);
    printf("\nAverage Turnaround Time (tat): %.2f\n", avg_tat);
}

