#include <stdio.h>
#include <string.h>
#include <regex.h>

int ingstat(char * command, char * str, char * value)
{

int i=0;
char temp[10];
FILE *fp;
char line[1024];
int found=0;
char myregex[64]="";

int len = 0;
int j = 0;
int error;

regex_t pdata;
regmatch_t pmatch[3];

DEBUGMSGTL(("ingres","ingstat called\n"));
DEBUGMSGTL(("ingres","running command %s\n",command));
DEBUGMSGTL(("ingres","looking for %s\n",str));

strcpy(myregex,str);

fp = popen(command, "r");
if(!fp) return -1;

while ( fgets( line, sizeof line, fp) && !found)
{
if (found = getval(myregex,line,value))
{
DEBUGMSGTL(("ingres","found\n"));
pclose(fp);
return 1;
}
} // end while loop
DEBUGMSGTL(("ingres","not found\n"));
return 0;
} //end logstat


int getval(char * regex,char * input,char * value)
{
int len = 0;
int i = 0;
int j = 0;
int error;

regex_t pdata;
regmatch_t pmatch[3];

if (error = regcomp(&pdata,regex,REG_EXTENDED))
{
        return -1;
        /* handle error */
}
else if (error = regexec(&pdata,input,3,pmatch,0))
{
        return 0;
}
else
{
        len = pmatch[1].rm_eo - pmatch[1].rm_so;

        i = pmatch[1].rm_so;
        while (i < pmatch[1].rm_eo) {
        value[j] = input[i];
        i++;
        j++;
        }
        value[j] = '\0';

        regfree(&pdata);
        return 1;

}

}

