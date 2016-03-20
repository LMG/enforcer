/**
 * @file tpl_os.h
 *
 * @section File description
 *
 * This file gathers system call declarations.
 *
 * Generated from application test
 * Automatically generated by goil on Tue Mar  1 13:17:54 2016
 * from root OIL file autosar_tp_s1.oil
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_H
#define TPL_OS_H


#ifdef __cplusplus
extern "C" {
#endif

#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_os_error.h"
#include "tpl_as_definitions.h"
#include "tpl_as_error.h"
#include "tpl_as_protec_hook.h"
/*--------------------------------------------------------------------------*
 * os system calls.
 * corresponding kernel implementation is in files
 * tpl_os_os_kernel.h and tpl_os_os_kernel.c
 * tpl_os_os.h and tpl_os_os.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_os.h"

/*
 * GetActiveApplicationMode
 *
 * This service returns the current application mode. It may be used to
 * write mode dependent code.
 *
 * Return value:
 * The active application mode
 */
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void);

/*
 * ShutdownOS
 *
 * The user can call this system service to abort the overall system (e.g.
 * emergency off). The operating system also calls this function
 * internally, if it has reached an undefined internal state and is no
 * longer ready to run.
 *
 * error:  The error that occured
 */
FUNC(void, OS_CODE) ShutdownOS(
  CONST(StatusType, AUTOMATIC) error);

/*--------------------------------------------------------------------------*
 * interrupt system calls.
 * corresponding kernel implementation is in files
 * tpl_os_interrupt_kernel.h and tpl_os_interrupt_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_interrupt.h"

/*
 * EnableAllInterrupts
 *
 * This service restores the state saved by DisableAllInterrupts.
 */
FUNC(void, OS_CODE) EnableAllInterrupts(void);

/*
 * DisableAllInterrupts
 *
 * This service disables all interrupts for which the hardware supports
 * disabling. The state before is saved for the EnableAllInterrupts call.
 */
FUNC(void, OS_CODE) DisableAllInterrupts(void);

/*
 * ResumeAllInterrupts
 *
 * This service restores the recognition status of all interrupts saved by
 * the SuspendAllInterrupts service.
 */
FUNC(void, OS_CODE) ResumeAllInterrupts(void);

/*
 * SuspendAllInterrupts
 *
 * This service saves the recognition status of all interrupts and
 * disables all interrupts for which the hardware supports disabling.
 */
FUNC(void, OS_CODE) SuspendAllInterrupts(void);

/*
 * ResumeOSInterrupts
 *
 * This service restores the recognition status of interrupts saved by the
 * SuspendOSInterrupts service.
 */
FUNC(void, OS_CODE) ResumeOSInterrupts(void);

/*
 * SuspendOSInterrupts
 *
 * This service saves the recognition status of interrupts of category 2
 * and disables the recognition of these interrupts.
 */
FUNC(void, OS_CODE) SuspendOSInterrupts(void);

/*
 * CallTerminateISR2
 *
 * 
 */
FUNC(void, OS_CODE) CallTerminateISR2(void);

/*--------------------------------------------------------------------------*
 * task system calls.
 * corresponding kernel implementation is in files
 * tpl_os_task_kernel.h and tpl_os_task_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_task.h"

/*
 * ActivateTask
 *
 * Activate a task
 *
 * task_id:  The identifier of the task to activate
 *
 * Return value:
 * E_OK:       No error (Standard & Extended)
 * E_OS_LIMIT: Too many activations of <task_id> (Standard & Extended)
 * E_OS_ID:    <task_id> is invalid (Extended)
 */
FUNC(StatusType, OS_CODE) ActivateTask(
  CONST(TaskType, AUTOMATIC) task_id);

/*
 * TerminateTask
 *
 * Terminate the calling task
 *
 * Return value:
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended)
 * E_OS_CALLEVEL: Call at interrupt level (Extended)
 */
FUNC(StatusType, OS_CODE) TerminateTask(void);

/*
 * ChainTask
 *
 * Terminate the calling task and activate task task_id
 *
 * task_id:  The identifier of the task to chain to
 *
 * Return value:
 * E_OS_LIMIT:    Too many activations of <task_id> (Standard & Extended)
 * E_OS_ID:       <task_id> is invalid (Extended)
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended)
 * E_OS_CALLEVEL: Call at interrupt level (Extended)
 */
FUNC(StatusType, OS_CODE) ChainTask(
  CONST(TaskType, AUTOMATIC) task_id);

/*
 * Schedule
 *
 * Call the scheduler
 *
 * Return value:
 * E_OK:          No error (Standard & Extended)
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended)
 * E_OS_CALLEVEL: Call at interrupt level (Extended)
 */
FUNC(StatusType, OS_CODE) Schedule(void);

/*
 * GetTaskID
 *
 * Get the id of the calling task
 *
 * task_id:  A pointer to the var where the identifier of the task will be
 *           stored
 *
 * Return value:
 * E_OK: No error (Standard & Extended)
 */
FUNC(StatusType, OS_CODE) GetTaskID(
  VAR(TaskRefType, AUTOMATIC) task_id);

/*
 * GetTaskState
 *
 * Get the task state of a task
 *
 * task_id:  The identifier of the task
 *
 * state:  A pointer to the var where the state of the task will be stored
 *
 * Return value:
 * E_OK:        No error (Standard & Extended)
 * E_OS_ID:     <alarm_id> is invalid (Extended)
 */
FUNC(StatusType, OS_CODE) GetTaskState(
  CONST(TaskType, AUTOMATIC) task_id,
  VAR(TaskStateRefType, AUTOMATIC) state);

/*--------------------------------------------------------------------------*
 * resource system calls.
 * corresponding kernel implementation is in files
 * tpl_os_resource_kernel.h and tpl_os_resource_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_resource.h"

/*
 * GetResource
 *
 * Get resource res_id. As a result, the priority of the caller may be
 * raised to the priority of the resource if the latter is higher
 *
 * res_id:  The id of the resource to get.
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * E_OS_ID: <res_id> is invalid (Extended)
 */
FUNC(StatusType, OS_CODE) GetResource(
  CONST(ResourceType, AUTOMATIC) res_id);

/*
 * ReleaseResource
 *
 * Release resource res_id. The priority of the caller returns to the
 * priority it had before getting the resource
 *
 * res_id:  The id of the resource to release.
 *
 * Return value:
 * E_OK:        No error (Standard & Extended)
 * E_OS_ID:     <res_id> is invalid (Extended)
 * E_OS_ACCESS: Attempt to get a resource which is already occupied by any
 *     task or ISR, or the statically assigned priority of the calling
 *     task or interrupt routine is higher than the calculated ceiling
 *     priority (Extended)
 */
FUNC(StatusType, OS_CODE) ReleaseResource(
  CONST(ResourceType, AUTOMATIC) res_id);

/*--------------------------------------------------------------------------*
 * counter system calls.
 * corresponding kernel implementation is in files
 * tpl_as_counter_kernel.h and tpl_as_counter_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_as_counter.h"

/*
 * IncrementCounter
 *
 * Increment a counter.
 *
 * counter_id:  identifier of the counter to be incremented
 *
 * Return value:
 * E_OK:    no error (Standard & Extended). Requirements OS286 and OS321
 * E_OS_ID: <counter_id> is not valid (Extended). Requirement OS285
 */
FUNC(StatusType, OS_CODE) IncrementCounter(
  CONST(CounterType, AUTOMATIC) counter_id);

/*
 * GetCounterValue
 *
 * Get the value of a counter.
 *
 * counter_id:  identifier of the counter
 *
 * value:  reference to the variable where is value is returned
 *
 * Return value:
 * E_OK        no error (Standard & Extended). Requirement OS377
 * E_OS_ID     <counter_id> is invalid (Extended). Eequirement OS376
 */
FUNC(StatusType, OS_CODE) GetCounterValue(
  CONST(CounterType, AUTOMATIC) counter_id,
  CONST(TickRefType, AUTOMATIC) value);

/*
 * GetElapsedCounterValue
 *
 * Get the elapsed value of a counter.
 *
 * counter_id:  identifier of the counter
 *
 * previous_value:  reference to the variable where a previous value is
 *                  stored
 *
 * value:  reference to the variable where is value is returned
 *
 * Return value:
 * E_OK        no error (Standard & Extended). Requirement OS382
 * E_OS_VALUE  the <previous_value> parameter is larger than the
 *     maxallowedvalue of the counter (Standard & Extended). Requirement
 *     OS391
 * E_OS_ID     <counter_id> is invalid (Extended). Eequirement OS381
 */
FUNC(StatusType, OS_CODE) GetElapsedCounterValue(
  CONST(CounterType, AUTOMATIC) counter_id,
  CONST(TickRefType, AUTOMATIC) previous_value,
  CONST(TickRefType, AUTOMATIC) value);

/*--------------------------------------------------------------------------*
 * scheduletables system calls.
 * corresponding kernel implementation is in files
 * tpl_as_st_kernel.h and tpl_as_st_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_as_schedtable.h"

/*
 * StartScheduleTableRel
 *
 * Start a schedule table at a relative date.
 *
 * sched_table_id:  identifier of the schedule table to be started.
 *
 * offset:  relative tick value between now and start of the schedule
 *          table.
 *
 * Return value:
 * E_OK:       no error (Standard & Extended). Requirement OS278.
 * E_OS_ID:    <sched_table_id> is not valid (Extended). Requirement
 *     OS275.
 * E_OS_VALUE: <offset> was set to 0 or is greater than the
 *     MAXALLOWEDVALUE of the counter (Standard & Extended). Requirement
 *     OS276 and OS332.
 * E_OS_STATE: the schedule table is already started or currently in state
 *     SCHEDULETABLE_NEXT (Standard & Extended). Requirement OS277.
 */
FUNC(StatusType, OS_CODE) StartScheduleTableRel(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id,
  CONST(TickType, AUTOMATIC) offset);

/*
 * StartScheduleTableAbs
 *
 * Start a schedule table at an absolute date.
 *
 * sched_table_id:  identifier of the schedule table to be started.
 *
 * tick_val:  absolute tick value of the start date of the schedule table.
 *
 * Return value:
 * E_OK:       no error (Standard & Extended). Requirement OS351.
 * E_OS_ID:    <sched_table_id> is not valid (Extended). Requirement
 *     OS348.
 * E_OS_VALUE: <tick_val> is greater than the MAXALLOWEDVALUE of the
 *     counter (Standard & Extended). Requirement OS349.
 * E_OS_STATE: the schedule table is already started or currently in state
 *     SCHEDULETABLE_NEXT (Standard & Extended). Requirement OS350.
 */
FUNC(StatusType, OS_CODE) StartScheduleTableAbs(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id,
  CONST(TickType, AUTOMATIC) tick_val);

/*
 * StopScheduleTable
 *
 *  Stop a schedule table.
 *
 * sched_table_id:  identifier of the schedule table to be started.
 *
 * Return value:
 * E_OK:        no error (Standard & Extended). Requirement OS281.
 * E_OS_ID:     <sched_table_id> is not valid (Extended). Requirement
 *     OS279.
 * E_OS_NOFUNC: the schedule table was not started (Standard & Extended).
 *     Requirement OS280.
 */
FUNC(StatusType, OS_CODE) StopScheduleTable(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id);

/*
 * NextScheduleTable
 *
 * Switch the processing from one schedule table to another.
 *
 * current_st_id:  identifier of the schedule table currently in use.
 *
 * next_st_id:  identifier of the next schedule table to process
 *
 * Return value:
 * E_OK:        no error (Standard & Extended). Requirement OS284.
 * E_OS_ID:     <current_sd_id> or <next_sd_id> are not valid (Extended).
 *     Requirement OS282.
 * E_OS_NOFUNC: the schedule table <current_sd_id> is not started or
 *     currently in state SCHEDULETABLE_NEXT (Standard & Extended).
 *     Requirement OS283.
 * E_OS_STATE:  the schedule table <next_sd_id> is already started or
 *     already a next schedule table (Standard & Extended). Requirement
 *     OS309.
 */
FUNC(StatusType, OS_CODE) NextScheduleTable(
  CONST(ScheduleTableType, AUTOMATIC) current_st_id,
  CONST(ScheduleTableType, AUTOMATIC) next_st_id);

/*
 * GetScheduleTableStatus
 *
 * Get the status of a schedule table
 *
 * sched_table_id:  identifier of the schedule table.
 *
 * status:  reference to a variable where the status is returned.
 *
 * Return value:
 * E_OK:        no error (Standard & Extended). Requirements OS289, OS353,
 *     OS354, OS290 and OS291.
 * E_OS_ID:     <sched_table_id> is not valid (Extended). Requirement
 *     OS293.
 */
FUNC(StatusType, OS_CODE) GetScheduleTableStatus(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id,
  CONST(ScheduleTableStatusRefType, AUTOMATIC) status);

/*--------------------------------------------------------------------------*
 * isrs system calls.
 * corresponding kernel implementation is in files
 * tpl_as_isr_kernel.h and tpl_as_isr_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_as_isr.h"

/*
 * GetISRID
 *
 * Get the ID of the currently running ISR.
 *
 * Return value:
 * Identifier of the currently running ISR or INVALID_ISR when called from
 *     outside a running ISR.
 */
FUNC(ISRType, OS_CODE) GetISRID(void);

/*--------------------------------------------------------------------------*
 * globaltime system calls.
 * corresponding kernel implementation is in files
 * tpl_as_gt_kernel.h and tpl_as_gt_kernel.c
 *--------------------------------------------------------------------------*/

/*
 * StartScheduleTableSynchron
 *
 * Start a schedule table synchronized with global time.
 *
 * sched_table_id:  identifier of the schedule table to be started.
 *
 * Return value:
 * E_OK:       No error.
 * E_OS_ID:    invalid schedule table id, or the schedule table is not
 *     configured as explicitly synchronized.
 * E_OS_STATE: the schedule table is already started
 */
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id);

/*
 * SyncScheduleTable
 *
 * Synchronize a schedule table with global time.
 *
 * sched_table_id:  Identifier of the schedule table.
 *
 * value:  Current value of the synchronization counter.
 *
 * Return value:
 * E_OK:       No error.
 * E_OS_STATE: The schedule table is not waiting or running.
 * E_OS_ID:    Invalid schedule table id, or the schedule table is not
 *     configured as explicitly synchronized.
 */
FUNC(StatusType, OS_CODE) SyncScheduleTable(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id,
  CONST(TickType, AUTOMATIC) value);

/*
 * SetScheduleTableAsync
 *
 * Set a schedule table asynchronous to global time.
 *
 * sched_table_id:  identifier of the schedule table.
 *
 * Return value:
 * E_OK:       No error.
 * E_OS_ID:    Invalid schedule table id, or the schedule table is not
 *     configured as explicitly synchronized.
 */
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(
  CONST(ScheduleTableType, AUTOMATIC) sched_table_id);


#ifdef __cplusplus
}
#endif




/* TPL_OS_H */
#endif

/* End of file tpl_os.h */
