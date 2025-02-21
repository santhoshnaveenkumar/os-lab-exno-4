#include <stdio.h>

struct process {
    int pid;   // Process ID
    int bt;    // Burst Time
    int wt;    // Waiting Time
    int tt;    // Turnaround Time
    int prior; // Priority
} p[10], temp;

int main() {
    int i, j, n, totwt = 0, tottt = 0;
    float avg1, avg2;  // Averages for WT and TT

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for (i = 1; i <= n; i++) {
        p[i].pid = i;  // Process ID
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
        printf("Enter the priority for process %d: ", i);
        scanf("%d", &p[i].prior);
    }

    // Sort processes based on priority (higher priority first)
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (p[i].prior > p[j].prior) {
                // Swap burst time, priority, and process ID
                temp.pid = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = temp.pid;

                temp.bt = p[i].bt;
                p[i].bt = p[j].bt;
                p[j].bt = temp.bt;

                temp.prior = p[i].prior;
                p[i].prior = p[j].prior;
                p[j].prior = temp.prior;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    p[1].wt = 0;  // Waiting time of the first process is always 0
    p[1].tt = p[1].bt + p[1].wt;  // Turnaround time = Burst time + Waiting time

    for (i = 2; i <= n; i++) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;  // Waiting time = Previous process burst time + Previous process waiting time
        p[i].tt = p[i].bt + p[i].wt;           // Turnaround time = Burst time + Waiting time
    }

    // Print the process details and calculate total waiting time and turnaround time
    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].prior, p[i].wt, p[i].tt);
        totwt += p[i].wt;  // Total waiting time
        tottt += p[i].tt;  // Total turnaround time
    }

    // Calculate averages
    avg1 = (float)totwt / n;  // Average Waiting Time
    avg2 = (float)tottt / n;  // Average Turnaround Time

    // Print the averages
    printf("\nAverage Waiting Time: %.2f\n", avg1);
    printf("Average Turnaround Time: %.2f\n", avg2);

    return 0;
}

