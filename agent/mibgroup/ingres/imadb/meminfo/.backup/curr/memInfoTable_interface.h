/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 15899 $ of $
 *
 * $Id:$
 */
/** @ingroup interface: Routines to interface to Net-SNMP
 *
 * \warning This code should not be modified, called directly,
 *          or used to interpret functionality. It is subject to
 *          change at any time.
 * 
 * @{
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 */
#ifndef MEMINFOTABLE_INTERFACE_H
#define MEMINFOTABLE_INTERFACE_H

#ifdef __cplusplus
extern          "C" {
#endif


#include "memInfoTable.h"


    /*
     ********************************************************************
     * Table declarations
     */

    /*
     * PUBLIC interface initialization routine 
     */
    void           
        _memInfoTable_initialize_interface(memInfoTable_registration *
                                           user_ctx, u_long flags);
    void           
        _memInfoTable_shutdown_interface(memInfoTable_registration *
                                         user_ctx);

    memInfoTable_registration *memInfoTable_registration_get(void);

    memInfoTable_registration
        *memInfoTable_registration_set(memInfoTable_registration * newreg);

    netsnmp_container *memInfoTable_container_get(void);
    int             memInfoTable_container_size(void);

    memInfoTable_rowreq_ctx *memInfoTable_allocate_rowreq_ctx(void *);
    void            memInfoTable_release_rowreq_ctx(memInfoTable_rowreq_ctx
                                                    * rowreq_ctx);

    int             memInfoTable_index_to_oid(netsnmp_index * oid_idx,
                                              memInfoTable_mib_index *
                                              mib_idx);
    int             memInfoTable_index_from_oid(netsnmp_index * oid_idx,
                                                memInfoTable_mib_index *
                                                mib_idx);

    /*
     * access to certain internals. use with caution!
     */
    void            memInfoTable_valid_columns_set(netsnmp_column_info
                                                   *vc);


#ifdef __cplusplus
}
#endif
#endif                          /* MEMINFOTABLE_INTERFACE_H */
/** @} */
