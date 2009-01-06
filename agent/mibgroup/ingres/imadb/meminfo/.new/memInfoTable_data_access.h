/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef MEMINFOTABLE_DATA_ACCESS_H
#define MEMINFOTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern          "C" {
#endif


    /*
     *********************************************************************
     * function declarations
     */

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table memInfoTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * INGRES-MIB::memInfoTable is subid 2 of imadb.
     * Its status is Current.
     * OID: .1.3.6.1.4.1.757.5.1.2, length: 10
     */


    int             memInfoTable_init_data(memInfoTable_registration *
                                           memInfoTable_reg);


    /*
     * TODO:180:o: Review memInfoTable cache timeout.
     * The number of seconds before the cache times out
     */
#define MEMINFOTABLE_CACHE_TIMEOUT   60

    void            memInfoTable_container_init(netsnmp_container **
                                                container_ptr_ptr,
                                                netsnmp_cache * cache);
    void            memInfoTable_container_shutdown(netsnmp_container *
                                                    container_ptr);

    int             memInfoTable_container_load(netsnmp_container *
                                                container);
    void            memInfoTable_container_free(netsnmp_container *
                                                container);

    int             memInfoTable_cache_load(netsnmp_container * container);
    void            memInfoTable_cache_free(netsnmp_container * container);

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     *********************************************************************
     * Since we have no idea how you really access your data, we'll go with
     * a worst case example: a flat text file.
     */
#define MAX_LINE_SIZE 256
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/
    int             memInfoTable_row_prep(memInfoTable_rowreq_ctx *
                                          rowreq_ctx);



#ifdef __cplusplus
}
#endif
#endif                          /* MEMINFOTABLE_DATA_ACCESS_H */
