/*************************************************************
 * *   FileName : create.c
 * *   FileFunc : custom_demo create filename
 * *   Version  : V1.0
 * *   Author   : Yu ting  
 * *   Date     : 2016-12-11 15:49 
 * *   Descp    : The create command to create file
 * *   Return   : 0 true ;  -1 false
 * *************************************************************/
#include "create.h"
int create (char *filename,char *s_mode,int dir_file)
{
	char is_cover = 'n';
	int mode = 0;
	int old_umask = umask(0);
        while (*s_mode)
       	{
               if (*s_mode >= '0' && *s_mode <= '7')
               {
                        mode = (mode<<3) | (*s_mode-'0');
               }
  	       else
               {
			printf("Error: bad mode\n");
			return 1;
               }
                        s_mode++;
        }
	if(mode == 0)
	{
		mode = 498;
	}
	if(access(filename,F_OK) == -1)
	{
		if(dir_file == 1)
		{
			if(creat(filename,mode) == -1)
			{
				printf("%s: File create failed!\n",filename);
				return -1;
			}
			printf("%s: File create success!\n",filename);	
			return 0;
		}
		if(mkdir(filename,mode) == -1)
		{
			printf("%s: Directory create failed!\n",filename);
			return -1;
		}
		printf("%s: Directory create success!\n",filename);	
		return 0;	
	}
	printf("%s: File is exsited,can you want to cover it? (N/Y/n/y) ",filename);
	scanf("%c",&is_cover);
	if(is_cover =='y'||is_cover =='Y')
	{
		remove(filename);
		if(dir_file == 1)
		{
			if(creat(filename,mode) == -1)
			{
				printf("%s: covered failed!\n",filename);
				return -1;
			}
			printf("%s: covered success!\n",filename);	
			return 0;	
		}
		if(mkdir(filename,mode) == -1)
		{
			printf("%s: covered failed!\n",filename);
			return -1;
		}
		printf("%s: covered success!\n",filename);	
		return 0;
	}
	else if(is_cover =='n'||is_cover =='N')
	{
		return -1;
	}
	else
	{
		printf("Invailed operation!\n");
		return -1;
	}
	umask(old_umask);
	return 0;
}
