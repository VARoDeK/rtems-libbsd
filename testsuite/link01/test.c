/*
 *  Simple test program -- simplified version of sample test hello.
 *
 *  $Id$
 */

#include <bsp.h>
#include <stdlib.h>
#include <stdio.h>
#include <freebsd/bsd.h>

/* needed by rtems-bsd-resource.c */
int maxproc;

/* needed by rtems-bsd-prot.c */
int ngroups_max;

/* needed by rtems-bsd-prot.c */
void prison_hold() {}
void prison_free() {}

/* needed by rtems-bsd-init-with-irq.c */
void rtems_interrupt_server_initialize(void) { }


/* 
 * Methods used to make sure the nic drivers
 * are pulled into the executable.
 */
// extern int _bsd_re_pcimodule_sys_init();
// extern int _bsd_fxp_pcimodule_sys_init();

rtems_task Init(
  rtems_task_argument ignored
)
{
  printf( "\n\n*** LIBFREEBSD INITIALIZATION TEST ***\n" );
  rtems_bsd_initialize_with_interrupt_server();

  printf("Nic Driver Addresses\n");
  // printf("RealTek %p\n", &_bsd_re_pcimodule_sys_init );
  // printf("EtherExpress k %p\n", &_bsd_fxp_pcimodule_sys_init );

  printf( "*** END OF LIBFREEBSD INITIALIZATION TEST ***\n" );
  exit( 0 );
}

/* configuration information */

/* NOTICE: the clock driver is explicitly disabled */
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_MAXIMUM_TASKS 1

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
/* end of file */
