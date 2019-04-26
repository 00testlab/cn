#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main()
{
	int orate, drop = 0,cap,x,count,inp[10] = {0}, i=0,nsec,ch;
	
	printf("Enter the bucket size\n");
	scanf("%d",&cap);
	printf("Enter the output rate\n");
	scanf("%d",&orate);
	
	do{
		printf("Enter number of packets coming at second %d ", i+1);
		scanf("%d",&inp[i]);
		if(inp[i]>cap)
		{
			printf("Bucket overflow\n");
			printf("Packet Discarded\n");
		}
		
		i++;
		
		printf("Enter 1 to continue or 0 to discard\n");
		scanf("%d",&ch);
	}while(ch);
	
	nsec = i;
	
	printf("Second\tReceived\tSent\tDroppeed\tRemained\n");
	for(i=0;count||i<nsec;i++)
	{
		printf("%d\t%d\t%d\t",i+1,inp[i],MIN(inp[i]+count,orate));
		
		if((x = inp[i]+count-orate)>0)
			if(x>cap)
			{
				count = cap;
				drop = x-cap;
			}
			else{
			count = x;
			drop = 0;
			}

		else
		{
			drop = 0;
			count = 0;
		}
		printf("%d\t%d\n",drop,count);

	}
return 0;
}
