1.) Depending on the operating system different locks can be used for different use cases such as whether the program runs in the user space or kernel, or it could be whether the 
program needs to run concurrently.  Spinlocks would be used by linux and windows to protect important resources that are frequently accessed. Mutex locks depend on the O.S. to
determine how it is utilized in windows it is used for thread synchronization, for linux based systems the kernel uses mutex to block access, and Solaris utilizes mutex locks 
for synchronization of user and kernel levels. Semaphores allow multiple processes or threads to access a shared resource while keeping track of the available count. When it comes 
to adaptive mutex locks they are a necessity when the system's convention is variable; it falls back when needed but also acts as a spinlock when convention is low.  Lastly condition 
variables allow a thread to wait until a certain condition is met before proceeding, reducing CPU usage by avoiding unnecessary polling.

2.) In a single processor system spinlocks are not used due to the fact that they can cause deadlocks.  This is because a thread holding the lock could not get scheduled.  
However in a multiprocessor system spinlocks are fantastic, this is due to the fact the locks can be altered while other processes waiting on the lock are running concurrently.

3.) Disabling interrupts can negatively impact the entirety system.  It disrupts the system clock and if an interrupt is disabled for long enough it can cause the system to miss a tic; 
furthermore, this will then cause a system clock to not advance correctly.  Ways to fix these issues there are a couple routes to take.  One easy way is to compensate for missed tics by 
checking how long the interrupt was and adjusting for any possible missed tics.  Another option is high resolution timers that can correct time drifts caused by temporary interrupt disabling.


