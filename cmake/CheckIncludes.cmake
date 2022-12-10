include (CheckIncludeFile)
include (CheckIncludeFiles)
include (CheckLibraryExists)
include (CheckSymbolExists)
include (CheckTypeSize)

check_include_files( "float.h;stdarg.h;stdlib.h;string.h" STDC_HEADERS )

check_include_file ("assert.h" HAVE_ASSERT_H)
check_include_file ("byteswap.h" HAVE_BYTESWAP_H)
check_include_file ("errno.h" HAVE_ERRNO_H)
check_include_file ("fcntl.h" HAVE_FCNTL_H)
check_include_file ("fenv.h" HAVE_FENV_H)
check_include_file ("inttypes.h" HAVE_INTTYPES_H)
check_include_file ("limits.h" HAVE_LIMITS_H)
check_include_file ("malloc.h" HAVE_MALLOC_H)
check_include_file ("memory.h" HAVE_MEMORY_H)
check_include_file ("stdbool.h" HAVE_STDBOOL_H)
check_include_file ("stdint.h" HAVE_STDINT_H)
check_include_file ("stdlib.h" HAVE_STDLIB_H)
check_include_file ("string.h" HAVE_STRING_H)
check_include_file ("strings.h" HAVE_STRINGS_H)
check_include_file ("sys/param.h" HAVE_SYS_PARAM_H)
check_include_file ("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file ("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file ("sys/wait.h" HAVE_SYS_WAIT_H)
check_include_file ("unistd.h" HAVE_UNISTD_H)
check_include_file ("xmmintrin.h" HAVE_XMMINTRIN_H)

check_symbol_exists (bcopy "strings.h" HAVE_BCOPY)
check_symbol_exists (fileno "stdio.h" HAVE_FILENO)
check_symbol_exists (flock "sys/file.h" HAVE_FLOCK)
check_symbol_exists (fork "unistd.h" HAVE_FORK )
check_symbol_exists (fsync "unistd.h" HAVE_FSYNC )
check_symbol_exists (ftruncate "unistd.h" HAVE_FTRUNCATE)
check_symbol_exists (getpagesize "unistd.h" HAVE_GETPAGESIZE)
check_symbol_exists (gettimeofday "sys/time.h" HAVE_GETTIMEOFDAY)
check_symbol_exists (gmtime "time.h" HAVE_GMTIME)
check_symbol_exists (gmtime_r "time.h" HAVE_GMTIME_R)
check_symbol_exists (lrint "math.h" HAVE_LRINT)
check_symbol_exists (lrintf "math.h" HAVE_LRINTF)
check_symbol_exists (lround "math.h" HAVE_LROUND)
check_symbol_exists (lstat "sys/stat.h" HAVE_LSTAT)
check_symbol_exists (memcpy "string.h" HAVE_MEMCPY)
check_symbol_exists (memmove "string.h" HAVE_MEMMOVE)
check_symbol_exists (mlock "sys/mman.h" HAVE_MLOCK)
check_symbol_exists (pipe "unistd.h" HAVE_PIPE)
check_symbol_exists (posix_fadvise "fcntl.h" HAVE_POSIX_FADVISE)
check_symbol_exists (posix_memalign "stdlib.h" HAVE_POSIX_MEMALIGN)
check_symbol_exists (strchr "string.h" HAVE_STRCHR)
check_symbol_exists (waitpid "sys/wait.h" HAVE_WAITPID)

check_type_size ("double" SIZEOF_DOUBLE LANGUAGE C)
check_type_size ("float" SIZEOF_FLOAT LANGUAGE C)
check_type_size ("int" SIZEOF_INT LANGUAGE C)
check_type_size ("int16_t" SIZEOF_INT16 LANGUAGE C)
check_type_size ("int32_t" SIZEOF_INT32 LANGUAGE C)
check_type_size ("int64_t" SIZEOF_INT64 LANGUAGE C)
check_type_size ("int8_t" SIZEOF_INT8 LANGUAGE C)
check_type_size ("loff_t" SIZEOF_LOFF LANGUAGE C)
check_type_size ("long double" SIZEOF_LONG_DOUBLE LANGUAGE C)
check_type_size ("long long" SIZEOF_LONG_LONG LANGUAGE C)
check_type_size ("long" SIZEOF_LONG LANGUAGE C)
check_type_size ("off64_t" SIZEOF_OFF64 LANGUAGE C)
check_type_size ("off_t" SIZEOF_OFF LANGUAGE C)
check_type_size ("short" SIZEOF_SHORT LANGUAGE C)
check_type_size ("size_t" SIZEOF_SIZE LANGUAGE C)
check_type_size ("u_int16_t" SIZEOF_U_INT16 LANGUAGE C)
check_type_size ("u_int32_t" SIZEOF_U_INT32 LANGUAGE C)
check_type_size ("uint16_t" SIZEOF_UINT16 LANGUAGE C)
check_type_size ("uint32_t" SIZEOF_UINT32 LANGUAGE C)
check_type_size ("unsigned int" SIZEOF_UNSIGNED_INT LANGUAGE C)
check_type_size ("unsigned long long" SIZEOF_UNSIGNED_LONG_LONG LANGUAGE C)
check_type_size ("unsigned long" SIZEOF_UNSIGNED_LONG LANGUAGE C)
check_type_size ("unsigned short" SIZEOF_UNSIGNED_SHORT LANGUAGE C)
check_type_size ("void*" SIZEOF_POINTER LANGUAGE C)
check_type_size ("wchar_t" SIZEOF_WCHAR LANGUAGE C)