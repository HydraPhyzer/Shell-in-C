#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <errno.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
	struct stat fileStat;
	struct tm * timestruct;
	struct tm dt;
	char Name[100];
	DIR *P;
	struct dirent *D;
	
	
	P=opendir(argv[0]);
	if(P==NULL)
	{
		printf("\n");
		printf("\033[1;31m");
		printf("ERROR IN LISTING DIRECTORIES !!\n");
		printf("\033[1;37m");
		printf("\n");
	}
	else
	{
		printf("\n");
		printf("File-Size \tCreation-Date \tAccess-Rights \tFile-Name\n");
		printf("========= \t============= \t============= \t=========\n");
		while(D=readdir(P))
		{
			if(stat(D->d_name , &fileStat)==0)
			{
				printf("%ld\t         " , fileStat.st_size);
				
				dt = *(gmtime(&fileStat.st_ctime));
				
				timestruct = localtime(&fileStat.st_mtime);
				char timebuf[20];
				strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", timestruct);
				printf("%s\t", timebuf);

			}
			printf( (S_ISDIR(fileStat.st_mode))  ? "d" : "-");
			printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
			printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
			printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
			
			printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
			printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
			printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
			
			printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
			printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
			printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
			
			printf("\t");
	
			printf("\033[1;33m");
			printf("%s\n" , D->d_name);
			printf("\033[1;37m");
			
		}
		printf("\n");
	}
}
