#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
void Copy(char *A , char *B , char *C)
{
	FILE *F1;
	FILE *F2;
	FILE *F3;
	
	
	F1=fopen(A, "r");
	if(F1==NULL)
	{
		printf("\n");
		printf("\033[1;33m");
		printf("1) %s : COPYING DENIED , FILE NOT FOUND !!\n\n" , A);
		printf("\033[1;37m");
		exit(0);
	}
	
	F2=fopen(B , "r");
	if(F2==NULL)
	{
		printf("\n");
		printf("\033[1;33m");
		printf("2) %s : COPYING DENIED , FILE NOT FOUND !!\n\n" , B);
		printf("\033[1;37m");
		exit(0);
	}
	
	F3=fopen(C , "a");
	if(F3==NULL)
	{
		printf("\n");
		printf("\033[1;33m");
		printf("3) %s : COPYING DENIED , FILE NOT FOUND !!\n\n" , C);
		printf("\033[1;37m");
		exit(0);
	}
	char Letter1=fgetc(F1);
	while(Letter1 !=EOF)
	{
		fputc(Letter1 , F3);
		Letter1=fgetc(F1);
	}
	char Letter2=fgetc(F2);
	while(Letter2 !=EOF)
	{
		fputc(Letter2 , F3);
		Letter2=fgetc(F2);
	}
	fclose(F1);
	fclose(F2);
	fclose(F3);
}
int main(int argc , char *argv[])
{
	int Size=-1;
	int i=0;
	while(argv[i]!=NULL)
	{
		Size++;
		i++;
	}
	if(Size==2)
	{
		FILE *F1;
		FILE *F2;
		
		strtok(argv[1] , "\n");
		strtok(argv[2] , "\n");
		
		F1=fopen(argv[1] , "r");
		if(F1==NULL)
		{
			printf("\n");
			printf("\033[1;33m");
			printf("1) %s : COPYING DENIED , FILE NOT FOUND !!\n\n" , argv[1]);
			printf("\033[1;37m");
			exit(0);
		}
		
		F2=fopen(argv[2] , "a");
		if(F2==NULL)
		{
			printf("\n");
			printf("\033[1;33m");
			printf("2) %s : COPYING DENIED , FILE NOT FOUND !!\n\n" , argv[2]);
			printf("\033[1;37m");
			exit(0);
		}
		
		char Letter=fgetc(F1);
		while(Letter !=EOF)
		{
			fputc(Letter , F2);
			Letter=fgetc(F1);
		}
		fclose(F1);
		fclose(F2);
	}
	else if(Size>2)
	{
		strtok(argv[3] , "\n");
		if(strcmp(argv[3] , ">")==0 && argv[4]!=NULL)
		{
			strtok(argv[1] , "\n");
			strtok(argv[2] , "\n");
			strtok(argv[4] , "\n");
			Copy(argv[1] , argv[2] , argv[4]);
		}
	}
	else
	{
		printf("\n");
		printf("\033[1;31m");
		printf("ERROR : SOMETHING WENT WRONG !! \n");
		printf("\033[1;37m");
		printf("\n");
	}
	if(Size>=2)
	{
		for(int j=1 ; j<=10 ; j++)
		{
			printf("[Progress : %d%c] >> [" , (j*10) ,37);
			for(int i=0 ; i<(j*3) ; i++)
			{
				printf("\033[1;31m");
				printf("📂️");
				printf("\033[1;37m");
			}
			printf("]\n");
			sleep(1);
			
			fputs("\033[A\033[2K" , stdout);
			rewind(stdout);
		}
		printf("\n");
		printf("\033[1;33m");
		printf("COPYING DATA SUCCESSFULL !! \n");
		printf("\033[1;37m");
		printf("\n");		
	}
}
