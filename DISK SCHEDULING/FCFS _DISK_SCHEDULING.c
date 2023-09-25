#include<stdio.h>
#include<stdlib.h>
void main(){
int i,np,req[50],dir,init,size,totaldisk=0;
printf("Enter the number of processes");
scanf("%d",&np);
printf("Enter the request sequence");
for(i=0;i<np;i++){
scanf("%d",&req[i]);
}
printf("Enter the disk size");
scanf("%d",&size);
size=-1;
printf("Enter the initial disk");
scanf("%d",&init);
for(i=0;i<np;i++){
totaldisk+=abs(req[i]-init);
init=req[i];
}
printf("seek time:%d\n",totaldisk);
}




/*OUTPUT

Enter the number of processes5
Enter the request sequence15
45
80
120
170
Enter the disk size200
Enter the initial disk53
seek time:193*/




