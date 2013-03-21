@echo off
echo "Do you really want to dump a project for XC2365B_40F!"
echo "Press any key to do so! Dangerous!"
echo "It will overwrite all files exists"
pause
echo "Start to copy -f app"
mkdir  app
cp  -f  ../../../app/usermain/src/inittask_def.c		./app
cp  -f  ../../../app/usermain/src/inittask_def.h		./app
cp  -f  ../../../app/usermain/src/usermain.c			./app

echo "Start to copy -f config"
mkdir config
cd config
mkdir sysdepend
cd sysdepend
mkdir chip_xc2365b_40f
cd ../../
cp  -f  ../../../config/config.h				./config
cp  -f  ../../../config/tdsvcproxy.h			./config
cp  -f  ../../../config/tksvcproxy.h			./config
cp  -f  ../../../config/utk_config.h			./config
cp  -f  ../../../config/utk_config_func.h		./config
cp  -f  ../../../config/sysdepend/app_xc23xx/utk_config_depend.h		./config/sysdepend
cp  -f  ../../../config/sysdepend/app_xc23xx/chip_xc2365b_40f/utk_config_depend.h		./config/sysdepend/chip_xc2365b_40f

echo "Start to copy -f include"
mkdir include
cd include
mkdir sys
cd sys
mkdir svc
mkdir sysdepend
cd  sysdepend
mkdir app_xc23xx
cd ../../../
cp  -f  ../../../include/basic.h			./include
cp  -f  ../../../include/libstr.h			./include
cp  -f  ../../../include/machine.h			./include
cp  -f  ../../../include/stddef.h			./include
cp  -f  ../../../include/stdtype.h			./include
cp  -f  ../../../include/sys/debug.h		./include/sys
cp  -f  ../../../include/sys/imalloc.h		./include/sys
cp  -f  ../../../include/sys/queue.h		./include/sys
cp  -f  ../../../include/sys/str_align.h	./include/sys
cp  -f  ../../../include/sys/sysinfo.h		./include/sys
cp  -f  ../../../include/sys/svc/tdfncd.h	./include/sys/svc
cp  -f  ../../../include/sys/svc/tdsvctbl.h	./include/sys/svc
cp  -f  ../../../include/sys/svc/tkfncd.h		./include/sys/svc
cp  -f  ../../../include/sys/svc/tksvctbl.h		./include/sys/svc
cp  -f  ../../../include/sys/sysdepend/app_xc23xx/machine_depend.h		./include/sys/sysdepend/app_xc23xx
cp  -f  ../../../include/sys/sysdepend/app_xc23xx/str_align_depend.h	./include/sys/sysdepend/app_xc23xx
cp  -f  ../../../include/sys/sysdepend/app_xc23xx/sysinfo_depend.h		./include/sys/sysdepend/app_xc23xx
cp  -f  ../../../include/sys/sysdepend/machine_common.h	./include/sys/sysdepend
cp  -f  ../../../include/sys/sysdepend/machine_depend.h	./include/sys/sysdepend
cp  -f  ../../../include/sys/sysdepend/str_align_common.h	./include/sys/sysdepend
cp  -f  ../../../include/sys/sysdepend/sysinfo_common.h	./include/sys/sysdepend

cd include
mkdir tk
cd tk
mkdir sysdepend
cd sysdepend
mkdir app_xc23xx
cd app_xc23xx
mkdir chip_xc2365b_40f
cd ../
cd ../../../
cp  -f  ../../../include/tk/asm.h		./include/tk
cp  -f  ../../../include/tk/dbgspt.h	./include/tk
cp  -f  ../../../include/tk/errno.h	./include/tk
cp  -f  ../../../include/tk/syscall.h	./include/tk
cp  -f  ../../../include/tk/sysdef.h	./include/tk
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/asm_depend.h			./include/tk/sysdepend/app_xc23xx
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/chip_xc2365b_40f/sysdef_depend.h	./include/tk/sysdepend/app_xc23xx/chip_xc2365b_40f
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/cpuattr.h		./include/tk/sysdepend/app_xc23xx
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/cpudef.h		./include/tk/sysdepend/app_xc23xx
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/dbgspt_depend.h		./include/tk/sysdepend/app_xc23xx
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/sysdef_depend.h		./include/tk/sysdepend/app_xc23xx
cp  -f  ../../../include/tk/sysdepend/app_xc23xx/syslib_depend.h		./include/tk/sysdepend/app_xc23xx
cp  -f  ../../../include/tk/sysdepend/asm_common.h		./include/tk/sysdepend/
cp  -f  ../../../include/tk/sysdepend/dbgspt_common.h	./include/tk/sysdepend/
cp  -f  ../../../include/tk/sysdepend/syscall_common.h	./include/tk/sysdepend/
cp  -f  ../../../include/tk/sysdepend/sysdef_common.h	./include/tk/sysdepend/
cp  -f  ../../../include/tk/sysdepend/syslib_common.h	./include/tk/sysdepend/
cp  -f  ../../../include/tk/syslib.h		./include/tk
cp  -f  ../../../include/tk/tkernel.h		./include/tk
cp  -f  ../../../include/tk/typedef.h		./include/tk
cp  -f  ../../../include/tk/util.h			./include/tk
cd include 
mkdir tm
cd ../
cp  -f  ../../../include/tm/tmonitor.h	./include/tm
cp  -f  ../../../include/tm/tm_printf.h		./include/tm
cp  -f  ../../../include/typedef.h		./include

echo "Start to copy -f kernel"
mkdir kernel
cd kernel
mkdir cpu
mkdir device
cd device
mkdir chip_xc2365b_40f
cd ../
mkdir osek
cd osek
mkdir config
cd ../
mkdir sysinit
mkdir sysmain
mkdir tkernel
mkdir tstd
cd ..
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_calls.c		./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_calls.h		./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_conf.h		./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_init.c		./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_insn.h		./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_status.h	./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_support.c	./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/cpu_task.h		./kernel/cpu
cp  -f  ../../../kernel/cpu/src/sysdepend/c166/offset.h		./kernel/cpu

cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/chip_xc2365b_40f/hwconfig.h	./kernel/device/chip_xc2365b_40f
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/chip_xc2365b_40f/icrt0.c		./kernel/device/chip_xc2365b_40f
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/chip_xc2365b_40f/tkdev_conf.h	./kernel/device/chip_xc2365b_40f
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/devinit.c			./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/hwconfig.h			./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/patch.c			./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/patch.h			./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/power.c			./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/tkdev_conf.h		./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/tkdev_init.c		./kernel/device/
cp  -f  ../../../kernel/device/src/sysdepend/app_xc23xx/tkdev_timer.h		./kernel/device/
cp  -f  ../../../kernel/osek/src/config/osek_cfg.c		./kernel/osek/config
cp  -f  ../../../kernel/osek/src/config/osek_cfg.h		./kernel/osek/config
cp  -f  ../../../kernel/osek/src/osek_alarm.c			./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_check.h			./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_event.c			./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_interrupt.c		./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_os.h				./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_osctrl.c			./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_resource.c		./kernel/osek/
cp  -f  ../../../kernel/osek/src/osek_task.c			./kernel/osek/
cp  -f  ../../../kernel/sysinit/src/sysinit.h		./kernel/sysinit/
cp  -f  ../../../kernel/sysinit/src/sysinit_main.c	./kernel/sysinit/
cp  -f  ../../../kernel/sysinit/src/sysstartup.c	./kernel/sysinit/
cp  -f  ../../../kernel/sysmain/src/inittask_main.c	./kernel/sysmain
cp  -f  ../../../kernel/sysmain/src/sysmain.h			./kernel/sysmain
cp  -f  ../../../kernel/tkernel/src/check.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/eventflag.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/eventflag.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/isyscall.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/isysconf.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/kernel.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/klock.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/limits.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/longlong.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/longlong.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mailbox.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mailbox.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/memory.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/memory.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mempfix.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mempfix.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mempool.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mempool.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/messagebuf.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/messagebuf.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/misc_calls.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/misc_calls.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mutex.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/mutex.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/objname.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/ready_queue.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/rendezvous.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/rendezvous.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/semaphore.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/semaphore.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/task.c			./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/task.h			./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/task_manage.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/task_sync.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/task_sync.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/timer.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/timer.h		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/time_calls.c	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/time_calls.h	./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/tkstart.c		./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/wait.c			./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/wait.h			./kernel/tkernel
cp  -f  ../../../kernel/tkernel/src/winfo.h		./kernel/tkernel
cp  -f  ../../../kernel/tstd/src/bitop.c			./kernel/tstd/
cp  -f  ../../../kernel/tstd/src/bitop.h			./kernel/tstd/

echo "Start to copy -f lib"
mkdir lib
cd lib
mkdir libstr
mkdir libtk
cd libtk
mkdir sysdepend
cd ../
mkdir libtm
cd libtm
mkdir sysdepend
cd ../
cd ../
cp  -f  ../../../lib/libstr/src/libstr_config.h		./lib/libstr/
cp  -f  ../../../lib/libstr/src/string.c				./lib/libstr/
cp  -f  ../../../lib/libtk/src/fastlock.c				./lib/libtk/
cp  -f  ../../../lib/libtk/src/fastmlock.c				./lib/libtk/
cp  -f  ../../../lib/libtk/src/libtk_config.h			./lib/libtk/
cp  -f  ../../../lib/libtk/src/sysdepend/c166/disint.c		./lib/libtk/sysdepend
cp  -f  ../../../lib/libtk/src/sysdepend/c166/int.c		./lib/libtk/sysdepend
cp  -f  ../../../lib/libtm/src/sysdepend/app_xc23xx/chip_xc2365b_40f/sio.c		./lib/libtm/sysdepend/
cp  -f  ../../../lib/libtm/src/tm_monitor.c	./lib/libtm
cp  -f  ../../../lib/libtm/src/tm_printf.c		./lib/libtm

echo "Finshed"
pause
