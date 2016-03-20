/**
 * @file tpl_service_ids.h
 *
 * @section desc File description
 *
 * Header of the service ids for application test
 * Automatically generated by goil on Tue Mar  1 13:17:54 2016
 * from root OIL file autosar_tp_s1.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2010
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

#ifndef TPL_SERVICES_IDS_H
#define TPL_SERVICES_IDS_H

#include "tpl_config_def.h"

/*=============================================================================
 * service ids
 */

/**
 * @def OSServiceId_GetActiveApplicationMode
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetActiveApplicationMode
 */
#define OSServiceId_GetActiveApplicationMode    0

/**
 * @def OSServiceId_StartOS
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartOS
 */
#define OSServiceId_StartOS    1

/**
 * @def OSServiceId_ShutdownOS
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ShutdownOS
 */
#define OSServiceId_ShutdownOS    2

/**
 * @def OSServiceId_EnableAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #EnableAllInterrupts
 */
#define OSServiceId_EnableAllInterrupts    3

/**
 * @def OSServiceId_DisableAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #DisableAllInterrupts
 */
#define OSServiceId_DisableAllInterrupts    4

/**
 * @def OSServiceId_ResumeAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ResumeAllInterrupts
 */
#define OSServiceId_ResumeAllInterrupts    5

/**
 * @def OSServiceId_SuspendAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SuspendAllInterrupts
 */
#define OSServiceId_SuspendAllInterrupts    6

/**
 * @def OSServiceId_ResumeOSInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ResumeOSInterrupts
 */
#define OSServiceId_ResumeOSInterrupts    7

/**
 * @def OSServiceId_SuspendOSInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SuspendOSInterrupts
 */
#define OSServiceId_SuspendOSInterrupts    8

/**
 * @def OSServiceId_CallTerminateISR2
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CallTerminateISR2
 */
#define OSServiceId_CallTerminateISR2    9

/**
 * @def OSServiceId_ActivateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ActivateTask
 */
#define OSServiceId_ActivateTask    10

/**
 * @def OSServiceId_TerminateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #TerminateTask
 */
#define OSServiceId_TerminateTask    11

/**
 * @def OSServiceId_ChainTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ChainTask
 */
#define OSServiceId_ChainTask    12

/**
 * @def OSServiceId_Schedule
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #Schedule
 */
#define OSServiceId_Schedule    13

/**
 * @def OSServiceId_GetTaskID
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetTaskID
 */
#define OSServiceId_GetTaskID    14

/**
 * @def OSServiceId_GetTaskState
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetTaskState
 */
#define OSServiceId_GetTaskState    15

/**
 * @def OSServiceId_CallTerminateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CallTerminateTask
 */
#define OSServiceId_CallTerminateTask    16

/**
 * @def OSServiceId_GetResource
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetResource
 */
#define OSServiceId_GetResource    17

/**
 * @def OSServiceId_ReleaseResource
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ReleaseResource
 */
#define OSServiceId_ReleaseResource    18

/**
 * @def OSServiceId_IncrementCounter
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #IncrementCounter
 */
#define OSServiceId_IncrementCounter    19

/**
 * @def OSServiceId_GetCounterValue
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetCounterValue
 */
#define OSServiceId_GetCounterValue    20

/**
 * @def OSServiceId_GetElapsedCounterValue
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetElapsedCounterValue
 */
#define OSServiceId_GetElapsedCounterValue    21

/**
 * @def OSServiceId_StartScheduleTableRel
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableRel
 */
#define OSServiceId_StartScheduleTableRel    22

/**
 * @def OSServiceId_StartScheduleTableAbs
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableAbs
 */
#define OSServiceId_StartScheduleTableAbs    23

/**
 * @def OSServiceId_StopScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StopScheduleTable
 */
#define OSServiceId_StopScheduleTable    24

/**
 * @def OSServiceId_NextScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #NextScheduleTable
 */
#define OSServiceId_NextScheduleTable    25

/**
 * @def OSServiceId_GetScheduleTableStatus
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetScheduleTableStatus
 */
#define OSServiceId_GetScheduleTableStatus    26

/**
 * @def OSServiceId_GetISRID
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetISRID
 */
#define OSServiceId_GetISRID    27

/**
 * @def OSServiceId_StartScheduleTableSynchron
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableSynchron
 */
#define OSServiceId_StartScheduleTableSynchron    28

/**
 * @def OSServiceId_SyncScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SyncScheduleTable
 */
#define OSServiceId_SyncScheduleTable    29

/**
 * @def OSServiceId_SetScheduleTableAsync
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetScheduleTableAsync
 */
#define OSServiceId_SetScheduleTableAsync    30

/**
 * @def SYSCALL_COUNT
 *
 * Number of system calls
 */
#define SYSCALL_COUNT    31

#endif

/* End of file TPL_SERVICES_IDS_H */

