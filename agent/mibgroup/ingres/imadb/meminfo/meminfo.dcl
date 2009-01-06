/* Description of table ima_memory_info from database imadb */
  EXEC SQL DECLARE ima_memory_info TABLE
	(memInfoServer	varchar(64) not null,
	 memInfoBytesUsed	integer not null,
	 memInfoFreePages	integer not null,
	 memInfoGetPages	integer not null,
	 memInfoPagesUsed	integer not null);

  struct meminfo_ {
	char	memInfoServer[65];
	long	memInfoBytesUsed;
	long	memInfoFreePages;
	long	memInfoGetPages;
	long	memInfoPagesUsed;
  } memInforec;
