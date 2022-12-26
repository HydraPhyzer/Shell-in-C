#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <errno.h>

int isFile(const char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
    	closedir(directory);
    	return 0;
    }

    if(errno == ENOTDIR)
    {
     return 1;
    }

    return -1;
}

int main(int argc , char *argv[])
{
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
		while(D=readdir(P))
		{
			int x=isFile(D->d_name);
			if(x==1)
			{
				printf("(File   #) ");
			}
			else
			{
				printf("(Folder #) ");
			}
			printf("\033[1;33m");
			printf("%s\n" , D->d_name);
			printf("\033[1;37m");
		}
		printf("\n");
	}
}
