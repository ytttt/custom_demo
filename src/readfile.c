/*************************************************************
 * *   FileName : read.c
 * *   FileFunc : custom_demo filename
 * *   Version  : V1.0
 * *   Author   : Yu ting  
 * *   Date     : 2018-12-09 20:16:10 
 * *   Descp    : The read command to return file content
 * *   Return   : 0: ture, -1: false
 * *************************************************************/
#include "readfile.h"

int readfile(char *filename,int offset,int length)
{
	int ch;	/*be used for read file content*/
	FILE *fp;
	struct stat s_buf;/*save info of file*/
        if(access(filename,F_OK) == -1)
	{
		printf("%s: No such file!\n",filename);
		return -1;
	}
	if(stat(filename,&s_buf) == -1)
	{
		printf("%s: get it property failed\n",filename);
		return -1;
	}
	if(S_ISDIR(s_buf.st_mode))
	{
		printf("%s: is directory!\n",filename);
		return -1;
	}
	fp = fopen(filename,"r");
	if (fp == NULL)
	{
		printf("%s: open filed\n",filename);
		return -1;
	}	
	fseek(fp,offset,0);/*0:SEEK_SET file begin*/
	ch = fgetc(fp);
	int count = 0;/*计算读取的字符个数*/
	while(ch != EOF)
	{
		putchar(ch);
		count++;
		if(count == length)
		{
			break;
		}
		ch = fgetc(fp);
	}
	printf("\n");
	fclose(fp);	
	return 0;
}
