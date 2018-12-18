#include "delete.h"

int delete(char *dir)
{
    char cur_dir[] = ".";
    char up_dir[] = "..";
    char dir_name[128];
    DIR *dirp;
    struct dirent *dp;
    struct stat dir_stat;
    	if ( 0 != access(dir, F_OK) ) 
	{
		printf("%s: No such file or directory\n",dir);
        	return 0;
    	}
    	if ( 0 > stat(dir, &dir_stat) )
	{
        	perror("Error: failed to get stat\n");
        	return -1;
    	}

    	if ( S_ISREG(dir_stat.st_mode) )
    	{ 
        	remove(dir);
		printf("%s: delete success\n",dir);
    	} 
	else if ( S_ISDIR(dir_stat.st_mode) )
	{   
        	dirp = opendir(dir);
        	while ( (dp=readdir(dirp)) != NULL )
		{
            		if ( (0 == strcmp(cur_dir, dp->d_name)) || (0 == strcmp(up_dir, dp->d_name)) ) 
			{
               			 continue;
            		}

            		sprintf(dir_name, "%s/%s", dir, dp->d_name);
            		delete(dir_name);   
        	}
        closedir(dirp);
        rmdir(dir);    
	printf("%s: delete success\n",dir); 
    	} 
	else
	{
        	perror("Error: unknow file type!");    
    	}
    return 0;
}
