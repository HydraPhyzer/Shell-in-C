#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define TRUE 1
int CK=0;
int His=-1;
char Path[200];
char PWD[200];
char Help[200];
char ShellName[200];
char *History[100];

void Black()
{
	printf("\033[1;30m");
}
void Red()
{
	printf("\033[1;31m");
}
void Green()
{
	printf("\033[1;32m");
}
void Yellow()
{
	printf("\033[1;33m");
}
void Blue()
{
	printf("\033[1;34m");
}
void Magenta()
{
	printf("\033[1;35m");
}
void Cyan()
{
	printf("\033[1;36m");
}
void White()
{
	printf("\033[1;37m");
}

void BG_Black()
{
	printf("\e[40m");
}
void BG_Red()
{
	printf("\e[41m");
}
void BG_Green()
{
	printf("\e[42m");
}
void BG_Yellow()
{
	printf("\e[43m");
}
void BG_Blue()
{
	printf("\e[44m");
}
void BG_Purple()
{
	printf("\e[45m");
}
void BG_Cyan()
{
	printf("\e[46m");
}
void BG_White()
{
	printf("\e[47m");
}
void InitShell()
{
	system("clear");
	printf("=============================\n");
	printf("    WELCOME TO PERL SHELL\n");
	printf("=============================\n\n");
//	printf("%s" , ShellName);
}
char *GetCommand()
{
	char *Arr=malloc(100);
	fgets(Arr , 100 , stdin);
	History[His++]=Arr;
	return Arr;
}
int getWords(char *base, char target[20][50])
{
	int n=0,i,j=0;
	
	for(i=0;TRUE;i++)
	{
		if(base[i]!=' ')
		{
			target[n][j++]=base[i];
		}
		else
		{
			target[n][j++]='\0';
			n++;
			j=0;
		}
		if(base[i]=='\0')
		break;
	}
	return n;
}
int main()
{
	getcwd(Path , 200);
	strcpy(PWD , Path);
	strcpy(Help , Path);
	
	strcat(PWD , "/All-Commands/");
	strcat(Help , "/Help-Files/");
	
	strcpy(ShellName , "$:Perl");
	strcat(ShellName , Path);
	strcat(ShellName , ">>");
	Up:
	InitShell();
	Top:
	if(CK==0)
	{
		BG_Green();
		printf("%s" , ShellName);
		printf("\e[0m");
	}
	if(CK>0)
	{
		printf("%s" , ShellName);
	}
	
	while(1)
	{
		char *Get=GetCommand();
		
		if(strcmp(Get,"wipe\n")==0)
		{
			system("clear");
			goto Up;
		}
		else if(strcmp(Get , "pwd\n")==0)
		{
			getcwd(Path , 200);
			printf("\nYour Present Working Directory is : \n\n");
			
			printf("\033[1;33m");
			printf("%s\n\n" , Path);
			printf("\033[1;37m");
			
			goto Top;
		}
		else if(strcmp(Get , "whoami\n")==0)
		{
			char *LogName;
			LogName=malloc(100);
			LogName=getlogin();
			printf("\nUser-Name : %s\n\n" , LogName);
			
			goto Top;
		}
		else if(strcmp(Get , "history\n")==0)
		{
			printf("\n");
			printf("\033[1;33m");
			for(int h=0 ; h<His ; h++)
			{
				printf("\t %d) %s" , h+1 , History[h]);
			}
			printf("\033[1;37m");
			printf("\n");
			goto Top;
		}
		else if(strcmp(Get,"leave\n")==0)
		{
			printf("\nEXITING THE TERMINAL\n\n");
			goto End;
			End:
				break;
				exit(0);
		}
		else if(strcmp(Get,"ls\n")==0)
		{
			int status;
			pid_t pid, wpid;
			pid = fork();
			if (pid == 0)
			{  // It's the child process
				char Add[200];
				char Add1[200];
				getcwd(Path , 200);
				strcpy(Add , Path);
				strcpy(Add1 , PWD);
				strcat(Add1 , "./");
				strtok(Get , "\n");
				strcat(Add1 , Get);
				char *Ex[]={Add , NULL};
				if(execv(Add1 , Ex) == -1)
				{
					printf("\n");
					Red();
					perror("ERROR : API UN-SUCCESSFULL ");
					White();
					printf("\n");
					goto Top;
				}
				exit(EXIT_FAILURE);	// To exit from child process
			}
			else if (pid < 0)
			{      // Error in fork
				perror("$Perl>>");
			}
			else
			{           // It's the parent process
				//do
				//{
				//	wpid = waitpid(pid, &status, WUNTRACED);
				//}
				//while (!WIFEXITED(status) && !WIFSIGNALED(status));
				wait(NULL);
				goto Top;
			}
		}
		else if(strcmp(Get,"help\n")==0)
		{
			int status;
			pid_t pid, wpid;
			pid = fork();
			if(pid == 0)
			{
				char Add[200];
				char Add1[200];
				getcwd(Path , 200);
				strcpy(Add1 , PWD);
				strtok(Get , "\n");
				strcat(Add1 , "./");
				strcat(Add1 , Get);
				char *Arr[]={NULL};
				if(execv(Add1 , Arr) == -1)
				{
					printf("\n");
					printf("\033[1;31m");
					printf("ERROR : API CALL UNSUCCESSFULL !! \n");
					printf("\033[1;37m");
					printf("\n");
				}
				exit(EXIT_FAILURE);	// To exit from child process
			}
			else if (pid < 0)
			{      // Error in fork
				perror("$Perl>>");
			}
			else
			{           // It's the parent process
				//do
				//{
				//	wpid = waitpid(pid, &status, WUNTRACED);
				//}
				//while (!WIFEXITED(status) && !WIFSIGNALED(status));
				wait(NULL);
				goto Top;
			}
		}
		else
		{
			int n;
			int i; 
			char Arr[20][50];
			n=getWords(Get,Arr);
			char *Words[n+1];
			for(i=0;i<=n;i++)
			{
				Words[i]=Arr[i];
			}
			Words[i]=NULL;
			
			if(strcmp(Words[0] , "color")==0)
			{
				if(strcmp(Words[1], "black\n")==0)
				{
					Black();
					goto Top;
				}
				else if(strcmp(Words[1], "red\n")==0)
				{
					Red();
					goto Top;
				}
				else if(strcmp(Words[1], "green\n")==0)
				{
					Green();
					goto Top;
				}
				else if(strcmp(Words[1], "yellow\n")==0)
				{
					Yellow();
					goto Top;
				}
				else if(strcmp(Words[1], "blue\n")==0)
				{
					Blue();
					goto Top;
				}
				else if(strcmp(Words[1], "magenta\n")==0)
				{
					Magenta();
					goto Top;
				}
				else if(strcmp(Words[1], "cyan\n")==0)
				{
					Cyan();
					goto Top;
				}
				else if(strcmp(Words[1], "white\n")==0)
				{
					White();
					goto Top;
				}
			}
			if(strcmp(Words[0] , "bgcolor")==0)
			{
				CK=1;
				if(strcmp(Words[1], "black\n")==0)
				{
					BG_Black();
					goto Top;
					
				}
				else if(strcmp(Words[1], "red\n")==0)
				{
					BG_Red();
					goto Top;
				}
				else if(strcmp(Words[1], "green\n")==0)
				{
					BG_Green();
					goto Top;
				}
				else if(strcmp(Words[1], "yellow\n")==0)
				{
					BG_Yellow();
					goto Top;
				}
				else if(strcmp(Words[1], "blue\n")==0)
				{
					BG_Blue();
					goto Top;
				}
				else if(strcmp(Words[1], "purple\n")==0)
				{
					BG_Purple();
					goto Top;
				}
				else if(strcmp(Words[1], "cyan\n")==0)
				{
					BG_Cyan();
					goto Top;
				}
				else if(strcmp(Words[1], "white\n")==0)
				{
					BG_White();
					goto Top;
				}
			}
			if(strcmp(Words[0], "man")==0)
			{
				char Add2[200];
				strcpy(Add2 , "nano");
				strcat(Add2 , " ");
				strcat(Add2 , Help);
				strtok(Words[1] , "\n");
				strcat(Add2 , Words[1]);
				strcat(Add2 , ".txt");
				
				if(strcmp(Words[1], "bgcolor")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "color")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "cat")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "cd")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "copy")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "crdir")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "deldir")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "del")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "touch")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "ls")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "wipe")==0)
				{
					system(Add2);
				}
				else if(strcmp(Words[1], "pwd")==0)
				{
					system(Add2);
				}
				else
				{
					printf("\n");
					Red();
					printf("ERROR : MANUAL YET NOT AVAILABLE !!\n");
					printf("\n");
					White();
				}
				goto Top;
			}
			if((strcmp(Words[0],"ls")==0 && strcmp(Words[1] , "-tree\n")==0 ) || 
			(strcmp(Words[0],"ls")==0 && strcmp(Words[1] , "-all\n")==0 ))
			{
				int status;
				pid_t pid, wpid;
				pid = fork();
				if (pid == 0)
				{  // It's the child process
					char Add[200];
					char Add1[200];
					getcwd(Path , 200);
					strcpy(Add , Path);
					strcpy(Add1 , PWD);
					strcat(Add1 , "./");
					strtok(Words[1] , "\n");
					strcat(Add1 , Words[0]);
					strcat(Add1 , " ");
					strcat(Add1 , Words[1]);
					char *Ex[]={Add , NULL};
					if(execv(Add1 , Ex) == -1)
					{
						printf("\n");
						printf("\033[1;31m");
						perror("ERROR : API UN-SUCCESSFULL ");
						printf("\033[1;37m");
						printf("\n");
						goto Top;
					}
					exit(EXIT_FAILURE);	// To exit from child process
				}
				else if (pid < 0)
				{      // Error in fork
					perror("$Perl>>");
				}
				else
				{           // It's the parent process
					//do
					//{
					//	wpid = waitpid(pid, &status, WUNTRACED);
					//}
					//while (!WIFEXITED(status) && !WIFSIGNALED(status));
					wait(NULL);
					goto Top;
				}
			}
			if(strcmp(Words[0] , "cd")==0)
			{
				strtok(Words[1] , "\n");
				
				if(chdir(Words[1])==0)
				{
					char NAD[200];
					getcwd(NAD , 200);
					
					strcpy(ShellName , "$:Perl");
					strcat(ShellName , NAD);
					strcat(ShellName , ">>");
				}
				else
				{
					printf("\n");
					printf("\033[1;31m");
					printf("ERROR : CHANGING DIRECTORY FAILED !! \n");
					printf("\033[1;37m");
					printf("\n");
				}
				
				goto Top;
			}
			else
			{
				int status;
				pid_t pid, wpid;
				pid = fork();
				if(pid == 0)
				{
					char Add[200];
					char Add1[200];
					getcwd(Path , 200);
					strcpy(Add1 , PWD);
					strcat(Add1 , "./");
					strcat(Add1 , Words[0]);
					
					if(execv(Add1 , Words) == -1)
					{
						printf("\n");
						printf("\033[1;31m");
						printf("ERROR : API CALL UNSUCCESSFULL !! \n");
						printf("\033[1;37m");
						printf("\n");
					}
					exit(EXIT_FAILURE);	// To exit from child process
				}
				else if (pid < 0)
				{      // Error in fork
					perror("$Perl>>");
				}
				else
				{           // It's the parent process
					//do
					//{
					//	wpid = waitpid(pid, &status, WUNTRACED);
					//}
					//while (!WIFEXITED(status) && !WIFSIGNALED(status));
					wait(NULL);
					goto Top;
				}
			}
		}
	}
	return 0;
}
