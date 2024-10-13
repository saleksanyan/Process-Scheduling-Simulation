# Process-Scheduling-Simulation

## Here you can find an example of usage

## Run

```
gcc scheduler.c -o scheduler
./scheduler
```

## Input

```Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5
```

## Output

```
FCFS Scheduling
Gantt Chart: P1 P2 P3 P4 

PID	Arrival	Burst	Waiting	Turnaround	Response
1	0	8	0	8		0
2	1	4	7	11		7
3	2	9	10	19		10
4	3	5	18	23		18

Average Waiting Time: 8.75
Average Turnaround Time: 15.25
Average Response Time: 8.75

SJF Scheduling
Gantt Chart: P2 P4 P1 P3 

PID	Arrival	Burst	Waiting	Turnaround	Response
2	1	4	0	4		0
4	3	5	2	7		2
1	0	8	10	18		10
3	2	9	16	25		16

Average Waiting Time: 7.00
Average Turnaround Time: 13.50
Average Response Time: 7.00
```
