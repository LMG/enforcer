#include "tpl_control.h"

transition node[TASK_COUNT][MAX_NODES_NUM][MAX_POSTS_NUM] = 
{
  //Task 1 model
  {
    //Node 0
    {
      //Outgoing transition 0
      {1, START_TASK, 5, 5, 0, -1, NULL, NULL, NULL},
      {2, START_TASK, 5, 5, 0, -1, NULL, NULL, NULL},
    },
    //Node 1
    {
      //Outgoing transition 0
      {0, OSServiceId_TerminateTask, 0, -1, 0, -1, NULL, NULL, NULL},
    },
    //Node 2
    {
      //Outgoing transition 0
      {0, OSServiceId_TerminateTask, 6, -1, 0, -1, NULL, NULL, NULL}, 
    }
  },
  //Task 2 model
  {
    //Node 0
    {
      //Outgoing transition 0
      {1, START_TASK, 0, -1, 0, -1, NULL, NULL, NULL},
    },
    //Node 2
    {
      //Outgoing transition 0
      {0, OSServiceId_TerminateTask, 0, -1, 0, -1, NULL, NULL, NULL}, 
    }
  },
  //Task 3 model
  {
    //Node 0
    {
      //Outgoing transition 0
      {1, START_TASK, 0, -1, 0, -1, NULL, NULL, NULL},
    },
    //Node 2
    {
      //Outgoing transition 0
      {0, OSServiceId_TerminateTask, 0, -1, 0, -1, NULL, NULL, NULL}, 
    }
  },
};
