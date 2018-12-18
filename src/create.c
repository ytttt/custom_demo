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
int create (char *filename,mode_t mode,int dir_file)
{
	char is_cover = 'n';
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
	return 0;
}
