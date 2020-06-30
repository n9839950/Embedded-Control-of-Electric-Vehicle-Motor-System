#include <string.h>
#include <stdio.h>
#include <time.h>
#include "user_interface.h"
#include <xdc/runtime/System.h>
#include "driverlib/udma.h"
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/BIOS.h>

// GUI - Canvas Drawing
// Set/Graph Menu Selection
Canvas(g_sMenuTypePage, WIDGET_ROOT, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240 - 0 -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);//0x00E09873

RectangularButton(g_sSetOption, &g_sMenuTypePage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 25, 145, 200,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrBlack, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Control", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphOption, &g_sMenuTypePage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 25, 145, 200,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Graph", 0, 0, 0, 0, 0);

// Set Menu Selection
Canvas(g_sMenuSetPage, &g_sMenuTypePage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240  -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sSetTemp, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Temp", 0, 0, 0, 0, 0);
RectangularButton(g_sSetMotor, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Motor", 0, 0, 0, 0, 0);
RectangularButton(g_sSetCurrent, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 115, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Current", 0, 0, 0, 0, 0);
RectangularButton(g_sSetAccel, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 115, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Accel", 0, 0, 0, 0, 0);
RectangularButton(g_sSetBack, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 200, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Back To Home", 0, 0, 0, 0, 0);

// Graph Menu Selection
Canvas(g_sMenuGraphPage, &g_sMenuTypePage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240 - 0 -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sGraphPower, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Power", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphSpeed, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Speed", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphAccel, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 115, 96, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Accel", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphTemp, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 113, 115, 96, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Temp", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphLight, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 214, 115, 96, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Light", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphBack, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 200, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Back To Home", 0, 0, 0, 0, 0);

// Settings Pages
Canvas(g_sSettingPage, &g_sSetTemp, 0, 0,
       &g_sKentec320x240x16_SSD2119, 10, 25, 300, (240 - 25 -10),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sSetAdd, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 200, 35, 100, 70,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "+", 0, 0, 0, 0, 0);

RectangularButton(g_sSetSub, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 200, 120, 100, 70,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "-", 0, 0, 0, 0, 0);

CircularButton(g_sSetMotorMode, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 150, 70, 35,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x0023A369, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Turn On", 0, 0, 0, 0, 0);

RectangularButton(g_sSetSave, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 200, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Confirm", 0, 0, 0, 0, 0);


// Graphing Page
Canvas(g_sGraphPage, &g_sMenuGraphPage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240 - 0 -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);
Canvas(g_sGraph, &g_sGraphPage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 20, 55, 280, 140,
       CANVAS_STYLE_FILL, 0x00314570, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sGraphActBack, &g_sGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 219, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, ClrWhite, ClrWhite,
                   g_psFontCmss18b, "Back", 0, 0, 0, 0, 0);


// Function Initialization
static char * getCurrentDateTime();
void DrawDateTime(tContext *);
void UserInterfaceDraw(UI_Params *, tContext *);
void UserInterfaceInit(uint32_t, tContext *, UI_Params *);

static void updateMenuOptions(UI_Params *);
static void DrawSetMenuScreen(tContext *, UI_Params *);
static void DrawGraphMenuScreen(tContext * sContext, UI_Params *);

static int16_t SetupSettingScreen(tContext *,UI_Params *);
static void SaveSettings(UI_Params *);
static void DrawSettingScreen(tContext *, UI_Params *);
static void GuiMotorClicked(UI_Params *);

static void DrawDataOnGraph(tContext *);
static void SetupGraphScreen(tContext *);
static void DrawGraphScreen(tContext *, UI_Params *);

static void DrawHomeScreen(tContext *, UI_Params *);
static uint8_t checkUiControls(UI_Params *, uint8_t);


// Global test variables
uint32_t counter;
extern uint32_t drawTime;

//*****************************************************************************
//
// The DMA control structure table.
//
//*****************************************************************************
#ifdef ewarm
#pragma data_alignment=1024
tDMAControlTable psDMAControlTable[64];
#elif defined(ccs)
#pragma DATA_ALIGN(psDMAControlTable, 1024)
tDMAControlTable psDMAControlTable[64];
#else
tDMAControlTable psDMAControlTable[64] __attribute__ ((aligned(1024)));
#endif

// Gets the current date and time
static char * getCurrentDateTime()
{
    static char t[30];
    struct tm * timeinfo;
    time_t t1 = time (NULL);
    timeinfo = localtime ( &t1 );
    timeinfo->tm_hour += 16;
    strcpy(t,asctime(timeinfo));
    return t;
}

// Draws the date, time and lux sensor results to the title bar
void DrawDateTime(tContext * sContext)
{
    if(drawTime)
    {
        counter +=1;
        if (counter%2 == 0){
            GrContextForegroundSet(sContext, 0x00FFC300);
            GrCircleFill(sContext,5, 5,10);
            GrLineDraw(sContext,15, 15, 20, 20);
            GrLineDraw(sContext,18, 10, 23, 13);
            GrLineDraw(sContext,19, 5,25,6);
        }else{
            GrContextForegroundSet(sContext, 0x00D8D4D5);
            GrCircleFill(sContext,5, 5,10);
            GrContextForegroundSet(sContext, 0x007584AD);
            GrLineDraw(sContext,15, 15, 20, 20);
            GrLineDraw(sContext,18, 10, 23, 13);
            GrLineDraw(sContext,19, 5,25,6);
        }
        GrContextBackgroundSet(sContext, 0x007584AD);
        GrContextForegroundSet(sContext, ClrWhite);
        GrContextFontSet(sContext, g_psFontCmss18b);
        GrStringDrawCentered(sContext, getCurrentDateTime(), -1, 160, 8, true);
        GrFlush(sContext);
        drawTime = 0;
    }
}

// Initialises the user interface
void UserInterfaceInit(uint32_t systemclock, tContext * sContext, UI_Params * params)
{

    Kentec320x240x16_SSD2119Init(systemclock);
    GrContextInit(sContext, &g_sKentec320x240x16_SSD2119);
    SysCtlDelay(10);


    params->screen = SCREEN_0;
    params->mode = 0;
    params->screen_option = SCREEN_0;
    params->data.motor_state = MOTOR_IDLE;
    initInterfaceButton();

    GrContextBackgroundSet(sContext, 0x007584AD);
    GrContextForegroundSet(sContext, ClrWhite);
    GrContextFontSet(sContext, g_psFontCmss18b);

    // New Main Screen
    WidgetAdd(WIDGET_ROOT, (tWidget *)&g_sMenuTypePage);
    WidgetAdd((tWidget *)&g_sMenuTypePage, (tWidget *)&g_sSetOption);
    WidgetAdd((tWidget *)&g_sMenuTypePage, (tWidget *)&g_sGraphOption);

    // Set menu
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetTemp);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetCurrent);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetMotor);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetAccel);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetBack);

    // Graph Menu
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphTemp);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphSpeed);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphPower);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphAccel);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphLight);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphBack);

    // Settings page
    WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetAdd);
    WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetSub);
    WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetSave);
   // WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetMotorMode);

    // Graph page
    WidgetAdd((tWidget *)&g_sGraphPage, (tWidget *) &g_sGraph);
    WidgetAdd((tWidget *)&g_sGraphPage, (tWidget *) &g_sGraphActBack);
}

// Visually updates the selection on each page
static void updateMenuOptions(UI_Params * param)
{
    tPushButtonWidget *prev;
    tPushButtonWidget *curr;
    switch(param->screen)
    {
        case SCREEN_0:
            switch(param->screen_option)
            {
                case 0:
                    prev = &g_sGraphOption;
                    curr = &g_sSetOption;
                    break;
                case 1:
                    curr = &g_sGraphOption;
                    prev = &g_sSetOption;
                    break;
            }
            break;
        case SCREEN_1:
            switch(param->screen_option)
            {
                case 0:
                    prev = &g_sSetBack;
                    curr = &g_sSetTemp;
                    break;
                case 1:
                    prev = &g_sSetTemp;
                    curr = &g_sSetMotor;
                    break;
                case 2:
                    prev = &g_sSetMotor;
                    curr = &g_sSetCurrent;
                    break;
                case 3:
                    prev = &g_sSetCurrent;
                    curr = &g_sSetAccel;
                    break;
                case 4:
                    prev = &g_sSetAccel;
                    curr = &g_sSetBack;
                    break;
            }
            break;
        case SCREEN_2:
            switch(param->screen_option)
            {
                case 0:
                    prev = &g_sGraphBack;
                    curr = &g_sGraphPower;
                    break;
                case 1:
                    prev = &g_sGraphPower;
                    curr = &g_sGraphSpeed;
                    break;
                case 2:
                    prev = &g_sGraphSpeed;
                    curr = &g_sGraphAccel;
                    break;
                case 3:
                    prev = &g_sGraphAccel;
                    curr = &g_sGraphTemp;
                    break;
                case 4:
                    prev = &g_sGraphTemp;
                    curr = &g_sGraphLight;
                    break;
                case 5:
                    prev = &g_sGraphLight;
                    curr = &g_sGraphBack;
                    break;
            }
            break;
        case SCREEN_3:
            switch(param->screen_option)
            {
                case 0:
                    prev = &g_sSetSave;
                    curr = &g_sSetAdd;
                    if (param->mode == 1){
                        PushButtonOutlineColorSet(&g_sSetMotorMode, 0x00AED1D6);
                        WidgetPaint((tWidget *) &g_sSetMotorMode);
                    }
                    break;
                case 1:
                    prev = &g_sSetAdd;
                    curr = &g_sSetSub;
                    break;
                case 2:
                    prev = &g_sSetSub;
                    curr = &g_sSetSave;
                    break;
                case 3:
                    prev = &g_sSetSave;
                    curr = &g_sSetMotorMode;
                    break;
            }
            break;
    }

    // Render the selection
    PushButtonOutlineColorSet(prev, 0x00AED1D6);
    PushButtonOutlineColorSet(curr, ClrWhite);
    WidgetPaint((tWidget *) prev);
    WidgetPaint((tWidget *) curr);
}

// Draws the setting menu
static void DrawSetMenuScreen(tContext * sContext, UI_Params * params)
{
    uint8_t but_press;
    WidgetPaint((tWidget *) &g_sMenuSetPage);
    updateMenuOptions(params);
    WidgetMessageQueueProcess();
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, SCREEN_1_OPTION);
        if(but_press)
        {
            if (params->screen_option == SCREEN_1_OPTION){
                params->screen_option = 0;
                params->screen = SCREEN_0;
            }
            else{
                params->screen = SCREEN_3;
                params->mode = params->screen_option;
                params->screen_option = SCREEN_0;
            }
            break;
        }
    }
}

// Draws the graphing menu
static void DrawGraphMenuScreen(tContext * sContext, UI_Params * params)
{
    uint8_t but_press;
    WidgetPaint((tWidget *) &g_sMenuGraphPage);
    updateMenuOptions(params);
    WidgetMessageQueueProcess();
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, SCREEN_2_OPTION);
        if(but_press)
        {
            if (params->screen_option == SCREEN_2_OPTION){
                params->screen_option = 1;
                params->screen = SCREEN_0;
            }
            else{
                params->screen = SCREEN_4;
                params->screen_option = 0;
            }
            break;
        }
    }
}

// Handles the user wanting to change motor state
static void GuiMotorClicked(UI_Params * params)
{
    if(params->data.motor_state){
        params->data.motor_state = 0;
        PushButtonFillColorSet(&g_sSetMotorMode, 0x0023A369);
        PushButtonTextSet(&g_sSetMotorMode, "Turn On");
    }else{
        params->data.motor_state = 1;
        PushButtonFillColorSet(&g_sSetMotorMode, 0x00912B24);
        PushButtonTextSet(&g_sSetMotorMode, "Turn Off");
    }
    WidgetPaint((tWidget *) &g_sSetMotorMode);
}

// Sets up the settings page
static int16_t SetupSettingScreen(tContext * sContext,UI_Params * params)
{

    WidgetPaint((tWidget *) &g_sSettingPage);
    WidgetMessageQueueProcess();
    int16_t measurement;
    char title[20];
    char units[20];
    if(params->mode == 0){
        measurement = 50;
        sprintf(units, "celsius\0");
        sprintf(title, "Temperature\0");
    }else if(params->mode == 1){
        measurement = 40;
        sprintf(units, "rpms\0");
        sprintf(title, "Speed\0");
    }else if(params->mode == 2){
        measurement = 60;
        sprintf(units, "amps\0");
        sprintf(title, "Current\0");
    }else{
        measurement = 70;
        sprintf(units, "m/s\0");
        sprintf(title, "Acceleration\0");
    }
    GrStringDraw(sContext, "Setting:", -1, 30, 40, true);
    GrStringDraw(sContext, title, -1, 30, 60, true);
    GrStringDraw(sContext, units, -1, 100, 150, 1);
    updateMenuOptions(params);
    return measurement;
}

// Saves the values set in the settings page
static void SaveSettings(UI_Params * params)
{
    params->screen_option = 0;
    params->mode = 0;
    params->screen = SCREEN_1;
}

// Draws the settings page
static void DrawSettingScreen(tContext * sContext, UI_Params * params)
{
    char meas[20];
    uint8_t but_press;
    int16_t measurement = SetupSettingScreen(sContext,params);
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, SCREEN_3_OPTION);
        if(but_press){
            if (params->screen_option == 0){
                if (measurement < 85)
                    measurement++;
            }
            else if(params->screen_option == 1){
                if (measurement > 10)
                    measurement--;

            }else if(params->screen_option == 2){
                SaveSettings(params);
                break;
            }else{
                GuiMotorClicked(params); //  clicked on motor start
            }
        }
        sprintf(meas, "%d \0",measurement);
        GrStringDraw(sContext, meas, -1, 60, 150, 1);
        WidgetMessageQueueProcess();
    }
}

// Graphs the chosen data on the map and scales accordingly
static void DrawDataOnGraph(tContext * sContext)
{
    // Define data
    uint8_t data[7] = {10,20,30,40,13,18,20};

    uint16_t sx = 20;
    uint16_t sy = 55;
    uint16_t w = 280;
    uint16_t h = 140;

    uint16_t max_y = 50;
    uint16_t max_x = 6; // number of seconds too plot (intervals)

    // Draw line values
    GrStringDraw(sContext, "6\0", -1, 290, 202, false);
    GrStringDraw(sContext, "50\0", -1, 18, 38, false);

    // Calculate y and x scale
    double yscale = h/max_y;
    double xscale = w/max_x;

    uint16_t x1,x2,y1,y2;

    // Draw onto graph
    int j;
    for (j = 0; j < 6; j++ ) {
        x1 = (j*xscale)+sx;
        y1 = (data[j]*yscale+sy);
        x2 = ((j+1)*xscale)+sx;
        y2 = (data[j+1]*yscale+sy);
        GrLineDraw(sContext,x1,y1,x2,y2);
    }

}

// Sets up the graphing screen
static void SetupGraphScreen(tContext * sContext)
{

    WidgetPaint((tWidget *) &g_sGraphPage);
    WidgetMessageQueueProcess();
    GrStringDraw(sContext, "Graphing: Power\0", -1, 100, 25, true);
    GrStringDraw(sContext, "time (s)\0", -1, 130, 202, false);
    GrLineDrawV(sContext, 10,45,200);
    GrLineDrawH(sContext, 10,305,200);
    GrLineDraw(sContext,10,45,8,50);
    GrLineDraw(sContext,10,45,12,50);
    GrLineDraw(sContext,305,200,303,198);
    GrLineDraw(sContext,305,200,303,202);
    // Axis Tick
    GrLineDraw(sContext,300,195,300,205);
    GrLineDraw(sContext,5,55,15,55);
}

// Draws the graphing screen
static void DrawGraphScreen(tContext * sContext, UI_Params * params)
{
    SetupGraphScreen(sContext);
    uint8_t button;
    while(1)
    {
        DrawDataOnGraph(sContext);
        button = OnButtonPress();
        if (button == BUTTON_SELECT){
            params->screen = SCREEN_2;
            params->screen_option = DEFAULT_SCREEN_OPTION;
            break;
        }
        WidgetMessageQueueProcess();
    }
}

// Draws the home screen
static void DrawHomeScreen(tContext *sContext, UI_Params *params)
{
    uint8_t but_press;
    WidgetPaint(WIDGET_ROOT);
    WidgetMessageQueueProcess();
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, SCREEN_0_OPTION);
        if(but_press){
            if (params->screen_option == 0){
                params->screen = SCREEN_1;
                params->screen_option = DEFAULT_SCREEN_OPTION;
            }else{
                params->screen = SCREEN_2;
                params->screen_option = DEFAULT_SCREEN_OPTION;
            }
            break;
        }
    }
}

// Handles the UI controls for navigating and interacting with the pages
static uint8_t checkUiControls(UI_Params *params, uint8_t screen_opt_num)
{
    uint8_t button = OnButtonPress();
    if(button == BUTTON_NONE){
        return 0;
    }else{
        if (button == BUTTON_SELECT)
        {
            return 1;
        }else{ // is select button
            if(params->screen_option < screen_opt_num)
            {
                params->screen_option += 1;
            }
            else if(params->screen_option == screen_opt_num)
            {
                if(params->mode != 1){
                    params->screen_option = 0;
                }else{
                    params->screen_option += 1;
                }
            }
            else if(params->screen_option > screen_opt_num)
            {
                params->screen_option = 0;
            }
            updateMenuOptions(params);
            WidgetMessageQueueProcess();
            return 0;
        }
    }
}

// Decides what pae to draw
void UserInterfaceDraw(UI_Params * params, tContext * sContext)
{
    switch(params->screen)
    {
        case SCREEN_0:
            DrawHomeScreen( sContext, params);
            break;
        case SCREEN_1:
            DrawSetMenuScreen(sContext, params);
            break;
        case SCREEN_2:
            DrawGraphMenuScreen(sContext, params);
            break;
        case SCREEN_3:
            DrawSettingScreen(sContext, params);
            break;
        case SCREEN_4:
            DrawGraphScreen(sContext, params);
            break;
    }
}
