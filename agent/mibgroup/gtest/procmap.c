/* A quick hack to show memory usage of running process
 *
 * Tru64 v4 and v5
 *
 * Demonstrates the use of /proc on Tru64
 *
 * MJR 2002
 */ 

#include<stdio.h>
#include<stdlib.h>       /* malloc */
#include<unistd.h>       /* close */
#include<sys/types.h>
#include<sys/signal.h>
#include<sys/fault.h>
#include<sys/syscall.h>
#include<sys/procfs.h>
#include<sys/user.h>
#include<string.h>
#include<fcntl.h>        /* open */
#include<errno.h>

#define STACK_TOP (void*)0x120000000
#define TEXT      (void*)0x120000000
#define DATA      (char*)0x140000000
#define SOT_LOW   0x3ff80000000
#define SOT_HIGH  0x3ffc0000000
#define SOD_LOW   SOT_HIGH
#define SOD_HIGH  0x40000000000   /* Seems prudent */

int main(int,char**);

int main(int argc, char *argv[]){
  int pid,proc,nmap,i,hex;
  unsigned long tot;
  char file[30];
  char cflags[7],name[17];
  prmap_t *maps;
  struct prpsinfo psinfo;
  void* heap;

  if ((argc==1)||(!strcmp(argv[1],"-h"))){
    printf("Usage: [-x] %s pid\n\n"
           "Reports memory map of running process. Use -x for hex output.\n\n"
           "Flags are:\n"
           "   RWX  Read Write eXecute\n"
           "   S    Shared (updates modify underlying mmapped object)\n"
           "   F    Grows by Faults (e.g. stack)\n"
           "   B    Grows by Brk (heap?)\n\n"
           "MJR 10/02\n",argv[0]);
    exit(0);
  }

  i=1;
  hex=0;
  if (!strcmp(argv[i],"-x")){hex=1;i++;}

  if (argv[i][0]=='-'){
    fprintf(stderr,"Unknown option %s. Use -h for help\n",argv[i]);
    exit(1);
  }

  pid=atoi(argv[i]);

  if (pid<=0){
    fprintf(stderr,"Refusing to consider a pid of %d.\n"
            "%s -h for help.\n\n",pid,argv[0]);
     exit(1);
  }

  sprintf(file,"/proc/%d",pid);

  proc=open(file,O_RDONLY);

  if (proc==-1){
    fprintf(stderr,"%s: failed to open %s\n",argv[0],file);
    perror(argv[0]);
    exit(1);
  }

  if(ioctl(proc,PIOCPSINFO,&psinfo)==-1){
    printf("Error: PIOCPSINFO failed\n");
    perror("Error");
    exit(1);
  }
  strncpy(name,psinfo.pr_fname,16);name[16]=0;
  printf("%d: %s\n",pid,name);


  if(ioctl(proc,PIOCNMAP,&nmap)==-1){
    printf("Error: PIOCNMAP failed\n");
    perror("Error");
    exit(1);
  }

  maps=malloc(sizeof(prmap_t)*(nmap+5));

  if (!maps){
    printf("Malloc failed\n");
    exit(1);
  }

  i=nmap+4;

  if(ioctl(proc,PIOCNMAP,&nmap)==-1){
    printf("Error: second PIOCNMAP failed\n");
    exit(1);
  }
  
  if (nmap<i){
    if(ioctl(proc,PIOCMAP,maps)==-1){
      printf("Error: PIOCMAPS failed\n");
      exit(1);
    }
  }
  else{
    printf("nmaps now %d: aborting!\n",nmap);
    exit(1);
  }

  close(proc);

  tot=0;heap=NULL;

  for(i=0;i<nmap;i++){
    printf("%16lx   ",(unsigned long)maps[i].pr_vaddr);
    if (hex) printf("%12lx   ",(unsigned long)maps[i].pr_size);
    else if ((unsigned long)maps[i].pr_size<10238976)
      printf("%12ldK  ",(unsigned long)maps[i].pr_size/1024);
    else printf("%12ldM  ",(unsigned long)maps[i].pr_size/1048576);
    tot+=(unsigned long)maps[i].pr_size;
    strcpy(cflags,"      ");
    if (maps[i].pr_mflags & MA_READ) cflags[0]='R';
    if (maps[i].pr_mflags & MA_WRITE) cflags[1]='W';
    if (maps[i].pr_mflags & MA_EXEC) cflags[2]='X';
    if (maps[i].pr_mflags & MA_SHARED) cflags[3]='S';
    if (maps[i].pr_mflags & MA_BREAK) cflags[4]='B';
    if (maps[i].pr_mflags & MA_STACK) cflags[5]='F';
    printf("%s",cflags);
    if (maps[i].pr_vaddr+maps[i].pr_size==STACK_TOP) printf(" [ stack ]");
    if (maps[i].pr_vaddr==TEXT) printf(" [ text  ]");
    if (maps[i].pr_vaddr==DATA) printf(" [ data  ]");
    if ((heap)&&(maps[i].pr_vaddr==heap)) printf(" [ heap  ]");
    if (((unsigned long)maps[i].pr_vaddr>=SOT_LOW)
	&&((unsigned long)maps[i].pr_vaddr<SOT_HIGH))
      printf(" [ shared library text ]");
    if (((unsigned long)maps[i].pr_vaddr>=SOD_LOW)
	&&((unsigned long)maps[i].pr_vaddr<SOD_HIGH))
      printf(" [ shared library data ]");

    if (maps[i].pr_vaddr==DATA) heap=DATA+maps[i].pr_size;
    printf("\n");
  }

  printf("           total   ");
  if (hex) printf("%12lx\n",tot);
  else if (tot<10238976)
    printf("%12ldK\n",tot/1024);
  else printf("%12ldM\n",tot/1048576);


  return(0);
}




