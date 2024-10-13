#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int turnaround;
    int waiting;
    int response;
};

void calculate_times(struct Process *p) {
    p->turnaround = p->waiting + p->burst;
    p->response = p->waiting;
}

void sort_processes(struct Process procs[], int n, int by_burst) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int condition = by_burst ? (procs[j].burst > procs[j + 1].burst) :
                                       (procs[j].arrival > procs[j + 1].arrival);
            if (condition || (procs[j].burst == procs[j + 1].burst && 
                              procs[j].arrival > procs[j + 1].arrival)) {
                struct Process temp = procs[j];
                procs[j] = procs[j + 1];
                procs[j + 1] = temp;
            }
        }
    }
}

void schedule_processes(struct Process procs[], int n, int by_burst) {
    printf("\n%s Scheduling\n", by_burst ? "SJF" : "FCFS");

    sort_processes(procs, n, by_burst);

    int current_time = 0;
    float total_waiting = 0, total_turnaround = 0, total_response = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < procs[i].arrival) {
            current_time = procs[i].arrival;
        }
        procs[i].waiting=current_time - procs[i].arrival;
        current_time += procs[i].burst;
        calculate_times(&procs[i]);

        total_waiting+=procs[i].waiting;
        total_turnaround+=procs[i].turnaround;
        total_response+=procs[i].response;
    }

    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", procs[i].pid);
    }
    printf("\n\n");

    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", procs[i].pid, procs[i].arrival, procs[i].burst,
               procs[i].waiting, procs[i].turnaround, procs[i].response);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting/n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround/n);
    printf("Average Response Time: %.2f\n", total_response / n);
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for ( int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
        processes[i].pid = i + 1;
    }

    schedule_processes(processes, n, 0);
    schedule_processes(processes, n, 1);

    return 0;
}

