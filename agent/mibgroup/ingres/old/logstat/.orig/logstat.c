/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.ingres.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "logstat.h"
#include <regex.h>
#include "/opt/Ingres/IngresII/ingres/sig/esql/ingstat.c"

/** Initializes the logstat module */
void
init_logstat(void)
{
    static oid      logWritersBusy_oid[] =
        { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 1 };

    static oid      maxWriteQueueLength_oid[] =
        { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 2 };

    static oid      maxWriteQueueCount_oid[] =
        { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 3 };

    static oid      logWaits_oid[] = { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 4 };

    static oid      splitBuffer_oid[] =
        { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 5 };

    static oid      freeBuffer_oid[] =
        { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 6 };

    static oid      lastBuf_oid[] = { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 7 };

    static oid      logFullStall_oid[] =
        { 1, 3, 6, 1, 4, 1, 757, 5, 3, 9, 8 };


    DEBUGMSGTL(("logstat", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("logWritersBusy", handle_logWritersBusy,
                             logWritersBusy_oid,
                             OID_LENGTH(logWritersBusy_oid),
                             HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised logWritersBusy as .1.3.6.1.4.1.757.5.3.9.1\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("maxWriteQueueLength",
                             handle_maxWriteQueueLength,
                             maxWriteQueueLength_oid,
                             OID_LENGTH(maxWriteQueueLength_oid),
                             HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised maxWriteQueueLength as .1.3.6.1.4.1.757.5.3.9.2\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("maxWriteQueueCount",
                             handle_maxWriteQueueCount,
                             maxWriteQueueCount_oid,
                             OID_LENGTH(maxWriteQueueCount_oid),
                             HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised maxWriteQueueCount as .1.3.6.1.4.1.757.5.3.9.3\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("logWaits", handle_logWaits, logWaits_oid,
                             OID_LENGTH(logWaits_oid), HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised logWaits as .1.3.6.1.4.1.757.5.3.9.4\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("splitBuffer", handle_splitBuffer,
                             splitBuffer_oid, OID_LENGTH(splitBuffer_oid),
                             HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised splitBuffer as .1.3.6.1.4.1.757.5.3.9.5\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("freeBuffer", handle_freeBuffer,
                             freeBuffer_oid, OID_LENGTH(freeBuffer_oid),
                             HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised freeBuffer as .1.3.6.1.4.1.757.5.3.9.6\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("lastBuf", handle_lastBuf, lastBuf_oid,
                             OID_LENGTH(lastBuf_oid), HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised lastBuf as .1.3.6.1.4.1.757.5.3.9.7\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("logFullStall", handle_logFullStall,
                             logFullStall_oid,
                             OID_LENGTH(logFullStall_oid),
                             HANDLER_CAN_RONLY));
    DEBUGMSGTL(("ingres",
                "Initialised logFullStall as .1.3.6.1.4.1.757.5.3.9.8\n"));

}

int
handle_logWritersBusy(netsnmp_mib_handler *handler,
                      netsnmp_handler_registration *reginfo,
                      netsnmp_agent_request_info *reqinfo,
                      netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "logwriters busy\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "logwriters busy\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_logWritersBusy\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_maxWriteQueueLength(netsnmp_mib_handler *handler,
                           netsnmp_handler_registration *reginfo,
                           netsnmp_agent_request_info *reqinfo,
                           netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "write queue len\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "write queue len\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_maxWriteQueueLength\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_maxWriteQueueCount(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info *reqinfo,
                          netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "write queue cnt\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "write queue cnt\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_maxWriteQueueCount\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_logWaits(netsnmp_mib_handler *handler,
                netsnmp_handler_registration *reginfo,
                netsnmp_agent_request_info *reqinfo,
                netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "Log waits\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "Log waits\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_logWaits\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_splitBuffer(netsnmp_mib_handler *handler,
                   netsnmp_handler_registration *reginfo,
                   netsnmp_agent_request_info *reqinfo,
                   netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "Split Buffer\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "Split Buffer\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_splitBuffer\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_freeBuffer(netsnmp_mib_handler *handler,
                  netsnmp_handler_registration *reginfo,
                  netsnmp_agent_request_info *reqinfo,
                  netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "Free Buffer\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "Free Buffer\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_freeBuffer\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_lastBuf(netsnmp_mib_handler *handler,
               netsnmp_handler_registration *reginfo,
               netsnmp_agent_request_info *reqinfo,
               netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "Lastbuf\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "Lastbuf\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_lastBuf\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_logFullStall(netsnmp_mib_handler *handler,
                    netsnmp_handler_registration *reginfo,
                    netsnmp_agent_request_info *reqinfo,
                    netsnmp_request_info *requests)
{
    char            OIDvalue[64] = "";
    char            ingcmd[64] = "";
    char            ingsearch[64] = "";
    char           *parent = "logStatistics";

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        DEBUGMSGTL(("ingres", "Handler called for MODE_GET\n"));

        if ((parent == "logstat") || (parent == "logWaitsByType")) {
            strcpy(ingcmd, "logstat -statistics");
            strcpy(ingsearch, "Logfull Stall\\s+([0-9]+)");
        }

        else if ((parent == "lockStatistics") || (parent == "lockSummary")) {
            strcpy(ingcmd, "lockstat -summary");
            strcpy(ingsearch, "Logfull Stall\\s+([0-9]+)");
        }
        ingstat(ingcmd, ingsearch, OIDvalue);
        DEBUGMSGTL(("ingres", "MODE_GET: iistat returned %s\n", OIDvalue));

        snmp_set_var_typed_value(requests->requestvb,
                                 ASN_OCTET_STR,
                                 (u_char *) OIDvalue, strlen(OIDvalue)
            );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_logFullStall\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
