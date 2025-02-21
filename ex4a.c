#include <stdio.h>

struct process {
    int pid;
    int bt;   // Burst Time
    int wt;   // Waiting Time
    int tt;   // Turnaround Time
} p[10];

int main() {
    int i, n, totwt = 0, tottt = 0;
    float avg1, avg2;   // Averages for WT and TT

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times for each process
    for (i = 1; i <= n; i++) {
        p[i].pid = i;  // Process ID
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    // Waiting time for the first process is always 0
    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;

    // Calculate waiting and turnaround time for other processes
    for (i = 2; i <= n; i++) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;  // Waiting time is previous burst time + previous waiting time
        p[i].tt = p[i].bt + p[i].wt;           // Turnaround time is burst time + waiting time
    }

    // Display process details
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    // Calculate averages
    avg1 = (float)totwt / n;
    avg2 = (float)tottt / n;

    // Display averages
    printf("\nAverage Waiting Time: %.2f\n", avg1);
    printf("Average Turnaround Time: %.2f\n", avg2);

    return 0;
}

