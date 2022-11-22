/*
 * scheduler.h
 *
 *  Created on: Nov 22, 2022
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

//Begin include section
#include "global.h"
#include <stdlib.h>
//End include section

//Begin Define Section
#define SCH_MAX_TASKS  32
//End Define Section

//Type Definition Declaration
//=================================================================


struct TaskControlBlock_t {
	void (*TaskPointer)();
    uint32_t 				TaskID;
    uint32_t 				Delay;
    uint32_t 				Period;
//    uint32_t 				Runme;
    struct TaskControlBlock_t * 	NextTask;
};

typedef struct TaskControlBlock_t TaskControlBlock_t;

typedef struct {
    TaskControlBlock_t * head;
    int size;
} TaskList_t;


//type definition for ERRORCODE
typedef enum {
		NO_ERROR,
		ERROR_SCH_TOO_MANY_TASKS,
		ERROR_SCH_CANNOT_DELETE_TASK
} ERROR_CODE;

//type definition for RETURN CODE
typedef enum {
		RETURN_NORMAL,
		RETURN_ERROR
} RETURN_CODE;

//=================================================================

//Function Declaration
//void 			systemInitialzation();
void 		  	schedulerInit();
unsigned char 	schedulerAddTask(void (* functionPointer)(), unsigned int DELAY, unsigned int PERIOD);
void 		  	schedulerUpdate();
void 		  	schedulerDispatcher();
RETURN_CODE   	schedulerDeleteTask(const unsigned char TaskID);

#ifdef WATCHDOG
void watchDogRefresh();
unsigned char isWatchDogReset();
void watchdogCounting();
void resetWatchdogCounting();
#endif
//operation relation function
void 			schedulerReportStatus();
void 			schedulerSleep();

#endif /* INC_SCHEDULER_H_ */
