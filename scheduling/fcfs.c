//https://www.easycodingzone.com/2021/06/c-program-on-fcfsfirst-come-first-serve.html

#include<stdio.h>
int main()
{
    int AT[10],BT[10],WT[10],TT[10],n;
    int burst=0,cmpl_T;
    float avg_WT,avg_TT,total=0;
    printf("Enter number of the process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    for(int i=0;i<n;i++)
    {
        printf("AT\n");
        scanf("%d",&AT[i]);
        printf("BT\n");
        scanf("%d",&BT[i]);
    }
    
    //Calculating Waiting time
    for(int i=0;i<n;i++)
    {
        if(i==0)
            WT[i]=AT[i];
        else
            WT[i]=burst-AT[i];
        burst+=BT[i];
        total+=WT[i];
    }
    avg_WT=total/n;
    
    //Calculating Turn around time
    cmpl_T=0;
    total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=BT[i];
        TT[i]=cmpl_T-AT[i];
        total+=TT[i];
    }
    avg_TT=total/n;
    
    //Printing outputs
    printf("Process  Waiting_Time  Turnaround_Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,WT[i],TT[i]);
    }
    printf("Average Waiting time is : %f\n",avg_WT);
    printf("Average Turnaround time is : %f\n",avg_TT);
    return 0;
} 
