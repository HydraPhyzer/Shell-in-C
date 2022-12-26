#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

int isFile(const char* name)
{
	DIR* D = opendir(name);

    	if(D != NULL)
    	{
    		closedir(D);
    		return 0;
    	}
    	else
    	{
    		return 1;
    	}

}

void Recursively(char *Path , const int root);

int main(int argc , char *argv[])
{
	char Path[100];
    	strcpy(Path, argv[0]);
    	printf("\n");
    	Recursively(Path , 0);
	printf("\n");
    	return 0;
}

void Recursively(char *Base , const int root)
{
	char Path[1000];
    	int i;
    	struct dirent *DP;
    	DIR *DR = opendir(Base);

    	if (!DR)
    	{
    		return;  
    	}
    	while ((DP = readdir(DR)) != NULL)
    	{
        	if (strcmp(DP->d_name, ".") != 0 && strcmp(DP->d_name, "..") != 0)
        	{
        
        		for (i=0; i<root; i++) 
            		{
                		if (i%2 == 0 || i == 0)
                		{
		        		printf("\033[1;33m");
		        		printf("|__");
		        		printf("\033[1;37m");                		
                		}
				else
				{
					printf(" ");                
				}
            		}
            	printf("\033[1;33m");
            	printf(">>");
            	printf("\033[1;37m");
		printf("%s\n" , DP->d_name);
            	strcpy(Path, Base);
            	strcat(Path, "/");
            	strcat(Path, DP->d_name);
            	Recursively(Path, root + 2);
        	}
    	}
    	closedir(DR);
}
