#include "lnsoft.h"
 
int lnsoft(char *oldpath,char *newpath)
{
	if(access(oldpath,F_OK) == -1)
	{
		return -1;
	}
	if(access(newpath,F_OK) == 0)
	{
		printf("failed to create soft link '%s': File exsits\n",newpath);
		return -1;
	}
	if(symlink(oldpath,newpath) == -1)
	{
		printf("failed to create soft link '%s'\n",newpath);
		return -1;		
	}
	printf("lnsoft: %s  create softlink success!\n",newpath);
	return 0;
}
