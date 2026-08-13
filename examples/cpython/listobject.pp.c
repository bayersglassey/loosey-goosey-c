typedef long unsigned int size_t;
typedef int wchar_t;

typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float32 strtof32 (const char *__restrict __nptr,
     char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float64 strtof64 (const char *__restrict __nptr,
     char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float128 strtof128 (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float32x strtof32x (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float64x strtof64x (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtol") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoul") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoll") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoull") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoll") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoull") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1)));
extern int strfromd (char *__dest, size_t __size, const char *__format,
       double __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf (char *__dest, size_t __size, const char *__format,
       float __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfroml (char *__dest, size_t __size, const char *__format,
       long double __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf32 (char *__dest, size_t __size, const char * __format,
         _Float32 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf64 (char *__dest, size_t __size, const char * __format,
         _Float64 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf128 (char *__dest, size_t __size, const char * __format,
   _Float128 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf32x (char *__dest, size_t __size, const char * __format,
   _Float32x __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf64x (char *__dest, size_t __size, const char * __format,
   _Float64x __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern long int strtol_l (const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
extern unsigned long int strtoul_l (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern long long int strtoll_l (const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
extern long int strtol_l (const char *__restrict __nptr, char **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_strtol_l") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 4)));
extern unsigned long int strtoul_l (const char *__restrict __nptr, char **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_strtoul_l") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern long long int strtoll_l (const char *__restrict __nptr, char **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_strtoll_l") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr, char **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_strtoull_l") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 4)));
extern double strtod_l (const char *__restrict __nptr,
   char **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern float strtof_l (const char *__restrict __nptr,
         char **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern long double strtold_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32 strtof32_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64 strtof64_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float128 strtof128_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32x strtof32x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64x strtof64x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino64_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off64_t off_t;
typedef __off64_t off64_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __builtin_bswap16 (__bsx);
}
static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __builtin_bswap32 (__bsx);
}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);

typedef __blksize_t blksize_t;
typedef __blkcnt64_t blkcnt_t;
typedef __fsblkcnt64_t fsblkcnt_t;
typedef __fsfilcnt64_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data ;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern __uint32_t arc4random (void)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern void arc4random_buf (void *__buf, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *secure_getenv (const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __asm__ ("" "mkstemp64")
     __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __asm__ ("" "mkstemps64") __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp (char *__template, int __flags) __asm__ ("" "mkostemp64")
     __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps (char *__template, int __suffixlen, int __flags) __asm__ ("" "mkostemps64")
     __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *canonicalize_file_name (const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__malloc__))
     __attribute__ ((__malloc__ (__builtin_free, 1))) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;
typedef int (*__compar_fn_t) (const void *, const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t) (const void *, const void *, void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int posix_openpt (int __oflag) ;
extern int grantpt (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int unlockpt (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern char *ptsname (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int getpt (void);
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


typedef __builtin_va_list __gnuc_va_list;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);
typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);
typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);
typedef int cookie_close_function_t (void *__cookie);
typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
typedef __gnuc_va_list va_list;
typedef __fpos64_t fpos_t;
typedef __fpos64_t fpos64_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
        const char *__new, unsigned int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int fclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern FILE *tmpfile (void) __asm__ ("" "tmpfile64")
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *tmpfile64 (void)
   __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern int fcloseall (void);
extern FILE *fopen (const char *__restrict __filename, const char *__restrict __modes) __asm__ ("" "fopen64")
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen (const char *__restrict __filename, const char *__restrict __modes, FILE *__restrict __stream) __asm__ ("" "freopen64")
  __attribute__ ((__nonnull__ (3)));
extern FILE *fopen64 (const char *__restrict __filename,
        const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen64 (const char *__restrict __filename,
   const char *__restrict __modes,
   FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__nonnull__ (1)));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nonnull__ (1)));
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc23_fscanf") __attribute__ ((__nonnull__ (1)));
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc23_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc23_sscanf") __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc23_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc23_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc23_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getc (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getchar (void);
extern int getc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int fputc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int putw (int __w, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2))) __attribute__ ((__nonnull__ (3)));
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream)
    __attribute__ ((__access__ (__write_only__, 1, 2))) __attribute__ ((__nonnull__ (3)));
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));
extern int fputs (const char *__restrict __s, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (2)));
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) __attribute__ ((__nonnull__ (4)));
extern int fputs_unlocked (const char *__restrict __s,
      FILE *__restrict __stream) __attribute__ ((__nonnull__ (2)));
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));
extern int fseek (FILE *__stream, long int __off, int __whence)
  __attribute__ ((__nonnull__ (1)));
extern long int ftell (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern void rewind (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int fseeko (FILE *__stream, __off64_t __off, int __whence) __asm__ ("" "fseeko64") __attribute__ ((__nonnull__ (1)));
extern __off64_t ftello (FILE *__stream) __asm__ ("" "ftello64")
  __attribute__ ((__nonnull__ (1)));
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos) __asm__ ("" "fgetpos64")
  __attribute__ ((__nonnull__ (1)));
extern int fsetpos (FILE *__stream, const fpos_t *__pos) __asm__ ("" "fsetpos64")
  __attribute__ ((__nonnull__ (1)));
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence)
  __attribute__ ((__nonnull__ (1)));
extern __off64_t ftello64 (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos)
  __attribute__ ((__nonnull__ (1)));
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos) __attribute__ ((__nonnull__ (1)));
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void perror (const char *__s) __attribute__ ((__cold__));
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
extern char *cuserid (char *__s)
  __attribute__ ((__access__ (__write_only__, 1)));
struct obstack;
extern int obstack_printf (struct obstack *__restrict __obstack,
      const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       const char *__restrict __format,
       __gnuc_va_list __args)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);


extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern char *program_invocation_name;
extern char *program_invocation_short_name;
typedef int error_t;


extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern void *rawmemchr (const void *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern void *memrchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)))
      __attribute__ ((__access__ (__read_only__, 1, 3)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));
extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 2, 3)));
extern const char *strerrordesc_np (int __err) __attribute__ ((__nothrow__ , __leaf__));
extern const char *strerrorname_np (int __err) __attribute__ ((__nothrow__ , __leaf__));
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));

extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern const char *sigabbrev_np (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern const char *sigdescr_np (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));
extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
extern int strverscmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strfry (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void *memfrob (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__read_write__, 1, 2)));
extern char *basename (const char *__filename) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int euidaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int eaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int execveat (int __fd, const char *__path, char *const __argv[],
                     char *const __envp[], int __flags)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __off64_t lseek (int __fd, __off64_t __offset, int __whence) __asm__ ("" "lseek64") __attribute__ ((__nothrow__ , __leaf__));
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));
extern ssize_t read (int __fd, void *__buf, size_t __nbytes)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t write (int __fd, const void *__buf, size_t __n)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes, __off64_t __offset) __asm__ ("" "pread64")
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t pwrite (int __fd, const void *__buf, size_t __nbytes, __off64_t __offset) __asm__ ("" "pwrite64")
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
   __off64_t __offset)
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern ssize_t pwrite64 (int __fd, const void *__buf, size_t __n,
    __off64_t __offset)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int pipe2 (int __pipedes[2], int __flags) __attribute__ ((__nothrow__ , __leaf__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *get_current_dir_name (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__))
    __attribute__ ((__access__ (__write_only__, 1)));
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern int dup3 (int __fd, int __fd2, int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern char **environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvpe (const char *__file, char *const __argv[],
      char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT,
    _SC_MINSIGSTKSZ,
    _SC_SIGSTKSZ
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 1)));
extern int group_member (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     __attribute__ ((__nothrow__ , __leaf__));
extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t _Fork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)))
     __attribute__ ((__access__ (__write_only__, 3, 4)));
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));



extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern int syncfs (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off64_t __length) __asm__ ("" "truncate64") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int truncate64 (const char *__file, __off64_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int ftruncate (int __fd, __off64_t __length) __asm__ ("" "ftruncate64") __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ftruncate64 (int __fd, __off64_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int lockf (int __fd, int __cmd, __off64_t __len) __asm__ ("" "lockf64") ;
extern int lockf64 (int __fd, int __cmd, __off64_t __len) ;
ssize_t copy_file_range (int __infd, __off64_t *__pinoff,
    int __outfd, __off64_t *__poutoff,
    size_t __length, unsigned int __flags);
extern int fdatasync (int __fildes);
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void swab (const void *__restrict __from, void *__restrict __to,
    ssize_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
    __attribute__ ((__access__ (__read_only__, 1, 3)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
int getentropy (void *__buffer, size_t __length)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int close_range (unsigned int __fd, unsigned int __max_fd,
   int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t gettid (void) __attribute__ ((__nothrow__ , __leaf__));


extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

typedef unsigned int wint_t;
typedef __mbstate_t mbstate_t;

struct tm;
extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t wcslcpy (wchar_t *__restrict __dest,
         const wchar_t *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));
extern size_t wcslcat (wchar_t *__restrict __dest,
         const wchar_t *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
extern wchar_t *wcscat (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int wcscmp (const wchar_t *__s1, const wchar_t *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int wcsncmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int wcscasecmp (const wchar_t *__s1, const wchar_t *__s2) __attribute__ ((__nothrow__ , __leaf__));
extern int wcsncasecmp (const wchar_t *__s1, const wchar_t *__s2,
   size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wcscasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
    locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern int wcsncasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
     size_t __n, locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern int wcscoll (const wchar_t *__s1, const wchar_t *__s2) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsxfrm (wchar_t *__restrict __s1,
         const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wcscoll_l (const wchar_t *__s1, const wchar_t *__s2,
        locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsxfrm_l (wchar_t *__s1, const wchar_t *__s2,
    size_t __n, locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcsdup (const wchar_t *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcschrnul (const wchar_t *__s, wchar_t __wc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern size_t wcscspn (const wchar_t *__wcs, const wchar_t *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern size_t wcsspn (const wchar_t *__wcs, const wchar_t *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcspbrk (const wchar_t *__wcs, const wchar_t *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcsstr (const wchar_t *__haystack, const wchar_t *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcstok (wchar_t *__restrict __s,
   const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcslen (const wchar_t *__s) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcswcs (const wchar_t *__haystack, const wchar_t *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern size_t wcsnlen (const wchar_t *__s, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wmemchr (const wchar_t *__s, wchar_t __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern int wmemcmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
     const wchar_t *__restrict __s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern wint_t btowc (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int wctob (wint_t __c) __attribute__ ((__nothrow__ , __leaf__));
extern int mbsinit (const mbstate_t *__ps) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern size_t mbrtowc (wchar_t *__restrict __pwc,
         const char *__restrict __s, size_t __n,
         mbstate_t *__restrict __p) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __mbrlen (const char *__restrict __s, size_t __n,
   mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbrlen (const char *__restrict __s, size_t __n,
        mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbsrtowcs (wchar_t *__restrict __dst,
    const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsrtombs (char *__restrict __dst,
    const wchar_t **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
     const char **__restrict __src, size_t __nmc,
     size_t __len, mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsnrtombs (char *__restrict __dst,
     const wchar_t **__restrict __src,
     size_t __nwc, size_t __len,
     mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern int wcwidth (wchar_t __c) __attribute__ ((__nothrow__ , __leaf__));
extern int wcswidth (const wchar_t *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern double wcstod (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern float wcstof (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern long double wcstold (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 wcstof32 (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 wcstof64 (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 wcstof128 (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x wcstof32x (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x wcstof64x (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern long int wcstol (const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned long int wcstoul (const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int wcstoll (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstoull (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int wcstoq (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstouq (const wchar_t *__restrict __nptr,
           wchar_t **__restrict __endptr,
           int __base) __attribute__ ((__nothrow__ , __leaf__));
extern long int wcstol (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstol") __attribute__ ((__nothrow__ , __leaf__));
extern unsigned long int wcstoul (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoul") __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int wcstoll (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoll") __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstoull (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoull") __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int wcstoq (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoll") __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstouq (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoull") __attribute__ ((__nothrow__ , __leaf__));
extern long int wcstol_l (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr, int __base,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned long int wcstoul_l (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr,
        int __base, locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int wcstoll_l (const wchar_t *__restrict __nptr,
    wchar_t **__restrict __endptr,
    int __base, locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstoull_l (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__));
extern long int wcstol_l (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_wcstol_l") __attribute__ ((__nothrow__ , __leaf__));
extern unsigned long int wcstoul_l (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_wcstoul_l") __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int wcstoll_l (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_wcstoll_l") __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstoull_l (const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, locale_t __loc) __asm__ ("" "__isoc23_wcstoull_l") __attribute__ ((__nothrow__ , __leaf__));
extern double wcstod_l (const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__));
extern float wcstof_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__));
extern long double wcstold_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 wcstof32_l (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 wcstof64_l (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 wcstof128_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x wcstof32x_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x wcstof64x_l (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcpcpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcpncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1)));
extern int fwide (__FILE *__fp, int __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fwprintf (__FILE *__restrict __stream,
       const wchar_t *__restrict __format, ...)
                                                           ;
extern int wprintf (const wchar_t *__restrict __format, ...)
                                                           ;
extern int swprintf (wchar_t *__restrict __s, size_t __n,
       const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int vfwprintf (__FILE *__restrict __s,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;
extern int vwprintf (const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;
extern int vswprintf (wchar_t *__restrict __s, size_t __n,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fwscanf (__FILE *__restrict __stream,
      const wchar_t *__restrict __format, ...)
                                                          ;
extern int wscanf (const wchar_t *__restrict __format, ...)
                                                          ;
extern int swscanf (const wchar_t *__restrict __s,
      const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fwscanf (__FILE *__restrict __stream, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc23_fwscanf")
                                                          ;
extern int wscanf (const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc23_wscanf")
                                                          ;
extern int swscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc23_swscanf") __attribute__ ((__nothrow__ , __leaf__))
                                                          ;
extern int vfwscanf (__FILE *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;
extern int vwscanf (const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;
extern int vswscanf (const wchar_t *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int vfwscanf (__FILE *__restrict __s, const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc23_vfwscanf")
                                                          ;
extern int vwscanf (const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc23_vwscanf")
                                                          ;
extern int vswscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc23_vswscanf") __attribute__ ((__nothrow__ , __leaf__))
                                                          ;
extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);
extern wint_t getwchar (void);
extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar (wchar_t __wc);
extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);
extern int fputws (const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);
extern wint_t ungetwc (wint_t __wc, __FILE *__stream);
extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);
extern wint_t fgetwc_unlocked (__FILE *__stream);
extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);
extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
     __FILE *__restrict __stream);
extern int fputws_unlocked (const wchar_t *__restrict __ws,
       __FILE *__restrict __stream);
extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
   const wchar_t *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize,
     const wchar_t *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef int __gwchar_t;

typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern intmax_t strtoimax (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoimax") __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t strtoumax (const char *__restrict __nptr, char **__restrict __endptr, int __base) __asm__ ("" "__isoc23_strtoumax") __attribute__ ((__nothrow__ , __leaf__));
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr, __gwchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoimax") __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr, __gwchar_t **__restrict __endptr, int __base) __asm__ ("" "__isoc23_wcstoumax") __attribute__ ((__nothrow__ , __leaf__));


extern long int __sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));

typedef uintptr_t Py_uintptr_t;
typedef intptr_t Py_intptr_t;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t Py_hash_t;
typedef size_t Py_uhash_t;
typedef Py_ssize_t Py_ssize_clean_t;

typedef float float_t;
typedef double double_t;
enum
  {
    FP_INT_UPWARD =
      0,
    FP_INT_DOWNWARD =
      1,
    FP_INT_TOWARDZERO =
      2,
    FP_INT_TONEARESTFROMZERO =
      3,
    FP_INT_TONEAREST =
      4,
  };
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincos (double __x, double *__sinx, double *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincos (double __x, double *__sinx, double *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern double exp10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double nextdown (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextdown (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextup (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextup (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
extern double roundeven (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __roundeven (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfp (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpx (double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalize (double *__cx, const double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern double fmaxmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaxmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminmag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum_mag (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmaximum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmaximum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fminimum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fminimum_mag_num (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorder (const double *__x, const double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermag (const double *__x, const double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern double getpayload (const double *__x) __attribute__ ((__nothrow__ , __leaf__)); extern double __getpayload (const double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayload (double *__x, double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsig (double *__x, double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf (float __x, float *__sinx, float *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf (float __x, float *__sinx, float *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern float exp10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));
 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float nextdownf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextdownf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextupf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextupf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
extern float roundevenf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundevenf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf (float __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef (float *__cx, const float *__x) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminmagf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimumf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimum_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimum_magf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmaximum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaximum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminimum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminimum_mag_numf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf (const float *__x, const float *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf (const float *__x, const float *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern float getpayloadf (const float *__x) __attribute__ ((__nothrow__ , __leaf__)); extern float __getpayloadf (const float *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf (float *__x, float __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf (float *__x, float __payload) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosl (long double __x, long double *__sinx, long double *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosl (long double __x, long double *__sinx, long double *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern long double exp10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextdownl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextdownl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextupl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextupl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundevenl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundevenl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxl (long double __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizel (long double *__cx, const long double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminmagl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimuml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimum_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimum_magl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmaximum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaximum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminimum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminimum_mag_numl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderl (const long double *__x, const long double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagl (const long double *__x, const long double *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern long double getpayloadl (const long double *__x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __getpayloadl (const long double *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadl (long double *__x, long double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigl (long double *__x, long double __payload) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 acosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __acosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 asinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __asinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 atanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __atanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 atan2f32 (_Float32 __y, _Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __atan2f32 (_Float32 __y, _Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 cosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __cosf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 sinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __sinf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 tanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __tanf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 coshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __coshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 sinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __sinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 tanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __tanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf32 (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf32 (_Float32 __x, _Float32 *__sinx, _Float32 *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 acoshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __acoshf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 asinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __asinhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 atanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __atanhf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 expf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __expf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 frexpf32 (_Float32 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __frexpf32 (_Float32 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 ldexpf32 (_Float32 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __ldexpf32 (_Float32 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 logf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __logf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 log10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __log10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 modff32 (_Float32 __x, _Float32 *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __modff32 (_Float32 __x, _Float32 *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float32 exp10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __exp10f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 expm1f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __expm1f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 log1pf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __log1pf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 logbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __logbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 exp2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __exp2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 log2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __log2f32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 powf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __powf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 sqrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __sqrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 hypotf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __hypotf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 cbrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __cbrtf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 ceilf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __ceilf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fabsf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fabsf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 floorf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __floorf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmodf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __fmodf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 copysignf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __copysignf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 nanf32 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nanf32 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 j0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __j0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 j1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __j1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 jnf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __jnf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 y0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __y0f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 y1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __y1f32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 ynf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __ynf32 (int, _Float32) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 erff32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __erff32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32 erfcf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __erfcf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 lgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __lgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 tgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __tgammaf32 (_Float32) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 lgammaf32_r (_Float32, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __lgammaf32_r (_Float32, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 rintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __rintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nextafterf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nextafterf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nextdownf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nextdownf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nextupf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nextupf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 remainderf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __remainderf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 scalbnf32 (_Float32 __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __scalbnf32 (_Float32 __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 scalblnf32 (_Float32 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __scalblnf32 (_Float32 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 nearbyintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __nearbyintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 roundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __roundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 truncf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __truncf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 remquof32 (_Float32 __x, _Float32 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __remquof32 (_Float32 __x, _Float32 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 fdimf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __fdimf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 fmaxf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaxf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaf32 (_Float32 __x, _Float32 __y, _Float32 __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __fmaf32 (_Float32 __x, _Float32 __y, _Float32 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 roundevenf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __roundevenf32 (_Float32 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf32 (_Float32 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef32 (_Float32 *__cx, const _Float32 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 fmaxmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaxmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminmagf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimumf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimum_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimum_magf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fmaximum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fmaximum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32 fminimum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32 __fminimum_mag_numf32 (_Float32 __x, _Float32 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf32 (const _Float32 *__x, const _Float32 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf32 (const _Float32 *__x, const _Float32 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float32 getpayloadf32 (const _Float32 *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32 __getpayloadf32 (const _Float32 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf32 (_Float32 *__x, _Float32 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf32 (_Float32 *__x, _Float32 __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 acosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __acosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 asinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __asinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 atanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __atanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 atan2f64 (_Float64 __y, _Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __atan2f64 (_Float64 __y, _Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 cosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __cosf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 sinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __sinf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 tanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __tanf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 coshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __coshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 sinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __sinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 tanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __tanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf64 (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf64 (_Float64 __x, _Float64 *__sinx, _Float64 *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 acoshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __acoshf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 asinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __asinhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 atanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __atanhf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 expf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __expf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 frexpf64 (_Float64 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __frexpf64 (_Float64 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 ldexpf64 (_Float64 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __ldexpf64 (_Float64 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 logf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __logf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 log10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __log10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 modff64 (_Float64 __x, _Float64 *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __modff64 (_Float64 __x, _Float64 *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float64 exp10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __exp10f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 expm1f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __expm1f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 log1pf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __log1pf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 logbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __logbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 exp2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __exp2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 log2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __log2f64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 powf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __powf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 sqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __sqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 hypotf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __hypotf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 cbrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __cbrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 ceilf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __ceilf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fabsf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fabsf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 floorf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __floorf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmodf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __fmodf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 copysignf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __copysignf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 nanf64 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nanf64 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 j0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __j0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 j1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __j1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 jnf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __jnf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 y0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __y0f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 y1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __y1f64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 ynf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __ynf64 (int, _Float64) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 erff64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __erff64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64 erfcf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __erfcf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 lgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __lgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 tgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __tgammaf64 (_Float64) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 lgammaf64_r (_Float64, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __lgammaf64_r (_Float64, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 rintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __rintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nextafterf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nextafterf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nextdownf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nextdownf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nextupf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nextupf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 remainderf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __remainderf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 scalbnf64 (_Float64 __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __scalbnf64 (_Float64 __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 scalblnf64 (_Float64 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __scalblnf64 (_Float64 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 nearbyintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __nearbyintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 roundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __roundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 truncf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __truncf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 remquof64 (_Float64 __x, _Float64 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __remquof64 (_Float64 __x, _Float64 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 fdimf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __fdimf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 fmaxf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaxf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 roundevenf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __roundevenf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf64 (_Float64 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef64 (_Float64 *__cx, const _Float64 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 fmaxmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaxmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminmagf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimumf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimum_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimum_magf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fmaximum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fmaximum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64 fminimum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64 __fminimum_mag_numf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf64 (const _Float64 *__x, const _Float64 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf64 (const _Float64 *__x, const _Float64 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float64 getpayloadf64 (const _Float64 *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64 __getpayloadf64 (const _Float64 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf64 (_Float64 *__x, _Float64 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf64 (_Float64 *__x, _Float64 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int __fpclassifyf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __isinff128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __finitef128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __isnanf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));
extern int __iseqsigf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __issignalingf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
 extern _Float128 acosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __acosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 asinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __asinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 atanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __atanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 atan2f128 (_Float128 __y, _Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __atan2f128 (_Float128 __y, _Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 cosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __cosf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 sinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __sinf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 tanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __tanf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 coshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __coshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 sinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __sinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 tanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __tanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf128 (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf128 (_Float128 __x, _Float128 *__sinx, _Float128 *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 acoshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __acoshf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 asinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __asinhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 atanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __atanhf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 expf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __expf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 frexpf128 (_Float128 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __frexpf128 (_Float128 __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 ldexpf128 (_Float128 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __ldexpf128 (_Float128 __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 logf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __logf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 log10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __log10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 modff128 (_Float128 __x, _Float128 *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __modff128 (_Float128 __x, _Float128 *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float128 exp10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __exp10f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 expm1f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __expm1f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 log1pf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __log1pf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 logbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __logbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 exp2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __exp2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 log2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __log2f128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 powf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __powf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 hypotf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __hypotf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 cbrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __cbrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 ceilf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __ceilf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fabsf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fabsf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 floorf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __floorf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmodf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __fmodf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 copysignf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __copysignf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 nanf128 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nanf128 (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 j0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __j0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 j1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __j1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 jnf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __jnf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 y0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __y0f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 y1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __y1f128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 ynf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __ynf128 (int, _Float128) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 erff128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __erff128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float128 erfcf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __erfcf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 lgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __lgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 tgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __tgammaf128 (_Float128) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 lgammaf128_r (_Float128, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __lgammaf128_r (_Float128, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 rintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __rintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nextafterf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nextafterf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nextdownf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nextdownf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nextupf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nextupf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 remainderf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __remainderf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 scalbnf128 (_Float128 __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __scalbnf128 (_Float128 __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 scalblnf128 (_Float128 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __scalblnf128 (_Float128 __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 nearbyintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __nearbyintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 roundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __roundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 truncf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __truncf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 remquof128 (_Float128 __x, _Float128 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __remquof128 (_Float128 __x, _Float128 __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 fdimf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __fdimf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 fmaxf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaxf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 roundevenf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __roundevenf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf128 (_Float128 __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef128 (_Float128 *__cx, const _Float128 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float128 fmaxmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaxmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminmagf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimumf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimum_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimum_magf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fmaximum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fmaximum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float128 fminimum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float128 __fminimum_mag_numf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf128 (const _Float128 *__x, const _Float128 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf128 (const _Float128 *__x, const _Float128 *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float128 getpayloadf128 (const _Float128 *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float128 __getpayloadf128 (const _Float128 *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf128 (_Float128 *__x, _Float128 __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf128 (_Float128 *__x, _Float128 __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x acosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __acosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x asinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __asinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x atanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __atanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x atan2f32x (_Float32x __y, _Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __atan2f32x (_Float32x __y, _Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x cosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __cosf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x sinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __sinf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x tanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __tanf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x coshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __coshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x sinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __sinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x tanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __tanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf32x (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf32x (_Float32x __x, _Float32x *__sinx, _Float32x *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x acoshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __acoshf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x asinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __asinhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x atanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __atanhf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x expf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __expf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x frexpf32x (_Float32x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __frexpf32x (_Float32x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x ldexpf32x (_Float32x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __ldexpf32x (_Float32x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x logf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __logf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x log10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __log10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x modff32x (_Float32x __x, _Float32x *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __modff32x (_Float32x __x, _Float32x *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float32x exp10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __exp10f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x expm1f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __expm1f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x log1pf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __log1pf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x logbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __logbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x exp2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __exp2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x log2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __log2f32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x powf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __powf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x sqrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __sqrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x hypotf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __hypotf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x cbrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __cbrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x ceilf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __ceilf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fabsf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fabsf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x floorf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __floorf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmodf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __fmodf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x copysignf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __copysignf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x nanf32x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nanf32x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x j0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __j0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x j1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __j1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x jnf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __jnf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x y0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __y0f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x y1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __y1f32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x ynf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __ynf32x (int, _Float32x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x erff32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __erff32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float32x erfcf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __erfcf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x lgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __lgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x tgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __tgammaf32x (_Float32x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x lgammaf32x_r (_Float32x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __lgammaf32x_r (_Float32x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x rintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __rintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nextafterf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nextafterf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nextdownf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nextdownf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nextupf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nextupf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x remainderf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __remainderf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x scalbnf32x (_Float32x __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __scalbnf32x (_Float32x __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x scalblnf32x (_Float32x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __scalblnf32x (_Float32x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x nearbyintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __nearbyintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x roundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __roundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x truncf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __truncf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x remquof32x (_Float32x __x, _Float32x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __remquof32x (_Float32x __x, _Float32x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x fdimf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __fdimf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x fmaxf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaxf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x roundevenf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __roundevenf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf32x (_Float32x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef32x (_Float32x *__cx, const _Float32x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x fmaxmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaxmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminmagf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimumf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimum_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimum_magf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fmaximum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fmaximum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float32x fminimum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float32x __fminimum_mag_numf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf32x (const _Float32x *__x, const _Float32x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf32x (const _Float32x *__x, const _Float32x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float32x getpayloadf32x (const _Float32x *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float32x __getpayloadf32x (const _Float32x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf32x (_Float32x *__x, _Float32x __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf32x (_Float32x *__x, _Float32x __payload) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x acosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __acosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x asinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __asinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x atanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __atanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x atan2f64x (_Float64x __y, _Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __atan2f64x (_Float64x __y, _Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x cosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __cosf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x sinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __sinf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x tanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __tanf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x coshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __coshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x sinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __sinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x tanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __tanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern void sincosf64x (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) __attribute__ ((__nothrow__ , __leaf__)); extern void __sincosf64x (_Float64x __x, _Float64x *__sinx, _Float64x *__cosx) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x acoshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __acoshf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x asinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __asinhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x atanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __atanhf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x expf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __expf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x frexpf64x (_Float64x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __frexpf64x (_Float64x __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x ldexpf64x (_Float64x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __ldexpf64x (_Float64x __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x logf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __logf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x log10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __log10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x modff64x (_Float64x __x, _Float64x *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __modff64x (_Float64x __x, _Float64x *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
 extern _Float64x exp10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __exp10f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x expm1f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __expm1f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x log1pf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __log1pf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x logbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __logbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x exp2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __exp2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x log2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __log2f64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x powf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __powf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x hypotf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __hypotf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x cbrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __cbrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x ceilf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __ceilf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fabsf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fabsf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x floorf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __floorf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmodf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __fmodf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x copysignf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __copysignf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x nanf64x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nanf64x (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x j0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __j0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x j1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __j1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x jnf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __jnf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x y0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __y0f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x y1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __y1f64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x ynf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __ynf64x (int, _Float64x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x erff64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __erff64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
 extern _Float64x erfcf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __erfcf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x lgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __lgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x tgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __tgammaf64x (_Float64x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x lgammaf64x_r (_Float64x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __lgammaf64x_r (_Float64x, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x rintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __rintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nextafterf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nextafterf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nextdownf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nextdownf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nextupf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nextupf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x remainderf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __remainderf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x scalbnf64x (_Float64x __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __scalbnf64x (_Float64x __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int llogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __llogbf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x scalblnf64x (_Float64x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __scalblnf64x (_Float64x __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x nearbyintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __nearbyintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x roundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __roundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x truncf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __truncf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x remquof64x (_Float64x __x, _Float64x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __remquof64x (_Float64x __x, _Float64x __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x fdimf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __fdimf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x fmaxf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaxf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x roundevenf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __roundevenf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __intmax_t fromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __intmax_t fromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __intmax_t __fromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern __uintmax_t ufromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__)); extern __uintmax_t __ufromfpxf64x (_Float64x __x, int __round, unsigned int __width) __attribute__ ((__nothrow__ , __leaf__));
extern int canonicalizef64x (_Float64x *__cx, const _Float64x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x fmaxmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaxmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminmagf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimumf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimum_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimum_magf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fmaximum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fmaximum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern _Float64x fminimum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern _Float64x __fminimum_mag_numf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int totalorderf64x (const _Float64x *__x, const _Float64x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern int totalordermagf64x (const _Float64x *__x, const _Float64x *__y) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__pure__));
extern _Float64x getpayloadf64x (const _Float64x *__x) __attribute__ ((__nothrow__ , __leaf__)); extern _Float64x __getpayloadf64x (const _Float64x *__x) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadf64x (_Float64x *__x, _Float64x __payload) __attribute__ ((__nothrow__ , __leaf__));
extern int setpayloadsigf64x (_Float64x *__x, _Float64x __payload) __attribute__ ((__nothrow__ , __leaf__));
extern float fadd (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fdiv (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float ffma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
extern float fmul (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fsqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fsub (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float faddl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fdivl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float ffmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern float fmull (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fsqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fsubl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double daddl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double ddivl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double dfmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
extern double dmull (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double dsqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double dsubl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf32x (_Float32x __x, _Float32x __y, _Float32x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf32x (_Float32x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf32x (_Float32x __x, _Float32x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32addf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32divf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32mulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32 f32subf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xaddf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xdivf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xfmaf64 (_Float64 __x, _Float64 __y, _Float64 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xmulf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsqrtf64 (_Float64 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsubf64 (_Float64 __x, _Float64 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xaddf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xdivf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xfmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xmulf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsubf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xaddf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xdivf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xfmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xmulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float32x f32xsubf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64addf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64divf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64fmaf64x (_Float64x __x, _Float64x __y, _Float64x __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64mulf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64sqrtf64x (_Float64x __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64subf64x (_Float64x __x, _Float64x __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64addf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64divf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64fmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64mulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64sqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64 f64subf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xaddf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xdivf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xfmaf128 (_Float128 __x, _Float128 __y, _Float128 __z) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xmulf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xsqrtf128 (_Float128 __x) __attribute__ ((__nothrow__ , __leaf__));
extern _Float64x f64xsubf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));
extern int signgam;
enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };
extern int __iscanonicall (long double __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
extern int gettimeofday (struct timeval *__restrict __tv,
    void *__restrict __tz) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (const struct timeval *__tv,
    const struct timezone *__tz)
     __attribute__ ((__nothrow__ , __leaf__));
extern int adjtime (const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__ , __leaf__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef enum __itimer_which __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int setitimer (__itimer_which_t __which,
        const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__ , __leaf__));
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int futimesat (int __fd, const char *__file,
        const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));

struct timex
{
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;
  int tai;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32;
};

extern int clock_adjtime (__clockid_t __clock_id, struct timex *__utx) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;

extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3, 4)));
extern char *strptime (const char *__restrict __s,
         const char *__restrict __fmt, struct tm *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern char *strptime_l (const char *__restrict __s,
    const char *__restrict __fmt, struct tm *__tp,
    locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int timespec_getres (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getdate_err;
extern struct tm *getdate (const char *__string);
extern int getdate_r (const char *__restrict __string,
        struct tm *__restrict __resbufp);


struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
  };
struct stat64
  {
    __dev_t st_dev;
    __ino64_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
  };
extern int stat (const char *__restrict __file, struct stat *__restrict __buf) __asm__ ("" "stat64") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __asm__ ("" "fstat64") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2)));
extern int stat64 (const char *__restrict __file,
     struct stat64 *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat64 (int __fd, struct stat64 *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int fstatat (int __fd, const char *__restrict __file, struct stat *__restrict __buf, int __flag) __asm__ ("" "fstatat64") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int fstatat64 (int __fd, const char *__restrict __file,
        struct stat64 *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int lstat (const char *__restrict __file, struct stat *__restrict __buf) __asm__ ("" "lstat64") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 2)));
extern int lstat64 (const char *__restrict __file,
      struct stat64 *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
extern __mode_t getumask (void) __attribute__ ((__nothrow__ , __leaf__));
extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
typedef __signed__ char __s8;
typedef unsigned char __u8;
typedef __signed__ short __s16;
typedef unsigned short __u16;
typedef __signed__ int __s32;
typedef unsigned int __u32;
__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;
typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned long __kernel_old_dev_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct {
 int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef __signed__ __int128 __s128 __attribute__((aligned(16)));
typedef unsigned __int128 __u128 __attribute__((aligned(16)));
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef __u16 __sum16;
typedef __u32 __wsum;
typedef unsigned __poll_t;
struct statx_timestamp {
 __s64 tv_sec;
 __u32 tv_nsec;
 __s32 __reserved;
};
struct statx {
 __u32 stx_mask;
 __u32 stx_blksize;
 __u64 stx_attributes;
 __u32 stx_nlink;
 __u32 stx_uid;
 __u32 stx_gid;
 __u16 stx_mode;
 __u16 __spare0[1];
 __u64 stx_ino;
 __u64 stx_size;
 __u64 stx_blocks;
 __u64 stx_attributes_mask;
 struct statx_timestamp stx_atime;
 struct statx_timestamp stx_btime;
 struct statx_timestamp stx_ctime;
 struct statx_timestamp stx_mtime;
 __u32 stx_rdev_major;
 __u32 stx_rdev_minor;
 __u32 stx_dev_major;
 __u32 stx_dev_minor;
 __u64 stx_mnt_id;
 __u32 stx_dio_mem_align;
 __u32 stx_dio_offset_align;
 __u64 stx_subvol;
 __u32 stx_atomic_write_unit_min;
 __u32 stx_atomic_write_unit_max;
 __u32 stx_atomic_write_segments_max;
 __u32 __spare1[1];
 __u64 __spare3[9];
};

int statx (int __dirfd, const char *__restrict __path, int __flags,
           unsigned int __mask, struct statx *__restrict __buf)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 5)));


__attribute__ ((visibility ("default"))) void * PyMem_Malloc(size_t size);
__attribute__ ((visibility ("default"))) void * PyMem_Calloc(size_t nelem, size_t elsize);
__attribute__ ((visibility ("default"))) void * PyMem_Realloc(void *ptr, size_t new_size);
__attribute__ ((visibility ("default"))) void PyMem_Free(void *ptr);
__attribute__ ((visibility ("default"))) void * PyMem_RawMalloc(size_t size);
__attribute__ ((visibility ("default"))) void * PyMem_RawCalloc(size_t nelem, size_t elsize);
__attribute__ ((visibility ("default"))) void * PyMem_RawRealloc(void *ptr, size_t new_size);
__attribute__ ((visibility ("default"))) void PyMem_RawFree(void *ptr);
__attribute__ ((visibility ("default"))) const char* _PyMem_GetCurrentAllocatorName(void);
__attribute__ ((visibility ("default"))) char * _PyMem_RawStrdup(const char *str);
__attribute__ ((visibility ("default"))) char * _PyMem_Strdup(const char *str);
__attribute__ ((visibility ("default"))) wchar_t* _PyMem_RawWcsdup(const wchar_t *str);
typedef enum {
    PYMEM_DOMAIN_RAW,
    PYMEM_DOMAIN_MEM,
    PYMEM_DOMAIN_OBJ
} PyMemAllocatorDomain;
typedef enum {
    PYMEM_ALLOCATOR_NOT_SET = 0,
    PYMEM_ALLOCATOR_DEFAULT = 1,
    PYMEM_ALLOCATOR_DEBUG = 2,
    PYMEM_ALLOCATOR_MALLOC = 3,
    PYMEM_ALLOCATOR_MALLOC_DEBUG = 4,
    PYMEM_ALLOCATOR_PYMALLOC = 5,
    PYMEM_ALLOCATOR_PYMALLOC_DEBUG = 6,
} PyMemAllocatorName;
typedef struct {
    void *ctx;
    void* (*malloc) (void *ctx, size_t size);
    void* (*calloc) (void *ctx, size_t nelem, size_t elsize);
    void* (*realloc) (void *ctx, void *ptr, size_t new_size);
    void (*free) (void *ctx, void *ptr);
} PyMemAllocatorEx;
__attribute__ ((visibility ("default"))) void PyMem_GetAllocator(PyMemAllocatorDomain domain,
                                    PyMemAllocatorEx *allocator);
__attribute__ ((visibility ("default"))) void PyMem_SetAllocator(PyMemAllocatorDomain domain,
                                    PyMemAllocatorEx *allocator);
__attribute__ ((visibility ("default"))) void PyMem_SetupDebugHooks(void);
typedef struct PyModuleDef PyModuleDef;
typedef struct PyModuleDef_Slot PyModuleDef_Slot;
typedef struct PyMethodDef PyMethodDef;
typedef struct PyGetSetDef PyGetSetDef;
typedef struct PyMemberDef PyMemberDef;
typedef struct _object PyObject;
typedef struct _longobject PyLongObject;
typedef struct _typeobject PyTypeObject;
typedef struct PyCodeObject PyCodeObject;
typedef struct _frame PyFrameObject;
typedef struct _ts PyThreadState;
typedef struct _is PyInterpreterState;
typedef struct {
    void *buf;
    PyObject *obj;
    Py_ssize_t len;
    Py_ssize_t itemsize;
    int readonly;
    int ndim;
    char *format;
    Py_ssize_t *shape;
    Py_ssize_t *strides;
    Py_ssize_t *suboffsets;
    void *internal;
} Py_buffer;
typedef int (*getbufferproc)(PyObject *, Py_buffer *, int);
typedef void (*releasebufferproc)(PyObject *, Py_buffer *);
__attribute__ ((visibility ("default"))) int PyObject_CheckBuffer(PyObject *obj);
__attribute__ ((visibility ("default"))) int PyObject_GetBuffer(PyObject *obj, Py_buffer *view,
                                   int flags);
__attribute__ ((visibility ("default"))) void * PyBuffer_GetPointer(const Py_buffer *view, const Py_ssize_t *indices);
__attribute__ ((visibility ("default"))) Py_ssize_t PyBuffer_SizeFromFormat(const char *format);
__attribute__ ((visibility ("default"))) int PyBuffer_ToContiguous(void *buf, const Py_buffer *view,
                                      Py_ssize_t len, char order);
__attribute__ ((visibility ("default"))) int PyBuffer_FromContiguous(const Py_buffer *view, const void *buf,
                                        Py_ssize_t len, char order);
__attribute__ ((visibility ("default"))) int PyObject_CopyData(PyObject *dest, PyObject *src);
__attribute__ ((visibility ("default"))) int PyBuffer_IsContiguous(const Py_buffer *view, char fort);
__attribute__ ((visibility ("default"))) void PyBuffer_FillContiguousStrides(int ndims,
                                               Py_ssize_t *shape,
                                               Py_ssize_t *strides,
                                               int itemsize,
                                               char fort);
__attribute__ ((visibility ("default"))) int PyBuffer_FillInfo(Py_buffer *view, PyObject *o, void *buf,
                                  Py_ssize_t len, int readonly,
                                  int flags);
__attribute__ ((visibility ("default"))) void PyBuffer_Release(Py_buffer *view);
struct _object {
   
    union {
       Py_ssize_t ob_refcnt;
       uint32_t ob_refcnt_split[2];
    };
    PyTypeObject *ob_type;
};
typedef struct {
    PyObject ob_base;
    Py_ssize_t ob_size;
} PyVarObject;
__attribute__ ((visibility ("default"))) int Py_Is(PyObject *x, PyObject *y);
static inline Py_ssize_t Py_REFCNT(PyObject *ob) {
    return ob->ob_refcnt;
}
static inline PyTypeObject* Py_TYPE(PyObject *ob) {
    return ob->ob_type;
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyLong_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyBool_Type;
static inline Py_ssize_t Py_SIZE(PyObject *ob) {
    ((void) sizeof ((ob->ob_type != &PyLong_Type) ? 1 : 0), __extension__ ({ if (ob->ob_type != &PyLong_Type) ; else __assert_fail ("ob->ob_type != &PyLong_Type", "/usr/include/python3.12/object.h", 231, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ob->ob_type != &PyBool_Type) ? 1 : 0), __extension__ ({ if (ob->ob_type != &PyBool_Type) ; else __assert_fail ("ob->ob_type != &PyBool_Type", "/usr/include/python3.12/object.h", 232, __extension__ __PRETTY_FUNCTION__); }));
    return ((PyVarObject*)((ob)))->ob_size;
}
static inline __attribute__((always_inline)) int _Py_IsImmortal(PyObject *op)
{
    return ((int32_t)(op->ob_refcnt)) < 0;
}
static inline int Py_IS_TYPE(PyObject *ob, PyTypeObject *type) {
    return Py_TYPE(((PyObject*)((ob)))) == type;
}
static inline void Py_SET_REFCNT(PyObject *ob, Py_ssize_t refcnt) {
    if (_Py_IsImmortal(((PyObject*)((ob))))) {
        return;
    }
    ob->ob_refcnt = refcnt;
}
static inline void Py_SET_TYPE(PyObject *ob, PyTypeObject *type) {
    ob->ob_type = type;
}
static inline void Py_SET_SIZE(PyVarObject *ob, Py_ssize_t size) {
    ((void) sizeof ((ob->ob_base.ob_type != &PyLong_Type) ? 1 : 0), __extension__ ({ if (ob->ob_base.ob_type != &PyLong_Type) ; else __assert_fail ("ob->ob_base.ob_type != &PyLong_Type", "/usr/include/python3.12/object.h", 280, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ob->ob_base.ob_type != &PyBool_Type) ? 1 : 0), __extension__ ({ if (ob->ob_base.ob_type != &PyBool_Type) ; else __assert_fail ("ob->ob_base.ob_type != &PyBool_Type", "/usr/include/python3.12/object.h", 281, __extension__ __PRETTY_FUNCTION__); }));
    ob->ob_size = size;
}
typedef PyObject * (*unaryfunc)(PyObject *);
typedef PyObject * (*binaryfunc)(PyObject *, PyObject *);
typedef PyObject * (*ternaryfunc)(PyObject *, PyObject *, PyObject *);
typedef int (*inquiry)(PyObject *);
typedef Py_ssize_t (*lenfunc)(PyObject *);
typedef PyObject *(*ssizeargfunc)(PyObject *, Py_ssize_t);
typedef PyObject *(*ssizessizeargfunc)(PyObject *, Py_ssize_t, Py_ssize_t);
typedef int(*ssizeobjargproc)(PyObject *, Py_ssize_t, PyObject *);
typedef int(*ssizessizeobjargproc)(PyObject *, Py_ssize_t, Py_ssize_t, PyObject *);
typedef int(*objobjargproc)(PyObject *, PyObject *, PyObject *);
typedef int (*objobjproc)(PyObject *, PyObject *);
typedef int (*visitproc)(PyObject *, void *);
typedef int (*traverseproc)(PyObject *, visitproc, void *);
typedef void (*freefunc)(void *);
typedef void (*destructor)(PyObject *);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef PyObject *(*getattrofunc)(PyObject *, PyObject *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef int (*setattrofunc)(PyObject *, PyObject *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef Py_hash_t (*hashfunc)(PyObject *);
typedef PyObject *(*richcmpfunc) (PyObject *, PyObject *, int);
typedef PyObject *(*getiterfunc) (PyObject *);
typedef PyObject *(*iternextfunc) (PyObject *);
typedef PyObject *(*descrgetfunc) (PyObject *, PyObject *, PyObject *);
typedef int (*descrsetfunc) (PyObject *, PyObject *, PyObject *);
typedef int (*initproc)(PyObject *, PyObject *, PyObject *);
typedef PyObject *(*newfunc)(PyTypeObject *, PyObject *, PyObject *);
typedef PyObject *(*allocfunc)(PyTypeObject *, Py_ssize_t);
typedef PyObject *(*vectorcallfunc)(PyObject *callable, PyObject *const *args,
                                    size_t nargsf, PyObject *kwnames);
typedef struct{
    int slot;
    void *pfunc;
} PyType_Slot;
typedef struct{
    const char* name;
    int basicsize;
    int itemsize;
    unsigned int flags;
    PyType_Slot *slots;
} PyType_Spec;
__attribute__ ((visibility ("default"))) PyObject* PyType_FromSpec(PyType_Spec*);
__attribute__ ((visibility ("default"))) PyObject* PyType_FromSpecWithBases(PyType_Spec*, PyObject*);
__attribute__ ((visibility ("default"))) void* PyType_GetSlot(PyTypeObject*, int);
__attribute__ ((visibility ("default"))) PyObject* PyType_FromModuleAndSpec(PyObject *, PyType_Spec *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyType_GetModule(PyTypeObject *);
__attribute__ ((visibility ("default"))) void * PyType_GetModuleState(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * PyType_GetName(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * PyType_GetQualName(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * PyType_FromMetaclass(PyTypeObject*, PyObject*, PyType_Spec*, PyObject*);
__attribute__ ((visibility ("default"))) void * PyObject_GetTypeData(PyObject *obj, PyTypeObject *cls);
__attribute__ ((visibility ("default"))) Py_ssize_t PyType_GetTypeDataSize(PyTypeObject *cls);
__attribute__ ((visibility ("default"))) int PyType_IsSubtype(PyTypeObject *, PyTypeObject *);
static inline int PyObject_TypeCheck(PyObject *ob, PyTypeObject *type) {
    return Py_IS_TYPE(((PyObject*)((ob))), (type)) || PyType_IsSubtype(Py_TYPE(((PyObject*)((ob)))), type);
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyType_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyBaseObject_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PySuper_Type;
__attribute__ ((visibility ("default"))) unsigned long PyType_GetFlags(PyTypeObject*);
__attribute__ ((visibility ("default"))) int PyType_Ready(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * PyType_GenericAlloc(PyTypeObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * PyType_GenericNew(PyTypeObject *,
                                               PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) unsigned int PyType_ClearCache(void);
__attribute__ ((visibility ("default"))) void PyType_Modified(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Repr(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Str(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_ASCII(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Bytes(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_RichCompare(PyObject *, PyObject *, int);
__attribute__ ((visibility ("default"))) int PyObject_RichCompareBool(PyObject *, PyObject *, int);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GetAttrString(PyObject *, const char *);
__attribute__ ((visibility ("default"))) int PyObject_SetAttrString(PyObject *, const char *, PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_HasAttrString(PyObject *, const char *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GetAttr(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_SetAttr(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_HasAttr(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_SelfIter(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GenericGetAttr(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_GenericSetAttr(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_GenericSetDict(PyObject *, PyObject *, void *);
__attribute__ ((visibility ("default"))) Py_hash_t PyObject_Hash(PyObject *);
__attribute__ ((visibility ("default"))) Py_hash_t PyObject_HashNotImplemented(PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_IsTrue(PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_Not(PyObject *);
__attribute__ ((visibility ("default"))) int PyCallable_Check(PyObject *);
__attribute__ ((visibility ("default"))) void PyObject_ClearWeakRefs(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Dir(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_GetState(PyObject *);
__attribute__ ((visibility ("default"))) int Py_ReprEnter(PyObject *);
__attribute__ ((visibility ("default"))) void Py_ReprLeave(PyObject *);
__attribute__ ((visibility ("default"))) void _Py_Dealloc(PyObject *);
__attribute__ ((visibility ("default"))) void Py_IncRef(PyObject *);
__attribute__ ((visibility ("default"))) void Py_DecRef(PyObject *);
__attribute__ ((visibility ("default"))) void _Py_IncRef(PyObject *);
__attribute__ ((visibility ("default"))) void _Py_DecRef(PyObject *);
static inline __attribute__((always_inline)) void Py_INCREF(PyObject *op)
{
    uint32_t cur_refcnt = op->ob_refcnt_split[0];
    uint32_t new_refcnt = cur_refcnt + 1;
    if (new_refcnt == 0) {
        return;
    }
    op->ob_refcnt_split[0] = new_refcnt;
    ((void)0);
}
static inline __attribute__((always_inline)) void Py_DECREF(PyObject *op)
{
    if (_Py_IsImmortal(((PyObject*)((op))))) {
        return;
    }
    ((void)0);
    if (--op->ob_refcnt == 0) {
        _Py_Dealloc(op);
    }
}
static inline void Py_XINCREF(PyObject *op)
{
    if (op != ((void *)0)) {
        Py_INCREF(((PyObject*)((op))));
    }
}
static inline void Py_XDECREF(PyObject *op)
{
    if (op != ((void *)0)) {
        Py_DECREF(((PyObject*)((op))));
    }
}
__attribute__ ((visibility ("default"))) PyObject* Py_NewRef(PyObject *obj);
__attribute__ ((visibility ("default"))) PyObject* Py_XNewRef(PyObject *obj);
static inline PyObject* _Py_NewRef(PyObject *obj)
{
    Py_INCREF(((PyObject*)((obj))));
    return obj;
}
static inline PyObject* _Py_XNewRef(PyObject *obj)
{
    Py_XINCREF(((PyObject*)((obj))));
    return obj;
}
extern __attribute__ ((visibility ("default"))) PyObject _Py_NoneStruct;
__attribute__ ((visibility ("default"))) int Py_IsNone(PyObject *x);
extern __attribute__ ((visibility ("default"))) PyObject _Py_NotImplementedStruct;
typedef enum {
    PYGEN_RETURN = 0,
    PYGEN_ERROR = -1,
    PYGEN_NEXT = 1,
} PySendResult;
__attribute__ ((visibility ("default"))) void _Py_NewReference(PyObject *op);
__attribute__ ((visibility ("default"))) void _Py_NewReferenceNoTotal(PyObject *op);
typedef struct _Py_Identifier {
    const char* string;
    Py_ssize_t index;
} _Py_Identifier;
typedef struct {
    binaryfunc nb_add;
    binaryfunc nb_subtract;
    binaryfunc nb_multiply;
    binaryfunc nb_remainder;
    binaryfunc nb_divmod;
    ternaryfunc nb_power;
    unaryfunc nb_negative;
    unaryfunc nb_positive;
    unaryfunc nb_absolute;
    inquiry nb_bool;
    unaryfunc nb_invert;
    binaryfunc nb_lshift;
    binaryfunc nb_rshift;
    binaryfunc nb_and;
    binaryfunc nb_xor;
    binaryfunc nb_or;
    unaryfunc nb_int;
    void *nb_reserved;
    unaryfunc nb_float;
    binaryfunc nb_inplace_add;
    binaryfunc nb_inplace_subtract;
    binaryfunc nb_inplace_multiply;
    binaryfunc nb_inplace_remainder;
    ternaryfunc nb_inplace_power;
    binaryfunc nb_inplace_lshift;
    binaryfunc nb_inplace_rshift;
    binaryfunc nb_inplace_and;
    binaryfunc nb_inplace_xor;
    binaryfunc nb_inplace_or;
    binaryfunc nb_floor_divide;
    binaryfunc nb_true_divide;
    binaryfunc nb_inplace_floor_divide;
    binaryfunc nb_inplace_true_divide;
    unaryfunc nb_index;
    binaryfunc nb_matrix_multiply;
    binaryfunc nb_inplace_matrix_multiply;
} PyNumberMethods;
typedef struct {
    lenfunc sq_length;
    binaryfunc sq_concat;
    ssizeargfunc sq_repeat;
    ssizeargfunc sq_item;
    void *was_sq_slice;
    ssizeobjargproc sq_ass_item;
    void *was_sq_ass_slice;
    objobjproc sq_contains;
    binaryfunc sq_inplace_concat;
    ssizeargfunc sq_inplace_repeat;
} PySequenceMethods;
typedef struct {
    lenfunc mp_length;
    binaryfunc mp_subscript;
    objobjargproc mp_ass_subscript;
} PyMappingMethods;
typedef PySendResult (*sendfunc)(PyObject *iter, PyObject *value, PyObject **result);
typedef struct {
    unaryfunc am_await;
    unaryfunc am_aiter;
    unaryfunc am_anext;
    sendfunc am_send;
} PyAsyncMethods;
typedef struct {
     getbufferproc bf_getbuffer;
     releasebufferproc bf_releasebuffer;
} PyBufferProcs;
typedef Py_ssize_t printfunc;
struct _typeobject {
    PyVarObject ob_base;
    const char *tp_name;
    Py_ssize_t tp_basicsize, tp_itemsize;
    destructor tp_dealloc;
    Py_ssize_t tp_vectorcall_offset;
    getattrfunc tp_getattr;
    setattrfunc tp_setattr;
    PyAsyncMethods *tp_as_async;
    reprfunc tp_repr;
    PyNumberMethods *tp_as_number;
    PySequenceMethods *tp_as_sequence;
    PyMappingMethods *tp_as_mapping;
    hashfunc tp_hash;
    ternaryfunc tp_call;
    reprfunc tp_str;
    getattrofunc tp_getattro;
    setattrofunc tp_setattro;
    PyBufferProcs *tp_as_buffer;
    unsigned long tp_flags;
    const char *tp_doc;
    traverseproc tp_traverse;
    inquiry tp_clear;
    richcmpfunc tp_richcompare;
    Py_ssize_t tp_weaklistoffset;
    getiterfunc tp_iter;
    iternextfunc tp_iternext;
    PyMethodDef *tp_methods;
    PyMemberDef *tp_members;
    PyGetSetDef *tp_getset;
    PyTypeObject *tp_base;
    PyObject *tp_dict;
    descrgetfunc tp_descr_get;
    descrsetfunc tp_descr_set;
    Py_ssize_t tp_dictoffset;
    initproc tp_init;
    allocfunc tp_alloc;
    newfunc tp_new;
    freefunc tp_free;
    inquiry tp_is_gc;
    PyObject *tp_bases;
    PyObject *tp_mro;
    PyObject *tp_cache;
    void *tp_subclasses;
    PyObject *tp_weaklist;
    destructor tp_del;
    unsigned int tp_version_tag;
    destructor tp_finalize;
    vectorcallfunc tp_vectorcall;
    unsigned char tp_watched;
};
struct _specialization_cache {
    PyObject *getitem;
    uint32_t getitem_version;
};
typedef struct _heaptypeobject {
    PyTypeObject ht_type;
    PyAsyncMethods as_async;
    PyNumberMethods as_number;
    PyMappingMethods as_mapping;
    PySequenceMethods as_sequence;
    PyBufferProcs as_buffer;
    PyObject *ht_name, *ht_slots, *ht_qualname;
    struct _dictkeysobject *ht_cached_keys;
    PyObject *ht_module;
    char *_ht_tpname;
    struct _specialization_cache _spec_cache;
} PyHeapTypeObject;
__attribute__ ((visibility ("default"))) const char * _PyType_Name(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyType_Lookup(PyTypeObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyType_LookupId(PyTypeObject *, _Py_Identifier *);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_LookupSpecialId(PyObject *, _Py_Identifier *);
__attribute__ ((visibility ("default"))) PyTypeObject * _PyType_CalculateMetaclass(PyTypeObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyType_GetDocFromInternalDoc(const char *, const char *);
__attribute__ ((visibility ("default"))) PyObject * _PyType_GetTextSignatureFromInternalDoc(const char *, const char *);
__attribute__ ((visibility ("default"))) PyObject * PyType_GetModuleByDef(PyTypeObject *, PyModuleDef *);
__attribute__ ((visibility ("default"))) PyObject * PyType_GetDict(PyTypeObject *);
__attribute__ ((visibility ("default"))) int PyObject_Print(PyObject *, FILE *, int);
__attribute__ ((visibility ("default"))) void _Py_BreakPoint(void);
__attribute__ ((visibility ("default"))) void _PyObject_Dump(PyObject *);
__attribute__ ((visibility ("default"))) int _PyObject_IsFreed(PyObject *);
__attribute__ ((visibility ("default"))) int _PyObject_IsAbstract(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_GetAttrId(PyObject *, _Py_Identifier *);
__attribute__ ((visibility ("default"))) int _PyObject_SetAttrId(PyObject *, _Py_Identifier *, PyObject *);
__attribute__ ((visibility ("default"))) int _PyObject_LookupAttr(PyObject *, PyObject *, PyObject **);
__attribute__ ((visibility ("default"))) int _PyObject_LookupAttrId(PyObject *, _Py_Identifier *, PyObject **);
__attribute__ ((visibility ("default"))) int _PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);
__attribute__ ((visibility ("default"))) PyObject ** _PyObject_GetDictPtr(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_NextNotImplemented(PyObject *);
__attribute__ ((visibility ("default"))) void PyObject_CallFinalizer(PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_CallFinalizerFromDealloc(PyObject *);
__attribute__ ((visibility ("default"))) PyObject *
_PyObject_GenericGetAttrWithDict(PyObject *, PyObject *, PyObject *, int);
__attribute__ ((visibility ("default"))) int
_PyObject_GenericSetAttrWithDict(PyObject *, PyObject *,
                                 PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_FunctionStr(PyObject *);
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyNone_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyNotImplemented_Type;
extern __attribute__ ((visibility ("default"))) int _Py_SwappedOp[];
__attribute__ ((visibility ("default"))) void
_PyDebugAllocatorStats(FILE *out, const char *block_name, int num_blocks,
                       size_t sizeof_block);
__attribute__ ((visibility ("default"))) void
_PyObject_DebugTypeStats(FILE *out);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) _PyObject_AssertFailed(
    PyObject *obj,
    const char *expr,
    const char *msg,
    const char *file,
    int line,
    const char *function);
__attribute__ ((visibility ("default"))) int _PyObject_CheckConsistency(
    PyObject *op,
    int check_content);
__attribute__ ((visibility ("default"))) int _PyTrash_begin(PyThreadState *tstate, PyObject *op);
__attribute__ ((visibility ("default"))) void _PyTrash_end(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) int _PyTrash_cond(PyObject *op, destructor dealloc);
__attribute__((__deprecated__)) typedef int UsingDeprecatedTrashcanMacro;
__attribute__ ((visibility ("default"))) void * PyObject_GetItemData(PyObject *obj);
__attribute__ ((visibility ("default"))) int _PyObject_VisitManagedDict(PyObject *obj, visitproc visit, void *arg);
__attribute__ ((visibility ("default"))) void _PyObject_ClearManagedDict(PyObject *obj);
typedef int(*PyType_WatchCallback)(PyTypeObject *);
__attribute__ ((visibility ("default"))) int PyType_AddWatcher(PyType_WatchCallback callback);
__attribute__ ((visibility ("default"))) int PyType_ClearWatcher(int watcher_id);
__attribute__ ((visibility ("default"))) int PyType_Watch(int watcher_id, PyObject *type);
__attribute__ ((visibility ("default"))) int PyType_Unwatch(int watcher_id, PyObject *type);
__attribute__ ((visibility ("default"))) int PyUnstable_Type_AssignVersionTag(PyTypeObject *type);
static inline int
PyType_HasFeature(PyTypeObject *type, unsigned long feature)
{
    unsigned long flags;
    flags = type->tp_flags;
    return ((flags & feature) != 0);
}
static inline int PyType_Check(PyObject *op) {
    return PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 31)));
}
static inline int PyType_CheckExact(PyObject *op) {
    return Py_IS_TYPE(((PyObject*)((op))), (&PyType_Type));
}
__attribute__ ((visibility ("default"))) void * PyObject_Malloc(size_t size);
__attribute__ ((visibility ("default"))) void * PyObject_Calloc(size_t nelem, size_t elsize);
__attribute__ ((visibility ("default"))) void * PyObject_Realloc(void *ptr, size_t new_size);
__attribute__ ((visibility ("default"))) void PyObject_Free(void *ptr);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Init(PyObject *, PyTypeObject *);
__attribute__ ((visibility ("default"))) PyVarObject * PyObject_InitVar(PyVarObject *,
                                           PyTypeObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_New(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyVarObject * _PyObject_NewVar(PyTypeObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) Py_ssize_t PyGC_Collect(void);
__attribute__ ((visibility ("default"))) int PyGC_Enable(void);
__attribute__ ((visibility ("default"))) int PyGC_Disable(void);
__attribute__ ((visibility ("default"))) int PyGC_IsEnabled(void);
typedef int (*gcvisitobjects_t)(PyObject*, void*);
__attribute__ ((visibility ("default"))) void PyUnstable_GC_VisitObjects(gcvisitobjects_t callback, void* arg);
__attribute__ ((visibility ("default"))) PyVarObject * _PyObject_GC_Resize(PyVarObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_GC_New(PyTypeObject *);
__attribute__ ((visibility ("default"))) PyVarObject * _PyObject_GC_NewVar(PyTypeObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) void PyObject_GC_Track(void *);
__attribute__ ((visibility ("default"))) void PyObject_GC_UnTrack(void *);
__attribute__ ((visibility ("default"))) void PyObject_GC_Del(void *);
__attribute__ ((visibility ("default"))) int PyObject_GC_IsTracked(PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_GC_IsFinalized(PyObject *);
static inline size_t _PyObject_SIZE(PyTypeObject *type) {
    return ((size_t)(type->tp_basicsize));
}
static inline size_t _PyObject_VAR_SIZE(PyTypeObject *type, Py_ssize_t nitems) {
    size_t size = ((size_t)(type->tp_basicsize));
    size += ((size_t)(nitems)) * ((size_t)(type->tp_itemsize));
    return (((size_t)(size) + (size_t)((8) - 1)) & ~(size_t)((8) - 1));
}
typedef struct {
    void *ctx;
    void* (*alloc) (void *ctx, size_t size);
    void (*free) (void *ctx, void *ptr, size_t size);
} PyObjectArenaAllocator;
__attribute__ ((visibility ("default"))) void PyObject_GetArenaAllocator(PyObjectArenaAllocator *allocator);
__attribute__ ((visibility ("default"))) void PyObject_SetArenaAllocator(PyObjectArenaAllocator *allocator);
__attribute__ ((visibility ("default"))) int PyObject_IS_GC(PyObject *obj);
__attribute__ ((visibility ("default"))) int PyType_SUPPORTS_WEAKREFS(PyTypeObject *type);
__attribute__ ((visibility ("default"))) PyObject ** PyObject_GET_WEAKREFS_LISTPTR(PyObject *op);
__attribute__ ((visibility ("default"))) PyObject * PyUnstable_Object_GC_NewWithExtraData(PyTypeObject *,
                                                             size_t);
__attribute__ ((visibility ("default"))) Py_hash_t _Py_HashDouble(PyObject *, double);
__attribute__ ((visibility ("default"))) Py_hash_t _Py_HashPointer(const void*);
__attribute__ ((visibility ("default"))) Py_hash_t _Py_HashPointerRaw(const void*);
__attribute__ ((visibility ("default"))) Py_hash_t _Py_HashBytes(const void*, Py_ssize_t);
typedef union {
    unsigned char uc[24];
    struct {
        Py_hash_t prefix;
        Py_hash_t suffix;
    } fnv;
    struct {
        uint64_t k0;
        uint64_t k1;
    } siphash;
    struct {
        unsigned char padding[16];
        Py_hash_t suffix;
    } djbx33a;
    struct {
        unsigned char padding[16];
        Py_hash_t hashsalt;
    } expat;
} _Py_HashSecret_t;
extern __attribute__ ((visibility ("default"))) _Py_HashSecret_t _Py_HashSecret;
typedef struct {
    Py_hash_t (*const hash)(const void *, Py_ssize_t);
    const char *name;
    const int hash_bits;
    const int seed_bits;
} PyHash_FuncDef;
__attribute__ ((visibility ("default"))) PyHash_FuncDef* PyHash_GetFuncDef(void);
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_DebugFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_VerboseFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_QuietFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_InteractiveFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_InspectFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_OptimizeFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_NoSiteFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_BytesWarningFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_FrozenFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_IgnoreEnvironmentFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_DontWriteBytecodeFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_NoUserSiteDirectory;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_UnbufferedStdioFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_HashRandomizationFlag;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_IsolatedFlag;
__attribute__ ((visibility ("default"))) char* Py_GETENV(const char *name);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyByteArray_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyByteArrayIter_Type;
__attribute__ ((visibility ("default"))) PyObject * PyByteArray_FromObject(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyByteArray_Concat(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyByteArray_FromStringAndSize(const char *, Py_ssize_t);
__attribute__ ((visibility ("default"))) Py_ssize_t PyByteArray_Size(PyObject *);
__attribute__ ((visibility ("default"))) char * PyByteArray_AsString(PyObject *);
__attribute__ ((visibility ("default"))) int PyByteArray_Resize(PyObject *, Py_ssize_t);
typedef struct {
    PyVarObject ob_base;
    Py_ssize_t ob_alloc;
    char *ob_bytes;
    char *ob_start;
    Py_ssize_t ob_exports;
} PyByteArrayObject;
extern __attribute__ ((visibility ("default"))) char _PyByteArray_empty_string[];
static inline char* PyByteArray_AS_STRING(PyObject *op)
{
    PyByteArrayObject *self = (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((op)))), (&PyByteArray_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((op)))), (&PyByteArray_Type))) ; else __assert_fail ("PyByteArray_Check(op)", "/usr/include/python3.12/cpython/bytearrayobject.h", 22, __extension__ __PRETTY_FUNCTION__); })), ((PyByteArrayObject*)(op)));
    if (Py_SIZE(((PyObject*)((self))))) {
        return self->ob_start;
    }
    return _PyByteArray_empty_string;
}
static inline Py_ssize_t PyByteArray_GET_SIZE(PyObject *op) {
    PyByteArrayObject *self = (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((op)))), (&PyByteArray_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((op)))), (&PyByteArray_Type))) ; else __assert_fail ("PyByteArray_Check(op)", "/usr/include/python3.12/cpython/bytearrayobject.h", 31, __extension__ __PRETTY_FUNCTION__); })), ((PyByteArrayObject*)(op)));
    return Py_SIZE(((PyObject*)((self))));
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyBytes_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyBytesIter_Type;
__attribute__ ((visibility ("default"))) PyObject * PyBytes_FromStringAndSize(const char *, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * PyBytes_FromString(const char *);
__attribute__ ((visibility ("default"))) PyObject * PyBytes_FromObject(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyBytes_FromFormatV(const char*, va_list)
                                __attribute__((format(printf, 1, 0)));
__attribute__ ((visibility ("default"))) PyObject * PyBytes_FromFormat(const char*, ...)
                                __attribute__((format(printf, 1, 2)));
__attribute__ ((visibility ("default"))) Py_ssize_t PyBytes_Size(PyObject *);
__attribute__ ((visibility ("default"))) char * PyBytes_AsString(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyBytes_Repr(PyObject *, int);
__attribute__ ((visibility ("default"))) void PyBytes_Concat(PyObject **, PyObject *);
__attribute__ ((visibility ("default"))) void PyBytes_ConcatAndDel(PyObject **, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyBytes_DecodeEscape(const char *, Py_ssize_t,
                                            const char *, Py_ssize_t,
                                            const char *);
__attribute__ ((visibility ("default"))) int PyBytes_AsStringAndSize(
    PyObject *obj,
    char **s,
    Py_ssize_t *len
    );
typedef struct {
    PyVarObject ob_base;
    __attribute__((__deprecated__)) Py_hash_t ob_shash;
    char ob_sval[1];
} PyBytesObject;
__attribute__ ((visibility ("default"))) int _PyBytes_Resize(PyObject **, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject* _PyBytes_FormatEx(
    const char *format,
    Py_ssize_t format_len,
    PyObject *args,
    int use_bytearray);
__attribute__ ((visibility ("default"))) PyObject* _PyBytes_FromHex(
    PyObject *string,
    int use_bytearray);
__attribute__ ((visibility ("default"))) PyObject* _PyBytes_DecodeEscape2(const char *, Py_ssize_t,
                                             const char *,
                                             int *, const char **);
__attribute__ ((visibility ("default"))) PyObject * _PyBytes_DecodeEscape(const char *, Py_ssize_t,
                                             const char *, const char **);
static inline char* PyBytes_AS_STRING(PyObject *op)
{
    return (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 27)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 27)))) ; else __assert_fail ("PyBytes_Check(op)", "/usr/include/python3.12/cpython/bytesobject.h", 41, __extension__ __PRETTY_FUNCTION__); })), ((PyBytesObject*)(op)))->ob_sval;
}
static inline Py_ssize_t PyBytes_GET_SIZE(PyObject *op) {
    PyBytesObject *self = (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 27)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 27)))) ; else __assert_fail ("PyBytes_Check(op)", "/usr/include/python3.12/cpython/bytesobject.h", 46, __extension__ __PRETTY_FUNCTION__); })), ((PyBytesObject*)(op)));
    return Py_SIZE(((PyObject*)((self))));
}
__attribute__ ((visibility ("default"))) PyObject * _PyBytes_Join(PyObject *sep, PyObject *x);
typedef struct {
    PyObject *buffer;
    Py_ssize_t allocated;
    Py_ssize_t min_size;
    int use_bytearray;
    int overallocate;
    int use_small_buffer;
    char small_buffer[512];
} _PyBytesWriter;
__attribute__ ((visibility ("default"))) void _PyBytesWriter_Init(_PyBytesWriter *writer);
__attribute__ ((visibility ("default"))) PyObject * _PyBytesWriter_Finish(_PyBytesWriter *writer,
    void *str);
__attribute__ ((visibility ("default"))) void _PyBytesWriter_Dealloc(_PyBytesWriter *writer);
__attribute__ ((visibility ("default"))) void* _PyBytesWriter_Alloc(_PyBytesWriter *writer,
    Py_ssize_t size);
__attribute__ ((visibility ("default"))) void* _PyBytesWriter_Prepare(_PyBytesWriter *writer,
    void *str,
    Py_ssize_t size);
__attribute__ ((visibility ("default"))) void* _PyBytesWriter_Resize(_PyBytesWriter *writer,
    void *str,
    Py_ssize_t size);
__attribute__ ((visibility ("default"))) void* _PyBytesWriter_WriteBytes(_PyBytesWriter *writer,
    void *str,
    const void *bytes,
    Py_ssize_t size);

enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isctype (int __c, int __mask) __attribute__ ((__nothrow__ , __leaf__));
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalnum_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isblank_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int __tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int __toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

typedef uint32_t Py_UCS4;
typedef uint16_t Py_UCS2;
typedef uint8_t Py_UCS1;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyUnicode_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyUnicodeIter_Type;
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromStringAndSize(
    const char *u,
    Py_ssize_t size
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromString(
    const char *u
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Substring(
    PyObject *str,
    Py_ssize_t start,
    Py_ssize_t end);
__attribute__ ((visibility ("default"))) Py_UCS4* PyUnicode_AsUCS4(
    PyObject *unicode,
    Py_UCS4* buffer,
    Py_ssize_t buflen,
    int copy_null);
__attribute__ ((visibility ("default"))) Py_UCS4* PyUnicode_AsUCS4Copy(PyObject *unicode);
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_GetLength(
    PyObject *unicode
);
__attribute__ ((visibility ("default"))) Py_UCS4 PyUnicode_ReadChar(
    PyObject *unicode,
    Py_ssize_t index
    );
__attribute__ ((visibility ("default"))) int PyUnicode_WriteChar(
    PyObject *unicode,
    Py_ssize_t index,
    Py_UCS4 character
    );
__attribute__ ((visibility ("default"))) int PyUnicode_Resize(
    PyObject **unicode,
    Py_ssize_t length
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromEncodedObject(
    PyObject *obj,
    const char *encoding,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromObject(
    PyObject *obj
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_FromFormatV(
    const char *format,
    va_list vargs
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_FromFormat(
    const char *format,
    ...
    );
__attribute__ ((visibility ("default"))) void PyUnicode_InternInPlace(PyObject **);
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_InternFromString(
    const char *u
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromWideChar(
    const wchar_t *w,
    Py_ssize_t size
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_AsWideChar(
    PyObject *unicode,
    wchar_t *w,
    Py_ssize_t size
    );
__attribute__ ((visibility ("default"))) wchar_t* PyUnicode_AsWideCharString(
    PyObject *unicode,
    Py_ssize_t *size
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromOrdinal(int ordinal);
__attribute__ ((visibility ("default"))) const char* PyUnicode_GetDefaultEncoding(void);
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Decode(
    const char *s,
    Py_ssize_t size,
    const char *encoding,
    const char *errors
    );
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsDecodedObject(
    PyObject *unicode,
    const char *encoding,
    const char *errors
    );
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsDecodedUnicode(
    PyObject *unicode,
    const char *encoding,
    const char *errors
    );
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsEncodedObject(
    PyObject *unicode,
    const char *encoding,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsEncodedString(
    PyObject *unicode,
    const char *encoding,
    const char *errors
    );
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsEncodedUnicode(
    PyObject *unicode,
    const char *encoding,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_BuildEncodingMap(
    PyObject* string
   );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF7(
    const char *string,
    Py_ssize_t length,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF7Stateful(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    Py_ssize_t *consumed
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF8(
    const char *string,
    Py_ssize_t length,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF8Stateful(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    Py_ssize_t *consumed
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsUTF8String(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) const char * PyUnicode_AsUTF8AndSize(
    PyObject *unicode,
    Py_ssize_t *size);
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF32(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    int *byteorder
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF32Stateful(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    int *byteorder,
    Py_ssize_t *consumed
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsUTF32String(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF16(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    int *byteorder
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUTF16Stateful(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    int *byteorder,
    Py_ssize_t *consumed
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsUTF16String(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeUnicodeEscape(
    const char *string,
    Py_ssize_t length,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsUnicodeEscapeString(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeRawUnicodeEscape(
    const char *string,
    Py_ssize_t length,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsRawUnicodeEscapeString(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeLatin1(
    const char *string,
    Py_ssize_t length,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsLatin1String(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeASCII(
    const char *string,
    Py_ssize_t length,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsASCIIString(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeCharmap(
    const char *string,
    Py_ssize_t length,
    PyObject *mapping,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_AsCharmapString(
    PyObject *unicode,
    PyObject *mapping
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeLocaleAndSize(
    const char *str,
    Py_ssize_t len,
    const char *errors);
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeLocale(
    const char *str,
    const char *errors);
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_EncodeLocale(
    PyObject *unicode,
    const char *errors
    );
__attribute__ ((visibility ("default"))) int PyUnicode_FSConverter(PyObject*, void*);
__attribute__ ((visibility ("default"))) int PyUnicode_FSDecoder(PyObject*, void*);
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeFSDefault(
    const char *s
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_DecodeFSDefaultAndSize(
    const char *s,
    Py_ssize_t size
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_EncodeFSDefault(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Concat(
    PyObject *left,
    PyObject *right
    );
__attribute__ ((visibility ("default"))) void PyUnicode_Append(
    PyObject **pleft,
    PyObject *right
    );
__attribute__ ((visibility ("default"))) void PyUnicode_AppendAndDel(
    PyObject **pleft,
    PyObject *right
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Split(
    PyObject *s,
    PyObject *sep,
    Py_ssize_t maxsplit
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Splitlines(
    PyObject *s,
    int keepends
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Partition(
    PyObject *s,
    PyObject *sep
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_RPartition(
    PyObject *s,
    PyObject *sep
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_RSplit(
    PyObject *s,
    PyObject *sep,
    Py_ssize_t maxsplit
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_Translate(
    PyObject *str,
    PyObject *table,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_Join(
    PyObject *separator,
    PyObject *seq
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_Tailmatch(
    PyObject *str,
    PyObject *substr,
    Py_ssize_t start,
    Py_ssize_t end,
    int direction
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_Find(
    PyObject *str,
    PyObject *substr,
    Py_ssize_t start,
    Py_ssize_t end,
    int direction
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_FindChar(
    PyObject *str,
    Py_UCS4 ch,
    Py_ssize_t start,
    Py_ssize_t end,
    int direction
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_Count(
    PyObject *str,
    PyObject *substr,
    Py_ssize_t start,
    Py_ssize_t end
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_Replace(
    PyObject *str,
    PyObject *substr,
    PyObject *replstr,
    Py_ssize_t maxcount
    );
__attribute__ ((visibility ("default"))) int PyUnicode_Compare(
    PyObject *left,
    PyObject *right
    );
__attribute__ ((visibility ("default"))) int PyUnicode_CompareWithASCIIString(
    PyObject *left,
    const char *right
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_RichCompare(
    PyObject *left,
    PyObject *right,
    int op
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicode_Format(
    PyObject *format,
    PyObject *args
    );
__attribute__ ((visibility ("default"))) int PyUnicode_Contains(
    PyObject *container,
    PyObject *element
    );
__attribute__ ((visibility ("default"))) int PyUnicode_IsIdentifier(PyObject *s);
                         typedef wchar_t Py_UNICODE;
static inline int Py_UNICODE_IS_SURROGATE(Py_UCS4 ch) {
    return (0xD800 <= ch && ch <= 0xDFFF);
}
static inline int Py_UNICODE_IS_HIGH_SURROGATE(Py_UCS4 ch) {
    return (0xD800 <= ch && ch <= 0xDBFF);
}
static inline int Py_UNICODE_IS_LOW_SURROGATE(Py_UCS4 ch) {
    return (0xDC00 <= ch && ch <= 0xDFFF);
}
static inline Py_UCS4 Py_UNICODE_JOIN_SURROGATES(Py_UCS4 high, Py_UCS4 low) {
    ((void) sizeof ((Py_UNICODE_IS_HIGH_SURROGATE(high)) ? 1 : 0), __extension__ ({ if (Py_UNICODE_IS_HIGH_SURROGATE(high)) ; else __assert_fail ("Py_UNICODE_IS_HIGH_SURROGATE(high)", "/usr/include/python3.12/cpython/unicodeobject.h", 27, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_UNICODE_IS_LOW_SURROGATE(low)) ? 1 : 0), __extension__ ({ if (Py_UNICODE_IS_LOW_SURROGATE(low)) ; else __assert_fail ("Py_UNICODE_IS_LOW_SURROGATE(low)", "/usr/include/python3.12/cpython/unicodeobject.h", 28, __extension__ __PRETTY_FUNCTION__); }));
    return 0x10000 + (((high & 0x03FF) << 10) | (low & 0x03FF));
}
static inline Py_UCS4 Py_UNICODE_HIGH_SURROGATE(Py_UCS4 ch) {
    ((void) sizeof ((0x10000 <= ch && ch <= 0x10ffff) ? 1 : 0), __extension__ ({ if (0x10000 <= ch && ch <= 0x10ffff) ; else __assert_fail ("0x10000 <= ch && ch <= 0x10ffff", "/usr/include/python3.12/cpython/unicodeobject.h", 35, __extension__ __PRETTY_FUNCTION__); }));
    return (0xD800 - (0x10000 >> 10) + (ch >> 10));
}
static inline Py_UCS4 Py_UNICODE_LOW_SURROGATE(Py_UCS4 ch) {
    ((void) sizeof ((0x10000 <= ch && ch <= 0x10ffff) ? 1 : 0), __extension__ ({ if (0x10000 <= ch && ch <= 0x10ffff) ; else __assert_fail ("0x10000 <= ch && ch <= 0x10ffff", "/usr/include/python3.12/cpython/unicodeobject.h", 42, __extension__ __PRETTY_FUNCTION__); }));
    return (0xDC00 + (ch & 0x3FF));
}
typedef struct {
    PyObject ob_base;
    Py_ssize_t length;
    Py_hash_t hash;
    struct {
        unsigned int interned:2;
        unsigned int kind:3;
        unsigned int compact:1;
        unsigned int ascii:1;
        unsigned int statically_allocated:1;
        unsigned int :24;
    } state;
} PyASCIIObject;
typedef struct {
    PyASCIIObject _base;
    Py_ssize_t utf8_length;
    char *utf8;
} PyCompactUnicodeObject;
typedef struct {
    PyCompactUnicodeObject _base;
    union {
        void *any;
        Py_UCS1 *latin1;
        Py_UCS2 *ucs2;
        Py_UCS4 *ucs4;
    } data;
} PyUnicodeObject;
__attribute__ ((visibility ("default"))) int _PyUnicode_CheckConsistency(
    PyObject *op,
    int check_content);
static inline unsigned int PyUnicode_CHECK_INTERNED(PyObject *op) {
    return (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 200, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op))))->state.interned;
}
static inline unsigned int PyUnicode_IS_READY(PyObject* _unused_op __attribute__((unused))) {
    return 1;
}
static inline unsigned int PyUnicode_IS_ASCII(PyObject *op) {
    return (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 214, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op))))->state.ascii;
}
static inline unsigned int PyUnicode_IS_COMPACT(PyObject *op) {
    return (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 221, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op))))->state.compact;
}
static inline int PyUnicode_IS_COMPACT_ASCII(PyObject *op) {
    return ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 228, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op))))->state.ascii && PyUnicode_IS_COMPACT(((PyObject*)((op)))));
}
enum PyUnicode_Kind {
    PyUnicode_1BYTE_KIND = 1,
    PyUnicode_2BYTE_KIND = 2,
    PyUnicode_4BYTE_KIND = 4
};
static inline void* _PyUnicode_COMPACT_DATA(PyObject *op) {
    if (PyUnicode_IS_ASCII(((PyObject*)((op))))) {
        return ((void*)(((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 250, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op)))) + 1)));
    }
    return ((void*)(((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 252, __extension__ __PRETTY_FUNCTION__); })), ((PyCompactUnicodeObject*)((op)))) + 1)));
}
static inline void* _PyUnicode_NONCOMPACT_DATA(PyObject *op) {
    void *data;
    ((void) sizeof ((!PyUnicode_IS_COMPACT(((PyObject*)((op))))) ? 1 : 0), __extension__ ({ if (!PyUnicode_IS_COMPACT(((PyObject*)((op))))) ; else __assert_fail ("!PyUnicode_IS_COMPACT(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 257, __extension__ __PRETTY_FUNCTION__); }));
    data = (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 258, __extension__ __PRETTY_FUNCTION__); })), ((PyUnicodeObject*)((op))))->data.any;
    ((void) sizeof ((data != ((void *)0)) ? 1 : 0), __extension__ ({ if (data != ((void *)0)) ; else __assert_fail ("data != NULL", "/usr/include/python3.12/cpython/unicodeobject.h", 259, __extension__ __PRETTY_FUNCTION__); }));
    return data;
}
static inline void* PyUnicode_DATA(PyObject *op) {
    if (PyUnicode_IS_COMPACT(((PyObject*)((op))))) {
        return _PyUnicode_COMPACT_DATA(op);
    }
    return _PyUnicode_NONCOMPACT_DATA(op);
}
static inline Py_ssize_t PyUnicode_GET_LENGTH(PyObject *op) {
    return (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 282, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op))))->length;
}
static inline void PyUnicode_WRITE(int kind, void *data,
                                   Py_ssize_t index, Py_UCS4 value)
{
    ((void) sizeof ((index >= 0) ? 1 : 0), __extension__ ({ if (index >= 0) ; else __assert_fail ("index >= 0", "/usr/include/python3.12/cpython/unicodeobject.h", 294, __extension__ __PRETTY_FUNCTION__); }));
    if (kind == PyUnicode_1BYTE_KIND) {
        ((void) sizeof ((value <= 0xffU) ? 1 : 0), __extension__ ({ if (value <= 0xffU) ; else __assert_fail ("value <= 0xffU", "/usr/include/python3.12/cpython/unicodeobject.h", 296, __extension__ __PRETTY_FUNCTION__); }));
        ((Py_UCS1*)(data))[index] = ((Py_UCS1)(value));
    }
    else if (kind == PyUnicode_2BYTE_KIND) {
        ((void) sizeof ((value <= 0xffffU) ? 1 : 0), __extension__ ({ if (value <= 0xffffU) ; else __assert_fail ("value <= 0xffffU", "/usr/include/python3.12/cpython/unicodeobject.h", 300, __extension__ __PRETTY_FUNCTION__); }));
        ((Py_UCS2*)(data))[index] = ((Py_UCS2)(value));
    }
    else {
        ((void) sizeof ((kind == PyUnicode_4BYTE_KIND) ? 1 : 0), __extension__ ({ if (kind == PyUnicode_4BYTE_KIND) ; else __assert_fail ("kind == PyUnicode_4BYTE_KIND", "/usr/include/python3.12/cpython/unicodeobject.h", 304, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((value <= 0x10ffffU) ? 1 : 0), __extension__ ({ if (value <= 0x10ffffU) ; else __assert_fail ("value <= 0x10ffffU", "/usr/include/python3.12/cpython/unicodeobject.h", 305, __extension__ __PRETTY_FUNCTION__); }));
        ((Py_UCS4*)(data))[index] = value;
    }
}
static inline Py_UCS4 PyUnicode_READ(int kind,
                                     const void *data, Py_ssize_t index)
{
    ((void) sizeof ((index >= 0) ? 1 : 0), __extension__ ({ if (index >= 0) ; else __assert_fail ("index >= 0", "/usr/include/python3.12/cpython/unicodeobject.h", 318, __extension__ __PRETTY_FUNCTION__); }));
    if (kind == PyUnicode_1BYTE_KIND) {
        return ((const Py_UCS1*)(data))[index];
    }
    if (kind == PyUnicode_2BYTE_KIND) {
        return ((const Py_UCS2*)(data))[index];
    }
    ((void) sizeof ((kind == PyUnicode_4BYTE_KIND) ? 1 : 0), __extension__ ({ if (kind == PyUnicode_4BYTE_KIND) ; else __assert_fail ("kind == PyUnicode_4BYTE_KIND", "/usr/include/python3.12/cpython/unicodeobject.h", 325, __extension__ __PRETTY_FUNCTION__); }));
    return ((const Py_UCS4*)(data))[index];
}
static inline Py_UCS4 PyUnicode_READ_CHAR(PyObject *unicode, Py_ssize_t index)
{
    int kind;
    ((void) sizeof ((index >= 0) ? 1 : 0), __extension__ ({ if (index >= 0) ; else __assert_fail ("index >= 0", "/usr/include/python3.12/cpython/unicodeobject.h", 341, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((index <= PyUnicode_GET_LENGTH(((PyObject*)((unicode))))) ? 1 : 0), __extension__ ({ if (index <= PyUnicode_GET_LENGTH(((PyObject*)((unicode))))) ; else __assert_fail ("index <= PyUnicode_GET_LENGTH(unicode)", "/usr/include/python3.12/cpython/unicodeobject.h", 343, __extension__ __PRETTY_FUNCTION__); }));
    kind = ((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((unicode))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((unicode))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(unicode)", "/usr/include/python3.12/cpython/unicodeobject.h", 345, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((unicode))))->state.kind));
    if (kind == PyUnicode_1BYTE_KIND) {
        return ((Py_UCS1*)(PyUnicode_DATA(((PyObject*)((unicode))))))[index];
    }
    if (kind == PyUnicode_2BYTE_KIND) {
        return ((Py_UCS2*)(PyUnicode_DATA(((PyObject*)((unicode))))))[index];
    }
    ((void) sizeof ((kind == PyUnicode_4BYTE_KIND) ? 1 : 0), __extension__ ({ if (kind == PyUnicode_4BYTE_KIND) ; else __assert_fail ("kind == PyUnicode_4BYTE_KIND", "/usr/include/python3.12/cpython/unicodeobject.h", 352, __extension__ __PRETTY_FUNCTION__); }));
    return ((Py_UCS4*)(PyUnicode_DATA(((PyObject*)((unicode))))))[index];
}
static inline Py_UCS4 PyUnicode_MAX_CHAR_VALUE(PyObject *op)
{
    int kind;
    if (PyUnicode_IS_ASCII(((PyObject*)((op))))) {
        return 0x7fU;
    }
    kind = ((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(op)", "/usr/include/python3.12/cpython/unicodeobject.h", 369, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((op))))->state.kind));
    if (kind == PyUnicode_1BYTE_KIND) {
       return 0xffU;
    }
    if (kind == PyUnicode_2BYTE_KIND) {
        return 0xffffU;
    }
    ((void) sizeof ((kind == PyUnicode_4BYTE_KIND) ? 1 : 0), __extension__ ({ if (kind == PyUnicode_4BYTE_KIND) ; else __assert_fail ("kind == PyUnicode_4BYTE_KIND", "/usr/include/python3.12/cpython/unicodeobject.h", 376, __extension__ __PRETTY_FUNCTION__); }));
    return 0x10ffffU;
}
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_New(
    Py_ssize_t size,
    Py_UCS4 maxchar
    );
static inline int PyUnicode_READY(PyObject* _unused_op __attribute__((unused)))
{
    return 0;
}
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_Copy(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_CopyCharacters(
    PyObject *to,
    Py_ssize_t to_start,
    PyObject *from,
    Py_ssize_t from_start,
    Py_ssize_t how_many
    );
__attribute__ ((visibility ("default"))) void _PyUnicode_FastCopyCharacters(
    PyObject *to,
    Py_ssize_t to_start,
    PyObject *from,
    Py_ssize_t from_start,
    Py_ssize_t how_many
    );
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnicode_Fill(
    PyObject *unicode,
    Py_ssize_t start,
    Py_ssize_t length,
    Py_UCS4 fill_char
    );
__attribute__ ((visibility ("default"))) void _PyUnicode_FastFill(
    PyObject *unicode,
    Py_ssize_t start,
    Py_ssize_t length,
    Py_UCS4 fill_char
    );
__attribute__ ((visibility ("default"))) PyObject* PyUnicode_FromKindAndData(
    int kind,
    const void *buffer,
    Py_ssize_t size);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_FromASCII(
    const char *buffer,
    Py_ssize_t size);
__attribute__ ((visibility ("default"))) Py_UCS4 _PyUnicode_FindMaxChar (
    PyObject *unicode,
    Py_ssize_t start,
    Py_ssize_t end);
typedef struct {
    PyObject *buffer;
    void *data;
    int kind;
    Py_UCS4 maxchar;
    Py_ssize_t size;
    Py_ssize_t pos;
    Py_ssize_t min_length;
    Py_UCS4 min_char;
    unsigned char overallocate;
    unsigned char readonly;
} _PyUnicodeWriter ;
__attribute__ ((visibility ("default"))) void
_PyUnicodeWriter_Init(_PyUnicodeWriter *writer);
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_PrepareInternal(_PyUnicodeWriter *writer,
                                 Py_ssize_t length, Py_UCS4 maxchar);
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_PrepareKindInternal(_PyUnicodeWriter *writer,
                                     int kind);
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_WriteChar(_PyUnicodeWriter *writer,
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_WriteStr(_PyUnicodeWriter *writer,
    PyObject *str
    );
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_WriteSubstring(_PyUnicodeWriter *writer,
    PyObject *str,
    Py_ssize_t start,
    Py_ssize_t end
    );
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_WriteASCIIString(_PyUnicodeWriter *writer,
    const char *str,
    Py_ssize_t len
    );
__attribute__ ((visibility ("default"))) int
_PyUnicodeWriter_WriteLatin1String(_PyUnicodeWriter *writer,
    const char *str,
    Py_ssize_t len
    );
__attribute__ ((visibility ("default"))) PyObject *
_PyUnicodeWriter_Finish(_PyUnicodeWriter *writer);
__attribute__ ((visibility ("default"))) void
_PyUnicodeWriter_Dealloc(_PyUnicodeWriter *writer);
__attribute__ ((visibility ("default"))) int _PyUnicode_FormatAdvancedWriter(
    _PyUnicodeWriter *writer,
    PyObject *obj,
    PyObject *format_spec,
    Py_ssize_t start,
    Py_ssize_t end);
__attribute__ ((visibility ("default"))) const char * PyUnicode_AsUTF8(PyObject *unicode);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_EncodeUTF7(
    PyObject *unicode,
    int base64SetO,
    int base64WhiteSpace,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_AsUTF8String(
    PyObject *unicode,
    const char *errors);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_EncodeUTF32(
    PyObject *object,
    const char *errors,
    int byteorder
    );
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_EncodeUTF16(
    PyObject* unicode,
    const char *errors,
    int byteorder
    );
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_DecodeUnicodeEscapeStateful(
        const char *string,
        Py_ssize_t length,
        const char *errors,
        Py_ssize_t *consumed
);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_DecodeUnicodeEscapeInternal2(
    const char *string,
    Py_ssize_t length,
    const char *errors,
    Py_ssize_t *consumed,
    int *first_invalid_escape_char,
    const char **first_invalid_escape_ptr);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_DecodeUnicodeEscapeInternal(
        const char *string,
        Py_ssize_t length,
        const char *errors,
        Py_ssize_t *consumed,
        const char **first_invalid_escape
);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_DecodeRawUnicodeEscapeStateful(
        const char *string,
        Py_ssize_t length,
        const char *errors,
        Py_ssize_t *consumed
);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_AsLatin1String(
    PyObject* unicode,
    const char* errors);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_AsASCIIString(
    PyObject* unicode,
    const char* errors);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_EncodeCharmap(
    PyObject *unicode,
    PyObject *mapping,
    const char *errors
    );
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_TransformDecimalAndSpaceToASCII(
    PyObject *unicode
    );
__attribute__ ((visibility ("default"))) PyObject * _PyUnicode_JoinArray(
    PyObject *separator,
    PyObject *const *items,
    Py_ssize_t seqlen
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_EqualToASCIIId(
    PyObject *left,
    _Py_Identifier *right
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_EqualToASCIIString(
    PyObject *left,
    const char *right
    );
__attribute__ ((visibility ("default"))) PyObject * _PyUnicode_XStrip(
    PyObject *self,
    int striptype,
    PyObject *sepobj
    );
__attribute__ ((visibility ("default"))) Py_ssize_t _PyUnicode_InsertThousandsGrouping(
    _PyUnicodeWriter *writer,
    Py_ssize_t n_buffer,
    PyObject *digits,
    Py_ssize_t d_pos,
    Py_ssize_t n_digits,
    Py_ssize_t min_width,
    const char *grouping,
    PyObject *thousands_sep,
    Py_UCS4 *maxchar);
__attribute__ ((visibility ("default"))) int _PyUnicode_IsLowercase(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsUppercase(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsTitlecase(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsXidStart(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsXidContinue(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsWhitespace(
    const Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsLinebreak(
    const Py_UCS4 ch
    );
                         __attribute__ ((visibility ("default"))) Py_UCS4 _PyUnicode_ToLowercase(
    Py_UCS4 ch
    );
                         __attribute__ ((visibility ("default"))) Py_UCS4 _PyUnicode_ToUppercase(
    Py_UCS4 ch
    );
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) Py_UCS4 _PyUnicode_ToTitlecase(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_ToLowerFull(
    Py_UCS4 ch,
    Py_UCS4 *res
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_ToTitleFull(
    Py_UCS4 ch,
    Py_UCS4 *res
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_ToUpperFull(
    Py_UCS4 ch,
    Py_UCS4 *res
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_ToFoldedFull(
    Py_UCS4 ch,
    Py_UCS4 *res
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsCaseIgnorable(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsCased(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_ToDecimalDigit(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_ToDigit(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) double _PyUnicode_ToNumeric(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsDecimalDigit(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsDigit(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsNumeric(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsPrintable(
    Py_UCS4 ch
    );
__attribute__ ((visibility ("default"))) int _PyUnicode_IsAlpha(
    Py_UCS4 ch
    );
extern __attribute__ ((visibility ("default"))) const unsigned char _Py_ascii_whitespace[];
static inline int Py_UNICODE_ISSPACE(Py_UCS4 ch) {
    if (ch < 128) {
        return _Py_ascii_whitespace[ch];
    }
    return _PyUnicode_IsWhitespace(ch);
}
static inline int Py_UNICODE_ISALNUM(Py_UCS4 ch) {
   return (_PyUnicode_IsAlpha(ch)
           || _PyUnicode_IsDecimalDigit(ch)
           || _PyUnicode_IsDigit(ch)
           || _PyUnicode_IsNumeric(ch));
}
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_FormatLong(PyObject *, int, int, int);
__attribute__ ((visibility ("default"))) PyObject* _PyUnicode_FromId(_Py_Identifier*);
__attribute__ ((visibility ("default"))) int _PyUnicode_EQ(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int _PyUnicode_Equal(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int _PyUnicode_WideCharString_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) int _PyUnicode_WideCharString_Opt_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) Py_ssize_t _PyUnicode_ScanIdentifier(PyObject *);
typedef struct {
    enum {
        _PyStatus_TYPE_OK=0,
        _PyStatus_TYPE_ERROR=1,
        _PyStatus_TYPE_EXIT=2
    } _type;
    const char *func;
    const char *err_msg;
    int exitcode;
} PyStatus;
__attribute__ ((visibility ("default"))) PyStatus PyStatus_Ok(void);
__attribute__ ((visibility ("default"))) PyStatus PyStatus_Error(const char *err_msg);
__attribute__ ((visibility ("default"))) PyStatus PyStatus_NoMemory(void);
__attribute__ ((visibility ("default"))) PyStatus PyStatus_Exit(int exitcode);
__attribute__ ((visibility ("default"))) int PyStatus_IsError(PyStatus err);
__attribute__ ((visibility ("default"))) int PyStatus_IsExit(PyStatus err);
__attribute__ ((visibility ("default"))) int PyStatus_Exception(PyStatus err);
__attribute__ ((visibility ("default"))) PyObject * _PyErr_SetFromPyStatus(PyStatus status);
typedef struct {
    Py_ssize_t length;
    wchar_t **items;
} PyWideStringList;
__attribute__ ((visibility ("default"))) PyStatus PyWideStringList_Append(PyWideStringList *list,
    const wchar_t *item);
__attribute__ ((visibility ("default"))) PyStatus PyWideStringList_Insert(PyWideStringList *list,
    Py_ssize_t index,
    const wchar_t *item);
typedef struct PyPreConfig {
    int _config_init;
    int parse_argv;
    int isolated;
    int use_environment;
    int configure_locale;
    int coerce_c_locale;
    int coerce_c_locale_warn;
    int utf8_mode;
    int dev_mode;
    int allocator;
} PyPreConfig;
__attribute__ ((visibility ("default"))) void PyPreConfig_InitPythonConfig(PyPreConfig *config);
__attribute__ ((visibility ("default"))) void PyPreConfig_InitIsolatedConfig(PyPreConfig *config);
typedef struct PyConfig {
    int _config_init;
    int isolated;
    int use_environment;
    int dev_mode;
    int install_signal_handlers;
    int use_hash_seed;
    unsigned long hash_seed;
    int faulthandler;
    int tracemalloc;
    int perf_profiling;
    int import_time;
    int code_debug_ranges;
    int show_ref_count;
    int dump_refs;
    wchar_t *dump_refs_file;
    int malloc_stats;
    wchar_t *filesystem_encoding;
    wchar_t *filesystem_errors;
    wchar_t *pycache_prefix;
    int parse_argv;
    PyWideStringList orig_argv;
    PyWideStringList argv;
    PyWideStringList xoptions;
    PyWideStringList warnoptions;
    int site_import;
    int bytes_warning;
    int warn_default_encoding;
    int inspect;
    int interactive;
    int optimization_level;
    int parser_debug;
    int write_bytecode;
    int verbose;
    int quiet;
    int user_site_directory;
    int configure_c_stdio;
    int buffered_stdio;
    wchar_t *stdio_encoding;
    wchar_t *stdio_errors;
    wchar_t *check_hash_pycs_mode;
    int use_frozen_modules;
    int safe_path;
    int int_max_str_digits;
    int pathconfig_warnings;
    wchar_t *program_name;
    wchar_t *pythonpath_env;
    wchar_t *home;
    wchar_t *platlibdir;
    int module_search_paths_set;
    PyWideStringList module_search_paths;
    wchar_t *stdlib_dir;
    wchar_t *executable;
    wchar_t *base_executable;
    wchar_t *prefix;
    wchar_t *base_prefix;
    wchar_t *exec_prefix;
    wchar_t *base_exec_prefix;
    int skip_source_first_line;
    wchar_t *run_command;
    wchar_t *run_module;
    wchar_t *run_filename;
    int _install_importlib;
    int _init_main;
    int _is_python_build;
} PyConfig;
__attribute__ ((visibility ("default"))) void PyConfig_InitPythonConfig(PyConfig *config);
__attribute__ ((visibility ("default"))) void PyConfig_InitIsolatedConfig(PyConfig *config);
__attribute__ ((visibility ("default"))) void PyConfig_Clear(PyConfig *);
__attribute__ ((visibility ("default"))) PyStatus PyConfig_SetString(
    PyConfig *config,
    wchar_t **config_str,
    const wchar_t *str);
__attribute__ ((visibility ("default"))) PyStatus PyConfig_SetBytesString(
    PyConfig *config,
    wchar_t **config_str,
    const char *str);
__attribute__ ((visibility ("default"))) PyStatus PyConfig_Read(PyConfig *config);
__attribute__ ((visibility ("default"))) PyStatus PyConfig_SetBytesArgv(
    PyConfig *config,
    Py_ssize_t argc,
    char * const *argv);
__attribute__ ((visibility ("default"))) PyStatus PyConfig_SetArgv(PyConfig *config,
    Py_ssize_t argc,
    wchar_t * const *argv);
__attribute__ ((visibility ("default"))) PyStatus PyConfig_SetWideStringList(PyConfig *config,
    PyWideStringList *list,
    Py_ssize_t length, wchar_t **items);
__attribute__ ((visibility ("default"))) void Py_GetArgcArgv(int *argc, wchar_t ***argv);
__attribute__ ((visibility ("default"))) PyInterpreterState * PyInterpreterState_New(void);
__attribute__ ((visibility ("default"))) void PyInterpreterState_Clear(PyInterpreterState *);
__attribute__ ((visibility ("default"))) void PyInterpreterState_Delete(PyInterpreterState *);
__attribute__ ((visibility ("default"))) PyInterpreterState * PyInterpreterState_Get(void);
__attribute__ ((visibility ("default"))) PyObject * PyInterpreterState_GetDict(PyInterpreterState *);
__attribute__ ((visibility ("default"))) int64_t PyInterpreterState_GetID(PyInterpreterState *);
__attribute__ ((visibility ("default"))) int PyState_AddModule(PyObject*, PyModuleDef*);
__attribute__ ((visibility ("default"))) int PyState_RemoveModule(PyModuleDef*);
__attribute__ ((visibility ("default"))) PyObject* PyState_FindModule(PyModuleDef*);
__attribute__ ((visibility ("default"))) PyThreadState * PyThreadState_New(PyInterpreterState *);
__attribute__ ((visibility ("default"))) void PyThreadState_Clear(PyThreadState *);
__attribute__ ((visibility ("default"))) void PyThreadState_Delete(PyThreadState *);
__attribute__ ((visibility ("default"))) PyThreadState * PyThreadState_Get(void);
__attribute__ ((visibility ("default"))) PyThreadState * PyThreadState_Swap(PyThreadState *);
__attribute__ ((visibility ("default"))) PyObject * PyThreadState_GetDict(void);
__attribute__ ((visibility ("default"))) int PyThreadState_SetAsyncExc(unsigned long, PyObject *);
__attribute__ ((visibility ("default"))) PyInterpreterState* PyThreadState_GetInterpreter(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) PyFrameObject* PyThreadState_GetFrame(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) uint64_t PyThreadState_GetID(PyThreadState *tstate);
typedef
    enum {PyGILState_LOCKED, PyGILState_UNLOCKED}
        PyGILState_STATE;
__attribute__ ((visibility ("default"))) PyGILState_STATE PyGILState_Ensure(void);
__attribute__ ((visibility ("default"))) void PyGILState_Release(PyGILState_STATE);
__attribute__ ((visibility ("default"))) PyThreadState * PyGILState_GetThisThreadState(void);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_HasFeature(PyInterpreterState *interp,
                                               unsigned long feature);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_RequiresIDRef(PyInterpreterState *);
__attribute__ ((visibility ("default"))) void _PyInterpreterState_RequireIDRef(PyInterpreterState *, int);
__attribute__ ((visibility ("default"))) PyObject * _PyInterpreterState_GetMainModule(PyInterpreterState *);
typedef int (*Py_tracefunc)(PyObject *, PyFrameObject *, int, PyObject *);
typedef struct _PyCFrame {
    struct _PyInterpreterFrame *current_frame;
    struct _PyCFrame *previous;
} _PyCFrame;
typedef struct _err_stackitem {
    PyObject *exc_value;
    struct _err_stackitem *previous_item;
} _PyErr_StackItem;
typedef struct _stack_chunk {
    struct _stack_chunk *previous;
    size_t size;
    size_t top;
    PyObject * data[1];
} _PyStackChunk;
struct _py_trashcan {
    int delete_nesting;
    PyObject *delete_later;
};
struct _ts {
    PyThreadState *prev;
    PyThreadState *next;
    PyInterpreterState *interp;
    struct {
        unsigned int initialized:1;
        unsigned int bound:1;
        unsigned int unbound:1;
        unsigned int bound_gilstate:1;
        unsigned int active:1;
        unsigned int finalizing:1;
        unsigned int cleared:1;
        unsigned int finalized:1;
        unsigned int :24;
    } _status;
    int py_recursion_remaining;
    int py_recursion_limit;
    int c_recursion_remaining;
    int recursion_headroom;
    int tracing;
    int what_event;
    _PyCFrame *cframe;
    Py_tracefunc c_profilefunc;
    Py_tracefunc c_tracefunc;
    PyObject *c_profileobj;
    PyObject *c_traceobj;
    PyObject *current_exception;
    _PyErr_StackItem *exc_info;
    PyObject *dict;
    int gilstate_counter;
    PyObject *async_exc;
    unsigned long thread_id;
    unsigned long native_thread_id;
    struct _py_trashcan trash;
    void (*on_delete)(void *);
    void *on_delete_data;
    int coroutine_origin_tracking_depth;
    PyObject *async_gen_firstiter;
    PyObject *async_gen_finalizer;
    PyObject *context;
    uint64_t context_ver;
    uint64_t id;
    _PyStackChunk *datastack_chunk;
    PyObject **datastack_top;
    PyObject **datastack_limit;
    _PyErr_StackItem exc_state;
    _PyCFrame root_cframe;
};
__attribute__ ((visibility ("default"))) PyThreadState * _PyThreadState_Prealloc(PyInterpreterState *);
__attribute__ ((visibility ("default"))) PyThreadState * _PyThreadState_UncheckedGet(void);
__attribute__ ((visibility ("default"))) PyObject * _PyThreadState_GetDict(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void PyThreadState_EnterTracing(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void PyThreadState_LeaveTracing(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) int PyGILState_Check(void);
__attribute__ ((visibility ("default"))) PyInterpreterState * _PyGILState_GetInterpreterStateUnsafe(void);
__attribute__ ((visibility ("default"))) PyObject * _PyThread_CurrentFrames(void);
__attribute__ ((visibility ("default"))) PyObject * _PyThread_CurrentExceptions(void);
__attribute__ ((visibility ("default"))) PyInterpreterState * PyInterpreterState_Main(void);
__attribute__ ((visibility ("default"))) PyInterpreterState * PyInterpreterState_Head(void);
__attribute__ ((visibility ("default"))) PyInterpreterState * PyInterpreterState_Next(PyInterpreterState *);
__attribute__ ((visibility ("default"))) PyThreadState * PyInterpreterState_ThreadHead(PyInterpreterState *);
__attribute__ ((visibility ("default"))) PyThreadState * PyThreadState_Next(PyThreadState *);
__attribute__ ((visibility ("default"))) void PyThreadState_DeleteCurrent(void);
typedef PyObject* (*_PyFrameEvalFunction)(PyThreadState *tstate, struct _PyInterpreterFrame *, int);
__attribute__ ((visibility ("default"))) _PyFrameEvalFunction _PyInterpreterState_GetEvalFrameFunc(
    PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) void _PyInterpreterState_SetEvalFrameFunc(
    PyInterpreterState *interp,
    _PyFrameEvalFunction eval_frame);
__attribute__ ((visibility ("default"))) const PyConfig* _PyInterpreterState_GetConfig(PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_GetConfigCopy(
    struct PyConfig *config);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_SetConfig(
    const struct PyConfig *config);
__attribute__ ((visibility ("default"))) const PyConfig* _Py_GetConfig(void);
typedef struct _xid _PyCrossInterpreterData;
typedef PyObject *(*xid_newobjectfunc)(_PyCrossInterpreterData *);
typedef void (*xid_freefunc)(void *);
struct _xid {
    void *data;
    PyObject *obj;
    int64_t interp;
    xid_newobjectfunc new_object;
    xid_freefunc free;
};
__attribute__ ((visibility ("default"))) void _PyCrossInterpreterData_Init(
        _PyCrossInterpreterData *data,
        PyInterpreterState *interp, void *shared, PyObject *obj,
        xid_newobjectfunc new_object);
__attribute__ ((visibility ("default"))) int _PyCrossInterpreterData_InitWithSize(
        _PyCrossInterpreterData *,
        PyInterpreterState *interp, const size_t, PyObject *,
        xid_newobjectfunc);
__attribute__ ((visibility ("default"))) void _PyCrossInterpreterData_Clear(
        PyInterpreterState *, _PyCrossInterpreterData *);
__attribute__ ((visibility ("default"))) int _PyObject_GetCrossInterpreterData(PyObject *, _PyCrossInterpreterData *);
__attribute__ ((visibility ("default"))) PyObject * _PyCrossInterpreterData_NewObject(_PyCrossInterpreterData *);
__attribute__ ((visibility ("default"))) int _PyCrossInterpreterData_Release(_PyCrossInterpreterData *);
__attribute__ ((visibility ("default"))) int _PyObject_CheckCrossInterpreterData(PyObject *);
typedef int (*crossinterpdatafunc)(PyThreadState *tstate, PyObject *,
                                   _PyCrossInterpreterData *);
__attribute__ ((visibility ("default"))) int _PyCrossInterpreterData_RegisterClass(PyTypeObject *, crossinterpdatafunc);
__attribute__ ((visibility ("default"))) int _PyCrossInterpreterData_UnregisterClass(PyTypeObject *);
__attribute__ ((visibility ("default"))) crossinterpdatafunc _PyCrossInterpreterData_Lookup(PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_SetNone(PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_SetObject(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_SetString(
    PyObject *exception,
    const char *string
    );
__attribute__ ((visibility ("default"))) PyObject * PyErr_Occurred(void);
__attribute__ ((visibility ("default"))) void PyErr_Clear(void);
__attribute__ ((visibility ("default"))) void PyErr_Fetch(PyObject **, PyObject **, PyObject **);
__attribute__ ((visibility ("default"))) void PyErr_Restore(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyErr_GetRaisedException(void);
__attribute__ ((visibility ("default"))) void PyErr_SetRaisedException(PyObject *);
__attribute__ ((visibility ("default"))) PyObject* PyErr_GetHandledException(void);
__attribute__ ((visibility ("default"))) void PyErr_SetHandledException(PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_GetExcInfo(PyObject **, PyObject **, PyObject **);
__attribute__ ((visibility ("default"))) void PyErr_SetExcInfo(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) Py_FatalError(const char *message);
__attribute__ ((visibility ("default"))) int PyErr_GivenExceptionMatches(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int PyErr_ExceptionMatches(PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_NormalizeException(PyObject**, PyObject**, PyObject**);
__attribute__ ((visibility ("default"))) int PyException_SetTraceback(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyException_GetTraceback(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyException_GetCause(PyObject *);
__attribute__ ((visibility ("default"))) void PyException_SetCause(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyException_GetContext(PyObject *);
__attribute__ ((visibility ("default"))) void PyException_SetContext(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyException_GetArgs(PyObject *);
__attribute__ ((visibility ("default"))) void PyException_SetArgs(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) const char * PyExceptionClass_Name(PyObject *);
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_BaseException;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_Exception;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_BaseExceptionGroup;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_StopAsyncIteration;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_StopIteration;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_GeneratorExit;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ArithmeticError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_LookupError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_AssertionError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_AttributeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_BufferError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_EOFError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_FloatingPointError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_OSError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ImportError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ModuleNotFoundError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_IndexError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_KeyError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_KeyboardInterrupt;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_MemoryError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_NameError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_OverflowError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_RuntimeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_RecursionError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_NotImplementedError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_SyntaxError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_IndentationError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_TabError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ReferenceError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_SystemError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_SystemExit;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_TypeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UnboundLocalError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UnicodeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UnicodeEncodeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UnicodeDecodeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UnicodeTranslateError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ValueError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ZeroDivisionError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_BlockingIOError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_BrokenPipeError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ChildProcessError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ConnectionError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ConnectionAbortedError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ConnectionRefusedError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ConnectionResetError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_FileExistsError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_FileNotFoundError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_InterruptedError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_IsADirectoryError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_NotADirectoryError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_PermissionError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ProcessLookupError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_TimeoutError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_EnvironmentError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_IOError;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_Warning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UserWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_DeprecationWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_PendingDeprecationWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_SyntaxWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_RuntimeWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_FutureWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ImportWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_UnicodeWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_BytesWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_EncodingWarning;
extern __attribute__ ((visibility ("default"))) PyObject * PyExc_ResourceWarning;
__attribute__ ((visibility ("default"))) int PyErr_BadArgument(void);
__attribute__ ((visibility ("default"))) PyObject * PyErr_NoMemory(void);
__attribute__ ((visibility ("default"))) PyObject * PyErr_SetFromErrno(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyErr_SetFromErrnoWithFilenameObject(
    PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyErr_SetFromErrnoWithFilenameObjects(
    PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyErr_SetFromErrnoWithFilename(
    PyObject *exc,
    const char *filename
    );
__attribute__ ((visibility ("default"))) PyObject * PyErr_Format(
    PyObject *exception,
    const char *format,
    ...
    );
__attribute__ ((visibility ("default"))) PyObject * PyErr_FormatV(
    PyObject *exception,
    const char *format,
    va_list vargs);
__attribute__ ((visibility ("default"))) PyObject * PyErr_SetImportErrorSubclass(PyObject *, PyObject *,
    PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyErr_SetImportError(PyObject *, PyObject *,
    PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_BadInternalCall(void);
__attribute__ ((visibility ("default"))) void _PyErr_BadInternalCall(const char *filename, int lineno);
__attribute__ ((visibility ("default"))) PyObject * PyErr_NewException(
    const char *name, PyObject *base, PyObject *dict);
__attribute__ ((visibility ("default"))) PyObject * PyErr_NewExceptionWithDoc(
    const char *name, const char *doc, PyObject *base, PyObject *dict);
__attribute__ ((visibility ("default"))) void PyErr_WriteUnraisable(PyObject *);
__attribute__ ((visibility ("default"))) int PyErr_CheckSignals(void);
__attribute__ ((visibility ("default"))) void PyErr_SetInterrupt(void);
__attribute__ ((visibility ("default"))) int PyErr_SetInterruptEx(int signum);
__attribute__ ((visibility ("default"))) void PyErr_SyntaxLocation(
    const char *filename,
    int lineno);
__attribute__ ((visibility ("default"))) void PyErr_SyntaxLocationEx(
    const char *filename,
    int lineno,
    int col_offset);
__attribute__ ((visibility ("default"))) PyObject * PyErr_ProgramText(
    const char *filename,
    int lineno);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeDecodeError_Create(
    const char *encoding,
    const char *object,
    Py_ssize_t length,
    Py_ssize_t start,
    Py_ssize_t end,
    const char *reason
    );
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeEncodeError_GetEncoding(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeDecodeError_GetEncoding(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeEncodeError_GetObject(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeDecodeError_GetObject(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeTranslateError_GetObject(PyObject *);
__attribute__ ((visibility ("default"))) int PyUnicodeEncodeError_GetStart(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int PyUnicodeDecodeError_GetStart(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int PyUnicodeTranslateError_GetStart(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int PyUnicodeEncodeError_SetStart(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyUnicodeDecodeError_SetStart(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyUnicodeTranslateError_SetStart(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyUnicodeEncodeError_GetEnd(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int PyUnicodeDecodeError_GetEnd(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int PyUnicodeTranslateError_GetEnd(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int PyUnicodeEncodeError_SetEnd(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyUnicodeDecodeError_SetEnd(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyUnicodeTranslateError_SetEnd(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeEncodeError_GetReason(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeDecodeError_GetReason(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyUnicodeTranslateError_GetReason(PyObject *);
__attribute__ ((visibility ("default"))) int PyUnicodeEncodeError_SetReason(
    PyObject *exc,
    const char *reason
    );
__attribute__ ((visibility ("default"))) int PyUnicodeDecodeError_SetReason(
    PyObject *exc,
    const char *reason
    );
__attribute__ ((visibility ("default"))) int PyUnicodeTranslateError_SetReason(
    PyObject *exc,
    const char *reason
    );
__attribute__ ((visibility ("default"))) int PyOS_snprintf(char *str, size_t size, const char *format, ...)
                        __attribute__((format(printf, 3, 4)));
__attribute__ ((visibility ("default"))) int PyOS_vsnprintf(char *str, size_t size, const char *format, va_list va)
                        __attribute__((format(printf, 3, 0)));
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
} PyBaseExceptionObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *msg;
    PyObject *excs;
} PyBaseExceptionGroupObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *msg;
    PyObject *filename;
    PyObject *lineno;
    PyObject *offset;
    PyObject *end_lineno;
    PyObject *end_offset;
    PyObject *text;
    PyObject *print_file_and_line;
} PySyntaxErrorObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *msg;
    PyObject *name;
    PyObject *path;
    PyObject *name_from;
} PyImportErrorObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *encoding;
    PyObject *object;
    Py_ssize_t start;
    Py_ssize_t end;
    PyObject *reason;
} PyUnicodeErrorObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *code;
} PySystemExitObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *myerrno;
    PyObject *strerror;
    PyObject *filename;
    PyObject *filename2;
    Py_ssize_t written;
} PyOSErrorObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *value;
} PyStopIterationObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *name;
} PyNameErrorObject;
typedef struct {
    PyObject ob_base; PyObject *dict; PyObject *args; PyObject *notes; PyObject *traceback; PyObject *context; PyObject *cause; char suppress_context;
    PyObject *obj;
    PyObject *name;
} PyAttributeErrorObject;
typedef PyOSErrorObject PyEnvironmentErrorObject;
__attribute__ ((visibility ("default"))) void _PyErr_SetKeyError(PyObject *);
__attribute__ ((visibility ("default"))) _PyErr_StackItem* _PyErr_GetTopmostException(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) PyObject* _PyErr_GetHandledException(PyThreadState *);
__attribute__ ((visibility ("default"))) void _PyErr_SetHandledException(PyThreadState *, PyObject *);
__attribute__ ((visibility ("default"))) void _PyErr_GetExcInfo(PyThreadState *, PyObject **, PyObject **, PyObject **);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void _PyErr_ChainExceptions(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) void _PyErr_ChainExceptions1(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyErr_FormatFromCause(
    PyObject *exception,
    const char *format,
    ...
    );
__attribute__ ((visibility ("default"))) int _PyException_AddNote(
     PyObject *exc,
     PyObject *note);
__attribute__ ((visibility ("default"))) PyObject* PyUnstable_Exc_PrepReraiseStar(
     PyObject *orig,
     PyObject *excs);
int PySignal_SetWakeupFd(int fd);
__attribute__ ((visibility ("default"))) int _PyErr_CheckSignals(void);
__attribute__ ((visibility ("default"))) void PyErr_SyntaxLocationObject(
    PyObject *filename,
    int lineno,
    int col_offset);
__attribute__ ((visibility ("default"))) void PyErr_RangedSyntaxLocationObject(
    PyObject *filename,
    int lineno,
    int col_offset,
    int end_lineno,
    int end_col_offset);
__attribute__ ((visibility ("default"))) PyObject * PyErr_ProgramTextObject(
    PyObject *filename,
    int lineno);
__attribute__ ((visibility ("default"))) PyObject * _PyErr_ProgramDecodedTextObject(
    PyObject *filename,
    int lineno,
    const char* encoding);
__attribute__ ((visibility ("default"))) PyObject * _PyUnicodeTranslateError_Create(
    PyObject *object,
    Py_ssize_t start,
    Py_ssize_t end,
    const char *reason
    );
__attribute__ ((visibility ("default"))) void _PyErr_WriteUnraisableMsg(
    const char *err_msg,
    PyObject *obj);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) _Py_FatalErrorFunc(
    const char *func,
    const char *message);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) _Py_FatalErrorFormat(
    const char *func,
    const char *format,
    ...);
extern PyObject *_PyErr_SetImportErrorWithNameFrom(
        PyObject *,
        PyObject *,
        PyObject *,
        PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromLong(long);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromUnsignedLong(unsigned long);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromSize_t(size_t);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromSsize_t(Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromDouble(double);
__attribute__ ((visibility ("default"))) long PyLong_AsLong(PyObject *);
__attribute__ ((visibility ("default"))) long PyLong_AsLongAndOverflow(PyObject *, int *);
__attribute__ ((visibility ("default"))) Py_ssize_t PyLong_AsSsize_t(PyObject *);
__attribute__ ((visibility ("default"))) size_t PyLong_AsSize_t(PyObject *);
__attribute__ ((visibility ("default"))) unsigned long PyLong_AsUnsignedLong(PyObject *);
__attribute__ ((visibility ("default"))) unsigned long PyLong_AsUnsignedLongMask(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyLong_GetInfo(void);
__attribute__ ((visibility ("default"))) double PyLong_AsDouble(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromVoidPtr(void *);
__attribute__ ((visibility ("default"))) void * PyLong_AsVoidPtr(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromLongLong(long long);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromUnsignedLongLong(unsigned long long);
__attribute__ ((visibility ("default"))) long long PyLong_AsLongLong(PyObject *);
__attribute__ ((visibility ("default"))) unsigned long long PyLong_AsUnsignedLongLong(PyObject *);
__attribute__ ((visibility ("default"))) unsigned long long PyLong_AsUnsignedLongLongMask(PyObject *);
__attribute__ ((visibility ("default"))) long long PyLong_AsLongLongAndOverflow(PyObject *, int *);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromString(const char *, char **, int);
__attribute__ ((visibility ("default"))) unsigned long PyOS_strtoul(const char *, char **, int);
__attribute__ ((visibility ("default"))) long PyOS_strtol(const char *, char **, int);
__attribute__ ((visibility ("default"))) int _PyLong_AsInt(PyObject *);
__attribute__ ((visibility ("default"))) int _PyLong_UnsignedShort_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) int _PyLong_UnsignedInt_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) int _PyLong_UnsignedLong_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) int _PyLong_UnsignedLongLong_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) int _PyLong_Size_t_Converter(PyObject *, void *);
__attribute__ ((visibility ("default"))) double _PyLong_Frexp(PyLongObject *a, Py_ssize_t *e);
__attribute__ ((visibility ("default"))) PyObject * PyLong_FromUnicodeObject(PyObject *u, int base);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_FromBytes(const char *, Py_ssize_t, int);
__attribute__ ((visibility ("default"))) int _PyLong_Sign(PyObject *v);
__attribute__ ((visibility ("default"))) size_t _PyLong_NumBits(PyObject *v);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_DivmodNear(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_FromByteArray(
    const unsigned char* bytes, size_t n,
    int little_endian, int is_signed);
__attribute__ ((visibility ("default"))) int _PyLong_AsByteArray(PyLongObject* v,
    unsigned char* bytes, size_t n,
    int little_endian, int is_signed);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_Format(PyObject *obj, int base);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_GCD(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_Rshift(PyObject *, size_t);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_Lshift(PyObject *, size_t);
__attribute__ ((visibility ("default"))) int PyUnstable_Long_IsCompact(const PyLongObject* op);
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnstable_Long_CompactValue(const PyLongObject* op);
typedef uint32_t digit;
typedef int32_t sdigit;
typedef uint64_t twodigits;
typedef int64_t stwodigits;
typedef struct _PyLongValue {
    uintptr_t lv_tag;
    digit ob_digit[1];
} _PyLongValue;
struct _longobject {
    PyObject ob_base;
    _PyLongValue long_value;
};
__attribute__ ((visibility ("default"))) PyLongObject * _PyLong_New(Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * _PyLong_Copy(PyLongObject *src);
__attribute__ ((visibility ("default"))) PyLongObject *
_PyLong_FromDigits(int negative, Py_ssize_t digit_count, digit *digits);
static inline int
_PyLong_IsCompact(const PyLongObject* op) {
    ((void) sizeof ((PyType_HasFeature((op)->ob_base.ob_type, (1UL << 24))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((op)->ob_base.ob_type, (1UL << 24))) ; else __assert_fail ("PyType_HasFeature((op)->ob_base.ob_type, Py_TPFLAGS_LONG_SUBCLASS)", "/usr/include/python3.12/cpython/longintrepr.h", 110, __extension__ __PRETTY_FUNCTION__); }));
    return op->long_value.lv_tag < (2 << 3);
}
static inline Py_ssize_t
_PyLong_CompactValue(const PyLongObject *op)
{
    Py_ssize_t sign;
    ((void) sizeof ((PyType_HasFeature((op)->ob_base.ob_type, (1UL << 24))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((op)->ob_base.ob_type, (1UL << 24))) ; else __assert_fail ("PyType_HasFeature((op)->ob_base.ob_type, Py_TPFLAGS_LONG_SUBCLASS)", "/usr/include/python3.12/cpython/longintrepr.h", 120, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((_PyLong_IsCompact(op)) ? 1 : 0), __extension__ ({ if (_PyLong_IsCompact(op)) ; else __assert_fail ("PyUnstable_Long_IsCompact(op)", "/usr/include/python3.12/cpython/longintrepr.h", 121, __extension__ __PRETTY_FUNCTION__); }));
    sign = 1 - (op->long_value.lv_tag & 3);
    return sign * (Py_ssize_t)op->long_value.ob_digit[0];
}
extern __attribute__ ((visibility ("default"))) PyLongObject _Py_FalseStruct;
extern __attribute__ ((visibility ("default"))) PyLongObject _Py_TrueStruct;
__attribute__ ((visibility ("default"))) int Py_IsTrue(PyObject *x);
__attribute__ ((visibility ("default"))) int Py_IsFalse(PyObject *x);
__attribute__ ((visibility ("default"))) PyObject * PyBool_FromLong(long);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyFloat_Type;
__attribute__ ((visibility ("default"))) double PyFloat_GetMax(void);
__attribute__ ((visibility ("default"))) double PyFloat_GetMin(void);
__attribute__ ((visibility ("default"))) PyObject* PyFloat_GetInfo(void);
__attribute__ ((visibility ("default"))) PyObject* PyFloat_FromString(PyObject*);
__attribute__ ((visibility ("default"))) PyObject* PyFloat_FromDouble(double);
__attribute__ ((visibility ("default"))) double PyFloat_AsDouble(PyObject*);
typedef struct {
    PyObject ob_base;
    double ob_fval;
} PyFloatObject;
static inline double PyFloat_AS_DOUBLE(PyObject *op) {
    return (((void) sizeof ((PyObject_TypeCheck(((PyObject*)((op))), (&PyFloat_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)((op))), (&PyFloat_Type))) ; else __assert_fail ("PyFloat_Check(op)", "/usr/include/python3.12/cpython/floatobject.h", 16, __extension__ __PRETTY_FUNCTION__); })), ((PyFloatObject*)(op)))->ob_fval;
}
__attribute__ ((visibility ("default"))) int PyFloat_Pack2(double x, char *p, int le);
__attribute__ ((visibility ("default"))) int PyFloat_Pack4(double x, char *p, int le);
__attribute__ ((visibility ("default"))) int PyFloat_Pack8(double x, char *p, int le);
__attribute__ ((visibility ("default"))) double PyFloat_Unpack2(const char *p, int le);
__attribute__ ((visibility ("default"))) double PyFloat_Unpack4(const char *p, int le);
__attribute__ ((visibility ("default"))) double PyFloat_Unpack8(const char *p, int le);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyComplex_Type;
__attribute__ ((visibility ("default"))) PyObject * PyComplex_FromDoubles(double real, double imag);
__attribute__ ((visibility ("default"))) double PyComplex_RealAsDouble(PyObject *op);
__attribute__ ((visibility ("default"))) double PyComplex_ImagAsDouble(PyObject *op);
typedef struct {
    double real;
    double imag;
} Py_complex;
__attribute__ ((visibility ("default"))) Py_complex _Py_c_sum(Py_complex, Py_complex);
__attribute__ ((visibility ("default"))) Py_complex _Py_c_diff(Py_complex, Py_complex);
__attribute__ ((visibility ("default"))) Py_complex _Py_c_neg(Py_complex);
__attribute__ ((visibility ("default"))) Py_complex _Py_c_prod(Py_complex, Py_complex);
__attribute__ ((visibility ("default"))) Py_complex _Py_c_quot(Py_complex, Py_complex);
__attribute__ ((visibility ("default"))) Py_complex _Py_c_pow(Py_complex, Py_complex);
__attribute__ ((visibility ("default"))) double _Py_c_abs(Py_complex);
typedef struct {
    PyObject ob_base;
    Py_complex cval;
} PyComplexObject;
__attribute__ ((visibility ("default"))) PyObject * PyComplex_FromCComplex(Py_complex);
__attribute__ ((visibility ("default"))) Py_complex PyComplex_AsCComplex(PyObject *op);
extern int _PyComplex_FormatAdvancedWriter(
    _PyUnicodeWriter *writer,
    PyObject *obj,
    PyObject *format_spec,
    Py_ssize_t start,
    Py_ssize_t end);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyRange_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyRangeIter_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyLongRangeIter_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyMemoryView_Type;
__attribute__ ((visibility ("default"))) PyObject * PyMemoryView_FromObject(PyObject *base);
__attribute__ ((visibility ("default"))) PyObject * PyMemoryView_FromMemory(char *mem, Py_ssize_t size,
                                               int flags);
__attribute__ ((visibility ("default"))) PyObject * PyMemoryView_FromBuffer(const Py_buffer *info);
__attribute__ ((visibility ("default"))) PyObject * PyMemoryView_GetContiguous(PyObject *base,
                                                  int buffertype,
                                                  char order);
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyManagedBuffer_Type;
typedef struct {
    PyObject ob_base;
    int flags;
    Py_ssize_t exports;
    Py_buffer master;
} _PyManagedBufferObject;
typedef struct {
    PyVarObject ob_base;
    _PyManagedBufferObject *mbuf;
    Py_hash_t hash;
    int flags;
    Py_ssize_t exports;
    Py_buffer view;
    PyObject *weakreflist;
    Py_ssize_t ob_array[1];
} PyMemoryViewObject;
static inline Py_buffer* PyMemoryView_GET_BUFFER(PyObject *op) {
    return (&((PyMemoryViewObject*)(op))->view);
}
static inline PyObject* PyMemoryView_GET_BASE(PyObject *op) {
    return ((PyMemoryViewObject*)(op))->view.obj;
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyTuple_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyTupleIter_Type;
__attribute__ ((visibility ("default"))) PyObject * PyTuple_New(Py_ssize_t size);
__attribute__ ((visibility ("default"))) Py_ssize_t PyTuple_Size(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyTuple_GetItem(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyTuple_SetItem(PyObject *, Py_ssize_t, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyTuple_GetSlice(PyObject *, Py_ssize_t, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject * PyTuple_Pack(Py_ssize_t, ...);
typedef struct {
    PyVarObject ob_base;
    PyObject *ob_item[1];
} PyTupleObject;
__attribute__ ((visibility ("default"))) int _PyTuple_Resize(PyObject **, Py_ssize_t);
__attribute__ ((visibility ("default"))) void _PyTuple_MaybeUntrack(PyObject *);
static inline Py_ssize_t PyTuple_GET_SIZE(PyObject *op) {
    PyTupleObject *tuple = (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 26)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 26)))) ; else __assert_fail ("PyTuple_Check(op)", "/usr/include/python3.12/cpython/tupleobject.h", 23, __extension__ __PRETTY_FUNCTION__); })), ((PyTupleObject*)((op))));
    return Py_SIZE(((PyObject*)((tuple))));
}
static inline void
PyTuple_SET_ITEM(PyObject *op, Py_ssize_t index, PyObject *value) {
    PyTupleObject *tuple = (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 26)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 26)))) ; else __assert_fail ("PyTuple_Check(op)", "/usr/include/python3.12/cpython/tupleobject.h", 33, __extension__ __PRETTY_FUNCTION__); })), ((PyTupleObject*)((op))));
    tuple->ob_item[index] = value;
}
__attribute__ ((visibility ("default"))) void _PyTuple_DebugMallocStats(FILE *out);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyList_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyListIter_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyListRevIter_Type;
__attribute__ ((visibility ("default"))) PyObject * PyList_New(Py_ssize_t size);
__attribute__ ((visibility ("default"))) Py_ssize_t PyList_Size(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyList_GetItem(PyObject *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyList_SetItem(PyObject *, Py_ssize_t, PyObject *);
__attribute__ ((visibility ("default"))) int PyList_Insert(PyObject *, Py_ssize_t, PyObject *);
__attribute__ ((visibility ("default"))) int PyList_Append(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyList_GetSlice(PyObject *, Py_ssize_t, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyList_SetSlice(PyObject *, Py_ssize_t, Py_ssize_t, PyObject *);
__attribute__ ((visibility ("default"))) int PyList_Sort(PyObject *);
__attribute__ ((visibility ("default"))) int PyList_Reverse(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyList_AsTuple(PyObject *);
typedef struct {
    PyVarObject ob_base;
    PyObject **ob_item;
    Py_ssize_t allocated;
} PyListObject;
__attribute__ ((visibility ("default"))) PyObject * _PyList_Extend(PyListObject *, PyObject *);
__attribute__ ((visibility ("default"))) void _PyList_DebugMallocStats(FILE *out);
static inline Py_ssize_t PyList_GET_SIZE(PyObject *op) {
    PyListObject *list = (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(op)", "/usr/include/python3.12/cpython/listobject.h", 34, __extension__ __PRETTY_FUNCTION__); })), ((PyListObject*)((op))));
    return Py_SIZE(((PyObject*)((list))));
}
static inline void
PyList_SET_ITEM(PyObject *op, Py_ssize_t index, PyObject *value) {
    PyListObject *list = (((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(op)", "/usr/include/python3.12/cpython/listobject.h", 43, __extension__ __PRETTY_FUNCTION__); })), ((PyListObject*)((op))));
    list->ob_item[index] = value;
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDict_Type;
__attribute__ ((visibility ("default"))) PyObject * PyDict_New(void);
__attribute__ ((visibility ("default"))) PyObject * PyDict_GetItem(PyObject *mp, PyObject *key);
__attribute__ ((visibility ("default"))) PyObject * PyDict_GetItemWithError(PyObject *mp, PyObject *key);
__attribute__ ((visibility ("default"))) int PyDict_SetItem(PyObject *mp, PyObject *key, PyObject *item);
__attribute__ ((visibility ("default"))) int PyDict_DelItem(PyObject *mp, PyObject *key);
__attribute__ ((visibility ("default"))) void PyDict_Clear(PyObject *mp);
__attribute__ ((visibility ("default"))) int PyDict_Next(
    PyObject *mp, Py_ssize_t *pos, PyObject **key, PyObject **value);
__attribute__ ((visibility ("default"))) PyObject * PyDict_Keys(PyObject *mp);
__attribute__ ((visibility ("default"))) PyObject * PyDict_Values(PyObject *mp);
__attribute__ ((visibility ("default"))) PyObject * PyDict_Items(PyObject *mp);
__attribute__ ((visibility ("default"))) Py_ssize_t PyDict_Size(PyObject *mp);
__attribute__ ((visibility ("default"))) PyObject * PyDict_Copy(PyObject *mp);
__attribute__ ((visibility ("default"))) int PyDict_Contains(PyObject *mp, PyObject *key);
__attribute__ ((visibility ("default"))) int PyDict_Update(PyObject *mp, PyObject *other);
__attribute__ ((visibility ("default"))) int PyDict_Merge(PyObject *mp,
                             PyObject *other,
                             int override);
__attribute__ ((visibility ("default"))) int PyDict_MergeFromSeq2(PyObject *d,
                                     PyObject *seq2,
                                     int override);
__attribute__ ((visibility ("default"))) PyObject * PyDict_GetItemString(PyObject *dp, const char *key);
__attribute__ ((visibility ("default"))) int PyDict_SetItemString(PyObject *dp, const char *key, PyObject *item);
__attribute__ ((visibility ("default"))) int PyDict_DelItemString(PyObject *dp, const char *key);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GenericGetDict(PyObject *, void *);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictKeys_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictValues_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictItems_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictIterKey_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictIterValue_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictIterItem_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictRevIterKey_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictRevIterItem_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictRevIterValue_Type;
typedef struct _dictkeysobject PyDictKeysObject;
typedef struct _dictvalues PyDictValues;
typedef struct {
    PyObject ob_base;
    Py_ssize_t ma_used;
    uint64_t ma_version_tag;
    PyDictKeysObject *ma_keys;
    PyDictValues *ma_values;
} PyDictObject;
__attribute__ ((visibility ("default"))) PyObject * _PyDict_GetItem_KnownHash(PyObject *mp, PyObject *key,
                                       Py_hash_t hash);
__attribute__ ((visibility ("default"))) PyObject * _PyDict_GetItemWithError(PyObject *dp, PyObject *key);
__attribute__ ((visibility ("default"))) PyObject * _PyDict_GetItemIdWithError(PyObject *dp,
                                                  _Py_Identifier *key);
__attribute__ ((visibility ("default"))) PyObject * _PyDict_GetItemStringWithError(PyObject *, const char *);
__attribute__ ((visibility ("default"))) PyObject * PyDict_SetDefault(
    PyObject *mp, PyObject *key, PyObject *defaultobj);
__attribute__ ((visibility ("default"))) int _PyDict_SetItem_KnownHash(PyObject *mp, PyObject *key,
                                          PyObject *item, Py_hash_t hash);
__attribute__ ((visibility ("default"))) int _PyDict_DelItem_KnownHash(PyObject *mp, PyObject *key,
                                          Py_hash_t hash);
__attribute__ ((visibility ("default"))) int _PyDict_DelItemIf(PyObject *mp, PyObject *key,
                                  int (*predicate)(PyObject *value));
__attribute__ ((visibility ("default"))) int _PyDict_Next(
    PyObject *mp, Py_ssize_t *pos, PyObject **key, PyObject **value, Py_hash_t *hash);
static inline Py_ssize_t PyDict_GET_SIZE(PyObject *op) {
    PyDictObject *mp;
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 29)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 29)))) ; else __assert_fail ("PyDict_Check(op)", "/usr/include/python3.12/cpython/dictobject.h", 55, __extension__ __PRETTY_FUNCTION__); }));
    mp = ((PyDictObject*)(op));
    return mp->ma_used;
}
__attribute__ ((visibility ("default"))) int _PyDict_Contains_KnownHash(PyObject *, PyObject *, Py_hash_t);
__attribute__ ((visibility ("default"))) int _PyDict_ContainsId(PyObject *, _Py_Identifier *);
__attribute__ ((visibility ("default"))) PyObject * _PyDict_NewPresized(Py_ssize_t minused);
__attribute__ ((visibility ("default"))) void _PyDict_MaybeUntrack(PyObject *mp);
__attribute__ ((visibility ("default"))) int _PyDict_HasOnlyStringKeys(PyObject *mp);
__attribute__ ((visibility ("default"))) Py_ssize_t _PyDict_SizeOf(PyDictObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyDict_Pop(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) int _PyDict_MergeEx(PyObject *mp, PyObject *other, int override);
__attribute__ ((visibility ("default"))) int _PyDict_SetItemId(PyObject *dp, _Py_Identifier *key, PyObject *item);
__attribute__ ((visibility ("default"))) int _PyDict_DelItemId(PyObject *mp, _Py_Identifier *key);
__attribute__ ((visibility ("default"))) void _PyDict_DebugMallocStats(FILE *out);
typedef struct {
    PyObject ob_base;
    PyDictObject *dv_dict;
} _PyDictViewObject;
__attribute__ ((visibility ("default"))) PyObject * _PyDictView_New(PyObject *, PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyDictView_Intersect(PyObject* self, PyObject *other);
typedef enum {
    PyDict_EVENT_ADDED, PyDict_EVENT_MODIFIED, PyDict_EVENT_DELETED, PyDict_EVENT_CLONED, PyDict_EVENT_CLEARED, PyDict_EVENT_DEALLOCATED,
} PyDict_WatchEvent;
typedef int(*PyDict_WatchCallback)(PyDict_WatchEvent event, PyObject* dict, PyObject* key, PyObject* new_value);
__attribute__ ((visibility ("default"))) int PyDict_AddWatcher(PyDict_WatchCallback callback);
__attribute__ ((visibility ("default"))) int PyDict_ClearWatcher(int watcher_id);
__attribute__ ((visibility ("default"))) int PyDict_Watch(int watcher_id, PyObject* dict);
__attribute__ ((visibility ("default"))) int PyDict_Unwatch(int watcher_id, PyObject* dict);
typedef struct _odictobject PyODictObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyODict_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyODictIter_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyODictKeys_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyODictItems_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyODictValues_Type;
__attribute__ ((visibility ("default"))) PyObject * PyODict_New(void);
__attribute__ ((visibility ("default"))) int PyODict_SetItem(PyObject *od, PyObject *key, PyObject *item);
__attribute__ ((visibility ("default"))) int PyODict_DelItem(PyObject *od, PyObject *key);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyEnum_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyReversed_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PySet_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyFrozenSet_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PySetIter_Type;
__attribute__ ((visibility ("default"))) PyObject * PySet_New(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFrozenSet_New(PyObject *);
__attribute__ ((visibility ("default"))) int PySet_Add(PyObject *set, PyObject *key);
__attribute__ ((visibility ("default"))) int PySet_Clear(PyObject *set);
__attribute__ ((visibility ("default"))) int PySet_Contains(PyObject *anyset, PyObject *key);
__attribute__ ((visibility ("default"))) int PySet_Discard(PyObject *set, PyObject *key);
__attribute__ ((visibility ("default"))) PyObject * PySet_Pop(PyObject *set);
__attribute__ ((visibility ("default"))) Py_ssize_t PySet_Size(PyObject *anyset);
typedef struct {
    PyObject *key;
    Py_hash_t hash;
} setentry;
typedef struct {
    PyObject ob_base;
    Py_ssize_t fill;
    Py_ssize_t used;
    Py_ssize_t mask;
    setentry *table;
    Py_hash_t hash;
    Py_ssize_t finger;
    setentry smalltable[8];
    PyObject *weakreflist;
} PySetObject;
static inline Py_ssize_t PySet_GET_SIZE(PyObject *so) {
    return (((void) sizeof (((Py_IS_TYPE(((PyObject*)(((so)))), (&PySet_Type)) || Py_IS_TYPE(((PyObject*)(((so)))), (&PyFrozenSet_Type)) || PyType_IsSubtype(Py_TYPE(((PyObject*)((so)))), &PySet_Type) || PyType_IsSubtype(Py_TYPE(((PyObject*)((so)))), &PyFrozenSet_Type))) ? 1 : 0), __extension__ ({ if ((Py_IS_TYPE(((PyObject*)(((so)))), (&PySet_Type)) || Py_IS_TYPE(((PyObject*)(((so)))), (&PyFrozenSet_Type)) || PyType_IsSubtype(Py_TYPE(((PyObject*)((so)))), &PySet_Type) || PyType_IsSubtype(Py_TYPE(((PyObject*)((so)))), &PyFrozenSet_Type))) ; else __assert_fail ("PyAnySet_Check(so)", "/usr/include/python3.12/cpython/setobject.h", 65, __extension__ __PRETTY_FUNCTION__); })), ((PySetObject*)(so)))->used;
}
extern __attribute__ ((visibility ("default"))) PyObject * _PySet_Dummy;
__attribute__ ((visibility ("default"))) int _PySet_NextEntry(PyObject *set, Py_ssize_t *pos, PyObject **key, Py_hash_t *hash);
__attribute__ ((visibility ("default"))) int _PySet_Update(PyObject *set, PyObject *iterable);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCFunction_Type;
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef PyObject *(*_PyCFunctionFast) (PyObject *, PyObject *const *, Py_ssize_t);
typedef PyObject *(*PyCFunctionWithKeywords)(PyObject *, PyObject *,
                                             PyObject *);
typedef PyObject *(*_PyCFunctionFastWithKeywords) (PyObject *,
                                                   PyObject *const *, Py_ssize_t,
                                                   PyObject *);
typedef PyObject *(*PyCMethod)(PyObject *, PyTypeObject *, PyObject *const *,
                               size_t, PyObject *);
__attribute__ ((visibility ("default"))) PyCFunction PyCFunction_GetFunction(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyCFunction_GetSelf(PyObject *);
__attribute__ ((visibility ("default"))) int PyCFunction_GetFlags(PyObject *);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject * PyCFunction_Call(PyObject *, PyObject *, PyObject *);
struct PyMethodDef {
    const char *ml_name;
    PyCFunction ml_meth;
    int ml_flags;
    const char *ml_doc;
};
__attribute__ ((visibility ("default"))) PyObject * PyCFunction_New(PyMethodDef *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyCFunction_NewEx(PyMethodDef *, PyObject *,
                                         PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyCMethod_New(PyMethodDef *, PyObject *,
                                     PyObject *, PyTypeObject *);
typedef struct {
    PyObject ob_base;
    PyMethodDef *m_ml;
    PyObject *m_self;
    PyObject *m_module;
    PyObject *m_weakreflist;
    vectorcallfunc vectorcall;
} PyCFunctionObject;
typedef struct {
    PyCFunctionObject func;
    PyTypeObject *mm_class;
} PyCMethodObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCMethod_Type;
static inline PyCFunction PyCFunction_GET_FUNCTION(PyObject *func) {
    return (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((func)))), (&PyCFunction_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((func)))), (&PyCFunction_Type))) ; else __assert_fail ("PyCFunction_Check(func)", "/usr/include/python3.12/cpython/methodobject.h", 41, __extension__ __PRETTY_FUNCTION__); })), ((PyCFunctionObject*)((func))))->m_ml->ml_meth;
}
static inline PyObject* PyCFunction_GET_SELF(PyObject *func_obj) {
    PyCFunctionObject *func = (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((func_obj)))), (&PyCFunction_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((func_obj)))), (&PyCFunction_Type))) ; else __assert_fail ("PyCFunction_Check(func_obj)", "/usr/include/python3.12/cpython/methodobject.h", 46, __extension__ __PRETTY_FUNCTION__); })), ((PyCFunctionObject*)((func_obj))));
    if (func->m_ml->ml_flags & 0x0020) {
        return ((void *)0);
    }
    return func->m_self;
}
static inline int PyCFunction_GET_FLAGS(PyObject *func) {
    return (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((func)))), (&PyCFunction_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((func)))), (&PyCFunction_Type))) ; else __assert_fail ("PyCFunction_Check(func)", "/usr/include/python3.12/cpython/methodobject.h", 55, __extension__ __PRETTY_FUNCTION__); })), ((PyCFunctionObject*)((func))))->m_ml->ml_flags;
}
static inline PyTypeObject* PyCFunction_GET_CLASS(PyObject *func_obj) {
    PyCFunctionObject *func = (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((func_obj)))), (&PyCFunction_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((func_obj)))), (&PyCFunction_Type))) ; else __assert_fail ("PyCFunction_Check(func_obj)", "/usr/include/python3.12/cpython/methodobject.h", 60, __extension__ __PRETTY_FUNCTION__); })), ((PyCFunctionObject*)((func_obj))));
    if (func->m_ml->ml_flags & 0x0200) {
        return (((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((func)))), (&PyCMethod_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((func)))), (&PyCMethod_Type))) ; else __assert_fail ("PyCMethod_Check(func)", "/usr/include/python3.12/cpython/methodobject.h", 62, __extension__ __PRETTY_FUNCTION__); })), ((PyCMethodObject*)((func))))->mm_class;
    }
    return ((void *)0);
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyModule_Type;
__attribute__ ((visibility ("default"))) PyObject * PyModule_NewObject(
    PyObject *name
    );
__attribute__ ((visibility ("default"))) PyObject * PyModule_New(
    const char *name
    );
__attribute__ ((visibility ("default"))) PyObject * PyModule_GetDict(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyModule_GetNameObject(PyObject *);
__attribute__ ((visibility ("default"))) const char * PyModule_GetName(PyObject *);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) const char * PyModule_GetFilename(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyModule_GetFilenameObject(PyObject *);
__attribute__ ((visibility ("default"))) void _PyModule_Clear(PyObject *);
__attribute__ ((visibility ("default"))) void _PyModule_ClearDict(PyObject *);
__attribute__ ((visibility ("default"))) int _PyModuleSpec_IsInitializing(PyObject *);
__attribute__ ((visibility ("default"))) PyModuleDef* PyModule_GetDef(PyObject*);
__attribute__ ((visibility ("default"))) void* PyModule_GetState(PyObject*);
__attribute__ ((visibility ("default"))) PyObject * PyModuleDef_Init(PyModuleDef*);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyModuleDef_Type;
typedef struct PyModuleDef_Base {
  PyObject ob_base;
  PyObject* (*m_init)(void);
  Py_ssize_t m_index;
  PyObject* m_copy;
} PyModuleDef_Base;
struct PyModuleDef_Slot {
    int slot;
    void *value;
};
struct PyModuleDef {
  PyModuleDef_Base m_base;
  const char* m_name;
  const char* m_doc;
  Py_ssize_t m_size;
  PyMethodDef *m_methods;
  PyModuleDef_Slot *m_slots;
  traverseproc m_traverse;
  inquiry m_clear;
  freefunc m_free;
};
extern int _PyModule_IsExtension(PyObject *obj);
typedef struct {
    PyObject *fc_globals; PyObject *fc_builtins; PyObject *fc_name; PyObject *fc_qualname; PyObject *fc_code; PyObject *fc_defaults; PyObject *fc_kwdefaults; PyObject *fc_closure;
} PyFrameConstructor;
typedef struct {
    PyObject ob_base;
    PyObject *func_globals; PyObject *func_builtins; PyObject *func_name; PyObject *func_qualname; PyObject *func_code; PyObject *func_defaults; PyObject *func_kwdefaults; PyObject *func_closure;
    PyObject *func_doc;
    PyObject *func_dict;
    PyObject *func_weakreflist;
    PyObject *func_module;
    PyObject *func_annotations;
    PyObject *func_typeparams;
    vectorcallfunc vectorcall;
    uint32_t func_version;
} PyFunctionObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyFunction_Type;
__attribute__ ((visibility ("default"))) PyObject * PyFunction_New(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_NewWithQualName(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetCode(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetGlobals(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetModule(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetDefaults(PyObject *);
__attribute__ ((visibility ("default"))) int PyFunction_SetDefaults(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) void PyFunction_SetVectorcall(PyFunctionObject *, vectorcallfunc);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetKwDefaults(PyObject *);
__attribute__ ((visibility ("default"))) int PyFunction_SetKwDefaults(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetClosure(PyObject *);
__attribute__ ((visibility ("default"))) int PyFunction_SetClosure(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyFunction_GetAnnotations(PyObject *);
__attribute__ ((visibility ("default"))) int PyFunction_SetAnnotations(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyFunction_Vectorcall(
    PyObject *func,
    PyObject *const *stack,
    size_t nargsf,
    PyObject *kwnames);
static inline PyObject* PyFunction_GET_CODE(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 94, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_code;
}
static inline PyObject* PyFunction_GET_GLOBALS(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 99, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_globals;
}
static inline PyObject* PyFunction_GET_MODULE(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 104, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_module;
}
static inline PyObject* PyFunction_GET_DEFAULTS(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 109, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_defaults;
}
static inline PyObject* PyFunction_GET_KW_DEFAULTS(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 114, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_kwdefaults;
}
static inline PyObject* PyFunction_GET_CLOSURE(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 119, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_closure;
}
static inline PyObject* PyFunction_GET_ANNOTATIONS(PyObject *func) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((func)))), (&PyFunction_Type))) ; else __assert_fail ("PyFunction_Check(func)", "/usr/include/python3.12/cpython/funcobject.h", 124, __extension__ __PRETTY_FUNCTION__); })), ((PyFunctionObject*)(func)))->func_annotations;
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PyClassMethod_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyStaticMethod_Type;
__attribute__ ((visibility ("default"))) PyObject * PyClassMethod_New(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyStaticMethod_New(PyObject *);
typedef enum {
    PyFunction_EVENT_CREATE, PyFunction_EVENT_DESTROY, PyFunction_EVENT_MODIFY_CODE, PyFunction_EVENT_MODIFY_DEFAULTS, PyFunction_EVENT_MODIFY_KWDEFAULTS,
} PyFunction_WatchEvent;
typedef int (*PyFunction_WatchCallback)(
  PyFunction_WatchEvent event,
  PyFunctionObject *func,
  PyObject *new_value);
__attribute__ ((visibility ("default"))) int PyFunction_AddWatcher(PyFunction_WatchCallback callback);
__attribute__ ((visibility ("default"))) int PyFunction_ClearWatcher(int watcher_id);
typedef struct {
    PyObject ob_base;
    PyObject *im_func;
    PyObject *im_self;
    PyObject *im_weakreflist;
    vectorcallfunc vectorcall;
} PyMethodObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyMethod_Type;
__attribute__ ((visibility ("default"))) PyObject * PyMethod_New(PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyMethod_Function(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyMethod_Self(PyObject *);
static inline PyObject* PyMethod_GET_FUNCTION(PyObject *meth) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((meth)))), (&PyMethod_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((meth)))), (&PyMethod_Type))) ; else __assert_fail ("PyMethod_Check(meth)", "/usr/include/python3.12/cpython/classobject.h", 35, __extension__ __PRETTY_FUNCTION__); })), ((PyMethodObject*)(meth)))->im_func;
}
static inline PyObject* PyMethod_GET_SELF(PyObject *meth) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((meth)))), (&PyMethod_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((meth)))), (&PyMethod_Type))) ; else __assert_fail ("PyMethod_Check(meth)", "/usr/include/python3.12/cpython/classobject.h", 40, __extension__ __PRETTY_FUNCTION__); })), ((PyMethodObject*)(meth)))->im_self;
}
typedef struct {
    PyObject ob_base;
    PyObject *func;
} PyInstanceMethodObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyInstanceMethod_Type;
__attribute__ ((visibility ("default"))) PyObject * PyInstanceMethod_New(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyInstanceMethod_Function(PyObject *);
static inline PyObject* PyInstanceMethod_GET_FUNCTION(PyObject *meth) {
    return (((void) sizeof ((Py_IS_TYPE(((PyObject*)(((meth)))), (&PyInstanceMethod_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((meth)))), (&PyInstanceMethod_Type))) ; else __assert_fail ("PyInstanceMethod_Check(meth)", "/usr/include/python3.12/cpython/classobject.h", 63, __extension__ __PRETTY_FUNCTION__); })), ((PyInstanceMethodObject*)(meth)))->func;
}
__attribute__ ((visibility ("default"))) PyObject * PyFile_FromFd(int, const char *, const char *, int,
                                     const char *, const char *,
                                     const char *, int);
__attribute__ ((visibility ("default"))) PyObject * PyFile_GetLine(PyObject *, int);
__attribute__ ((visibility ("default"))) int PyFile_WriteObject(PyObject *, PyObject *, int);
__attribute__ ((visibility ("default"))) int PyFile_WriteString(const char *, PyObject *);
__attribute__ ((visibility ("default"))) int PyObject_AsFileDescriptor(PyObject *);
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) const char * Py_FileSystemDefaultEncoding;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) const char * Py_FileSystemDefaultEncodeErrors;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_HasFileSystemDefaultEncoding;
__attribute__((__deprecated__)) extern __attribute__ ((visibility ("default"))) int Py_UTF8Mode;
__attribute__ ((visibility ("default"))) char * Py_UniversalNewlineFgets(char *, int, FILE*, PyObject *);
__attribute__ ((visibility ("default"))) char * _Py_UniversalNewlineFgetsWithSize(char *, int, FILE*, PyObject *, size_t*);
__attribute__ ((visibility ("default"))) PyObject * PyFile_NewStdPrinter(int);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyStdPrinter_Type;
typedef PyObject * (*Py_OpenCodeHookFunction)(PyObject *, void *);
__attribute__ ((visibility ("default"))) PyObject * PyFile_OpenCode(const char *utf8path);
__attribute__ ((visibility ("default"))) PyObject * PyFile_OpenCodeObject(PyObject *path);
__attribute__ ((visibility ("default"))) int PyFile_SetOpenCodeHook(Py_OpenCodeHookFunction hook, void *userData);
__attribute__ ((visibility ("default"))) int _PyLong_FileDescriptor_Converter(PyObject *, void *);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCapsule_Type;
typedef void (*PyCapsule_Destructor)(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyCapsule_New(
    void *pointer,
    const char *name,
    PyCapsule_Destructor destructor);
__attribute__ ((visibility ("default"))) void * PyCapsule_GetPointer(PyObject *capsule, const char *name);
__attribute__ ((visibility ("default"))) PyCapsule_Destructor PyCapsule_GetDestructor(PyObject *capsule);
__attribute__ ((visibility ("default"))) const char * PyCapsule_GetName(PyObject *capsule);
__attribute__ ((visibility ("default"))) void * PyCapsule_GetContext(PyObject *capsule);
__attribute__ ((visibility ("default"))) int PyCapsule_IsValid(PyObject *capsule, const char *name);
__attribute__ ((visibility ("default"))) int PyCapsule_SetPointer(PyObject *capsule, void *pointer);
__attribute__ ((visibility ("default"))) int PyCapsule_SetDestructor(PyObject *capsule, PyCapsule_Destructor destructor);
__attribute__ ((visibility ("default"))) int PyCapsule_SetName(PyObject *capsule, const char *name);
__attribute__ ((visibility ("default"))) int PyCapsule_SetContext(PyObject *capsule, void *context);
__attribute__ ((visibility ("default"))) void * PyCapsule_Import(
    const char *name,
    int no_block);
typedef struct _Py_LocalMonitors {
    uint8_t tools[15];
} _Py_LocalMonitors;
typedef struct _Py_GlobalMonitors {
    uint8_t tools[15];
} _Py_GlobalMonitors;
typedef union {
    uint16_t cache;
    struct {
        uint8_t code;
        uint8_t arg;
    } op;
} _Py_CODEUNIT;
static inline _Py_CODEUNIT
_py_make_codeunit(uint8_t opcode, uint8_t oparg)
{
    _Py_CODEUNIT word;
    word.op.code = opcode;
    word.op.arg = oparg;
    return word;
}
static inline void
_py_set_opcode(_Py_CODEUNIT *word, uint8_t opcode)
{
    word->op.code = opcode;
}
typedef struct {
    PyObject *_co_code;
    PyObject *_co_varnames;
    PyObject *_co_cellvars;
    PyObject *_co_freevars;
} _PyCoCached;
typedef struct {
    uint8_t original_opcode;
    int8_t line_delta;
} _PyCoLineInstrumentationData;
typedef struct {
    _Py_LocalMonitors local_monitors;
    _Py_LocalMonitors active_monitors;
    uint8_t *tools;
    _PyCoLineInstrumentationData *lines;
    uint8_t *line_tools;
    uint8_t *per_instruction_opcodes;
    uint8_t *per_instruction_tools;
} _PyCoMonitoringData;
struct PyCodeObject { PyVarObject ob_base; PyObject *co_consts; PyObject *co_names; PyObject *co_exceptiontable; int co_flags; int co_argcount; int co_posonlyargcount; int co_kwonlyargcount; int co_stacksize; int co_firstlineno; int co_nlocalsplus; int co_framesize; int co_nlocals; int co_ncellvars; int co_nfreevars; uint32_t co_version; PyObject *co_localsplusnames; PyObject *co_localspluskinds; PyObject *co_filename; PyObject *co_name; PyObject *co_qualname; PyObject *co_linetable; PyObject *co_weakreflist; _PyCoCached *_co_cached; uint64_t _co_instrumentation_version; _PyCoMonitoringData *_co_monitoring; int _co_firsttraceable; void *co_extra; char co_code_adaptive[(1)]; };
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCode_Type;
static inline Py_ssize_t PyCode_GetNumFree(PyCodeObject *op) {
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)(((op)))), (&PyCode_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((op)))), (&PyCode_Type))) ; else __assert_fail ("PyCode_Check(op)", "/usr/include/python3.12/cpython/code.h", 217, __extension__ __PRETTY_FUNCTION__); }));
    return op->co_nfreevars;
}
static inline int PyCode_GetFirstFree(PyCodeObject *op) {
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)(((op)))), (&PyCode_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((op)))), (&PyCode_Type))) ; else __assert_fail ("PyCode_Check(op)", "/usr/include/python3.12/cpython/code.h", 222, __extension__ __PRETTY_FUNCTION__); }));
    return op->co_nlocalsplus - op->co_nfreevars;
}
__attribute__ ((visibility ("default"))) PyCodeObject * PyUnstable_Code_New(
        int, int, int, int, int, PyObject *, PyObject *,
        PyObject *, PyObject *, PyObject *, PyObject *,
        PyObject *, PyObject *, PyObject *, int, PyObject *,
        PyObject *);
__attribute__ ((visibility ("default"))) PyCodeObject * PyUnstable_Code_NewWithPosOnlyArgs(
        int, int, int, int, int, int, PyObject *, PyObject *,
        PyObject *, PyObject *, PyObject *, PyObject *,
        PyObject *, PyObject *, PyObject *, int, PyObject *,
        PyObject *);
 static inline PyCodeObject *
PyCode_New(
        int a, int b, int c, int d, int e, PyObject *f, PyObject *g,
        PyObject *h, PyObject *i, PyObject *j, PyObject *k,
        PyObject *l, PyObject *m, PyObject *n, int o, PyObject *p,
        PyObject *q)
{
    return PyUnstable_Code_New(
        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q);
}
 static inline PyCodeObject *
PyCode_NewWithPosOnlyArgs(
        int a, int poac, int b, int c, int d, int e, PyObject *f, PyObject *g,
        PyObject *h, PyObject *i, PyObject *j, PyObject *k,
        PyObject *l, PyObject *m, PyObject *n, int o, PyObject *p,
        PyObject *q)
{
    return PyUnstable_Code_NewWithPosOnlyArgs(
        a, poac, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q);
}
__attribute__ ((visibility ("default"))) PyCodeObject *
PyCode_NewEmpty(const char *filename, const char *funcname, int firstlineno);
__attribute__ ((visibility ("default"))) int PyCode_Addr2Line(PyCodeObject *, int);
__attribute__ ((visibility ("default"))) int PyCode_Addr2Location(PyCodeObject *, int, int *, int *, int *, int *);
typedef enum {
    PY_CODE_EVENT_CREATE, PY_CODE_EVENT_DESTROY,
} PyCodeEvent;
typedef int (*PyCode_WatchCallback)(
  PyCodeEvent event,
  PyCodeObject* co);
__attribute__ ((visibility ("default"))) int PyCode_AddWatcher(PyCode_WatchCallback callback);
__attribute__ ((visibility ("default"))) int PyCode_ClearWatcher(int watcher_id);
struct _opaque {
    int computed_line;
    const uint8_t *lo_next;
    const uint8_t *limit;
};
typedef struct _line_offsets {
    int ar_start;
    int ar_end;
    int ar_line;
    struct _opaque opaque;
} PyCodeAddressRange;
__attribute__ ((visibility ("default"))) int _PyCode_CheckLineNumber(int lasti, PyCodeAddressRange *bounds);
__attribute__ ((visibility ("default"))) PyObject* _PyCode_ConstantKey(PyObject *obj);
__attribute__ ((visibility ("default"))) PyObject* PyCode_Optimize(PyObject *code, PyObject* consts,
                                      PyObject *names, PyObject *lnotab);
__attribute__ ((visibility ("default"))) int PyUnstable_Code_GetExtra(
    PyObject *code, Py_ssize_t index, void **extra);
__attribute__ ((visibility ("default"))) int PyUnstable_Code_SetExtra(
    PyObject *code, Py_ssize_t index, void *extra);
 static inline int
_PyCode_GetExtra(PyObject *code, Py_ssize_t index, void **extra)
{
    return PyUnstable_Code_GetExtra(code, index, extra);
}
 static inline int
_PyCode_SetExtra(PyObject *code, Py_ssize_t index, void *extra)
{
    return PyUnstable_Code_SetExtra(code, index, extra);
}
__attribute__ ((visibility ("default"))) PyObject * PyCode_GetCode(PyCodeObject *code);
__attribute__ ((visibility ("default"))) PyObject * PyCode_GetVarnames(PyCodeObject *code);
__attribute__ ((visibility ("default"))) PyObject * PyCode_GetCellvars(PyCodeObject *code);
__attribute__ ((visibility ("default"))) PyObject * PyCode_GetFreevars(PyCodeObject *code);
typedef enum _PyCodeLocationInfoKind {
    PY_CODE_LOCATION_INFO_SHORT0 = 0,
    PY_CODE_LOCATION_INFO_ONE_LINE0 = 10,
    PY_CODE_LOCATION_INFO_ONE_LINE1 = 11,
    PY_CODE_LOCATION_INFO_ONE_LINE2 = 12,
    PY_CODE_LOCATION_INFO_NO_COLUMNS = 13,
    PY_CODE_LOCATION_INFO_LONG = 14,
    PY_CODE_LOCATION_INFO_NONE = 15
} _PyCodeLocationInfoKind;
__attribute__ ((visibility ("default"))) int PyFrame_GetLineNumber(PyFrameObject *);
__attribute__ ((visibility ("default"))) PyCodeObject * PyFrame_GetCode(PyFrameObject *frame);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyFrame_Type;
__attribute__ ((visibility ("default"))) PyFrameObject * PyFrame_GetBack(PyFrameObject *frame);
__attribute__ ((visibility ("default"))) PyObject * PyFrame_GetLocals(PyFrameObject *frame);
__attribute__ ((visibility ("default"))) PyObject * PyFrame_GetGlobals(PyFrameObject *frame);
__attribute__ ((visibility ("default"))) PyObject * PyFrame_GetBuiltins(PyFrameObject *frame);
__attribute__ ((visibility ("default"))) PyObject * PyFrame_GetGenerator(PyFrameObject *frame);
__attribute__ ((visibility ("default"))) int PyFrame_GetLasti(PyFrameObject *frame);
__attribute__ ((visibility ("default"))) PyObject* PyFrame_GetVar(PyFrameObject *frame, PyObject *name);
__attribute__ ((visibility ("default"))) PyObject* PyFrame_GetVarString(PyFrameObject *frame, const char *name);
struct _PyInterpreterFrame;
__attribute__ ((visibility ("default"))) PyObject * PyUnstable_InterpreterFrame_GetCode(struct _PyInterpreterFrame *frame);
__attribute__ ((visibility ("default"))) int PyUnstable_InterpreterFrame_GetLasti(struct _PyInterpreterFrame *frame);
__attribute__ ((visibility ("default"))) int PyUnstable_InterpreterFrame_GetLine(struct _PyInterpreterFrame *frame);
__attribute__ ((visibility ("default"))) int PyTraceBack_Here(PyFrameObject *);
__attribute__ ((visibility ("default"))) int PyTraceBack_Print(PyObject *, PyObject *);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyTraceBack_Type;
typedef struct _traceback PyTracebackObject;
struct _traceback {
    PyObject ob_base;
    PyTracebackObject *tb_next;
    PyFrameObject *tb_frame;
    int tb_lasti;
    int tb_lineno;
};
__attribute__ ((visibility ("default"))) int _Py_DisplaySourceLine(PyObject *, PyObject *, int, int, int *, PyObject **);
__attribute__ ((visibility ("default"))) void _PyTraceback_Add(const char *, const char *, int);
extern __attribute__ ((visibility ("default"))) PyObject _Py_EllipsisObject;
typedef struct {
    PyObject ob_base;
    PyObject *start, *stop, *step;
} PySliceObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PySlice_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyEllipsis_Type;
__attribute__ ((visibility ("default"))) PyObject * PySlice_New(PyObject* start, PyObject* stop,
                                  PyObject* step);
__attribute__ ((visibility ("default"))) PyObject * _PySlice_FromIndices(Py_ssize_t start, Py_ssize_t stop);
__attribute__ ((visibility ("default"))) int _PySlice_GetLongIndices(PySliceObject *self, PyObject *length,
                                 PyObject **start_ptr, PyObject **stop_ptr,
                                 PyObject **step_ptr);
__attribute__ ((visibility ("default"))) int PySlice_GetIndices(PyObject *r, Py_ssize_t length,
                                  Py_ssize_t *start, Py_ssize_t *stop, Py_ssize_t *step);
__attribute__((__deprecated__))
__attribute__ ((visibility ("default"))) int PySlice_GetIndicesEx(PyObject *r, Py_ssize_t length,
                                     Py_ssize_t *start, Py_ssize_t *stop,
                                     Py_ssize_t *step,
                                     Py_ssize_t *slicelength);
__attribute__ ((visibility ("default"))) int PySlice_Unpack(PyObject *slice,
                               Py_ssize_t *start, Py_ssize_t *stop, Py_ssize_t *step);
__attribute__ ((visibility ("default"))) Py_ssize_t PySlice_AdjustIndices(Py_ssize_t length,
                                             Py_ssize_t *start, Py_ssize_t *stop,
                                             Py_ssize_t step);
typedef struct {
    PyObject ob_base;
    PyObject *ob_ref;
} PyCellObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCell_Type;
__attribute__ ((visibility ("default"))) PyObject * PyCell_New(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyCell_Get(PyObject *);
__attribute__ ((visibility ("default"))) int PyCell_Set(PyObject *, PyObject *);
static inline PyObject* PyCell_GET(PyObject *op) {
    PyCellObject *cell;
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)(((op)))), (&PyCell_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((op)))), (&PyCell_Type))) ; else __assert_fail ("PyCell_Check(op)", "/usr/include/python3.12/cpython/cellobject.h", 26, __extension__ __PRETTY_FUNCTION__); }));
    cell = ((PyCellObject*)(op));
    return cell->ob_ref;
}
static inline void PyCell_SET(PyObject *op, PyObject *value) {
    PyCellObject *cell;
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)(((op)))), (&PyCell_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((op)))), (&PyCell_Type))) ; else __assert_fail ("PyCell_Check(op)", "/usr/include/python3.12/cpython/cellobject.h", 34, __extension__ __PRETTY_FUNCTION__); }));
    cell = ((PyCellObject*)(op));
    cell->ob_ref = value;
}
extern __attribute__ ((visibility ("default"))) PyTypeObject PySeqIter_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCallIter_Type;
extern PyTypeObject _PyAnextAwaitable_Type;
__attribute__ ((visibility ("default"))) PyObject * PySeqIter_New(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyCallIter_New(PyObject *, PyObject *);
typedef struct {
    PyObject ob_base; PyObject *gi_weakreflist; PyObject *gi_name; PyObject *gi_qualname; _PyErr_StackItem gi_exc_state; PyObject *gi_origin_or_finalizer; char gi_hooks_inited; char gi_closed; char gi_running_async; int8_t gi_frame_state; PyObject *gi_iframe[1];
} PyGenObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyGen_Type;
__attribute__ ((visibility ("default"))) PyObject * PyGen_New(PyFrameObject *);
__attribute__ ((visibility ("default"))) PyObject * PyGen_NewWithQualName(PyFrameObject *,
    PyObject *name, PyObject *qualname);
__attribute__ ((visibility ("default"))) int _PyGen_SetStopIterationValue(PyObject *);
__attribute__ ((visibility ("default"))) int _PyGen_FetchStopIterationValue(PyObject **);
__attribute__ ((visibility ("default"))) void _PyGen_Finalize(PyObject *self);
__attribute__ ((visibility ("default"))) PyCodeObject * PyGen_GetCode(PyGenObject *gen);
typedef struct {
    PyObject ob_base; PyObject *cr_weakreflist; PyObject *cr_name; PyObject *cr_qualname; _PyErr_StackItem cr_exc_state; PyObject *cr_origin_or_finalizer; char cr_hooks_inited; char cr_closed; char cr_running_async; int8_t cr_frame_state; PyObject *cr_iframe[1];
} PyCoroObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyCoro_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyCoroWrapper_Type;
__attribute__ ((visibility ("default"))) PyObject * PyCoro_New(PyFrameObject *,
    PyObject *name, PyObject *qualname);
typedef struct {
    PyObject ob_base; PyObject *ag_weakreflist; PyObject *ag_name; PyObject *ag_qualname; _PyErr_StackItem ag_exc_state; PyObject *ag_origin_or_finalizer; char ag_hooks_inited; char ag_closed; char ag_running_async; int8_t ag_frame_state; PyObject *ag_iframe[1];
} PyAsyncGenObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyAsyncGen_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyAsyncGenASend_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyAsyncGenWrappedValue_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyAsyncGenAThrow_Type;
__attribute__ ((visibility ("default"))) PyObject * PyAsyncGen_New(PyFrameObject *,
    PyObject *name, PyObject *qualname);
typedef PyObject *(*getter)(PyObject *, void *);
typedef int (*setter)(PyObject *, PyObject *, void *);
struct PyGetSetDef {
    const char *name;
    getter get;
    setter set;
    const char *doc;
    void *closure;
};
extern __attribute__ ((visibility ("default"))) PyTypeObject PyClassMethodDescr_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyGetSetDescr_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyMemberDescr_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyMethodDescr_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyWrapperDescr_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyDictProxy_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyProperty_Type;
__attribute__ ((visibility ("default"))) PyObject * PyDescr_NewMethod(PyTypeObject *, PyMethodDef *);
__attribute__ ((visibility ("default"))) PyObject * PyDescr_NewClassMethod(PyTypeObject *, PyMethodDef *);
__attribute__ ((visibility ("default"))) PyObject * PyDescr_NewMember(PyTypeObject *, PyMemberDef *);
__attribute__ ((visibility ("default"))) PyObject * PyDescr_NewGetSet(PyTypeObject *, PyGetSetDef *);
__attribute__ ((visibility ("default"))) PyObject * PyDictProxy_New(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyWrapper_New(PyObject *, PyObject *);
struct PyMemberDef {
    const char *name;
    int type;
    Py_ssize_t offset;
    int flags;
    const char *doc;
};
__attribute__ ((visibility ("default"))) PyObject * PyMember_GetOne(const char *, PyMemberDef *);
__attribute__ ((visibility ("default"))) int PyMember_SetOne(char *, PyMemberDef *, PyObject *);
typedef PyObject *(*wrapperfunc)(PyObject *self, PyObject *args,
                                 void *wrapped);
typedef PyObject *(*wrapperfunc_kwds)(PyObject *self, PyObject *args,
                                      void *wrapped, PyObject *kwds);
struct wrapperbase {
    const char *name;
    int offset;
    void *function;
    wrapperfunc wrapper;
    const char *doc;
    int flags;
    PyObject *name_strobj;
};
typedef struct {
    PyObject ob_base;
    PyTypeObject *d_type;
    PyObject *d_name;
    PyObject *d_qualname;
} PyDescrObject;
typedef struct {
    PyDescrObject d_common;
    PyMethodDef *d_method;
    vectorcallfunc vectorcall;
} PyMethodDescrObject;
typedef struct {
    PyDescrObject d_common;
    PyMemberDef *d_member;
} PyMemberDescrObject;
typedef struct {
    PyDescrObject d_common;
    PyGetSetDef *d_getset;
} PyGetSetDescrObject;
typedef struct {
    PyDescrObject d_common;
    struct wrapperbase *d_base;
    void *d_wrapped;
} PyWrapperDescrObject;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyMethodWrapper_Type;
__attribute__ ((visibility ("default"))) PyObject * PyDescr_NewWrapper(PyTypeObject *,
                                                struct wrapperbase *, void *);
__attribute__ ((visibility ("default"))) int PyDescr_IsData(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * Py_GenericAlias(PyObject *, PyObject *);
extern __attribute__ ((visibility ("default"))) PyTypeObject Py_GenericAliasType;
__attribute__ ((visibility ("default"))) int PyErr_WarnEx(
    PyObject *category,
    const char *message,
    Py_ssize_t stack_level);
__attribute__ ((visibility ("default"))) int PyErr_WarnFormat(
    PyObject *category,
    Py_ssize_t stack_level,
    const char *format,
    ...);
__attribute__ ((visibility ("default"))) int PyErr_ResourceWarning(
    PyObject *source,
    Py_ssize_t stack_level,
    const char *format,
    ...);
__attribute__ ((visibility ("default"))) int PyErr_WarnExplicit(
    PyObject *category,
    const char *message,
    const char *filename,
    int lineno,
    const char *module,
    PyObject *registry);
__attribute__ ((visibility ("default"))) int PyErr_WarnExplicitObject(
    PyObject *category,
    PyObject *message,
    PyObject *filename,
    int lineno,
    PyObject *module,
    PyObject *registry);
__attribute__ ((visibility ("default"))) int PyErr_WarnExplicitFormat(
    PyObject *category,
    const char *filename, int lineno,
    const char *module, PyObject *registry,
    const char *format, ...);
typedef struct _PyWeakReference PyWeakReference;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyWeakref_RefType;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyWeakref_ProxyType;
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyWeakref_CallableProxyType;
__attribute__ ((visibility ("default"))) PyObject * PyWeakref_NewRef(PyObject *ob,
                                        PyObject *callback);
__attribute__ ((visibility ("default"))) PyObject * PyWeakref_NewProxy(PyObject *ob,
                                          PyObject *callback);
__attribute__ ((visibility ("default"))) PyObject * PyWeakref_GetObject(PyObject *ref);
struct _PyWeakReference {
    PyObject ob_base;
    PyObject *wr_object;
    PyObject *wr_callback;
    Py_hash_t hash;
    PyWeakReference *wr_prev;
    PyWeakReference *wr_next;
    vectorcallfunc vectorcall;
};
__attribute__ ((visibility ("default"))) Py_ssize_t _PyWeakref_GetWeakrefCount(PyWeakReference *head);
__attribute__ ((visibility ("default"))) void _PyWeakref_ClearRef(PyWeakReference *self);
static inline PyObject* PyWeakref_GET_OBJECT(PyObject *ref_obj) {
    PyWeakReference *ref;
    PyObject *obj;
    ((void) sizeof (((PyObject_TypeCheck(((PyObject*)(((ref_obj)))), (&_PyWeakref_RefType)) || (Py_IS_TYPE(((PyObject*)(((ref_obj)))), (&_PyWeakref_ProxyType)) || Py_IS_TYPE(((PyObject*)(((ref_obj)))), (&_PyWeakref_CallableProxyType))))) ? 1 : 0), __extension__ ({ if ((PyObject_TypeCheck(((PyObject*)(((ref_obj)))), (&_PyWeakref_RefType)) || (Py_IS_TYPE(((PyObject*)(((ref_obj)))), (&_PyWeakref_ProxyType)) || Py_IS_TYPE(((PyObject*)(((ref_obj)))), (&_PyWeakref_CallableProxyType))))) ; else __assert_fail ("PyWeakref_Check(ref_obj)", "/usr/include/python3.12/cpython/weakrefobject.h", 42, __extension__ __PRETTY_FUNCTION__); }));
    ref = ((PyWeakReference*)(ref_obj));
    obj = ref->wr_object;
    if (Py_REFCNT(((PyObject*)((obj)))) > 0) {
        return obj;
    }
    return (&_Py_NoneStruct);
}
typedef struct PyStructSequence_Field {
    const char *name;
    const char *doc;
} PyStructSequence_Field;
typedef struct PyStructSequence_Desc {
    const char *name;
    const char *doc;
    PyStructSequence_Field *fields;
    int n_in_sequence;
} PyStructSequence_Desc;
extern __attribute__ ((visibility ("default"))) const char * const PyStructSequence_UnnamedField;
__attribute__ ((visibility ("default"))) void PyStructSequence_InitType(PyTypeObject *type,
                                           PyStructSequence_Desc *desc);
__attribute__ ((visibility ("default"))) int PyStructSequence_InitType2(PyTypeObject *type,
                                           PyStructSequence_Desc *desc);
__attribute__ ((visibility ("default"))) PyTypeObject* PyStructSequence_NewType(PyStructSequence_Desc *desc);
__attribute__ ((visibility ("default"))) PyObject * PyStructSequence_New(PyTypeObject* type);
typedef PyTupleObject PyStructSequence;
__attribute__ ((visibility ("default"))) void PyStructSequence_SetItem(PyObject*, Py_ssize_t, PyObject*);
__attribute__ ((visibility ("default"))) PyObject* PyStructSequence_GetItem(PyObject*, Py_ssize_t);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyPickleBuffer_Type;
__attribute__ ((visibility ("default"))) PyObject * PyPickleBuffer_FromObject(PyObject *);
__attribute__ ((visibility ("default"))) const Py_buffer * PyPickleBuffer_GetBuffer(PyObject *);
__attribute__ ((visibility ("default"))) int PyPickleBuffer_Release(PyObject *);
typedef int64_t _PyTime_t;
typedef enum {
    _PyTime_ROUND_FLOOR=0,
    _PyTime_ROUND_CEILING=1,
    _PyTime_ROUND_HALF_EVEN=2,
    _PyTime_ROUND_UP=3,
    _PyTime_ROUND_TIMEOUT = _PyTime_ROUND_UP
} _PyTime_round_t;
__attribute__ ((visibility ("default"))) PyObject * _PyLong_FromTime_t(
    time_t sec);
__attribute__ ((visibility ("default"))) time_t _PyLong_AsTime_t(
    PyObject *obj);
__attribute__ ((visibility ("default"))) int _PyTime_ObjectToTime_t(
    PyObject *obj,
    time_t *sec,
    _PyTime_round_t);
__attribute__ ((visibility ("default"))) int _PyTime_ObjectToTimeval(
    PyObject *obj,
    time_t *sec,
    long *usec,
    _PyTime_round_t);
__attribute__ ((visibility ("default"))) int _PyTime_ObjectToTimespec(
    PyObject *obj,
    time_t *sec,
    long *nsec,
    _PyTime_round_t);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_FromSeconds(int seconds);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_FromNanoseconds(_PyTime_t ns);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_FromMicrosecondsClamp(_PyTime_t us);
__attribute__ ((visibility ("default"))) int _PyTime_FromNanosecondsObject(_PyTime_t *t,
    PyObject *obj);
__attribute__ ((visibility ("default"))) int _PyTime_FromSecondsObject(_PyTime_t *t,
    PyObject *obj,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) int _PyTime_FromMillisecondsObject(_PyTime_t *t,
    PyObject *obj,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) double _PyTime_AsSecondsDouble(_PyTime_t t);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_AsMilliseconds(_PyTime_t t,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_AsMicroseconds(_PyTime_t t,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_AsNanoseconds(_PyTime_t t);
__attribute__ ((visibility ("default"))) PyObject * _PyTime_AsNanosecondsObject(_PyTime_t t);
__attribute__ ((visibility ("default"))) int _PyTime_FromTimeval(_PyTime_t *tp, struct timeval *tv);
__attribute__ ((visibility ("default"))) int _PyTime_AsTimeval(_PyTime_t t,
    struct timeval *tv,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) void _PyTime_AsTimeval_clamp(_PyTime_t t,
    struct timeval *tv,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) int _PyTime_AsTimevalTime_t(
    _PyTime_t t,
    time_t *secs,
    int *us,
    _PyTime_round_t round);
__attribute__ ((visibility ("default"))) int _PyTime_FromTimespec(_PyTime_t *tp, struct timespec *ts);
__attribute__ ((visibility ("default"))) int _PyTime_AsTimespec(_PyTime_t t, struct timespec *ts);
__attribute__ ((visibility ("default"))) void _PyTime_AsTimespec_clamp(_PyTime_t t, struct timespec *ts);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_Add(_PyTime_t t1, _PyTime_t t2);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_MulDiv(_PyTime_t ticks,
    _PyTime_t mul,
    _PyTime_t div);
typedef struct {
    const char *implementation;
    int monotonic;
    int adjustable;
    double resolution;
} _Py_clock_info_t;
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_GetSystemClock(void);
__attribute__ ((visibility ("default"))) int _PyTime_GetSystemClockWithInfo(
    _PyTime_t *t,
    _Py_clock_info_t *info);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_GetMonotonicClock(void);
__attribute__ ((visibility ("default"))) int _PyTime_GetMonotonicClockWithInfo(
    _PyTime_t *t,
    _Py_clock_info_t *info);
__attribute__ ((visibility ("default"))) int _PyTime_localtime(time_t t, struct tm *tm);
__attribute__ ((visibility ("default"))) int _PyTime_gmtime(time_t t, struct tm *tm);
__attribute__ ((visibility ("default"))) _PyTime_t _PyTime_GetPerfCounter(void);
__attribute__ ((visibility ("default"))) int _PyTime_GetPerfCounterWithInfo(
    _PyTime_t *t,
    _Py_clock_info_t *info);
__attribute__ ((visibility ("default"))) _PyTime_t _PyDeadline_Init(_PyTime_t timeout);
__attribute__ ((visibility ("default"))) _PyTime_t _PyDeadline_Get(_PyTime_t deadline);
__attribute__ ((visibility ("default"))) int PyCodec_Register(
       PyObject *search_function
       );
__attribute__ ((visibility ("default"))) int PyCodec_Unregister(
       PyObject *search_function
       );
__attribute__ ((visibility ("default"))) PyObject * _PyCodec_Lookup(
       const char *encoding
       );
__attribute__ ((visibility ("default"))) int _PyCodec_Forget(
       const char *encoding
       );
__attribute__ ((visibility ("default"))) int PyCodec_KnownEncoding(
       const char *encoding
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_Encode(
       PyObject *object,
       const char *encoding,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_Decode(
       PyObject *object,
       const char *encoding,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * _PyCodec_LookupTextEncoding(
       const char *encoding,
       const char *alternate_command
       );
__attribute__ ((visibility ("default"))) PyObject * _PyCodec_EncodeText(
       PyObject *object,
       const char *encoding,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * _PyCodec_DecodeText(
       PyObject *object,
       const char *encoding,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * _PyCodecInfo_GetIncrementalDecoder(
       PyObject *codec_info,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * _PyCodecInfo_GetIncrementalEncoder(
       PyObject *codec_info,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_Encoder(
       const char *encoding
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_Decoder(
       const char *encoding
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_IncrementalEncoder(
       const char *encoding,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_IncrementalDecoder(
       const char *encoding,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_StreamReader(
       const char *encoding,
       PyObject *stream,
       const char *errors
       );
__attribute__ ((visibility ("default"))) PyObject * PyCodec_StreamWriter(
       const char *encoding,
       PyObject *stream,
       const char *errors
       );
__attribute__ ((visibility ("default"))) int PyCodec_RegisterError(const char *name, PyObject *error);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_LookupError(const char *name);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_StrictErrors(PyObject *exc);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_IgnoreErrors(PyObject *exc);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_ReplaceErrors(PyObject *exc);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_XMLCharRefReplaceErrors(PyObject *exc);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_BackslashReplaceErrors(PyObject *exc);
__attribute__ ((visibility ("default"))) PyObject * PyCodec_NameReplaceErrors(PyObject *exc);
extern __attribute__ ((visibility ("default"))) const char * Py_hexdigits;
typedef void *PyThread_type_lock;
typedef enum PyLockStatus {
    PY_LOCK_FAILURE = 0,
    PY_LOCK_ACQUIRED = 1,
    PY_LOCK_INTR
} PyLockStatus;
__attribute__ ((visibility ("default"))) void PyThread_init_thread(void);
__attribute__ ((visibility ("default"))) unsigned long PyThread_start_new_thread(void (*)(void *), void *);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) PyThread_exit_thread(void);
__attribute__ ((visibility ("default"))) unsigned long PyThread_get_thread_ident(void);
__attribute__ ((visibility ("default"))) unsigned long PyThread_get_thread_native_id(void);
__attribute__ ((visibility ("default"))) PyThread_type_lock PyThread_allocate_lock(void);
__attribute__ ((visibility ("default"))) void PyThread_free_lock(PyThread_type_lock);
__attribute__ ((visibility ("default"))) int PyThread_acquire_lock(PyThread_type_lock, int);
__attribute__ ((visibility ("default"))) PyLockStatus PyThread_acquire_lock_timed(PyThread_type_lock,
                                                     long long microseconds,
                                                     int intr_flag);
__attribute__ ((visibility ("default"))) void PyThread_release_lock(PyThread_type_lock);
__attribute__ ((visibility ("default"))) size_t PyThread_get_stacksize(void);
__attribute__ ((visibility ("default"))) int PyThread_set_stacksize(size_t);
__attribute__ ((visibility ("default"))) PyObject* PyThread_GetInfo(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) int PyThread_create_key(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyThread_delete_key(int key);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) int PyThread_set_key_value(int key,
                                                          void *value);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void * PyThread_get_key_value(int key);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyThread_delete_key_value(int key);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyThread_ReInitTLS(void);
typedef struct _Py_tss_t Py_tss_t;
__attribute__ ((visibility ("default"))) Py_tss_t * PyThread_tss_alloc(void);
__attribute__ ((visibility ("default"))) void PyThread_tss_free(Py_tss_t *key);
__attribute__ ((visibility ("default"))) int PyThread_tss_is_created(Py_tss_t *key);
__attribute__ ((visibility ("default"))) int PyThread_tss_create(Py_tss_t *key);
__attribute__ ((visibility ("default"))) void PyThread_tss_delete(Py_tss_t *key);
__attribute__ ((visibility ("default"))) int PyThread_tss_set(Py_tss_t *key, void *value);
__attribute__ ((visibility ("default"))) void * PyThread_tss_get(Py_tss_t *key);
__attribute__ ((visibility ("default"))) int _PyThread_at_fork_reinit(PyThread_type_lock *lock);
struct sched_param
{
  int sched_priority;
};

extern int clone (int (*__fn) (void *__arg), void *__child_stack,
    int __flags, void *__arg, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int unshare (int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getcpu (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getcpu (unsigned int *, unsigned int *) __attribute__ ((__nothrow__ , __leaf__));
extern int setns (int __fd, int __nstype) __attribute__ ((__nothrow__ , __leaf__));

typedef unsigned long int __cpu_mask;
typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;

extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
     __attribute__ ((__nothrow__ , __leaf__));
extern cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setscheduler (__pid_t __pid, int __policy,
          const struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_yield (void) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setaffinity (__pid_t __pid, size_t __cpusetsize,
         const cpu_set_t *__cpuset) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getaffinity (__pid_t __pid, size_t __cpusetsize,
         cpu_set_t *__cpuset) __attribute__ ((__nothrow__ , __leaf__));

typedef long int __jmp_buf[8];
struct __jmp_buf_tag
  {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };
enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
};
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum
{
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};
enum
{
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};
enum
{
  PTHREAD_PROCESS_PRIVATE,
  PTHREAD_PROCESS_SHARED
};
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};
enum
{
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};
enum
{
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};

extern int pthread_create (pthread_t *__restrict __newthread,
      const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));
extern int pthread_join (pthread_t __th, void **__thread_return);
extern int pthread_tryjoin_np (pthread_t __th, void **__thread_return) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_timedjoin_np (pthread_t __th, void **__thread_return,
     const struct timespec *__abstime);
extern int pthread_clockjoin_np (pthread_t __th, void **__thread_return,
                                 clockid_t __clockid,
     const struct timespec *__abstime);
extern int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__ , __leaf__));
extern pthread_t pthread_self (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_equal (pthread_t __thread1, pthread_t __thread2)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getguardsize (const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getschedparam (const pthread_attr_t *__restrict __attr,
           struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           const struct sched_param *__restrict
           __param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_getschedpolicy (const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getinheritsched (const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getscope (const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstackaddr (const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));
extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));
extern int pthread_attr_getstacksize (const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstack (const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_setaffinity_np (pthread_attr_t *__attr,
     size_t __cpusetsize,
     const cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_attr_getaffinity_np (const pthread_attr_t *__attr,
     size_t __cpusetsize,
     cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_getattr_default_np (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_setsigmask_np (pthread_attr_t *__attr,
           const __sigset_t *sigmask);
extern int pthread_attr_getsigmask_np (const pthread_attr_t *__attr,
           __sigset_t *sigmask);
extern int pthread_setattr_default_np (const pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_getattr_np (pthread_t __th, pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_getname_np (pthread_t __target_thread, char *__buf,
          size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_setname_np (pthread_t __target_thread, const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_getconcurrency (void) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setconcurrency (int __level) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_yield (void) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_yield (void) __asm__ ("" "sched_yield") __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("pthread_yield is deprecated, use sched_yield instead")));
extern int pthread_setaffinity_np (pthread_t __th, size_t __cpusetsize,
       const cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getaffinity_np (pthread_t __th, size_t __cpusetsize,
       cpu_set_t *__cpuset)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_setcancelstate (int __state, int *__oldstate);
extern int pthread_setcanceltype (int __type, int *__oldtype);
extern int pthread_cancel (pthread_t __th);
extern void pthread_testcancel (void);
struct __cancel_jmp_buf_tag
{
  __jmp_buf __cancel_jmp_buf;
  int __mask_was_saved;
};
typedef struct
{
  struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_register_cancel_defer (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel_restore (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__noreturn__))
     __attribute__ ((__weak__))
     ;
extern int __sigsetjmp_cancel (struct __cancel_jmp_buf_tag __env[1], int __savemask) __asm__ ("" "__sigsetjmp") __attribute__ ((__nothrow__)) __attribute__ ((__returns_twice__));
extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_clocklock (pthread_mutex_t *__restrict __mutex,
        clockid_t __clockid,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_getprioceiling (const pthread_mutex_t *
      __restrict __mutex,
      int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_setprioceiling (pthread_mutex_t *__restrict __mutex,
      int __prioceiling,
      int *__restrict __old_ceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_consistent (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_consistent_np (pthread_mutex_t *) __asm__ ("" "pthread_mutex_consistent") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__deprecated__ ("pthread_mutex_consistent_np is deprecated, use pthread_mutex_consistent")));
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *__restrict
          __attr, int *__restrict __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *
       __restrict __attr,
       int *__restrict __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprotocol (pthread_mutexattr_t *__attr,
       int __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *
          __restrict __attr,
          int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *__attr,
          int __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getrobust (const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_getrobust_np (pthread_mutexattr_t *, int *) __asm__ ("" "pthread_mutexattr_getrobust") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__deprecated__ ("pthread_mutexattr_getrobust_np is deprecated, use pthread_mutexattr_getrobust")));
extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_setrobust_np (pthread_mutexattr_t *, int) __asm__ ("" "pthread_mutexattr_setrobust") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
  __attribute__ ((__deprecated__ ("pthread_mutexattr_setrobust_np is deprecated, use pthread_mutexattr_setrobust")));
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_clockrdlock (pthread_rwlock_t *__restrict __rwlock,
           clockid_t __clockid,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_clockwrlock (pthread_rwlock_t *__restrict __rwlock,
           clockid_t __clockid,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         const pthread_condattr_t *__restrict __cond_attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_cond_clockwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       __clockid_t __clock_id,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 4)));
extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getpshared (const pthread_condattr_t *
     __restrict __attr,
     int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
     int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getclock (const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
        int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setspecific (pthread_key_t __key,
    const void *__pointer)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__access__ (__none__, 2)));
extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__ , __leaf__));

struct _Py_tss_t {
    int _is_initialized;
    pthread_key_t _key;
};
extern __attribute__ ((visibility ("default"))) PyTypeObject PyContext_Type;
typedef struct _pycontextobject PyContext;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyContextVar_Type;
typedef struct _pycontextvarobject PyContextVar;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyContextToken_Type;
typedef struct _pycontexttokenobject PyContextToken;
__attribute__ ((visibility ("default"))) PyObject * PyContext_New(void);
__attribute__ ((visibility ("default"))) PyObject * PyContext_Copy(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyContext_CopyCurrent(void);
__attribute__ ((visibility ("default"))) int PyContext_Enter(PyObject *);
__attribute__ ((visibility ("default"))) int PyContext_Exit(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyContextVar_New(
    const char *name, PyObject *default_value);
__attribute__ ((visibility ("default"))) int PyContextVar_Get(
    PyObject *var, PyObject *default_value, PyObject **value);
__attribute__ ((visibility ("default"))) PyObject * PyContextVar_Set(PyObject *var, PyObject *value);
__attribute__ ((visibility ("default"))) int PyContextVar_Reset(PyObject *var, PyObject *token);
__attribute__ ((visibility ("default"))) PyObject * _PyContext_NewHamtForTests(void);
__attribute__ ((visibility ("default"))) int PyArg_Parse(PyObject *, const char *, ...);
__attribute__ ((visibility ("default"))) int PyArg_ParseTuple(PyObject *, const char *, ...);
__attribute__ ((visibility ("default"))) int PyArg_ParseTupleAndKeywords(PyObject *, PyObject *,
                                                  const char *, char **, ...);
__attribute__ ((visibility ("default"))) int PyArg_VaParse(PyObject *, const char *, va_list);
__attribute__ ((visibility ("default"))) int PyArg_VaParseTupleAndKeywords(PyObject *, PyObject *,
                                                  const char *, char **, va_list);
__attribute__ ((visibility ("default"))) int PyArg_ValidateKeywordArguments(PyObject *);
__attribute__ ((visibility ("default"))) int PyArg_UnpackTuple(PyObject *, const char *, Py_ssize_t, Py_ssize_t, ...);
__attribute__ ((visibility ("default"))) PyObject * Py_BuildValue(const char *, ...);
__attribute__ ((visibility ("default"))) PyObject * _Py_BuildValue_SizeT(const char *, ...);
__attribute__ ((visibility ("default"))) PyObject * Py_VaBuildValue(const char *, va_list);
__attribute__ ((visibility ("default"))) int PyModule_AddObjectRef(PyObject *mod, const char *name, PyObject *value);
__attribute__ ((visibility ("default"))) int PyModule_AddObject(PyObject *mod, const char *, PyObject *value);
__attribute__ ((visibility ("default"))) int PyModule_AddIntConstant(PyObject *, const char *, long);
__attribute__ ((visibility ("default"))) int PyModule_AddStringConstant(PyObject *, const char *, const char *);
__attribute__ ((visibility ("default"))) int PyModule_AddType(PyObject *module, PyTypeObject *type);
__attribute__ ((visibility ("default"))) int PyModule_SetDocString(PyObject *, const char *);
__attribute__ ((visibility ("default"))) int PyModule_AddFunctions(PyObject *, PyMethodDef *);
__attribute__ ((visibility ("default"))) int PyModule_ExecDef(PyObject *module, PyModuleDef *def);
__attribute__ ((visibility ("default"))) PyObject * PyModule_Create2(PyModuleDef*, int apiver);
__attribute__ ((visibility ("default"))) PyObject * PyModule_FromDefAndSpec2(PyModuleDef *def,
                                                PyObject *spec,
                                                int module_api_version);
__attribute__ ((visibility ("default"))) PyObject * _Py_VaBuildValue_SizeT(const char *, va_list);
__attribute__ ((visibility ("default"))) PyObject ** _Py_VaBuildStack_SizeT(
    PyObject **small_stack,
    Py_ssize_t small_stack_len,
    const char *format,
    va_list va,
    Py_ssize_t *p_nargs);
__attribute__ ((visibility ("default"))) int _PyArg_UnpackStack(
    PyObject *const *args,
    Py_ssize_t nargs,
    const char *name,
    Py_ssize_t min,
    Py_ssize_t max,
    ...);
__attribute__ ((visibility ("default"))) int _PyArg_NoKeywords(const char *funcname, PyObject *kwargs);
__attribute__ ((visibility ("default"))) int _PyArg_NoKwnames(const char *funcname, PyObject *kwnames);
__attribute__ ((visibility ("default"))) int _PyArg_NoPositional(const char *funcname, PyObject *args);
__attribute__ ((visibility ("default"))) void _PyArg_BadArgument(const char *, const char *, const char *, PyObject *);
__attribute__ ((visibility ("default"))) int _PyArg_CheckPositional(const char *, Py_ssize_t,
                                       Py_ssize_t, Py_ssize_t);
__attribute__ ((visibility ("default"))) PyObject ** _Py_VaBuildStack(
    PyObject **small_stack,
    Py_ssize_t small_stack_len,
    const char *format,
    va_list va,
    Py_ssize_t *p_nargs);
typedef struct _PyArg_Parser {
    int initialized;
    const char *format;
    const char * const *keywords;
    const char *fname;
    const char *custom_msg;
    int pos;
    int min;
    int max;
    PyObject *kwtuple;
    struct _PyArg_Parser *next;
} _PyArg_Parser;
__attribute__ ((visibility ("default"))) int _PyArg_ParseTupleAndKeywordsFast(PyObject *, PyObject *,
                                                 struct _PyArg_Parser *, ...);
__attribute__ ((visibility ("default"))) int _PyArg_ParseStack(
    PyObject *const *args,
    Py_ssize_t nargs,
    const char *format,
    ...);
__attribute__ ((visibility ("default"))) int _PyArg_ParseStackAndKeywords(
    PyObject *const *args,
    Py_ssize_t nargs,
    PyObject *kwnames,
    struct _PyArg_Parser *,
    ...);
__attribute__ ((visibility ("default"))) int _PyArg_VaParseTupleAndKeywordsFast(PyObject *, PyObject *,
                                                   struct _PyArg_Parser *, va_list);
__attribute__ ((visibility ("default"))) PyObject * const * _PyArg_UnpackKeywords(
        PyObject *const *args, Py_ssize_t nargs,
        PyObject *kwargs, PyObject *kwnames,
        struct _PyArg_Parser *parser,
        int minpos, int maxpos, int minkw,
        PyObject **buf);
__attribute__ ((visibility ("default"))) PyObject * const * _PyArg_UnpackKeywordsWithVararg(
        PyObject *const *args, Py_ssize_t nargs,
        PyObject *kwargs, PyObject *kwnames,
        struct _PyArg_Parser *parser,
        int minpos, int maxpos, int minkw,
        int vararg, PyObject **buf);
__attribute__ ((visibility ("default"))) PyObject * _PyModule_CreateInitialized(PyModuleDef*, int apiver);
__attribute__ ((visibility ("default"))) int _PyModule_Add(PyObject *, const char *, PyObject *);
typedef struct {
    int cf_flags;
    int cf_feature_version;
} PyCompilerFlags;
typedef struct {
    int lineno;
    int end_lineno;
    int col_offset;
    int end_col_offset;
} _PyCompilerSrcLocation;
typedef struct {
    int ff_features;
    _PyCompilerSrcLocation ff_location;
} PyFutureFeatures;
__attribute__ ((visibility ("default"))) int PyCompile_OpcodeStackEffect(int opcode, int oparg);
__attribute__ ((visibility ("default"))) int PyCompile_OpcodeStackEffectWithJump(int opcode, int oparg, int jump);
__attribute__ ((visibility ("default"))) PyObject * Py_CompileString(const char *, const char *, int);
__attribute__ ((visibility ("default"))) void PyErr_Print(void);
__attribute__ ((visibility ("default"))) void PyErr_PrintEx(int);
__attribute__ ((visibility ("default"))) void PyErr_Display(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) void PyErr_DisplayException(PyObject *);
extern __attribute__ ((visibility ("default"))) int (*PyOS_InputHook)(void);
__attribute__ ((visibility ("default"))) int PyRun_SimpleStringFlags(const char *, PyCompilerFlags *);
__attribute__ ((visibility ("default"))) int _PyRun_SimpleFileObject(
    FILE *fp,
    PyObject *filename,
    int closeit,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int PyRun_AnyFileExFlags(
    FILE *fp,
    const char *filename,
    int closeit,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int _PyRun_AnyFileObject(
    FILE *fp,
    PyObject *filename,
    int closeit,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int PyRun_SimpleFileExFlags(
    FILE *fp,
    const char *filename,
    int closeit,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int PyRun_InteractiveOneFlags(
    FILE *fp,
    const char *filename,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int PyRun_InteractiveOneObject(
    FILE *fp,
    PyObject *filename,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int PyRun_InteractiveLoopFlags(
    FILE *fp,
    const char *filename,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) int _PyRun_InteractiveLoopObject(
    FILE *fp,
    PyObject *filename,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) PyObject * PyRun_StringFlags(const char *, int, PyObject *,
                                         PyObject *, PyCompilerFlags *);
__attribute__ ((visibility ("default"))) PyObject * PyRun_FileExFlags(
    FILE *fp,
    const char *filename,
    int start,
    PyObject *globals,
    PyObject *locals,
    int closeit,
    PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) PyObject * Py_CompileStringExFlags(
    const char *str,
    const char *filename,
    int start,
    PyCompilerFlags *flags,
    int optimize);
__attribute__ ((visibility ("default"))) PyObject * Py_CompileStringObject(
    const char *str,
    PyObject *filename, int start,
    PyCompilerFlags *flags,
    int optimize);
__attribute__ ((visibility ("default"))) const char * _Py_SourceAsString(
    PyObject *cmd,
    const char *funcname,
    const char *what,
    PyCompilerFlags *cf,
    PyObject **cmd_copy);
__attribute__ ((visibility ("default"))) PyObject * PyRun_String(const char *str, int s, PyObject *g, PyObject *l);
__attribute__ ((visibility ("default"))) int PyRun_AnyFile(FILE *fp, const char *name);
__attribute__ ((visibility ("default"))) int PyRun_AnyFileEx(FILE *fp, const char *name, int closeit);
__attribute__ ((visibility ("default"))) int PyRun_AnyFileFlags(FILE *, const char *, PyCompilerFlags *);
__attribute__ ((visibility ("default"))) int PyRun_SimpleString(const char *s);
__attribute__ ((visibility ("default"))) int PyRun_SimpleFile(FILE *f, const char *p);
__attribute__ ((visibility ("default"))) int PyRun_SimpleFileEx(FILE *f, const char *p, int c);
__attribute__ ((visibility ("default"))) int PyRun_InteractiveOne(FILE *f, const char *p);
__attribute__ ((visibility ("default"))) int PyRun_InteractiveLoop(FILE *f, const char *p);
__attribute__ ((visibility ("default"))) PyObject * PyRun_File(FILE *fp, const char *p, int s, PyObject *g, PyObject *l);
__attribute__ ((visibility ("default"))) PyObject * PyRun_FileEx(FILE *fp, const char *p, int s, PyObject *g, PyObject *l, int c);
__attribute__ ((visibility ("default"))) PyObject * PyRun_FileFlags(FILE *fp, const char *p, int s, PyObject *g, PyObject *l, PyCompilerFlags *flags);
__attribute__ ((visibility ("default"))) char * PyOS_Readline(FILE *, FILE *, const char *);
extern __attribute__ ((visibility ("default"))) PyThreadState* _PyOS_ReadlineTState;
extern __attribute__ ((visibility ("default"))) char *(*PyOS_ReadlineFunctionPointer)(FILE *, FILE *, const char *);
__attribute__ ((visibility ("default"))) void Py_Initialize(void);
__attribute__ ((visibility ("default"))) void Py_InitializeEx(int);
__attribute__ ((visibility ("default"))) void Py_Finalize(void);
__attribute__ ((visibility ("default"))) int Py_FinalizeEx(void);
__attribute__ ((visibility ("default"))) int Py_IsInitialized(void);
__attribute__ ((visibility ("default"))) PyThreadState * Py_NewInterpreter(void);
__attribute__ ((visibility ("default"))) void Py_EndInterpreter(PyThreadState *);
__attribute__ ((visibility ("default"))) int Py_AtExit(void (*func)(void));
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) Py_Exit(int);
__attribute__ ((visibility ("default"))) int Py_Main(int argc, wchar_t **argv);
__attribute__ ((visibility ("default"))) int Py_BytesMain(int argc, char **argv);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void Py_SetProgramName(const wchar_t *);
__attribute__ ((visibility ("default"))) wchar_t * Py_GetProgramName(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void Py_SetPythonHome(const wchar_t *);
__attribute__ ((visibility ("default"))) wchar_t * Py_GetPythonHome(void);
__attribute__ ((visibility ("default"))) wchar_t * Py_GetProgramFullPath(void);
__attribute__ ((visibility ("default"))) wchar_t * Py_GetPrefix(void);
__attribute__ ((visibility ("default"))) wchar_t * Py_GetExecPrefix(void);
__attribute__ ((visibility ("default"))) wchar_t * Py_GetPath(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void Py_SetPath(const wchar_t *);
__attribute__ ((visibility ("default"))) const char * Py_GetVersion(void);
__attribute__ ((visibility ("default"))) const char * Py_GetPlatform(void);
__attribute__ ((visibility ("default"))) const char * Py_GetCopyright(void);
__attribute__ ((visibility ("default"))) const char * Py_GetCompiler(void);
__attribute__ ((visibility ("default"))) const char * Py_GetBuildInfo(void);
typedef void (*PyOS_sighandler_t)(int);
__attribute__ ((visibility ("default"))) PyOS_sighandler_t PyOS_getsig(int);
__attribute__ ((visibility ("default"))) PyOS_sighandler_t PyOS_setsig(int, PyOS_sighandler_t);
extern __attribute__ ((visibility ("default"))) const unsigned long Py_Version;
__attribute__ ((visibility ("default"))) int Py_FrozenMain(int argc, char **argv);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) int Py_SetStandardStreamEncoding(
    const char *encoding,
    const char *errors);
__attribute__ ((visibility ("default"))) PyStatus Py_PreInitialize(
    const PyPreConfig *src_config);
__attribute__ ((visibility ("default"))) PyStatus Py_PreInitializeFromBytesArgs(
    const PyPreConfig *src_config,
    Py_ssize_t argc,
    char **argv);
__attribute__ ((visibility ("default"))) PyStatus Py_PreInitializeFromArgs(
    const PyPreConfig *src_config,
    Py_ssize_t argc,
    wchar_t **argv);
__attribute__ ((visibility ("default"))) int _Py_IsCoreInitialized(void);
__attribute__ ((visibility ("default"))) PyStatus Py_InitializeFromConfig(
    const PyConfig *config);
__attribute__ ((visibility ("default"))) PyStatus _Py_InitializeMain(void);
__attribute__ ((visibility ("default"))) int Py_RunMain(void);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) Py_ExitStatusException(PyStatus err);
__attribute__ ((visibility ("default"))) void _Py_RestoreSignals(void);
__attribute__ ((visibility ("default"))) int Py_FdIsInteractive(FILE *, const char *);
__attribute__ ((visibility ("default"))) int _Py_FdIsInteractive(FILE *fp, PyObject *filename);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void _Py_SetProgramFullPath(const wchar_t *);
__attribute__ ((visibility ("default"))) const char * _Py_gitidentifier(void);
__attribute__ ((visibility ("default"))) const char * _Py_gitversion(void);
__attribute__ ((visibility ("default"))) int _Py_IsFinalizing(void);
__attribute__ ((visibility ("default"))) int _Py_IsInterpreterFinalizing(PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) int _PyOS_URandom(void *buffer, Py_ssize_t size);
__attribute__ ((visibility ("default"))) int _PyOS_URandomNonblock(void *buffer, Py_ssize_t size);
__attribute__ ((visibility ("default"))) int _Py_CoerceLegacyLocale(int warn);
__attribute__ ((visibility ("default"))) int _Py_LegacyLocaleDetected(int warn);
__attribute__ ((visibility ("default"))) char * _Py_SetLocaleFromEnv(int category);
typedef struct {
    int use_main_obmalloc;
    int allow_fork;
    int allow_exec;
    int allow_threads;
    int allow_daemon_threads;
    int check_multi_interp_extensions;
    int gil;
} PyInterpreterConfig;
__attribute__ ((visibility ("default"))) PyStatus Py_NewInterpreterFromConfig(
    PyThreadState **tstate_p,
    const PyInterpreterConfig *config);
typedef void (*atexit_datacallbackfunc)(void *);
__attribute__ ((visibility ("default"))) int _Py_AtExit(
        PyInterpreterState *, atexit_datacallbackfunc, void *);
__attribute__ ((visibility ("default"))) PyObject * PyEval_EvalCode(PyObject *, PyObject *, PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyEval_EvalCodeEx(PyObject *co,
                                         PyObject *globals,
                                         PyObject *locals,
                                         PyObject *const *args, int argc,
                                         PyObject *const *kwds, int kwdc,
                                         PyObject *const *defs, int defc,
                                         PyObject *kwdefs, PyObject *closure);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject * PyEval_CallObjectWithKeywords(
    PyObject *callable,
    PyObject *args,
    PyObject *kwargs);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject * PyEval_CallFunction(
    PyObject *callable, const char *format, ...);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) PyObject * PyEval_CallMethod(
    PyObject *obj, const char *name, const char *format, ...);
__attribute__ ((visibility ("default"))) PyObject * PyEval_GetBuiltins(void);
__attribute__ ((visibility ("default"))) PyObject * PyEval_GetGlobals(void);
__attribute__ ((visibility ("default"))) PyObject * PyEval_GetLocals(void);
__attribute__ ((visibility ("default"))) PyFrameObject * PyEval_GetFrame(void);
__attribute__ ((visibility ("default"))) int Py_AddPendingCall(int (*func)(void *), void *arg);
__attribute__ ((visibility ("default"))) int Py_MakePendingCalls(void);
__attribute__ ((visibility ("default"))) void Py_SetRecursionLimit(int);
__attribute__ ((visibility ("default"))) int Py_GetRecursionLimit(void);
__attribute__ ((visibility ("default"))) int Py_EnterRecursiveCall(const char *where);
__attribute__ ((visibility ("default"))) void Py_LeaveRecursiveCall(void);
__attribute__ ((visibility ("default"))) const char * PyEval_GetFuncName(PyObject *);
__attribute__ ((visibility ("default"))) const char * PyEval_GetFuncDesc(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyEval_EvalFrame(PyFrameObject *);
__attribute__ ((visibility ("default"))) PyObject * PyEval_EvalFrameEx(PyFrameObject *f, int exc);
__attribute__ ((visibility ("default"))) PyThreadState * PyEval_SaveThread(void);
__attribute__ ((visibility ("default"))) void PyEval_RestoreThread(PyThreadState *);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) int PyEval_ThreadsInitialized(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyEval_InitThreads(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyEval_AcquireLock(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyEval_ReleaseLock(void);
__attribute__ ((visibility ("default"))) void PyEval_AcquireThread(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void PyEval_ReleaseThread(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void PyEval_SetProfile(Py_tracefunc, PyObject *);
__attribute__ ((visibility ("default"))) void PyEval_SetProfileAllThreads(Py_tracefunc, PyObject *);
extern __attribute__ ((visibility ("default"))) int _PyEval_SetProfile(PyThreadState *tstate, Py_tracefunc func, PyObject *arg);
__attribute__ ((visibility ("default"))) void PyEval_SetTrace(Py_tracefunc, PyObject *);
__attribute__ ((visibility ("default"))) void PyEval_SetTraceAllThreads(Py_tracefunc, PyObject *);
__attribute__ ((visibility ("default"))) int _PyEval_SetTrace(PyThreadState *tstate, Py_tracefunc func, PyObject *arg);
__attribute__ ((visibility ("default"))) PyObject * _PyEval_GetBuiltin(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyEval_GetBuiltinId(_Py_Identifier *);
__attribute__ ((visibility ("default"))) int PyEval_MergeCompilerFlags(PyCompilerFlags *cf);
__attribute__ ((visibility ("default"))) PyObject * _PyEval_EvalFrameDefault(PyThreadState *tstate, struct _PyInterpreterFrame *f, int exc);
__attribute__ ((visibility ("default"))) void _PyEval_SetSwitchInterval(unsigned long microseconds);
__attribute__ ((visibility ("default"))) unsigned long _PyEval_GetSwitchInterval(void);
__attribute__ ((visibility ("default"))) int _PyEval_MakePendingCalls(PyThreadState *);
__attribute__ ((visibility ("default"))) Py_ssize_t PyUnstable_Eval_RequestCodeExtraIndex(freefunc);
 static inline Py_ssize_t
_PyEval_RequestCodeExtraIndex(freefunc f) {
    return PyUnstable_Eval_RequestCodeExtraIndex(f);
}
__attribute__ ((visibility ("default"))) int _PyEval_SliceIndex(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) int _PyEval_SliceIndexNotNone(PyObject *, Py_ssize_t *);
__attribute__ ((visibility ("default"))) PyObject * PySys_GetObject(const char *);
__attribute__ ((visibility ("default"))) int PySys_SetObject(const char *, PyObject *);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PySys_SetArgv(int, wchar_t **);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PySys_SetArgvEx(int, wchar_t **, int);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PySys_SetPath(const wchar_t *);
__attribute__ ((visibility ("default"))) void PySys_WriteStdout(const char *format, ...)
                 __attribute__((format(printf, 1, 2)));
__attribute__ ((visibility ("default"))) void PySys_WriteStderr(const char *format, ...)
                 __attribute__((format(printf, 1, 2)));
__attribute__ ((visibility ("default"))) void PySys_FormatStdout(const char *format, ...);
__attribute__ ((visibility ("default"))) void PySys_FormatStderr(const char *format, ...);
__attribute__ ((visibility ("default"))) void PySys_ResetWarnOptions(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PySys_AddWarnOption(const wchar_t *);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PySys_AddWarnOptionUnicode(PyObject *);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) int PySys_HasWarnOptions(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PySys_AddXOption(const wchar_t *);
__attribute__ ((visibility ("default"))) PyObject * PySys_GetXOptions(void);
typedef struct {
    FILE* perf_map;
    PyThread_type_lock map_lock;
} PerfMapState;
__attribute__ ((visibility ("default"))) int PyUnstable_PerfMapState_Init(void);
__attribute__ ((visibility ("default"))) int PyUnstable_WritePerfMapEntry(const void *code_addr, unsigned int code_size, const char *entry_name);
__attribute__ ((visibility ("default"))) void PyUnstable_PerfMapState_Fini(void);
__attribute__ ((visibility ("default"))) PyObject * _PySys_GetAttr(PyThreadState *tstate,
                                      PyObject *name);
__attribute__ ((visibility ("default"))) size_t _PySys_GetSizeOf(PyObject *);
typedef int(*Py_AuditHookFunction)(const char *, PyObject *, void *);
__attribute__ ((visibility ("default"))) int PySys_Audit(
    const char *event,
    const char *argFormat,
    ...);
__attribute__ ((visibility ("default"))) int PySys_AddAuditHook(Py_AuditHookFunction, void*);
__attribute__ ((visibility ("default"))) PyObject * PyOS_FSPath(PyObject *path);
__attribute__ ((visibility ("default"))) int PyOS_InterruptOccurred(void);
__attribute__ ((visibility ("default"))) void PyOS_BeforeFork(void);
__attribute__ ((visibility ("default"))) void PyOS_AfterFork_Parent(void);
__attribute__ ((visibility ("default"))) void PyOS_AfterFork_Child(void);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) void PyOS_AfterFork(void);
__attribute__ ((visibility ("default"))) int _PyOS_IsMainThread(void);
__attribute__ ((visibility ("default"))) long PyImport_GetMagicNumber(void);
__attribute__ ((visibility ("default"))) const char * PyImport_GetMagicTag(void);
__attribute__ ((visibility ("default"))) PyObject * PyImport_ExecCodeModule(
    const char *name,
    PyObject *co
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ExecCodeModuleEx(
    const char *name,
    PyObject *co,
    const char *pathname
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ExecCodeModuleWithPathnames(
    const char *name,
    PyObject *co,
    const char *pathname,
    const char *cpathname
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ExecCodeModuleObject(
    PyObject *name,
    PyObject *co,
    PyObject *pathname,
    PyObject *cpathname
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_GetModuleDict(void);
__attribute__ ((visibility ("default"))) PyObject * PyImport_GetModule(PyObject *name);
__attribute__ ((visibility ("default"))) PyObject * PyImport_AddModuleObject(
    PyObject *name
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_AddModule(
    const char *name
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ImportModule(
    const char *name
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ImportModuleNoBlock(
    const char *name
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ImportModuleLevel(
    const char *name,
    PyObject *globals,
    PyObject *locals,
    PyObject *fromlist,
    int level
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_ImportModuleLevelObject(
    PyObject *name,
    PyObject *globals,
    PyObject *locals,
    PyObject *fromlist,
    int level
    );
__attribute__ ((visibility ("default"))) PyObject * PyImport_GetImporter(PyObject *path);
__attribute__ ((visibility ("default"))) PyObject * PyImport_Import(PyObject *name);
__attribute__ ((visibility ("default"))) PyObject * PyImport_ReloadModule(PyObject *m);
__attribute__ ((visibility ("default"))) int PyImport_ImportFrozenModuleObject(
    PyObject *name
    );
__attribute__ ((visibility ("default"))) int PyImport_ImportFrozenModule(
    const char *name
    );
__attribute__ ((visibility ("default"))) int PyImport_AppendInittab(
    const char *name,
    PyObject* (*initfunc)(void)
    );
__attribute__ ((visibility ("default"))) PyObject* PyInit__imp(void);
__attribute__ ((visibility ("default"))) int _PyImport_IsInitialized(PyInterpreterState *);
__attribute__ ((visibility ("default"))) PyObject * _PyImport_GetModuleId(_Py_Identifier *name);
__attribute__ ((visibility ("default"))) int _PyImport_SetModule(PyObject *name, PyObject *module);
__attribute__ ((visibility ("default"))) int _PyImport_SetModuleString(const char *name, PyObject* module);
__attribute__ ((visibility ("default"))) void _PyImport_AcquireLock(PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) int _PyImport_ReleaseLock(PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) int _PyImport_FixupBuiltin(
    PyObject *mod,
    const char *name,
    PyObject *modules
    );
__attribute__ ((visibility ("default"))) int _PyImport_FixupExtensionObject(PyObject*, PyObject *,
                                               PyObject *, PyObject *);
struct _inittab {
    const char *name;
    PyObject* (*initfunc)(void);
};
extern __attribute__ ((visibility ("default"))) struct _inittab * PyImport_Inittab;
__attribute__ ((visibility ("default"))) int PyImport_ExtendInittab(struct _inittab *newtab);
struct _frozen {
    const char *name;
    const unsigned char *code;
    int size;
    int is_package;
    PyObject *(*get_code)(void);
};
extern __attribute__ ((visibility ("default"))) const struct _frozen * PyImport_FrozenModules;
extern __attribute__ ((visibility ("default"))) PyObject * _PyImport_GetModuleAttr(PyObject *, PyObject *);
extern __attribute__ ((visibility ("default"))) PyObject * _PyImport_GetModuleAttrString(const char *, const char *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallNoArgs(PyObject *func);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Call(PyObject *callable,
                                     PyObject *args, PyObject *kwargs);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallObject(PyObject *callable,
                                           PyObject *args);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallFunction(PyObject *callable,
                                             const char *format, ...);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallMethod(PyObject *obj,
                                           const char *name,
                                           const char *format, ...);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_CallFunction_SizeT(PyObject *callable,
                                                    const char *format,
                                                    ...);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_CallMethod_SizeT(PyObject *obj,
                                                  const char *name,
                                                  const char *format,
                                                  ...);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallFunctionObjArgs(PyObject *callable,
                                                    ...);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallMethodObjArgs(
    PyObject *obj,
    PyObject *name,
    ...);
__attribute__ ((visibility ("default"))) Py_ssize_t PyVectorcall_NARGS(size_t nargsf);
__attribute__ ((visibility ("default"))) PyObject * PyVectorcall_Call(PyObject *callable, PyObject *tuple, PyObject *dict);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Vectorcall(
    PyObject *callable,
    PyObject *const *args,
    size_t nargsf,
    PyObject *kwnames);
__attribute__ ((visibility ("default"))) PyObject * PyObject_VectorcallMethod(
    PyObject *name, PyObject *const *args,
    size_t nargsf, PyObject *kwnames);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Type(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PyObject_Size(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PyObject_Length(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GetItem(PyObject *o, PyObject *key);
__attribute__ ((visibility ("default"))) int PyObject_SetItem(PyObject *o, PyObject *key, PyObject *v);
__attribute__ ((visibility ("default"))) int PyObject_DelItemString(PyObject *o, const char *key);
__attribute__ ((visibility ("default"))) int PyObject_DelItem(PyObject *o, PyObject *key);
__attribute__((__deprecated__))
__attribute__ ((visibility ("default"))) int PyObject_AsCharBuffer(PyObject *obj,
                                      const char **buffer,
                                      Py_ssize_t *buffer_len);
__attribute__((__deprecated__)) __attribute__ ((visibility ("default"))) int PyObject_CheckReadBuffer(PyObject *obj);
__attribute__((__deprecated__))
__attribute__ ((visibility ("default"))) int PyObject_AsReadBuffer(PyObject *obj,
                                      const void **buffer,
                                      Py_ssize_t *buffer_len);
__attribute__((__deprecated__))
__attribute__ ((visibility ("default"))) int PyObject_AsWriteBuffer(PyObject *obj,
                                       void **buffer,
                                       Py_ssize_t *buffer_len);
__attribute__ ((visibility ("default"))) PyObject * PyObject_Format(PyObject *obj,
                                       PyObject *format_spec);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GetIter(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyObject_GetAIter(PyObject *);
__attribute__ ((visibility ("default"))) int PyIter_Check(PyObject *);
__attribute__ ((visibility ("default"))) int PyAIter_Check(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyIter_Next(PyObject *);
__attribute__ ((visibility ("default"))) PySendResult PyIter_Send(PyObject *, PyObject *, PyObject **);
__attribute__ ((visibility ("default"))) int PyNumber_Check(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Add(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Subtract(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Multiply(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_MatrixMultiply(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_FloorDivide(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_TrueDivide(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Remainder(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Divmod(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Power(PyObject *o1, PyObject *o2,
                                      PyObject *o3);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Negative(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Positive(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Absolute(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Invert(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Lshift(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Rshift(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_And(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Xor(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Or(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) int PyIndex_Check(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Index(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PyNumber_AsSsize_t(PyObject *o, PyObject *exc);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Long(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_Float(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceAdd(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceSubtract(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceMultiply(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceMatrixMultiply(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceFloorDivide(PyObject *o1,
                                                   PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceTrueDivide(PyObject *o1,
                                                  PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceRemainder(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlacePower(PyObject *o1, PyObject *o2,
                                             PyObject *o3);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceLshift(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceRshift(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceAnd(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceXor(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_InPlaceOr(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PyNumber_ToBase(PyObject *n, int base);
__attribute__ ((visibility ("default"))) int PySequence_Check(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PySequence_Size(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PySequence_Length(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PySequence_Concat(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PySequence_Repeat(PyObject *o, Py_ssize_t count);
__attribute__ ((visibility ("default"))) PyObject * PySequence_GetItem(PyObject *o, Py_ssize_t i);
__attribute__ ((visibility ("default"))) PyObject * PySequence_GetSlice(PyObject *o, Py_ssize_t i1, Py_ssize_t i2);
__attribute__ ((visibility ("default"))) int PySequence_SetItem(PyObject *o, Py_ssize_t i, PyObject *v);
__attribute__ ((visibility ("default"))) int PySequence_DelItem(PyObject *o, Py_ssize_t i);
__attribute__ ((visibility ("default"))) int PySequence_SetSlice(PyObject *o, Py_ssize_t i1, Py_ssize_t i2,
                                    PyObject *v);
__attribute__ ((visibility ("default"))) int PySequence_DelSlice(PyObject *o, Py_ssize_t i1, Py_ssize_t i2);
__attribute__ ((visibility ("default"))) PyObject * PySequence_Tuple(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PySequence_List(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PySequence_Fast(PyObject *o, const char* m);
__attribute__ ((visibility ("default"))) Py_ssize_t PySequence_Count(PyObject *o, PyObject *value);
__attribute__ ((visibility ("default"))) int PySequence_Contains(PyObject *seq, PyObject *ob);
__attribute__ ((visibility ("default"))) int PySequence_In(PyObject *o, PyObject *value);
__attribute__ ((visibility ("default"))) Py_ssize_t PySequence_Index(PyObject *o, PyObject *value);
__attribute__ ((visibility ("default"))) PyObject * PySequence_InPlaceConcat(PyObject *o1, PyObject *o2);
__attribute__ ((visibility ("default"))) PyObject * PySequence_InPlaceRepeat(PyObject *o, Py_ssize_t count);
__attribute__ ((visibility ("default"))) int PyMapping_Check(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PyMapping_Size(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PyMapping_Length(PyObject *o);
__attribute__ ((visibility ("default"))) int PyMapping_HasKeyString(PyObject *o, const char *key);
__attribute__ ((visibility ("default"))) int PyMapping_HasKey(PyObject *o, PyObject *key);
__attribute__ ((visibility ("default"))) PyObject * PyMapping_Keys(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyMapping_Values(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyMapping_Items(PyObject *o);
__attribute__ ((visibility ("default"))) PyObject * PyMapping_GetItemString(PyObject *o,
                                               const char *key);
__attribute__ ((visibility ("default"))) int PyMapping_SetItemString(PyObject *o, const char *key,
                                        PyObject *value);
__attribute__ ((visibility ("default"))) int PyObject_IsInstance(PyObject *object, PyObject *typeorclass);
__attribute__ ((visibility ("default"))) int PyObject_IsSubclass(PyObject *object, PyObject *typeorclass);
__attribute__ ((visibility ("default"))) PyObject * _PyStack_AsDict(
    PyObject *const *values,
    PyObject *kwnames);
__attribute__ ((visibility ("default"))) PyObject * _Py_CheckFunctionResult(
    PyThreadState *tstate,
    PyObject *callable,
    PyObject *result,
    const char *where);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_MakeTpCall(
    PyThreadState *tstate,
    PyObject *callable,
    PyObject *const *args, Py_ssize_t nargs,
    PyObject *keywords);
static inline Py_ssize_t
_PyVectorcall_NARGS(size_t n)
{
    return n & ~(((size_t)(1)) << (8 * sizeof(size_t) - 1));
}
__attribute__ ((visibility ("default"))) vectorcallfunc PyVectorcall_Function(PyObject *callable);
__attribute__ ((visibility ("default"))) PyObject * PyObject_VectorcallDict(
    PyObject *callable,
    PyObject *const *args,
    size_t nargsf,
    PyObject *kwargs);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_FastCall(
    PyObject *func,
    PyObject *const *args,
    Py_ssize_t nargs);
__attribute__ ((visibility ("default"))) PyObject * PyObject_CallOneArg(PyObject *func, PyObject *arg);
static inline PyObject *
PyObject_CallMethodNoArgs(PyObject *self, PyObject *name)
{
    size_t nargsf = 1 | (((size_t)(1)) << (8 * sizeof(size_t) - 1));
    return PyObject_VectorcallMethod(name, &self, nargsf, ((void *)0));
}
static inline PyObject *
PyObject_CallMethodOneArg(PyObject *self, PyObject *name, PyObject *arg)
{
    PyObject *args[2] = {self, arg};
    size_t nargsf = 2 | (((size_t)(1)) << (8 * sizeof(size_t) - 1));
    ((void) sizeof ((arg != ((void *)0)) ? 1 : 0), __extension__ ({ if (arg != ((void *)0)) ; else __assert_fail ("arg != NULL", "/usr/include/python3.12/cpython/abstract.h", 102, __extension__ __PRETTY_FUNCTION__); }));
    return PyObject_VectorcallMethod(name, args, nargsf, ((void *)0));
}
__attribute__ ((visibility ("default"))) PyObject * _PyObject_CallMethod(PyObject *obj,
                                            PyObject *name,
                                            const char *format, ...);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_CallMethodId(PyObject *obj,
                                              _Py_Identifier *name,
                                              const char *format, ...);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_CallMethodId_SizeT(PyObject *obj,
                                                    _Py_Identifier *name,
                                                    const char *format,
                                                    ...);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_CallMethodIdObjArgs(
    PyObject *obj,
    _Py_Identifier *name,
    ...);
static inline PyObject *
_PyObject_VectorcallMethodId(
    _Py_Identifier *name, PyObject *const *args,
    size_t nargsf, PyObject *kwnames)
{
    PyObject *oname = _PyUnicode_FromId(name);
    if (!oname) {
        return ((void *)0);
    }
    return PyObject_VectorcallMethod(oname, args, nargsf, kwnames);
}
static inline PyObject *
_PyObject_CallMethodIdNoArgs(PyObject *self, _Py_Identifier *name)
{
    size_t nargsf = 1 | (((size_t)(1)) << (8 * sizeof(size_t) - 1));
    return _PyObject_VectorcallMethodId(name, &self, nargsf, ((void *)0));
}
static inline PyObject *
_PyObject_CallMethodIdOneArg(PyObject *self, _Py_Identifier *name, PyObject *arg)
{
    PyObject *args[2] = {self, arg};
    size_t nargsf = 2 | (((size_t)(1)) << (8 * sizeof(size_t) - 1));
    ((void) sizeof ((arg != ((void *)0)) ? 1 : 0), __extension__ ({ if (arg != ((void *)0)) ; else __assert_fail ("arg != NULL", "/usr/include/python3.12/cpython/abstract.h", 150, __extension__ __PRETTY_FUNCTION__); }));
    return _PyObject_VectorcallMethodId(name, args, nargsf, ((void *)0));
}
__attribute__ ((visibility ("default"))) int _PyObject_HasLen(PyObject *o);
__attribute__ ((visibility ("default"))) Py_ssize_t PyObject_LengthHint(PyObject *o, Py_ssize_t);
__attribute__ ((visibility ("default"))) Py_ssize_t _PySequence_IterSearch(PyObject *seq,
                                              PyObject *obj, int operation);
__attribute__ ((visibility ("default"))) int _PyObject_RealIsInstance(PyObject *inst, PyObject *cls);
__attribute__ ((visibility ("default"))) int _PyObject_RealIsSubclass(PyObject *derived, PyObject *cls);
__attribute__ ((visibility ("default"))) char *const * _PySequence_BytesToCharpArray(PyObject* self);
__attribute__ ((visibility ("default"))) void _Py_FreeCharPArray(char *const array[]);
__attribute__ ((visibility ("default"))) void _Py_add_one_to_index_F(int nd, Py_ssize_t *index,
                                        const Py_ssize_t *shape);
__attribute__ ((visibility ("default"))) void _Py_add_one_to_index_C(int nd, Py_ssize_t *index,
                                        const Py_ssize_t *shape);
__attribute__ ((visibility ("default"))) int _Py_convert_optional_to_ssize_t(PyObject *, void *);
__attribute__ ((visibility ("default"))) PyObject * _PyNumber_Index(PyObject *o);
extern __attribute__ ((visibility ("default"))) PyTypeObject PyFilter_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyMap_Type;
extern __attribute__ ((visibility ("default"))) PyTypeObject PyZip_Type;
extern __attribute__ ((visibility ("default"))) const unsigned int _Py_ctype_table[256];
extern __attribute__ ((visibility ("default"))) const unsigned char _Py_ctype_tolower[256];
extern __attribute__ ((visibility ("default"))) const unsigned char _Py_ctype_toupper[256];
__attribute__ ((visibility ("default"))) double PyOS_string_to_double(const char *str,
                                         char **endptr,
                                         PyObject *overflow_exception);
__attribute__ ((visibility ("default"))) char * PyOS_double_to_string(double val,
                                         char format_code,
                                         int precision,
                                         int flags,
                                         int *type);
__attribute__ ((visibility ("default"))) PyObject * _Py_string_to_number_with_underscores(
    const char *str, Py_ssize_t len, const char *what, PyObject *obj, void *arg,
    PyObject *(*innerfunc)(const char *, Py_ssize_t, void *));
__attribute__ ((visibility ("default"))) double _Py_parse_inf_or_nan(const char *p, char **endptr);
__attribute__ ((visibility ("default"))) int PyOS_mystrnicmp(const char *, const char *, Py_ssize_t);
__attribute__ ((visibility ("default"))) int PyOS_mystricmp(const char *, const char *);
__attribute__ ((visibility ("default"))) wchar_t * Py_DecodeLocale(
    const char *arg,
    size_t *size);
__attribute__ ((visibility ("default"))) char* Py_EncodeLocale(
    const wchar_t *text,
    size_t *error_pos);
__attribute__ ((visibility ("default"))) FILE* _Py_fopen_obj(
    PyObject *path,
    const char *mode);
__attribute__ ((visibility ("default"))) int PyTraceMalloc_Track(
    unsigned int domain,
    uintptr_t ptr,
    size_t size);
__attribute__ ((visibility ("default"))) int PyTraceMalloc_Untrack(
    unsigned int domain,
    uintptr_t ptr);
__attribute__ ((visibility ("default"))) PyObject* _PyTraceMalloc_GetTraceback(
    unsigned int domain,
    uintptr_t ptr);
__attribute__ ((visibility ("default"))) int _PyTraceMalloc_IsTracing(void);
__attribute__ ((visibility ("default"))) void _PyTraceMalloc_ClearTraces(void);
__attribute__ ((visibility ("default"))) PyObject * _PyTraceMalloc_GetTraces(void);
__attribute__ ((visibility ("default"))) PyObject * _PyTraceMalloc_GetObjectTraceback(PyObject *obj);
__attribute__ ((visibility ("default"))) int _PyTraceMalloc_Init(void);
__attribute__ ((visibility ("default"))) int _PyTraceMalloc_Start(int max_nframe);
__attribute__ ((visibility ("default"))) void _PyTraceMalloc_Stop(void);
__attribute__ ((visibility ("default"))) int _PyTraceMalloc_GetTracebackLimit(void);
__attribute__ ((visibility ("default"))) size_t _PyTraceMalloc_GetMemory(void);
__attribute__ ((visibility ("default"))) PyObject * _PyTraceMalloc_GetTracedMemory(void);
__attribute__ ((visibility ("default"))) void _PyTraceMalloc_ResetPeak(void);
static inline int
_PyIndex_Check(PyObject *obj)
{
    PyNumberMethods *tp_as_number = Py_TYPE(((PyObject*)((obj))))->tp_as_number;
    return (tp_as_number != ((void *)0) && tp_as_number->nb_index != ((void *)0));
}
PyObject *_PyNumber_PowerNoMod(PyObject *lhs, PyObject *rhs);
PyObject *_PyNumber_InPlacePowerNoMod(PyObject *lhs, PyObject *rhs);
struct ast_state {
    int initialized;
    int unused_recursion_depth;
    int unused_recursion_limit;
    PyObject *AST_type;
    PyObject *Add_singleton;
    PyObject *Add_type;
    PyObject *And_singleton;
    PyObject *And_type;
    PyObject *AnnAssign_type;
    PyObject *Assert_type;
    PyObject *Assign_type;
    PyObject *AsyncFor_type;
    PyObject *AsyncFunctionDef_type;
    PyObject *AsyncWith_type;
    PyObject *Attribute_type;
    PyObject *AugAssign_type;
    PyObject *Await_type;
    PyObject *BinOp_type;
    PyObject *BitAnd_singleton;
    PyObject *BitAnd_type;
    PyObject *BitOr_singleton;
    PyObject *BitOr_type;
    PyObject *BitXor_singleton;
    PyObject *BitXor_type;
    PyObject *BoolOp_type;
    PyObject *Break_type;
    PyObject *Call_type;
    PyObject *ClassDef_type;
    PyObject *Compare_type;
    PyObject *Constant_type;
    PyObject *Continue_type;
    PyObject *Del_singleton;
    PyObject *Del_type;
    PyObject *Delete_type;
    PyObject *DictComp_type;
    PyObject *Dict_type;
    PyObject *Div_singleton;
    PyObject *Div_type;
    PyObject *Eq_singleton;
    PyObject *Eq_type;
    PyObject *ExceptHandler_type;
    PyObject *Expr_type;
    PyObject *Expression_type;
    PyObject *FloorDiv_singleton;
    PyObject *FloorDiv_type;
    PyObject *For_type;
    PyObject *FormattedValue_type;
    PyObject *FunctionDef_type;
    PyObject *FunctionType_type;
    PyObject *GeneratorExp_type;
    PyObject *Global_type;
    PyObject *GtE_singleton;
    PyObject *GtE_type;
    PyObject *Gt_singleton;
    PyObject *Gt_type;
    PyObject *IfExp_type;
    PyObject *If_type;
    PyObject *ImportFrom_type;
    PyObject *Import_type;
    PyObject *In_singleton;
    PyObject *In_type;
    PyObject *Interactive_type;
    PyObject *Invert_singleton;
    PyObject *Invert_type;
    PyObject *IsNot_singleton;
    PyObject *IsNot_type;
    PyObject *Is_singleton;
    PyObject *Is_type;
    PyObject *JoinedStr_type;
    PyObject *LShift_singleton;
    PyObject *LShift_type;
    PyObject *Lambda_type;
    PyObject *ListComp_type;
    PyObject *List_type;
    PyObject *Load_singleton;
    PyObject *Load_type;
    PyObject *LtE_singleton;
    PyObject *LtE_type;
    PyObject *Lt_singleton;
    PyObject *Lt_type;
    PyObject *MatMult_singleton;
    PyObject *MatMult_type;
    PyObject *MatchAs_type;
    PyObject *MatchClass_type;
    PyObject *MatchMapping_type;
    PyObject *MatchOr_type;
    PyObject *MatchSequence_type;
    PyObject *MatchSingleton_type;
    PyObject *MatchStar_type;
    PyObject *MatchValue_type;
    PyObject *Match_type;
    PyObject *Mod_singleton;
    PyObject *Mod_type;
    PyObject *Module_type;
    PyObject *Mult_singleton;
    PyObject *Mult_type;
    PyObject *Name_type;
    PyObject *NamedExpr_type;
    PyObject *Nonlocal_type;
    PyObject *NotEq_singleton;
    PyObject *NotEq_type;
    PyObject *NotIn_singleton;
    PyObject *NotIn_type;
    PyObject *Not_singleton;
    PyObject *Not_type;
    PyObject *Or_singleton;
    PyObject *Or_type;
    PyObject *ParamSpec_type;
    PyObject *Pass_type;
    PyObject *Pow_singleton;
    PyObject *Pow_type;
    PyObject *RShift_singleton;
    PyObject *RShift_type;
    PyObject *Raise_type;
    PyObject *Return_type;
    PyObject *SetComp_type;
    PyObject *Set_type;
    PyObject *Slice_type;
    PyObject *Starred_type;
    PyObject *Store_singleton;
    PyObject *Store_type;
    PyObject *Sub_singleton;
    PyObject *Sub_type;
    PyObject *Subscript_type;
    PyObject *TryStar_type;
    PyObject *Try_type;
    PyObject *Tuple_type;
    PyObject *TypeAlias_type;
    PyObject *TypeIgnore_type;
    PyObject *TypeVarTuple_type;
    PyObject *TypeVar_type;
    PyObject *UAdd_singleton;
    PyObject *UAdd_type;
    PyObject *USub_singleton;
    PyObject *USub_type;
    PyObject *UnaryOp_type;
    PyObject *While_type;
    PyObject *With_type;
    PyObject *YieldFrom_type;
    PyObject *Yield_type;
    PyObject *__dict__;
    PyObject *__doc__;
    PyObject *__match_args__;
    PyObject *__module__;
    PyObject *_attributes;
    PyObject *_fields;
    PyObject *alias_type;
    PyObject *annotation;
    PyObject *arg;
    PyObject *arg_type;
    PyObject *args;
    PyObject *argtypes;
    PyObject *arguments_type;
    PyObject *asname;
    PyObject *ast;
    PyObject *attr;
    PyObject *bases;
    PyObject *body;
    PyObject *boolop_type;
    PyObject *bound;
    PyObject *cases;
    PyObject *cause;
    PyObject *cls;
    PyObject *cmpop_type;
    PyObject *col_offset;
    PyObject *comparators;
    PyObject *comprehension_type;
    PyObject *context_expr;
    PyObject *conversion;
    PyObject *ctx;
    PyObject *decorator_list;
    PyObject *defaults;
    PyObject *elt;
    PyObject *elts;
    PyObject *end_col_offset;
    PyObject *end_lineno;
    PyObject *exc;
    PyObject *excepthandler_type;
    PyObject *expr_context_type;
    PyObject *expr_type;
    PyObject *finalbody;
    PyObject *format_spec;
    PyObject *func;
    PyObject *generators;
    PyObject *guard;
    PyObject *handlers;
    PyObject *id;
    PyObject *ifs;
    PyObject *is_async;
    PyObject *items;
    PyObject *iter;
    PyObject *key;
    PyObject *keys;
    PyObject *keyword_type;
    PyObject *keywords;
    PyObject *kind;
    PyObject *kw_defaults;
    PyObject *kwarg;
    PyObject *kwd_attrs;
    PyObject *kwd_patterns;
    PyObject *kwonlyargs;
    PyObject *left;
    PyObject *level;
    PyObject *lineno;
    PyObject *lower;
    PyObject *match_case_type;
    PyObject *mod_type;
    PyObject *module;
    PyObject *msg;
    PyObject *name;
    PyObject *names;
    PyObject *op;
    PyObject *operand;
    PyObject *operator_type;
    PyObject *ops;
    PyObject *optional_vars;
    PyObject *orelse;
    PyObject *pattern;
    PyObject *pattern_type;
    PyObject *patterns;
    PyObject *posonlyargs;
    PyObject *rest;
    PyObject *returns;
    PyObject *right;
    PyObject *simple;
    PyObject *slice;
    PyObject *step;
    PyObject *stmt_type;
    PyObject *subject;
    PyObject *tag;
    PyObject *target;
    PyObject *targets;
    PyObject *test;
    PyObject *type;
    PyObject *type_comment;
    PyObject *type_ignore_type;
    PyObject *type_ignores;
    PyObject *type_param_type;
    PyObject *type_params;
    PyObject *unaryop_type;
    PyObject *upper;
    PyObject *value;
    PyObject *values;
    PyObject *vararg;
    PyObject *withitem_type;
};
typedef void (*atexit_callbackfunc)(void);
struct _atexit_runtime_state {
    PyThread_type_lock mutex;
    atexit_callbackfunc callbacks[32];
    int ncallbacks;
};
struct atexit_callback;
typedef struct atexit_callback {
    atexit_datacallbackfunc func;
    void *data;
    struct atexit_callback *next;
} atexit_callback;
typedef struct {
    PyObject *func;
    PyObject *args;
    PyObject *kwargs;
} atexit_py_callback;
struct atexit_state {
    atexit_callback *ll_callbacks;
    atexit_callback *last_ll_callback;
    atexit_py_callback **callbacks;
    int ncallbacks;
    int callback_len;
};
void AnnotateRWLockCreate(const char *file, int line,
                          const volatile void *lock);
void AnnotateRWLockDestroy(const char *file, int line,
                           const volatile void *lock);
void AnnotateRWLockAcquired(const char *file, int line,
                            const volatile void *lock, long is_w);
void AnnotateRWLockReleased(const char *file, int line,
                            const volatile void *lock, long is_w);
void AnnotateBarrierInit(const char *file, int line,
                         const volatile void *barrier, long count,
                         long reinitialization_allowed);
void AnnotateBarrierWaitBefore(const char *file, int line,
                               const volatile void *barrier);
void AnnotateBarrierWaitAfter(const char *file, int line,
                              const volatile void *barrier);
void AnnotateBarrierDestroy(const char *file, int line,
                            const volatile void *barrier);
void AnnotateCondVarWait(const char *file, int line,
                         const volatile void *cv,
                         const volatile void *lock);
void AnnotateCondVarSignal(const char *file, int line,
                           const volatile void *cv);
void AnnotateCondVarSignalAll(const char *file, int line,
                              const volatile void *cv);
void AnnotatePublishMemoryRange(const char *file, int line,
                                const volatile void *address,
                                long size);
void AnnotateUnpublishMemoryRange(const char *file, int line,
                                  const volatile void *address,
                                  long size);
void AnnotatePCQCreate(const char *file, int line,
                       const volatile void *pcq);
void AnnotatePCQDestroy(const char *file, int line,
                        const volatile void *pcq);
void AnnotatePCQPut(const char *file, int line,
                    const volatile void *pcq);
void AnnotatePCQGet(const char *file, int line,
                    const volatile void *pcq);
void AnnotateNewMemory(const char *file, int line,
                       const volatile void *address,
                       long size);
void AnnotateExpectRace(const char *file, int line,
                        const volatile void *address,
                        const char *description);
void AnnotateBenignRace(const char *file, int line,
                        const volatile void *address,
                        const char *description);
void AnnotateBenignRaceSized(const char *file, int line,
                        const volatile void *address,
                        long size,
                        const char *description);
void AnnotateMutexIsUsedAsCondVar(const char *file, int line,
                                  const volatile void *mu);
void AnnotateTraceMemory(const char *file, int line,
                         const volatile void *arg);
void AnnotateThreadName(const char *file, int line,
                        const char *name);
void AnnotateIgnoreReadsBegin(const char *file, int line);
void AnnotateIgnoreReadsEnd(const char *file, int line);
void AnnotateIgnoreWritesBegin(const char *file, int line);
void AnnotateIgnoreWritesEnd(const char *file, int line);
void AnnotateEnableRaceDetection(const char *file, int line, int enable);
void AnnotateNoOp(const char *file, int line,
                  const volatile void *arg);
void AnnotateFlushState(const char *file, int line);
int RunningOnValgrind(void);
typedef enum
  {
    memory_order_relaxed = 0,
    memory_order_consume = 1,
    memory_order_acquire = 2,
    memory_order_release = 3,
    memory_order_acq_rel = 4,
    memory_order_seq_cst = 5
  } memory_order;
typedef _Atomic _Bool atomic_bool;
typedef _Atomic char atomic_char;
typedef _Atomic signed char atomic_schar;
typedef _Atomic unsigned char atomic_uchar;
typedef _Atomic short atomic_short;
typedef _Atomic unsigned short atomic_ushort;
typedef _Atomic int atomic_int;
typedef _Atomic unsigned int atomic_uint;
typedef _Atomic long atomic_long;
typedef _Atomic unsigned long atomic_ulong;
typedef _Atomic long long atomic_llong;
typedef _Atomic unsigned long long atomic_ullong;
typedef _Atomic short unsigned int atomic_char16_t;
typedef _Atomic unsigned int atomic_char32_t;
typedef _Atomic int atomic_wchar_t;
typedef _Atomic signed char atomic_int_least8_t;
typedef _Atomic unsigned char atomic_uint_least8_t;
typedef _Atomic short int atomic_int_least16_t;
typedef _Atomic short unsigned int atomic_uint_least16_t;
typedef _Atomic int atomic_int_least32_t;
typedef _Atomic unsigned int atomic_uint_least32_t;
typedef _Atomic long int atomic_int_least64_t;
typedef _Atomic long unsigned int atomic_uint_least64_t;
typedef _Atomic signed char atomic_int_fast8_t;
typedef _Atomic unsigned char atomic_uint_fast8_t;
typedef _Atomic long int atomic_int_fast16_t;
typedef _Atomic long unsigned int atomic_uint_fast16_t;
typedef _Atomic long int atomic_int_fast32_t;
typedef _Atomic long unsigned int atomic_uint_fast32_t;
typedef _Atomic long int atomic_int_fast64_t;
typedef _Atomic long unsigned int atomic_uint_fast64_t;
typedef _Atomic long int atomic_intptr_t;
typedef _Atomic long unsigned int atomic_uintptr_t;
typedef _Atomic long unsigned int atomic_size_t;
typedef _Atomic long int atomic_ptrdiff_t;
typedef _Atomic long int atomic_intmax_t;
typedef _Atomic long unsigned int atomic_uintmax_t;
extern void atomic_thread_fence (memory_order);
extern void atomic_signal_fence (memory_order);
typedef _Atomic struct
{
  _Bool __val;
} atomic_flag;
extern _Bool atomic_flag_test_and_set (volatile atomic_flag *);
extern _Bool atomic_flag_test_and_set_explicit (volatile atomic_flag *,
      memory_order);
extern void atomic_flag_clear (volatile atomic_flag *);
extern void atomic_flag_clear_explicit (volatile atomic_flag *, memory_order);
typedef enum _Py_memory_order {
    _Py_memory_order_relaxed = memory_order_relaxed,
    _Py_memory_order_acquire = memory_order_acquire,
    _Py_memory_order_release = memory_order_release,
    _Py_memory_order_acq_rel = memory_order_acq_rel,
    _Py_memory_order_seq_cst = memory_order_seq_cst
} _Py_memory_order;
typedef struct _Py_atomic_address {
    atomic_uintptr_t _value;
} _Py_atomic_address;
typedef struct _Py_atomic_int {
    atomic_int _value;
} _Py_atomic_int;
struct _gil_runtime_state {
    unsigned long interval;
    _Py_atomic_address last_holder;
    _Py_atomic_int locked;
    unsigned long switch_number;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    pthread_cond_t switch_cond;
    pthread_mutex_t switch_mutex;
};
struct _pending_calls {
    int busy;
    PyThread_type_lock lock;
    _Py_atomic_int calls_to_do;
    int async_exc;
    struct _pending_call {
        int (*func)(void *);
        void *arg;
    } calls[32];
    int first;
    int last;
};
typedef enum {
    PERF_STATUS_FAILED = -1,
    PERF_STATUS_NO_INIT = 0,
    PERF_STATUS_OK = 1,
} perf_status_t;
struct code_arena_st;
struct trampoline_api_st {
    void* (*init_state)(void);
    void (*write_state)(void* state, const void *code_addr,
                        unsigned int code_size, PyCodeObject* code);
    int (*free_state)(void* state);
    void *state;
};
struct _ceval_runtime_state {
    struct {
        perf_status_t status;
        Py_ssize_t extra_code_index;
        struct code_arena_st *code_arena;
        struct trampoline_api_st trampoline_api;
        FILE *map_file;
    } perf;
    _Py_atomic_int signals_pending;
    struct _pending_calls pending_mainthread;
};
struct _ceval_state {
    _Py_atomic_int eval_breaker;
    _Py_atomic_int gil_drop_request;
    int recursion_limit;
    struct _gil_runtime_state *gil;
    int own_gil;
    _Py_atomic_int gc_scheduled;
    struct _pending_calls pending;
};
typedef struct {
    uint16_t counter;
    uint16_t index;
    uint16_t module_keys_version;
    uint16_t builtin_keys_version;
} _PyLoadGlobalCache;
typedef struct {
    uint16_t counter;
} _PyBinaryOpCache;
typedef struct {
    uint16_t counter;
} _PyUnpackSequenceCache;
typedef struct {
    uint16_t counter;
} _PyCompareOpCache;
typedef struct {
    uint16_t counter;
} _PyBinarySubscrCache;
typedef struct {
    uint16_t counter;
} _PySuperAttrCache;
typedef struct {
    uint16_t counter;
    uint16_t version[2];
    uint16_t index;
} _PyAttrCache;
typedef struct {
    uint16_t counter;
    uint16_t type_version[2];
    uint16_t keys_version[2];
    uint16_t descr[4];
} _PyLoadMethodCache;
typedef struct {
    uint16_t counter;
    uint16_t func_version[2];
} _PyCallCache;
typedef struct {
    uint16_t counter;
} _PyStoreSubscrCache;
typedef struct {
    uint16_t counter;
} _PyForIterCache;
typedef struct {
    uint16_t counter;
} _PySendCache;
struct callable_cache {
    PyObject *isinstance;
    PyObject *len;
    PyObject *list_append;
    PyObject *object__getattribute__;
};
typedef unsigned char _PyLocals_Kind;
static inline _PyLocals_Kind
_PyLocals_GetKind(PyObject *kinds, int i)
{
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((kinds))))), ((1UL << 27)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((kinds))))), ((1UL << 27)))) ; else __assert_fail ("PyBytes_Check(kinds)", "/usr/include/python3.12/internal/pycore_code.h", 141, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((0 <= i && i < PyBytes_GET_SIZE(((PyObject*)((kinds))))) ? 1 : 0), __extension__ ({ if (0 <= i && i < PyBytes_GET_SIZE(((PyObject*)((kinds))))) ; else __assert_fail ("0 <= i && i < PyBytes_GET_SIZE(kinds)", "/usr/include/python3.12/internal/pycore_code.h", 142, __extension__ __PRETTY_FUNCTION__); }));
    char *ptr = PyBytes_AS_STRING(((PyObject*)((kinds))));
    return (_PyLocals_Kind)(ptr[i]);
}
static inline void
_PyLocals_SetKind(PyObject *kinds, int i, _PyLocals_Kind kind)
{
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((kinds))))), ((1UL << 27)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((kinds))))), ((1UL << 27)))) ; else __assert_fail ("PyBytes_Check(kinds)", "/usr/include/python3.12/internal/pycore_code.h", 150, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((0 <= i && i < PyBytes_GET_SIZE(((PyObject*)((kinds))))) ? 1 : 0), __extension__ ({ if (0 <= i && i < PyBytes_GET_SIZE(((PyObject*)((kinds))))) ; else __assert_fail ("0 <= i && i < PyBytes_GET_SIZE(kinds)", "/usr/include/python3.12/internal/pycore_code.h", 151, __extension__ __PRETTY_FUNCTION__); }));
    char *ptr = PyBytes_AS_STRING(((PyObject*)((kinds))));
    ptr[i] = (char) kind;
}
struct _PyCodeConstructor {
    PyObject *filename;
    PyObject *name;
    PyObject *qualname;
    int flags;
    PyObject *code;
    int firstlineno;
    PyObject *linetable;
    PyObject *consts;
    PyObject *names;
    PyObject *localsplusnames;
    PyObject *localspluskinds;
    int argcount;
    int posonlyargcount;
    int kwonlyargcount;
    int stacksize;
    PyObject *exceptiontable;
};
__attribute__ ((visibility ("default"))) int _PyCode_Validate(struct _PyCodeConstructor *);
__attribute__ ((visibility ("default"))) PyCodeObject * _PyCode_New(struct _PyCodeConstructor *);
extern PyObject* _PyCode_GetVarnames(PyCodeObject *);
extern PyObject* _PyCode_GetCellvars(PyCodeObject *);
extern PyObject* _PyCode_GetFreevars(PyCodeObject *);
extern PyObject* _PyCode_GetCode(PyCodeObject *);
extern int _PyCode_InitAddressRange(PyCodeObject* co, PyCodeAddressRange *bounds);
extern void _PyLineTable_InitAddressRange(
    const char *linetable,
    Py_ssize_t length,
    int firstlineno,
    PyCodeAddressRange *range);
extern int _PyLineTable_NextAddressRange(PyCodeAddressRange *range);
extern int _PyLineTable_PreviousAddressRange(PyCodeAddressRange *range);
extern void _Py_Specialize_LoadSuperAttr(PyObject *global_super, PyObject *cls,
                                         _Py_CODEUNIT *instr, int load_method);
extern void _Py_Specialize_LoadAttr(PyObject *owner, _Py_CODEUNIT *instr,
                                    PyObject *name);
extern void _Py_Specialize_StoreAttr(PyObject *owner, _Py_CODEUNIT *instr,
                                     PyObject *name);
extern void _Py_Specialize_LoadGlobal(PyObject *globals, PyObject *builtins,
                                      _Py_CODEUNIT *instr, PyObject *name);
extern void _Py_Specialize_BinarySubscr(PyObject *sub, PyObject *container,
                                        _Py_CODEUNIT *instr);
extern void _Py_Specialize_StoreSubscr(PyObject *container, PyObject *sub,
                                       _Py_CODEUNIT *instr);
extern void _Py_Specialize_Call(PyObject *callable, _Py_CODEUNIT *instr,
                                int nargs, PyObject *kwnames);
extern void _Py_Specialize_BinaryOp(PyObject *lhs, PyObject *rhs, _Py_CODEUNIT *instr,
                                    int oparg, PyObject **locals);
extern void _Py_Specialize_CompareOp(PyObject *lhs, PyObject *rhs,
                                     _Py_CODEUNIT *instr, int oparg);
extern void _Py_Specialize_UnpackSequence(PyObject *seq, _Py_CODEUNIT *instr,
                                          int oparg);
extern void _Py_Specialize_ForIter(PyObject *iter, _Py_CODEUNIT *instr, int oparg);
extern void _Py_Specialize_Send(PyObject *receiver, _Py_CODEUNIT *instr);
extern void _PyStaticCode_Fini(PyCodeObject *co);
extern int _PyStaticCode_Init(PyCodeObject *co);
static inline void
write_u32(uint16_t *p, uint32_t val)
{
    memcpy(p, &val, sizeof(val));
}
static inline void
write_u64(uint16_t *p, uint64_t val)
{
    memcpy(p, &val, sizeof(val));
}
static inline void
write_obj(uint16_t *p, PyObject *val)
{
    memcpy(p, &val, sizeof(val));
}
static inline uint16_t
read_u16(uint16_t *p)
{
    return *p;
}
static inline uint32_t
read_u32(uint16_t *p)
{
    uint32_t val;
    memcpy(&val, p, sizeof(val));
    return val;
}
static inline uint64_t
read_u64(uint16_t *p)
{
    uint64_t val;
    memcpy(&val, p, sizeof(val));
    return val;
}
static inline PyObject *
read_obj(uint16_t *p)
{
    PyObject *val;
    memcpy(&val, p, sizeof(val));
    return val;
}
static inline unsigned char *
parse_varint(unsigned char *p, int *result) {
    int val = p[0] & 63;
    while (p[0] & 64) {
        p++;
        val = (val << 6) | (p[0] & 63);
    }
    *result = val;
    return p+1;
}
static inline int
write_varint(uint8_t *ptr, unsigned int val)
{
    int written = 1;
    while (val >= 64) {
        *ptr++ = 64 | (val & 63);
        val >>= 6;
        written++;
    }
    *ptr = (uint8_t)val;
    return written;
}
static inline int
write_signed_varint(uint8_t *ptr, int val)
{
    unsigned int uval;
    if (val < 0) {
        uval = ((0 - (unsigned int)val) << 1) | 1;
    }
    else {
        uval = (unsigned int)val << 1;
    }
    return write_varint(ptr, uval);
}
static inline int
write_location_entry_start(uint8_t *ptr, int code, int length)
{
    ((void) sizeof (((code & 15) == code) ? 1 : 0), __extension__ ({ if ((code & 15) == code) ; else __assert_fail ("(code & 15) == code", "/usr/include/python3.12/internal/pycore_code.h", 383, __extension__ __PRETTY_FUNCTION__); }));
    *ptr = 128 | (uint8_t)(code << 3) | (uint8_t)(length - 1);
    return 1;
}
static inline uint16_t
adaptive_counter_bits(uint16_t value, uint16_t backoff) {
    return ((value << 4)
            | (backoff & ((1 << 4) - 1)));
}
static inline uint16_t
adaptive_counter_warmup(void) {
    return adaptive_counter_bits(1,
                                 1);
}
static inline uint16_t
adaptive_counter_cooldown(void) {
    return adaptive_counter_bits(52,
                                 0);
}
static inline uint16_t
adaptive_counter_backoff(uint16_t counter) {
    uint16_t backoff = counter & ((1 << 4) - 1);
    backoff++;
    if (backoff > (16 - 4)) {
        backoff = (16 - 4);
    }
    uint16_t value = (uint16_t)(1 << backoff) - 1;
    return adaptive_counter_bits(value, backoff);
}
typedef struct _PyShimCodeDef {
    const uint8_t *code;
    int codelen;
    int stacksize;
    const char *cname;
} _PyShimCodeDef;
extern PyCodeObject *
_Py_MakeShimCode(const _PyShimCodeDef *code);
extern uint32_t _Py_next_func_version;
extern int _Py_Instrument(PyCodeObject *co, PyInterpreterState *interp);
extern int _Py_GetBaseOpcode(PyCodeObject *code, int offset);
extern PyTypeObject _PyHamt_Type;
extern PyTypeObject _PyHamt_ArrayNode_Type;
extern PyTypeObject _PyHamt_BitmapNode_Type;
extern PyTypeObject _PyHamt_CollisionNode_Type;
extern PyTypeObject _PyHamtKeys_Type;
extern PyTypeObject _PyHamtValues_Type;
extern PyTypeObject _PyHamtItems_Type;
typedef struct {
    PyObject ob_base;
} PyHamtNode;
typedef struct {
    PyObject ob_base;
    PyHamtNode *h_root;
    PyObject *h_weakreflist;
    Py_ssize_t h_count;
} PyHamtObject;
typedef struct {
    PyVarObject ob_base;
    uint32_t b_bitmap;
    PyObject *b_array[1];
} PyHamtNode_Bitmap;
typedef struct {
    PyHamtNode *i_nodes[8];
    Py_ssize_t i_pos[8];
    int8_t i_level;
} PyHamtIteratorState;
typedef struct {
    PyObject ob_base;
    PyHamtObject *hi_obj;
    PyHamtIteratorState hi_iter;
    binaryfunc hi_yield;
} PyHamtIterator;
PyHamtObject * _PyHamt_New(void);
PyHamtObject * _PyHamt_Assoc(PyHamtObject *o, PyObject *key, PyObject *val);
PyHamtObject * _PyHamt_Without(PyHamtObject *o, PyObject *key);
int _PyHamt_Find(PyHamtObject *o, PyObject *key, PyObject **val);
int _PyHamt_Eq(PyHamtObject *v, PyHamtObject *w);
Py_ssize_t _PyHamt_Len(PyHamtObject *o);
PyObject * _PyHamt_NewIterKeys(PyHamtObject *o);
PyObject * _PyHamt_NewIterValues(PyHamtObject *o);
PyObject * _PyHamt_NewIterItems(PyHamtObject *o);
extern PyTypeObject _PyContextTokenMissing_Type;
PyStatus _PyContext_Init(PyInterpreterState *);
void _PyContext_Fini(PyInterpreterState *);
typedef struct {
    PyObject ob_base;
} _PyContextTokenMissing;
struct _Py_context_state {
    PyContext *freelist;
    int numfree;
};
struct _pycontextobject {
    PyObject ob_base;
    PyContext *ctx_prev;
    PyHamtObject *ctx_vars;
    PyObject *ctx_weakreflist;
    int ctx_entered;
};
struct _pycontextvarobject {
    PyObject ob_base;
    PyObject *var_name;
    PyObject *var_default;
    PyObject *var_cached;
    uint64_t var_cached_tsid;
    uint64_t var_cached_tsver;
    Py_hash_t var_hash;
};
struct _pycontexttokenobject {
    PyObject ob_base;
    PyContext *tok_ctx;
    PyContextVar *tok_var;
    PyObject *tok_oldval;
    int tok_used;
};
struct _Py_dict_state {
    uint64_t global_version;
    uint32_t next_keys_version;
    PyDictObject *free_list[80];
    PyDictKeysObject *keys_free_list[80];
    int numfree;
    int keys_numfree;
    PyDict_WatchCallback watchers[8];
};
static inline void _Py_ADJUST_ERANGE1(double x)
{
    if ((*__errno_location ()) == 0) {
        if (x == (__builtin_huge_val ()) || x == -(__builtin_huge_val ())) {
            (*__errno_location ()) = 34;
        }
    }
    else if ((*__errno_location ()) == 34 && x == 0.0) {
        (*__errno_location ()) = 0;
    }
}
static inline void _Py_ADJUST_ERANGE2(double x, double y)
{
    if (x == (__builtin_huge_val ()) || x == -(__builtin_huge_val ()) ||
        y == (__builtin_huge_val ()) || y == -(__builtin_huge_val ()))
    {
        if ((*__errno_location ()) == 0) {
            (*__errno_location ()) = 34;
        }
    }
    else if ((*__errno_location ()) == 34) {
        (*__errno_location ()) = 0;
    }
}
extern unsigned short _Py_get_387controlword(void);
extern void _Py_set_387controlword(unsigned short);
typedef uint32_t ULong;
struct
Bigint {
    struct Bigint *next;
    int k, maxwds, sign, wds;
    ULong x[1];
};
struct _dtoa_state {
    struct Bigint *p5s;
    struct Bigint *freelist[7 +1];
    double preallocated[((2304 +sizeof(double)-1)/sizeof(double))];
    double *preallocated_next;
};
__attribute__ ((visibility ("default"))) double _Py_dg_strtod(const char *str, char **ptr);
__attribute__ ((visibility ("default"))) char * _Py_dg_dtoa(double d, int mode, int ndigits,
                        int *decpt, int *sign, char **rve);
__attribute__ ((visibility ("default"))) void _Py_dg_freedtoa(char *s);
extern PyStatus _PyExc_InitState(PyInterpreterState *);
extern PyStatus _PyExc_InitGlobalObjects(PyInterpreterState *);
extern int _PyExc_InitTypes(PyInterpreterState *);
extern void _PyExc_Fini(PyInterpreterState *);
struct _Py_exc_state {
    PyObject *errnomap;
    PyBaseExceptionObject *memerrors_freelist;
    int memerrors_numfree;
    PyObject *PyExc_ExceptionGroup;
};
extern void _PyExc_ClearExceptionGroupType(PyInterpreterState *);
extern void _PyFloat_InitState(PyInterpreterState *);
extern PyStatus _PyFloat_InitTypes(PyInterpreterState *);
extern void _PyFloat_Fini(PyInterpreterState *);
extern void _PyFloat_FiniType(PyInterpreterState *);
enum _py_float_format_type {
    _py_float_format_unknown,
    _py_float_format_ieee_big_endian,
    _py_float_format_ieee_little_endian,
};
struct _Py_float_runtime_state {
    enum _py_float_format_type float_format;
    enum _py_float_format_type double_format;
};
struct _Py_float_state {
    int numfree;
    PyFloatObject *free_list;
};
void _PyFloat_ExactDealloc(PyObject *op);
__attribute__ ((visibility ("default"))) void _PyFloat_DebugMallocStats(FILE* out);
__attribute__ ((visibility ("default"))) int _PyFloat_FormatAdvancedWriter(
    _PyUnicodeWriter *writer,
    PyObject *obj,
    PyObject *format_spec,
    Py_ssize_t start,
    Py_ssize_t end);
struct _py_func_state {
    uint32_t next_version;
};
extern PyFunctionObject* _PyFunction_FromConstructor(PyFrameConstructor *constr);
extern uint32_t _PyFunction_GetVersionForCurrentState(PyFunctionObject *func);
extern PyObject *_Py_set_function_type_params(
    PyThreadState* unused, PyObject *func, PyObject *type_params);
extern PyObject *_PyGen_yf(PyGenObject *);
extern PyObject *_PyCoro_GetAwaitableIter(PyObject *o);
extern PyObject *_PyAsyncGenValueWrapperNew(PyThreadState *state, PyObject *);
extern void _PyAsyncGen_Fini(PyInterpreterState *);
struct _Py_async_gen_state {
    struct _PyAsyncGenWrappedValue* value_freelist[80];
    int value_numfree;
    struct PyAsyncGenASend* asend_freelist[80];
    int asend_numfree;
};
typedef struct {
    uintptr_t _gc_next;
    uintptr_t _gc_prev;
} PyGC_Head;
static inline PyGC_Head* _Py_AS_GC(PyObject *op) {
    return (((PyGC_Head*)(op)) - 1);
}
static inline int _PyObject_GC_IS_TRACKED(PyObject *op) {
    PyGC_Head *gc = _Py_AS_GC(op);
    return (gc->_gc_next != 0);
}
static inline int _PyObject_GC_MAY_BE_TRACKED(PyObject *obj) {
    if (!PyObject_IS_GC(obj)) {
        return 0;
    }
    if (Py_IS_TYPE(((PyObject*)(((obj)))), (&PyTuple_Type))) {
        return _PyObject_GC_IS_TRACKED(((PyObject*)(obj)));
    }
    return 1;
}
static inline PyGC_Head* _PyGCHead_NEXT(PyGC_Head *gc) {
    uintptr_t next = gc->_gc_next;
    return ((PyGC_Head*)(next));
}
static inline void _PyGCHead_SET_NEXT(PyGC_Head *gc, PyGC_Head *next) {
    gc->_gc_next = ((uintptr_t)(next));
}
static inline PyGC_Head* _PyGCHead_PREV(PyGC_Head *gc) {
    uintptr_t prev = (gc->_gc_prev & (((uintptr_t) -1) << (2)));
    return ((PyGC_Head*)(prev));
}
static inline void _PyGCHead_SET_PREV(PyGC_Head *gc, PyGC_Head *prev) {
    uintptr_t uprev = ((uintptr_t)(prev));
    ((void) sizeof (((uprev & ~(((uintptr_t) -1) << (2))) == 0) ? 1 : 0), __extension__ ({ if ((uprev & ~(((uintptr_t) -1) << (2))) == 0) ; else __assert_fail ("(uprev & ~_PyGC_PREV_MASK) == 0", "/usr/include/python3.12/internal/pycore_gc.h", 73, __extension__ __PRETTY_FUNCTION__); }));
    gc->_gc_prev = ((gc->_gc_prev & ~(((uintptr_t) -1) << (2))) | uprev);
}
static inline int _PyGCHead_FINALIZED(PyGC_Head *gc) {
    return ((gc->_gc_prev & (1)) != 0);
}
static inline void _PyGCHead_SET_FINALIZED(PyGC_Head *gc) {
    gc->_gc_prev |= (1);
}
static inline int _PyGC_FINALIZED(PyObject *op) {
    PyGC_Head *gc = _Py_AS_GC(op);
    return _PyGCHead_FINALIZED(gc);
}
static inline void _PyGC_SET_FINALIZED(PyObject *op) {
    PyGC_Head *gc = _Py_AS_GC(op);
    _PyGCHead_SET_FINALIZED(gc);
}
struct gc_generation {
    PyGC_Head head;
    int threshold;
    int count;
};
struct gc_generation_stats {
    Py_ssize_t collections;
    Py_ssize_t collected;
    Py_ssize_t uncollectable;
};
struct _gc_runtime_state {
    PyObject *trash_delete_later;
    int trash_delete_nesting;
    int enabled;
    int debug;
    struct gc_generation generations[3];
    PyGC_Head *generation0;
    struct gc_generation permanent_generation;
    struct gc_generation_stats generation_stats[3];
    int collecting;
    PyObject *garbage;
    PyObject *callbacks;
    Py_ssize_t long_lived_total;
    Py_ssize_t long_lived_pending;
};
extern void _PyGC_InitState(struct _gc_runtime_state *);
extern Py_ssize_t _PyGC_CollectNoFail(PyThreadState *tstate);
extern void _PyTuple_ClearFreeList(PyInterpreterState *interp);
extern void _PyFloat_ClearFreeList(PyInterpreterState *interp);
extern void _PyList_ClearFreeList(PyInterpreterState *interp);
extern void _PyDict_ClearFreeList(PyInterpreterState *interp);
extern void _PyAsyncGen_ClearFreeLists(PyInterpreterState *interp);
extern void _PyContext_ClearFreeList(PyInterpreterState *interp);
extern void _Py_ScheduleGC(PyInterpreterState *interp);
extern void _Py_RunGC(PyThreadState *tstate);
typedef struct _Py_slist_item_s {
    struct _Py_slist_item_s *next;
} _Py_slist_item_t;
typedef struct {
    _Py_slist_item_t *head;
} _Py_slist_t;
typedef struct {
    _Py_slist_item_t _Py_slist_item;
    Py_uhash_t key_hash;
    void *key;
    void *value;
} _Py_hashtable_entry_t;
struct _Py_hashtable_t;
typedef struct _Py_hashtable_t _Py_hashtable_t;
typedef Py_uhash_t (*_Py_hashtable_hash_func) (const void *key);
typedef int (*_Py_hashtable_compare_func) (const void *key1, const void *key2);
typedef void (*_Py_hashtable_destroy_func) (void *key);
typedef _Py_hashtable_entry_t* (*_Py_hashtable_get_entry_func)(_Py_hashtable_t *ht,
                                                               const void *key);
typedef struct {
    void* (*malloc) (size_t size);
    void (*free) (void *ptr);
} _Py_hashtable_allocator_t;
struct _Py_hashtable_t {
    size_t nentries;
    size_t nbuckets;
    _Py_slist_t *buckets;
    _Py_hashtable_get_entry_func get_entry_func;
    _Py_hashtable_hash_func hash_func;
    _Py_hashtable_compare_func compare_func;
    _Py_hashtable_destroy_func key_destroy_func;
    _Py_hashtable_destroy_func value_destroy_func;
    _Py_hashtable_allocator_t alloc;
};
__attribute__ ((visibility ("default"))) Py_uhash_t _Py_hashtable_hash_ptr(const void *key);
__attribute__ ((visibility ("default"))) int _Py_hashtable_compare_direct(
    const void *key1,
    const void *key2);
__attribute__ ((visibility ("default"))) _Py_hashtable_t * _Py_hashtable_new(
    _Py_hashtable_hash_func hash_func,
    _Py_hashtable_compare_func compare_func);
__attribute__ ((visibility ("default"))) _Py_hashtable_t * _Py_hashtable_new_full(
    _Py_hashtable_hash_func hash_func,
    _Py_hashtable_compare_func compare_func,
    _Py_hashtable_destroy_func key_destroy_func,
    _Py_hashtable_destroy_func value_destroy_func,
    _Py_hashtable_allocator_t *allocator);
__attribute__ ((visibility ("default"))) void _Py_hashtable_destroy(_Py_hashtable_t *ht);
__attribute__ ((visibility ("default"))) void _Py_hashtable_clear(_Py_hashtable_t *ht);
typedef int (*_Py_hashtable_foreach_func) (_Py_hashtable_t *ht,
                                           const void *key, const void *value,
                                           void *user_data);
__attribute__ ((visibility ("default"))) int _Py_hashtable_foreach(
    _Py_hashtable_t *ht,
    _Py_hashtable_foreach_func func,
    void *user_data);
__attribute__ ((visibility ("default"))) size_t _Py_hashtable_size(const _Py_hashtable_t *ht);
__attribute__ ((visibility ("default"))) size_t _Py_hashtable_len(const _Py_hashtable_t *ht);
__attribute__ ((visibility ("default"))) int _Py_hashtable_set(
    _Py_hashtable_t *ht,
    const void *key,
    void *value);
static inline _Py_hashtable_entry_t *
_Py_hashtable_get_entry(_Py_hashtable_t *ht, const void *key)
{
    return ht->get_entry_func(ht, key);
}
__attribute__ ((visibility ("default"))) void* _Py_hashtable_get(_Py_hashtable_t *ht, const void *key);
__attribute__ ((visibility ("default"))) void* _Py_hashtable_steal(
    _Py_hashtable_t *ht,
    const void *key);
struct _Py_global_strings {
    struct {
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<dictcomp>")]; } _py_anon_dictcomp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<genexpr>")]; } _py_anon_genexpr;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<lambda>")]; } _py_anon_lambda;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<listcomp>")]; } _py_anon_listcomp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<module>")]; } _py_anon_module;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<setcomp>")]; } _py_anon_setcomp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<string>")]; } _py_anon_string;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<unknown>")]; } _py_anon_unknown;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("}")]; } _py_close_br;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("}}")]; } _py_dbl_close_br;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("{{")]; } _py_dbl_open_br;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("%%")]; } _py_dbl_percent;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof(".defaults")]; } _py_defaults;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof(".")]; } _py_dot;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof(".<locals>")]; } _py_dot_locals;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("")]; } _py_empty;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof(".generic_base")]; } _py_generic_base;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("json.decoder")]; } _py_json_decoder;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof(".kwdefaults")]; } _py_kwdefaults;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("list index out of range")]; } _py_list_err;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("\n")]; } _py_newline;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("{")]; } _py_open_br;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("%")]; } _py_percent;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("<shim>")]; } _py_shim_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof(".type_params")]; } _py_type_params;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("utf-8")]; } _py_utf_8;
    } literals;
    struct {
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("CANCELLED")]; } _py_CANCELLED;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("FINISHED")]; } _py_FINISHED;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("False")]; } _py_False;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("JSONDecodeError")]; } _py_JSONDecodeError;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("PENDING")]; } _py_PENDING;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("Py_Repr")]; } _py_Py_Repr;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("TextIOWrapper")]; } _py_TextIOWrapper;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("True")]; } _py_True;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("WarningMessage")]; } _py_WarningMessage;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_")]; } _py__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_WindowsConsoleIO")]; } _py__WindowsConsoleIO;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__IOBase_closed")]; } _py___IOBase_closed;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__abc_tpflags__")]; } _py___abc_tpflags__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__abs__")]; } _py___abs__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__abstractmethods__")]; } _py___abstractmethods__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__add__")]; } _py___add__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__aenter__")]; } _py___aenter__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__aexit__")]; } _py___aexit__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__aiter__")]; } _py___aiter__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__all__")]; } _py___all__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__and__")]; } _py___and__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__anext__")]; } _py___anext__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__annotations__")]; } _py___annotations__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__args__")]; } _py___args__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__asyncio_running_event_loop__")]; } _py___asyncio_running_event_loop__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__await__")]; } _py___await__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__bases__")]; } _py___bases__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__bool__")]; } _py___bool__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__buffer__")]; } _py___buffer__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__build_class__")]; } _py___build_class__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__builtins__")]; } _py___builtins__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__bytes__")]; } _py___bytes__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__call__")]; } _py___call__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__cantrace__")]; } _py___cantrace__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__class__")]; } _py___class__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__class_getitem__")]; } _py___class_getitem__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__classcell__")]; } _py___classcell__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__classdict__")]; } _py___classdict__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__classdictcell__")]; } _py___classdictcell__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__complex__")]; } _py___complex__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__contains__")]; } _py___contains__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__copy__")]; } _py___copy__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ctypes_from_outparam__")]; } _py___ctypes_from_outparam__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__del__")]; } _py___del__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__delattr__")]; } _py___delattr__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__delete__")]; } _py___delete__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__delitem__")]; } _py___delitem__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__dict__")]; } _py___dict__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__dictoffset__")]; } _py___dictoffset__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__dir__")]; } _py___dir__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__divmod__")]; } _py___divmod__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__doc__")]; } _py___doc__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__enter__")]; } _py___enter__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__eq__")]; } _py___eq__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__exit__")]; } _py___exit__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__file__")]; } _py___file__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__float__")]; } _py___float__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__floordiv__")]; } _py___floordiv__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__format__")]; } _py___format__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__fspath__")]; } _py___fspath__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ge__")]; } _py___ge__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__get__")]; } _py___get__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getattr__")]; } _py___getattr__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getattribute__")]; } _py___getattribute__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getinitargs__")]; } _py___getinitargs__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getitem__")]; } _py___getitem__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getnewargs__")]; } _py___getnewargs__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getnewargs_ex__")]; } _py___getnewargs_ex__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__getstate__")]; } _py___getstate__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__gt__")]; } _py___gt__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__hash__")]; } _py___hash__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__iadd__")]; } _py___iadd__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__iand__")]; } _py___iand__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ifloordiv__")]; } _py___ifloordiv__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ilshift__")]; } _py___ilshift__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__imatmul__")]; } _py___imatmul__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__imod__")]; } _py___imod__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__import__")]; } _py___import__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__imul__")]; } _py___imul__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__index__")]; } _py___index__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__init__")]; } _py___init__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__init_subclass__")]; } _py___init_subclass__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__instancecheck__")]; } _py___instancecheck__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__int__")]; } _py___int__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__invert__")]; } _py___invert__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ior__")]; } _py___ior__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ipow__")]; } _py___ipow__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__irshift__")]; } _py___irshift__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__isabstractmethod__")]; } _py___isabstractmethod__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__isub__")]; } _py___isub__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__iter__")]; } _py___iter__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__itruediv__")]; } _py___itruediv__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ixor__")]; } _py___ixor__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__le__")]; } _py___le__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__len__")]; } _py___len__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__length_hint__")]; } _py___length_hint__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__lltrace__")]; } _py___lltrace__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__loader__")]; } _py___loader__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__lshift__")]; } _py___lshift__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__lt__")]; } _py___lt__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__main__")]; } _py___main__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__matmul__")]; } _py___matmul__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__missing__")]; } _py___missing__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__mod__")]; } _py___mod__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__module__")]; } _py___module__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__mro_entries__")]; } _py___mro_entries__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__mul__")]; } _py___mul__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__name__")]; } _py___name__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ne__")]; } _py___ne__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__neg__")]; } _py___neg__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__new__")]; } _py___new__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__newobj__")]; } _py___newobj__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__newobj_ex__")]; } _py___newobj_ex__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__next__")]; } _py___next__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__notes__")]; } _py___notes__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__or__")]; } _py___or__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__orig_class__")]; } _py___orig_class__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__origin__")]; } _py___origin__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__package__")]; } _py___package__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__parameters__")]; } _py___parameters__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__path__")]; } _py___path__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__pos__")]; } _py___pos__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__pow__")]; } _py___pow__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__prepare__")]; } _py___prepare__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__qualname__")]; } _py___qualname__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__radd__")]; } _py___radd__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rand__")]; } _py___rand__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rdivmod__")]; } _py___rdivmod__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__reduce__")]; } _py___reduce__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__reduce_ex__")]; } _py___reduce_ex__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__release_buffer__")]; } _py___release_buffer__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__repr__")]; } _py___repr__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__reversed__")]; } _py___reversed__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rfloordiv__")]; } _py___rfloordiv__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rlshift__")]; } _py___rlshift__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rmatmul__")]; } _py___rmatmul__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rmod__")]; } _py___rmod__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rmul__")]; } _py___rmul__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__ror__")]; } _py___ror__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__round__")]; } _py___round__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rpow__")]; } _py___rpow__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rrshift__")]; } _py___rrshift__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rshift__")]; } _py___rshift__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rsub__")]; } _py___rsub__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rtruediv__")]; } _py___rtruediv__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__rxor__")]; } _py___rxor__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__set__")]; } _py___set__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__set_name__")]; } _py___set_name__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__setattr__")]; } _py___setattr__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__setitem__")]; } _py___setitem__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__setstate__")]; } _py___setstate__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__sizeof__")]; } _py___sizeof__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__slotnames__")]; } _py___slotnames__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__slots__")]; } _py___slots__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__spec__")]; } _py___spec__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__str__")]; } _py___str__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__sub__")]; } _py___sub__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__subclasscheck__")]; } _py___subclasscheck__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__subclasshook__")]; } _py___subclasshook__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__truediv__")]; } _py___truediv__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__trunc__")]; } _py___trunc__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__type_params__")]; } _py___type_params__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__typing_is_unpacked_typevartuple__")]; } _py___typing_is_unpacked_typevartuple__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__typing_prepare_subst__")]; } _py___typing_prepare_subst__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__typing_subst__")]; } _py___typing_subst__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__typing_unpacked_tuple_args__")]; } _py___typing_unpacked_tuple_args__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__warningregistry__")]; } _py___warningregistry__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__weaklistoffset__")]; } _py___weaklistoffset__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__weakref__")]; } _py___weakref__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("__xor__")]; } _py___xor__;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_abc_impl")]; } _py__abc_impl;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_abstract_")]; } _py__abstract_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_active")]; } _py__active;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_annotation")]; } _py__annotation;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_anonymous_")]; } _py__anonymous_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_argtypes_")]; } _py__argtypes_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_as_parameter_")]; } _py__as_parameter_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_asyncio_future_blocking")]; } _py__asyncio_future_blocking;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_blksize")]; } _py__blksize;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_bootstrap")]; } _py__bootstrap;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_check_retval_")]; } _py__check_retval_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_dealloc_warn")]; } _py__dealloc_warn;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_feature_version")]; } _py__feature_version;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_fields_")]; } _py__fields_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_finalizing")]; } _py__finalizing;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_find_and_load")]; } _py__find_and_load;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_fix_up_module")]; } _py__fix_up_module;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_flags_")]; } _py__flags_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_get_sourcefile")]; } _py__get_sourcefile;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_handle_fromlist")]; } _py__handle_fromlist;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_initializing")]; } _py__initializing;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_io")]; } _py__io;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_is_text_encoding")]; } _py__is_text_encoding;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_length_")]; } _py__length_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_limbo")]; } _py__limbo;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_lock_unlock_module")]; } _py__lock_unlock_module;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_loop")]; } _py__loop;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_needs_com_addref_")]; } _py__needs_com_addref_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_pack_")]; } _py__pack_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_restype_")]; } _py__restype_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_showwarnmsg")]; } _py__showwarnmsg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_shutdown")]; } _py__shutdown;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_slotnames")]; } _py__slotnames;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_strptime_datetime")]; } _py__strptime_datetime;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_swappedbytes_")]; } _py__swappedbytes_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_type_")]; } _py__type_;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_uninitialized_submodules")]; } _py__uninitialized_submodules;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_warn_unawaited_coroutine")]; } _py__warn_unawaited_coroutine;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("_xoptions")]; } _py__xoptions;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("a")]; } _py_a;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("abs_tol")]; } _py_abs_tol;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("access")]; } _py_access;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("add")]; } _py_add;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("add_done_callback")]; } _py_add_done_callback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("after_in_child")]; } _py_after_in_child;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("after_in_parent")]; } _py_after_in_parent;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("aggregate_class")]; } _py_aggregate_class;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("alias")]; } _py_alias;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("append")]; } _py_append;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("arg")]; } _py_arg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("argdefs")]; } _py_argdefs;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("args")]; } _py_args;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("arguments")]; } _py_arguments;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("argv")]; } _py_argv;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("as_integer_ratio")]; } _py_as_integer_ratio;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ast")]; } _py_ast;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("attribute")]; } _py_attribute;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("authorizer_callback")]; } _py_authorizer_callback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("autocommit")]; } _py_autocommit;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("b")]; } _py_b;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("backtick")]; } _py_backtick;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("base")]; } _py_base;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("before")]; } _py_before;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("big")]; } _py_big;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("binary_form")]; } _py_binary_form;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("block")]; } _py_block;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("bound")]; } _py_bound;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("buffer")]; } _py_buffer;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("buffer_callback")]; } _py_buffer_callback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("buffer_size")]; } _py_buffer_size;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("buffering")]; } _py_buffering;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("buffers")]; } _py_buffers;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("bufsize")]; } _py_bufsize;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("builtins")]; } _py_builtins;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("byteorder")]; } _py_byteorder;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("bytes")]; } _py_bytes;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("bytes_per_sep")]; } _py_bytes_per_sep;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("c")]; } _py_c;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("c_call")]; } _py_c_call;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("c_exception")]; } _py_c_exception;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("c_return")]; } _py_c_return;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cached_statements")]; } _py_cached_statements;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cadata")]; } _py_cadata;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cafile")]; } _py_cafile;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("call")]; } _py_call;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("call_exception_handler")]; } _py_call_exception_handler;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("call_soon")]; } _py_call_soon;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cancel")]; } _py_cancel;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("capath")]; } _py_capath;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("category")]; } _py_category;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cb_type")]; } _py_cb_type;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("certfile")]; } _py_certfile;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("check_same_thread")]; } _py_check_same_thread;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("clear")]; } _py_clear;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("close")]; } _py_close;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("closed")]; } _py_closed;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("closefd")]; } _py_closefd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("closure")]; } _py_closure;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_argcount")]; } _py_co_argcount;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_cellvars")]; } _py_co_cellvars;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_code")]; } _py_co_code;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_consts")]; } _py_co_consts;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_exceptiontable")]; } _py_co_exceptiontable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_filename")]; } _py_co_filename;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_firstlineno")]; } _py_co_firstlineno;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_flags")]; } _py_co_flags;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_freevars")]; } _py_co_freevars;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_kwonlyargcount")]; } _py_co_kwonlyargcount;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_linetable")]; } _py_co_linetable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_name")]; } _py_co_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_names")]; } _py_co_names;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_nlocals")]; } _py_co_nlocals;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_posonlyargcount")]; } _py_co_posonlyargcount;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_qualname")]; } _py_co_qualname;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_stacksize")]; } _py_co_stacksize;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("co_varnames")]; } _py_co_varnames;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("code")]; } _py_code;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("command")]; } _py_command;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("comment_factory")]; } _py_comment_factory;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("compile_mode")]; } _py_compile_mode;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("consts")]; } _py_consts;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("context")]; } _py_context;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("contravariant")]; } _py_contravariant;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cookie")]; } _py_cookie;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("copy")]; } _py_copy;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("copyreg")]; } _py_copyreg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("coro")]; } _py_coro;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("count")]; } _py_count;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("covariant")]; } _py_covariant;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("cwd")]; } _py_cwd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("d")]; } _py_d;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("data")]; } _py_data;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("database")]; } _py_database;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("decode")]; } _py_decode;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("decoder")]; } _py_decoder;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("default")]; } _py_default;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("defaultaction")]; } _py_defaultaction;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("delete")]; } _py_delete;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("depth")]; } _py_depth;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("detect_types")]; } _py_detect_types;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("deterministic")]; } _py_deterministic;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("device")]; } _py_device;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dict")]; } _py_dict;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dictcomp")]; } _py_dictcomp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("difference_update")]; } _py_difference_update;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("digest")]; } _py_digest;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("digest_size")]; } _py_digest_size;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("digestmod")]; } _py_digestmod;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dir_fd")]; } _py_dir_fd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("discard")]; } _py_discard;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dispatch_table")]; } _py_dispatch_table;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("displayhook")]; } _py_displayhook;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dklen")]; } _py_dklen;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("doc")]; } _py_doc;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dont_inherit")]; } _py_dont_inherit;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dst")]; } _py_dst;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("dst_dir_fd")]; } _py_dst_dir_fd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("duration")]; } _py_duration;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("e")]; } _py_e;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("eager_start")]; } _py_eager_start;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("effective_ids")]; } _py_effective_ids;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("element_factory")]; } _py_element_factory;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("encode")]; } _py_encode;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("encoding")]; } _py_encoding;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("end")]; } _py_end;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("end_lineno")]; } _py_end_lineno;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("end_offset")]; } _py_end_offset;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("endpos")]; } _py_endpos;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("entrypoint")]; } _py_entrypoint;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("env")]; } _py_env;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("errors")]; } _py_errors;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("event")]; } _py_event;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("eventmask")]; } _py_eventmask;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("exc_type")]; } _py_exc_type;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("exc_value")]; } _py_exc_value;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("excepthook")]; } _py_excepthook;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("exception")]; } _py_exception;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("existing_file_name")]; } _py_existing_file_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("exp")]; } _py_exp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("extend")]; } _py_extend;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("extra_tokens")]; } _py_extra_tokens;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("facility")]; } _py_facility;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("factory")]; } _py_factory;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("false")]; } _py_false;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("family")]; } _py_family;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fanout")]; } _py_fanout;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fd")]; } _py_fd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fd2")]; } _py_fd2;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fdel")]; } _py_fdel;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fget")]; } _py_fget;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("file")]; } _py_file;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("file_actions")]; } _py_file_actions;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("filename")]; } _py_filename;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fileno")]; } _py_fileno;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("filepath")]; } _py_filepath;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fillvalue")]; } _py_fillvalue;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("filters")]; } _py_filters;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("final")]; } _py_final;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("find_class")]; } _py_find_class;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fix_imports")]; } _py_fix_imports;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("flags")]; } _py_flags;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("flush")]; } _py_flush;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("follow_symlinks")]; } _py_follow_symlinks;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("format")]; } _py_format;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("frequency")]; } _py_frequency;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("from_param")]; } _py_from_param;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fromlist")]; } _py_fromlist;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fromtimestamp")]; } _py_fromtimestamp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fromutc")]; } _py_fromutc;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("fset")]; } _py_fset;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("func")]; } _py_func;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("future")]; } _py_future;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("generation")]; } _py_generation;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("genexpr")]; } _py_genexpr;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("get")]; } _py_get;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("get_debug")]; } _py_get_debug;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("get_event_loop")]; } _py_get_event_loop;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("get_loop")]; } _py_get_loop;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("get_source")]; } _py_get_source;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("getattr")]; } _py_getattr;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("getstate")]; } _py_getstate;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("gid")]; } _py_gid;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("globals")]; } _py_globals;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("groupindex")]; } _py_groupindex;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("groups")]; } _py_groups;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("handle")]; } _py_handle;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("hash_name")]; } _py_hash_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("header")]; } _py_header;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("headers")]; } _py_headers;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("hi")]; } _py_hi;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("hook")]; } _py_hook;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("id")]; } _py_id;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ident")]; } _py_ident;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ignore")]; } _py_ignore;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("imag")]; } _py_imag;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("importlib")]; } _py_importlib;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("in_fd")]; } _py_in_fd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("incoming")]; } _py_incoming;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("indexgroup")]; } _py_indexgroup;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("inf")]; } _py_inf;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("infer_variance")]; } _py_infer_variance;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("inheritable")]; } _py_inheritable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("initial")]; } _py_initial;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("initial_bytes")]; } _py_initial_bytes;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("initial_value")]; } _py_initial_value;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("initval")]; } _py_initval;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("inner_size")]; } _py_inner_size;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("input")]; } _py_input;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("insert_comments")]; } _py_insert_comments;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("insert_pis")]; } _py_insert_pis;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("instructions")]; } _py_instructions;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("intern")]; } _py_intern;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("intersection")]; } _py_intersection;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("is_running")]; } _py_is_running;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("isatty")]; } _py_isatty;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("isinstance")]; } _py_isinstance;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("isoformat")]; } _py_isoformat;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("isolation_level")]; } _py_isolation_level;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("istext")]; } _py_istext;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("item")]; } _py_item;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("items")]; } _py_items;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("iter")]; } _py_iter;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("iterable")]; } _py_iterable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("iterations")]; } _py_iterations;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("join")]; } _py_join;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("jump")]; } _py_jump;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("keepends")]; } _py_keepends;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("key")]; } _py_key;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("keyfile")]; } _py_keyfile;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("keys")]; } _py_keys;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("kind")]; } _py_kind;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("kw")]; } _py_kw;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("kw1")]; } _py_kw1;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("kw2")]; } _py_kw2;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("lambda")]; } _py_lambda;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("last")]; } _py_last;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("last_exc")]; } _py_last_exc;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("last_node")]; } _py_last_node;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("last_traceback")]; } _py_last_traceback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("last_type")]; } _py_last_type;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("last_value")]; } _py_last_value;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("latin1")]; } _py_latin1;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("leaf_size")]; } _py_leaf_size;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("len")]; } _py_len;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("length")]; } _py_length;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("level")]; } _py_level;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("limit")]; } _py_limit;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("line")]; } _py_line;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("line_buffering")]; } _py_line_buffering;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("lineno")]; } _py_lineno;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("listcomp")]; } _py_listcomp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("little")]; } _py_little;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("lo")]; } _py_lo;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("locale")]; } _py_locale;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("locals")]; } _py_locals;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("logoption")]; } _py_logoption;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("loop")]; } _py_loop;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("mapping")]; } _py_mapping;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("match")]; } _py_match;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("max_length")]; } _py_max_length;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("maxdigits")]; } _py_maxdigits;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("maxevents")]; } _py_maxevents;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("maxmem")]; } _py_maxmem;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("maxsplit")]; } _py_maxsplit;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("maxvalue")]; } _py_maxvalue;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("memLevel")]; } _py_memLevel;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("memlimit")]; } _py_memlimit;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("message")]; } _py_message;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("metaclass")]; } _py_metaclass;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("metadata")]; } _py_metadata;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("method")]; } _py_method;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("mod")]; } _py_mod;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("mode")]; } _py_mode;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("module")]; } _py_module;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("module_globals")]; } _py_module_globals;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("modules")]; } _py_modules;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("mro")]; } _py_mro;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("msg")]; } _py_msg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("mycmp")]; } _py_mycmp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("n")]; } _py_n;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("n_arg")]; } _py_n_arg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("n_fields")]; } _py_n_fields;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("n_sequence_fields")]; } _py_n_sequence_fields;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("n_unnamed_fields")]; } _py_n_unnamed_fields;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("name")]; } _py_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("name_from")]; } _py_name_from;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("namespace_separator")]; } _py_namespace_separator;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("namespaces")]; } _py_namespaces;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("narg")]; } _py_narg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ndigits")]; } _py_ndigits;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("new_file_name")]; } _py_new_file_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("new_limit")]; } _py_new_limit;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("newline")]; } _py_newline;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("newlines")]; } _py_newlines;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("next")]; } _py_next;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("nlocals")]; } _py_nlocals;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("node_depth")]; } _py_node_depth;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("node_offset")]; } _py_node_offset;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ns")]; } _py_ns;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("nstype")]; } _py_nstype;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("nt")]; } _py_nt;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("null")]; } _py_null;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("number")]; } _py_number;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("obj")]; } _py_obj;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("object")]; } _py_object;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("offset")]; } _py_offset;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("offset_dst")]; } _py_offset_dst;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("offset_src")]; } _py_offset_src;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("on_type_read")]; } _py_on_type_read;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("onceregistry")]; } _py_onceregistry;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("only_keys")]; } _py_only_keys;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("oparg")]; } _py_oparg;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("opcode")]; } _py_opcode;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("open")]; } _py_open;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("opener")]; } _py_opener;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("operation")]; } _py_operation;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("optimize")]; } _py_optimize;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("options")]; } _py_options;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("order")]; } _py_order;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("origin")]; } _py_origin;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("out_fd")]; } _py_out_fd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("outgoing")]; } _py_outgoing;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("overlapped")]; } _py_overlapped;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("owner")]; } _py_owner;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("p")]; } _py_p;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pages")]; } _py_pages;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("parent")]; } _py_parent;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("password")]; } _py_password;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("path")]; } _py_path;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pattern")]; } _py_pattern;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("peek")]; } _py_peek;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("persistent_id")]; } _py_persistent_id;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("persistent_load")]; } _py_persistent_load;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("person")]; } _py_person;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pi_factory")]; } _py_pi_factory;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pid")]; } _py_pid;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("policy")]; } _py_policy;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pos")]; } _py_pos;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pos1")]; } _py_pos1;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("pos2")]; } _py_pos2;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("posix")]; } _py_posix;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("print_file_and_line")]; } _py_print_file_and_line;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("priority")]; } _py_priority;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("progress")]; } _py_progress;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("progress_handler")]; } _py_progress_handler;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("progress_routine")]; } _py_progress_routine;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("proto")]; } _py_proto;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("protocol")]; } _py_protocol;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ps1")]; } _py_ps1;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("ps2")]; } _py_ps2;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("query")]; } _py_query;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("quotetabs")]; } _py_quotetabs;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("r")]; } _py_r;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("raw")]; } _py_raw;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("read")]; } _py_read;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("read1")]; } _py_read1;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("readable")]; } _py_readable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("readall")]; } _py_readall;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("readinto")]; } _py_readinto;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("readinto1")]; } _py_readinto1;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("readline")]; } _py_readline;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("readonly")]; } _py_readonly;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("real")]; } _py_real;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("reducer_override")]; } _py_reducer_override;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("registry")]; } _py_registry;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("rel_tol")]; } _py_rel_tol;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("release")]; } _py_release;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("reload")]; } _py_reload;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("repl")]; } _py_repl;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("replace")]; } _py_replace;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("reserved")]; } _py_reserved;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("reset")]; } _py_reset;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("resetids")]; } _py_resetids;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("return")]; } _py_return;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("reverse")]; } _py_reverse;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("reversed")]; } _py_reversed;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("s")]; } _py_s;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("salt")]; } _py_salt;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sched_priority")]; } _py_sched_priority;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("scheduler")]; } _py_scheduler;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("seek")]; } _py_seek;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("seekable")]; } _py_seekable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("selectors")]; } _py_selectors;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("self")]; } _py_self;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("send")]; } _py_send;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sep")]; } _py_sep;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sequence")]; } _py_sequence;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("server_hostname")]; } _py_server_hostname;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("server_side")]; } _py_server_side;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("session")]; } _py_session;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("setcomp")]; } _py_setcomp;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("setpgroup")]; } _py_setpgroup;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("setsid")]; } _py_setsid;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("setsigdef")]; } _py_setsigdef;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("setsigmask")]; } _py_setsigmask;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("setstate")]; } _py_setstate;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("shape")]; } _py_shape;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("show_cmd")]; } _py_show_cmd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("signed")]; } _py_signed;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("size")]; } _py_size;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sizehint")]; } _py_sizehint;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("skip_file_prefixes")]; } _py_skip_file_prefixes;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sleep")]; } _py_sleep;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sock")]; } _py_sock;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sort")]; } _py_sort;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sound")]; } _py_sound;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("source")]; } _py_source;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("source_traceback")]; } _py_source_traceback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("src")]; } _py_src;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("src_dir_fd")]; } _py_src_dir_fd;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("stacklevel")]; } _py_stacklevel;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("start")]; } _py_start;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("statement")]; } _py_statement;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("status")]; } _py_status;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("stderr")]; } _py_stderr;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("stdin")]; } _py_stdin;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("stdout")]; } _py_stdout;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("step")]; } _py_step;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("steps")]; } _py_steps;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("store_name")]; } _py_store_name;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("strategy")]; } _py_strategy;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("strftime")]; } _py_strftime;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("strict")]; } _py_strict;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("strict_mode")]; } _py_strict_mode;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("string")]; } _py_string;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("sub_key")]; } _py_sub_key;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("symmetric_difference_update")]; } _py_symmetric_difference_update;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tabsize")]; } _py_tabsize;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tag")]; } _py_tag;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("target")]; } _py_target;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("target_is_directory")]; } _py_target_is_directory;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("task")]; } _py_task;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tb_frame")]; } _py_tb_frame;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tb_lasti")]; } _py_tb_lasti;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tb_lineno")]; } _py_tb_lineno;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tb_next")]; } _py_tb_next;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tell")]; } _py_tell;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("template")]; } _py_template;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("term")]; } _py_term;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("text")]; } _py_text;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("threading")]; } _py_threading;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("throw")]; } _py_throw;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("timeout")]; } _py_timeout;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("times")]; } _py_times;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("timetuple")]; } _py_timetuple;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("top")]; } _py_top;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("trace_callback")]; } _py_trace_callback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("traceback")]; } _py_traceback;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("trailers")]; } _py_trailers;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("translate")]; } _py_translate;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("true")]; } _py_true;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("truncate")]; } _py_truncate;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("twice")]; } _py_twice;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("txt")]; } _py_txt;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("type")]; } _py_type;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("type_params")]; } _py_type_params;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tz")]; } _py_tz;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("tzname")]; } _py_tzname;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("uid")]; } _py_uid;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("unlink")]; } _py_unlink;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("unraisablehook")]; } _py_unraisablehook;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("uri")]; } _py_uri;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("usedforsecurity")]; } _py_usedforsecurity;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("value")]; } _py_value;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("values")]; } _py_values;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("version")]; } _py_version;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("volume")]; } _py_volume;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("warnings")]; } _py_warnings;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("warnoptions")]; } _py_warnoptions;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("wbits")]; } _py_wbits;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("week")]; } _py_week;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("weekday")]; } _py_weekday;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("which")]; } _py_which;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("who")]; } _py_who;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("withdata")]; } _py_withdata;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("writable")]; } _py_writable;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("write")]; } _py_write;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("write_through")]; } _py_write_through;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("x")]; } _py_x;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("year")]; } _py_year;
        struct { PyASCIIObject _ascii; uint8_t _data[sizeof("zdict")]; } _py_zdict;
    } identifiers;
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    } ascii[128];
    struct {
        PyCompactUnicodeObject _latin1;
        uint8_t _data[2];
    } latin1[128];
};
typedef struct {
    PyObject ob_base;
    PyObject *md_dict;
    PyModuleDef *md_def;
    void *md_state;
    PyObject *md_weaklist;
    PyObject *md_name;
} PyModuleObject;
static inline PyModuleDef* _PyModule_GetDef(PyObject *mod) {
    ((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((mod)))), (&PyModule_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((mod)))), (&PyModule_Type))) ; else __assert_fail ("PyModule_Check(mod)", "/usr/include/python3.12/internal/pycore_moduleobject.h", 22, __extension__ __PRETTY_FUNCTION__); }));
    return ((PyModuleObject *)mod)->md_def;
}
static inline void* _PyModule_GetState(PyObject* mod) {
    ((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((mod)))), (&PyModule_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((mod)))), (&PyModule_Type))) ; else __assert_fail ("PyModule_Check(mod)", "/usr/include/python3.12/internal/pycore_moduleobject.h", 27, __extension__ __PRETTY_FUNCTION__); }));
    return ((PyModuleObject *)mod)->md_state;
}
static inline PyObject* _PyModule_GetDict(PyObject *mod) {
    ((void) sizeof ((PyObject_TypeCheck(((PyObject*)(((mod)))), (&PyModule_Type))) ? 1 : 0), __extension__ ({ if (PyObject_TypeCheck(((PyObject*)(((mod)))), (&PyModule_Type))) ; else __assert_fail ("PyModule_Check(mod)", "/usr/include/python3.12/internal/pycore_moduleobject.h", 32, __extension__ __PRETTY_FUNCTION__); }));
    PyObject *dict = ((PyModuleObject *)mod) -> md_dict;
    ((void) sizeof ((dict != ((void *)0)) ? 1 : 0), __extension__ ({ if (dict != ((void *)0)) ; else __assert_fail ("dict != NULL", "/usr/include/python3.12/internal/pycore_moduleobject.h", 35, __extension__ __PRETTY_FUNCTION__); }));
    return dict;
}
PyObject* _Py_module_getattro_impl(PyModuleObject *m, PyObject *name, int suppress);
PyObject* _Py_module_getattro(PyModuleObject *m, PyObject *name);
struct _types_runtime_state {
    unsigned int next_version_tag;
};
struct type_cache_entry {
    unsigned int version;
    PyObject *name;
    PyObject *value;
};
struct type_cache {
    struct type_cache_entry hashtable[1 << 12];
};
typedef struct {
    PyTypeObject *type;
    int readying;
    int ready;
    PyObject *tp_dict;
    PyObject *tp_subclasses;
    PyObject *tp_weaklist;
} static_builtin_state;
struct types_state {
    unsigned int next_version_tag;
    struct type_cache type_cache;
    size_t num_builtins_initialized;
    static_builtin_state builtins[200];
};
extern PyStatus _PyTypes_InitTypes(PyInterpreterState *);
extern void _PyTypes_FiniTypes(PyInterpreterState *);
extern void _PyTypes_Fini(PyInterpreterState *);
typedef struct wrapperbase pytype_slotdef;
static inline PyObject **
_PyStaticType_GET_WEAKREFS_LISTPTR(static_builtin_state *state)
{
    ((void) sizeof ((state != ((void *)0)) ? 1 : 0), __extension__ ({ if (state != ((void *)0)) ; else __assert_fail ("state != NULL", "/usr/include/python3.12/internal/pycore_typeobject.h", 93, __extension__ __PRETTY_FUNCTION__); }));
    return &state->tp_weaklist;
}
static inline void *
_PyType_GetModuleState(PyTypeObject *type)
{
    ((void) sizeof ((PyType_Check(((PyObject*)((type))))) ? 1 : 0), __extension__ ({ if (PyType_Check(((PyObject*)((type))))) ; else __assert_fail ("PyType_Check(type)", "/usr/include/python3.12/internal/pycore_typeobject.h", 102, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((type->tp_flags & (1UL << 9)) ? 1 : 0), __extension__ ({ if (type->tp_flags & (1UL << 9)) ; else __assert_fail ("type->tp_flags & Py_TPFLAGS_HEAPTYPE", "/usr/include/python3.12/internal/pycore_typeobject.h", 103, __extension__ __PRETTY_FUNCTION__); }));
    PyHeapTypeObject *et = (PyHeapTypeObject *)type;
    ((void) sizeof ((et->ht_module) ? 1 : 0), __extension__ ({ if (et->ht_module) ; else __assert_fail ("et->ht_module", "/usr/include/python3.12/internal/pycore_typeobject.h", 105, __extension__ __PRETTY_FUNCTION__); }));
    PyModuleObject *mod = (PyModuleObject *)(et->ht_module);
    ((void) sizeof ((mod != ((void *)0)) ? 1 : 0), __extension__ ({ if (mod != ((void *)0)) ; else __assert_fail ("mod != NULL", "/usr/include/python3.12/internal/pycore_typeobject.h", 107, __extension__ __PRETTY_FUNCTION__); }));
    return mod->md_state;
}
extern int _PyStaticType_InitBuiltin(PyInterpreterState *, PyTypeObject *type);
extern static_builtin_state * _PyStaticType_GetState(PyInterpreterState *, PyTypeObject *);
extern void _PyStaticType_ClearWeakRefs(PyInterpreterState *, PyTypeObject *type);
extern void _PyStaticType_Dealloc(PyInterpreterState *, PyTypeObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyType_GetDict(PyTypeObject *);
extern PyObject * _PyType_GetBases(PyTypeObject *type);
extern PyObject * _PyType_GetMRO(PyTypeObject *type);
extern PyObject* _PyType_GetSubclasses(PyTypeObject *);
extern int _PyType_HasSubclasses(PyTypeObject *);
static inline int
_PyType_IsReady(PyTypeObject *type)
{
    return _PyType_GetDict(type) != ((void *)0);
}
PyObject *
_Py_type_getattro_impl(PyTypeObject *type, PyObject *name, int *suppress_missing_attribute);
PyObject *
_Py_type_getattro(PyTypeObject *type, PyObject *name);
extern PyObject* _Py_BaseObject_RichCompare(PyObject* self, PyObject* other, int op);
PyObject *_Py_slot_tp_getattro(PyObject *self, PyObject *name);
PyObject *_Py_slot_tp_getattr_hook(PyObject *self, PyObject *name);
extern __attribute__ ((visibility ("default"))) PyTypeObject _PyBufferWrapper_Type;
PyObject *
_PySuper_Lookup(PyTypeObject *su_type, PyObject *su_obj, PyObject *name, int *meth_found);
struct _Py_cached_objects {
    _Py_hashtable_t *interned_strings;
};
struct _Py_static_objects {
    struct {
        PyLongObject small_ints[5 + 257];
        PyBytesObject bytes_empty;
        struct {
            PyBytesObject ob;
            char eos;
        } bytes_characters[256];
        struct _Py_global_strings strings;
        PyGC_Head _tuple_empty_gc_not_used;
        PyTupleObject tuple_empty;
        PyGC_Head _hamt_bitmap_node_empty_gc_not_used;
        PyHamtNode_Bitmap hamt_bitmap_node_empty;
        _PyContextTokenMissing context_token_missing;
    } singletons;
};
struct _Py_interp_cached_objects {
    PyObject *interned_strings;
    PyObject *str_replace_inf;
    PyObject *objreduce;
    PyObject *type_slots_pname;
    pytype_slotdef *type_slots_ptrs[10];
    PyTypeObject *generic_type;
    PyTypeObject *typevar_type;
    PyTypeObject *typevartuple_type;
    PyTypeObject *paramspec_type;
    PyTypeObject *paramspecargs_type;
    PyTypeObject *paramspeckwargs_type;
};
struct _Py_interp_static_objects {
    struct {
        int _not_used;
        PyGC_Head _hamt_empty_gc_not_used;
        PyHamtObject hamt_empty;
        PyBaseExceptionObject last_resort_memory_error;
    } singletons;
};
struct _time_runtime_state {
    int ticks_per_second_initialized;
    long ticks_per_second;
};
struct _import_runtime_state {
    struct _inittab *inittab;
    Py_ssize_t last_module_index;
    struct {
        PyThread_type_lock mutex;
        _Py_hashtable_t *hashtable;
    } extensions;
    const char * pkgcontext;
};
struct _import_state {
    PyObject *modules;
    PyObject *modules_by_index;
    PyObject *importlib;
    int override_frozen_modules;
    int override_multi_interp_extensions_check;
    int dlopenflags;
    PyObject *import_func;
    struct {
        PyThread_type_lock mutex;
        unsigned long thread;
        int level;
    } lock;
    struct {
        int import_level;
        _PyTime_t accumulated;
        int header;
    } find_and_load;
};

extern void _dl_mcount_wrapper_check (void *__selfpc) __attribute__ ((__nothrow__ , __leaf__));

typedef long int Lmid_t;

extern void *dlopen (const char *__file, int __mode) __attribute__ ((__nothrow__));
extern int dlclose (void *__handle) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void *dlsym (void *__restrict __handle,
      const char *__restrict __name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern void *dlmopen (Lmid_t __nsid, const char *__file, int __mode) __attribute__ ((__nothrow__));
extern void *dlvsym (void *__restrict __handle,
       const char *__restrict __name,
       const char *__restrict __version)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *dlerror (void) __attribute__ ((__nothrow__ , __leaf__));
typedef struct
{
  const char *dli_fname;
  void *dli_fbase;
  const char *dli_sname;
  void *dli_saddr;
} Dl_info;
extern int dladdr (const void *__address, Dl_info *__info)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int dladdr1 (const void *__address, Dl_info *__info,
      void **__extra_info, int __flags) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
enum
  {
    RTLD_DL_SYMENT = 1,
    RTLD_DL_LINKMAP = 2
  };
extern int dlinfo (void *__restrict __handle,
     int __request, void *__restrict __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
enum
  {
    RTLD_DI_LMID = 1,
    RTLD_DI_LINKMAP = 2,
    RTLD_DI_CONFIGADDR = 3,
    RTLD_DI_SERINFO = 4,
    RTLD_DI_SERINFOSIZE = 5,
    RTLD_DI_ORIGIN = 6,
    RTLD_DI_PROFILENAME = 7,
    RTLD_DI_PROFILEOUT = 8,
    RTLD_DI_TLS_MODID = 9,
    RTLD_DI_TLS_DATA = 10,
    RTLD_DI_PHDR = 11,
    RTLD_DI_MAX = 11
  };
typedef struct
{
  char *dls_name;
  unsigned int dls_flags;
} Dl_serpath;
typedef struct
{
  size_t dls_size;
  unsigned int dls_cnt;
  __extension__ union
  {
    Dl_serpath dls_serpath[0];
    Dl_serpath __dls_serpath_pad[1];
  };
} Dl_serinfo;
struct dl_find_object
{
  __extension__ unsigned long long int dlfo_flags;
  void *dlfo_map_start;
  void *dlfo_map_end;
  struct link_map *dlfo_link_map;
  void *dlfo_eh_frame;
  __extension__ unsigned long long int __dflo_reserved[7];
};
int _dl_find_object (void *__address, struct dl_find_object *__result) __attribute__ ((__nothrow__ , __leaf__));

extern void _PyImport_ClearCore(PyInterpreterState *interp);
extern Py_ssize_t _PyImport_GetNextModuleIndex(void);
extern const char * _PyImport_ResolveNameWithPackageContext(const char *name);
extern const char * _PyImport_SwapPackageContext(const char *newcontext);
extern int _PyImport_GetDLOpenFlags(PyInterpreterState *interp);
extern void _PyImport_SetDLOpenFlags(PyInterpreterState *interp, int new_val);
extern PyObject * _PyImport_InitModules(PyInterpreterState *interp);
extern PyObject * _PyImport_GetModules(PyInterpreterState *interp);
extern void _PyImport_ClearModules(PyInterpreterState *interp);
extern void _PyImport_ClearModulesByIndex(PyInterpreterState *interp);
extern int _PyImport_InitDefaultImportFunc(PyInterpreterState *interp);
extern int _PyImport_IsDefaultImportFunc(
        PyInterpreterState *interp,
        PyObject *func);
extern PyObject * _PyImport_GetImportlibLoader(
        PyInterpreterState *interp,
        const char *loader_name);
extern PyObject * _PyImport_GetImportlibExternalLoader(
        PyInterpreterState *interp,
        const char *loader_name);
extern PyObject * _PyImport_BlessMyLoader(
        PyInterpreterState *interp,
        PyObject *module_globals);
extern PyObject * _PyImport_ImportlibModuleRepr(
        PyInterpreterState *interp,
        PyObject *module);
extern PyStatus _PyImport_Init(void);
extern void _PyImport_Fini(void);
extern void _PyImport_Fini2(void);
extern PyStatus _PyImport_InitCore(
        PyThreadState *tstate,
        PyObject *sysmod,
        int importlib);
extern PyStatus _PyImport_InitExternal(PyThreadState *tstate);
extern void _PyImport_FiniCore(PyInterpreterState *interp);
extern void _PyImport_FiniExternal(PyInterpreterState *interp);
extern PyStatus _PyImport_ReInitLock(PyInterpreterState *interp);
extern PyObject* _PyImport_GetBuiltinModuleNames(void);
struct _module_alias {
    const char *name;
    const char *orig;
};
extern __attribute__ ((visibility ("default"))) const struct _frozen * _PyImport_FrozenBootstrap;
extern __attribute__ ((visibility ("default"))) const struct _frozen * _PyImport_FrozenStdlib;
extern __attribute__ ((visibility ("default"))) const struct _frozen * _PyImport_FrozenTest;
extern const struct _module_alias * _PyImport_FrozenAliases;
__attribute__ ((visibility ("default"))) int _PyImport_CheckSubinterpIncompatibleExtensionAllowed(
    const char *name);
__attribute__ ((visibility ("default"))) int _PyImport_ClearExtension(PyObject *name, PyObject *filename);
static inline uint16_t
_Py_bswap16(uint16_t word)
{
    return __builtin_bswap16(word);
}
static inline uint32_t
_Py_bswap32(uint32_t word)
{
    return __builtin_bswap32(word);
}
static inline uint64_t
_Py_bswap64(uint64_t word)
{
    return __builtin_bswap64(word);
}
static inline int
_Py_popcount32(uint32_t x)
{
    do { (void)(sizeof(char [1 - 2*!(sizeof(x) <= sizeof(unsigned int))]) - 1); } while(0);
    return __builtin_popcount(x);
}
static inline int
_Py_bit_length(unsigned long x)
{
    if (x != 0) {
        return (int)sizeof(unsigned long) * 8 - __builtin_clzl(x);
    }
    else {
        return 0;
    }
}
typedef long int ptrdiff_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
struct _frame {
    PyObject ob_base;
    PyFrameObject *f_back;
    struct _PyInterpreterFrame *f_frame;
    PyObject *f_trace;
    int f_lineno;
    char f_trace_lines;
    char f_trace_opcodes;
    char f_fast_as_locals;
    PyObject *_f_frame_data[1];
};
extern PyFrameObject* _PyFrame_New_NoTrack(PyCodeObject *code);
typedef enum _framestate {
    FRAME_CREATED = -2,
    FRAME_SUSPENDED = -1,
    FRAME_EXECUTING = 0,
    FRAME_COMPLETED = 1,
    FRAME_CLEARED = 4
} PyFrameState;
enum _frameowner {
    FRAME_OWNED_BY_THREAD = 0,
    FRAME_OWNED_BY_GENERATOR = 1,
    FRAME_OWNED_BY_FRAME_OBJECT = 2,
    FRAME_OWNED_BY_CSTACK = 3,
};
typedef struct _PyInterpreterFrame {
    PyCodeObject *f_code;
    struct _PyInterpreterFrame *previous;
    PyObject *f_funcobj;
    PyObject *f_globals;
    PyObject *f_builtins;
    PyObject *f_locals;
    PyFrameObject *frame_obj;
    _Py_CODEUNIT *prev_instr;
    int stacktop;
    uint16_t return_offset;
    char owner;
    PyObject *localsplus[1];
} _PyInterpreterFrame;
static inline PyObject **_PyFrame_Stackbase(_PyInterpreterFrame *f) {
    return f->localsplus + f->f_code->co_nlocalsplus;
}
static inline PyObject *_PyFrame_StackPeek(_PyInterpreterFrame *f) {
    ((void) sizeof ((f->stacktop > f->f_code->co_nlocalsplus) ? 1 : 0), __extension__ ({ if (f->stacktop > f->f_code->co_nlocalsplus) ; else __assert_fail ("f->stacktop > f->f_code->co_nlocalsplus", "/usr/include/python3.12/internal/pycore_frame.h", 85, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((f->localsplus[f->stacktop-1] != ((void *)0)) ? 1 : 0), __extension__ ({ if (f->localsplus[f->stacktop-1] != ((void *)0)) ; else __assert_fail ("f->localsplus[f->stacktop-1] != NULL", "/usr/include/python3.12/internal/pycore_frame.h", 86, __extension__ __PRETTY_FUNCTION__); }));
    return f->localsplus[f->stacktop-1];
}
static inline PyObject *_PyFrame_StackPop(_PyInterpreterFrame *f) {
    ((void) sizeof ((f->stacktop > f->f_code->co_nlocalsplus) ? 1 : 0), __extension__ ({ if (f->stacktop > f->f_code->co_nlocalsplus) ; else __assert_fail ("f->stacktop > f->f_code->co_nlocalsplus", "/usr/include/python3.12/internal/pycore_frame.h", 91, __extension__ __PRETTY_FUNCTION__); }));
    f->stacktop--;
    return f->localsplus[f->stacktop];
}
static inline void _PyFrame_StackPush(_PyInterpreterFrame *f, PyObject *value) {
    f->localsplus[f->stacktop] = value;
    f->stacktop++;
}
static inline int
_PyFrame_NumSlotsForCodeObject(PyCodeObject *code)
{
    ((void) sizeof ((code->co_framesize >= ((int)((sizeof(_PyInterpreterFrame)-1)/sizeof(PyObject *)))) ? 1 : 0), __extension__ ({ if (code->co_framesize >= ((int)((sizeof(_PyInterpreterFrame)-1)/sizeof(PyObject *)))) ; else __assert_fail ("code->co_framesize >= FRAME_SPECIALS_SIZE", "/usr/include/python3.12/internal/pycore_frame.h", 108, __extension__ __PRETTY_FUNCTION__); }));
    return code->co_framesize - ((int)((sizeof(_PyInterpreterFrame)-1)/sizeof(PyObject *)));
}
void _PyFrame_Copy(_PyInterpreterFrame *src, _PyInterpreterFrame *dest);
static inline void
_PyFrame_Initialize(
    _PyInterpreterFrame *frame, PyFunctionObject *func,
    PyObject *locals, PyCodeObject *code, int null_locals_from)
{
    frame->f_funcobj = (PyObject *)func;
    frame->f_code = (PyCodeObject *)_Py_NewRef(((PyObject*)((code))));
    frame->f_builtins = func->func_builtins;
    frame->f_globals = func->func_globals;
    frame->f_locals = locals;
    frame->stacktop = code->co_nlocalsplus;
    frame->frame_obj = ((void *)0);
    frame->prev_instr = ((void)0, ((_Py_CODEUNIT *)(code)->co_code_adaptive)) - 1;
    frame->return_offset = 0;
    frame->owner = FRAME_OWNED_BY_THREAD;
    for (int i = null_locals_from; i < code->co_nlocalsplus; i++) {
        frame->localsplus[i] = ((void *)0);
    }
}
static inline PyObject**
_PyFrame_GetLocalsArray(_PyInterpreterFrame *frame)
{
    return frame->localsplus;
}
static inline PyObject**
_PyFrame_GetStackPointer(_PyInterpreterFrame *frame)
{
    PyObject **sp = frame->localsplus + frame->stacktop;
    frame->stacktop = -1;
    return sp;
}
static inline void
_PyFrame_SetStackPointer(_PyInterpreterFrame *frame, PyObject **stack_pointer)
{
    frame->stacktop = (int)(stack_pointer - frame->localsplus);
}
static inline _Bool
_PyFrame_IsIncomplete(_PyInterpreterFrame *frame)
{
    return frame->owner != FRAME_OWNED_BY_GENERATOR &&
    frame->prev_instr < ((void)0, ((_Py_CODEUNIT *)(frame->f_code)->co_code_adaptive)) + frame->f_code->_co_firsttraceable;
}
static inline _PyInterpreterFrame *
_PyFrame_GetFirstComplete(_PyInterpreterFrame *frame)
{
    while (frame && _PyFrame_IsIncomplete(frame)) {
        frame = frame->previous;
    }
    return frame;
}
static inline _PyInterpreterFrame *
_PyThreadState_GetFrame(PyThreadState *tstate)
{
    return _PyFrame_GetFirstComplete(tstate->cframe->current_frame);
}
PyFrameObject *
_PyFrame_MakeAndSetFrameObject(_PyInterpreterFrame *frame);
static inline PyFrameObject *
_PyFrame_GetFrameObject(_PyInterpreterFrame *frame)
{
    ((void) sizeof ((!_PyFrame_IsIncomplete(frame)) ? 1 : 0), __extension__ ({ if (!_PyFrame_IsIncomplete(frame)) ; else __assert_fail ("!_PyFrame_IsIncomplete(frame)", "/usr/include/python3.12/internal/pycore_frame.h", 208, __extension__ __PRETTY_FUNCTION__); }));
    PyFrameObject *res = frame->frame_obj;
    if (res != ((void *)0)) {
        return res;
    }
    return _PyFrame_MakeAndSetFrameObject(frame);
}
void
_PyFrame_ClearExceptCode(_PyInterpreterFrame * frame);
int
_PyFrame_Traverse(_PyInterpreterFrame *frame, visitproc visit, void *arg);
PyObject *
_PyFrame_GetLocals(_PyInterpreterFrame *frame, int include_hidden);
int
_PyFrame_FastToLocalsWithError(_PyInterpreterFrame *frame);
void
_PyFrame_LocalsToFast(_PyInterpreterFrame *frame, int clear);
static inline _Bool
_PyThreadState_HasStackSpace(PyThreadState *tstate, int size)
{
    ((void) sizeof (((tstate->datastack_top == ((void *)0) && tstate->datastack_limit == ((void *)0)) || (tstate->datastack_top != ((void *)0) && tstate->datastack_limit != ((void *)0))) ? 1 : 0), __extension__ ({ if ((tstate->datastack_top == ((void *)0) && tstate->datastack_limit == ((void *)0)) || (tstate->datastack_top != ((void *)0) && tstate->datastack_limit != ((void *)0))) ; else __assert_fail ("(tstate->datastack_top == NULL && tstate->datastack_limit == NULL) || (tstate->datastack_top != NULL && tstate->datastack_limit != NULL)", "/usr/include/python3.12/internal/pycore_frame.h", 243, __extension__ __PRETTY_FUNCTION__); }));
    return tstate->datastack_top != ((void *)0) &&
        size < tstate->datastack_limit - tstate->datastack_top;
}
extern _PyInterpreterFrame *
_PyThreadState_PushFrame(PyThreadState *tstate, size_t size);
void _PyThreadState_PopFrame(PyThreadState *tstate, _PyInterpreterFrame *frame);
static inline _PyInterpreterFrame *
_PyFrame_PushUnchecked(PyThreadState *tstate, PyFunctionObject *func, int null_locals_from)
{
    ((void)0);
    PyCodeObject *code = (PyCodeObject *)func->func_code;
    _PyInterpreterFrame *new_frame = (_PyInterpreterFrame *)tstate->datastack_top;
    tstate->datastack_top += code->co_framesize;
    ((void) sizeof ((tstate->datastack_top < tstate->datastack_limit) ? 1 : 0), __extension__ ({ if (tstate->datastack_top < tstate->datastack_limit) ; else __assert_fail ("tstate->datastack_top < tstate->datastack_limit", "/usr/include/python3.12/internal/pycore_frame.h", 267, __extension__ __PRETTY_FUNCTION__); }));
    _PyFrame_Initialize(new_frame, func, ((void *)0), code, null_locals_from);
    return new_frame;
}
static inline
PyGenObject *_PyFrame_GetGenerator(_PyInterpreterFrame *frame)
{
    ((void) sizeof ((frame->owner == FRAME_OWNED_BY_GENERATOR) ? 1 : 0), __extension__ ({ if (frame->owner == FRAME_OWNED_BY_GENERATOR) ; else __assert_fail ("frame->owner == FRAME_OWNED_BY_GENERATOR", "/usr/include/python3.12/internal/pycore_frame.h", 275, __extension__ __PRETTY_FUNCTION__); }));
    size_t offset_in_gen = __builtin_offsetof (PyGenObject, gi_iframe);
    return (PyGenObject *)(((char *)frame) - offset_in_gen);
}
typedef uint32_t _PyMonitoringEventSet;
PyObject *_PyMonitoring_RegisterCallback(int tool_id, int event_id, PyObject *obj);
int _PyMonitoring_SetEvents(int tool_id, _PyMonitoringEventSet events);
extern int
_Py_call_instrumentation(PyThreadState *tstate, int event,
    _PyInterpreterFrame *frame, _Py_CODEUNIT *instr);
extern int
_Py_call_instrumentation_line(PyThreadState *tstate, _PyInterpreterFrame* frame,
                              _Py_CODEUNIT *instr, _Py_CODEUNIT *prev);
extern int
_Py_call_instrumentation_instruction(
    PyThreadState *tstate, _PyInterpreterFrame* frame, _Py_CODEUNIT *instr);
_Py_CODEUNIT *
_Py_call_instrumentation_jump(
    PyThreadState *tstate, int event,
    _PyInterpreterFrame *frame, _Py_CODEUNIT *instr, _Py_CODEUNIT *target);
extern int
_Py_call_instrumentation_arg(PyThreadState *tstate, int event,
    _PyInterpreterFrame *frame, _Py_CODEUNIT *instr, PyObject *arg);
extern int
_Py_call_instrumentation_2args(PyThreadState *tstate, int event,
    _PyInterpreterFrame *frame, _Py_CODEUNIT *instr, PyObject *arg0, PyObject *arg1);
extern void
_Py_call_instrumentation_exc2(PyThreadState *tstate, int event,
    _PyInterpreterFrame *frame, _Py_CODEUNIT *instr, PyObject *arg0, PyObject *arg1);
extern int
_Py_Instrumentation_GetLine(PyCodeObject *code, int index);
extern PyObject _PyInstrumentation_MISSING;
extern PyObject _PyInstrumentation_DISABLE;
extern void _PyList_Fini(PyInterpreterState *);
struct _Py_list_state {
    PyListObject *free_list[80];
    int numfree;
};
extern int
_PyList_AppendTakeRefListResize(PyListObject *self, PyObject *newitem);
static inline int
_PyList_AppendTakeRef(PyListObject *self, PyObject *newitem)
{
    ((void) sizeof ((self != ((void *)0) && newitem != ((void *)0)) ? 1 : 0), __extension__ ({ if (self != ((void *)0) && newitem != ((void *)0)) ; else __assert_fail ("self != NULL && newitem != NULL", "/usr/include/python3.12/internal/pycore_list.h", 46, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(self)", "/usr/include/python3.12/internal/pycore_list.h", 47, __extension__ __PRETTY_FUNCTION__); }));
    Py_ssize_t len = PyList_GET_SIZE(((PyObject*)((self))));
    Py_ssize_t allocated = self->allocated;
    ((void) sizeof (((size_t)len + 1 < 0x7fffffffffffffffL) ? 1 : 0), __extension__ ({ if ((size_t)len + 1 < 0x7fffffffffffffffL) ; else __assert_fail ("(size_t)len + 1 < PY_SSIZE_T_MAX", "/usr/include/python3.12/internal/pycore_list.h", 50, __extension__ __PRETTY_FUNCTION__); }));
    if (allocated > len) {
        PyList_SET_ITEM(((PyObject*)((self))), (len), ((PyObject*)((newitem))));
        Py_SET_SIZE(((PyVarObject*)((self))), (len + 1));
        return 0;
    }
    return _PyList_AppendTakeRefListResize(self, newitem);
}
static inline void
_Py_memory_repeat(char* dest, Py_ssize_t len_dest, Py_ssize_t len_src)
{
    ((void) sizeof ((len_src > 0) ? 1 : 0), __extension__ ({ if (len_src > 0) ; else __assert_fail ("len_src > 0", "/usr/include/python3.12/internal/pycore_list.h", 63, __extension__ __PRETTY_FUNCTION__); }));
    Py_ssize_t copied = len_src;
    while (copied < len_dest) {
        Py_ssize_t bytes_to_copy = (((copied) > (len_dest - copied)) ? (len_dest - copied) : (copied));
        memcpy(dest + copied, dest, bytes_to_copy);
        copied += bytes_to_copy;
    }
}
typedef struct {
    PyObject ob_base;
    Py_ssize_t it_index;
    PyListObject *it_seq;
} _PyListIterObject;
extern PyObject *_PyList_FromArraySteal(PyObject *const *src, Py_ssize_t n);
struct _py_object_runtime_state {
    int _not_used;
};
struct _py_object_state {
    int _not_used;
};
typedef unsigned int pymem_uint;
typedef uint8_t pymem_block;
struct pool_header {
    union { pymem_block *_padding;
            pymem_uint count; } ref;
    pymem_block *freeblock;
    struct pool_header *nextpool;
    struct pool_header *prevpool;
    pymem_uint arenaindex;
    pymem_uint szidx;
    pymem_uint nextoffset;
    pymem_uint maxnextoffset;
};
typedef struct pool_header *poolp;
struct arena_object {
    uintptr_t address;
    pymem_block* pool_address;
    pymem_uint nfreepools;
    pymem_uint ntotalpools;
    struct pool_header* freepools;
    struct arena_object* nextarena;
    struct arena_object* prevarena;
};
struct _obmalloc_pools {
    poolp used[(2 * (((512 / 16) + 7) / 8) * 8)];
};
struct _obmalloc_mgmt {
    struct arena_object* arenas;
    pymem_uint maxarenas;
    struct arena_object* unused_arena_objects;
    struct arena_object* usable_arenas;
    struct arena_object* nfp2lasta[((1 << 20) / (1 << 14)) + 1];
    size_t narenas_currently_allocated;
    size_t ntimes_arena_allocated;
    size_t narenas_highwater;
    Py_ssize_t raw_allocated_blocks;
};
typedef struct {
    int32_t tail_hi;
    int32_t tail_lo;
} arena_coverage_t;
typedef struct arena_map_bot {
    arena_coverage_t arenas[(1 << ((64 - 0) - 20 - 2*(((64 - 0) - 20 + 2) / 3)))];
} arena_map_bot_t;
typedef struct arena_map_mid {
    struct arena_map_bot *ptrs[(1 << (((64 - 0) - 20 + 2) / 3))];
} arena_map_mid_t;
typedef struct arena_map_top {
    struct arena_map_mid *ptrs[(1 << (((64 - 0) - 20 + 2) / 3))];
} arena_map_top_t;
struct _obmalloc_usage {
    arena_map_top_t arena_map_root;
    int arena_map_mid_count;
    int arena_map_bot_count;
};
struct _obmalloc_global_state {
    int dump_debug_stats;
    Py_ssize_t interpreter_leaks;
};
struct _obmalloc_state {
    struct _obmalloc_pools pools;
    struct _obmalloc_mgmt mgmt;
    struct _obmalloc_usage usage;
};
void *_PyObject_VirtualAlloc(size_t size);
void _PyObject_VirtualFree(void *, size_t size);
extern Py_ssize_t _Py_GetGlobalAllocatedBlocks(void);
extern Py_ssize_t _PyInterpreterState_GetAllocatedBlocks(PyInterpreterState *);
extern void _PyInterpreterState_FinalizeAllocatedBlocks(PyInterpreterState *);
__attribute__ ((visibility ("default"))) int _PyObject_DebugMallocStats(FILE *out);
extern PyStatus _PyTuple_InitGlobalObjects(PyInterpreterState *);
extern void _PyTuple_Fini(PyInterpreterState *);
struct _Py_tuple_state {
    PyTupleObject *free_list[20];
    int numfree[20];
};
extern PyObject *_PyTuple_FromArray(PyObject *const *, Py_ssize_t);
extern PyObject *_PyTuple_FromArraySteal(PyObject *const *, Py_ssize_t);
typedef struct {
    PyObject ob_base;
    Py_ssize_t it_index;
    PyTupleObject *it_seq;
} _PyTupleIterObject;

struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
extern char *setlocale (int __category, const char *__locale) __attribute__ ((__nothrow__ , __leaf__));
extern struct lconv *localeconv (void) __attribute__ ((__nothrow__ , __leaf__));
extern locale_t newlocale (int __category_mask, const char *__locale,
      locale_t __base) __attribute__ ((__nothrow__ , __leaf__));
extern locale_t duplocale (locale_t __dataset) __attribute__ ((__nothrow__ , __leaf__));
extern void freelocale (locale_t __dataset) __attribute__ ((__nothrow__ , __leaf__));
extern locale_t uselocale (locale_t __dataset) __attribute__ ((__nothrow__ , __leaf__));

struct _fileutils_state {
    int force_ascii;
};
typedef enum {
    _Py_ERROR_UNKNOWN=0,
    _Py_ERROR_STRICT,
    _Py_ERROR_SURROGATEESCAPE,
    _Py_ERROR_REPLACE,
    _Py_ERROR_IGNORE,
    _Py_ERROR_BACKSLASHREPLACE,
    _Py_ERROR_SURROGATEPASS,
    _Py_ERROR_XMLCHARREFREPLACE,
    _Py_ERROR_OTHER
} _Py_error_handler;
__attribute__ ((visibility ("default"))) _Py_error_handler _Py_GetErrorHandler(const char *errors);
__attribute__ ((visibility ("default"))) int _Py_DecodeLocaleEx(
    const char *arg,
    wchar_t **wstr,
    size_t *wlen,
    const char **reason,
    int current_locale,
    _Py_error_handler errors);
__attribute__ ((visibility ("default"))) int _Py_EncodeLocaleEx(
    const wchar_t *text,
    char **str,
    size_t *error_pos,
    const char **reason,
    int current_locale,
    _Py_error_handler errors);
__attribute__ ((visibility ("default"))) char* _Py_EncodeLocaleRaw(
    const wchar_t *text,
    size_t *error_pos);
__attribute__ ((visibility ("default"))) PyObject * _Py_device_encoding(int);
__attribute__ ((visibility ("default"))) int _Py_fstat(
    int fd,
    struct stat *status);
__attribute__ ((visibility ("default"))) int _Py_fstat_noraise(
    int fd,
    struct stat *status);
__attribute__ ((visibility ("default"))) int _Py_stat(
    PyObject *path,
    struct stat *status);
__attribute__ ((visibility ("default"))) int _Py_open(
    const char *pathname,
    int flags);
__attribute__ ((visibility ("default"))) int _Py_open_noraise(
    const char *pathname,
    int flags);
__attribute__ ((visibility ("default"))) FILE * _Py_wfopen(
    const wchar_t *path,
    const wchar_t *mode);
__attribute__ ((visibility ("default"))) Py_ssize_t _Py_read(
    int fd,
    void *buf,
    size_t count);
__attribute__ ((visibility ("default"))) Py_ssize_t _Py_write(
    int fd,
    const void *buf,
    size_t count);
__attribute__ ((visibility ("default"))) Py_ssize_t _Py_write_noraise(
    int fd,
    const void *buf,
    size_t count);
__attribute__ ((visibility ("default"))) int _Py_wreadlink(
    const wchar_t *path,
    wchar_t *buf,
    size_t buflen);
__attribute__ ((visibility ("default"))) wchar_t* _Py_wrealpath(
    const wchar_t *path,
    wchar_t *resolved_path,
    size_t resolved_path_len);
__attribute__ ((visibility ("default"))) wchar_t* _Py_wgetcwd(
    wchar_t *buf,
    size_t buflen);
__attribute__ ((visibility ("default"))) int _Py_get_inheritable(int fd);
__attribute__ ((visibility ("default"))) int _Py_set_inheritable(int fd, int inheritable,
                                    int *atomic_flag_works);
__attribute__ ((visibility ("default"))) int _Py_set_inheritable_async_safe(int fd, int inheritable,
                                               int *atomic_flag_works);
__attribute__ ((visibility ("default"))) int _Py_dup(int fd);
__attribute__ ((visibility ("default"))) int _Py_get_blocking(int fd);
__attribute__ ((visibility ("default"))) int _Py_set_blocking(int fd, int blocking);
extern __attribute__ ((visibility ("default"))) int _Py_HasFileSystemDefaultEncodeErrors;
__attribute__ ((visibility ("default"))) int _Py_DecodeUTF8Ex(
    const char *arg,
    Py_ssize_t arglen,
    wchar_t **wstr,
    size_t *wlen,
    const char **reason,
    _Py_error_handler errors);
__attribute__ ((visibility ("default"))) int _Py_EncodeUTF8Ex(
    const wchar_t *text,
    char **str,
    size_t *error_pos,
    const char **reason,
    int raw_malloc,
    _Py_error_handler errors);
__attribute__ ((visibility ("default"))) wchar_t* _Py_DecodeUTF8_surrogateescape(
    const char *arg,
    Py_ssize_t arglen,
    size_t *wlen);
extern int
_Py_wstat(const wchar_t *, struct stat *);
__attribute__ ((visibility ("default"))) int _Py_GetForceASCII(void);
__attribute__ ((visibility ("default"))) void _Py_ResetForceASCII(void);
__attribute__ ((visibility ("default"))) int _Py_GetLocaleconvNumeric(
    struct lconv *lc,
    PyObject **decimal_point,
    PyObject **thousands_sep);
__attribute__ ((visibility ("default"))) void _Py_closerange(int first, int last);
__attribute__ ((visibility ("default"))) wchar_t* _Py_GetLocaleEncoding(void);
__attribute__ ((visibility ("default"))) PyObject* _Py_GetLocaleEncodingObject(void);
extern int _Py_isabs(const wchar_t *path);
extern int _Py_abspath(const wchar_t *path, wchar_t **abspath_p);
extern wchar_t * _Py_join_relfile(const wchar_t *dirname,
                                  const wchar_t *relfile);
extern int _Py_add_relfile(wchar_t *dirname,
                           const wchar_t *relfile,
                           size_t bufsize);
extern size_t _Py_find_basename(const wchar_t *filename);
__attribute__ ((visibility ("default"))) wchar_t* _Py_normpath(wchar_t *path, Py_ssize_t size);
extern wchar_t *_Py_normpath_and_size(wchar_t *path, Py_ssize_t size, Py_ssize_t *length);
typedef struct {
    int (*getname)(Py_UCS4 code, char* buffer, int buflen,
                   int with_alias_and_seq);
    int (*getcode)(const char* name, int namelen, Py_UCS4* code,
                   int with_named_seq);
} _PyUnicode_Name_CAPI;
void _PyUnicode_ExactDealloc(PyObject *op);
Py_ssize_t _PyUnicode_InternedSize(void);
extern void _PyUnicode_InitState(PyInterpreterState *);
extern PyStatus _PyUnicode_InitGlobalObjects(PyInterpreterState *);
extern PyStatus _PyUnicode_InitTypes(PyInterpreterState *);
extern void _PyUnicode_Fini(PyInterpreterState *);
extern void _PyUnicode_FiniTypes(PyInterpreterState *);
extern PyTypeObject _PyUnicodeASCIIIter_Type;
struct _Py_unicode_runtime_ids {
    PyThread_type_lock lock;
    Py_ssize_t next_index;
};
struct _Py_unicode_runtime_state {
    struct _Py_unicode_runtime_ids ids;
};
struct _Py_unicode_fs_codec {
    char *encoding;
    int utf8;
    char *errors;
    _Py_error_handler error_handler;
};
struct _Py_unicode_ids {
    Py_ssize_t size;
    PyObject **array;
};
struct _Py_unicode_state {
    struct _Py_unicode_fs_codec fs_codec;
    _PyUnicode_Name_CAPI *ucnhash_capi;
    struct _Py_unicode_ids ids;
};
extern void _PyUnicode_InternInPlace(PyInterpreterState *interp, PyObject **p);
extern void _PyUnicode_ClearInterned(PyInterpreterState *interp);
struct _warnings_runtime_state {
    PyObject *filters;
    PyObject *once_registry;
    PyObject *default_action;
    long filters_version;
};
extern int _PyWarnings_InitState(PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) PyObject* _PyWarnings_Init(void);
extern void _PyErr_WarnUnawaitedCoroutine(PyObject *coro);
struct _Py_long_state {
    int max_str_digits;
};
struct _xidregitem;
struct _xidregitem {
    struct _xidregitem *prev;
    struct _xidregitem *next;
    PyTypeObject *cls;
    PyObject *weakref;
    size_t refcount;
    crossinterpdatafunc getdata;
};
struct _xidregistry {
    PyThread_type_lock mutex;
    struct _xidregitem *head;
};
struct _is {
    PyInterpreterState *next;
    int64_t id;
    int64_t id_refcount;
    int requires_idref;
    PyThread_type_lock id_mutex;
    int _initialized;
    int finalizing;
    uint64_t monitoring_version;
    uint64_t last_restart_version;
    struct pythreads {
        uint64_t next_unique_id;
        PyThreadState *head;
        long count;
        size_t stacksize;
    } threads;
    struct pyruntimestate *runtime;
    _Py_atomic_address _finalizing;
    struct _gc_runtime_state gc;
    PyObject *sysdict;
    PyObject *builtins;
    struct _ceval_state ceval;
    struct _import_state imports;
    struct _gil_runtime_state _gil;
    PyObject *codec_search_path;
    PyObject *codec_search_cache;
    PyObject *codec_error_registry;
    int codecs_initialized;
    PyConfig config;
    unsigned long feature_flags;
    PyObject *dict;
    PyObject *sysdict_copy;
    PyObject *builtins_copy;
    _PyFrameEvalFunction eval_frame;
    PyFunction_WatchCallback func_watchers[8];
    uint8_t active_func_watchers;
    Py_ssize_t co_extra_user_count;
    freefunc co_extra_freefuncs[255];
    PyObject *before_forkers;
    PyObject *after_forkers_parent;
    PyObject *after_forkers_child;
    struct _warnings_runtime_state warnings;
    struct atexit_state atexit;
    struct _obmalloc_state obmalloc;
    PyObject *audit_hooks;
    PyType_WatchCallback type_watchers[8];
    PyCode_WatchCallback code_watchers[8];
    uint8_t active_code_watchers;
    struct _py_object_state object_state;
    struct _Py_unicode_state unicode;
    struct _Py_float_state float_state;
    struct _Py_long_state long_state;
    struct _dtoa_state dtoa;
    struct _py_func_state func_state;
    PySliceObject *slice_cache;
    struct _Py_tuple_state tuple;
    struct _Py_list_state list;
    struct _Py_dict_state dict_state;
    struct _Py_async_gen_state async_gen;
    struct _Py_context_state context;
    struct _Py_exc_state exc_state;
    struct ast_state ast;
    struct types_state types;
    struct callable_cache callable_cache;
    PyCodeObject *interpreter_trampoline;
    _Py_GlobalMonitors monitors;
    _Bool f_opcode_trace_set;
    _Bool sys_profile_initialized;
    _Bool sys_trace_initialized;
    Py_ssize_t sys_profiling_threads;
    Py_ssize_t sys_tracing_threads;
    PyObject *monitoring_callables[8][17];
    PyObject *monitoring_tool_names[8];
    struct _Py_interp_cached_objects cached_objects;
    struct _Py_interp_static_objects static_objects;
    struct _xidregistry xidregistry;
    PyThreadState *threads_main;
    _Py_atomic_address _finalizing_id;
    PyThreadState _initial_thread;
};
extern void _PyInterpreterState_Clear(PyThreadState *tstate);
static inline PyThreadState*
_PyInterpreterState_GetFinalizing(PyInterpreterState *interp) {
    return (PyThreadState*)__extension__ ({ __auto_type __atomic_load_ptr = (&(((&interp->_finalizing))->_value)); __typeof__ ((void)0, *__atomic_load_ptr) __atomic_load_tmp; __atomic_load (__atomic_load_ptr, &__atomic_load_tmp, (_Py_memory_order_relaxed)); __atomic_load_tmp; });
}
static inline unsigned long
_PyInterpreterState_GetFinalizingID(PyInterpreterState *interp) {
    return (unsigned long)__extension__ ({ __auto_type __atomic_load_ptr = (&(((&interp->_finalizing_id))->_value)); __typeof__ ((void)0, *__atomic_load_ptr) __atomic_load_tmp; __atomic_load (__atomic_load_ptr, &__atomic_load_tmp, (_Py_memory_order_relaxed)); __atomic_load_tmp; });
}
static inline void
_PyInterpreterState_SetFinalizing(PyInterpreterState *interp, PyThreadState *tstate) {
    __extension__ ({ __auto_type __atomic_store_ptr = (&(((&interp->_finalizing))->_value)); __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = (((uintptr_t)tstate)); __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (_Py_memory_order_relaxed)); });
    if (tstate == ((void *)0)) {
        __extension__ ({ __auto_type __atomic_store_ptr = (&(((&interp->_finalizing_id))->_value)); __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = ((0)); __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (_Py_memory_order_relaxed)); });
    }
    else {
        __extension__ ({ __auto_type __atomic_store_ptr = (&(((&interp->_finalizing_id))->_value)); __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = (((uintptr_t)tstate->thread_id)); __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (_Py_memory_order_relaxed)); });
    }
}
__attribute__ ((visibility ("default"))) PyInterpreterState* _PyInterpreterState_LookUpID(int64_t);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_IDInitref(PyInterpreterState *);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_IDIncref(PyInterpreterState *);
__attribute__ ((visibility ("default"))) void _PyInterpreterState_IDDecref(PyInterpreterState *);

typedef __sig_atomic_t sig_atomic_t;
union sigval
{
  int sival_int;
  void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct
  {
    int si_signo;
    int si_errno;
    int si_code;
    int __pad0;
    union
      {
 int _pad[((128 / sizeof (int)) - 4)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     __sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     __sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
    
     short int si_addr_lsb;
     union
       {
  struct
    {
      void *_lower;
      void *_upper;
    } _addr_bnd;
  __uint32_t _pkey;
       } _bounds;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;
      } _sifields;
  } siginfo_t ;
enum
{
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,
  SI_TKILL,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK,
  ILL_BADIADDR
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB,
  FPE_FLTUNK = 14,
  FPE_CONDTRAP
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR,
  SEGV_BNDERR,
  SEGV_PKUERR,
  SEGV_ACCADI,
  SEGV_ADIDERR,
  SEGV_ADIPERR,
  SEGV_MTEAERR,
  SEGV_MTESERR,
  SEGV_CPERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR,
  BUS_MCEERR_AR,
  BUS_MCEERR_AO
};
enum
{
  TRAP_BRKPT = 1,
  TRAP_TRACE,
  TRAP_BRANCH,
  TRAP_HWBKPT,
  TRAP_UNK
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
typedef __sigval_t sigval_t;
typedef struct sigevent
  {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 4)];
 __pid_t _tid;
 struct
   {
     void (*_function) (__sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern void psignal (int __sig, const char *__s);
extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
extern int sigpause (int __sig) __asm__ ("__xpg_sigpause")
  __attribute__ ((__deprecated__ ("Use the sigsuspend function instead")));
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
typedef __sighandler_t sighandler_t;
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigisemptyset (const sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigandset (sigset_t *__set, const sigset_t *__left,
        const sigset_t *__right) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int sigorset (sigset_t *__set, const sigset_t *__left,
       const sigset_t *__right) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));
extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));
struct _fpx_sw_bytes
{
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t __glibc_reserved1[7];
};
struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};
struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short __glibc_reserved1[3];
};
struct _xmmreg
{
  __uint32_t element[4];
};
struct _fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};
struct sigcontext
{
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  __extension__ union
    {
      struct _fpstate * fpstate;
      __uint64_t __fpstate_word;
    };
  __uint64_t __reserved1 [8];
};
struct _xsave_hdr
{
  __uint64_t xstate_bv;
  __uint64_t __glibc_reserved1[2];
  __uint64_t __glibc_reserved2[5];
};
struct _ymmh_state
{
  __uint32_t ymmh_space[64];
};
struct _xstate
{
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));
typedef struct
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];
enum
{
  REG_R8 = 0,
  REG_R9,
  REG_R10,
  REG_R11,
  REG_R12,
  REG_R13,
  REG_R14,
  REG_R15,
  REG_RDI,
  REG_RSI,
  REG_RBP,
  REG_RBX,
  REG_RDX,
  REG_RAX,
  REG_RCX,
  REG_RSP,
  REG_RIP,
  REG_EFL,
  REG_CSGSFS,
  REG_ERR,
  REG_TRAPNO,
  REG_OLDMASK,
  REG_CR2
};
struct _libc_fpxreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int __glibc_reserved1[3];
};
struct _libc_xmmreg
{
  __uint32_t element[4];
};
struct _libc_fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};
typedef struct _libc_fpstate *fpregset_t;
typedef struct
  {
    gregset_t gregs;
    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1 [8];
} mcontext_t;
typedef struct ucontext_t
  {
    unsigned long int uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
    __extension__ unsigned long long int __ssp[4];
  } ucontext_t;
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use sigaction with SA_RESTART instead")));
enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
extern int sigaltstack (const stack_t *__restrict __ss,
   stack_t *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sighold (int __sig) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the sigprocmask function instead")));
extern int sigrelse (int __sig) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the sigprocmask function instead")));
extern int sigignore (int __sig) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the signal function instead")));
extern __sighandler_t sigset (int __sig, __sighandler_t __disp) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__deprecated__ ("Use the signal and sigprocmask functions instead")));
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_sigqueue (pthread_t __threadid, int __signo,
        const union sigval __value) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));
extern int tgkill (__pid_t __tgid, __pid_t __tid, int __signal);

typedef struct sigaction _Py_sighandler_t;
struct faulthandler_user_signal {
    int enabled;
    PyObject *file;
    int fd;
    int all_threads;
    int chain;
    _Py_sighandler_t previous;
    PyInterpreterState *interp;
};
struct _faulthandler_runtime_state {
    struct {
        int enabled;
        PyObject *file;
        int fd;
        int all_threads;
        PyInterpreterState *interp;
    } fatal_error;
    struct {
        PyObject *file;
        int fd;
        long long timeout_us;
        int repeat;
        PyInterpreterState *interp;
        int exit;
        char *header;
        size_t header_len;
        PyThread_type_lock cancel_event;
        PyThread_type_lock running;
    } thread;
    struct faulthandler_user_signal *user_signals;
    stack_t stack;
    stack_t old_stack;
};
typedef struct _arena PyArena;
__attribute__ ((visibility ("default"))) PyArena* _PyArena_New(void);
__attribute__ ((visibility ("default"))) void _PyArena_Free(PyArena *);
__attribute__ ((visibility ("default"))) void* _PyArena_Malloc(PyArena *, size_t size);
__attribute__ ((visibility ("default"))) int _PyArena_AddPyObject(PyArena *, PyObject *);
typedef PyObject * identifier;
typedef PyObject * string;
typedef PyObject * object;
typedef PyObject * constant;
typedef struct {
    Py_ssize_t size; void **elements;
} asdl_seq;
typedef struct {
    Py_ssize_t size; void **elements;
    void *typed_elements[1];
} asdl_generic_seq;
typedef struct {
    Py_ssize_t size; void **elements;
    PyObject *typed_elements[1];
} asdl_identifier_seq;
typedef struct {
    Py_ssize_t size; void **elements;
    int typed_elements[1];
} asdl_int_seq;
asdl_generic_seq *_Py_asdl_generic_seq_new(Py_ssize_t size, PyArena *arena);
asdl_identifier_seq *_Py_asdl_identifier_seq_new(Py_ssize_t size, PyArena *arena);
asdl_int_seq *_Py_asdl_int_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct _mod *mod_ty;
typedef struct _stmt *stmt_ty;
typedef struct _expr *expr_ty;
typedef enum _expr_context { Load=1, Store=2, Del=3 } expr_context_ty;
typedef enum _boolop { And=1, Or=2 } boolop_ty;
typedef enum _operator { Add=1, Sub=2, Mult=3, MatMult=4, Div=5, Mod=6, Pow=7,
                         LShift=8, RShift=9, BitOr=10, BitXor=11, BitAnd=12,
                         FloorDiv=13 } operator_ty;
typedef enum _unaryop { Invert=1, Not=2, UAdd=3, USub=4 } unaryop_ty;
typedef enum _cmpop { Eq=1, NotEq=2, Lt=3, LtE=4, Gt=5, GtE=6, Is=7, IsNot=8,
                      In=9, NotIn=10 } cmpop_ty;
typedef struct _comprehension *comprehension_ty;
typedef struct _excepthandler *excepthandler_ty;
typedef struct _arguments *arguments_ty;
typedef struct _arg *arg_ty;
typedef struct _keyword *keyword_ty;
typedef struct _alias *alias_ty;
typedef struct _withitem *withitem_ty;
typedef struct _match_case *match_case_ty;
typedef struct _pattern *pattern_ty;
typedef struct _type_ignore *type_ignore_ty;
typedef struct _type_param *type_param_ty;
typedef struct {
    Py_ssize_t size; void **elements;
    mod_ty typed_elements[1];
} asdl_mod_seq;
asdl_mod_seq *_Py_asdl_mod_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    stmt_ty typed_elements[1];
} asdl_stmt_seq;
asdl_stmt_seq *_Py_asdl_stmt_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    expr_ty typed_elements[1];
} asdl_expr_seq;
asdl_expr_seq *_Py_asdl_expr_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    comprehension_ty typed_elements[1];
} asdl_comprehension_seq;
asdl_comprehension_seq *_Py_asdl_comprehension_seq_new(Py_ssize_t size, PyArena
                                                       *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    excepthandler_ty typed_elements[1];
} asdl_excepthandler_seq;
asdl_excepthandler_seq *_Py_asdl_excepthandler_seq_new(Py_ssize_t size, PyArena
                                                       *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    arguments_ty typed_elements[1];
} asdl_arguments_seq;
asdl_arguments_seq *_Py_asdl_arguments_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    arg_ty typed_elements[1];
} asdl_arg_seq;
asdl_arg_seq *_Py_asdl_arg_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    keyword_ty typed_elements[1];
} asdl_keyword_seq;
asdl_keyword_seq *_Py_asdl_keyword_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    alias_ty typed_elements[1];
} asdl_alias_seq;
asdl_alias_seq *_Py_asdl_alias_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    withitem_ty typed_elements[1];
} asdl_withitem_seq;
asdl_withitem_seq *_Py_asdl_withitem_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    match_case_ty typed_elements[1];
} asdl_match_case_seq;
asdl_match_case_seq *_Py_asdl_match_case_seq_new(Py_ssize_t size, PyArena
                                                 *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    pattern_ty typed_elements[1];
} asdl_pattern_seq;
asdl_pattern_seq *_Py_asdl_pattern_seq_new(Py_ssize_t size, PyArena *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    type_ignore_ty typed_elements[1];
} asdl_type_ignore_seq;
asdl_type_ignore_seq *_Py_asdl_type_ignore_seq_new(Py_ssize_t size, PyArena
                                                   *arena);
typedef struct {
    Py_ssize_t size; void **elements;
    type_param_ty typed_elements[1];
} asdl_type_param_seq;
asdl_type_param_seq *_Py_asdl_type_param_seq_new(Py_ssize_t size, PyArena
                                                 *arena);
enum _mod_kind {Module_kind=1, Interactive_kind=2, Expression_kind=3,
                 FunctionType_kind=4};
struct _mod {
    enum _mod_kind kind;
    union {
        struct {
            asdl_stmt_seq *body;
            asdl_type_ignore_seq *type_ignores;
        } Module;
        struct {
            asdl_stmt_seq *body;
        } Interactive;
        struct {
            expr_ty body;
        } Expression;
        struct {
            asdl_expr_seq *argtypes;
            expr_ty returns;
        } FunctionType;
    } v;
};
enum _stmt_kind {FunctionDef_kind=1, AsyncFunctionDef_kind=2, ClassDef_kind=3,
                  Return_kind=4, Delete_kind=5, Assign_kind=6,
                  TypeAlias_kind=7, AugAssign_kind=8, AnnAssign_kind=9,
                  For_kind=10, AsyncFor_kind=11, While_kind=12, If_kind=13,
                  With_kind=14, AsyncWith_kind=15, Match_kind=16,
                  Raise_kind=17, Try_kind=18, TryStar_kind=19, Assert_kind=20,
                  Import_kind=21, ImportFrom_kind=22, Global_kind=23,
                  Nonlocal_kind=24, Expr_kind=25, Pass_kind=26, Break_kind=27,
                  Continue_kind=28};
struct _stmt {
    enum _stmt_kind kind;
    union {
        struct {
            identifier name;
            arguments_ty args;
            asdl_stmt_seq *body;
            asdl_expr_seq *decorator_list;
            expr_ty returns;
            string type_comment;
            asdl_type_param_seq *type_params;
        } FunctionDef;
        struct {
            identifier name;
            arguments_ty args;
            asdl_stmt_seq *body;
            asdl_expr_seq *decorator_list;
            expr_ty returns;
            string type_comment;
            asdl_type_param_seq *type_params;
        } AsyncFunctionDef;
        struct {
            identifier name;
            asdl_expr_seq *bases;
            asdl_keyword_seq *keywords;
            asdl_stmt_seq *body;
            asdl_expr_seq *decorator_list;
            asdl_type_param_seq *type_params;
        } ClassDef;
        struct {
            expr_ty value;
        } Return;
        struct {
            asdl_expr_seq *targets;
        } Delete;
        struct {
            asdl_expr_seq *targets;
            expr_ty value;
            string type_comment;
        } Assign;
        struct {
            expr_ty name;
            asdl_type_param_seq *type_params;
            expr_ty value;
        } TypeAlias;
        struct {
            expr_ty target;
            operator_ty op;
            expr_ty value;
        } AugAssign;
        struct {
            expr_ty target;
            expr_ty annotation;
            expr_ty value;
            int simple;
        } AnnAssign;
        struct {
            expr_ty target;
            expr_ty iter;
            asdl_stmt_seq *body;
            asdl_stmt_seq *orelse;
            string type_comment;
        } For;
        struct {
            expr_ty target;
            expr_ty iter;
            asdl_stmt_seq *body;
            asdl_stmt_seq *orelse;
            string type_comment;
        } AsyncFor;
        struct {
            expr_ty test;
            asdl_stmt_seq *body;
            asdl_stmt_seq *orelse;
        } While;
        struct {
            expr_ty test;
            asdl_stmt_seq *body;
            asdl_stmt_seq *orelse;
        } If;
        struct {
            asdl_withitem_seq *items;
            asdl_stmt_seq *body;
            string type_comment;
        } With;
        struct {
            asdl_withitem_seq *items;
            asdl_stmt_seq *body;
            string type_comment;
        } AsyncWith;
        struct {
            expr_ty subject;
            asdl_match_case_seq *cases;
        } Match;
        struct {
            expr_ty exc;
            expr_ty cause;
        } Raise;
        struct {
            asdl_stmt_seq *body;
            asdl_excepthandler_seq *handlers;
            asdl_stmt_seq *orelse;
            asdl_stmt_seq *finalbody;
        } Try;
        struct {
            asdl_stmt_seq *body;
            asdl_excepthandler_seq *handlers;
            asdl_stmt_seq *orelse;
            asdl_stmt_seq *finalbody;
        } TryStar;
        struct {
            expr_ty test;
            expr_ty msg;
        } Assert;
        struct {
            asdl_alias_seq *names;
        } Import;
        struct {
            identifier module;
            asdl_alias_seq *names;
            int level;
        } ImportFrom;
        struct {
            asdl_identifier_seq *names;
        } Global;
        struct {
            asdl_identifier_seq *names;
        } Nonlocal;
        struct {
            expr_ty value;
        } Expr;
    } v;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
enum _expr_kind {BoolOp_kind=1, NamedExpr_kind=2, BinOp_kind=3, UnaryOp_kind=4,
                  Lambda_kind=5, IfExp_kind=6, Dict_kind=7, Set_kind=8,
                  ListComp_kind=9, SetComp_kind=10, DictComp_kind=11,
                  GeneratorExp_kind=12, Await_kind=13, Yield_kind=14,
                  YieldFrom_kind=15, Compare_kind=16, Call_kind=17,
                  FormattedValue_kind=18, JoinedStr_kind=19, Constant_kind=20,
                  Attribute_kind=21, Subscript_kind=22, Starred_kind=23,
                  Name_kind=24, List_kind=25, Tuple_kind=26, Slice_kind=27};
struct _expr {
    enum _expr_kind kind;
    union {
        struct {
            boolop_ty op;
            asdl_expr_seq *values;
        } BoolOp;
        struct {
            expr_ty target;
            expr_ty value;
        } NamedExpr;
        struct {
            expr_ty left;
            operator_ty op;
            expr_ty right;
        } BinOp;
        struct {
            unaryop_ty op;
            expr_ty operand;
        } UnaryOp;
        struct {
            arguments_ty args;
            expr_ty body;
        } Lambda;
        struct {
            expr_ty test;
            expr_ty body;
            expr_ty orelse;
        } IfExp;
        struct {
            asdl_expr_seq *keys;
            asdl_expr_seq *values;
        } Dict;
        struct {
            asdl_expr_seq *elts;
        } Set;
        struct {
            expr_ty elt;
            asdl_comprehension_seq *generators;
        } ListComp;
        struct {
            expr_ty elt;
            asdl_comprehension_seq *generators;
        } SetComp;
        struct {
            expr_ty key;
            expr_ty value;
            asdl_comprehension_seq *generators;
        } DictComp;
        struct {
            expr_ty elt;
            asdl_comprehension_seq *generators;
        } GeneratorExp;
        struct {
            expr_ty value;
        } Await;
        struct {
            expr_ty value;
        } Yield;
        struct {
            expr_ty value;
        } YieldFrom;
        struct {
            expr_ty left;
            asdl_int_seq *ops;
            asdl_expr_seq *comparators;
        } Compare;
        struct {
            expr_ty func;
            asdl_expr_seq *args;
            asdl_keyword_seq *keywords;
        } Call;
        struct {
            expr_ty value;
            int conversion;
            expr_ty format_spec;
        } FormattedValue;
        struct {
            asdl_expr_seq *values;
        } JoinedStr;
        struct {
            constant value;
            string kind;
        } Constant;
        struct {
            expr_ty value;
            identifier attr;
            expr_context_ty ctx;
        } Attribute;
        struct {
            expr_ty value;
            expr_ty slice;
            expr_context_ty ctx;
        } Subscript;
        struct {
            expr_ty value;
            expr_context_ty ctx;
        } Starred;
        struct {
            identifier id;
            expr_context_ty ctx;
        } Name;
        struct {
            asdl_expr_seq *elts;
            expr_context_ty ctx;
        } List;
        struct {
            asdl_expr_seq *elts;
            expr_context_ty ctx;
        } Tuple;
        struct {
            expr_ty lower;
            expr_ty upper;
            expr_ty step;
        } Slice;
    } v;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
struct _comprehension {
    expr_ty target;
    expr_ty iter;
    asdl_expr_seq *ifs;
    int is_async;
};
enum _excepthandler_kind {ExceptHandler_kind=1};
struct _excepthandler {
    enum _excepthandler_kind kind;
    union {
        struct {
            expr_ty type;
            identifier name;
            asdl_stmt_seq *body;
        } ExceptHandler;
    } v;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
struct _arguments {
    asdl_arg_seq *posonlyargs;
    asdl_arg_seq *args;
    arg_ty vararg;
    asdl_arg_seq *kwonlyargs;
    asdl_expr_seq *kw_defaults;
    arg_ty kwarg;
    asdl_expr_seq *defaults;
};
struct _arg {
    identifier arg;
    expr_ty annotation;
    string type_comment;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
struct _keyword {
    identifier arg;
    expr_ty value;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
struct _alias {
    identifier name;
    identifier asname;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
struct _withitem {
    expr_ty context_expr;
    expr_ty optional_vars;
};
struct _match_case {
    pattern_ty pattern;
    expr_ty guard;
    asdl_stmt_seq *body;
};
enum _pattern_kind {MatchValue_kind=1, MatchSingleton_kind=2,
                     MatchSequence_kind=3, MatchMapping_kind=4,
                     MatchClass_kind=5, MatchStar_kind=6, MatchAs_kind=7,
                     MatchOr_kind=8};
struct _pattern {
    enum _pattern_kind kind;
    union {
        struct {
            expr_ty value;
        } MatchValue;
        struct {
            constant value;
        } MatchSingleton;
        struct {
            asdl_pattern_seq *patterns;
        } MatchSequence;
        struct {
            asdl_expr_seq *keys;
            asdl_pattern_seq *patterns;
            identifier rest;
        } MatchMapping;
        struct {
            expr_ty cls;
            asdl_pattern_seq *patterns;
            asdl_identifier_seq *kwd_attrs;
            asdl_pattern_seq *kwd_patterns;
        } MatchClass;
        struct {
            identifier name;
        } MatchStar;
        struct {
            pattern_ty pattern;
            identifier name;
        } MatchAs;
        struct {
            asdl_pattern_seq *patterns;
        } MatchOr;
    } v;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
enum _type_ignore_kind {TypeIgnore_kind=1};
struct _type_ignore {
    enum _type_ignore_kind kind;
    union {
        struct {
            int lineno;
            string tag;
        } TypeIgnore;
    } v;
};
enum _type_param_kind {TypeVar_kind=1, ParamSpec_kind=2, TypeVarTuple_kind=3};
struct _type_param {
    enum _type_param_kind kind;
    union {
        struct {
            identifier name;
            expr_ty bound;
        } TypeVar;
        struct {
            identifier name;
        } ParamSpec;
        struct {
            identifier name;
        } TypeVarTuple;
    } v;
    int lineno;
    int col_offset;
    int end_lineno;
    int end_col_offset;
};
mod_ty _PyAST_Module(asdl_stmt_seq * body, asdl_type_ignore_seq * type_ignores,
                     PyArena *arena);
mod_ty _PyAST_Interactive(asdl_stmt_seq * body, PyArena *arena);
mod_ty _PyAST_Expression(expr_ty body, PyArena *arena);
mod_ty _PyAST_FunctionType(asdl_expr_seq * argtypes, expr_ty returns, PyArena
                           *arena);
stmt_ty _PyAST_FunctionDef(identifier name, arguments_ty args, asdl_stmt_seq *
                           body, asdl_expr_seq * decorator_list, expr_ty
                           returns, string type_comment, asdl_type_param_seq *
                           type_params, int lineno, int col_offset, int
                           end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_AsyncFunctionDef(identifier name, arguments_ty args,
                                asdl_stmt_seq * body, asdl_expr_seq *
                                decorator_list, expr_ty returns, string
                                type_comment, asdl_type_param_seq *
                                type_params, int lineno, int col_offset, int
                                end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_ClassDef(identifier name, asdl_expr_seq * bases,
                        asdl_keyword_seq * keywords, asdl_stmt_seq * body,
                        asdl_expr_seq * decorator_list, asdl_type_param_seq *
                        type_params, int lineno, int col_offset, int
                        end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Return(expr_ty value, int lineno, int col_offset, int
                      end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Delete(asdl_expr_seq * targets, int lineno, int col_offset, int
                      end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Assign(asdl_expr_seq * targets, expr_ty value, string
                      type_comment, int lineno, int col_offset, int end_lineno,
                      int end_col_offset, PyArena *arena);
stmt_ty _PyAST_TypeAlias(expr_ty name, asdl_type_param_seq * type_params,
                         expr_ty value, int lineno, int col_offset, int
                         end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_AugAssign(expr_ty target, operator_ty op, expr_ty value, int
                         lineno, int col_offset, int end_lineno, int
                         end_col_offset, PyArena *arena);
stmt_ty _PyAST_AnnAssign(expr_ty target, expr_ty annotation, expr_ty value, int
                         simple, int lineno, int col_offset, int end_lineno,
                         int end_col_offset, PyArena *arena);
stmt_ty _PyAST_For(expr_ty target, expr_ty iter, asdl_stmt_seq * body,
                   asdl_stmt_seq * orelse, string type_comment, int lineno, int
                   col_offset, int end_lineno, int end_col_offset, PyArena
                   *arena);
stmt_ty _PyAST_AsyncFor(expr_ty target, expr_ty iter, asdl_stmt_seq * body,
                        asdl_stmt_seq * orelse, string type_comment, int
                        lineno, int col_offset, int end_lineno, int
                        end_col_offset, PyArena *arena);
stmt_ty _PyAST_While(expr_ty test, asdl_stmt_seq * body, asdl_stmt_seq *
                     orelse, int lineno, int col_offset, int end_lineno, int
                     end_col_offset, PyArena *arena);
stmt_ty _PyAST_If(expr_ty test, asdl_stmt_seq * body, asdl_stmt_seq * orelse,
                  int lineno, int col_offset, int end_lineno, int
                  end_col_offset, PyArena *arena);
stmt_ty _PyAST_With(asdl_withitem_seq * items, asdl_stmt_seq * body, string
                    type_comment, int lineno, int col_offset, int end_lineno,
                    int end_col_offset, PyArena *arena);
stmt_ty _PyAST_AsyncWith(asdl_withitem_seq * items, asdl_stmt_seq * body,
                         string type_comment, int lineno, int col_offset, int
                         end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Match(expr_ty subject, asdl_match_case_seq * cases, int lineno,
                     int col_offset, int end_lineno, int end_col_offset,
                     PyArena *arena);
stmt_ty _PyAST_Raise(expr_ty exc, expr_ty cause, int lineno, int col_offset,
                     int end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Try(asdl_stmt_seq * body, asdl_excepthandler_seq * handlers,
                   asdl_stmt_seq * orelse, asdl_stmt_seq * finalbody, int
                   lineno, int col_offset, int end_lineno, int end_col_offset,
                   PyArena *arena);
stmt_ty _PyAST_TryStar(asdl_stmt_seq * body, asdl_excepthandler_seq * handlers,
                       asdl_stmt_seq * orelse, asdl_stmt_seq * finalbody, int
                       lineno, int col_offset, int end_lineno, int
                       end_col_offset, PyArena *arena);
stmt_ty _PyAST_Assert(expr_ty test, expr_ty msg, int lineno, int col_offset,
                      int end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Import(asdl_alias_seq * names, int lineno, int col_offset, int
                      end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_ImportFrom(identifier module, asdl_alias_seq * names, int level,
                          int lineno, int col_offset, int end_lineno, int
                          end_col_offset, PyArena *arena);
stmt_ty _PyAST_Global(asdl_identifier_seq * names, int lineno, int col_offset,
                      int end_lineno, int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Nonlocal(asdl_identifier_seq * names, int lineno, int
                        col_offset, int end_lineno, int end_col_offset, PyArena
                        *arena);
stmt_ty _PyAST_Expr(expr_ty value, int lineno, int col_offset, int end_lineno,
                    int end_col_offset, PyArena *arena);
stmt_ty _PyAST_Pass(int lineno, int col_offset, int end_lineno, int
                    end_col_offset, PyArena *arena);
stmt_ty _PyAST_Break(int lineno, int col_offset, int end_lineno, int
                     end_col_offset, PyArena *arena);
stmt_ty _PyAST_Continue(int lineno, int col_offset, int end_lineno, int
                        end_col_offset, PyArena *arena);
expr_ty _PyAST_BoolOp(boolop_ty op, asdl_expr_seq * values, int lineno, int
                      col_offset, int end_lineno, int end_col_offset, PyArena
                      *arena);
expr_ty _PyAST_NamedExpr(expr_ty target, expr_ty value, int lineno, int
                         col_offset, int end_lineno, int end_col_offset,
                         PyArena *arena);
expr_ty _PyAST_BinOp(expr_ty left, operator_ty op, expr_ty right, int lineno,
                     int col_offset, int end_lineno, int end_col_offset,
                     PyArena *arena);
expr_ty _PyAST_UnaryOp(unaryop_ty op, expr_ty operand, int lineno, int
                       col_offset, int end_lineno, int end_col_offset, PyArena
                       *arena);
expr_ty _PyAST_Lambda(arguments_ty args, expr_ty body, int lineno, int
                      col_offset, int end_lineno, int end_col_offset, PyArena
                      *arena);
expr_ty _PyAST_IfExp(expr_ty test, expr_ty body, expr_ty orelse, int lineno,
                     int col_offset, int end_lineno, int end_col_offset,
                     PyArena *arena);
expr_ty _PyAST_Dict(asdl_expr_seq * keys, asdl_expr_seq * values, int lineno,
                    int col_offset, int end_lineno, int end_col_offset, PyArena
                    *arena);
expr_ty _PyAST_Set(asdl_expr_seq * elts, int lineno, int col_offset, int
                   end_lineno, int end_col_offset, PyArena *arena);
expr_ty _PyAST_ListComp(expr_ty elt, asdl_comprehension_seq * generators, int
                        lineno, int col_offset, int end_lineno, int
                        end_col_offset, PyArena *arena);
expr_ty _PyAST_SetComp(expr_ty elt, asdl_comprehension_seq * generators, int
                       lineno, int col_offset, int end_lineno, int
                       end_col_offset, PyArena *arena);
expr_ty _PyAST_DictComp(expr_ty key, expr_ty value, asdl_comprehension_seq *
                        generators, int lineno, int col_offset, int end_lineno,
                        int end_col_offset, PyArena *arena);
expr_ty _PyAST_GeneratorExp(expr_ty elt, asdl_comprehension_seq * generators,
                            int lineno, int col_offset, int end_lineno, int
                            end_col_offset, PyArena *arena);
expr_ty _PyAST_Await(expr_ty value, int lineno, int col_offset, int end_lineno,
                     int end_col_offset, PyArena *arena);
expr_ty _PyAST_Yield(expr_ty value, int lineno, int col_offset, int end_lineno,
                     int end_col_offset, PyArena *arena);
expr_ty _PyAST_YieldFrom(expr_ty value, int lineno, int col_offset, int
                         end_lineno, int end_col_offset, PyArena *arena);
expr_ty _PyAST_Compare(expr_ty left, asdl_int_seq * ops, asdl_expr_seq *
                       comparators, int lineno, int col_offset, int end_lineno,
                       int end_col_offset, PyArena *arena);
expr_ty _PyAST_Call(expr_ty func, asdl_expr_seq * args, asdl_keyword_seq *
                    keywords, int lineno, int col_offset, int end_lineno, int
                    end_col_offset, PyArena *arena);
expr_ty _PyAST_FormattedValue(expr_ty value, int conversion, expr_ty
                              format_spec, int lineno, int col_offset, int
                              end_lineno, int end_col_offset, PyArena *arena);
expr_ty _PyAST_JoinedStr(asdl_expr_seq * values, int lineno, int col_offset,
                         int end_lineno, int end_col_offset, PyArena *arena);
expr_ty _PyAST_Constant(constant value, string kind, int lineno, int
                        col_offset, int end_lineno, int end_col_offset, PyArena
                        *arena);
expr_ty _PyAST_Attribute(expr_ty value, identifier attr, expr_context_ty ctx,
                         int lineno, int col_offset, int end_lineno, int
                         end_col_offset, PyArena *arena);
expr_ty _PyAST_Subscript(expr_ty value, expr_ty slice, expr_context_ty ctx, int
                         lineno, int col_offset, int end_lineno, int
                         end_col_offset, PyArena *arena);
expr_ty _PyAST_Starred(expr_ty value, expr_context_ty ctx, int lineno, int
                       col_offset, int end_lineno, int end_col_offset, PyArena
                       *arena);
expr_ty _PyAST_Name(identifier id, expr_context_ty ctx, int lineno, int
                    col_offset, int end_lineno, int end_col_offset, PyArena
                    *arena);
expr_ty _PyAST_List(asdl_expr_seq * elts, expr_context_ty ctx, int lineno, int
                    col_offset, int end_lineno, int end_col_offset, PyArena
                    *arena);
expr_ty _PyAST_Tuple(asdl_expr_seq * elts, expr_context_ty ctx, int lineno, int
                     col_offset, int end_lineno, int end_col_offset, PyArena
                     *arena);
expr_ty _PyAST_Slice(expr_ty lower, expr_ty upper, expr_ty step, int lineno,
                     int col_offset, int end_lineno, int end_col_offset,
                     PyArena *arena);
comprehension_ty _PyAST_comprehension(expr_ty target, expr_ty iter,
                                      asdl_expr_seq * ifs, int is_async,
                                      PyArena *arena);
excepthandler_ty _PyAST_ExceptHandler(expr_ty type, identifier name,
                                      asdl_stmt_seq * body, int lineno, int
                                      col_offset, int end_lineno, int
                                      end_col_offset, PyArena *arena);
arguments_ty _PyAST_arguments(asdl_arg_seq * posonlyargs, asdl_arg_seq * args,
                              arg_ty vararg, asdl_arg_seq * kwonlyargs,
                              asdl_expr_seq * kw_defaults, arg_ty kwarg,
                              asdl_expr_seq * defaults, PyArena *arena);
arg_ty _PyAST_arg(identifier arg, expr_ty annotation, string type_comment, int
                  lineno, int col_offset, int end_lineno, int end_col_offset,
                  PyArena *arena);
keyword_ty _PyAST_keyword(identifier arg, expr_ty value, int lineno, int
                          col_offset, int end_lineno, int end_col_offset,
                          PyArena *arena);
alias_ty _PyAST_alias(identifier name, identifier asname, int lineno, int
                      col_offset, int end_lineno, int end_col_offset, PyArena
                      *arena);
withitem_ty _PyAST_withitem(expr_ty context_expr, expr_ty optional_vars,
                            PyArena *arena);
match_case_ty _PyAST_match_case(pattern_ty pattern, expr_ty guard,
                                asdl_stmt_seq * body, PyArena *arena);
pattern_ty _PyAST_MatchValue(expr_ty value, int lineno, int col_offset, int
                             end_lineno, int end_col_offset, PyArena *arena);
pattern_ty _PyAST_MatchSingleton(constant value, int lineno, int col_offset,
                                 int end_lineno, int end_col_offset, PyArena
                                 *arena);
pattern_ty _PyAST_MatchSequence(asdl_pattern_seq * patterns, int lineno, int
                                col_offset, int end_lineno, int end_col_offset,
                                PyArena *arena);
pattern_ty _PyAST_MatchMapping(asdl_expr_seq * keys, asdl_pattern_seq *
                               patterns, identifier rest, int lineno, int
                               col_offset, int end_lineno, int end_col_offset,
                               PyArena *arena);
pattern_ty _PyAST_MatchClass(expr_ty cls, asdl_pattern_seq * patterns,
                             asdl_identifier_seq * kwd_attrs, asdl_pattern_seq
                             * kwd_patterns, int lineno, int col_offset, int
                             end_lineno, int end_col_offset, PyArena *arena);
pattern_ty _PyAST_MatchStar(identifier name, int lineno, int col_offset, int
                            end_lineno, int end_col_offset, PyArena *arena);
pattern_ty _PyAST_MatchAs(pattern_ty pattern, identifier name, int lineno, int
                          col_offset, int end_lineno, int end_col_offset,
                          PyArena *arena);
pattern_ty _PyAST_MatchOr(asdl_pattern_seq * patterns, int lineno, int
                          col_offset, int end_lineno, int end_col_offset,
                          PyArena *arena);
type_ignore_ty _PyAST_TypeIgnore(int lineno, string tag, PyArena *arena);
type_param_ty _PyAST_TypeVar(identifier name, expr_ty bound, int lineno, int
                             col_offset, int end_lineno, int end_col_offset,
                             PyArena *arena);
type_param_ty _PyAST_ParamSpec(identifier name, int lineno, int col_offset, int
                               end_lineno, int end_col_offset, PyArena *arena);
type_param_ty _PyAST_TypeVarTuple(identifier name, int lineno, int col_offset,
                                  int end_lineno, int end_col_offset, PyArena
                                  *arena);
PyObject* PyAST_mod2obj(mod_ty t);
mod_ty PyAST_obj2mod(PyObject* ast, PyArena* arena, int mode);
int PyAST_Check(PyObject* obj);
extern int _PyAST_Validate(mod_ty);
extern PyObject* _PyAST_ExprAsUnicode(expr_ty);
extern PyObject* _PyAST_GetDocString(asdl_stmt_seq *);
struct _parser_runtime_state {
    int _not_used;
    struct _expr dummy_name;
};

extern struct _mod* _PyParser_ASTFromString(
    const char *str,
    PyObject* filename,
    int mode,
    PyCompilerFlags *flags,
    PyArena *arena);
extern struct _mod* _PyParser_ASTFromFile(
    FILE *fp,
    PyObject *filename_ob,
    const char *enc,
    int mode,
    const char *ps1,
    const char *ps2,
    PyCompilerFlags *flags,
    int *errcode,
    PyArena *arena);
typedef struct {
    char api_id;
    PyMemAllocatorEx alloc;
} debug_alloc_api_t;
struct _pymem_allocators {
    PyThread_type_lock mutex;
    struct {
        PyMemAllocatorEx raw;
        PyMemAllocatorEx mem;
        PyMemAllocatorEx obj;
    } standard;
    struct {
        debug_alloc_api_t raw;
        debug_alloc_api_t mem;
        debug_alloc_api_t obj;
    } debug;
    PyObjectArenaAllocator obj_arena;
};
__attribute__ ((visibility ("default"))) int _PyMem_SetDefaultAllocator(
    PyMemAllocatorDomain domain,
    PyMemAllocatorEx *old_alloc);
static inline int _PyMem_IsPtrFreed(const void *ptr)
{
    uintptr_t value = (uintptr_t)ptr;
    return (value == 0
            || value == (uintptr_t)0xCDCDCDCDCDCDCDCD
            || value == (uintptr_t)0xDDDDDDDDDDDDDDDD
            || value == (uintptr_t)0xFDFDFDFDFDFDFDFD);
}
__attribute__ ((visibility ("default"))) int _PyMem_GetAllocatorName(
    const char *name,
    PyMemAllocatorName *allocator);
__attribute__ ((visibility ("default"))) int _PyMem_SetupAllocators(PyMemAllocatorName allocator);
struct pyhash_runtime_state {
    struct {
        int fd;
        dev_t st_dev;
        ino_t st_ino;
    } urandom_cache;
};
uint64_t _Py_KeyedHash(uint64_t, const char *, Py_ssize_t);
struct _pythread_runtime_state {
    int initialized;
    struct {
        pthread_condattr_t *ptr;
        pthread_condattr_t val;
    } _condattr_monotonic;
};
struct _signals_runtime_state {
    volatile struct {
        _Py_atomic_int tripped;
        _Py_atomic_address func;
    } handlers[(64 + 1)];
    volatile struct {
        sig_atomic_t fd;
        int warn_on_full_buffer;
    } wakeup;
    _Py_atomic_int is_tripped;
    PyObject *default_handler;
    PyObject *ignore_handler;
    int unhandled_keyboard_interrupt;
};
struct _PyTraceMalloc_Config {
    enum {
        TRACEMALLOC_NOT_INITIALIZED,
        TRACEMALLOC_INITIALIZED,
        TRACEMALLOC_FINALIZED
    } initialized;
    int tracing;
    int max_nframe;
};
struct
__attribute__((packed))
tracemalloc_frame {
    PyObject *filename;
    unsigned int lineno;
};
struct tracemalloc_traceback {
    Py_uhash_t hash;
    uint16_t nframe;
    uint16_t total_nframe;
    struct tracemalloc_frame frames[1];
};
struct _tracemalloc_runtime_state {
    struct _PyTraceMalloc_Config config;
    struct {
        PyMemAllocatorEx mem;
        PyMemAllocatorEx raw;
        PyMemAllocatorEx obj;
    } allocators;
    PyThread_type_lock tables_lock;
    size_t traced_memory;
    size_t peak_traced_memory;
    _Py_hashtable_t *filenames;
    struct tracemalloc_traceback *traceback;
    _Py_hashtable_t *tracebacks;
    _Py_hashtable_t *traces;
    _Py_hashtable_t *domains;
    struct tracemalloc_traceback empty_traceback;
    Py_tss_t reentrant_key;
};
struct _getargs_runtime_state {
    PyThread_type_lock mutex;
    struct _PyArg_Parser *static_parsers;
};
struct _gilstate_runtime_state {
    int check_enabled;
    PyInterpreterState *autoInterpreterState;
};
typedef struct _Py_AuditHookEntry {
    struct _Py_AuditHookEntry *next;
    Py_AuditHookFunction hookCFunction;
    void *userData;
} _Py_AuditHookEntry;
typedef struct pyruntimestate {
    int _initialized;
    int preinitializing;
    int preinitialized;
    int core_initialized;
    int initialized;
    _Py_atomic_address _finalizing;
    struct pyinterpreters {
        PyThread_type_lock mutex;
        PyInterpreterState *head;
        PyInterpreterState *main;
        int64_t next_id;
    } interpreters;
    unsigned long main_thread;
    struct _xidregistry xidregistry;
    struct _pymem_allocators allocators;
    struct _obmalloc_global_state obmalloc;
    struct pyhash_runtime_state pyhash_state;
    struct _time_runtime_state time;
    struct _pythread_runtime_state threads;
    struct _signals_runtime_state signals;
    Py_tss_t autoTSSkey;
    Py_tss_t trashTSSkey;
    PyWideStringList orig_argv;
    struct _parser_runtime_state parser;
    struct _atexit_runtime_state atexit;
    struct _import_runtime_state imports;
    struct _ceval_runtime_state ceval;
    struct _gilstate_runtime_state gilstate;
    struct _getargs_runtime_state getargs;
    struct _fileutils_state fileutils;
    struct _faulthandler_runtime_state faulthandler;
    struct _tracemalloc_runtime_state tracemalloc;
    PyPreConfig preconfig;
    Py_OpenCodeHookFunction open_code_hook;
    void *open_code_userdata;
    struct {
        PyThread_type_lock mutex;
        _Py_AuditHookEntry *head;
    } audit_hooks;
    struct _py_object_runtime_state object_state;
    struct _Py_float_runtime_state float_state;
    struct _Py_unicode_runtime_state unicode_state;
    struct _types_runtime_state types;
    struct _Py_static_objects static_objects;
    struct _Py_cached_objects cached_objects;
    _Py_atomic_address _finalizing_id;
    wchar_t *sys_path_0;
    PyInterpreterState _main_interpreter;
} _PyRuntimeState;
extern __attribute__ ((visibility ("default"))) _PyRuntimeState _PyRuntime;
__attribute__ ((visibility ("default"))) PyStatus _PyRuntimeState_Init(_PyRuntimeState *runtime);
__attribute__ ((visibility ("default"))) void _PyRuntimeState_Fini(_PyRuntimeState *runtime);
extern PyStatus _PyRuntimeState_ReInitThreads(_PyRuntimeState *runtime);
__attribute__ ((visibility ("default"))) PyStatus _PyRuntime_Initialize(void);
__attribute__ ((visibility ("default"))) void _PyRuntime_Finalize(void);
static inline PyThreadState*
_PyRuntimeState_GetFinalizing(_PyRuntimeState *runtime) {
    return (PyThreadState*)__extension__ ({ __auto_type __atomic_load_ptr = (&(((&runtime->_finalizing))->_value)); __typeof__ ((void)0, *__atomic_load_ptr) __atomic_load_tmp; __atomic_load (__atomic_load_ptr, &__atomic_load_tmp, (_Py_memory_order_relaxed)); __atomic_load_tmp; });
}
static inline unsigned long
_PyRuntimeState_GetFinalizingID(_PyRuntimeState *runtime) {
    return (unsigned long)__extension__ ({ __auto_type __atomic_load_ptr = (&(((&runtime->_finalizing_id))->_value)); __typeof__ ((void)0, *__atomic_load_ptr) __atomic_load_tmp; __atomic_load (__atomic_load_ptr, &__atomic_load_tmp, (_Py_memory_order_relaxed)); __atomic_load_tmp; });
}
static inline void
_PyRuntimeState_SetFinalizing(_PyRuntimeState *runtime, PyThreadState *tstate) {
    __extension__ ({ __auto_type __atomic_store_ptr = (&(((&runtime->_finalizing))->_value)); __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = (((uintptr_t)tstate)); __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (_Py_memory_order_relaxed)); });
    if (tstate == ((void *)0)) {
        __extension__ ({ __auto_type __atomic_store_ptr = (&(((&runtime->_finalizing_id))->_value)); __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = ((0)); __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (_Py_memory_order_relaxed)); });
    }
    else {
        __extension__ ({ __auto_type __atomic_store_ptr = (&(((&runtime->_finalizing_id))->_value)); __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = (((uintptr_t)tstate->thread_id)); __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (_Py_memory_order_relaxed)); });
    }
}
extern PyStatus _PyLong_InitTypes(PyInterpreterState *);
extern void _PyLong_FiniTypes(PyInterpreterState *interp);
static inline PyObject* _PyLong_GetZero(void)
{ return (PyObject *)&_PyRuntime.static_objects.singletons.small_ints[5]; }
static inline PyObject* _PyLong_GetOne(void)
{ return (PyObject *)&_PyRuntime.static_objects.singletons.small_ints[5 +1]; }
static inline PyObject* _PyLong_FromUnsignedChar(unsigned char i)
{
    return _Py_NewRef(((PyObject*)(((PyObject *)&_PyRuntime.static_objects.singletons.small_ints[5 +i]))));
}
PyObject *_PyLong_Add(PyLongObject *left, PyLongObject *right);
PyObject *_PyLong_Multiply(PyLongObject *left, PyLongObject *right);
PyObject *_PyLong_Subtract(PyLongObject *left, PyLongObject *right);
extern __attribute__ ((visibility ("default"))) unsigned char _PyLong_DigitValue[256];
__attribute__ ((visibility ("default"))) int _PyLong_FormatAdvancedWriter(
    _PyUnicodeWriter *writer,
    PyObject *obj,
    PyObject *format_spec,
    Py_ssize_t start,
    Py_ssize_t end);
__attribute__ ((visibility ("default"))) int _PyLong_FormatWriter(
    _PyUnicodeWriter *writer,
    PyObject *obj,
    int base,
    int alternate);
__attribute__ ((visibility ("default"))) char* _PyLong_FormatBytesWriter(
    _PyBytesWriter *writer,
    char *str,
    PyObject *obj,
    int base,
    int alternate);
_Static_assert(3 == 3, "SIGN_MASK does not match _PyLong_SIGN_MASK");
_Static_assert(3 == 3, "NON_SIZE_BITS does not match _PyLong_NON_SIZE_BITS");
static inline int
_PyLong_IsNonNegativeCompact(const PyLongObject* op) {
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(op)", "/usr/include/python3.12/internal/pycore_long.h", 145, __extension__ __PRETTY_FUNCTION__); }));
    return op->long_value.lv_tag <= (1 << 3);
}
static inline int
_PyLong_BothAreCompact(const PyLongObject* a, const PyLongObject* b) {
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((a))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((a))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(a)", "/usr/include/python3.12/internal/pycore_long.h", 152, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((b))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((b))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(b)", "/usr/include/python3.12/internal/pycore_long.h", 153, __extension__ __PRETTY_FUNCTION__); }));
    return (a->long_value.lv_tag | b->long_value.lv_tag) < (2 << 3);
}
static inline _Bool
_PyLong_IsZero(const PyLongObject *op)
{
    return (op->long_value.lv_tag & 3) == 1;
}
static inline _Bool
_PyLong_IsNegative(const PyLongObject *op)
{
    return (op->long_value.lv_tag & 3) == 2;
}
static inline _Bool
_PyLong_IsPositive(const PyLongObject *op)
{
    return (op->long_value.lv_tag & 3) == 0;
}
static inline Py_ssize_t
_PyLong_DigitCount(const PyLongObject *op)
{
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(op)", "/usr/include/python3.12/internal/pycore_long.h", 178, __extension__ __PRETTY_FUNCTION__); }));
    return op->long_value.lv_tag >> 3;
}
static inline Py_ssize_t
_PyLong_SignedDigitCount(const PyLongObject *op)
{
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(op)", "/usr/include/python3.12/internal/pycore_long.h", 186, __extension__ __PRETTY_FUNCTION__); }));
    Py_ssize_t sign = 1 - (op->long_value.lv_tag & 3);
    return sign * (Py_ssize_t)(op->long_value.lv_tag >> 3);
}
static inline int
_PyLong_CompactSign(const PyLongObject *op)
{
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(op)", "/usr/include/python3.12/internal/pycore_long.h", 194, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((_PyLong_IsCompact(op)) ? 1 : 0), __extension__ ({ if (_PyLong_IsCompact(op)) ; else __assert_fail ("_PyLong_IsCompact(op)", "/usr/include/python3.12/internal/pycore_long.h", 195, __extension__ __PRETTY_FUNCTION__); }));
    return 1 - (op->long_value.lv_tag & 3);
}
static inline int
_PyLong_NonCompactSign(const PyLongObject *op)
{
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 24)))) ; else __assert_fail ("PyLong_Check(op)", "/usr/include/python3.12/internal/pycore_long.h", 202, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((!_PyLong_IsCompact(op)) ? 1 : 0), __extension__ ({ if (!_PyLong_IsCompact(op)) ; else __assert_fail ("!_PyLong_IsCompact(op)", "/usr/include/python3.12/internal/pycore_long.h", 203, __extension__ __PRETTY_FUNCTION__); }));
    return 1 - (op->long_value.lv_tag & 3);
}
static inline int
_PyLong_SameSign(const PyLongObject *a, const PyLongObject *b)
{
    return (a->long_value.lv_tag & 3) == (b->long_value.lv_tag & 3);
}
static inline void
_PyLong_SetSignAndDigitCount(PyLongObject *op, int sign, Py_ssize_t size)
{
    ((void) sizeof ((size >= 0) ? 1 : 0), __extension__ ({ if (size >= 0) ; else __assert_fail ("size >= 0", "/usr/include/python3.12/internal/pycore_long.h", 219, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((-1 <= sign && sign <= 1) ? 1 : 0), __extension__ ({ if (-1 <= sign && sign <= 1) ; else __assert_fail ("-1 <= sign && sign <= 1", "/usr/include/python3.12/internal/pycore_long.h", 220, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((sign != 0 || size == 0) ? 1 : 0), __extension__ ({ if (sign != 0 || size == 0) ; else __assert_fail ("sign != 0 || size == 0", "/usr/include/python3.12/internal/pycore_long.h", 221, __extension__ __PRETTY_FUNCTION__); }));
    op->long_value.lv_tag = ((1 - (sign)) | (((size_t)size) << 3));
}
static inline void
_PyLong_SetDigitCount(PyLongObject *op, Py_ssize_t size)
{
    ((void) sizeof ((size >= 0) ? 1 : 0), __extension__ ({ if (size >= 0) ; else __assert_fail ("size >= 0", "/usr/include/python3.12/internal/pycore_long.h", 228, __extension__ __PRETTY_FUNCTION__); }));
    op->long_value.lv_tag = (((size_t)size) << 3) | (op->long_value.lv_tag & 3);
}
static inline void
_PyLong_FlipSign(PyLongObject *op) {
    unsigned int flipped_sign = 2 - (op->long_value.lv_tag & 3);
    op->long_value.lv_tag &= ~((1 << 3) - 1);
    op->long_value.lv_tag |= flipped_sign;
}
static inline int
_Py_IsMainThread(void)
{
    unsigned long thread = PyThread_get_thread_ident();
    return (thread == _PyRuntime.main_thread);
}
static inline PyInterpreterState *
_PyInterpreterState_Main(void)
{
    return _PyRuntime.interpreters.main;
}
static inline int
_Py_IsMainInterpreter(PyInterpreterState *interp)
{
    return (interp == _PyInterpreterState_Main());
}
static inline int
_Py_IsMainInterpreterFinalizing(PyInterpreterState *interp)
{
    return (_PyRuntimeState_GetFinalizing(&_PyRuntime) != ((void *)0) &&
            interp == &_PyRuntime._main_interpreter);
}
__attribute__ ((visibility ("default"))) int _PyInterpreterState_SetRunningMain(PyInterpreterState *);
__attribute__ ((visibility ("default"))) void _PyInterpreterState_SetNotRunningMain(PyInterpreterState *);
__attribute__ ((visibility ("default"))) int _PyInterpreterState_IsRunningMain(PyInterpreterState *);
static inline const PyConfig *
_Py_GetMainConfig(void)
{
    PyInterpreterState *interp = _PyInterpreterState_Main();
    if (interp == ((void *)0)) {
        return ((void *)0);
    }
    return _PyInterpreterState_GetConfig(interp);
}
static inline int
_Py_ThreadCanHandleSignals(PyInterpreterState *interp)
{
    return (_Py_IsMainThread() && _Py_IsMainInterpreter(interp));
}
extern _Thread_local PyThreadState *_Py_tss_tstate;
extern __attribute__ ((visibility ("default"))) PyThreadState * _PyThreadState_GetCurrent(void);
extern int _PyThreadState_CheckConsistency(PyThreadState *tstate);
extern int _PyThreadState_MustExit(PyThreadState *tstate);
static inline PyThreadState*
_PyThreadState_GET(void)
{
    return _Py_tss_tstate;
}
static inline void
_Py_EnsureFuncTstateNotNULL(const char *func, PyThreadState *tstate)
{
    if (tstate == ((void *)0)) {
        _Py_FatalErrorFunc(func,
            "the function must be called with the GIL held, "
            "after Python initialization and before Python finalization, "
            "but the GIL is released (the current Python thread state is NULL)");
    }
}
static inline PyInterpreterState* _PyInterpreterState_GET(void) {
    PyThreadState *tstate = _PyThreadState_GET();
    return tstate->interp;
}
__attribute__ ((visibility ("default"))) PyThreadState * _PyThreadState_New(PyInterpreterState *interp);
__attribute__ ((visibility ("default"))) void _PyThreadState_Bind(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void _PyThreadState_Init(
    PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void _PyThreadState_DeleteExcept(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) PyThreadState * _PyThreadState_Swap(
    _PyRuntimeState *runtime,
    PyThreadState *newts);
__attribute__ ((visibility ("default"))) PyStatus _PyInterpreterState_Enable(_PyRuntimeState *runtime);
extern PyStatus _PyInterpreterState_DeleteExceptMain(_PyRuntimeState *runtime);
extern void _PySignal_AfterFork(void);
__attribute__ ((visibility ("default"))) int _PyCrossInterpreterData_ReleaseAndRawFree(_PyCrossInterpreterData *);
__attribute__ ((visibility ("default"))) int _PyState_AddModule(
    PyThreadState *tstate,
    PyObject* module,
    PyModuleDef* def);
__attribute__ ((visibility ("default"))) int _PyOS_InterruptOccurred(PyThreadState *tstate);
__attribute__ ((visibility ("default"))) void __attribute__((__noreturn__)) _Py_FatalRefcountErrorFunc(
    const char *func,
    const char *message);
static inline void _Py_RefcntAdd(PyObject* op, Py_ssize_t n)
{
    if (_Py_IsImmortal(((PyObject*)((op))))) {
        return;
    }
    op->ob_refcnt += n;
}
static inline void _Py_SetImmortal(PyObject *op)
{
    if (op) {
        op->ob_refcnt = (0x7fffffff * 2U + 1U);
    }
}
static inline void _Py_ClearImmortal(PyObject *op)
{
    if (op) {
        ((void) sizeof ((op->ob_refcnt == (0x7fffffff * 2U + 1U)) ? 1 : 0), __extension__ ({ if (op->ob_refcnt == (0x7fffffff * 2U + 1U)) ; else __assert_fail ("op->ob_refcnt == _Py_IMMORTAL_REFCNT", "/usr/include/python3.12/internal/pycore_object.h", 83, __extension__ __PRETTY_FUNCTION__); }));
        op->ob_refcnt = 1;
        Py_DECREF(((PyObject*)((op))));
    }
}
static inline void
_Py_DECREF_SPECIALIZED(PyObject *op, const destructor destruct)
{
    if (_Py_IsImmortal(((PyObject*)((op))))) {
        return;
    }
    ((void)0);
    if (--op->ob_refcnt != 0) {
        ((void) sizeof ((op->ob_refcnt > 0) ? 1 : 0), __extension__ ({ if (op->ob_refcnt > 0) ; else __assert_fail ("op->ob_refcnt > 0", "/usr/include/python3.12/internal/pycore_object.h", 105, __extension__ __PRETTY_FUNCTION__); }));
    }
    else {
        destruct(op);
    }
}
static inline void
_Py_DECREF_NO_DEALLOC(PyObject *op)
{
    if (_Py_IsImmortal(((PyObject*)((op))))) {
        return;
    }
    ((void)0);
    op->ob_refcnt--;
}
__attribute__ ((visibility ("default"))) int _PyType_CheckConsistency(PyTypeObject *type);
__attribute__ ((visibility ("default"))) int _PyDict_CheckConsistency(PyObject *mp, int check_content);
extern int _PyTraceMalloc_NewReference(PyObject *op);
static inline int
_PyType_HasFeature(PyTypeObject *type, unsigned long feature) {
    return ((type->tp_flags & feature) != 0);
}
extern void _PyType_InitCache(PyInterpreterState *interp);
extern void _PyObject_InitState(PyInterpreterState *interp);
static inline void
_PyObject_Init(PyObject *op, PyTypeObject *typeobj)
{
    ((void) sizeof ((op != ((void *)0)) ? 1 : 0), __extension__ ({ if (op != ((void *)0)) ; else __assert_fail ("op != NULL", "/usr/include/python3.12/internal/pycore_object.h", 165, __extension__ __PRETTY_FUNCTION__); }));
    Py_SET_TYPE(((PyObject*)((op))), typeobj);
    if (_PyType_HasFeature(typeobj, (1UL << 9))) {
        Py_INCREF(((PyObject*)((typeobj))));
    }
    _Py_NewReference(op);
}
static inline void
_PyObject_InitVar(PyVarObject *op, PyTypeObject *typeobj, Py_ssize_t size)
{
    ((void) sizeof ((op != ((void *)0)) ? 1 : 0), __extension__ ({ if (op != ((void *)0)) ; else __assert_fail ("op != NULL", "/usr/include/python3.12/internal/pycore_object.h", 176, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((typeobj != &PyLong_Type) ? 1 : 0), __extension__ ({ if (typeobj != &PyLong_Type) ; else __assert_fail ("typeobj != &PyLong_Type", "/usr/include/python3.12/internal/pycore_object.h", 177, __extension__ __PRETTY_FUNCTION__); }));
    _PyObject_Init((PyObject *)op, typeobj);
    Py_SET_SIZE(((PyVarObject*)((op))), (size));
}
static inline void _PyObject_GC_TRACK(
    const char *filename, int lineno,
    PyObject *op)
{
    ((!_PyObject_GC_IS_TRACKED(((PyObject*)(op)))) ? (void)(0) : _PyObject_AssertFailed((op), "!_PyObject_GC_IS_TRACKED(((PyObject*)(op)))", ("object already tracked by the garbage collector"), (filename), (lineno), (__func__)));
    PyGC_Head *gc = _Py_AS_GC(op);
    (((gc->_gc_prev & (2)) == 0) ? (void)(0) : _PyObject_AssertFailed((op), "(gc->_gc_prev & (2)) == 0", ("object is in generation which is garbage collected"), (filename), (lineno), (__func__)));
    PyInterpreterState *interp = _PyInterpreterState_GET();
    PyGC_Head *generation0 = interp->gc.generation0;
    PyGC_Head *last = (PyGC_Head*)(generation0->_gc_prev);
    _PyGCHead_SET_NEXT(last, gc);
    _PyGCHead_SET_PREV(gc, last);
    _PyGCHead_SET_NEXT(gc, generation0);
    generation0->_gc_prev = (uintptr_t)gc;
}
static inline void _PyObject_GC_UNTRACK(
    const char *filename, int lineno,
    PyObject *op)
{
    ((_PyObject_GC_IS_TRACKED(((PyObject*)(op)))) ? (void)(0) : _PyObject_AssertFailed((op), "_PyObject_GC_IS_TRACKED(((PyObject*)(op)))", ("object not tracked by the garbage collector"), (filename), (lineno), (__func__)));
    PyGC_Head *gc = _Py_AS_GC(op);
    PyGC_Head *prev = _PyGCHead_PREV(gc);
    PyGC_Head *next = _PyGCHead_NEXT(gc);
    _PyGCHead_SET_NEXT(prev, next);
    _PyGCHead_SET_PREV(next, prev);
    gc->_gc_next = 0;
    gc->_gc_prev &= (1);
}
static inline PyObject **
_PyObject_GET_WEAKREFS_LISTPTR(PyObject *op)
{
    if (PyType_Check(((PyObject*)((op)))) &&
            ((PyTypeObject *)op)->tp_flags & (1 << 1)) {
        PyInterpreterState *interp = _PyInterpreterState_GET();
        static_builtin_state *state = _PyStaticType_GetState(
                                                interp, (PyTypeObject *)op);
        return _PyStaticType_GET_WEAKREFS_LISTPTR(state);
    }
    Py_ssize_t offset = Py_TYPE(((PyObject*)((op))))->tp_weaklistoffset;
    return (PyObject **)((char *)op + offset);
}
static inline PyWeakReference **
_PyObject_GET_WEAKREFS_LISTPTR_FROM_OFFSET(PyObject *op)
{
    ((void) sizeof ((!PyType_Check(((PyObject*)((op)))) || ((PyTypeObject *)op)->tp_flags & (1UL << 9)) ? 1 : 0), __extension__ ({ if (!PyType_Check(((PyObject*)((op)))) || ((PyTypeObject *)op)->tp_flags & (1UL << 9)) ; else __assert_fail ("!PyType_Check(op) || ((PyTypeObject *)op)->tp_flags & Py_TPFLAGS_HEAPTYPE", "/usr/include/python3.12/internal/pycore_object.h", 319, __extension__ __PRETTY_FUNCTION__); }));
    Py_ssize_t offset = Py_TYPE(((PyObject*)((op))))->tp_weaklistoffset;
    return (PyWeakReference **)((char *)op + offset);
}
static inline int
_PyObject_IS_GC(PyObject *obj)
{
    return (PyType_HasFeature((Py_TYPE(((PyObject*)((obj))))), (1UL << 14))
            && (Py_TYPE(((PyObject*)((obj))))->tp_is_gc == ((void *)0)
                || Py_TYPE(((PyObject*)((obj))))->tp_is_gc(obj)));
}
static inline size_t
_PyType_PreHeaderSize(PyTypeObject *tp)
{
    return _PyType_HasFeature((tp), (1UL << 14)) * sizeof(PyGC_Head) +
        _PyType_HasFeature(tp, ((1 << 3) | (1 << 4))) * 2 * sizeof(PyObject *);
}
void _PyObject_GC_Link(PyObject *op);
extern int _Py_CheckSlotResult(
    PyObject *obj,
    const char *slot_name,
    int success);
static inline int _PyType_SUPPORTS_WEAKREFS(PyTypeObject *type) {
    return (type->tp_weaklistoffset != 0);
}
extern PyObject* _PyType_AllocNoTrack(PyTypeObject *type, Py_ssize_t nitems);
extern int _PyObject_InitializeDict(PyObject *obj);
extern int _PyObject_StoreInstanceAttribute(PyObject *obj, PyDictValues *values,
                                          PyObject *name, PyObject *value);
PyObject * _PyObject_GetInstanceAttribute(PyObject *obj, PyDictValues *values,
                                        PyObject *name);
typedef union {
    PyObject *dict;
    char *values;
} PyDictOrValues;
static inline PyDictOrValues *
_PyObject_DictOrValuesPointer(PyObject *obj)
{
    ((void) sizeof ((Py_TYPE(((PyObject*)((obj))))->tp_flags & (1 << 4)) ? 1 : 0), __extension__ ({ if (Py_TYPE(((PyObject*)((obj))))->tp_flags & (1 << 4)) ; else __assert_fail ("Py_TYPE(obj)->tp_flags & Py_TPFLAGS_MANAGED_DICT", "/usr/include/python3.12/internal/pycore_object.h", 375, __extension__ __PRETTY_FUNCTION__); }));
    return ((PyDictOrValues *)obj)-3;
}
static inline int
_PyDictOrValues_IsValues(PyDictOrValues dorv)
{
    return ((uintptr_t)dorv.values) & 1;
}
static inline PyDictValues *
_PyDictOrValues_GetValues(PyDictOrValues dorv)
{
    ((void) sizeof ((_PyDictOrValues_IsValues(dorv)) ? 1 : 0), __extension__ ({ if (_PyDictOrValues_IsValues(dorv)) ; else __assert_fail ("_PyDictOrValues_IsValues(dorv)", "/usr/include/python3.12/internal/pycore_object.h", 388, __extension__ __PRETTY_FUNCTION__); }));
    return (PyDictValues *)(dorv.values + 1);
}
static inline PyObject *
_PyDictOrValues_GetDict(PyDictOrValues dorv)
{
    ((void) sizeof ((!_PyDictOrValues_IsValues(dorv)) ? 1 : 0), __extension__ ({ if (!_PyDictOrValues_IsValues(dorv)) ; else __assert_fail ("!_PyDictOrValues_IsValues(dorv)", "/usr/include/python3.12/internal/pycore_object.h", 395, __extension__ __PRETTY_FUNCTION__); }));
    return dorv.dict;
}
static inline void
_PyDictOrValues_SetValues(PyDictOrValues *ptr, PyDictValues *values)
{
    ptr->values = ((char *)values) - 1;
}
extern PyObject ** _PyObject_ComputedDictPointer(PyObject *);
extern void _PyObject_FreeInstanceAttributes(PyObject *obj);
extern int _PyObject_IsInstanceDictEmpty(PyObject *);
__attribute__ ((visibility ("default"))) PyObject * _PyObject_LookupSpecial(PyObject *, PyObject *);
static const char list_insert__doc__[] = "insert($self, index, object, /)\n" "--\n" "\n" "Insert object before index.";
static PyObject *
list_insert_impl(PyListObject *self, Py_ssize_t index, PyObject *object);
static PyObject *
list_insert(PyListObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    PyObject *return_value = ((void *)0);
    Py_ssize_t index;
    PyObject *object;
    if (!((!((2) == 0x7fffffffffffffffL) && (2) <= (nargs) && (nargs) <= (2)) || _PyArg_CheckPositional(("insert"), (nargs), (2), (2)))) {
        goto exit;
    }
    {
        Py_ssize_t ival = -1;
        PyObject *iobj = _PyNumber_Index(args[0]);
        if (iobj != ((void *)0)) {
            ival = PyLong_AsSsize_t(iobj);
            Py_DECREF(((PyObject*)((iobj))));
        }
        if (ival == -1 && PyErr_Occurred()) {
            goto exit;
        }
        index = ival;
    }
    object = args[1];
    return_value = list_insert_impl(self, index, object);
exit:
    return return_value;
}
static const char list_clear__doc__[] = "clear($self, /)\n" "--\n" "\n" "Remove all items from list.";
static PyObject *
list_clear_impl(PyListObject *self);
static PyObject *
list_clear(PyListObject *self, PyObject *_unused_ignored __attribute__((unused)))
{
    return list_clear_impl(self);
}
static const char list_copy__doc__[] = "copy($self, /)\n" "--\n" "\n" "Return a shallow copy of the list.";
static PyObject *
list_copy_impl(PyListObject *self);
static PyObject *
list_copy(PyListObject *self, PyObject *_unused_ignored __attribute__((unused)))
{
    return list_copy_impl(self);
}
static const char list_append__doc__[] = "append($self, object, /)\n" "--\n" "\n" "Append object to the end of the list.";
static const char list_extend__doc__[] = "extend($self, iterable, /)\n" "--\n" "\n" "Extend list by appending elements from the iterable.";
static const char list_pop__doc__[] = "pop($self, index=-1, /)\n" "--\n" "\n" "Remove and return item at index (default last).\n" "\n" "Raises IndexError if list is empty or index is out of range.";
static PyObject *
list_pop_impl(PyListObject *self, Py_ssize_t index);
static PyObject *
list_pop(PyListObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    PyObject *return_value = ((void *)0);
    Py_ssize_t index = -1;
    if (!((!((1) == 0x7fffffffffffffffL) && (0) <= (nargs) && (nargs) <= (1)) || _PyArg_CheckPositional(("pop"), (nargs), (0), (1)))) {
        goto exit;
    }
    if (nargs < 1) {
        goto skip_optional;
    }
    {
        Py_ssize_t ival = -1;
        PyObject *iobj = _PyNumber_Index(args[0]);
        if (iobj != ((void *)0)) {
            ival = PyLong_AsSsize_t(iobj);
            Py_DECREF(((PyObject*)((iobj))));
        }
        if (ival == -1 && PyErr_Occurred()) {
            goto exit;
        }
        index = ival;
    }
skip_optional:
    return_value = list_pop_impl(self, index);
exit:
    return return_value;
}
static const char list_sort__doc__[] = "sort($self, /, *, key=None, reverse=False)\n" "--\n" "\n" "Sort the list in ascending order and return None.\n" "\n" "The sort is in-place (i.e. the list itself is modified) and stable (i.e. the\n" "order of two equal elements is maintained).\n" "\n" "If a key function is given, apply it once to each list item and sort them,\n" "ascending or descending, according to their function values.\n" "\n" "The reverse flag can be set to sort in descending order.";
static PyObject *
list_sort_impl(PyListObject *self, PyObject *keyfunc, int reverse);
static PyObject *
list_sort(PyListObject *self, PyObject *const *args, Py_ssize_t nargs, PyObject *kwnames)
{
    PyObject *return_value = ((void *)0);
    static struct {
        PyGC_Head _this_is_not_used;
        PyVarObject ob_base;
        PyObject *ob_item[2];
    } _kwtuple = {
        .ob_base = { { { (0x7fffffff * 2U + 1U) }, (&PyTuple_Type) }, (2) },
        .ob_item = { &(_PyRuntime.static_objects.singletons.strings.identifiers._py_key._ascii.ob_base), &(_PyRuntime.static_objects.singletons.strings.identifiers._py_reverse._ascii.ob_base), },
    };
    static const char * const _keywords[] = {"key", "reverse", ((void *)0)};
    static _PyArg_Parser _parser = {
        .keywords = _keywords,
        .fname = "sort",
        .kwtuple = (&_kwtuple.ob_base.ob_base),
    };
    PyObject *argsbuf[2];
    Py_ssize_t noptargs = nargs + (kwnames ? PyTuple_GET_SIZE(((PyObject*)((kwnames)))) : 0) - 0;
    PyObject *keyfunc = (&_Py_NoneStruct);
    int reverse = 0;
    args = (((0) == 0 && (((void *)0)) == ((void *)0) && (kwnames) == ((void *)0) && (0) <= (nargs) && (nargs) <= (0) && (args) != ((void *)0)) ? (args) : _PyArg_UnpackKeywords((args), (nargs), (((void *)0)), (kwnames), (&_parser), (0), (0), (0), (argsbuf)));
    if (!args) {
        goto exit;
    }
    if (!noptargs) {
        goto skip_optional_kwonly;
    }
    if (args[0]) {
        keyfunc = args[0];
        if (!--noptargs) {
            goto skip_optional_kwonly;
        }
    }
    reverse = PyObject_IsTrue(args[1]);
    if (reverse < 0) {
        goto exit;
    }
skip_optional_kwonly:
    return_value = list_sort_impl(self, keyfunc, reverse);
exit:
    return return_value;
}
static const char list_reverse__doc__[] = "reverse($self, /)\n" "--\n" "\n" "Reverse *IN PLACE*.";
static PyObject *
list_reverse_impl(PyListObject *self);
static PyObject *
list_reverse(PyListObject *self, PyObject *_unused_ignored __attribute__((unused)))
{
    return list_reverse_impl(self);
}
static const char list_index__doc__[] = "index($self, value, start=0, stop=sys.maxsize, /)\n" "--\n" "\n" "Return first index of value.\n" "\n" "Raises ValueError if the value is not present.";
static PyObject *
list_index_impl(PyListObject *self, PyObject *value, Py_ssize_t start,
                Py_ssize_t stop);
static PyObject *
list_index(PyListObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    PyObject *return_value = ((void *)0);
    PyObject *value;
    Py_ssize_t start = 0;
    Py_ssize_t stop = 0x7fffffffffffffffL;
    if (!((!((3) == 0x7fffffffffffffffL) && (1) <= (nargs) && (nargs) <= (3)) || _PyArg_CheckPositional(("index"), (nargs), (1), (3)))) {
        goto exit;
    }
    value = args[0];
    if (nargs < 2) {
        goto skip_optional;
    }
    if (!_PyEval_SliceIndexNotNone(args[1], &start)) {
        goto exit;
    }
    if (nargs < 3) {
        goto skip_optional;
    }
    if (!_PyEval_SliceIndexNotNone(args[2], &stop)) {
        goto exit;
    }
skip_optional:
    return_value = list_index_impl(self, value, start, stop);
exit:
    return return_value;
}
static const char list_count__doc__[] = "count($self, value, /)\n" "--\n" "\n" "Return number of occurrences of value.";
static const char list_remove__doc__[] = "remove($self, value, /)\n" "--\n" "\n" "Remove first occurrence of value.\n" "\n" "Raises ValueError if the value is not present.";
static const char list___init____doc__[] = "list(iterable=(), /)\n" "--\n" "\n" "Built-in mutable sequence.\n" "\n" "If no argument is given, the constructor creates a new empty list.\n" "The argument must be an iterable if specified.";
static int
list___init___impl(PyListObject *self, PyObject *iterable);
static int
list___init__(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int return_value = -1;
    PyTypeObject *base_tp = &PyList_Type;
    PyObject *iterable = ((void *)0);
    if ((Py_IS_TYPE(((PyObject*)((self))), (base_tp)) ||
         Py_TYPE(((PyObject*)((self))))->tp_new == base_tp->tp_new) &&
        !((kwargs) == ((void *)0) || _PyArg_NoKeywords(("list"), (kwargs)))) {
        goto exit;
    }
    if (!((!((1) == 0x7fffffffffffffffL) && (0) <= (PyTuple_GET_SIZE(((PyObject*)((args))))) && (PyTuple_GET_SIZE(((PyObject*)((args))))) <= (1)) || _PyArg_CheckPositional(("list"), (PyTuple_GET_SIZE(((PyObject*)((args))))), (0), (1)))) {
        goto exit;
    }
    if (PyTuple_GET_SIZE(((PyObject*)((args)))) < 1) {
        goto skip_optional;
    }
    iterable = ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((args))))), ((1UL << 26)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((args))))), ((1UL << 26)))) ; else __assert_fail ("PyTuple_Check(args)", "/home/bag/repos/cpython/Objects/clinic/listobject.c.h", 343, __extension__ __PRETTY_FUNCTION__); })), ((PyTupleObject*)((args))))->ob_item[(0)]);
skip_optional:
    return_value = list___init___impl((PyListObject *)self, iterable);
exit:
    return return_value;
}
static const char list___sizeof____doc__[] = "__sizeof__($self, /)\n" "--\n" "\n" "Return the size of the list in memory, in bytes.";
static PyObject *
list___sizeof___impl(PyListObject *self);
static PyObject *
list___sizeof__(PyListObject *self, PyObject *_unused_ignored __attribute__((unused)))
{
    return list___sizeof___impl(self);
}
static const char list___reversed____doc__[] = "__reversed__($self, /)\n" "--\n" "\n" "Return a reverse iterator over the list.";
static PyObject *
list___reversed___impl(PyListObject *self);
static PyObject *
list___reversed__(PyListObject *self, PyObject *_unused_ignored __attribute__((unused)))
{
    return list___reversed___impl(self);
}
;
static struct _Py_list_state *
get_list_state(void)
{
    PyInterpreterState *interp = _PyInterpreterState_GET();
    return &interp->list;
}
static int
list_resize(PyListObject *self, Py_ssize_t newsize)
{
    PyObject **items;
    size_t new_allocated, num_allocated_bytes;
    Py_ssize_t allocated = self->allocated;
    if (allocated >= newsize && newsize >= (allocated >> 1)) {
        ((void) sizeof ((self->ob_item != ((void *)0) || newsize == 0) ? 1 : 0), __extension__ ({ if (self->ob_item != ((void *)0) || newsize == 0) ; else __assert_fail ("self->ob_item != NULL || newsize == 0", "/home/bag/repos/cpython/Objects/listobject.c", 56, __extension__ __PRETTY_FUNCTION__); }));
        Py_SET_SIZE(((PyVarObject*)((self))), (newsize));
        return 0;
    }
    new_allocated = ((size_t)newsize + (newsize >> 3) + 6) & ~(size_t)3;
    if (newsize - Py_SIZE(((PyObject*)((self)))) > (Py_ssize_t)(new_allocated - newsize))
        new_allocated = ((size_t)newsize + 3) & ~(size_t)3;
    if (newsize == 0)
        new_allocated = 0;
    if (new_allocated <= (size_t)0x7fffffffffffffffL / sizeof(PyObject *)) {
        num_allocated_bytes = new_allocated * sizeof(PyObject *);
        items = (PyObject **)PyMem_Realloc(self->ob_item, num_allocated_bytes);
    }
    else {
        items = ((void *)0);
    }
    if (items == ((void *)0)) {
        PyErr_NoMemory();
        return -1;
    }
    self->ob_item = items;
    Py_SET_SIZE(((PyVarObject*)((self))), (newsize));
    self->allocated = new_allocated;
    return 0;
}
static int
list_preallocate_exact(PyListObject *self, Py_ssize_t size)
{
    ((void) sizeof ((self->ob_item == ((void *)0)) ? 1 : 0), __extension__ ({ if (self->ob_item == ((void *)0)) ; else __assert_fail ("self->ob_item == NULL", "/home/bag/repos/cpython/Objects/listobject.c", 101, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((size > 0) ? 1 : 0), __extension__ ({ if (size > 0) ; else __assert_fail ("size > 0", "/home/bag/repos/cpython/Objects/listobject.c", 102, __extension__ __PRETTY_FUNCTION__); }));
    size = (size + 1) & ~(size_t)1;
    PyObject **items = ( ((size_t)(size) > 0x7fffffffffffffffL / sizeof(PyObject*)) ? ((void *)0) : ( (PyObject* *) PyMem_Malloc((size) * sizeof(PyObject*)) ) );
    if (items == ((void *)0)) {
        PyErr_NoMemory();
        return -1;
    }
    self->ob_item = items;
    self->allocated = size;
    return 0;
}
void
_PyList_ClearFreeList(PyInterpreterState *interp)
{
    struct _Py_list_state *state = &interp->list;
    while (state->numfree) {
        PyListObject *op = state->free_list[--state->numfree];
        ((void) sizeof ((Py_IS_TYPE(((PyObject*)(((op)))), (&PyList_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)(((op)))), (&PyList_Type))) ; else __assert_fail ("PyList_CheckExact(op)", "/home/bag/repos/cpython/Objects/listobject.c", 127, __extension__ __PRETTY_FUNCTION__); }));
        PyObject_GC_Del(op);
    }
}
void
_PyList_Fini(PyInterpreterState *interp)
{
    _PyList_ClearFreeList(interp);
}
void
_PyList_DebugMallocStats(FILE *out)
{
    struct _Py_list_state *state = get_list_state();
    _PyDebugAllocatorStats(out,
                           "free PyListObject",
                           state->numfree, sizeof(PyListObject));
}
PyObject *
PyList_New(Py_ssize_t size)
{
    PyListObject *op;
    if (size < 0) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 161);
        return ((void *)0);
    }
    struct _Py_list_state *state = get_list_state();
    if (80 && state->numfree) {
        state->numfree--;
        op = state->free_list[state->numfree];
        ((void)0);
        _Py_NewReference((PyObject *)op);
    }
    else
    {
        op = ((PyListObject*)(_PyObject_GC_New(&PyList_Type)));
        if (op == ((void *)0)) {
            return ((void *)0);
        }
    }
    if (size <= 0) {
        op->ob_item = ((void *)0);
    }
    else {
        op->ob_item = (PyObject **) PyMem_Calloc(size, sizeof(PyObject *));
        if (op->ob_item == ((void *)0)) {
            Py_DECREF(((PyObject*)((op))));
            return PyErr_NoMemory();
        }
    }
    Py_SET_SIZE(((PyVarObject*)((op))), (size));
    op->allocated = size;
    _PyObject_GC_TRACK("/home/bag/repos/cpython/Objects/listobject.c", 197, ((PyObject*)((op))));
    return (PyObject *) op;
}
static PyObject *
list_new_prealloc(Py_ssize_t size)
{
    ((void) sizeof ((size > 0) ? 1 : 0), __extension__ ({ if (size > 0) ; else __assert_fail ("size > 0", "/home/bag/repos/cpython/Objects/listobject.c", 204, __extension__ __PRETTY_FUNCTION__); }));
    PyListObject *op = (PyListObject *) PyList_New(0);
    if (op == ((void *)0)) {
        return ((void *)0);
    }
    ((void) sizeof ((op->ob_item == ((void *)0)) ? 1 : 0), __extension__ ({ if (op->ob_item == ((void *)0)) ; else __assert_fail ("op->ob_item == NULL", "/home/bag/repos/cpython/Objects/listobject.c", 209, __extension__ __PRETTY_FUNCTION__); }));
    op->ob_item = ( ((size_t)(size) > 0x7fffffffffffffffL / sizeof(PyObject *)) ? ((void *)0) : ( (PyObject * *) PyMem_Malloc((size) * sizeof(PyObject *)) ) );
    if (op->ob_item == ((void *)0)) {
        Py_DECREF(((PyObject*)((op))));
        return PyErr_NoMemory();
    }
    op->allocated = size;
    return (PyObject *) op;
}
Py_ssize_t
PyList_Size(PyObject *op)
{
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 223);
        return -1;
    }
    else
        return Py_SIZE(((PyObject*)((op))));
}
static inline int
valid_index(Py_ssize_t i, Py_ssize_t limit)
{
    return (size_t) i < (size_t) limit;
}
PyObject *
PyList_GetItem(PyObject *op, Py_ssize_t i)
{
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 247);
        return ((void *)0);
    }
    if (!valid_index(i, Py_SIZE(((PyObject*)((op)))))) {
        ;
        PyErr_SetObject(PyExc_IndexError, &(_PyRuntime.static_objects.singletons.strings.literals._py_list_err._ascii.ob_base));
        return ((void *)0);
    }
    return ((PyListObject *)op) -> ob_item[i];
}
int
PyList_SetItem(PyObject *op, Py_ssize_t i,
               PyObject *newitem)
{
    PyObject **p;
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) {
        Py_XDECREF(((PyObject*)((newitem))));
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 265);
        return -1;
    }
    if (!valid_index(i, Py_SIZE(((PyObject*)((op)))))) {
        Py_XDECREF(((PyObject*)((newitem))));
        PyErr_SetString(PyExc_IndexError,
                        "list assignment index out of range");
        return -1;
    }
    p = ((PyListObject *)op) -> ob_item + i;
    do { __typeof__(*p)* _tmp_dst_ptr = &(*p); __typeof__(*p) _tmp_old_dst = (*_tmp_dst_ptr); *_tmp_dst_ptr = (newitem); Py_XDECREF(((PyObject*)((_tmp_old_dst)))); } while (0);
    return 0;
}
static int
ins1(PyListObject *self, Py_ssize_t where, PyObject *v)
{
    Py_ssize_t i, n = Py_SIZE(((PyObject*)((self))));
    PyObject **items;
    if (v == ((void *)0)) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 285);
        return -1;
    }
    ((void) sizeof (((size_t)n + 1 < 0x7fffffffffffffffL) ? 1 : 0), __extension__ ({ if ((size_t)n + 1 < 0x7fffffffffffffffL) ; else __assert_fail ("(size_t)n + 1 < PY_SSIZE_T_MAX", "/home/bag/repos/cpython/Objects/listobject.c", 289, __extension__ __PRETTY_FUNCTION__); }));
    if (list_resize(self, n+1) < 0)
        return -1;
    if (where < 0) {
        where += n;
        if (where < 0)
            where = 0;
    }
    if (where > n)
        where = n;
    items = self->ob_item;
    for (i = n; --i >= where; )
        items[i+1] = items[i];
    items[where] = _Py_NewRef(((PyObject*)((v))));
    return 0;
}
int
PyList_Insert(PyObject *op, Py_ssize_t where, PyObject *newitem)
{
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 311);
        return -1;
    }
    return ins1((PyListObject *)op, where, newitem);
}
int
_PyList_AppendTakeRefListResize(PyListObject *self, PyObject *newitem)
{
    Py_ssize_t len = PyList_GET_SIZE(((PyObject*)((self))));
    ((void) sizeof ((self->allocated == -1 || self->allocated == len) ? 1 : 0), __extension__ ({ if (self->allocated == -1 || self->allocated == len) ; else __assert_fail ("self->allocated == -1 || self->allocated == len", "/home/bag/repos/cpython/Objects/listobject.c", 322, __extension__ __PRETTY_FUNCTION__); }));
    if (list_resize(self, len + 1) < 0) {
        Py_DECREF(((PyObject*)((newitem))));
        return -1;
    }
    PyList_SET_ITEM(((PyObject*)((self))), (len), ((PyObject*)((newitem))));
    return 0;
}
int
PyList_Append(PyObject *op, PyObject *newitem)
{
    if (PyType_HasFeature((Py_TYPE(((PyObject*)((op))))), ((1UL << 25))) && (newitem != ((void *)0))) {
        return _PyList_AppendTakeRef((PyListObject *)op, _Py_NewRef(((PyObject*)((newitem)))));
    }
    _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 337);
    return -1;
}
static void
list_dealloc(PyListObject *op)
{
    Py_ssize_t i;
    PyObject_GC_UnTrack(op);
    do { PyThreadState *_tstate = ((void *)0); if (_PyTrash_cond(((PyObject*)((op))), (destructor)(list_dealloc))) { _tstate = _PyThreadState_UncheckedGet(); if (_PyTrash_begin(_tstate, ((PyObject*)(((op)))))) { break; } }
    if (op->ob_item != ((void *)0)) {
        i = Py_SIZE(((PyObject*)((op))));
        while (--i >= 0) {
            Py_XDECREF(((PyObject*)((op->ob_item[i]))));
        }
        PyMem_Free(op->ob_item);
    }
    struct _Py_list_state *state = get_list_state();
    if (state->numfree < 80 && Py_IS_TYPE(((PyObject*)(((op)))), (&PyList_Type))) {
        state->free_list[state->numfree++] = op;
        ((void)0);
    }
    else
    {
        Py_TYPE(((PyObject*)((op))))->tp_free((PyObject *)op);
    }
    if (_tstate) { _PyTrash_end(_tstate); } } while (0);
}
static PyObject *
list_repr(PyListObject *v)
{
    Py_ssize_t i;
    PyObject *s;
    _PyUnicodeWriter writer;
    if (Py_SIZE(((PyObject*)((v)))) == 0) {
        return PyUnicode_FromString("[]");
    }
    i = Py_ReprEnter((PyObject*)v);
    if (i != 0) {
        return i > 0 ? PyUnicode_FromString("[...]") : ((void *)0);
    }
    _PyUnicodeWriter_Init(&writer);
    writer.overallocate = 1;
    writer.min_length = 1 + 1 + (2 + 1) * (Py_SIZE(((PyObject*)((v)))) - 1) + 1;
    if (_PyUnicodeWriter_WriteChar(&writer, '[') < 0)
        goto error;
    for (i = 0; i < Py_SIZE(((PyObject*)((v)))); ++i) {
        if (i > 0) {
            if (_PyUnicodeWriter_WriteASCIIString(&writer, ", ", 2) < 0)
                goto error;
        }
        s = PyObject_Repr(v->ob_item[i]);
        if (s == ((void *)0))
            goto error;
        if (_PyUnicodeWriter_WriteStr(&writer, s) < 0) {
            Py_DECREF(((PyObject*)((s))));
            goto error;
        }
        Py_DECREF(((PyObject*)((s))));
    }
    writer.overallocate = 0;
    if (_PyUnicodeWriter_WriteChar(&writer, ']') < 0)
        goto error;
    Py_ReprLeave((PyObject *)v);
    return _PyUnicodeWriter_Finish(&writer);
error:
    _PyUnicodeWriter_Dealloc(&writer);
    Py_ReprLeave((PyObject *)v);
    return ((void *)0);
}
static Py_ssize_t
list_length(PyListObject *a)
{
    return Py_SIZE(((PyObject*)((a))));
}
static int
list_contains(PyListObject *a, PyObject *el)
{
    PyObject *item;
    Py_ssize_t i;
    int cmp;
    for (i = 0, cmp = 0 ; cmp == 0 && i < Py_SIZE(((PyObject*)((a)))); ++i) {
        item = ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((a))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((a))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(a)", "/home/bag/repos/cpython/Objects/listobject.c", 448, __extension__ __PRETTY_FUNCTION__); })), ((PyListObject*)((a))))->ob_item[(i)]);
        Py_INCREF(((PyObject*)((item))));
        cmp = PyObject_RichCompareBool(item, el, 2);
        Py_DECREF(((PyObject*)((item))));
    }
    return cmp;
}
static PyObject *
list_item(PyListObject *a, Py_ssize_t i)
{
    if (!valid_index(i, Py_SIZE(((PyObject*)((a)))))) {
        PyErr_SetObject(PyExc_IndexError, &(_PyRuntime.static_objects.singletons.strings.literals._py_list_err._ascii.ob_base));
        return ((void *)0);
    }
    return _Py_NewRef(((PyObject*)((a->ob_item[i]))));
}
static PyObject *
list_slice(PyListObject *a, Py_ssize_t ilow, Py_ssize_t ihigh)
{
    PyListObject *np;
    PyObject **src, **dest;
    Py_ssize_t i, len;
    len = ihigh - ilow;
    if (len <= 0) {
        return PyList_New(0);
    }
    np = (PyListObject *) list_new_prealloc(len);
    if (np == ((void *)0))
        return ((void *)0);
    src = a->ob_item + ilow;
    dest = np->ob_item;
    for (i = 0; i < len; i++) {
        PyObject *v = src[i];
        dest[i] = _Py_NewRef(((PyObject*)((v))));
    }
    Py_SET_SIZE(((PyVarObject*)((np))), (len));
    return (PyObject *)np;
}
PyObject *
PyList_GetSlice(PyObject *a, Py_ssize_t ilow, Py_ssize_t ihigh)
{
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((a))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 494);
        return ((void *)0);
    }
    if (ilow < 0) {
        ilow = 0;
    }
    else if (ilow > Py_SIZE(((PyObject*)((a))))) {
        ilow = Py_SIZE(((PyObject*)((a))));
    }
    if (ihigh < ilow) {
        ihigh = ilow;
    }
    else if (ihigh > Py_SIZE(((PyObject*)((a))))) {
        ihigh = Py_SIZE(((PyObject*)((a))));
    }
    return list_slice((PyListObject *)a, ilow, ihigh);
}
static PyObject *
list_concat(PyListObject *a, PyObject *bb)
{
    Py_ssize_t size;
    Py_ssize_t i;
    PyObject **src, **dest;
    PyListObject *np;
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((bb))))), ((1UL << 25)))) {
        PyErr_Format(PyExc_TypeError,
                  "can only concatenate list (not \"%.200s\") to list",
                  Py_TYPE(((PyObject*)((bb))))->tp_name);
        return ((void *)0);
    }
    ((void) sizeof (((size_t)Py_SIZE(((PyObject*)((a)))) + (size_t)Py_SIZE(((PyObject*)((((PyListObject *)bb))))) < 0x7fffffffffffffffL) ? 1 : 0), __extension__ ({ if ((size_t)Py_SIZE(((PyObject*)((a)))) + (size_t)Py_SIZE(((PyObject*)((((PyListObject *)bb))))) < 0x7fffffffffffffffL) ; else __assert_fail ("(size_t)Py_SIZE(a) + (size_t)Py_SIZE(b) < PY_SSIZE_T_MAX", "/home/bag/repos/cpython/Objects/listobject.c", 526, __extension__ __PRETTY_FUNCTION__); }));
    size = Py_SIZE(((PyObject*)((a)))) + Py_SIZE(((PyObject*)((((PyListObject *)bb)))));
    if (size == 0) {
        return PyList_New(0);
    }
    np = (PyListObject *) list_new_prealloc(size);
    if (np == ((void *)0)) {
        return ((void *)0);
    }
    src = a->ob_item;
    dest = np->ob_item;
    for (i = 0; i < Py_SIZE(((PyObject*)((a)))); i++) {
        PyObject *v = src[i];
        dest[i] = _Py_NewRef(((PyObject*)((v))));
    }
    src = ((PyListObject *)bb)->ob_item;
    dest = np->ob_item + Py_SIZE(((PyObject*)((a))));
    for (i = 0; i < Py_SIZE(((PyObject*)((((PyListObject *)bb))))); i++) {
        PyObject *v = src[i];
        dest[i] = _Py_NewRef(((PyObject*)((v))));
    }
    Py_SET_SIZE(((PyVarObject*)((np))), (size));
    return (PyObject *)np;
}
static PyObject *
list_repeat(PyListObject *a, Py_ssize_t n)
{
    const Py_ssize_t input_size = Py_SIZE(((PyObject*)((a))));
    if (input_size == 0 || n <= 0)
        return PyList_New(0);
    ((void) sizeof ((n > 0) ? 1 : 0), __extension__ ({ if (n > 0) ; else __assert_fail ("n > 0", "/home/bag/repos/cpython/Objects/listobject.c", 558, __extension__ __PRETTY_FUNCTION__); }));
    if (input_size > 0x7fffffffffffffffL / n)
        return PyErr_NoMemory();
    Py_ssize_t output_size = input_size * n;
    PyListObject *np = (PyListObject *) list_new_prealloc(output_size);
    if (np == ((void *)0))
        return ((void *)0);
    PyObject **dest = np->ob_item;
    if (input_size == 1) {
        PyObject *elem = a->ob_item[0];
        _Py_RefcntAdd(((PyObject*)((elem))), n);
        PyObject **dest_end = dest + output_size;
        while (dest < dest_end) {
            *dest++ = elem;
        }
    }
    else {
        PyObject **src = a->ob_item;
        PyObject **src_end = src + input_size;
        while (src < src_end) {
            _Py_RefcntAdd(((PyObject*)((*src))), n);
            *dest++ = *src++;
        }
        _Py_memory_repeat((char *)np->ob_item, sizeof(PyObject *)*output_size,
                                        sizeof(PyObject *)*input_size);
    }
    Py_SET_SIZE(((PyVarObject*)((np))), (output_size));
    return (PyObject *) np;
}
static int
_list_clear(PyListObject *a)
{
    Py_ssize_t i;
    PyObject **item = a->ob_item;
    if (item != ((void *)0)) {
        i = Py_SIZE(((PyObject*)((a))));
        Py_SET_SIZE(((PyVarObject*)((a))), (0));
        a->ob_item = ((void *)0);
        a->allocated = 0;
        while (--i >= 0) {
            Py_XDECREF(((PyObject*)((item[i]))));
        }
        PyMem_Free(item);
    }
    return 0;
}
static int
list_ass_slice(PyListObject *a, Py_ssize_t ilow, Py_ssize_t ihigh, PyObject *v)
{
    PyObject *recycle_on_stack[8];
    PyObject **recycle = recycle_on_stack;
    PyObject **item;
    PyObject **vitem = ((void *)0);
    PyObject *v_as_SF = ((void *)0);
    Py_ssize_t n;
    Py_ssize_t norig;
    Py_ssize_t d;
    Py_ssize_t k;
    size_t s;
    int result = -1;
    if (v == ((void *)0))
        n = 0;
    else {
        if (a == ((PyListObject *)v)) {
            v = list_slice(((PyListObject *)v), 0, Py_SIZE(((PyObject*)((((PyListObject *)v))))));
            if (v == ((void *)0))
                return result;
            result = list_ass_slice(a, ilow, ihigh, v);
            Py_DECREF(((PyObject*)((v))));
            return result;
        }
        v_as_SF = PySequence_Fast(v, "can only assign an iterable");
        if(v_as_SF == ((void *)0))
            goto Error;
        n = (PyType_HasFeature((Py_TYPE(((PyObject*)((v_as_SF))))), ((1UL << 25))) ? PyList_GET_SIZE(((PyObject*)((v_as_SF)))) : PyTuple_GET_SIZE(((PyObject*)((v_as_SF)))));
        vitem = (PyType_HasFeature((Py_TYPE(((PyObject*)((v_as_SF))))), ((1UL << 25))) ? ((PyListObject *)(v_as_SF))->ob_item : ((PyTupleObject *)(v_as_SF))->ob_item);
    }
    if (ilow < 0)
        ilow = 0;
    else if (ilow > Py_SIZE(((PyObject*)((a)))))
        ilow = Py_SIZE(((PyObject*)((a))));
    if (ihigh < ilow)
        ihigh = ilow;
    else if (ihigh > Py_SIZE(((PyObject*)((a)))))
        ihigh = Py_SIZE(((PyObject*)((a))));
    norig = ihigh - ilow;
    ((void) sizeof ((norig >= 0) ? 1 : 0), __extension__ ({ if (norig >= 0) ; else __assert_fail ("norig >= 0", "/home/bag/repos/cpython/Objects/listobject.c", 672, __extension__ __PRETTY_FUNCTION__); }));
    d = n - norig;
    if (Py_SIZE(((PyObject*)((a)))) + d == 0) {
        Py_XDECREF(((PyObject*)((v_as_SF))));
        return _list_clear(a);
    }
    item = a->ob_item;
    s = norig * sizeof(PyObject *);
    if (s) {
        if (s > sizeof(recycle_on_stack)) {
            recycle = (PyObject **)PyMem_Malloc(s);
            if (recycle == ((void *)0)) {
                PyErr_NoMemory();
                goto Error;
            }
        }
        memcpy(recycle, &item[ilow], s);
    }
    if (d < 0) {
        Py_ssize_t tail;
        tail = (Py_SIZE(((PyObject*)((a)))) - ihigh) * sizeof(PyObject *);
        memmove(&item[ihigh+d], &item[ihigh], tail);
        if (list_resize(a, Py_SIZE(((PyObject*)((a)))) + d) < 0) {
            memmove(&item[ihigh], &item[ihigh+d], tail);
            memcpy(&item[ilow], recycle, s);
            goto Error;
        }
        item = a->ob_item;
    }
    else if (d > 0) {
        k = Py_SIZE(((PyObject*)((a))));
        if (list_resize(a, k+d) < 0)
            goto Error;
        item = a->ob_item;
        memmove(&item[ihigh+d], &item[ihigh],
            (k - ihigh)*sizeof(PyObject *));
    }
    for (k = 0; k < n; k++, ilow++) {
        PyObject *w = vitem[k];
        item[ilow] = _Py_XNewRef(((PyObject*)((w))));
    }
    for (k = norig - 1; k >= 0; --k)
        Py_XDECREF(((PyObject*)((recycle[k]))));
    result = 0;
 Error:
    if (recycle != recycle_on_stack)
        PyMem_Free(recycle);
    Py_XDECREF(((PyObject*)((v_as_SF))));
    return result;
}
int
PyList_SetSlice(PyObject *a, Py_ssize_t ilow, Py_ssize_t ihigh, PyObject *v)
{
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((a))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 731);
        return -1;
    }
    return list_ass_slice((PyListObject *)a, ilow, ihigh, v);
}
static PyObject *
list_inplace_repeat(PyListObject *self, Py_ssize_t n)
{
    Py_ssize_t input_size = PyList_GET_SIZE(((PyObject*)((self))));
    if (input_size == 0 || n == 1) {
        return _Py_NewRef(((PyObject*)((self))));
    }
    if (n < 1) {
        (void)_list_clear(self);
        return _Py_NewRef(((PyObject*)((self))));
    }
    if (input_size > 0x7fffffffffffffffL / n) {
        return PyErr_NoMemory();
    }
    Py_ssize_t output_size = input_size * n;
    if (list_resize(self, output_size) < 0)
        return ((void *)0);
    PyObject **items = self->ob_item;
    for (Py_ssize_t j = 0; j < input_size; j++) {
        _Py_RefcntAdd(((PyObject*)((items[j]))), n-1);
    }
    _Py_memory_repeat((char *)items, sizeof(PyObject *)*output_size,
                      sizeof(PyObject *)*input_size);
    return _Py_NewRef(((PyObject*)((self))));
}
static int
list_ass_item(PyListObject *a, Py_ssize_t i, PyObject *v)
{
    if (!valid_index(i, Py_SIZE(((PyObject*)((a)))))) {
        PyErr_SetString(PyExc_IndexError,
                        "list assignment index out of range");
        return -1;
    }
    if (v == ((void *)0))
        return list_ass_slice(a, i, i+1, v);
    do { __typeof__(a->ob_item[i])* _tmp_dst_ptr = &(a->ob_item[i]); __typeof__(a->ob_item[i]) _tmp_old_dst = (*_tmp_dst_ptr); *_tmp_dst_ptr = (_Py_NewRef(((PyObject*)((v))))); Py_DECREF(((PyObject*)((_tmp_old_dst)))); } while (0);
    return 0;
}
static PyObject *
list_insert_impl(PyListObject *self, Py_ssize_t index, PyObject *object)
{
    if (ins1(self, index, object) == 0)
        return (&_Py_NoneStruct);
    return ((void *)0);
}
static PyObject *
list_clear_impl(PyListObject *self)
{
    _list_clear(self);
    return (&_Py_NoneStruct);
}
static PyObject *
list_copy_impl(PyListObject *self)
{
    return list_slice(self, 0, Py_SIZE(((PyObject*)((self)))));
}
static PyObject *
list_append(PyListObject *self, PyObject *object)
{
    if (_PyList_AppendTakeRef(self, _Py_NewRef(((PyObject*)((object))))) < 0) {
        return ((void *)0);
    }
    return (&_Py_NoneStruct);
}
static PyObject *
list_extend(PyListObject *self, PyObject *iterable)
{
    PyObject *it;
    Py_ssize_t m;
    Py_ssize_t n;
    Py_ssize_t i;
    PyObject *(*iternext)(PyObject *);
    if (Py_IS_TYPE(((PyObject*)(((iterable)))), (&PyList_Type)) || Py_IS_TYPE(((PyObject*)(((iterable)))), (&PyTuple_Type)) ||
                (PyObject *)self == iterable) {
        PyObject **src, **dest;
        iterable = PySequence_Fast(iterable, "argument must be iterable");
        if (!iterable)
            return ((void *)0);
        n = (PyType_HasFeature((Py_TYPE(((PyObject*)((iterable))))), ((1UL << 25))) ? PyList_GET_SIZE(((PyObject*)((iterable)))) : PyTuple_GET_SIZE(((PyObject*)((iterable)))));
        if (n == 0) {
            Py_DECREF(((PyObject*)((iterable))));
            return (&_Py_NoneStruct);
        }
        m = Py_SIZE(((PyObject*)((self))));
        ((void) sizeof ((m < 0x7fffffffffffffffL - n) ? 1 : 0), __extension__ ({ if (m < 0x7fffffffffffffffL - n) ; else __assert_fail ("m < PY_SSIZE_T_MAX - n", "/home/bag/repos/cpython/Objects/listobject.c", 885, __extension__ __PRETTY_FUNCTION__); }));
        if (self->ob_item == ((void *)0)) {
            if (list_preallocate_exact(self, n) < 0) {
                return ((void *)0);
            }
            Py_SET_SIZE(((PyVarObject*)((self))), (n));
        }
        else if (list_resize(self, m + n) < 0) {
            Py_DECREF(((PyObject*)((iterable))));
            return ((void *)0);
        }
        src = (PyType_HasFeature((Py_TYPE(((PyObject*)((iterable))))), ((1UL << 25))) ? ((PyListObject *)(iterable))->ob_item : ((PyTupleObject *)(iterable))->ob_item);
        dest = self->ob_item + m;
        for (i = 0; i < n; i++) {
            PyObject *o = src[i];
            dest[i] = _Py_NewRef(((PyObject*)((o))));
        }
        Py_DECREF(((PyObject*)((iterable))));
        return (&_Py_NoneStruct);
    }
    it = PyObject_GetIter(iterable);
    if (it == ((void *)0))
        return ((void *)0);
    iternext = *Py_TYPE(((PyObject*)((it))))->tp_iternext;
    n = PyObject_LengthHint(iterable, 8);
    if (n < 0) {
        Py_DECREF(((PyObject*)((it))));
        return ((void *)0);
    }
    m = Py_SIZE(((PyObject*)((self))));
    if (m > 0x7fffffffffffffffL - n) {
    }
    else if (self->ob_item == ((void *)0)) {
        if (n && list_preallocate_exact(self, n) < 0)
            goto error;
    }
    else {
        if (list_resize(self, m + n) < 0)
            goto error;
        Py_SET_SIZE(((PyVarObject*)((self))), (m));
    }
    for (;;) {
        PyObject *item = iternext(it);
        if (item == ((void *)0)) {
            if (PyErr_Occurred()) {
                if (PyErr_ExceptionMatches(PyExc_StopIteration))
                    PyErr_Clear();
                else
                    goto error;
            }
            break;
        }
        if (Py_SIZE(((PyObject*)((self)))) < self->allocated) {
            PyList_SET_ITEM(((PyObject*)((self))), (Py_SIZE(((PyObject*)((self))))), ((PyObject*)((item))));
            Py_SET_SIZE(((PyVarObject*)((self))), (Py_SIZE(((PyObject*)((self)))) + 1));
        }
        else {
            if (_PyList_AppendTakeRef(self, item) < 0)
                goto error;
        }
    }
    if (Py_SIZE(((PyObject*)((self)))) < self->allocated) {
        if (list_resize(self, Py_SIZE(((PyObject*)((self))))) < 0)
            goto error;
    }
    Py_DECREF(((PyObject*)((it))));
    return (&_Py_NoneStruct);
  error:
    Py_DECREF(((PyObject*)((it))));
    return ((void *)0);
}
PyObject *
_PyList_Extend(PyListObject *self, PyObject *iterable)
{
    return list_extend(self, iterable);
}
static PyObject *
list_inplace_concat(PyListObject *self, PyObject *other)
{
    PyObject *result;
    result = list_extend(self, other);
    if (result == ((void *)0))
        return result;
    Py_DECREF(((PyObject*)((result))));
    return _Py_NewRef(((PyObject*)((self))));
}
static PyObject *
list_pop_impl(PyListObject *self, Py_ssize_t index)
{
    PyObject *v;
    int status;
    if (Py_SIZE(((PyObject*)((self)))) == 0) {
        PyErr_SetString(PyExc_IndexError, "pop from empty list");
        return ((void *)0);
    }
    if (index < 0)
        index += Py_SIZE(((PyObject*)((self))));
    if (!valid_index(index, Py_SIZE(((PyObject*)((self)))))) {
        PyErr_SetString(PyExc_IndexError, "pop index out of range");
        return ((void *)0);
    }
    PyObject **items = self->ob_item;
    v = items[index];
    const Py_ssize_t size_after_pop = Py_SIZE(((PyObject*)((self)))) - 1;
    if (size_after_pop == 0) {
        Py_INCREF(((PyObject*)((v))));
        status = _list_clear(self);
    }
    else {
        if ((size_after_pop - index) > 0) {
            memmove(&items[index], &items[index+1], (size_after_pop - index) * sizeof(PyObject *));
        }
        status = list_resize(self, size_after_pop);
    }
    if (status >= 0) {
        return v;
    }
    else {
        memmove(&items[index+1], &items[index], (size_after_pop - index)* sizeof(PyObject *));
        items[index] = v;
        return ((void *)0);
    }
}
static void
reverse_slice(PyObject **lo, PyObject **hi)
{
    ((void) sizeof ((lo && hi) ? 1 : 0), __extension__ ({ if (lo && hi) ; else __assert_fail ("lo && hi", "/home/bag/repos/cpython/Objects/listobject.c", 1055, __extension__ __PRETTY_FUNCTION__); }));
    --hi;
    while (lo < hi) {
        PyObject *t = *lo;
        *lo = *hi;
        *hi = t;
        ++lo;
        --hi;
    }
}
typedef struct {
    PyObject **keys;
    PyObject **values;
} sortslice;
static inline void
sortslice_copy(sortslice *s1, Py_ssize_t i, sortslice *s2, Py_ssize_t j)
{
    s1->keys[i] = s2->keys[j];
    if (s1->values != ((void *)0))
        s1->values[i] = s2->values[j];
}
static inline void
sortslice_copy_incr(sortslice *dst, sortslice *src)
{
    *dst->keys++ = *src->keys++;
    if (dst->values != ((void *)0))
        *dst->values++ = *src->values++;
}
static inline void
sortslice_copy_decr(sortslice *dst, sortslice *src)
{
    *dst->keys-- = *src->keys--;
    if (dst->values != ((void *)0))
        *dst->values-- = *src->values--;
}
static inline void
sortslice_memcpy(sortslice *s1, Py_ssize_t i, sortslice *s2, Py_ssize_t j,
                 Py_ssize_t n)
{
    memcpy(&s1->keys[i], &s2->keys[j], sizeof(PyObject *) * n);
    if (s1->values != ((void *)0))
        memcpy(&s1->values[i], &s2->values[j], sizeof(PyObject *) * n);
}
static inline void
sortslice_memmove(sortslice *s1, Py_ssize_t i, sortslice *s2, Py_ssize_t j,
                  Py_ssize_t n)
{
    memmove(&s1->keys[i], &s2->keys[j], sizeof(PyObject *) * n);
    if (s1->values != ((void *)0))
        memmove(&s1->values[i], &s2->values[j], sizeof(PyObject *) * n);
}
static inline void
sortslice_advance(sortslice *slice, Py_ssize_t n)
{
    slice->keys += n;
    if (slice->values != ((void *)0))
        slice->values += n;
}
struct s_slice {
    sortslice base;
    Py_ssize_t len;
    int power;
};
typedef struct s_MergeState MergeState;
struct s_MergeState {
    Py_ssize_t min_gallop;
    Py_ssize_t listlen;
    PyObject **basekeys;
    sortslice a;
    Py_ssize_t alloced;
    int n;
    struct s_slice pending[(8 * 8)];
    PyObject *temparray[256];
    int (*key_compare)(PyObject *, PyObject *, MergeState *);
    PyObject *(*key_richcompare)(PyObject *, PyObject *, int);
    int (*tuple_elem_compare)(PyObject *, PyObject *, MergeState *);
};
static int
binarysort(MergeState *ms, sortslice lo, PyObject **hi, PyObject **start)
{
    Py_ssize_t k;
    PyObject **l, **p, **r;
    PyObject *pivot;
    ((void) sizeof ((lo.keys <= start && start <= hi) ? 1 : 0), __extension__ ({ if (lo.keys <= start && start <= hi) ; else __assert_fail ("lo.keys <= start && start <= hi", "/home/bag/repos/cpython/Objects/listobject.c", 1240, __extension__ __PRETTY_FUNCTION__); }));
    if (lo.keys == start)
        ++start;
    for (; start < hi; ++start) {
        l = lo.keys;
        r = start;
        pivot = *r;
        ((void) sizeof ((l < r) ? 1 : 0), __extension__ ({ if (l < r) ; else __assert_fail ("l < r", "/home/bag/repos/cpython/Objects/listobject.c", 1254, __extension__ __PRETTY_FUNCTION__); }));
        do {
            p = l + ((r - l) >> 1);
            if ((k = (*(ms->key_compare))(pivot, *p, ms)) < 0) goto fail; if (k)
                r = p;
            else
                l = p+1;
        } while (l < r);
        ((void) sizeof ((l == r) ? 1 : 0), __extension__ ({ if (l == r) ; else __assert_fail ("l == r", "/home/bag/repos/cpython/Objects/listobject.c", 1262, __extension__ __PRETTY_FUNCTION__); }));
        for (p = start; p > l; --p)
            *p = *(p-1);
        *l = pivot;
        if (lo.values != ((void *)0)) {
            Py_ssize_t offset = lo.values - lo.keys;
            p = start + offset;
            pivot = *p;
            l += offset;
            for (p = start + offset; p > l; --p)
                *p = *(p-1);
            *l = pivot;
        }
    }
    return 0;
 fail:
    return -1;
}
static Py_ssize_t
count_run(MergeState *ms, PyObject **lo, PyObject **hi, int *descending)
{
    Py_ssize_t k;
    Py_ssize_t n;
    ((void) sizeof ((lo < hi) ? 1 : 0), __extension__ ({ if (lo < hi) ; else __assert_fail ("lo < hi", "/home/bag/repos/cpython/Objects/listobject.c", 1313, __extension__ __PRETTY_FUNCTION__); }));
    *descending = 0;
    ++lo;
    if (lo == hi)
        return 1;
    n = 2;
    if ((k = (*(ms->key_compare))(*lo, *(lo-1), ms)) < 0) goto fail; if (k) {
        *descending = 1;
        for (lo = lo+1; lo < hi; ++lo, ++n) {
            if ((k = (*(ms->key_compare))(*lo, *(lo-1), ms)) < 0) goto fail; if (k)
                ;
            else
                break;
        }
    }
    else {
        for (lo = lo+1; lo < hi; ++lo, ++n) {
            if ((k = (*(ms->key_compare))(*lo, *(lo-1), ms)) < 0) goto fail; if (k)
                break;
        }
    }
    return n;
fail:
    return -1;
}
static Py_ssize_t
gallop_left(MergeState *ms, PyObject *key, PyObject **a, Py_ssize_t n, Py_ssize_t hint)
{
    Py_ssize_t ofs;
    Py_ssize_t lastofs;
    Py_ssize_t k;
    ((void) sizeof ((key && a && n > 0 && hint >= 0 && hint < n) ? 1 : 0), __extension__ ({ if (key && a && n > 0 && hint >= 0 && hint < n) ; else __assert_fail ("key && a && n > 0 && hint >= 0 && hint < n", "/home/bag/repos/cpython/Objects/listobject.c", 1369, __extension__ __PRETTY_FUNCTION__); }));
    a += hint;
    lastofs = 0;
    ofs = 1;
    if ((k = (*(ms->key_compare))(*a, key, ms)) < 0) goto fail; if (k) {
        const Py_ssize_t maxofs = n - hint;
        while (ofs < maxofs) {
            if ((k = (*(ms->key_compare))(a[ofs], key, ms)) < 0) goto fail; if (k) {
                lastofs = ofs;
                ((void) sizeof ((ofs <= (0x7fffffffffffffffL - 1) / 2) ? 1 : 0), __extension__ ({ if (ofs <= (0x7fffffffffffffffL - 1) / 2) ; else __assert_fail ("ofs <= (PY_SSIZE_T_MAX - 1) / 2", "/home/bag/repos/cpython/Objects/listobject.c", 1382, __extension__ __PRETTY_FUNCTION__); }));
                ofs = (ofs << 1) + 1;
            }
            else
                break;
        }
        if (ofs > maxofs)
            ofs = maxofs;
        lastofs += hint;
        ofs += hint;
    }
    else {
        const Py_ssize_t maxofs = hint + 1;
        while (ofs < maxofs) {
            if ((k = (*(ms->key_compare))(*(a-ofs), key, ms)) < 0) goto fail; if (k)
                break;
            lastofs = ofs;
            ((void) sizeof ((ofs <= (0x7fffffffffffffffL - 1) / 2) ? 1 : 0), __extension__ ({ if (ofs <= (0x7fffffffffffffffL - 1) / 2) ; else __assert_fail ("ofs <= (PY_SSIZE_T_MAX - 1) / 2", "/home/bag/repos/cpython/Objects/listobject.c", 1404, __extension__ __PRETTY_FUNCTION__); }));
            ofs = (ofs << 1) + 1;
        }
        if (ofs > maxofs)
            ofs = maxofs;
        k = lastofs;
        lastofs = hint - ofs;
        ofs = hint - k;
    }
    a -= hint;
    ((void) sizeof ((-1 <= lastofs && lastofs < ofs && ofs <= n) ? 1 : 0), __extension__ ({ if (-1 <= lastofs && lastofs < ofs && ofs <= n) ; else __assert_fail ("-1 <= lastofs && lastofs < ofs && ofs <= n", "/home/bag/repos/cpython/Objects/listobject.c", 1416, __extension__ __PRETTY_FUNCTION__); }));
    ++lastofs;
    while (lastofs < ofs) {
        Py_ssize_t m = lastofs + ((ofs - lastofs) >> 1);
        if ((k = (*(ms->key_compare))(a[m], key, ms)) < 0) goto fail; if (k)
            lastofs = m+1;
        else
            ofs = m;
    }
    ((void) sizeof ((lastofs == ofs) ? 1 : 0), __extension__ ({ if (lastofs == ofs) ; else __assert_fail ("lastofs == ofs", "/home/bag/repos/cpython/Objects/listobject.c", 1430, __extension__ __PRETTY_FUNCTION__); }));
    return ofs;
fail:
    return -1;
}
static Py_ssize_t
gallop_right(MergeState *ms, PyObject *key, PyObject **a, Py_ssize_t n, Py_ssize_t hint)
{
    Py_ssize_t ofs;
    Py_ssize_t lastofs;
    Py_ssize_t k;
    ((void) sizeof ((key && a && n > 0 && hint >= 0 && hint < n) ? 1 : 0), __extension__ ({ if (key && a && n > 0 && hint >= 0 && hint < n) ; else __assert_fail ("key && a && n > 0 && hint >= 0 && hint < n", "/home/bag/repos/cpython/Objects/listobject.c", 1458, __extension__ __PRETTY_FUNCTION__); }));
    a += hint;
    lastofs = 0;
    ofs = 1;
    if ((k = (*(ms->key_compare))(key, *a, ms)) < 0) goto fail; if (k) {
        const Py_ssize_t maxofs = hint + 1;
        while (ofs < maxofs) {
            if ((k = (*(ms->key_compare))(key, *(a-ofs), ms)) < 0) goto fail; if (k) {
                lastofs = ofs;
                ((void) sizeof ((ofs <= (0x7fffffffffffffffL - 1) / 2) ? 1 : 0), __extension__ ({ if (ofs <= (0x7fffffffffffffffL - 1) / 2) ; else __assert_fail ("ofs <= (PY_SSIZE_T_MAX - 1) / 2", "/home/bag/repos/cpython/Objects/listobject.c", 1471, __extension__ __PRETTY_FUNCTION__); }));
                ofs = (ofs << 1) + 1;
            }
            else
                break;
        }
        if (ofs > maxofs)
            ofs = maxofs;
        k = lastofs;
        lastofs = hint - ofs;
        ofs = hint - k;
    }
    else {
        const Py_ssize_t maxofs = n - hint;
        while (ofs < maxofs) {
            if ((k = (*(ms->key_compare))(key, a[ofs], ms)) < 0) goto fail; if (k)
                break;
            lastofs = ofs;
            ((void) sizeof ((ofs <= (0x7fffffffffffffffL - 1) / 2) ? 1 : 0), __extension__ ({ if (ofs <= (0x7fffffffffffffffL - 1) / 2) ; else __assert_fail ("ofs <= (PY_SSIZE_T_MAX - 1) / 2", "/home/bag/repos/cpython/Objects/listobject.c", 1494, __extension__ __PRETTY_FUNCTION__); }));
            ofs = (ofs << 1) + 1;
        }
        if (ofs > maxofs)
            ofs = maxofs;
        lastofs += hint;
        ofs += hint;
    }
    a -= hint;
    ((void) sizeof ((-1 <= lastofs && lastofs < ofs && ofs <= n) ? 1 : 0), __extension__ ({ if (-1 <= lastofs && lastofs < ofs && ofs <= n) ; else __assert_fail ("-1 <= lastofs && lastofs < ofs && ofs <= n", "/home/bag/repos/cpython/Objects/listobject.c", 1505, __extension__ __PRETTY_FUNCTION__); }));
    ++lastofs;
    while (lastofs < ofs) {
        Py_ssize_t m = lastofs + ((ofs - lastofs) >> 1);
        if ((k = (*(ms->key_compare))(key, a[m], ms)) < 0) goto fail; if (k)
            ofs = m;
        else
            lastofs = m+1;
    }
    ((void) sizeof ((lastofs == ofs) ? 1 : 0), __extension__ ({ if (lastofs == ofs) ; else __assert_fail ("lastofs == ofs", "/home/bag/repos/cpython/Objects/listobject.c", 1519, __extension__ __PRETTY_FUNCTION__); }));
    return ofs;
fail:
    return -1;
}
static void
merge_init(MergeState *ms, Py_ssize_t list_size, int has_keyfunc,
           sortslice *lo)
{
    ((void) sizeof ((ms != ((void *)0)) ? 1 : 0), __extension__ ({ if (ms != ((void *)0)) ; else __assert_fail ("ms != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 1531, __extension__ __PRETTY_FUNCTION__); }));
    if (has_keyfunc) {
        ms->alloced = (list_size + 1) / 2;
        if (256 / 2 < ms->alloced)
            ms->alloced = 256 / 2;
        ms->a.values = &ms->temparray[ms->alloced];
    }
    else {
        ms->alloced = 256;
        ms->a.values = ((void *)0);
    }
    ms->a.keys = ms->temparray;
    ms->n = 0;
    ms->min_gallop = 7;
    ms->listlen = list_size;
    ms->basekeys = lo->keys;
}
static void
merge_freemem(MergeState *ms)
{
    ((void) sizeof ((ms != ((void *)0)) ? 1 : 0), __extension__ ({ if (ms != ((void *)0)) ; else __assert_fail ("ms != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 1565, __extension__ __PRETTY_FUNCTION__); }));
    if (ms->a.keys != ms->temparray) {
        PyMem_Free(ms->a.keys);
        ms->a.keys = ((void *)0);
    }
}
static int
merge_getmem(MergeState *ms, Py_ssize_t need)
{
    int multiplier;
    ((void) sizeof ((ms != ((void *)0)) ? 1 : 0), __extension__ ({ if (ms != ((void *)0)) ; else __assert_fail ("ms != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 1580, __extension__ __PRETTY_FUNCTION__); }));
    if (need <= ms->alloced)
        return 0;
    multiplier = ms->a.values != ((void *)0) ? 2 : 1;
    merge_freemem(ms);
    if ((size_t)need > 0x7fffffffffffffffL / sizeof(PyObject *) / multiplier) {
        PyErr_NoMemory();
        return -1;
    }
    ms->a.keys = (PyObject **)PyMem_Malloc(multiplier * need
                                          * sizeof(PyObject *));
    if (ms->a.keys != ((void *)0)) {
        ms->alloced = need;
        if (ms->a.values != ((void *)0))
            ms->a.values = &ms->a.keys[need];
        return 0;
    }
    PyErr_NoMemory();
    return -1;
}
static Py_ssize_t
merge_lo(MergeState *ms, sortslice ssa, Py_ssize_t na,
         sortslice ssb, Py_ssize_t nb)
{
    Py_ssize_t k;
    sortslice dest;
    int result = -1;
    Py_ssize_t min_gallop;
    ((void) sizeof ((ms && ssa.keys && ssb.keys && na > 0 && nb > 0) ? 1 : 0), __extension__ ({ if (ms && ssa.keys && ssb.keys && na > 0 && nb > 0) ; else __assert_fail ("ms && ssa.keys && ssb.keys && na > 0 && nb > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1623, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ssa.keys + na == ssb.keys) ? 1 : 0), __extension__ ({ if (ssa.keys + na == ssb.keys) ; else __assert_fail ("ssa.keys + na == ssb.keys", "/home/bag/repos/cpython/Objects/listobject.c", 1624, __extension__ __PRETTY_FUNCTION__); }));
    if (((na) <= (ms)->alloced ? 0 : merge_getmem(ms, na)) < 0)
        return -1;
    sortslice_memcpy(&ms->a, 0, &ssa, 0, na);
    dest = ssa;
    ssa = ms->a;
    sortslice_copy_incr(&dest, &ssb);
    --nb;
    if (nb == 0)
        goto Succeed;
    if (na == 1)
        goto CopyB;
    min_gallop = ms->min_gallop;
    for (;;) {
        Py_ssize_t acount = 0;
        Py_ssize_t bcount = 0;
        for (;;) {
            ((void) sizeof ((na > 1 && nb > 0) ? 1 : 0), __extension__ ({ if (na > 1 && nb > 0) ; else __assert_fail ("na > 1 && nb > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1647, __extension__ __PRETTY_FUNCTION__); }));
            k = (*(ms->key_compare))(ssb.keys[0], ssa.keys[0], ms);
            if (k) {
                if (k < 0)
                    goto Fail;
                sortslice_copy_incr(&dest, &ssb);
                ++bcount;
                acount = 0;
                --nb;
                if (nb == 0)
                    goto Succeed;
                if (bcount >= min_gallop)
                    break;
            }
            else {
                sortslice_copy_incr(&dest, &ssa);
                ++acount;
                bcount = 0;
                --na;
                if (na == 1)
                    goto CopyB;
                if (acount >= min_gallop)
                    break;
            }
        }
        ++min_gallop;
        do {
            ((void) sizeof ((na > 1 && nb > 0) ? 1 : 0), __extension__ ({ if (na > 1 && nb > 0) ; else __assert_fail ("na > 1 && nb > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1680, __extension__ __PRETTY_FUNCTION__); }));
            min_gallop -= min_gallop > 1;
            ms->min_gallop = min_gallop;
            k = gallop_right(ms, ssb.keys[0], ssa.keys, na, 0);
            acount = k;
            if (k) {
                if (k < 0)
                    goto Fail;
                sortslice_memcpy(&dest, 0, &ssa, 0, k);
                sortslice_advance(&dest, k);
                sortslice_advance(&ssa, k);
                na -= k;
                if (na == 1)
                    goto CopyB;
                if (na == 0)
                    goto Succeed;
            }
            sortslice_copy_incr(&dest, &ssb);
            --nb;
            if (nb == 0)
                goto Succeed;
            k = gallop_left(ms, ssa.keys[0], ssb.keys, nb, 0);
            bcount = k;
            if (k) {
                if (k < 0)
                    goto Fail;
                sortslice_memmove(&dest, 0, &ssb, 0, k);
                sortslice_advance(&dest, k);
                sortslice_advance(&ssb, k);
                nb -= k;
                if (nb == 0)
                    goto Succeed;
            }
            sortslice_copy_incr(&dest, &ssa);
            --na;
            if (na == 1)
                goto CopyB;
        } while (acount >= 7 || bcount >= 7);
        ++min_gallop;
        ms->min_gallop = min_gallop;
    }
Succeed:
    result = 0;
Fail:
    if (na)
        sortslice_memcpy(&dest, 0, &ssa, 0, na);
    return result;
CopyB:
    ((void) sizeof ((na == 1 && nb > 0) ? 1 : 0), __extension__ ({ if (na == 1 && nb > 0) ; else __assert_fail ("na == 1 && nb > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1733, __extension__ __PRETTY_FUNCTION__); }));
    sortslice_memmove(&dest, 0, &ssb, 0, nb);
    sortslice_copy(&dest, nb, &ssa, 0);
    return 0;
}
static Py_ssize_t
merge_hi(MergeState *ms, sortslice ssa, Py_ssize_t na,
         sortslice ssb, Py_ssize_t nb)
{
    Py_ssize_t k;
    sortslice dest, basea, baseb;
    int result = -1;
    Py_ssize_t min_gallop;
    ((void) sizeof ((ms && ssa.keys && ssb.keys && na > 0 && nb > 0) ? 1 : 0), __extension__ ({ if (ms && ssa.keys && ssb.keys && na > 0 && nb > 0) ; else __assert_fail ("ms && ssa.keys && ssb.keys && na > 0 && nb > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1755, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ssa.keys + na == ssb.keys) ? 1 : 0), __extension__ ({ if (ssa.keys + na == ssb.keys) ; else __assert_fail ("ssa.keys + na == ssb.keys", "/home/bag/repos/cpython/Objects/listobject.c", 1756, __extension__ __PRETTY_FUNCTION__); }));
    if (((nb) <= (ms)->alloced ? 0 : merge_getmem(ms, nb)) < 0)
        return -1;
    dest = ssb;
    sortslice_advance(&dest, nb-1);
    sortslice_memcpy(&ms->a, 0, &ssb, 0, nb);
    basea = ssa;
    baseb = ms->a;
    ssb.keys = ms->a.keys + nb - 1;
    if (ssb.values != ((void *)0))
        ssb.values = ms->a.values + nb - 1;
    sortslice_advance(&ssa, na - 1);
    sortslice_copy_decr(&dest, &ssa);
    --na;
    if (na == 0)
        goto Succeed;
    if (nb == 1)
        goto CopyA;
    min_gallop = ms->min_gallop;
    for (;;) {
        Py_ssize_t acount = 0;
        Py_ssize_t bcount = 0;
        for (;;) {
            ((void) sizeof ((na > 0 && nb > 1) ? 1 : 0), __extension__ ({ if (na > 0 && nb > 1) ; else __assert_fail ("na > 0 && nb > 1", "/home/bag/repos/cpython/Objects/listobject.c", 1785, __extension__ __PRETTY_FUNCTION__); }));
            k = (*(ms->key_compare))(ssb.keys[0], ssa.keys[0], ms);
            if (k) {
                if (k < 0)
                    goto Fail;
                sortslice_copy_decr(&dest, &ssa);
                ++acount;
                bcount = 0;
                --na;
                if (na == 0)
                    goto Succeed;
                if (acount >= min_gallop)
                    break;
            }
            else {
                sortslice_copy_decr(&dest, &ssb);
                ++bcount;
                acount = 0;
                --nb;
                if (nb == 1)
                    goto CopyA;
                if (bcount >= min_gallop)
                    break;
            }
        }
        ++min_gallop;
        do {
            ((void) sizeof ((na > 0 && nb > 1) ? 1 : 0), __extension__ ({ if (na > 0 && nb > 1) ; else __assert_fail ("na > 0 && nb > 1", "/home/bag/repos/cpython/Objects/listobject.c", 1818, __extension__ __PRETTY_FUNCTION__); }));
            min_gallop -= min_gallop > 1;
            ms->min_gallop = min_gallop;
            k = gallop_right(ms, ssb.keys[0], basea.keys, na, na-1);
            if (k < 0)
                goto Fail;
            k = na - k;
            acount = k;
            if (k) {
                sortslice_advance(&dest, -k);
                sortslice_advance(&ssa, -k);
                sortslice_memmove(&dest, 1, &ssa, 1, k);
                na -= k;
                if (na == 0)
                    goto Succeed;
            }
            sortslice_copy_decr(&dest, &ssb);
            --nb;
            if (nb == 1)
                goto CopyA;
            k = gallop_left(ms, ssa.keys[0], baseb.keys, nb, nb-1);
            if (k < 0)
                goto Fail;
            k = nb - k;
            bcount = k;
            if (k) {
                sortslice_advance(&dest, -k);
                sortslice_advance(&ssb, -k);
                sortslice_memcpy(&dest, 1, &ssb, 1, k);
                nb -= k;
                if (nb == 1)
                    goto CopyA;
                if (nb == 0)
                    goto Succeed;
            }
            sortslice_copy_decr(&dest, &ssa);
            --na;
            if (na == 0)
                goto Succeed;
        } while (acount >= 7 || bcount >= 7);
        ++min_gallop;
        ms->min_gallop = min_gallop;
    }
Succeed:
    result = 0;
Fail:
    if (nb)
        sortslice_memcpy(&dest, -(nb-1), &baseb, 0, nb);
    return result;
CopyA:
    ((void) sizeof ((nb == 1 && na > 0) ? 1 : 0), __extension__ ({ if (nb == 1 && na > 0) ; else __assert_fail ("nb == 1 && na > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1873, __extension__ __PRETTY_FUNCTION__); }));
    sortslice_memmove(&dest, 1-na, &ssa, 1-na, na);
    sortslice_advance(&dest, -na);
    sortslice_advance(&ssa, -na);
    sortslice_copy(&dest, 0, &ssb, 0);
    return 0;
}
static Py_ssize_t
merge_at(MergeState *ms, Py_ssize_t i)
{
    sortslice ssa, ssb;
    Py_ssize_t na, nb;
    Py_ssize_t k;
    ((void) sizeof ((ms != ((void *)0)) ? 1 : 0), __extension__ ({ if (ms != ((void *)0)) ; else __assert_fail ("ms != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 1892, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ms->n >= 2) ? 1 : 0), __extension__ ({ if (ms->n >= 2) ; else __assert_fail ("ms->n >= 2", "/home/bag/repos/cpython/Objects/listobject.c", 1893, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((i >= 0) ? 1 : 0), __extension__ ({ if (i >= 0) ; else __assert_fail ("i >= 0", "/home/bag/repos/cpython/Objects/listobject.c", 1894, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((i == ms->n - 2 || i == ms->n - 3) ? 1 : 0), __extension__ ({ if (i == ms->n - 2 || i == ms->n - 3) ; else __assert_fail ("i == ms->n - 2 || i == ms->n - 3", "/home/bag/repos/cpython/Objects/listobject.c", 1895, __extension__ __PRETTY_FUNCTION__); }));
    ssa = ms->pending[i].base;
    na = ms->pending[i].len;
    ssb = ms->pending[i+1].base;
    nb = ms->pending[i+1].len;
    ((void) sizeof ((na > 0 && nb > 0) ? 1 : 0), __extension__ ({ if (na > 0 && nb > 0) ; else __assert_fail ("na > 0 && nb > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1901, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ssa.keys + na == ssb.keys) ? 1 : 0), __extension__ ({ if (ssa.keys + na == ssb.keys) ; else __assert_fail ("ssa.keys + na == ssb.keys", "/home/bag/repos/cpython/Objects/listobject.c", 1902, __extension__ __PRETTY_FUNCTION__); }));
    ms->pending[i].len = na + nb;
    if (i == ms->n - 3)
        ms->pending[i+1] = ms->pending[i+2];
    --ms->n;
    k = gallop_right(ms, *ssb.keys, ssa.keys, na, 0);
    if (k < 0)
        return -1;
    sortslice_advance(&ssa, k);
    na -= k;
    if (na == 0)
        return 0;
    nb = gallop_left(ms, ssa.keys[na-1], ssb.keys, nb, nb-1);
    if (nb <= 0)
        return nb;
    if (na <= nb)
        return merge_lo(ms, ssa, na, ssb, nb);
    else
        return merge_hi(ms, ssa, na, ssb, nb);
}
static int
powerloop(Py_ssize_t s1, Py_ssize_t n1, Py_ssize_t n2, Py_ssize_t n)
{
    int result = 0;
    ((void) sizeof ((s1 >= 0) ? 1 : 0), __extension__ ({ if (s1 >= 0) ; else __assert_fail ("s1 >= 0", "/home/bag/repos/cpython/Objects/listobject.c", 1949, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((n1 > 0 && n2 > 0) ? 1 : 0), __extension__ ({ if (n1 > 0 && n2 > 0) ; else __assert_fail ("n1 > 0 && n2 > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1950, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((s1 + n1 + n2 <= n) ? 1 : 0), __extension__ ({ if (s1 + n1 + n2 <= n) ; else __assert_fail ("s1 + n1 + n2 <= n", "/home/bag/repos/cpython/Objects/listobject.c", 1951, __extension__ __PRETTY_FUNCTION__); }));
    Py_ssize_t a = 2 * s1 + n1;
    Py_ssize_t b = a + n1 + n2;
    for (;;) {
        ++result;
        if (a >= n) {
            ((void) sizeof ((b >= a) ? 1 : 0), __extension__ ({ if (b >= a) ; else __assert_fail ("b >= a", "/home/bag/repos/cpython/Objects/listobject.c", 1967, __extension__ __PRETTY_FUNCTION__); }));
            a -= n;
            b -= n;
        }
        else if (b >= n) {
            break;
        }
        ((void) sizeof ((a < b && b < n) ? 1 : 0), __extension__ ({ if (a < b && b < n) ; else __assert_fail ("a < b && b < n", "/home/bag/repos/cpython/Objects/listobject.c", 1974, __extension__ __PRETTY_FUNCTION__); }));
        a <<= 1;
        b <<= 1;
    }
    return result;
}
static int
found_new_run(MergeState *ms, Py_ssize_t n2)
{
    ((void) sizeof ((ms) ? 1 : 0), __extension__ ({ if (ms) ; else __assert_fail ("ms", "/home/bag/repos/cpython/Objects/listobject.c", 1995, __extension__ __PRETTY_FUNCTION__); }));
    if (ms->n) {
        ((void) sizeof ((ms->n > 0) ? 1 : 0), __extension__ ({ if (ms->n > 0) ; else __assert_fail ("ms->n > 0", "/home/bag/repos/cpython/Objects/listobject.c", 1997, __extension__ __PRETTY_FUNCTION__); }));
        struct s_slice *p = ms->pending;
        Py_ssize_t s1 = p[ms->n - 1].base.keys - ms->basekeys;
        Py_ssize_t n1 = p[ms->n - 1].len;
        int power = powerloop(s1, n1, n2, ms->listlen);
        while (ms->n > 1 && p[ms->n - 2].power > power) {
            if (merge_at(ms, ms->n - 2) < 0)
                return -1;
        }
        ((void) sizeof ((ms->n < 2 || p[ms->n - 2].power < power) ? 1 : 0), __extension__ ({ if (ms->n < 2 || p[ms->n - 2].power < power) ; else __assert_fail ("ms->n < 2 || p[ms->n - 2].power < power", "/home/bag/repos/cpython/Objects/listobject.c", 2006, __extension__ __PRETTY_FUNCTION__); }));
        p[ms->n - 1].power = power;
    }
    return 0;
}
static int
merge_force_collapse(MergeState *ms)
{
    struct s_slice *p = ms->pending;
    ((void) sizeof ((ms) ? 1 : 0), __extension__ ({ if (ms) ; else __assert_fail ("ms", "/home/bag/repos/cpython/Objects/listobject.c", 2022, __extension__ __PRETTY_FUNCTION__); }));
    while (ms->n > 1) {
        Py_ssize_t n = ms->n - 2;
        if (n > 0 && p[n-1].len < p[n+1].len)
            --n;
        if (merge_at(ms, n) < 0)
            return -1;
    }
    return 0;
}
static Py_ssize_t
merge_compute_minrun(Py_ssize_t n)
{
    Py_ssize_t r = 0;
    ((void) sizeof ((n >= 0) ? 1 : 0), __extension__ ({ if (n >= 0) ; else __assert_fail ("n >= 0", "/home/bag/repos/cpython/Objects/listobject.c", 2048, __extension__ __PRETTY_FUNCTION__); }));
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}
static void
reverse_sortslice(sortslice *s, Py_ssize_t n)
{
    reverse_slice(s->keys, &s->keys[n]);
    if (s->values != ((void *)0))
        reverse_slice(s->values, &s->values[n]);
}
static int
safe_object_compare(PyObject *v, PyObject *w, MergeState *ms)
{
    return PyObject_RichCompareBool(v, w, 0);
}
static int
unsafe_object_compare(PyObject *v, PyObject *w, MergeState *ms)
{
    PyObject *res_obj; int res;
    if (Py_TYPE(((PyObject*)((v))))->tp_richcompare != ms->key_richcompare)
        return PyObject_RichCompareBool(v, w, 0);
    ((void) sizeof ((ms->key_richcompare != ((void *)0)) ? 1 : 0), __extension__ ({ if (ms->key_richcompare != ((void *)0)) ; else __assert_fail ("ms->key_richcompare != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 2094, __extension__ __PRETTY_FUNCTION__); }));
    res_obj = (*(ms->key_richcompare))(v, w, 0);
    if (res_obj == (&_Py_NotImplementedStruct)) {
        Py_DECREF(((PyObject*)((res_obj))));
        return PyObject_RichCompareBool(v, w, 0);
    }
    if (res_obj == ((void *)0))
        return -1;
    if (Py_IS_TYPE(((PyObject*)(((res_obj)))), (&PyBool_Type))) {
        res = (res_obj == ((PyObject*)((&_Py_TrueStruct))));
    }
    else {
        res = PyObject_IsTrue(res_obj);
    }
    Py_DECREF(((PyObject*)((res_obj))));
    return res;
}
static int
unsafe_latin_compare(PyObject *v, PyObject *w, MergeState *ms)
{
    Py_ssize_t len;
    int res;
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((v))), (&PyUnicode_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((v))), (&PyUnicode_Type))) ; else __assert_fail ("Py_IS_TYPE(v, &PyUnicode_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2128, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((w))), (&PyUnicode_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((w))), (&PyUnicode_Type))) ; else __assert_fail ("Py_IS_TYPE(w, &PyUnicode_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2129, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(v)", "/home/bag/repos/cpython/Objects/listobject.c", 2130, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((v))))->state.kind)) == ((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((w))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((w))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(w)", "/home/bag/repos/cpython/Objects/listobject.c", 2130, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((w))))->state.kind))) ? 1 : 0), __extension__ ({ if (((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(v)", "/home/bag/repos/cpython/Objects/listobject.c", 2130, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((v))))->state.kind)) == ((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((w))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((w))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(w)", "/home/bag/repos/cpython/Objects/listobject.c", 2130, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((w))))->state.kind))) ; else __assert_fail ("PyUnicode_KIND(v) == PyUnicode_KIND(w)", "/home/bag/repos/cpython/Objects/listobject.c", 2130, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(v)", "/home/bag/repos/cpython/Objects/listobject.c", 2131, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((v))))->state.kind)) == PyUnicode_1BYTE_KIND) ? 1 : 0), __extension__ ({ if (((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(v)", "/home/bag/repos/cpython/Objects/listobject.c", 2131, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((v))))->state.kind)) == PyUnicode_1BYTE_KIND) ; else __assert_fail ("PyUnicode_KIND(v) == PyUnicode_1BYTE_KIND", "/home/bag/repos/cpython/Objects/listobject.c", 2131, __extension__ __PRETTY_FUNCTION__); }));
    len = (((PyUnicode_GET_LENGTH(((PyObject*)((v))))) > (PyUnicode_GET_LENGTH(((PyObject*)((w)))))) ? (PyUnicode_GET_LENGTH(((PyObject*)((w))))) : (PyUnicode_GET_LENGTH(((PyObject*)((v))))));
    res = memcmp(PyUnicode_DATA(((PyObject*)((v)))), PyUnicode_DATA(((PyObject*)((w)))), len);
    res = (res != 0 ?
           res < 0 :
           PyUnicode_GET_LENGTH(((PyObject*)((v)))) < PyUnicode_GET_LENGTH(((PyObject*)((w)))));
    ((void) sizeof ((res == PyObject_RichCompareBool(v, w, 0)) ? 1 : 0), __extension__ ({ if (res == PyObject_RichCompareBool(v, w, 0)) ; else __assert_fail ("res == PyObject_RichCompareBool(v, w, Py_LT)", "/home/bag/repos/cpython/Objects/listobject.c", 2140, __extension__ __PRETTY_FUNCTION__); }));;
    return res;
}
static int
unsafe_long_compare(PyObject *v, PyObject *w, MergeState *ms)
{
    PyLongObject *vl, *wl;
    intptr_t v0, w0;
    int res;
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((v))), (&PyLong_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((v))), (&PyLong_Type))) ; else __assert_fail ("Py_IS_TYPE(v, &PyLong_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2153, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((w))), (&PyLong_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((w))), (&PyLong_Type))) ; else __assert_fail ("Py_IS_TYPE(w, &PyLong_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2154, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((_PyLong_IsCompact((PyLongObject *)v)) ? 1 : 0), __extension__ ({ if (_PyLong_IsCompact((PyLongObject *)v)) ; else __assert_fail ("_PyLong_IsCompact((PyLongObject *)v)", "/home/bag/repos/cpython/Objects/listobject.c", 2155, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((_PyLong_IsCompact((PyLongObject *)w)) ? 1 : 0), __extension__ ({ if (_PyLong_IsCompact((PyLongObject *)w)) ; else __assert_fail ("_PyLong_IsCompact((PyLongObject *)w)", "/home/bag/repos/cpython/Objects/listobject.c", 2156, __extension__ __PRETTY_FUNCTION__); }));
    vl = (PyLongObject*)v;
    wl = (PyLongObject*)w;
    v0 = _PyLong_CompactValue(vl);
    w0 = _PyLong_CompactValue(wl);
    res = v0 < w0;
    ((void) sizeof ((res == PyObject_RichCompareBool(v, w, 0)) ? 1 : 0), __extension__ ({ if (res == PyObject_RichCompareBool(v, w, 0)) ; else __assert_fail ("res == PyObject_RichCompareBool(v, w, Py_LT)", "/home/bag/repos/cpython/Objects/listobject.c", 2165, __extension__ __PRETTY_FUNCTION__); }));
    return res;
}
static int
unsafe_float_compare(PyObject *v, PyObject *w, MergeState *ms)
{
    int res;
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((v))), (&PyFloat_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((v))), (&PyFloat_Type))) ; else __assert_fail ("Py_IS_TYPE(v, &PyFloat_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2176, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((w))), (&PyFloat_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((w))), (&PyFloat_Type))) ; else __assert_fail ("Py_IS_TYPE(w, &PyFloat_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2177, __extension__ __PRETTY_FUNCTION__); }));
    res = PyFloat_AS_DOUBLE(((PyObject*)((v)))) < PyFloat_AS_DOUBLE(((PyObject*)((w))));
    ((void) sizeof ((res == PyObject_RichCompareBool(v, w, 0)) ? 1 : 0), __extension__ ({ if (res == PyObject_RichCompareBool(v, w, 0)) ; else __assert_fail ("res == PyObject_RichCompareBool(v, w, Py_LT)", "/home/bag/repos/cpython/Objects/listobject.c", 2180, __extension__ __PRETTY_FUNCTION__); }));
    return res;
}
static int
unsafe_tuple_compare(PyObject *v, PyObject *w, MergeState *ms)
{
    PyTupleObject *vt, *wt;
    Py_ssize_t i, vlen, wlen;
    int k;
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((v))), (&PyTuple_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((v))), (&PyTuple_Type))) ; else __assert_fail ("Py_IS_TYPE(v, &PyTuple_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2198, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_IS_TYPE(((PyObject*)((w))), (&PyTuple_Type))) ? 1 : 0), __extension__ ({ if (Py_IS_TYPE(((PyObject*)((w))), (&PyTuple_Type))) ; else __assert_fail ("Py_IS_TYPE(w, &PyTuple_Type)", "/home/bag/repos/cpython/Objects/listobject.c", 2199, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_SIZE(((PyObject*)((v)))) > 0) ? 1 : 0), __extension__ ({ if (Py_SIZE(((PyObject*)((v)))) > 0) ; else __assert_fail ("Py_SIZE(v) > 0", "/home/bag/repos/cpython/Objects/listobject.c", 2200, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_SIZE(((PyObject*)((w)))) > 0) ? 1 : 0), __extension__ ({ if (Py_SIZE(((PyObject*)((w)))) > 0) ; else __assert_fail ("Py_SIZE(w) > 0", "/home/bag/repos/cpython/Objects/listobject.c", 2201, __extension__ __PRETTY_FUNCTION__); }));
    vt = (PyTupleObject *)v;
    wt = (PyTupleObject *)w;
    vlen = Py_SIZE(((PyObject*)((vt))));
    wlen = Py_SIZE(((PyObject*)((wt))));
    for (i = 0; i < vlen && i < wlen; i++) {
        k = PyObject_RichCompareBool(vt->ob_item[i], wt->ob_item[i], 2);
        if (k < 0)
            return -1;
        if (!k)
            break;
    }
    if (i >= vlen || i >= wlen)
        return vlen < wlen;
    if (i == 0)
        return ms->tuple_elem_compare(vt->ob_item[i], wt->ob_item[i], ms);
    else
        return PyObject_RichCompareBool(vt->ob_item[i], wt->ob_item[i], 0);
}
static PyObject *
list_sort_impl(PyListObject *self, PyObject *keyfunc, int reverse)
{
    MergeState ms;
    Py_ssize_t nremaining;
    Py_ssize_t minrun;
    sortslice lo;
    Py_ssize_t saved_ob_size, saved_allocated;
    PyObject **saved_ob_item;
    PyObject **final_ob_item;
    PyObject *result = ((void *)0);
    Py_ssize_t i;
    PyObject **keys;
    ((void) sizeof ((self != ((void *)0)) ? 1 : 0), __extension__ ({ if (self != ((void *)0)) ; else __assert_fail ("self != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 2264, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(self)", "/home/bag/repos/cpython/Objects/listobject.c", 2265, __extension__ __PRETTY_FUNCTION__); }));
    if (keyfunc == (&_Py_NoneStruct))
        keyfunc = ((void *)0);
    saved_ob_size = Py_SIZE(((PyObject*)((self))));
    saved_ob_item = self->ob_item;
    saved_allocated = self->allocated;
    Py_SET_SIZE(((PyVarObject*)((self))), (0));
    self->ob_item = ((void *)0);
    self->allocated = -1;
    if (keyfunc == ((void *)0)) {
        keys = ((void *)0);
        lo.keys = saved_ob_item;
        lo.values = ((void *)0);
    }
    else {
        if (saved_ob_size < 256/2)
            keys = &ms.temparray[saved_ob_size+1];
        else {
            keys = PyMem_Malloc(sizeof(PyObject *) * saved_ob_size);
            if (keys == ((void *)0)) {
                PyErr_NoMemory();
                goto keyfunc_fail;
            }
        }
        for (i = 0; i < saved_ob_size ; i++) {
            keys[i] = PyObject_CallOneArg(keyfunc, saved_ob_item[i]);
            if (keys[i] == ((void *)0)) {
                for (i=i-1 ; i>=0 ; i--)
                    Py_DECREF(((PyObject*)((keys[i]))));
                if (saved_ob_size >= 256/2)
                    PyMem_Free(keys);
                goto keyfunc_fail;
            }
        }
        lo.keys = keys;
        lo.values = saved_ob_item;
    }
    if (saved_ob_size > 1) {
        int keys_are_in_tuples = (Py_IS_TYPE(((PyObject*)((lo.keys[0]))), (&PyTuple_Type)) &&
                                  Py_SIZE(((PyObject*)((lo.keys[0])))) > 0);
        PyTypeObject* key_type = (keys_are_in_tuples ?
                                  Py_TYPE(((PyObject*)((((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((lo.keys[0]))))), ((1UL << 26)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((lo.keys[0]))))), ((1UL << 26)))) ; else __assert_fail ("PyTuple_Check(lo.keys[0])", "/home/bag/repos/cpython/Objects/listobject.c", 2324, __extension__ __PRETTY_FUNCTION__); })), ((PyTupleObject*)((lo.keys[0]))))->ob_item[(0)]))))) :
                                  Py_TYPE(((PyObject*)((lo.keys[0])))));
        int keys_are_all_same_type = 1;
        int strings_are_latin = 1;
        int ints_are_bounded = 1;
        for (i=0; i < saved_ob_size; i++) {
            if (keys_are_in_tuples &&
                !(Py_IS_TYPE(((PyObject*)((lo.keys[i]))), (&PyTuple_Type)) && Py_SIZE(((PyObject*)((lo.keys[i])))) != 0)) {
                keys_are_in_tuples = 0;
                keys_are_all_same_type = 0;
                break;
            }
            PyObject *key = (keys_are_in_tuples ?
                             ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((lo.keys[i]))))), ((1UL << 26)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((lo.keys[i]))))), ((1UL << 26)))) ; else __assert_fail ("PyTuple_Check(lo.keys[i])", "/home/bag/repos/cpython/Objects/listobject.c", 2345, __extension__ __PRETTY_FUNCTION__); })), ((PyTupleObject*)((lo.keys[i]))))->ob_item[(0)]) :
                             lo.keys[i]);
            if (!Py_IS_TYPE(((PyObject*)((key))), (key_type))) {
                keys_are_all_same_type = 0;
                if (!keys_are_in_tuples) {
                    break;
                }
            }
            if (keys_are_all_same_type) {
                if (key_type == &PyLong_Type &&
                    ints_are_bounded &&
                    !_PyLong_IsCompact((PyLongObject *)key)) {
                    ints_are_bounded = 0;
                }
                else if (key_type == &PyUnicode_Type &&
                         strings_are_latin &&
                         ((void)0, ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((key))))), ((1UL << 28)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((key))))), ((1UL << 28)))) ; else __assert_fail ("PyUnicode_Check(key)", "/home/bag/repos/cpython/Objects/listobject.c", 2366, __extension__ __PRETTY_FUNCTION__); })), ((PyASCIIObject*)((key))))->state.kind)) != PyUnicode_1BYTE_KIND) {
                        strings_are_latin = 0;
                    }
                }
            }
        if (keys_are_all_same_type) {
            if (key_type == &PyUnicode_Type && strings_are_latin) {
                ms.key_compare = unsafe_latin_compare;
            }
            else if (key_type == &PyLong_Type && ints_are_bounded) {
                ms.key_compare = unsafe_long_compare;
            }
            else if (key_type == &PyFloat_Type) {
                ms.key_compare = unsafe_float_compare;
            }
            else if ((ms.key_richcompare = key_type->tp_richcompare) != ((void *)0)) {
                ms.key_compare = unsafe_object_compare;
            }
            else {
                ms.key_compare = safe_object_compare;
            }
        }
        else {
            ms.key_compare = safe_object_compare;
        }
        if (keys_are_in_tuples) {
            if (key_type == &PyTuple_Type) {
                ms.tuple_elem_compare = safe_object_compare;
            }
            else {
                ms.tuple_elem_compare = ms.key_compare;
            }
            ms.key_compare = unsafe_tuple_compare;
        }
    }
    merge_init(&ms, saved_ob_size, keys != ((void *)0), &lo);
    nremaining = saved_ob_size;
    if (nremaining < 2)
        goto succeed;
    if (reverse) {
        if (keys != ((void *)0))
            reverse_slice(&keys[0], &keys[saved_ob_size]);
        reverse_slice(&saved_ob_item[0], &saved_ob_item[saved_ob_size]);
    }
    minrun = merge_compute_minrun(nremaining);
    do {
        int descending;
        Py_ssize_t n;
        n = count_run(&ms, lo.keys, lo.keys + nremaining, &descending);
        if (n < 0)
            goto fail;
        if (descending)
            reverse_sortslice(&lo, n);
        if (n < minrun) {
            const Py_ssize_t force = nremaining <= minrun ?
                              nremaining : minrun;
            if (binarysort(&ms, lo, lo.keys + force, lo.keys + n) < 0)
                goto fail;
            n = force;
        }
        ((void) sizeof ((ms.n == 0 || ms.pending[ms.n -1].base.keys + ms.pending[ms.n-1].len == lo.keys) ? 1 : 0), __extension__ ({ if (ms.n == 0 || ms.pending[ms.n -1].base.keys + ms.pending[ms.n-1].len == lo.keys) ; else __assert_fail ("ms.n == 0 || ms.pending[ms.n -1].base.keys + ms.pending[ms.n-1].len == lo.keys", "/home/bag/repos/cpython/Objects/listobject.c", 2448, __extension__ __PRETTY_FUNCTION__); }));
        if (found_new_run(&ms, n) < 0)
            goto fail;
        ((void) sizeof ((ms.n < (8 * 8)) ? 1 : 0), __extension__ ({ if (ms.n < (8 * 8)) ; else __assert_fail ("ms.n < MAX_MERGE_PENDING", "/home/bag/repos/cpython/Objects/listobject.c", 2453, __extension__ __PRETTY_FUNCTION__); }));
        ms.pending[ms.n].base = lo;
        ms.pending[ms.n].len = n;
        ++ms.n;
        sortslice_advance(&lo, n);
        nremaining -= n;
    } while (nremaining);
    if (merge_force_collapse(&ms) < 0)
        goto fail;
    ((void) sizeof ((ms.n == 1) ? 1 : 0), __extension__ ({ if (ms.n == 1) ; else __assert_fail ("ms.n == 1", "/home/bag/repos/cpython/Objects/listobject.c", 2464, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((keys == ((void *)0) ? ms.pending[0].base.keys == saved_ob_item : ms.pending[0].base.keys == &keys[0]) ? 1 : 0), __extension__ ({ if (keys == ((void *)0) ? ms.pending[0].base.keys == saved_ob_item : ms.pending[0].base.keys == &keys[0]) ; else __assert_fail ("keys == NULL ? ms.pending[0].base.keys == saved_ob_item : ms.pending[0].base.keys == &keys[0]", "/home/bag/repos/cpython/Objects/listobject.c", 2465, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((ms.pending[0].len == saved_ob_size) ? 1 : 0), __extension__ ({ if (ms.pending[0].len == saved_ob_size) ; else __assert_fail ("ms.pending[0].len == saved_ob_size", "/home/bag/repos/cpython/Objects/listobject.c", 2468, __extension__ __PRETTY_FUNCTION__); }));
    lo = ms.pending[0].base;
succeed:
    result = (&_Py_NoneStruct);
fail:
    if (keys != ((void *)0)) {
        for (i = 0; i < saved_ob_size; i++)
            Py_DECREF(((PyObject*)((keys[i]))));
        if (saved_ob_size >= 256/2)
            PyMem_Free(keys);
    }
    if (self->allocated != -1 && result != ((void *)0)) {
        PyErr_SetString(PyExc_ValueError, "list modified during sort");
        result = ((void *)0);
    }
    if (reverse && saved_ob_size > 1)
        reverse_slice(saved_ob_item, saved_ob_item + saved_ob_size);
    merge_freemem(&ms);
keyfunc_fail:
    final_ob_item = self->ob_item;
    i = Py_SIZE(((PyObject*)((self))));
    Py_SET_SIZE(((PyVarObject*)((self))), (saved_ob_size));
    self->ob_item = saved_ob_item;
    self->allocated = saved_allocated;
    if (final_ob_item != ((void *)0)) {
        while (--i >= 0) {
            Py_XDECREF(((PyObject*)((final_ob_item[i]))));
        }
        PyMem_Free(final_ob_item);
    }
    return _Py_XNewRef(((PyObject*)((result))));
}
int
PyList_Sort(PyObject *v)
{
    if (v == ((void *)0) || !PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 2517);
        return -1;
    }
    v = list_sort_impl((PyListObject *)v, ((void *)0), 0);
    if (v == ((void *)0))
        return -1;
    Py_DECREF(((PyObject*)((v))));
    return 0;
}
static PyObject *
list_reverse_impl(PyListObject *self)
{
    if (Py_SIZE(((PyObject*)((self)))) > 1)
        reverse_slice(self->ob_item, self->ob_item + Py_SIZE(((PyObject*)((self)))));
    return (&_Py_NoneStruct);
}
int
PyList_Reverse(PyObject *v)
{
    PyListObject *self = (PyListObject *)v;
    if (v == ((void *)0) || !PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 2548);
        return -1;
    }
    if (Py_SIZE(((PyObject*)((self)))) > 1)
        reverse_slice(self->ob_item, self->ob_item + Py_SIZE(((PyObject*)((self)))));
    return 0;
}
PyObject *
PyList_AsTuple(PyObject *v)
{
    if (v == ((void *)0) || !PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 2560);
        return ((void *)0);
    }
    return _PyTuple_FromArray(((PyListObject *)v)->ob_item, Py_SIZE(((PyObject*)((v)))));
}
PyObject *
_PyList_FromArraySteal(PyObject *const *src, Py_ssize_t n)
{
    if (n == 0) {
        return PyList_New(0);
    }
    PyListObject *list = (PyListObject *)PyList_New(n);
    if (list == ((void *)0)) {
        for (Py_ssize_t i = 0; i < n; i++) {
            Py_DECREF(((PyObject*)((src[i]))));
        }
        return ((void *)0);
    }
    PyObject **dst = list->ob_item;
    memcpy(dst, src, n * sizeof(PyObject *));
    return (PyObject *)list;
}
static PyObject *
list_index_impl(PyListObject *self, PyObject *value, Py_ssize_t start,
                Py_ssize_t stop)
{
    Py_ssize_t i;
    if (start < 0) {
        start += Py_SIZE(((PyObject*)((self))));
        if (start < 0)
            start = 0;
    }
    if (stop < 0) {
        stop += Py_SIZE(((PyObject*)((self))));
        if (stop < 0)
            stop = 0;
    }
    for (i = start; i < stop && i < Py_SIZE(((PyObject*)((self)))); i++) {
        PyObject *obj = self->ob_item[i];
        Py_INCREF(((PyObject*)((obj))));
        int cmp = PyObject_RichCompareBool(obj, value, 2);
        Py_DECREF(((PyObject*)((obj))));
        if (cmp > 0)
            return PyLong_FromSsize_t(i);
        else if (cmp < 0)
            return ((void *)0);
    }
    PyErr_Format(PyExc_ValueError, "%R is not in list", value);
    return ((void *)0);
}
static PyObject *
list_count(PyListObject *self, PyObject *value)
{
    Py_ssize_t count = 0;
    Py_ssize_t i;
    for (i = 0; i < Py_SIZE(((PyObject*)((self)))); i++) {
        PyObject *obj = self->ob_item[i];
        if (obj == value) {
           count++;
           continue;
        }
        Py_INCREF(((PyObject*)((obj))));
        int cmp = PyObject_RichCompareBool(obj, value, 2);
        Py_DECREF(((PyObject*)((obj))));
        if (cmp > 0)
            count++;
        else if (cmp < 0)
            return ((void *)0);
    }
    return PyLong_FromSsize_t(count);
}
static PyObject *
list_remove(PyListObject *self, PyObject *value)
{
    Py_ssize_t i;
    for (i = 0; i < Py_SIZE(((PyObject*)((self)))); i++) {
        PyObject *obj = self->ob_item[i];
        Py_INCREF(((PyObject*)((obj))));
        int cmp = PyObject_RichCompareBool(obj, value, 2);
        Py_DECREF(((PyObject*)((obj))));
        if (cmp > 0) {
            if (list_ass_slice(self, i, i+1,
                               (PyObject *)((void *)0)) == 0)
                return (&_Py_NoneStruct);
            return ((void *)0);
        }
        else if (cmp < 0)
            return ((void *)0);
    }
    PyErr_SetString(PyExc_ValueError, "list.remove(x): x not in list");
    return ((void *)0);
}
static int
list_traverse(PyListObject *o, visitproc visit, void *arg)
{
    Py_ssize_t i;
    for (i = Py_SIZE(((PyObject*)((o)))); --i >= 0; )
        do { if (o->ob_item[i]) { int vret = visit(((PyObject*)((o->ob_item[i]))), arg); if (vret) return vret; } } while (0);
    return 0;
}
static PyObject *
list_richcompare(PyObject *v, PyObject *w, int op)
{
    PyListObject *vl, *wl;
    Py_ssize_t i;
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((v))))), ((1UL << 25))) || !PyType_HasFeature((Py_TYPE(((PyObject*)((w))))), ((1UL << 25))))
        return (&_Py_NotImplementedStruct);
    vl = (PyListObject *)v;
    wl = (PyListObject *)w;
    if (Py_SIZE(((PyObject*)((vl)))) != Py_SIZE(((PyObject*)((wl)))) && (op == 2 || op == 3)) {
        if (op == 2)
            return ((PyObject*)((&_Py_FalseStruct)));
        else
            return ((PyObject*)((&_Py_TrueStruct)));
    }
    for (i = 0; i < Py_SIZE(((PyObject*)((vl)))) && i < Py_SIZE(((PyObject*)((wl)))); i++) {
        PyObject *vitem = vl->ob_item[i];
        PyObject *witem = wl->ob_item[i];
        if (vitem == witem) {
            continue;
        }
        Py_INCREF(((PyObject*)((vitem))));
        Py_INCREF(((PyObject*)((witem))));
        int k = PyObject_RichCompareBool(vitem, witem, 2);
        Py_DECREF(((PyObject*)((vitem))));
        Py_DECREF(((PyObject*)((witem))));
        if (k < 0)
            return ((void *)0);
        if (!k)
            break;
    }
    if (i >= Py_SIZE(((PyObject*)((vl)))) || i >= Py_SIZE(((PyObject*)((wl))))) {
        do { switch (op) { case 2: if ((Py_SIZE(((PyObject*)((vl))))) == (Py_SIZE(((PyObject*)((wl)))))) return ((PyObject*)((&_Py_TrueStruct))); return ((PyObject*)((&_Py_FalseStruct))); case 3: if ((Py_SIZE(((PyObject*)((vl))))) != (Py_SIZE(((PyObject*)((wl)))))) return ((PyObject*)((&_Py_TrueStruct))); return ((PyObject*)((&_Py_FalseStruct))); case 0: if ((Py_SIZE(((PyObject*)((vl))))) < (Py_SIZE(((PyObject*)((wl)))))) return ((PyObject*)((&_Py_TrueStruct))); return ((PyObject*)((&_Py_FalseStruct))); case 4: if ((Py_SIZE(((PyObject*)((vl))))) > (Py_SIZE(((PyObject*)((wl)))))) return ((PyObject*)((&_Py_TrueStruct))); return ((PyObject*)((&_Py_FalseStruct))); case 1: if ((Py_SIZE(((PyObject*)((vl))))) <= (Py_SIZE(((PyObject*)((wl)))))) return ((PyObject*)((&_Py_TrueStruct))); return ((PyObject*)((&_Py_FalseStruct))); case 5: if ((Py_SIZE(((PyObject*)((vl))))) >= (Py_SIZE(((PyObject*)((wl)))))) return ((PyObject*)((&_Py_TrueStruct))); return ((PyObject*)((&_Py_FalseStruct))); default: __builtin_unreachable(); } } while (0);
    }
    if (op == 2) {
        return ((PyObject*)((&_Py_FalseStruct)));
    }
    if (op == 3) {
        return ((PyObject*)((&_Py_TrueStruct)));
    }
    PyObject *vitem = vl->ob_item[i];
    PyObject *witem = wl->ob_item[i];
    Py_INCREF(((PyObject*)((vitem))));
    Py_INCREF(((PyObject*)((witem))));
    PyObject *result = PyObject_RichCompare(vl->ob_item[i], wl->ob_item[i], op);
    Py_DECREF(((PyObject*)((vitem))));
    Py_DECREF(((PyObject*)((witem))));
    return result;
}
static int
list___init___impl(PyListObject *self, PyObject *iterable)
{
    ((void) sizeof ((0 <= Py_SIZE(((PyObject*)((self))))) ? 1 : 0), __extension__ ({ if (0 <= Py_SIZE(((PyObject*)((self))))) ; else __assert_fail ("0 <= Py_SIZE(self)", "/home/bag/repos/cpython/Objects/listobject.c", 2789, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((Py_SIZE(((PyObject*)((self)))) <= self->allocated || self->allocated == -1) ? 1 : 0), __extension__ ({ if (Py_SIZE(((PyObject*)((self)))) <= self->allocated || self->allocated == -1) ; else __assert_fail ("Py_SIZE(self) <= self->allocated || self->allocated == -1", "/home/bag/repos/cpython/Objects/listobject.c", 2790, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((self->ob_item != ((void *)0) || self->allocated == 0 || self->allocated == -1) ? 1 : 0), __extension__ ({ if (self->ob_item != ((void *)0) || self->allocated == 0 || self->allocated == -1) ; else __assert_fail ("self->ob_item != NULL || self->allocated == 0 || self->allocated == -1", "/home/bag/repos/cpython/Objects/listobject.c", 2791, __extension__ __PRETTY_FUNCTION__); }));
    if (self->ob_item != ((void *)0)) {
        (void)_list_clear(self);
    }
    if (iterable != ((void *)0)) {
        PyObject *rv = list_extend(self, iterable);
        if (rv == ((void *)0))
            return -1;
        Py_DECREF(((PyObject*)((rv))));
    }
    return 0;
}
static PyObject *
list_vectorcall(PyObject *type, PyObject * const*args,
                size_t nargsf, PyObject *kwnames)
{
    if (!((kwnames) == ((void *)0) || _PyArg_NoKwnames(("list"), (kwnames)))) {
        return ((void *)0);
    }
    Py_ssize_t nargs = _PyVectorcall_NARGS(nargsf);
    if (!((!((1) == 0x7fffffffffffffffL) && (0) <= (nargs) && (nargs) <= (1)) || _PyArg_CheckPositional(("list"), (nargs), (0), (1)))) {
        return ((void *)0);
    }
    PyObject *list = PyType_GenericAlloc((((void) sizeof ((PyType_Check(((PyObject*)((type))))) ? 1 : 0), __extension__ ({ if (PyType_Check(((PyObject*)((type))))) ; else __assert_fail ("PyType_Check(type)", "/home/bag/repos/cpython/Objects/listobject.c", 2819, __extension__ __PRETTY_FUNCTION__); })), ((PyTypeObject*)((type)))), 0);
    if (list == ((void *)0)) {
        return ((void *)0);
    }
    if (nargs) {
        if (list___init___impl((PyListObject *)list, args[0])) {
            Py_DECREF(((PyObject*)((list))));
            return ((void *)0);
        }
    }
    return list;
}
static PyObject *
list___sizeof___impl(PyListObject *self)
{
    size_t res = _PyObject_SIZE(Py_TYPE(((PyObject*)((self)))));
    res += (size_t)self->allocated * sizeof(void*);
    return PyLong_FromSize_t(res);
}
static PyObject *list_iter(PyObject *seq);
static PyObject *list_subscript(PyListObject*, PyObject*);
static PyMethodDef list_methods[] = {
    {"__getitem__", (PyCFunction)list_subscript, 0x0008|0x0040,
     "__getitem__($self, index, /)\n--\n\nReturn self[index]."},
    {"__reversed__", (PyCFunction)list___reversed__, 0x0004, list___reversed____doc__},
    {"__sizeof__", (PyCFunction)list___sizeof__, 0x0004, list___sizeof____doc__},
    {"clear", (PyCFunction)list_clear, 0x0004, list_clear__doc__},
    {"copy", (PyCFunction)list_copy, 0x0004, list_copy__doc__},
    {"append", (PyCFunction)list_append, 0x0008, list_append__doc__},
    {"insert", ((PyCFunction)(((void(*)(void))((list_insert))))), 0x0080, list_insert__doc__},
    {"extend", (PyCFunction)list_extend, 0x0008, list_extend__doc__},
    {"pop", ((PyCFunction)(((void(*)(void))((list_pop))))), 0x0080, list_pop__doc__},
    {"remove", (PyCFunction)list_remove, 0x0008, list_remove__doc__},
    {"index", ((PyCFunction)(((void(*)(void))((list_index))))), 0x0080, list_index__doc__},
    {"count", (PyCFunction)list_count, 0x0008, list_count__doc__},
    {"reverse", (PyCFunction)list_reverse, 0x0004, list_reverse__doc__},
    {"sort", ((PyCFunction)(((void(*)(void))((list_sort))))), 0x0080|0x0002, list_sort__doc__},
    {"__class_getitem__", Py_GenericAlias, 0x0008|0x0010, "See PEP 585"},
    {((void *)0), ((void *)0)}
};
static PySequenceMethods list_as_sequence = {
    (lenfunc)list_length,
    (binaryfunc)list_concat,
    (ssizeargfunc)list_repeat,
    (ssizeargfunc)list_item,
    0,
    (ssizeobjargproc)list_ass_item,
    0,
    (objobjproc)list_contains,
    (binaryfunc)list_inplace_concat,
    (ssizeargfunc)list_inplace_repeat,
};
static PyObject *
list_subscript(PyListObject* self, PyObject* item)
{
    if (_PyIndex_Check(item)) {
        Py_ssize_t i;
        i = PyNumber_AsSsize_t(item, PyExc_IndexError);
        if (i == -1 && PyErr_Occurred())
            return ((void *)0);
        if (i < 0)
            i += PyList_GET_SIZE(((PyObject*)((self))));
        return list_item(self, i);
    }
    else if (Py_IS_TYPE(((PyObject*)(((item)))), (&PySlice_Type))) {
        Py_ssize_t start, stop, step, slicelength, i;
        size_t cur;
        PyObject* result;
        PyObject* it;
        PyObject **src, **dest;
        if (PySlice_Unpack(item, &start, &stop, &step) < 0) {
            return ((void *)0);
        }
        slicelength = PySlice_AdjustIndices(Py_SIZE(((PyObject*)((self)))), &start, &stop,
                                            step);
        if (slicelength <= 0) {
            return PyList_New(0);
        }
        else if (step == 1) {
            return list_slice(self, start, stop);
        }
        else {
            result = list_new_prealloc(slicelength);
            if (!result) return ((void *)0);
            src = self->ob_item;
            dest = ((PyListObject *)result)->ob_item;
            for (cur = start, i = 0; i < slicelength;
                 cur += (size_t)step, i++) {
                it = _Py_NewRef(((PyObject*)((src[cur]))));
                dest[i] = it;
            }
            Py_SET_SIZE(((PyVarObject*)((result))), (slicelength));
            return result;
        }
    }
    else {
        PyErr_Format(PyExc_TypeError,
                     "list indices must be integers or slices, not %.200s",
                     Py_TYPE(((PyObject*)((item))))->tp_name);
        return ((void *)0);
    }
}
static Py_ssize_t
adjust_slice_indexes(PyListObject *lst,
                     Py_ssize_t *start, Py_ssize_t *stop,
                     Py_ssize_t step)
{
    Py_ssize_t slicelength = PySlice_AdjustIndices(Py_SIZE(((PyObject*)((lst)))), start, stop,
                                                   step);
    if ((step < 0 && *start < *stop) ||
        (step > 0 && *start > *stop))
        *stop = *start;
    return slicelength;
}
static int
list_ass_subscript(PyListObject* self, PyObject* item, PyObject* value)
{
    if (_PyIndex_Check(item)) {
        Py_ssize_t i = PyNumber_AsSsize_t(item, PyExc_IndexError);
        if (i == -1 && PyErr_Occurred())
            return -1;
        if (i < 0)
            i += PyList_GET_SIZE(((PyObject*)((self))));
        return list_ass_item(self, i, value);
    }
    else if (Py_IS_TYPE(((PyObject*)(((item)))), (&PySlice_Type))) {
        Py_ssize_t start, stop, step;
        if (PySlice_Unpack(item, &start, &stop, &step) < 0) {
            return -1;
        }
        if (value == ((void *)0)) {
            PyObject **garbage;
            size_t cur;
            Py_ssize_t i;
            int res;
            Py_ssize_t slicelength = adjust_slice_indexes(self, &start, &stop,
                                                          step);
            if (step == 1)
                return list_ass_slice(self, start, stop, value);
            if (slicelength <= 0)
                return 0;
            if (step < 0) {
                stop = start + 1;
                start = stop + step*(slicelength - 1) - 1;
                step = -step;
            }
            garbage = (PyObject**)
                PyMem_Malloc(slicelength*sizeof(PyObject*));
            if (!garbage) {
                PyErr_NoMemory();
                return -1;
            }
            for (cur = start, i = 0;
                 cur < (size_t)stop;
                 cur += step, i++) {
                Py_ssize_t lim = step - 1;
                garbage[i] = ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(self)", "/home/bag/repos/cpython/Objects/listobject.c", 3013, __extension__ __PRETTY_FUNCTION__); })), ((PyListObject*)((self))))->ob_item[(cur)]);
                if (cur + step >= (size_t)Py_SIZE(((PyObject*)((self))))) {
                    lim = Py_SIZE(((PyObject*)((self)))) - cur - 1;
                }
                memmove(self->ob_item + cur - i,
                    self->ob_item + cur + 1,
                    lim * sizeof(PyObject *));
            }
            cur = start + (size_t)slicelength * step;
            if (cur < (size_t)Py_SIZE(((PyObject*)((self))))) {
                memmove(self->ob_item + cur - slicelength,
                    self->ob_item + cur,
                    (Py_SIZE(((PyObject*)((self)))) - cur) *
                     sizeof(PyObject *));
            }
            Py_SET_SIZE(((PyVarObject*)((self))), (Py_SIZE(((PyObject*)((self)))) - slicelength));
            res = list_resize(self, Py_SIZE(((PyObject*)((self)))));
            for (i = 0; i < slicelength; i++) {
                Py_DECREF(((PyObject*)((garbage[i]))));
            }
            PyMem_Free(garbage);
            return res;
        }
        else {
            PyObject *ins, *seq;
            PyObject **garbage, **seqitems, **selfitems;
            Py_ssize_t i;
            size_t cur;
            if (self == (PyListObject*)value) {
                seq = list_slice((PyListObject*)value, 0,
                                   PyList_GET_SIZE(((PyObject*)((value)))));
            }
            else {
                seq = PySequence_Fast(value,
                                      "must assign iterable "
                                      "to extended slice");
            }
            if (!seq)
                return -1;
            Py_ssize_t slicelength = adjust_slice_indexes(self, &start, &stop,
                                                          step);
            if (step == 1) {
                int res = list_ass_slice(self, start, stop, seq);
                Py_DECREF(((PyObject*)((seq))));
                return res;
            }
            if ((PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25))) ? PyList_GET_SIZE(((PyObject*)((seq)))) : PyTuple_GET_SIZE(((PyObject*)((seq))))) != slicelength) {
                PyErr_Format(PyExc_ValueError,
                    "attempt to assign sequence of "
                    "size %zd to extended slice of "
                    "size %zd",
                         (PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25))) ? PyList_GET_SIZE(((PyObject*)((seq)))) : PyTuple_GET_SIZE(((PyObject*)((seq))))),
                         slicelength);
                Py_DECREF(((PyObject*)((seq))));
                return -1;
            }
            if (!slicelength) {
                Py_DECREF(((PyObject*)((seq))));
                return 0;
            }
            garbage = (PyObject**)
                PyMem_Malloc(slicelength*sizeof(PyObject*));
            if (!garbage) {
                Py_DECREF(((PyObject*)((seq))));
                PyErr_NoMemory();
                return -1;
            }
            selfitems = self->ob_item;
            seqitems = (PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25))) ? ((PyListObject *)(seq))->ob_item : ((PyTupleObject *)(seq))->ob_item);
            for (cur = start, i = 0; i < slicelength;
                 cur += (size_t)step, i++) {
                garbage[i] = selfitems[cur];
                ins = _Py_NewRef(((PyObject*)((seqitems[i]))));
                selfitems[cur] = ins;
            }
            for (i = 0; i < slicelength; i++) {
                Py_DECREF(((PyObject*)((garbage[i]))));
            }
            PyMem_Free(garbage);
            Py_DECREF(((PyObject*)((seq))));
            return 0;
        }
    }
    else {
        PyErr_Format(PyExc_TypeError,
                     "list indices must be integers or slices, not %.200s",
                     Py_TYPE(((PyObject*)((item))))->tp_name);
        return -1;
    }
}
static PyMappingMethods list_as_mapping = {
    (lenfunc)list_length,
    (binaryfunc)list_subscript,
    (objobjargproc)list_ass_subscript
};
PyTypeObject PyList_Type = {
    { { { (0x7fffffff * 2U + 1U) }, (&PyType_Type) }, (0) },
    "list",
    sizeof(PyListObject),
    0,
    (destructor)list_dealloc,
    0,
    0,
    0,
    0,
    (reprfunc)list_repr,
    0,
    &list_as_sequence,
    &list_as_mapping,
    PyObject_HashNotImplemented,
    0,
    0,
    PyObject_GenericGetAttr,
    0,
    0,
    ( 0 | 0) | (1UL << 14) |
        (1UL << 10) | (1UL << 25) |
        (1UL << 22) | (1 << 5),
    list___init____doc__,
    (traverseproc)list_traverse,
    (inquiry)_list_clear,
    list_richcompare,
    0,
    list_iter,
    0,
    list_methods,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (initproc)list___init__,
    PyType_GenericAlloc,
    PyType_GenericNew,
    PyObject_GC_Del,
    .tp_vectorcall = list_vectorcall,
};
static void listiter_dealloc(_PyListIterObject *);
static int listiter_traverse(_PyListIterObject *, visitproc, void *);
static PyObject *listiter_next(_PyListIterObject *);
static PyObject *listiter_len(_PyListIterObject *, PyObject *);
static PyObject *listiter_reduce_general(void *_it, int forward);
static PyObject *listiter_reduce(_PyListIterObject *, PyObject *);
static PyObject *listiter_setstate(_PyListIterObject *, PyObject *state);
static const char length_hint_doc[] = "Private method returning an estimate of len(list(it)).";
static const char reduce_doc[] = "Return state information for pickling.";
static const char setstate_doc[] = "Set state information for unpickling.";
static PyMethodDef listiter_methods[] = {
    {"__length_hint__", (PyCFunction)listiter_len, 0x0004, length_hint_doc},
    {"__reduce__", (PyCFunction)listiter_reduce, 0x0004, reduce_doc},
    {"__setstate__", (PyCFunction)listiter_setstate, 0x0008, setstate_doc},
    {((void *)0), ((void *)0)}
};
PyTypeObject PyListIter_Type = {
    { { { (0x7fffffff * 2U + 1U) }, (&PyType_Type) }, (0) },
    "list_iterator",
    sizeof(_PyListIterObject),
    0,
    (destructor)listiter_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    PyObject_GenericGetAttr,
    0,
    0,
    ( 0 | 0) | (1UL << 14),
    0,
    (traverseproc)listiter_traverse,
    0,
    0,
    0,
    PyObject_SelfIter,
    (iternextfunc)listiter_next,
    listiter_methods,
    0,
};
static PyObject *
list_iter(PyObject *seq)
{
    _PyListIterObject *it;
    if (!PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) {
        _PyErr_BadInternalCall("/home/bag/repos/cpython/Objects/listobject.c", 3233);
        return ((void *)0);
    }
    it = ((_PyListIterObject*)(_PyObject_GC_New(&PyListIter_Type)));
    if (it == ((void *)0))
        return ((void *)0);
    it->it_index = 0;
    it->it_seq = (PyListObject *)_Py_NewRef(((PyObject*)((seq))));
    _PyObject_GC_TRACK("/home/bag/repos/cpython/Objects/listobject.c", 3241, ((PyObject*)((it))));
    return (PyObject *)it;
}
static void
listiter_dealloc(_PyListIterObject *it)
{
    _PyObject_GC_UNTRACK("/home/bag/repos/cpython/Objects/listobject.c", 3248, ((PyObject*)((it))));
    Py_XDECREF(((PyObject*)((it->it_seq))));
    PyObject_GC_Del(it);
}
static int
listiter_traverse(_PyListIterObject *it, visitproc visit, void *arg)
{
    do { if (it->it_seq) { int vret = visit(((PyObject*)((it->it_seq))), arg); if (vret) return vret; } } while (0);
    return 0;
}
static PyObject *
listiter_next(_PyListIterObject *it)
{
    PyListObject *seq;
    PyObject *item;
    ((void) sizeof ((it != ((void *)0)) ? 1 : 0), __extension__ ({ if (it != ((void *)0)) ; else __assert_fail ("it != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 3266, __extension__ __PRETTY_FUNCTION__); }));
    seq = it->it_seq;
    if (seq == ((void *)0))
        return ((void *)0);
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(seq)", "/home/bag/repos/cpython/Objects/listobject.c", 3270, __extension__ __PRETTY_FUNCTION__); }));
    if (it->it_index < PyList_GET_SIZE(((PyObject*)((seq))))) {
        item = ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(seq)", "/home/bag/repos/cpython/Objects/listobject.c", 3273, __extension__ __PRETTY_FUNCTION__); })), ((PyListObject*)((seq))))->ob_item[(it->it_index)]);
        ++it->it_index;
        return _Py_NewRef(((PyObject*)((item))));
    }
    it->it_seq = ((void *)0);
    Py_DECREF(((PyObject*)((seq))));
    return ((void *)0);
}
static PyObject *
listiter_len(_PyListIterObject *it, PyObject *_unused_ignored __attribute__((unused)))
{
    Py_ssize_t len;
    if (it->it_seq) {
        len = PyList_GET_SIZE(((PyObject*)((it->it_seq)))) - it->it_index;
        if (len >= 0)
            return PyLong_FromSsize_t(len);
    }
    return PyLong_FromLong(0);
}
static PyObject *
listiter_reduce(_PyListIterObject *it, PyObject *_unused_ignored __attribute__((unused)))
{
    return listiter_reduce_general(it, 1);
}
static PyObject *
listiter_setstate(_PyListIterObject *it, PyObject *state)
{
    Py_ssize_t index = PyLong_AsSsize_t(state);
    if (index == -1 && PyErr_Occurred())
        return ((void *)0);
    if (it->it_seq != ((void *)0)) {
        if (index < 0)
            index = 0;
        else if (index > PyList_GET_SIZE(((PyObject*)((it->it_seq)))))
            index = PyList_GET_SIZE(((PyObject*)((it->it_seq))));
        it->it_index = index;
    }
    return (&_Py_NoneStruct);
}
typedef struct {
    PyObject ob_base;
    Py_ssize_t it_index;
    PyListObject *it_seq;
} listreviterobject;
static void listreviter_dealloc(listreviterobject *);
static int listreviter_traverse(listreviterobject *, visitproc, void *);
static PyObject *listreviter_next(listreviterobject *);
static PyObject *listreviter_len(listreviterobject *, PyObject *);
static PyObject *listreviter_reduce(listreviterobject *, PyObject *);
static PyObject *listreviter_setstate(listreviterobject *, PyObject *);
static PyMethodDef listreviter_methods[] = {
    {"__length_hint__", (PyCFunction)listreviter_len, 0x0004, length_hint_doc},
    {"__reduce__", (PyCFunction)listreviter_reduce, 0x0004, reduce_doc},
    {"__setstate__", (PyCFunction)listreviter_setstate, 0x0008, setstate_doc},
    {((void *)0), ((void *)0)}
};
PyTypeObject PyListRevIter_Type = {
    { { { (0x7fffffff * 2U + 1U) }, (&PyType_Type) }, (0) },
    "list_reverseiterator",
    sizeof(listreviterobject),
    0,
    (destructor)listreviter_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    PyObject_GenericGetAttr,
    0,
    0,
    ( 0 | 0) | (1UL << 14),
    0,
    (traverseproc)listreviter_traverse,
    0,
    0,
    0,
    PyObject_SelfIter,
    (iternextfunc)listreviter_next,
    listreviter_methods,
    0,
};
static PyObject *
list___reversed___impl(PyListObject *self)
{
    listreviterobject *it;
    it = ((listreviterobject*)(_PyObject_GC_New(&PyListRevIter_Type)));
    if (it == ((void *)0))
        return ((void *)0);
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((self))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(self)", "/home/bag/repos/cpython/Objects/listobject.c", 3387, __extension__ __PRETTY_FUNCTION__); }));
    it->it_index = PyList_GET_SIZE(((PyObject*)((self)))) - 1;
    it->it_seq = (PyListObject*)_Py_NewRef(((PyObject*)((self))));
    PyObject_GC_Track(it);
    return (PyObject *)it;
}
static void
listreviter_dealloc(listreviterobject *it)
{
    PyObject_GC_UnTrack(it);
    Py_XDECREF(((PyObject*)((it->it_seq))));
    PyObject_GC_Del(it);
}
static int
listreviter_traverse(listreviterobject *it, visitproc visit, void *arg)
{
    do { if (it->it_seq) { int vret = visit(((PyObject*)((it->it_seq))), arg); if (vret) return vret; } } while (0);
    return 0;
}
static PyObject *
listreviter_next(listreviterobject *it)
{
    PyObject *item;
    Py_ssize_t index;
    PyListObject *seq;
    ((void) sizeof ((it != ((void *)0)) ? 1 : 0), __extension__ ({ if (it != ((void *)0)) ; else __assert_fail ("it != NULL", "/home/bag/repos/cpython/Objects/listobject.c", 3416, __extension__ __PRETTY_FUNCTION__); }));
    seq = it->it_seq;
    if (seq == ((void *)0)) {
        return ((void *)0);
    }
    ((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(seq)", "/home/bag/repos/cpython/Objects/listobject.c", 3421, __extension__ __PRETTY_FUNCTION__); }));
    index = it->it_index;
    if (index>=0 && index < PyList_GET_SIZE(((PyObject*)((seq))))) {
        item = ((((void) sizeof ((PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ? 1 : 0), __extension__ ({ if (PyType_HasFeature((Py_TYPE(((PyObject*)((seq))))), ((1UL << 25)))) ; else __assert_fail ("PyList_Check(seq)", "/home/bag/repos/cpython/Objects/listobject.c", 3425, __extension__ __PRETTY_FUNCTION__); })), ((PyListObject*)((seq))))->ob_item[(index)]);
        it->it_index--;
        return _Py_NewRef(((PyObject*)((item))));
    }
    it->it_index = -1;
    it->it_seq = ((void *)0);
    Py_DECREF(((PyObject*)((seq))));
    return ((void *)0);
}
static PyObject *
listreviter_len(listreviterobject *it, PyObject *_unused_ignored __attribute__((unused)))
{
    Py_ssize_t len = it->it_index + 1;
    if (it->it_seq == ((void *)0) || PyList_GET_SIZE(((PyObject*)((it->it_seq)))) < len)
        len = 0;
    return PyLong_FromSsize_t(len);
}
static PyObject *
listreviter_reduce(listreviterobject *it, PyObject *_unused_ignored __attribute__((unused)))
{
    return listiter_reduce_general(it, 0);
}
static PyObject *
listreviter_setstate(listreviterobject *it, PyObject *state)
{
    Py_ssize_t index = PyLong_AsSsize_t(state);
    if (index == -1 && PyErr_Occurred())
        return ((void *)0);
    if (it->it_seq != ((void *)0)) {
        if (index < -1)
            index = -1;
        else if (index > PyList_GET_SIZE(((PyObject*)((it->it_seq)))) - 1)
            index = PyList_GET_SIZE(((PyObject*)((it->it_seq)))) - 1;
        it->it_index = index;
    }
    return (&_Py_NoneStruct);
}
static PyObject *
listiter_reduce_general(void *_it, int forward)
{
    PyObject *list;
    PyObject *iter;
    if (forward) {
        iter = _PyEval_GetBuiltin(&(_PyRuntime.static_objects.singletons.strings.identifiers._py_iter._ascii.ob_base));
        if (!iter) {
            return ((void *)0);
        }
        _PyListIterObject *it = (_PyListIterObject *)_it;
        if (it->it_seq) {
            return Py_BuildValue("N(O)n", iter, it->it_seq, it->it_index);
        }
    } else {
        iter = _PyEval_GetBuiltin(&(_PyRuntime.static_objects.singletons.strings.identifiers._py_reversed._ascii.ob_base));
        if (!iter) {
            return ((void *)0);
        }
        listreviterobject *it = (listreviterobject *)_it;
        if (it->it_seq) {
            return Py_BuildValue("N(O)n", iter, it->it_seq, it->it_index);
        }
    }
    list = PyList_New(0);
    if (list == ((void *)0))
        return ((void *)0);
    return Py_BuildValue("N(N)", iter, list);
}
