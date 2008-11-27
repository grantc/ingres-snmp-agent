/* Description of table ima_dmf_cache_stats from database imadb */
  EXEC SQL DECLARE ima_dmf_cache_stats TABLE
	(server	varchar(64) not null,
	 pagesize	integer not null,
	 forceCount	integer not null,
	 ioWaitCount	integer not null,
	 groupBufferReadCount	integer not null,
	 groupBufferWriteCount	integer not null,
	 fixCount	integer not null,
	 unfixCount	integer not null,
	 readCount	integer not null,
	 writeCount	integer not null,
	 hitCount	integer not null,
	 dirtyUnfixCount	integer not null,
	 pagesStillValid	integer not null,
	 pagesInvalid	integer not null,
	 bufferCount	integer not null,
	 pageBufferCount	integer not null,
	 fLimit	integer not null,
	 mLimit	integer not null,
	 wbStart	integer not null,
	 wbEnd	integer not null,
	 hashBucketCount	integer not null,
	 groupBufferCount	integer not null,
	 groupBufferSize	integer not null,
	 cacheStatus	integer not null,
	 freeBuffercount	integer not null,
	 freeBufferWaiters	integer not null,
	 fixedBufferCount	integer not null,
	 modifiedBufferCount	integer not null,
	 freeGroupBufferCount	integer not null,
	 fixedGroupBufferCount	integer not null,
	 modifiedGroupBufferCount	integer not null);

  struct dmfrec_ {
	char	server[65];
	long	pagesize;
	long	forceCount;
	long	ioWaitCount;
	long	groupBufferReadCount;
	long	groupBufferWriteCount;
	long	fixCount;
	long	unfixCount;
	long	readCount;
	long	writeCount;
	long	hitCount;
	long	dirtyUnfixCount;
	long	pagesStillValid;
	long	pagesInvalid;
	long	bufferCount;
	long	pageBufferCount;
	long	fLimit;
	long	mLimit;
	long	wbStart;
	long	wbEnd;
	long	hashBucketCount;
	long	groupBufferCount;
	long	groupBufferSize;
	long	cacheStatus;
	long	freeBufferCount;
	long	freeBufferWaiters;
	long	fixedBufferCount;
	long	modifiedBufferCount;
	long	freeGroupBufferCount;
	long	fixedGroupBufferCount;
	long	modifiedGroupBufferCount;
  } dmfrec;
