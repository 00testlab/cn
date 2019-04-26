#include<stdio.h>
#include<stdlib.h>

int main()
{
	int count,i,j,v,w,min=0;
	int cost[100][100],last[100],flag[100],dist[100],src_router=0;
	printf("Enter the number of routers\n");
	scanf("%d",&count);
	
	printf("Enter the cost matrix\n");
		
	for(i=0;i<count;i++)
	{for(j=0;j<count;j++)
	{
		printf("%d --> %d :",i,j);
		scanf("%d",&cost[i][j]);
	
		if(cost[i][j]<0)
		cost[i][j] = 999;
	}}
	
	printf("Enter the source node\n");
	scanf("%d",&src_router);
	
	for(v = 0; v < count; v++)
	{
		flag[v] = 0;
		last[v] = src_router;
		dist[v] = cost[src_router][v];
	}
	
	flag[src_router] = 1;
	
	for(i = 0; i < count; i++)
	{
		min = 999;
		for(w = 0; w < count; w++)
		{
			if(!flag[w])
			if(dist[w]<min)
			{
			v =w;
			min = dist[w];
			}
		}
	}
	
	flag[v] = 1;
	
	for(w = 0; w < count; w++)
	{
		if(!flag[w])
		if(min+cost[v][w]<dist[w])
		{
			dist[w] = min+cost[v][w];
			last[w] = v;
		}
	}

	for(i = 0 ; i < count; i++)
	{
		printf("\n%d --- > %d ",src_router,i);
		printf("Shortest cost path is %d",dist[i]);
	}
return 0;
}
