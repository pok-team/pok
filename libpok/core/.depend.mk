threadpriority.o: threadpriority.c \
 ../..//libpok/include/core/dependencies.h ../..//libpok/include/arch.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/thread.h
eventcreate.o: eventcreate.c
semsignal.o: semsignal.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/lockobj.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/semaphore.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/syscall.h
threadperiod.o: threadperiod.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h
threaddelayedstart.o: threaddelayedstart.c \
 ../..//libpok/include/core/dependencies.h ../..//libpok/include/arch.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/thread.h
errorlog.o: errorlog.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/error.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/time.h ../..//libpok/include/core/syscall.h
errorignore.o: errorignore.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/error.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h
errorhandlercreate.o: errorhandlercreate.c \
 ../..//libpok/include/core/error.h \
 ../..//libpok/include/core/dependencies.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/core/thread.h
shutdown.o: shutdown.c ../..//libpok/include/core/dependencies.h
errorhandlerworker.o: errorhandlerworker.c \
 ../..//libpok/include/core/error.h \
 ../..//libpok/include/core/dependencies.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/partition.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/core/thread.h \
 ../..//libpok/include/libc/stdio.h ../..//libpok/include/libc/stdarg.h \
 ../..//libpok/include/libc/string.h
threadresume.o: threadresume.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/arch.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/thread.h
allocator.o: allocator.c ../..//libpok/include/core/allocator.h \
 ../..//libpok/include/core/dependencies.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h
eventsignal.o: eventsignal.c
threadcreate.o: threadcreate.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/arch.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/thread.h
errorconfirm.o: errorconfirm.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/error.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h
semwait.o: semwait.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/lockobj.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/semaphore.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/syscall.h
timecomputedeadline.o: timecomputedeadline.c
semcreate.o: semcreate.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/lockobj.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/semaphore.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/syscall.h
errorraise.o: errorraise.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h
mutexunlock.o: mutexunlock.c
semstatus.o: semstatus.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/semaphore.h \
 ../..//libpok/include/core/lockobj.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h ../..//libpok/include/errno.h
mutexlock.o: mutexlock.c
threadsleep.o: threadsleep.c ../..//libpok/include/core/syscall.h \
 ../..//libpok/include/errno.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h
eventwait.o: eventwait.c
errno.o: errno.c ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h
main.o: main.c ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h
eventlock.o: eventlock.c
mutexcreate.o: mutexcreate.c
timeget.o: timeget.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/time.h ../..//libpok/include/core/syscall.h \
 ../..//libpok/include/errno.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h
threadid.o: threadid.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/arch.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/thread.h
errorget.o: errorget.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/error.h ../..//libpok/include/errno.h \
 ../..//libpok/include/types.h ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h
eventbroadcast.o: eventbroadcast.c
threadstatus.o: threadstatus.c ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/arch.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h \
 ../..//libpok/include/core/syscall.h ../..//libpok/include/errno.h \
 ../..//libpok/include/core/thread.h
eventunlock.o: eventunlock.c
mutextrylock.o: mutextrylock.c
assert.o: assert.c
threadattrinit.o: threadattrinit.c \
 ../..//libpok/include/core/dependencies.h \
 ../..//libpok/include/core/thread.h ../..//libpok/include/core/syscall.h \
 ../..//libpok/include/errno.h ../..//libpok/include/types.h \
 ../..//libpok/include/arch/x86/types.h
