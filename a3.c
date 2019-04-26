#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define N strlen(g)

char t[120],cs[120],g[] = "100000111";
int a,c,e;

void XOR()
{
	for(c = 1; c < N; c++)
		cs[c] = ((cs[c] == g[c])?'0':'1');
}

void CRC()
{
	for(e = 0; e<N; e++)
		cs[e] = t[e];
	do{
		if(cs[0] == '1')
			XOR();
		for(c = 0; c<N-1;c++)
			cs[c] = cs[c+1];
		cs[c] = t[e++];
	}while(e<a+N-1);
}

void main()
{
	printf("Enter the polynomial\n");
	scanf("%s",t);
	printf("Generating polynomial is %s\n",g);
	a = strlen(t);
	
	for(e = a; e < a+N-1;e++)
		t[e] = '0';
	
	printf("Modified t[u] is %s\n",t);
	
	CRC();
	printf("Checksum is %s\n",cs);
	
	for(e = a; e<a+N-1;e++)
		t[e] = cs[e-a];
	
	printf("\nFinal codeword is %s\n",t);
	printf("Test Error detection 0(Yes) or 1 (No)\n");
	scanf("%d",&e);
	
	if(e ==0)
	{
		do{
			printf("Enter the position to induce the error\n");
			scanf("%d",&e);
		}while(e == 0 || e> a+N-1);
	t[e-1] = (t[e-1] == '0')?'1':'0';
	printf("Errornous data is %s\n",t);
	}

	CRC();
	
	for(e=0;(e<N-1)&&(cs[e]!= '1'); e++);
	if(e<N-1)
		printf("Error detetcted\n");
	else
		printf("Error is not detected\n");
}
