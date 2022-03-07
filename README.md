# studies_philo

## [memset](https://man7.org/linux/man-pages/man3/memset.3.html) - fill memory with a constant byte
The C library function void *memset(void *str, int c, size_t n) copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
Following is the declaration for memset() function.
```
void *memset(void *str, int c, size_t n)
```
#### Parameters
str − This is a pointer to the block of memory to fill.
c − This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
n − This is the number of bytes to be set to the value.

#### Return Value
This function returns a pointer to the memory area str.

```
#include <stdio.h>
#include <string.h>

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7);
   puts(str);
   
   return(0);
}
```

## [usleep](https://man7.org/linux/man-pages/man3/usleep.3.html) - suspend execution for microsecond intervals
The usleep() function suspends execution of the calling thread
       for (at least) usec microseconds.  The sleep may be lengthened
       slightly by any system activity or by the time spent processing
       the call or by the granularity of system timers.
#### Return value
 The usleep() function returns 0 on success.  On error, -1 is
       returned, with errno set to indicate the error.

## [gettimeofday](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)  - get / set time
 The functions gettimeofday() and settimeofday() can get and set
       the time as well as a timezone.
#### Return value
 gettimeofday() and settimeofday() return 0 for success.  On
       error, -1 is returned and errno is set to indicate the error.

## pthread_create

## pthread_detach

## pthread_join

## pthread_mutex_init

## pthread_mutex_destroy

## pthread_mutex_lock

## pthread_mutex_unlock


## [printf](https://man7.org/linux/man-pages/man3/printf.3.html) - formatted output conversion
The functions in the printf() family produce output according to a format as described below.
The format string is a character string, beginning and ending in its initial shift state, if any. The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the character %, and ends with a conversion specifier. In between there may be (in this order) zero or more flags, an optional minimum field width, an optional precision and an optional length modifier.
```c
 The overall syntax of a conversion specification is:

           %[$][flags][width][.precision][length modifier]conversion
```

## [malloc](https://man7.org/linux/man-pages/man3/free.3.html)
 The malloc() function allocates size bytes and returns a pointer to the allocated memory.The memory is not initialized. If size is 0, then malloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().

## [free](https://man7.org/linux/man-pages/man3/free.3p.html)
 The free() function frees the memory space pointed to by ptr, which must have been returned by a previous call tomalloc(), calloc(), orrealloc().  Otherwise, or if free(ptr) has already been called before, undefined behavior occurs. If ptr is NULL, no operation is performed.

## [write](https://man7.org/linux/man-pages/man3/write.3p.html)
```c
#include <unistd.h>

       ssize_t write(int fd, const void *buf, size_t count);
```
write() writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptorfd. The number of bytes written may be less thancount if, for example, there is insufficient space on the underlying physical medium, or the RLIMIT_FSIZE resource limit is encountered (see setrlimit(2)), or the call was interrupted by a signal handler after having written less thancount bytes.
