/* Description of table ima_dmf_cache_stats from database imadb */
  EXEC SQL DECLARE ima_dmf_cache_stats TABLE
	(server	varchar(64) not null,
	 page_size	integer not null,
	 force_count	integer not null,
	 io_wait_count	integer not null,
	 group_buffer_read_count	integer not null,
	 group_buffer_write_count	integer not null,
	 fix_count	integer not null,
	 unfix_count	integer not null,
	 read_count	integer not null,
	 write_count	integer not null,
	 hit_count	integer not null,
	 dirty_unfix_count	integer not null,
	 pages_still_valid	integer not null,
	 pages_invalid	integer not null,
	 buffer_count	integer not null,
	 page_buffer_count	integer not null,
	 flimit	integer not null,
	 mlimit	integer not null,
	 wbstart	integer not null,
	 wbend	integer not null,
	 hash_bucket_count	integer not null,
	 group_buffer_count	integer not null,
	 group_buffer_size	integer not null,
	 cache_status	integer not null,
	 free_buffer_count	integer not null,
	 free_buffer_waiters	integer not null,
	 fixed_buffer_count	integer not null,
	 modified_buffer_count	integer not null,
	 free_group_buffer_count	integer not null,
	 fixed_group_buffer_count	integer not null,
	 modified_group_buffer_count	integer not null);

  struct dmfrec_ {
	char	server[65];
	long	page_size;
	long	force_count;
	long	io_wait_count;
	long	group_buffer_read_count;
	long	group_buffer_write_count;
	long	fix_count;
	long	unfix_count;
	long	read_count;
	long	write_count;
	long	hit_count;
	long	dirty_unfix_count;
	long	pages_still_valid;
	long	pages_invalid;
	long	buffer_count;
	long	page_buffer_count;
	long	flimit;
	long	mlimit;
	long	wbstart;
	long	wbend;
	long	hash_bucket_count;
	long	group_buffer_count;
	long	group_buffer_size;
	long	cache_status;
	long	free_buffer_count;
	long	free_buffer_waiters;
	long	fixed_buffer_count;
	long	modified_buffer_count;
	long	free_group_buffer_count;
	long	fixed_group_buffer_count;
	long	modified_group_buffer_count;
  } dmfrec;
