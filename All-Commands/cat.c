#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Write(char *FName)
{
	FILE *FP;
	FP=fopen(FName , "a");
	if(!FP)
	{
		printf("\n");
		printf("\033[1;31m");
		printf("ERROR : OPENING FILE FAILED \n");
		printf("\033[1;37m");
		printf("\n");
		return;
	}
	else
	{
		char Data[1000];
		
		while(fgets(Data,1000,stdin)!=NULL)
		{
			fputs(Data,FP);
		}
		fclose(FP);
	}
}
void Show(char *Arg)
{
	FILE *PTR;
	
	PTR=fopen(Arg , "r");
	
	char CH;
	if(!PTR)
	{
		printf("\033[1;31m");
		printf("ERROR : OPENING FILE FAILED\n");
		printf("\033[1;37m");
		printf("\n");
		return;
	}
	while((CH=fgetc(PTR))!=EOF)
	{
		printf("%c" , CH);
	}
	printf("\n");
	fclose(PTR);
}
void main(int argc , char *argv[])
{
	int Size=-1;
	int i=0;
	while(argv[i]!=NULL)
	{
		Size++;
		i++;
	}
	if(strcmp((strtok(argv[1] , "\n")),">")==0)
	{
		strtok(argv[2] , "\n");
		Write(argv[2]);
	}
	else
	{
		for(int j=1 ; j<=Size ; j++)
		{
			printf("\n");
			printf("\033[1;33m");
			printf("%d) FILE NAME : %s\n\n" ,j, argv[j]);
			printf("\033[1;37m");
			strtok(argv[j] , "\n");
			Show(argv[j]);
			printf("\033[1;33m");
			printf("====================================\n");
			printf("\033[1;37m");
		}	
	}
}

