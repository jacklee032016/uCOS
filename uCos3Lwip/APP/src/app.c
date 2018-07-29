/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                             (c) Copyright 2009; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                            EXAMPLE CODE
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                        Evaluation Board
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : JJL
                  EHS
                  Michael Vysotsky
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>


/*
*********************************************************************************************************
*                                             LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB   AppTaskStartTCB; 
static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppTaskStart  (void *p_arg);


/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*********************************************************************************************************
*/

int  main (void)
{
    OS_ERR  err;

  /* Setup STM32 system (clock, PLL and Flash configuration) */
    BSP_IntDisAll();                                            /* Disable all interrupts.                              */

    OSInit(&err);                                               /* Init uC/OS-III.                                      */

    OSTaskCreate((OS_TCB    *)&AppTaskStartTCB,                 /* Create the start task                                */
                 (CPU_CHAR  *)"App Task Start",
                 (OS_TASK_PTR)AppTaskStart, 
                 (void      *)0,
                 (OS_PRIO    )APP_TASK_START_PRIO,
                 (CPU_STK   *)&AppTaskStartStk[0],
                 (CPU_STK   *)&AppTaskStartStk[APP_TASK_START_STK_SIZE / 10],
                 (OS_STK_SIZE)APP_TASK_START_STK_SIZE,
                 (OS_MSG_QTY )0,
                 (OS_TICK    )0,
                 (void      *)0,
                 (OS_OPT     )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR    *)&err);

    OSStart(&err);                                              /* Start multitasking (i.e. give control to uC/OS-III). */    
    return (0);    
}

/*
*********************************************************************************************************
*                                          App_TaskStart()
*
* Description : The startup task.  The uC/OS-II ticker should only be initialize once multitasking starts.
*
* Argument(s) : p_arg       Argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Note(s)     : none.
*********************************************************************************************************
*/

/*--------------- LCD Messages ---------------*/
#include "stm32_eval.h"
#include "stm322xg_eval_lcd.h"
#define MESSAGE1   "     STM32F2x7      "
#define MESSAGE2   "  STM32F-2 Series   "
#define MESSAGE3   "     uCOS-III       "

static  void  AppTaskStart (void *p_arg)
{
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;
    OS_ERR      err;
    
   (void)p_arg;

    BSP_Init();                                                   /* Initialize BSP functions                         */
    CPU_Init();                                                   /* Initialize the uC/CPU services                   */

    cpu_clk_freq = BSP_CPU_ClkFreq();                             /* Determine SysTick reference freq.                */                                                                        
    cnts         = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;  /* Determine nbr SysTick increments                 */
    OS_CPU_SysTickInit(cnts);                                     /* Init uC/OS periodic time src (SysTick).          */

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                                 /* Compute CPU capacity with no task running        */
#endif

    CPU_IntDisMeasMaxCurReset();
    
    STM322xG_LCD_Init();
    /* Clear the LCD */
    LCD_Clear(Black);
  
    /* Set the LCD Back Color */
    LCD_SetBackColor(Black);
  
    /* Set the LCD Text Color */
    LCD_SetTextColor(White);
  
    /* Display message on the LCD*/
    LCD_DisplayStringLine(Line0, (uint8_t*)MESSAGE1);
    LCD_DisplayStringLine(Line1, (uint8_t*)MESSAGE2);
    LCD_DisplayStringLine(Line2, (uint8_t*)MESSAGE3);
    LwIP_Init(false);
    
      /* Initialize webserver demo */
    http_server_netconn_init();

    while (DEF_TRUE) {                                            /* Task body, always written as an infinite loop.   */
      BSP_Sleep(10);
    }    
    
}
