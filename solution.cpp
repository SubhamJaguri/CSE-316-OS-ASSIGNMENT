#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{

  int count,i,j,m=0,n,y=0,time,remain=0,min,flag=0;
  int waitingTime=0,turnAroundTime=0,arrivalTime[10],burstTime[10],p[10],z[10];
  float k=0,x=0;
  printf("Enter the number of Process:\t ");
  scanf("%d",&n);
  printf("\n\tArrival time should be greater than 2 as CPU remains idle for first 3 secs.\n");
  printf("\n\tBurst time should be less then 10\n");
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
    scanf("%d",&arrivalTime[i]);
    scanf("%d",&burstTime[i]);
  }

for(i=0;i<n;i++)
{
	if(arrivalTime[i]==0)
	{
		printf("\nS Invalid Arrival Time\n");
		getch();
		exit(1);
	}
}
for(i=0;i<n;i++)
{
	if(arrivalTime[i]<3)
	{
		printf("\nS Invalid Arrival Time it should be greater than 3\n");
		getch();
		exit(1);
	}
}
  printf("\n\n\tProcess\t|Turnaround Time|Waiting Time\n\n");
  printf("\t===========================================\n");
for(i=0;i<n;i++)
{
	m=m+burstTime[i];
}
min=m;
time=m;
for(i=0;i<n;i++)
{
	if(arrivalTime[i]<time)
	{
		time=arrivalTime[i];
	}
}
for(i=time;i<=m;i=i+burstTime[j])
{
	min=m;
	remain=0;
	flag=0;

	for(count=0;count<n;count++)
	{

		if(arrivalTime[count]<=i)
		{

			if(burstTime[count]<min)
			{

				min = burstTime[count];
				j=count;
				flag=1;
			}
			remain=1;
		}
	}
	if(flag==1&&remain==1)
	{
		waitingTime=i-arrivalTime[j];
		turnAroundTime=waitingTime+burstTime[j];
		printf("\tP[%d]\t|\t%d\t|\t%d\n",j+1,turnAroundTime,waitingTime);
		k=k+waitingTime;
		x=x+turnAroundTime;

		arrivalTime[j]=m+1;
		p[y]=j+1;
		z[y]=i;
		y++;
	}
}
printf("\n\nAverage Waiting Time= %.2f\n",k/n);
printf("Avg Turnaround Time = %.2f",x/n);
printf("\n\n\nTotal time taken by processor to complete all the jobs : %d",m);
printf("\n\nQueue  for order of execution:\n");
printf("\n\nProcess		");

for(i=0;i<n;i++)
{
	printf(" P[%d]   ",p[i]);
	if(i==(n-1))
	{
		printf("End");
	}
}


  return 0;
}
