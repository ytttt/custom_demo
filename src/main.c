#include "main.h"

void quit(int);
int main(int argc, char *argv[])
{
	int dir_file = 0;/*judge create dir or file*/
	int  opt;
	char *optstring = "hqrcdpsfo:l:";
	int offset = 0,length = 0;
	int readenable = 0; 
	int createnable = 0;
	while( (opt = getopt(argc,argv,optstring)) != -1 )
	{
		switch (opt)
		{
			case 'h':
				if(argc != optind)
				{
					quit(-1);
				}
				readfile("/home/yt/custom_demo/manpage",0,0);
				quit(0);
			case 'q':
				if(optind < 2 ||argc - optind != 1)
				{
					quit(-1);
				}
				getprops(argv[optind]);
				quit(0);
			case 'r':
				readenable = 1;
				break;
			case 'c':
				createnable = 1;
				break;
			case 'd':
				if(optind < 2 ||argc - optind != 1)
				{
					quit(-1);
				}
				delete(argv[optind]);
				quit(0);
			case 'p':
				if(optind < 2 ||argc - optind != 2)
				{
					quit(-1);
				}
				copyfile(argv[optind],argv[optind+1]);
				quit(0);
			case 's':
				if(optind < 2 ||argc - optind != 2)
				{
					quit(-1);
				}
				lnsoft(argv[optind],argv[optind+1]);
				quit(0);
			case 'f':
				dir_file = 1;
				break;
			case 'o':
				offset = atoi(optarg);
				break;
			case 'l':
				length = atoi(optarg);
				break;
			case '?':
				quit(-1);
		}
	}
	if(readenable == 1)
	{	
		if (argv[optind] == NULL)
		{
			quit(-1);
		}
		readfile(argv[optind],offset,length);
	}
	if(createnable == 1)
	{
		if (argv[optind] == NULL)
		{
			quit(-1);
		}
		create (argv[optind],0666,dir_file);
	}
	if(optind < 2)
	{
		printf("Missing option!\n");
		quit(-1);
	}
	return 0;
}
void quit(int quit_status)
{
	if( quit_status != 0 )	
	{
		printf("Error : Try 'custom_demo -h' for more information!\n");
		exit(-1);
	}
	exit(0);
}
