#include "../event.h"

void cn1_Events(GameTracker*, StreamUnit*, GlobalData*);

int cn1_event00(GameTracker*, StreamUnit*, GlobalData*, int*);
int cn1_event99(GameTracker*, StreamUnit*, GlobalData*, int*);

int cn1_event00_block0(GameTracker*, StreamUnit*, GlobalData*, int*);
int cn1_event00_block1(GameTracker*, StreamUnit*, GlobalData*, int*);

int cn1_event99_block0(GameTracker*, StreamUnit*, GlobalData*, int*);

void EventMain(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData)
{
    cn1_Events(gameTracker, unit, globalData);
}

void cn1_Events(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData)
{
    if (globalData->versionNumber != 4103)
    {
        globalData->FONT_Print("wrong event version for cn1\n");
        return;
    }

    cn1_event00(gameTracker, unit, globalData, event00);
    cn1_event99(gameTracker, unit, globalData, event99);
}

int cn1_event00(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    cn1_event00_block0(gameTracker, unit, globalData, arguments);
    cn1_event00_block1(gameTracker, unit, globalData, arguments);

    return 1;
}

int cn1_event99(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    cn1_event99_block0(gameTracker, unit, globalData, arguments);

    return 1;
}

int cn1_event00_block0(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (gameTracker->playerInstance->currentStreamUnitID == 141)
    {
        globalData->EVENT_DisplayStringXY("cn1: Los Alamos, Ghost Town", 1, 100, 6);
    }

    return 1;
}

int cn1_event00_block1(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    return 1;
}

int cn1_event99_block0(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if ((gameTracker->gameFlags & 0x20) != 0)
    {
        arguments[1] = 1;
        arguments[2] = 0;
        arguments[3] = 0;
    }

    if (arguments[1])
    {
        if ((gameTracker->debugFlags2 & 0x100) != 0)
        {
            globalData->FONT_Print("cn1_event99_block0_line %d\n", arguments[3]);
        }

        if (arguments[2] > 0.0)
        {
            arguments[2] = arguments[2] - gameTracker->timeMult;
        }

        if (arguments[3] != 406)
        {
            globalData->GAMELOOP_SetScreenWipe(10, 100, 1);
            globalData->EVENT_StopAllCine();

            arguments[2] = (int)100.0;
            arguments[3] = 406;
        }
        
        if (arguments[2] <= 0.0)
        {
            globalData->GAMELOOP_SetScreenWipe(10, 0, 1);
            arguments[1] = 0;
        }
    }

    return 1;
}