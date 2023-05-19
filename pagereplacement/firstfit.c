// First-fit algorithm
#include<stdio.h>


void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	
	int allocatedblock[n]; //index is process no, value is the block number it is allocated to

	//initially every block is empty
	for(i = 0; i < n; i++)
	{
		allocatedblock[i] = -1;
	}

	//allocating processes using first fit
	for (i = 0; i < n; i++)	 //n is number of processes
	{
		for (j = 0; j < m; j++)	 //m is number of blocks
		{
			if (blockSize[j] >= processSize[i])
			{
				//if process fits in a block
				allocatedblock[i] = j;
				//reducing the available memory in this block
				blockSize[j] -= processSize[i];
				break; //go to the next process
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %d\t\t", i+1);
		printf("%d\t\t", processSize[i]);
		if (allocatedblock[i] != -1)
		{
			printf("%d", allocatedblock[i] + 1);
		}
		else
			printf("Not Allocated");
		printf("\n");
	}
}

int main()
{
	int m,n;
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	m = sizeof(blockSize) / sizeof(blockSize[0]);
	n = sizeof(processSize) / sizeof(processSize[0]);

	firstFit(blockSize, m, processSize, n);

	return 0;
}
