#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	UP:
	system("clear");
	while(1)
	{
		printf("ENTER \"Shell\" To INITITATE TERMINAL : ");
		char *Inp=malloc(100);
		fgets(Inp , 100 , stdin);
		if(strcmp(Inp , "Shell\n")==0)
		{
			
			char *cmd = "x-terminal-emulator -e \"/home/zubair/Desktop/Final/./a.out\"";
			system (cmd);
			goto UP;
		}
		else
		{
			printf("\n");
			printf("\033[1;31m");
			printf("FAILED TO START SHELL !! \n");
			printf("\n");
			printf("\033[1;37m");
			getchar();
			goto UP;
		}		
	}
		
}
