/**
 * @file tpl_app_config.c
 *
 * @section desc File description
 *
 * OS data structure generated from application test
 * Automatically generated by goil on Tue Mar  1 13:17:54 2016
 * from root OIL file autosar_tp_s1.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_app_config.h"

#include "tpl_os_internal_types.h"
#include "tpl_machine.h"
#include "tpl_os_interrupt.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_alarm.h"
#include "tpl_os_resource_kernel.h"
#include "tpl_os_resource.h"
#include "tpl_os_event_kernel.h"
#include "tpl_os_event.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"


#include "tpl_as_schedtable.h"
#include "tpl_as_st_kernel.h"
#include "tpl_as_action.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_as_isr.h"
#include "tpl_as_counter.h"
#include "tpl_as_app_kernel.h"
#include "tpl_as_trusted_fct.h"
#include "tpl_as_trusted_fct_kernel.h"
#include "tpl_as_application.h"

#include "tpl_as_protec_hook.h"
#include "tpl_as_timing_protec.h"

/*=============================================================================
 * Application Modes tables for tasks, alarms and schedule tables
 * Application Modes masks are as follow:
 * std = 1
 */

CONST(tpl_application_mode, OS_CONST) std = 0; /* mask = 1 */
CONST(tpl_application_mode, OS_CONST) OSDEFAULTAPPMODE = 0;
CONST(tpl_appmode_mask, OS_CONST) tpl_task_app_mode[TASK_COUNT] = {
  0 /* task t4 :  */ ,
  0 /* task t1 :  */ ,
  0 /* task t2 :  */ ,
  0 /* task t3 :  */ 
};

CONST(tpl_appmode_mask, OS_CONST) tpl_scheduletable_app_mode[SCHEDTABLE_COUNT] = {
  1 /* schedule table sched1 : std */ 
};

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Declaration of processes IDs
 */

/* Task t4 identifier */
#define t4_id 0
CONST(TaskType, AUTOMATIC) t4 = t4_id;

/* Task t1 identifier */
#define t1_id 1
CONST(TaskType, AUTOMATIC) t1 = t1_id;

/* Task t2 identifier */
#define t2_id 2
CONST(TaskType, AUTOMATIC) t2 = t2_id;

/* Task t3 identifier */
#define t3_id 3
CONST(TaskType, AUTOMATIC) t3 = t3_id;

/*=============================================================================
 * Declaration of Counter IDs
 */

/* Counter Hardware_Counter identifier */
#define Hardware_Counter_id 0
CONST(CounterType, AUTOMATIC) Hardware_Counter = Hardware_Counter_id;

/* Counter SystemCounter identifier */
#define SystemCounter_id 1
CONST(CounterType, AUTOMATIC) SystemCounter = SystemCounter_id;

/*=============================================================================
 * Declaration of Scheduletables IDs
 */

/* Schedule table sched1 identifier */
#define sched1_id 0
CONST(ScheduleTableType, AUTOMATIC) sched1 = sched1_id;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
tpl_resource_table[RESOURCE_COUNT] = {
  &res_sched_rez_desc  
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */
/*-----------------------------------------------------------------------------
 * Counter Hardware_Counter descriptor
 */

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_tick, OS_CONST) OSTICKSPERBASE_Hardware_Counter = 10;
CONST(tpl_tick, OS_CONST) OSMAXALLOWEDVALUE_Hardware_Counter = 16;
CONST(tpl_tick, OS_CONST) OSMINCYCLE_Hardware_Counter = 1;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_counter, OS_VAR) Hardware_Counter_counter_desc = {
  /* ticks per base       */  10,
  /* max allowed value    */  16,
  /* minimum cycle        */  1,
  /* current tick         */  0,
  /* current date         */  0,
    /* type the counter     */  HARDWARE_COUNTER,
#if WITH_OSAPPLICATION == YES
    /* OS Application id    */  
#endif
    /* first alarm          */  NULL_PTR,
    /* next alarm to raise  */  NULL_PTR
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Counter SystemCounter descriptor
 */

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_tick, OS_CONST) OSTICKSPERBASE = 1;
CONST(tpl_tick, OS_CONST) OSMAXALLOWEDVALUE = 32767;
CONST(tpl_tick, OS_CONST) OSMINCYCLE = 1;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_counter, OS_VAR) SystemCounter_counter_desc = {
  /* ticks per base       */  1,
  /* max allowed value    */  32767,
  /* minimum cycle        */  1,
  /* current tick         */  0,
  /* current date         */  0,
    /* type the counter     */  HARDWARE_COUNTER,
#if WITH_OSAPPLICATION == YES
    /* OS Application id    */  
#endif
    /* first alarm          */  NULL_PTR,
    /* next alarm to raise  */  NULL_PTR
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#include "tpl_os_kernel.h"          /* tpl_schedule */
#include "tpl_os_timeobj_kernel.h"  /* tpl_counter_tick */
#include "tpl_machine_interface.h"  /* tpl_switch_context_from_it */

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
volatile VAR(uint32, OS_VAR) tpl_time_counter = 0;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_bool, OS_CODE) tpl_tick_SysTick(void)
{
  tpl_counter_tick(&Hardware_Counter_counter_desc);
  tpl_counter_tick(&SystemCounter_counter_desc);
  tpl_time_counter++;

  if (tpl_kern.need_schedule == TRUE)
  {
    tpl_schedule_from_running();
    LOCAL_SWITCH_CONTEXT()
  }

  return TRUE;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2VAR(tpl_counter, OS_VAR, OS_APPL_DATA)
tpl_counter_table[COUNTER_COUNT] = {
  &Hardware_Counter_counter_desc,
  &SystemCounter_counter_desc
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Descriptor(s) of the idle task(s)
 */
/*-----------------------------------------------------------------------------
 * Task IDLE_TASK descriptor
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task IDLE_TASK function prototype
 */

FUNC(void, OS_APPL_CODE) idle_function(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task IDLE_TASK stack
 */
#define APP_Task_IDLE_TASK_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) IDLE_TASK_stack_zone[IDLE_STACK_SIZE/sizeof(tpl_stack_word)];
#define APP_Task_IDLE_TASK_STOP_SEC_STACK
#include "tpl_memmap.h"

#define IDLE_TASK_STACK {IDLE_TASK_stack_zone, IDLE_STACK_SIZE}

/*
 * Task IDLE_TASK context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_core_context, OS_VAR) IDLE_TASK_int_context;

#define IDLE_TASK_CONTEXT &IDLE_TASK_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task IDLE_TASK
 */
CONST(tpl_proc_static, OS_CONST) IDLE_TASK_task_stat_desc = {
  /* context                  */  IDLE_TASK_CONTEXT,
  /* stack                    */  IDLE_TASK_STACK,
  /* entry point (function)   */  idle_function,
  /* internal ressource       */  NULL,
  /* task id                  */  IDLE_TASK_ID,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  0,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task IDLE_TASK
 */
VAR(tpl_proc, OS_VAR) IDLE_TASK_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  ,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  0,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */
/*-----------------------------------------------------------------------------
 * Task t4 descriptor
 */
#define APP_Task_t4_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task t4 function prototype
 */

FUNC(void, OS_APPL_CODE) t4_function(void);
#define APP_Task_t4_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task t4 stack
 */
#define APP_Task_t4_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) t4_stack_zone[32768/sizeof(tpl_stack_word)];
#define APP_Task_t4_STOP_SEC_STACK
#include "tpl_memmap.h"

#define t4_STACK {t4_stack_zone, 32768}

/*
 * Task t4 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_core_context, OS_VAR) t4_int_context;

#define t4_CONTEXT &t4_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task t4
 */
CONST(tpl_proc_static, OS_CONST) t4_task_stat_desc = {
  /* context                  */  t4_CONTEXT,
  /* stack                    */  t4_STACK,
  /* entry point (function)   */  t4_function,
  /* internal ressource       */  NULL,
  /* task id                  */  t4_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  1,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task t4
 */
VAR(tpl_proc, OS_VAR) t4_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  ,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  1,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task t1 descriptor
 */
#define APP_Task_t1_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task t1 function prototype
 */

FUNC(void, OS_APPL_CODE) t1_function(void);
#define APP_Task_t1_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task t1 stack
 */
#define APP_Task_t1_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) t1_stack_zone[32768/sizeof(tpl_stack_word)];
#define APP_Task_t1_STOP_SEC_STACK
#include "tpl_memmap.h"

#define t1_STACK {t1_stack_zone, 32768}

/*
 * Task t1 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_core_context, OS_VAR) t1_int_context;

#define t1_CONTEXT &t1_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"



#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_timing_protection timeprotect_t1 = {    
    /* date of the last successful activation */        0,                      
    /* first instance marker */                         TRUE, 
    /* set of watchdogs */                              { 
    /* execution budget watchdog */                       {FALSE, 0, 0}, 
    /* resource lock -- to modify */                      {FALSE, 0, 0},
    /* allinterrupt lock watchdog */                      {FALSE, 0, 0},
    /* osinterrupt lock watchdog */                       {FALSE, 0, 0}
                                                        }
                                                    };

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task t1
 */
CONST(tpl_proc_static, OS_CONST) t1_task_stat_desc = {
  /* context                  */  t1_CONTEXT,
  /* stack                    */  t1_STACK,
  /* entry point (function)   */  t1_function,
  /* internal ressource       */  NULL,
  /* task id                  */  t1_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  2,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        100,
  /* timeframe        */        1,
  /* pointer to the timing
     protection descriptor    */ &timeprotect_t1

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task t1
 */
VAR(tpl_proc, OS_VAR) t1_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  ,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  2,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task t2 descriptor
 */
#define APP_Task_t2_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task t2 function prototype
 */

FUNC(void, OS_APPL_CODE) t2_function(void);
#define APP_Task_t2_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task t2 stack
 */
#define APP_Task_t2_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) t2_stack_zone[32768/sizeof(tpl_stack_word)];
#define APP_Task_t2_STOP_SEC_STACK
#include "tpl_memmap.h"

#define t2_STACK {t2_stack_zone, 32768}

/*
 * Task t2 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_core_context, OS_VAR) t2_int_context;

#define t2_CONTEXT &t2_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task t2
 */
CONST(tpl_proc_static, OS_CONST) t2_task_stat_desc = {
  /* context                  */  t2_CONTEXT,
  /* stack                    */  t2_STACK,
  /* entry point (function)   */  t2_function,
  /* internal ressource       */  NULL,
  /* task id                  */  t2_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  3,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task t2
 */
VAR(tpl_proc, OS_VAR) t2_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  ,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  3,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task t3 descriptor
 */
#define APP_Task_t3_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task t3 function prototype
 */

FUNC(void, OS_APPL_CODE) t3_function(void);
#define APP_Task_t3_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task t3 stack
 */
#define APP_Task_t3_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) t3_stack_zone[32768/sizeof(tpl_stack_word)];
#define APP_Task_t3_STOP_SEC_STACK
#include "tpl_memmap.h"

#define t3_STACK {t3_stack_zone, 32768}

/*
 * Task t3 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_core_context, OS_VAR) t3_int_context;

#define t3_CONTEXT &t3_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"



#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_timing_protection timeprotect_t3 = {    
    /* date of the last successful activation */        0,                      
    /* first instance marker */                         TRUE, 
    /* set of watchdogs */                              { 
    /* execution budget watchdog */                       {FALSE, 0, 0}, 
    /* resource lock -- to modify */                      {FALSE, 0, 0},
    /* allinterrupt lock watchdog */                      {FALSE, 0, 0},
    /* osinterrupt lock watchdog */                       {FALSE, 0, 0}
                                                        }
                                                    };

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task t3
 */
CONST(tpl_proc_static, OS_CONST) t3_task_stat_desc = {
  /* context                  */  t3_CONTEXT,
  /* stack                    */  t3_STACK,
  /* entry point (function)   */  t3_function,
  /* internal ressource       */  NULL,
  /* task id                  */  t3_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  3,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        100,
  /* timeframe        */        1,
  /* pointer to the timing
     protection descriptor    */ &timeprotect_t3

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task t3
 */
VAR(tpl_proc, OS_VAR) t3_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  ,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  3,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#include "tpl_machine.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) SysTick_Handler(void)
{
  tpl_tick_SysTick();

}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Definition and initialization of process tables (tasks and isrs)
 */
CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &t4_task_stat_desc,
  &t1_task_stat_desc,
  &t2_task_stat_desc,
  &t3_task_stat_desc,
  &IDLE_TASK_task_stat_desc
};

CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)
tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &t4_task_desc,
  &t1_task_desc,
  &t2_task_desc,
  &t3_task_desc,
  &IDLE_TASK_task_desc
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Declaration of flags functions
 */
/* $FLAGSFUNCTIONS$ */


/*=============================================================================
 * Declaration of schedule tables related defines and structures
 */


/*-----------------------------------------------------------------------------
 * Schedule table sched1 descriptor
 */

/*
 * Expiry points of schedule table sched1 
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_task_activation_action, OS_CONST) sched1_0_0_action = {
  {
    /* action function  */  tpl_action_activate_task
  },
  /* task id            */  t1_id
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
P2CONST(tpl_action, AUTOMATIC, OS_CONST) sched1_0[1] = {
  (tpl_action *)&sched1_0_0_action
};


tpl_expiry_point sched1_0_expirypoint = {
  /*  offset from previous expiry point   */  0,
  /*  sync_offset                         */  0,
  /*  number of actions for the expiry pt */  1,
  /*  pointer to the actions array        */  sched1_0,
  /*  maximum advance deviation           */  0,
  /*  maximum retard deviation            */  0
};

tpl_schedule_table sched1_st_dyn;

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

tpl_finalize_schedule_table_action sched1_5_0_action = {
  {
    /*  notification function */  tpl_action_finalize_schedule_table
  },
  /*  Schedule table descriptor pointer */  &sched1_st_dyn
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
P2CONST(tpl_action, AUTOMATIC, OS_CONST) sched1_5[1] = {
  (tpl_action *)&sched1_5_0_action
};


tpl_expiry_point sched1_5_expirypoint = {
  /*  offset from previous expiry point   */  5,
  /*  sync_offset                         */  5,
  /*  number of actions for the expiry pt */  1,
  /*  pointer to the actions array        */  sched1_5,
  /*  maximum advance deviation           */  0,
  /*  maximum retard deviation            */  0
};

P2VAR(tpl_expiry_point, AUTOMATIC, OS_CONST) sched1_expiry_table[2] = {
  &sched1_0_expirypoint,
  &sched1_5_expirypoint
};


tpl_schedtable_static sched1_st_stat = {
  { /* static time object part */
    /* counter            */  &Hardware_Counter_counter_desc,
    /* expire function    */  tpl_process_schedtable
#if (WITH_TRACE == YES)
    /* id of the table for tracing  */  , sched1_id
#endif
  },
  /* expiry points        */  sched1_expiry_table,
  /* expiry points count  */  2,
  /* sync strategy        */  SCHEDTABLE_NO_SYNC,
  /* periodic             */  TRUE,
  /* length               */  5,
  /* precision            */  0
};

tpl_schedule_table sched1_st_dyn = {
  { /* dynamic time object part */
    /* ptr to the static part   */  (tpl_time_obj_static *)&sched1_st_stat,
    /* next time object         */  NULL,
    /* prev time object         */  NULL,
    /* cycle                    */  0,
    /* date                     */  1,
    /* state of the time object */  SCHEDULETABLE_AUTOSTART_RELATIVE
  },
  /* next schedule table   */  NULL,
  /* current expiry point  */  0,
  /* deviation             */  0    
};

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONSTP2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA)
tpl_schedtable_table[1] = {
  &sched1_st_dyn
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Definition and initialization of Ready List structures
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_heap_entry, OS_VAR) tpl_ready_list[6];
VAR(tpl_rank_count, OS_VAR) tpl_tail_for_prio[5] = {
  0,
  0,
  0,
  0
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @internal
 *
 * tpl_kern gather informations on the current executing object and
 * the previous one
 */
VAR(tpl_kern_state, OS_VAR) tpl_kern =
{
  NULL,                      /* no running task static descriptor   */
  &IDLE_TASK_task_stat_desc, /* elected task to run is idle task    */
  NULL,                      /* no running task dynamic descriptor  */
  &IDLE_TASK_task_desc,      /* elected task to run is idle task    */
  INVALID_PROC_ID,           /* no running task so no ID            */
  INVALID_PROC_ID,           /* idle task has no ID                 */
  NO_NEED_SWITCH,            /* no context switch needed at start   */
  FALSE,                     /* no schedule needed at start         */
#if WITH_MEMORY_PROTECTION == YES
  1,                         /* at early system startup, we run in  */
                             /*  kernel mode, so in trusted mode    */
#endif /* WITH_MEMORY_PROTECTION */
};

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT + 1] = {

  "t4",
  "t1",
  "t2",
  "t3",
  "*idle*"
};
#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/* End of file tpl_app_config.c */
