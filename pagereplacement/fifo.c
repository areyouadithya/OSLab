#include<stdio.h>  
int main(){  
    int refstring[] = {4,1,2,4,5,3,2,4,1,2,5};  
    int pageFaults = 0;  
    int frames = 3;  
    int m,n,s,pages;   
    pages = sizeof(refstring)/sizeof(refstring[0]);   
    printf("Incoming Page\tFrame 1\t\tFrame 2\t\tFrame 3");  
    int temp[frames];  
    for(m=0;m<frames;m++)  
    {  
        temp[m] = -1;  
    }  
    for(m=0;m<pages;m++)  
    {  
        s=0;   
        for(n=0;n<frames;n++)  
        {  
            if(refstring[m]==temp[n])  
            {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults<=frames) && (s == 0))  
        {  
            temp[m]=refstring[m];  
        }  
        else if(s==0)  
        {  
            temp[(pageFaults-1) % frames] = refstring[m];  
        }  
        printf("\n");  
        printf("%d\t\t",refstring[m]);  
        for(n=0;n<frames;n++)  
        {  
            if(temp[n]!=-1)  
                printf(" %d\t\t", temp[n]);  
            else  
                printf(" - \t\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;  
}