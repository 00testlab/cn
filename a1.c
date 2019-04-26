#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char final[150];
void send()
{
	int i,len,n;
	char sub[10],l[10];
	printf("Enter the number of frames to be send\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		printf("Enter the frame\n");
		scanf("%s",sub);
		len = strlen(sub);
		sprintf(l,"%d",len);
		strcat(l,sub);
		strcat(final,l);
	}
        printf("message sent is %s\n",final);

}

void recv()
{
	int i, j,len ;
    for(i=0;i<strlen(final);i++)
    {
        len=final[i]-'0';
        for(j=i+1;j<=(i+len);j++)
            printf("%c",final[j]);
            i=i+len;
            printf("\n");

    }
}

	int main()
	{
	    send();
	    recv();
	    return 0;
	}
