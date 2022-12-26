#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc , char *argv[])
{
	int i=1;
	while(argv[i]!=NULL)
	{
		printf("%s" , argv[i]);
		
		i++;
		
		if(argv[i]!=NULL)
		printf(" ");
	}
}

