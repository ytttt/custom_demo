/*************************************************************
 * * *   FileName : isexsit.c
 * * *   FileFunc : 
 * * *   Version  : V1.0
 * * *   Author   : Yu ting  
 * * *   Date     : 2016-12-09 18:49 
 * * *   Descp    : The function to judge file whether or not exsit
 * * *   Return   : 1 true   -1 false
 ** *************************************************************/

#include <stdio.h>
#include <unistd.h>

int isexsit (char *filename)
{
	int n = access(filename,F_OK);/*check file exsit*/
        if (n == -1)
        {
                printf("%s  : no such file\n",filename);
                return -1;
        }
	return 1;
}
