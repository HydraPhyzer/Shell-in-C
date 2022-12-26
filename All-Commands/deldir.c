#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
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
			strtok(argv[j] , "\n");
			int Check=rmdir(argv[j]);
			if(Check==0)
			{
				printf("%d) %s : " , j , argv[j]);
				printf("\033[1;33m");
				printf("FOLDER SUCCESSFULLY DELETED !! \n");
				printf("\033[1;37m");
			}
			else
			{
				printf("%d) %s : " , j , argv[j]);
				printf("\033[1;33m");
				printf("UNABLE TO DELETE !! \n");
				printf("\033[1;37m");
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

