#include "getprops.h"

int getprops (char *filename)
{
	struct stat file_stat;
        char mode[] = "----------";
        int er_mode[]={0,0,0,0};
        int pos;
        mode_t m;
	char *type; /* file type*/
	if( access(filename,F_OK) == -1)
	{
		return -1;
	}
        if ((stat(filename, &file_stat)) == -1)
        {
   	 /* 获取文件属性出错 */
                printf("stat File Error.\n");
                exit(1);
        }
        m = file_stat.st_mode;
        pos = 0;
        mode[0] = S_ISDIR(file_stat.st_mode)?'d':'-';
        pos++;
        if (S_IRUSR & m)
        {
                mode[pos] = 'r';
                er_mode[1] = er_mode[1]+4;
        }
        pos++;
        if (S_IWUSR & m)
        {
               mode[pos] = 'w';
                er_mode[1] = er_mode[1]+2;
        }
        pos++;
        if (S_IXUSR & m)
        {
               mode[pos] = 'x';
                er_mode[1] = er_mode[1]+1;
        }
        pos++;
	 if (S_IRGRP & m)
        {
                mode[pos] = 'r';
                er_mode[2] = er_mode[2]+4;
        }
        pos++;
        if (S_IWGRP & m)
        {
                mode[pos] = 'w';
                er_mode[2] = er_mode[2]+2;
        }
        pos++;
        if (S_IXGRP & m)
        {
                mode[pos] = 'x';
                er_mode[2] = er_mode[2]+1;
        }
        pos++;

	if (S_IROTH & m)
        {
               mode[pos] = 'r';
               er_mode[3] = er_mode[3]+4;
        }
        pos++;
        if (S_IWOTH & m)
        {
                mode[pos] = 'w';
                er_mode[3] = er_mode[3]+2;
        }
        pos++;
        if (S_IXOTH & m)
        {
                mode[pos] = 'x';
                er_mode[3] = er_mode[3]+1;
        }
	type = S_ISDIR(file_stat.st_mode)?"directory":"regular file";
        printf("  File: '%s'\n", filename);
        printf("  Size: %d",(int)file_stat.st_blksize);
        printf("\t Blocks: %d   %s\n", (int)file_stat.st_blocks,type);
        printf("Device: %d",(int)file_stat.st_dev);
        printf("\t Inode: %ld",(long)file_stat.st_ino);
        printf("\t Links: %d\n",(int)file_stat.st_nlink);
        printf("Access: (0%d%d%d / %s)", er_mode[1],er_mode[2],er_mode[3],mode);
        printf("   Uid: (%d)    Gid: (%d)\n",file_stat.st_uid,file_stat.st_gid);
        printf("Access: %s", ctime(&file_stat.st_atime));
        printf("Modify: %s", ctime(&file_stat.st_mtime));
        printf("Change: %s", ctime(&file_stat.st_ctime));
	return 0;
}
