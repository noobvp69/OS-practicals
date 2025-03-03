#include<stdio.h>
struct ff
{int pid,wait,ser,temp;
}p[20];
struct ff temp;
void main()
{int i,j,n,tot=0,totwait=0,avwait,tturn=0,aturn;
printf("Enter no of process\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("Enter the process id\n");
scanf("%d",&p[i].pid);
printf("Enter service time\n");
scanf("%d",&p[i].ser);
p[i].wait=0;}
for(i=0;i<=n;i++)
{for(j=i+1;j<n;j++)
{if(p[i].ser>p[j].ser)
{temp=p[i];
p[i]=p[j];
p[j]=temp;
}}}
printf("\n\nPID\t SER\t WAIT\t TOT\t\n");
for(i=0;i<n;i++)
{tot=tot+p[i].ser;
tturn=tturn+tot;
p[i+1].wait=tot;
totwait=totwait+p[i].wait;
printf("%d\t %d\t %d\t %d\t\n",p[i].pid,p[i].ser,p[i].wait,tot);avwait=totwait/n;
aturn=tturn/n;
}
printf("\ntotal waiting time %d\n",totwait);
printf("average waiting time %d\n",avwait);
printf("total turn around time %d\n",tturn);
printf("Average turn around time %d\n",aturn);
}
