
/* XDCtools Header files */
#include <xdc/std.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/Seconds.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <xdc/runtime/System.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

//ADDED
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "grlib/grlib.h"
#include "grlib/widget.h"
#include "grlib/canvas.h"
#include "grlib/pushbutton.h"
#include "drivers/Kentec320x240x16_ssd2119_spi.h"
#include "drivers/touch.h"
#include <xdc/runtime/System.h>
#include "driverlib/udma.h"

/* Board Header file */
#include "Board.h"
#include "user_interface.h"


#define STACKSIZE           2048//512
tContext sContext;
UI_Params uiParams;
Char taskStack[STACKSIZE];
uint32_t drawTime;
Task_Handle uiTask;
Clock_Struct clk0Struct;

// Function - Initialization
void clockUpdateFxn(UArg arg0);
void userInterfaceFxn(UArg arg0, UArg arg1);
void setSystemTime();

// Notifies the task when to update the time
void clockUpdateFxn(UArg arg0)
{
    drawTime = 1;
}
// Tasks Function to draw the interface
void userInterfaceFxn(UArg arg0, UArg arg1)
{
    while(1)
    {
        UserInterfaceDraw(&uiParams, &sContext);
    }
}

int main(void)
{
    // Parameters
    Task_Params taskParams;
    Clock_Params clkParams;

    /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    uint32_t ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
                                                SYSCTL_CFG_VCO_480), 120000000);
    // Task - User Interface Updater
    Task_Params_init(&taskParams);
    taskParams.stackSize = STACKSIZE;
    taskParams.priority = 1;
    taskParams.stack = &taskStack;
    taskParams.arg0 = ui32SysClock;
    uiTask = Task_create((Task_FuncPtr)userInterfaceFxn, &taskParams, NULL);

    // Clock - Periodic interval for update clock on GUI
    Clock_Params_init(&clkParams);
    clkParams.period = 1000;
    clkParams.startFlag = TRUE;
    Clock_construct(&clk0Struct, (Clock_FuncPtr)clockUpdateFxn,
                    1000, &clkParams);
    // Startup procedures
    UserInterfaceInit(ui32SysClock, &sContext, &uiParams);

    /* Start BIOS */
    BIOS_start();
    return (0);
}
