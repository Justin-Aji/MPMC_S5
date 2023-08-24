#include<stdio.h>
void main(){
int pid[20],bt[20],n,i;
printf(" Enter the no of processes");
scanf("%d",&n);
int wait[n],tat[n];
printf("Enter the processid of processess");
for(i=0;i<n;i++){
scanf(" %d",&pid[i]);
}
printf(" Enter the burst time");
for(i=0;i<n;i++){
scanf(" %d",bt[i]);
}
float tavg,wavg,toturn,totwait;
wait[0]=0;
tat[0]=bt[0];
for(i=1;i<n;i++){
tat[i]=bt[i]+tat[i-1];
}
for(i=1;i<n;i++){
wait[i]=tat[i]-bt[i];
}
for(i=0;i<n;i++){
toturn+=tat[i];
}
for(i=0;i<n;i++){
totwait+=wait[i];
}
tavg=(toturn/n);
wavg=(totwait/n);
printf(" Gantt chart");
for(i=0;i<n;i++){
printf(" p%d\t",pid[i]);
}
printf("\n");
for(i=0;i<n;i++){
printf(" %d\t",tat[i]);
}
printf("\n");
printf("average turn around time:%f\t",tavg);
printf("\n average waiting time:%f\n",wavg);
}
