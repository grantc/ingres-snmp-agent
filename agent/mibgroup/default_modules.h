/* this is a Net-SNMP distributed file that sets all default mib
   modules to be built into the Net-SNMP agent */


/* these go into both the mini agent and the full agent */


/* limit the mibII modules to the bare minimum */
config_require(mibII/snmp_mib)
config_require(mibII/system_mib)
config_require(mibII/sysORTable)
config_require(mibII/vacm_vars)
config_require(ucd_snmp)
config_require(notification)
config_require(notification-log-mib)
config_require(agentx)
config_require(disman/event)
config_require(disman/schedule)
config_require(utilities)

/* very few default mibs */
config_add_mib(SNMPv2-MIB)
config_add_mib(RFC1213-MIB)

