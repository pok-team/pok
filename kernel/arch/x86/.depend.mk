multiprocessing.o: multiprocessing.c \
 ../../..//kernel/include/arch/x86/ioports.h \
 ../../..//kernel/include/core/syscall.h ../../..//kernel/include/errno.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/arch/x86/ipi.h \
 ../../..//kernel/include/arch/x86/spinlock.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/assert.h \
 ../../..//kernel/include/core/partition.h \
 ../../..//kernel/include/core/error.h \
 ../../..//kernel/include/core/sched.h \
 ../../..//kernel/include/core/schedvalues.h \
 ../../..//kernel/include/core/thread.h \
 ../../..//kernel/include/core/time.h ../../..//kernel/include/libc.h
exceptions.o: exceptions.c event.h \
 ../../..//kernel/include/arch/x86/interrupt.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h gdt.h \
 ../../..//kernel/include/errno.h ../../..//kernel/include/arch.h \
 ../../..//kernel/include/arch/x86/rendezvous.h \
 ../../..//kernel/include/assert.h \
 ../../..//kernel/include/arch/x86/spinlock.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/core/debug.h \
 ../../..//kernel/include/core/error.h \
 ../../..//kernel/include/core/sched.h \
 ../../..//kernel/include/core/schedvalues.h \
 ../../..//kernel/include/core/partition.h \
 ../../..//kernel/include/core/thread.h ../../..//kernel/include/libc.h
arch.o: arch.c event.h ../../..//kernel/include/arch/x86/interrupt.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h gdt.h \
 ../../..//kernel/include/errno.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/core/partition.h \
 ../../..//kernel/include/core/error.h \
 ../../..//kernel/include/core/sched.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/core/schedvalues.h \
 ../../..//kernel/include/core/thread.h
divisionbyzeroerror.o: divisionbyzeroerror.c \
 ../../..//kernel/include/arch.h ../../..//kernel/include/errno.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/arch/x86/rendezvous.h \
 ../../..//kernel/include/assert.h \
 ../../..//kernel/include/arch/x86/spinlock.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h
syscalls.o: syscalls.c ../../..//kernel/include/core/debug.h \
 ../../..//kernel/include/core/partition.h \
 ../../..//kernel/include/core/error.h \
 ../../..//kernel/include/core/sched.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/core/schedvalues.h \
 ../../..//kernel/include/errno.h ../../..//kernel/include/core/thread.h \
 ../../..//kernel/include/core/syscall.h event.h \
 ../../..//kernel/include/arch/x86/interrupt.h gdt.h
pci.o: pci.c
interrupt.o: interrupt.c gdt.h ../../..//kernel/include/errno.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h tss.h \
 ../../..//kernel/include/arch/x86/interrupt.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h
ipi.o: ipi.c event.h ../../..//kernel/include/arch/x86/interrupt.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h gdt.h \
 ../../..//kernel/include/errno.h ../../..//kernel/include/arch.h \
 ../../..//kernel/include/arch/x86/rendezvous.h \
 ../../..//kernel/include/assert.h \
 ../../..//kernel/include/arch/x86/spinlock.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/arch/x86/ipi.h \
 ../../..//kernel/include/core/sched.h \
 ../../..//kernel/include/core/schedvalues.h \
 ../../..//kernel/include/libc.h
ap.o: ap.c event.h ../../..//kernel/include/arch/x86/interrupt.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h gdt.h \
 ../../..//kernel/include/errno.h ../../..//kernel/include/arch.h \
 ../../..//kernel/include/arch/x86/rendezvous.h \
 ../../..//kernel/include/assert.h \
 ../../..//kernel/include/arch/x86/spinlock.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/arch/x86/ipi.h ../../..//kernel/include/libc.h
event.o: event.c ../../..//kernel/include/libc.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/core/syscall.h ../../..//kernel/include/errno.h \
 event.h ../../..//kernel/include/arch/x86/interrupt.h gdt.h sysdesc.h
space.o: space.c ../../..//kernel/include/bsp.h \
 ../../..//kernel/include/errno.h ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/libc.h ../../..//kernel/include/arch.h \
 ../../..//kernel/include/arch/x86/rendezvous.h \
 ../../..//kernel/include/assert.h \
 ../../..//kernel/include/arch/x86/spinlock.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/arch/x86/interrupt.h gdt.h tss.h space.h \
 thread.h
thread.o: thread.c ../../..//kernel/include/bsp.h \
 ../../..//kernel/include/errno.h ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/core/thread.h \
 ../../..//kernel/include/core/multiprocessing.h \
 ../../..//kernel/include/arch/x86/multiprocessing.h \
 ../../..//kernel/include/core/sched.h \
 ../../..//kernel/include/core/schedvalues.h \
 ../../..//kernel/include/libc.h gdt.h thread.h
gdt.o: gdt.c ../../..//kernel/include/libc.h \
 ../../..//kernel/include/types.h \
 ../../..//kernel/include/arch/x86/types.h \
 ../../..//kernel/include/errno.h gdt.h sysdesc.h tss.h
start_ap.o: start_ap.S
