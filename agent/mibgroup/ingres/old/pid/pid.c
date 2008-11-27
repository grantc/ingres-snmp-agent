#include <stdio.h>
#include <sys/signal.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <sys/fault.h>
#include <sys/syscall.h>
#include <sys/procfs.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>

#define SHOW_UTT
#include <sys/user.h>

void usage()
{
	printf("usage: arg pid\n");
	exit (-1);
}

int old_main(int argc,char *argv[])
{
	int pid;
	int ret;

	if (argc != 2)
		usage();

	pid = atoi(argv[1]);
	printf("using pid %d\n",pid);

	if ((ret=ptrace(PT_READ_U , pid, NULL, 0)) < 0)
		perror("ptrace");

	printf("ret=0x%x\n",ret);

	return 0;
}

void get_argv(int fd, off_t argv,int size) {
	int i;
	char * buf , * ptr;
	int was_zero = 0;

	ptr = buf = malloc(size);

	if (pread(fd,buf,size,argv) < 0)
		perror("pread");

	/* replace \0 par space, and skip useless space  */

	for (i=0;i<size-1;i++)
	{
		if (buf[i] == 0)
		{
			if (!was_zero)
				*ptr ++ = ' ';
			was_zero = 1;
		}
		else
		{
			*ptr ++ = buf[i];
			was_zero = 0;
		}
	}

	*ptr = 0;

	printf("buf[%d]=%s\n",strlen(buf),buf);

	free(buf);
}

int get_info(const char *file)
{
	int fd;
	struct prpsinfo info;
	struct prstatus status;
	struct utask user;

	fd =open(file,O_RDWR);
	if (fd < 0)
	{
		//perror(file);
		return -1;
	}

	if (ioctl(fd,PIOCPSINFO,&info) < 0)
		perror("ioctl1");

	if (ioctl(fd,PIOCSTATUS,&status) < 0)
		perror("ioctl2");

	if (ioctl(fd,PIOCGETUTK,&user) < 0)
		perror("ioctl 3");

	printf("pr_fname=%s\n",info.pr_fname);
	printf("pr_psargs=%s\n",info.pr_psargs);
	printf("uu_arg_size=%d\n",user.uu_arg_size);
	get_argv(fd,user.uu_argp,user.uu_arg_size);

	return 0;
}

int scan_dir(const char * le_dir)
{
	DIR * dir;
	struct dirent * ent;
	char le_file[100];

	dir = opendir(le_dir);
	if (dir == NULL)
		return -1;

	while ((ent=readdir(dir)) != NULL)
	{
		if (strcmp(ent->d_name,".")==0)
			continue;
		if (strcmp(ent->d_name,"..")==0)
			continue;

		sprintf(le_file,"%s/%s",le_dir,ent->d_name);
		get_info(le_file);
	}

	closedir(dir);
	return 0;
}

int main(int argc,char *argv[])
{
	int pid;
	int ret;
	char file[100];
/*
	if (argc != 2)
		usage();

	pid = atoi(argv[1]);
	printf("using pid %d\n",pid);

	sprintf(file,"/proc/%05d",pid);
	get_info(file);
*/

	scan_dir("/proc");
	return 0;
}
