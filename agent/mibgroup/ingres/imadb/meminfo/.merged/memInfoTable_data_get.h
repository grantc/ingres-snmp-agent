/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $
 *
 * $Id:$
 *
 * @file memInfoTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef MEMINFOTABLE_DATA_GET_H
#define MEMINFOTABLE_DATA_GET_H

#ifdef __cplusplus
extern          "C" {
#endif

    /*
     *********************************************************************
     * GET function declarations
     */

    /*
     *********************************************************************
     * GET Table declarations
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
    /*
     * indexes
     */

    int             memInfoBytesUsed_get(memInfoTable_rowreq_ctx *
                                         rowreq_ctx,
                                         long *memInfoBytesUsed_val_ptr);
    int             memInfoFreePages_get(memInfoTable_rowreq_ctx *
                                         rowreq_ctx,
                                         long *memInfoFreePages_val_ptr);
    int             memInfoGetPages_get(memInfoTable_rowreq_ctx *
                                        rowreq_ctx,
                                        long *memInfoGetPages_val_ptr);
    int             memInfoPagesUsed_get(memInfoTable_rowreq_ctx *
                                         rowreq_ctx,
                                         long *memInfoPagesUsed_val_ptr);


    int             memInfoTable_indexes_set_tbl_idx(memInfoTable_mib_index
                                                     * tbl_idx,
                                                     char
                                                     *memInfoServer_val_ptr,
                                                     size_t
                                                     memInfoServer_val_ptr_len);
    int             memInfoTable_indexes_set(memInfoTable_rowreq_ctx *
                                             rowreq_ctx,
                                             char *memInfoServer_val_ptr,
                                             size_t
                                             memInfoServer_val_ptr_len);




#ifdef __cplusplus
}
#endif
#endif                          /* MEMINFOTABLE_DATA_GET_H */
/** @} */
