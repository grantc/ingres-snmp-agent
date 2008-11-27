#include <stdio.h>

EXEC SQL INCLUDE SQLCA;

main () {

EXEC SQL DECLARE dmfcsr CURSOR FOR 
	select page_size from ima_dmf_cache_stats; 

EXEC SQL WHENEVER SQLERROR STOP;

EXEC SQL CONNECT imadb;

EXEC SQL WHENEVER SQLERROR CALL clean_up;

EXEC SQL OPEN dmfcsr FOR READONLY;

}


clean_up() {
exec sql begin declare section;
	char errmsg[101];
exec sql end declare section;

exec sql inquire_sql (:errmsg = ERRORTEXT);
printf("Aborting because of error:\n%s\n",errmsg);
exec sql disconnect;

exit(-1);
}







