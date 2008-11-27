# include "/opt/Ingres/IngresII/ingres/files/eqdef.h"
#include <stdio.h>
# include "/opt/Ingres/IngresII/ingres/files/eqsqlca.h"
    extern IISQLCA sqlca;   /* SQL Communications Area */
main () {
/* # line 12 "cursor.sc" */	/* connect */
  {
    IIsqInit(&sqlca);
    IIsqConnect(0,(char *)"imadb",(char *)0, (char *)0, (char *)0, (char *)0, 
    (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, 
    (char *)0, (char *)0, (char *)0);
    if (sqlca.sqlcode < 0) 
      IIsqStop(&sqlca);
  }
/* # line 16 "cursor.sc" */	/* open */
  {
    IIsqInit(&sqlca);
    IIcsOpen((char *)"dmfcsr",5353,31724);
    IIwritio(0,(short *)0,1,32,0,(char *)
"select page_size from ima_dmf_cache_stats");
    IIwritio(0,(short *)0,1,32,0,(char *)" for readonly ");
    IIcsQuery((char *)"dmfcsr",5353,31724);
    if (sqlca.sqlcode < 0) 
      clean_up();
  }
/* # line 18 "cursor.sc" */	/* host code */
}
clean_up() {
  char errmsg[101];
/* # line 26 "cursor.sc" */	/* inquire_sql */
  {
    IILQisInqSqlio((short *)0,1,32,100,errmsg,63);
  }
/* # line 27 "cursor.sc" */	/* host code */
printf("Aborting because of error:\n%s\n",errmsg);
/* # line 28 "cursor.sc" */	/* disconnect */
  {
    IIsqInit(&sqlca);
    IIsqDisconnect();
    if (sqlca.sqlcode < 0) 
      clean_up();
  }
/* # line 30 "cursor.sc" */	/* host code */
exit(-1);
}
