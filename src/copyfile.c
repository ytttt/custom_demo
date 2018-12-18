#include "copyfile.h"

int is_coverfunc(char );
int copyfile(char *filename1,char *filename2)
{
	FILE *f_one,*f_two;
	char ch;
	struct stat stat_buf;
	char is_cover = 'y';
	if(access(filename1,F_OK) != 0)
	{
		printf("'%s': No such file\n",filename1);
		return -1;
	}
	if(filename2 == NULL)
	{
		printf("Error: missing destination file after '%s'\n ",filename1);
		return -1;
	}
	if(strcmp(filename1,filename2) == 0)
	{
		printf("Error: '%s' and '%s' are the same file\n ",filename1,filename2);
		return -1;
	}
	if(access(filename2,F_OK) == 0)
	{
		printf("%s is existed! can you want to cover it?",filename2);
		scanf("%c",&is_cover);
	}
	if(is_coverfunc(is_cover)==-1)
	{
		return -1;
	}	
	if(!(f_one=fopen(filename1,"r")))
	{
		printf("Error: failed to open the file\n");
		return -1;
	}
	if(!(f_two=fopen(filename2,"w")))
	{
		printf("Error:failed to write in the file\n");
		return -1;
	}
	while(!feof(f_one))
	{
		ch=fgetc(f_one);
		if(!feof(f_one))
		 putc(ch,f_two);
	}
	stat(filename1,&stat_buf);
	int m = chmod(filename2,stat_buf.st_mode);
	if(m == -1)
	{
		printf("Error: copy failed! \n");
		return -1;
	}
	printf("copy success!\n");
	fclose(f_one);
	fclose(f_two);
	return 0;
}
int is_coverfunc(char is_cover)
{
	if(is_cover =='y'||is_cover =='Y')
        {
		return 0;
	}
         else if(is_cover =='n'||is_cover =='N')
        {
                return -1;
        }
        else
        {
                printf("Invailed operation\n");
                return -1;
        }
}
