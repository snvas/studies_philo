# studies_philo

Mandatory part
You will have to write one program for the mandatory part and one for the bonus part but they will have the same basic rules:

- This project is to be coded in C, following the Norm. Any leak, crash, undefined behavior, or norm error means 0 to the project.
- Several philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping.
- While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
- The philosophers sit at a circular table with a large bowl of spaghetti in the center.
- There are some forks on the table.
- As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.
- The philosophers must never be starving.
- Every philosopher needs to eat.
- Philosophers don’t speak with each other.
- Philosophers don’t know when another philosopher is about to die.
- Each time a philosopher has finished eating, he will drop his forks and start sleeping.
- When a philosopher is done sleeping, he will start thinking.
- The simulation stops when a philosopher dies.
- Each program should have the same options: number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat

	- number_of_philosophers: is the number of philosophers and also the number of forks
	- time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies
	- time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
	- time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
	- number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
- Each philosopher should be given a number from 1 to ’number_of_philosophers’.
- Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with the number N is seated between philosopher N - 1 and philosopher N + 1
- Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and 	- timestamp_in_ms the current timestamp in milliseconds)
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died
- The status printed should not be scrambled or intertwined with another philosopher’s status.
- You can’t have more than 10 ms between the death of a philosopher and when it will print its death.
### Again, philosophers should avoid dying!

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

## [pthread_create](https://man7.org/linux/man-pages/man3/pthread_create.3.html) - create a new thread
 The pthread_create() function starts a new thread in the calling
       process.  The new thread starts execution by invoking
       start_routine(); arg is passed as the sole argument of
       start_routine().

       The new thread terminates in one of the following ways:

       * It calls pthread_exit(3), specifying an exit status value that
         is available to another thread in the same process that calls
         pthread_join(3).

       * It returns from start_routine(). This is equivalent to calling
         pthread_exit(3) with the value supplied in the return
         statement.

       * It is canceled (see pthread_cancel(3)).

       * Any of the threads in the process calls exit(3), or the main
         thread performs a return from main(). This causes the
         termination of all threads in the process.

#### Return value
 On success, pthread_create() returns 0; on error, it returns an
       error number, and the contents of *thread are undefined.

## [pthread_detach](https://man7.org/linux/man-pages/man3/pthread_detach.3.html)  - detach a thread
The pthread_detach() function marks the thread identified by
       thread as detached.  When a detached thread terminates, its
       resources are automatically released back to the system without
       the need for another thread to join with the terminated thread.

Attempting to detach an already detached thread results in
       unspecified behavior.

#### Return value
On success, pthread_detach() returns 0; on error, it returns an error number.

## [pthread_join](https://man7.org/linux/man-pages/man3/pthread_join.3.html) - join with a terminated thread
 The pthread_join() function waits for the thread specified by
       thread to terminate.  If that thread has already terminated, then
       pthread_join() returns immediately. The thread specified by
       thread must be joinable.

#### Return value
On success, pthread_join() returns 0; on error, it returns an
       error number.

## [pthread_mutex_destroy and pthread_mutex_init](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html) — destroy and initialize a mutex
 The pthread_mutex_destroy() function shall destroy the mutex
       object referenced by mutex; the mutex object becomes, in effect,
       uninitialized. An implementation may cause
       pthread_mutex_destroy() to set the object referenced by mutex to
       an invalid value.

A destroyed mutex object can be reinitialized using
       pthread_mutex_init(); the results of otherwise referencing the
       object after it has been destroyed are undefined.

It shall be safe to destroy an initialized mutex that is
       unlocked. Attempting to destroy a locked mutex, or a mutex that
       another thread is attempting to lock, or a mutex that is being
       used in a pthread_cond_timedwait() or pthread_cond_wait() call by
       another thread, results in undefined behavior.

The pthread_mutex_init() function shall initialize the mutex
       referenced by mutex with attributes specified by attr. If attr
       is NULL, the default mutex attributes are used; the effect shall
       be the same as passing the address of a default mutex attributes
       object. Upon successful initialization, the state of the mutex
       becomes initialized and unlocked.
```
#include <pthread.h>

       int pthread_mutex_init(pthread_mutex_t *restrict mutex,
           const pthread_mutexattr_t *restrict attr);
       pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
```

## [pthread_mutex_lock, pthread_mutex_trylock, pthread_mutex_unlock](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html) — lock and unlock a mutex
```
#include <pthread.h>

       int pthread_mutex_lock(pthread_mutex_t *mutex);
       int pthread_mutex_trylock(pthread_mutex_t *mutex);
       int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
The mutex object referenced by mutex shall be locked by a call to
 pthread_mutex_lock() that returns zero or [EOWNERDEAD].  If the
 mutex is already locked by another thread, the calling thread
 shall block until the mutex becomes available. This operation
 shall return with the mutex object referenced by mutex in the
 locked state with the calling thread as its owner. 
If a thread attempts to relock a mutex that it has already locked,
 pthread_mutex_lock() shall behave as described in the Relock
 column of the following table. If a thread attempts to unlock a
 mutex that it has not locked or a mutex which is unlocked,
 pthread_mutex_unlock() shall behave as described in the Unlock
 When Not Owner column of the following table.

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
