/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-oids.m2c 12855 2005-09-27 15:56:08Z rstory $
 *
 * $Id:$
 */
#ifndef MEMINFOTABLE_OIDS_H
#define MEMINFOTABLE_OIDS_H

#ifdef __cplusplus
extern          "C" {
#endif


    /*
     * column number definitions for table memInfoTable 
     */
#define MEMINFOTABLE_OID              1,3,6,1,4,1,757,5,1,2

#define COLUMN_MEMINFOSERVER         1

#define COLUMN_MEMINFOBYTESUSED         2

#define COLUMN_MEMINFOFREEPAGES         3

#define COLUMN_MEMINFOGETPAGES         4

#define COLUMN_MEMINFOPAGESUSED         5


#define MEMINFOTABLE_MIN_COL   COLUMN_MEMINFOSERVER
#define MEMINFOTABLE_MAX_COL   COLUMN_MEMINFOPAGESUSED



#ifdef __cplusplus
}
#endif
#endif                          /* MEMINFOTABLE_OIDS_H */
