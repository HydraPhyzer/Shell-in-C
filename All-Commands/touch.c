#include<stdio.h>
#include<unistd.h>
#include<string.h>
void main(int argc , char *argv[])
{
	int Size=-1;
	int i=0;
	while(argv[i]!=NULL)
	{
		Size++;
		i++;
	}
	if(Size>=1)
	{
		printf("\n");
		for(int j=1 ; j<=Size ; j++)
		{
			FILE *FP;
			strtok(argv[j] , "\n");
			if(!access(argv[j] , F_OK))
			{
				printf("\033[1;31m");
				printf("%d) %s : ALREADY AVAILABLE \n" , j , argv[j]);
				printf("\033[1;37m");
			}
			else
			{
				printf("\033[1;33m");
				FP=fopen(argv[j],"w");
				printf("%d) %s : CREATED SUCCESSFULLY \n" , j , argv[j]);
				printf("\033[1;37m");
				fclose(FP);			
			}
		}
		printf("\n");
	}
	else
	{
		printf("\033[1;31m");
		printf("\nERROR : ARGUMENTS MISSED !!\n");
		printf("\033[1;37m");
	}
}

