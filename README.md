GaInOS_Based_On_uTenuxV1.4-tkernel
===================================

GaInOS is an OSEK conformed OS based on uTenux(iTron/tkernel), It include the C embeded code and the GUI configuration tool.

###
    这里仅提供了一个基于uTenuxV1.4的完整发布包，包含uTenux的内核代码。
    本项目的主要部分是autosar目录下的代码部分，其首先基于uTenux的丰富强大型API提供了以及兼容OSEK223规范的
API接口层（osek），然后在此基础之上，移植Arctic Core（http://www.arccore.com）的Com通讯栈，继而构建完整的
Autosar的通讯栈环境。

###  
    Autosar目录下代码兼容uTenuxV1.5,但需要对tk_sysimpl.c代码进行小小的修改：
    
    定为到函数：SYSCALL void tk_sta_sys( T_CTSK *pk_ctsk )
    
    注释掉287行到294行的代码，如下所示：
    #if 0
    /*
     * Create/start initial task
     */
    knl_init_task_startup(pk_ctsk);

    knl_dispatch_force();
    /* No return */
    #endif
    
    这样做，就是不希望uTenux创建初始话任务，任务将都统一由OSEK兼容层来管理。
    
    修改main（）函数代码如下：
    
    EXPORT INT main( void )
    {
      /* Initialize bsp sequence */
        bsp_init();
        
    	/* Start uT/Kernel and return*/
    	tk_sta_sys((T_CTSK *)NULL);
        /* Start OSEK OS and will never return */
        StartOS(0);
        
    	return 0;
    }
    
    这样，你就可以开始学习OSEK和Autosar了。
    
    
