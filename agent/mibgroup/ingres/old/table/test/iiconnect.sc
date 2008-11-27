# include <stdio.h>

int ima_scalar(char * classid, char * instance);

int main (void)
{
char value[256];
ima_scalar(&'exp.scf.scd.fastcommit',&'0',value);
printf("%s\n",value);
}

int ima_scalar(char * classid, char * instance, char val[256])
{
printf("ima_scalar called !\n");

EXEC SQL CONNECT imadb;
EXEC SQL SELECT value 
	INTO :val 
	from ima_mib_objects 
	where classid = 'exp.scf.scd.fastcommit' and instance = '0' ; 
EXEC SQL COMMIT;
EXEC SQL DISCONNECT;

printf("Value is %s\n",val);

}

