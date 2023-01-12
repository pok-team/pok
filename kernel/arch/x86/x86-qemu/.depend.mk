shutdown.o: shutdown.c ../../../..//kernel/include/dependencies.h
bsp.o: bsp.c ../../../..//kernel/include/arch.h \
 ../../../..//kernel/include/errno.h ../../../..//kernel/include/types.h \
 ../../../..//kernel/include/arch/x86/types.h \
 ../../../..//kernel/include/arch/x86/rendezvous.h \
 ../../../..//kernel/include/assert.h \
 ../../../..//kernel/include/arch/x86/spinlock.h \
 ../../../..//kernel/include/core/multiprocessing.h \
 ../../../..//kernel/include/arch/x86/multiprocessing.h cons.h pic.h \
 pit.h pm.h
pm.o: pm.c ../../../..//kernel/include/arch/x86/multiboot.h \
 ../../../..//kernel/include/errno.h ../../../..//kernel/include/types.h \
 ../../../..//kernel/include/arch/x86/types.h pm.h
cons.o: cons.c ../../../..//kernel/include/dependencies.h \
 ../../../..//kernel/include/errno.h \
 ../../../..//kernel/include/arch/x86/ioports.h \
 ../../../..//kernel/include/core/syscall.h \
 ../../../..//kernel/include/types.h \
 ../../../..//kernel/include/arch/x86/types.h \
 ../../../..//kernel/include/arch/x86/spinlock.h \
 ../../../..//kernel/include/core/multiprocessing.h \
 ../../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../../..//kernel/include/core/cons.h \
 ../../../..//kernel/include/core/debug.h \
 ../../../..//kernel/include/libc.h cons.h
debug.o: debug.c
pit.o: pit.c ../../../..//kernel/include/arch/x86/interrupt.h \
 ../../../..//kernel/include/types.h \
 ../../../..//kernel/include/arch/x86/types.h \
 ../../../..//kernel/include/arch/x86/ioports.h \
 ../../../..//kernel/include/core/syscall.h \
 ../../../..//kernel/include/errno.h ../../../..//kernel/include/assert.h \
 ../../../..//kernel/include/bsp.h \
 ../../../..//kernel/include/core/sched.h \
 ../../../..//kernel/include/core/multiprocessing.h \
 ../../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../../..//kernel/include/core/schedvalues.h \
 ../../../..//kernel/include/core/time.h pic.h pit.h
pic.o: pic.c ../../../..//kernel/include/errno.h \
 ../../../..//kernel/include/types.h \
 ../../../..//kernel/include/arch/x86/types.h \
 ../../../..//kernel/include/arch/x86/ioports.h \
 ../../../..//kernel/include/core/syscall.h pic.h
entry.o: entry.S
