#include <stdio.h>
struct Process {
	int Name;
	int Burst_Time;
	int Arrival_Time;
	int Completion_Time;
	int Turn_Around_Time;
	int Waiting_Time;
};

int main() {
	int n, current_ct=0;
	float total_tat=0, total_wt=0, avg_tat, avg_wt;
	printf("Enter the number of process : ");
	scanf("%d", &n);
	struct Process p[n];

	for(int i=0; i<n; i++) {
		p[i].Name = i;
		printf("Enter the Burst Time of P%d : ", i);
		scanf("%d", &p[i].Burst_Time);
		p[i].Arrival_Time = 0;
		current_ct += p[i].Burst_Time;
		p[i].Completion_Time = current_ct;
		p[i].Turn_Around_Time = p[i].Completion_Time;
		p[i].Waiting_Time = p[i].Turn_Around_Time - p[i].Burst_Time;
	}

	printf("\n      Burst Time\tTurn Around Time\tWaiting Time\n");
	for(int i=0; i<n; i++) {
		printf("P%d    %d\t\t\t%d\t\t\t%d\n", p[i].Name, p[i].Burst_Time, p[i].Turn_Around_Time, p[i].Waiting_Time);
		total_tat += p[i].Turn_Around_Time;
		total_wt += p[i].Waiting_Time;
	}
	printf("\n");

	printf("Gantt Chart\n");
	printf("|");
	for(int i=0; i<n; i++) {
		printf("  P%d  |", p[i].Name);
	}
	printf("\n");
	printf("0      ");
	for(int i=0; i<n; i++) {
		printf("%d      ", p[i].Completion_Time);
	}
	printf("\n\n");

	printf("Total Turn Around Time : %f\n", total_tat);
	printf("Total Waiting Time : %f\n", total_wt);
	printf("Average Turn Around Time : %f\n", total_tat/n);
	printf("Average Waiting Time : %f\n\n", total_wt/n);

}
