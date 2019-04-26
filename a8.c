#include<stdio.h>
#include<stdlib.h>

struct node{
unsigned int dist[30];
unsigned int from[30];
}rt[10];

int main()
{
	int i,j,k,n,count = 0;
	int dmat[20][20];
	
	printf("Enter the number of routers\n");
	scanf("%d",&count);
	
	printf("Enter the cost matrix\n");
	
	for(i = 0; i < count; i++)
		for(j = 0; j < count; j++)
		{
			scanf("%d",&dmat[i][j]);
			dmat[i][i] = 0;
			rt[i].dist[j] = dmat[i][j];
			rt[i].from[j] = j;
		}
	
	do{
		n = 0;
		for(i = 0; i < count; i++)
		{
			for(j = 0; j < count; j++)
			{
				for(k = 0; k < count; k++)
				{
					if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
					{
						rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j] = k;
						n++;
					}
				}

			}
		}
	}while(n != 0);

	for(i = 0; i < count; i++)
	{
		printf("State value of router %d \n",i+1);
		
		for(j = 0; j < count; j++)
			printf("Node %d via %d Distance %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
	}
	printf("\n\n");
return 0;
}
					
