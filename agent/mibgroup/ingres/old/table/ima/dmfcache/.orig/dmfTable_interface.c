/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 15899 $ of $ 
 *
 * $Id:$
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

/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "dmfTable.h"


#include <net-snmp/agent/table_container.h>
#include <net-snmp/library/container.h>

#include "dmfTable_interface.h"

#include <ctype.h>

/**********************************************************************
 **********************************************************************
 ***
 *** Table dmfTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * INGRES-MIB::dmfTable is subid 1 of imadb.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.757.5.1.1, length: 10
 */
typedef struct dmfTable_interface_ctx_s {

    netsnmp_container *container;
    netsnmp_cache  *cache;

    dmfTable_registration *user_ctx;

    netsnmp_table_registration_info tbl_info;

    netsnmp_baby_steps_access_methods access_multiplexer;

} dmfTable_interface_ctx;

static dmfTable_interface_ctx dmfTable_if_ctx;

static void     _dmfTable_container_init(dmfTable_interface_ctx * if_ctx);
static void     _dmfTable_container_shutdown(dmfTable_interface_ctx *
                                             if_ctx);


netsnmp_container *
dmfTable_container_get(void)
{
    return dmfTable_if_ctx.container;
}

dmfTable_registration *
dmfTable_registration_get(void)
{
    return dmfTable_if_ctx.user_ctx;
}

dmfTable_registration *
dmfTable_registration_set(dmfTable_registration * newreg)
{
    dmfTable_registration *old = dmfTable_if_ctx.user_ctx;
    dmfTable_if_ctx.user_ctx = newreg;
    return old;
}

int
dmfTable_container_size(void)
{
    return CONTAINER_SIZE(dmfTable_if_ctx.container);
}

/*
 * mfd multiplexer modes
 */
static Netsnmp_Node_Handler _mfd_dmfTable_pre_request;
static Netsnmp_Node_Handler _mfd_dmfTable_post_request;
static Netsnmp_Node_Handler _mfd_dmfTable_object_lookup;
static Netsnmp_Node_Handler _mfd_dmfTable_get_values;
/**
 * @internal
 * Initialize the table dmfTable 
 *    (Define its contents and how it's structured)
 */
void
_dmfTable_initialize_interface(dmfTable_registration * reg_ptr,
                               u_long flags)
{
    netsnmp_baby_steps_access_methods *access_multiplexer =
        &dmfTable_if_ctx.access_multiplexer;
    netsnmp_table_registration_info *tbl_info = &dmfTable_if_ctx.tbl_info;
    netsnmp_handler_registration *reginfo;
    netsnmp_mib_handler *handler;
    int             mfd_modes = 0;

    DEBUGMSGTL(("internal:dmfTable:_dmfTable_initialize_interface",
                "called\n"));


    /*************************************************
     *
     * save interface context for dmfTable
     */
    /*
     * Setting up the table's definition
     */
    netsnmp_table_helper_add_indexes(tbl_info, ASN_OCTET_STR,
                                                 /** index: server */
                                     ASN_INTEGER,
                                               /** index: pagesize */
                                     0);

    /*
     * Define the minimum and maximum accessible columns.  This
     * optimizes retrival. 
     */
    tbl_info->min_column = DMFTABLE_MIN_COL;
    tbl_info->max_column = DMFTABLE_MAX_COL;

    /*
     * save users context
     */
    dmfTable_if_ctx.user_ctx = reg_ptr;

    /*
     * call data access initialization code
     */
    dmfTable_init_data(reg_ptr);

    /*
     * set up the container
     */
    _dmfTable_container_init(&dmfTable_if_ctx);
    if (NULL == dmfTable_if_ctx.container) {
        snmp_log(LOG_ERR, "could not initialize container for dmfTable\n");
        return;
    }

    /*
     * access_multiplexer: REQUIRED wrapper for get request handling
     */
    access_multiplexer->object_lookup = _mfd_dmfTable_object_lookup;
    access_multiplexer->get_values = _mfd_dmfTable_get_values;

    /*
     * no wrappers yet
     */
    access_multiplexer->pre_request = _mfd_dmfTable_pre_request;
    access_multiplexer->post_request = _mfd_dmfTable_post_request;


    /*************************************************
     *
     * Create a registration, save our reg data, register table.
     */
    DEBUGMSGTL(("dmfTable:init_dmfTable",
                "Registering dmfTable as a mibs-for-dummies table.\n"));
    handler =
        netsnmp_baby_steps_access_multiplexer_get(access_multiplexer);
    reginfo =
        netsnmp_handler_registration_create("dmfTable", handler,
                                            dmfTable_oid,
                                            dmfTable_oid_size,
                                            HANDLER_CAN_BABY_STEP |
                                            HANDLER_CAN_RONLY);
    if (NULL == reginfo) {
        snmp_log(LOG_ERR, "error registering table dmfTable\n");
        return;
    }
    reginfo->my_reg_void = &dmfTable_if_ctx;

    /*************************************************
     *
     * set up baby steps handler, create it and inject it
     */
    if (access_multiplexer->object_lookup)
        mfd_modes |= BABY_STEP_OBJECT_LOOKUP;
    if (access_multiplexer->set_values)
        mfd_modes |= BABY_STEP_SET_VALUES;
    if (access_multiplexer->irreversible_commit)
        mfd_modes |= BABY_STEP_IRREVERSIBLE_COMMIT;
    if (access_multiplexer->object_syntax_checks)
        mfd_modes |= BABY_STEP_CHECK_OBJECT;

    if (access_multiplexer->pre_request)
        mfd_modes |= BABY_STEP_PRE_REQUEST;
    if (access_multiplexer->post_request)
        mfd_modes |= BABY_STEP_POST_REQUEST;

    if (access_multiplexer->undo_setup)
        mfd_modes |= BABY_STEP_UNDO_SETUP;
    if (access_multiplexer->undo_cleanup)
        mfd_modes |= BABY_STEP_UNDO_CLEANUP;
    if (access_multiplexer->undo_sets)
        mfd_modes |= BABY_STEP_UNDO_SETS;

    if (access_multiplexer->row_creation)
        mfd_modes |= BABY_STEP_ROW_CREATE;
    if (access_multiplexer->consistency_checks)
        mfd_modes |= BABY_STEP_CHECK_CONSISTENCY;
    if (access_multiplexer->commit)
        mfd_modes |= BABY_STEP_COMMIT;
    if (access_multiplexer->undo_commit)
        mfd_modes |= BABY_STEP_UNDO_COMMIT;

    handler = netsnmp_baby_steps_handler_get(mfd_modes);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject row_merge helper with prefix rootoid_len + 2 (entry.col)
     */
    handler = netsnmp_get_row_merge_handler(reginfo->rootoid_len + 2);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject container_table helper
     */
    handler =
        netsnmp_container_table_handler_get(tbl_info,
                                            dmfTable_if_ctx.container,
                                            TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject cache helper
     */
    if (NULL != dmfTable_if_ctx.cache) {
        handler = netsnmp_cache_handler_get(dmfTable_if_ctx.cache);
        netsnmp_inject_handler(reginfo, handler);
    }

    /*
     * register table
     */
    netsnmp_register_table(reginfo, tbl_info);

}                               /* _dmfTable_initialize_interface */

/**
 * @internal
 * Shutdown the table dmfTable
 */
void
_dmfTable_shutdown_interface(dmfTable_registration * reg_ptr)
{
    /*
     * shutdown the container
     */
    _dmfTable_container_shutdown(&dmfTable_if_ctx);
}

void
dmfTable_valid_columns_set(netsnmp_column_info *vc)
{
    dmfTable_if_ctx.tbl_info.valid_columns = vc;
}                               /* dmfTable_valid_columns_set */

/**
 * @internal
 * convert the index component stored in the context to an oid
 */
int
dmfTable_index_to_oid(netsnmp_index * oid_idx,
                      dmfTable_mib_index * mib_idx)
{
    int             err = SNMP_ERR_NOERROR;

    /*
     * temp storage for parsing indexes
     */
    /*
     * server(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
     */
    netsnmp_variable_list var_server;
    /*
     * pagesize(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
     */
    netsnmp_variable_list var_pagesize;

    /*
     * set up varbinds
     */
    memset(&var_server, 0x00, sizeof(var_server));
    var_server.type = ASN_OCTET_STR;
    memset(&var_pagesize, 0x00, sizeof(var_pagesize));
    var_pagesize.type = ASN_INTEGER;

    /*
     * chain temp index varbinds together
     */
    var_server.next_variable = &var_pagesize;
    var_pagesize.next_variable = NULL;


    DEBUGMSGTL(("verbose:dmfTable:dmfTable_index_to_oid", "called\n"));

    /*
     * server(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h 
     */
    snmp_set_var_value(&var_server, (u_char *) & mib_idx->server,
                       mib_idx->server_len * sizeof(mib_idx->server[0]));

    /*
     * pagesize(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h 
     */
    snmp_set_var_value(&var_pagesize, (u_char *) & mib_idx->pagesize,
                       sizeof(mib_idx->pagesize));


    err = build_oid_noalloc(oid_idx->oids, oid_idx->len, &oid_idx->len,
                            NULL, 0, &var_server);
    if (err)
        snmp_log(LOG_ERR, "error %d converting index to oid\n", err);

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_server);

    return err;
}                               /* dmfTable_index_to_oid */

/**
 * extract dmfTable indexes from a netsnmp_index
 *
 * @retval SNMP_ERR_NOERROR  : no error
 * @retval SNMP_ERR_GENERR   : error
 */
int
dmfTable_index_from_oid(netsnmp_index * oid_idx,
                        dmfTable_mib_index * mib_idx)
{
    int             err = SNMP_ERR_NOERROR;

    /*
     * temp storage for parsing indexes
     */
    /*
     * server(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
     */
    netsnmp_variable_list var_server;
    /*
     * pagesize(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
     */
    netsnmp_variable_list var_pagesize;

    /*
     * set up varbinds
     */
    memset(&var_server, 0x00, sizeof(var_server));
    var_server.type = ASN_OCTET_STR;
    memset(&var_pagesize, 0x00, sizeof(var_pagesize));
    var_pagesize.type = ASN_INTEGER;

    /*
     * chain temp index varbinds together
     */
    var_server.next_variable = &var_pagesize;
    var_pagesize.next_variable = NULL;


    DEBUGMSGTL(("verbose:dmfTable:dmfTable_index_from_oid", "called\n"));

    /*
     * parse the oid into the individual index components
     */
    err = parse_oid_indexes(oid_idx->oids, oid_idx->len, &var_server);
    if (err == SNMP_ERR_NOERROR) {
        /*
         * copy out values
         */
        /*
         * NOTE: val_len is in bytes, server_len might not be
         */
        if (var_server.val_len > sizeof(mib_idx->server))
            err = SNMP_ERR_GENERR;
        else {
            memcpy(mib_idx->server, var_server.val.string,
                   var_server.val_len);
            mib_idx->server_len =
                var_server.val_len / sizeof(mib_idx->server[0]);
        }
        mib_idx->pagesize = *((long *) var_pagesize.val.string);


    }

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_server);

    return err;
}                               /* dmfTable_index_from_oid */


/*
 *********************************************************************
 * @internal
 * allocate resources for a dmfTable_rowreq_ctx
 */
dmfTable_rowreq_ctx *
dmfTable_allocate_rowreq_ctx(void *user_init_ctx)
{
    dmfTable_rowreq_ctx *rowreq_ctx =
        SNMP_MALLOC_TYPEDEF(dmfTable_rowreq_ctx);

    DEBUGMSGTL(("internal:dmfTable:dmfTable_allocate_rowreq_ctx",
                "called\n"));

    if (NULL == rowreq_ctx) {
        snmp_log(LOG_ERR, "Couldn't allocate memory for a "
                 "dmfTable_rowreq_ctx.\n");
        return NULL;
    }

    rowreq_ctx->oid_idx.oids = rowreq_ctx->oid_tmp;

    rowreq_ctx->dmfTable_data_list = NULL;

    /*
     * if we allocated data, call init routine
     */
    if (!(rowreq_ctx->rowreq_flags & MFD_ROW_DATA_FROM_USER)) {
        if (SNMPERR_SUCCESS !=
            dmfTable_rowreq_ctx_init(rowreq_ctx, user_init_ctx)) {
            dmfTable_release_rowreq_ctx(rowreq_ctx);
            rowreq_ctx = NULL;
        }
    }

    return rowreq_ctx;
}                               /* dmfTable_allocate_rowreq_ctx */

/*
 * @internal
 * release resources for a dmfTable_rowreq_ctx
 */
void
dmfTable_release_rowreq_ctx(dmfTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("internal:dmfTable:dmfTable_release_rowreq_ctx",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    dmfTable_rowreq_ctx_cleanup(rowreq_ctx);

    /*
     * free index oid pointer
     */
    if (rowreq_ctx->oid_idx.oids != rowreq_ctx->oid_tmp)
        free(rowreq_ctx->oid_idx.oids);

    SNMP_FREE(rowreq_ctx);
}                               /* dmfTable_release_rowreq_ctx */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dmfTable_pre_request(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info *agtreq_info,
                          netsnmp_request_info *requests)
{
    int             rc;

    DEBUGMSGTL(("internal:dmfTable:_mfd_dmfTable_pre_request",
                "called\n"));

    if (1 != netsnmp_row_merge_status_first(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:dmfTable",
                    "skipping additional pre_request\n"));
        return SNMP_ERR_NOERROR;
    }

    rc = dmfTable_pre_request(dmfTable_if_ctx.user_ctx);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("dmfTable", "error %d from "
                    "dmfTable_pre_request\n", rc));
        netsnmp_request_set_error_all(requests, SNMP_VALIDATE_ERR(rc));
    }

    return SNMP_ERR_NOERROR;
}                               /* _mfd_dmfTable_pre_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dmfTable_post_request(netsnmp_mib_handler *handler,
                           netsnmp_handler_registration *reginfo,
                           netsnmp_agent_request_info *agtreq_info,
                           netsnmp_request_info *requests)
{
    dmfTable_rowreq_ctx *rowreq_ctx =
        netsnmp_container_table_row_extract(requests);
    int             rc, packet_rc;

    DEBUGMSGTL(("internal:dmfTable:_mfd_dmfTable_post_request",
                "called\n"));

    /*
     * release row context, if deleted
     */
    if (rowreq_ctx && (rowreq_ctx->rowreq_flags & MFD_ROW_DELETED))
        dmfTable_release_rowreq_ctx(rowreq_ctx);

    /*
     * wait for last call before calling user
     */
    if (1 != netsnmp_row_merge_status_last(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:dmfTable",
                    "waiting for last post_request\n"));
        return SNMP_ERR_NOERROR;
    }

    packet_rc = netsnmp_check_all_requests_error(agtreq_info->asp, 0);
    rc = dmfTable_post_request(dmfTable_if_ctx.user_ctx, packet_rc);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("dmfTable", "error %d from "
                    "dmfTable_post_request\n", rc));
    }

    return SNMP_ERR_NOERROR;
}                               /* _mfd_dmfTable_post_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dmfTable_object_lookup(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *agtreq_info,
                            netsnmp_request_info *requests)
{
    int             rc = SNMP_ERR_NOERROR;
    dmfTable_rowreq_ctx *rowreq_ctx =
        netsnmp_container_table_row_extract(requests);

    DEBUGMSGTL(("internal:dmfTable:_mfd_dmfTable_object_lookup",
                "called\n"));

    /*
     * get our context from mfd
     * dmfTable_interface_ctx *if_ctx =
     *             (dmfTable_interface_ctx *)reginfo->my_reg_void;
     */

    if (NULL == rowreq_ctx) {
        rc = SNMP_ERR_NOCREATION;
    }

    if (MFD_SUCCESS != rc)
        netsnmp_request_set_error_all(requests, rc);
    else
        dmfTable_row_prep(rowreq_ctx);

    return SNMP_VALIDATE_ERR(rc);
}                               /* _mfd_dmfTable_object_lookup */

/***********************************************************************
 *
 * GET processing
 *
 ***********************************************************************/
/*
 * @internal
 * Retrieve the value for a particular column
 */
NETSNMP_STATIC_INLINE int
_dmfTable_get_column(dmfTable_rowreq_ctx * rowreq_ctx,
                     netsnmp_variable_list * var, int column)
{
    int             rc = SNMPERR_SUCCESS;

    DEBUGMSGTL(("internal:dmfTable:_mfd_dmfTable_get_column",
                "called for %d\n", column));


    netsnmp_assert(NULL != rowreq_ctx);

    switch (column) {

        /*
         * (INDEX) server(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h 
         */
    case COLUMN_SERVER:
        var->type = ASN_OCTET_STR;
        /*
         * NOTE: val_len is in bytes, server_len might not be (e.g. oids)
         */
        if (var->val_len < (rowreq_ctx->tbl_idx.server_len *
                            sizeof(rowreq_ctx->tbl_idx.server[0]))) {
            var->val.string = malloc(rowreq_ctx->tbl_idx.server_len *
                                     sizeof(rowreq_ctx->tbl_idx.
                                            server[0]));
        }
        var->val_len =
            rowreq_ctx->tbl_idx.server_len *
            sizeof(rowreq_ctx->tbl_idx.server[0]);
        memcpy(var->val.string, rowreq_ctx->tbl_idx.server, var->val_len);
        break;

        /*
         * (INDEX) pagesize(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h 
         */
    case COLUMN_PAGESIZE:
        var->type = ASN_INTEGER;
        var->val_len = sizeof(long);
        (*var->val.integer) = rowreq_ctx->tbl_idx.pagesize;
        break;

        /*
         * fixCount(3)/INTEGER32/ASN_INTEGER/long(long)//l/A/w/e/r/d/h 
         */
    case COLUMN_FIXCOUNT:
        var->val_len = sizeof(long);
        var->type = ASN_INTEGER;
        rc = fixCount_get(rowreq_ctx, (long *) var->val.string);
        break;

    default:
        if (DMFTABLE_MIN_COL <= column && column <= DMFTABLE_MAX_COL) {
            DEBUGMSGTL(("internal:dmfTable:_mfd_dmfTable_get_column",
                        "assume column %d is reserved\n", column));
            rc = MFD_SKIP;
        } else {
            snmp_log(LOG_ERR,
                     "unknown column %d in _dmfTable_get_column\n",
                     column);
        }
        break;
    }

    return rc;
}                               /* _dmfTable_get_column */

int
_mfd_dmfTable_get_values(netsnmp_mib_handler *handler,
                         netsnmp_handler_registration *reginfo,
                         netsnmp_agent_request_info *agtreq_info,
                         netsnmp_request_info *requests)
{
    dmfTable_rowreq_ctx *rowreq_ctx =
        netsnmp_container_table_row_extract(requests);
    netsnmp_table_request_info *tri;
    u_char         *old_string;
    void            (*dataFreeHook) (void *);
    int             rc;

    DEBUGMSGTL(("internal:dmfTable:_mfd_dmfTable_get_values", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    for (; requests; requests = requests->next) {
        /*
         * save old pointer, so we can free it if replaced
         */
        old_string = requests->requestvb->val.string;
        dataFreeHook = requests->requestvb->dataFreeHook;
        if (NULL == requests->requestvb->val.string) {
            requests->requestvb->val.string = requests->requestvb->buf;
            requests->requestvb->val_len =
                sizeof(requests->requestvb->buf);
        } else if (requests->requestvb->buf ==
                   requests->requestvb->val.string) {
            if (requests->requestvb->val_len !=
                sizeof(requests->requestvb->buf))
                requests->requestvb->val_len =
                    sizeof(requests->requestvb->buf);
        }

        /*
         * get column data
         */
        tri = netsnmp_extract_table_info(requests);
        if (NULL == tri)
            continue;

        rc = _dmfTable_get_column(rowreq_ctx, requests->requestvb,
                                  tri->colnum);
        if (rc) {
            if (MFD_SKIP == rc) {
                requests->requestvb->type = SNMP_NOSUCHINSTANCE;
                rc = SNMP_ERR_NOERROR;
            }
        } else if (NULL == requests->requestvb->val.string) {
            snmp_log(LOG_ERR, "NULL varbind data pointer!\n");
            rc = SNMP_ERR_GENERR;
        }
        if (rc)
            netsnmp_request_set_error(requests, SNMP_VALIDATE_ERR(rc));

        /*
         * if the buffer wasn't used previously for the old data (i.e. it
         * was allcoated memory)  and the get routine replaced the pointer,
         * we need to free the previous pointer.
         */
        if (old_string && (old_string != requests->requestvb->buf) &&
            (requests->requestvb->val.string != old_string)) {
            if (dataFreeHook)
                (*dataFreeHook) (old_string);
            else
                free(old_string);
        }
    }                           /* for results */

    return SNMP_ERR_NOERROR;
}                               /* _mfd_dmfTable_get_values */


/***********************************************************************
 *
 * SET processing
 *
 ***********************************************************************/

/*
 * SET PROCESSING NOT APPLICABLE (per MIB or user setting)
 */
/***********************************************************************
 *
 * DATA ACCESS
 *
 ***********************************************************************/
static void     _container_free(netsnmp_container * container);

/**
 * @internal
 */
static int
_cache_load(netsnmp_cache * cache, void *vmagic)
{
    DEBUGMSGTL(("internal:dmfTable:_cache_load", "called\n"));

    if ((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache for dmfTable_cache_load\n");
        return -1;
    }

    /** should only be called for an invalid or expired cache */
    netsnmp_assert((0 == cache->valid) || (1 == cache->expired));

    /*
     * call user code
     */
    return dmfTable_container_load((netsnmp_container *) cache->magic);
}                               /* _cache_load */

/**
 * @internal
 */
static void
_cache_free(netsnmp_cache * cache, void *magic)
{
    netsnmp_container *container;

    DEBUGMSGTL(("internal:dmfTable:_cache_free", "called\n"));

    if ((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache in dmfTable_cache_free\n");
        return;
    }

    container = (netsnmp_container *) cache->magic;

    _container_free(container);
}                               /* _cache_free */

/**
 * @internal
 */
static void
_container_item_free(dmfTable_rowreq_ctx * rowreq_ctx, void *context)
{
    DEBUGMSGTL(("internal:dmfTable:_container_item_free", "called\n"));

    if (NULL == rowreq_ctx)
        return;

    dmfTable_release_rowreq_ctx(rowreq_ctx);
}                               /* _container_item_free */

/**
 * @internal
 */
static void
_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("internal:dmfTable:_container_free", "called\n"));

    if (NULL == container) {
        snmp_log(LOG_ERR,
                 "invalid container in dmfTable_container_free\n");
        return;
    }

    /*
     * call user code
     */
    dmfTable_container_free(container);

    /*
     * free all items. inefficient, but easy.
     */
    CONTAINER_CLEAR(container,
                    (netsnmp_container_obj_func *) _container_item_free,
                    NULL);
}                               /* _container_free */

/**
 * @internal
 * initialize the container with functions or wrappers
 */
void
_dmfTable_container_init(dmfTable_interface_ctx * if_ctx)
{
    DEBUGMSGTL(("internal:dmfTable:_dmfTable_container_init", "called\n"));

    /*
     * cache init
     */
    if_ctx->cache = netsnmp_cache_create(30,    /* timeout in seconds */
                                         _cache_load, _cache_free,
                                         dmfTable_oid, dmfTable_oid_size);

    if (NULL == if_ctx->cache) {
        snmp_log(LOG_ERR, "error creating cache for dmfTable\n");
        return;
    }

    if_ctx->cache->flags = NETSNMP_CACHE_DONT_INVALIDATE_ON_SET;

    dmfTable_container_init(&if_ctx->container, if_ctx->cache);
    if (NULL == if_ctx->container)
        if_ctx->container =
            netsnmp_container_find("dmfTable:table_container");
    if (NULL == if_ctx->container) {
        snmp_log(LOG_ERR, "error creating container in "
                 "dmfTable_container_init\n");
        return;
    }

    if (NULL != if_ctx->cache)
        if_ctx->cache->magic = (void *) if_ctx->container;
}                               /* _dmfTable_container_init */

/**
 * @internal
 * shutdown the container with functions or wrappers
 */
void
_dmfTable_container_shutdown(dmfTable_interface_ctx * if_ctx)
{
    DEBUGMSGTL(("internal:dmfTable:_dmfTable_container_shutdown",
                "called\n"));

    dmfTable_container_shutdown(if_ctx->container);

    _container_free(if_ctx->container);

}                               /* _dmfTable_container_shutdown */


dmfTable_rowreq_ctx *
dmfTable_row_find_by_mib_index(dmfTable_mib_index * mib_idx)
{
    dmfTable_rowreq_ctx *rowreq_ctx;
    oid             oid_tmp[MAX_OID_LEN];
    netsnmp_index   oid_idx;
    int             rc;

    /*
     * set up storage for OID
     */
    oid_idx.oids = oid_tmp;
    oid_idx.len = sizeof(oid_tmp) / sizeof(oid);

    /*
     * convert
     */
    rc = dmfTable_index_to_oid(&oid_idx, mib_idx);
    if (MFD_SUCCESS != rc)
        return NULL;

    rowreq_ctx = CONTAINER_FIND(dmfTable_if_ctx.container, &oid_idx);

    return rowreq_ctx;
}
