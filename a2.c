#include<stdio.h>
#include<string.h>

void sender();
void receiver(int *result, int l2);

int main()
{
	sender();
return 0;
}

void sender()
{
	int i, j, n, count = 0, zerocount = 0, zero = 0,l1;
	
	int msg[50],result[50];
	
	printf("Enter the number of bits of message\n");
	scanf("%d",&n);
	
	printf("Enter the bits\n");
	
	for(i =0; i < n; i++)
		scanf("%d",&msg[i]);
	
	result[0] = 0;
	result[1] = 1;
	result[2] = 1;
	result[3] = 1;
	result[4] = 1;
	result[5] = 1;
	result[6] = 1;
	result[7] = 0;
	
	j = 8;
	
	for(i = 0; i < n; i++)
	{
		if(msg[i] == 0)
		{
			result[j] = msg[i];
			j++;
			zero = 1;
			count = 0;
		}
	
		else{
		if((count == 5)&& (zero ==1))
		{
			result[j] = 0;
			zerocount++;
			j++;
			result[j] = msg[i];
			j++;
			count = 0;
		}
		
		else{
		result[j] = msg[i];
		j++;
		count++;
		}
		}
	}
	
	result[j++] = 0;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 1;
	result[j++] = 0;

	l1 = 16+n+zerocount;
	
	printf("The length of the frame is %d\n",l1);
	printf("The frame is \n");

	for(i = 0; i < j; i++)
	{
		printf("%d",result[i]);
	}
	
	receiver(result,l1);
}

void receiver(int *result, int l2)
{
	int i,j,counter,l3;
	int mesg[100];
		
	l3 = l2-8;
	j = 0;
	for(i = 8; i < l3; i++)
	{
		if(result[i] == 0)
		{
			if(counter == 5)
			{
				i++;
				mesg[j] = result[i];
				j++;
				counter = 0;
			}
			else{
				mesg[j] = mesg[i];
				j++;
				counter = 0;
			}
		}

		else{
			mesg[j] = result[i];
			j++;
			counter++;
		}
	}
		printf("Receiver side message is :");
		for(i= 0; i < j; i++)
			printf("%d",mesg[i]);
		
		printf("\n\n");
}

