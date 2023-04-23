#include "../event.h"

int winston_unit_position = 0;

int event00[50];

Proc gProcList[14];
int gNumProcs = 0;

void ma10_Events(GameTracker*, StreamUnit*, GlobalData*);

int ma10_event00(GameTracker*, StreamUnit*, GlobalData*, int*);
int ma10_event01(GameTracker*, StreamUnit*, GlobalData*, int*);
int ma10_event70(GameTracker*, StreamUnit*, GlobalData*, int*);

int ma10_event00_block1(GameTracker*, StreamUnit*, GlobalData*, int*);

int ma10_proc_winston_placement(GameTracker*, StreamUnit*, GlobalData*, int*);

int ma10_proc_winston_placement_block1(GameTracker*, StreamUnit*, GlobalData*, int*);
int ma10_proc_winston_placement_block2(GameTracker*, StreamUnit*, GlobalData*, int*);
int ma10_proc_winston_placement_block3(GameTracker*, StreamUnit*, GlobalData*, int*);
int ma10_proc_winston_placement_block4(GameTracker*, StreamUnit*, GlobalData*, int*);

int ma10_proc_winston_animator(GameTracker*, StreamUnit*, GlobalData*, int*);

void EventMain(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData)
{
    ma10_Events(gameTracker, unit, globalData);
}

void ma10_Events(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData)
{
    if (globalData->versionNumber != 4103)
    {
        globalData->FONT_Print("wrong event version for ma10\n");
        return;
    }

    ma10_event00(gameTracker, unit, globalData, event00);
    ma10_event01(gameTracker, unit, globalData, event01);
    ma10_event70(gameTracker, unit, globalData, event70);

    for (int i = 0; i < gNumProcs; i++)
    {

    }
}

int ma10_event00(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (gameTracker->playerInstance->currentStreamUnitID == 123)
    {
        globalData->EVENT_DisplayStringXY("MA10: Courtyard", 1, 100, 6);
    }

    ma10_event00_block1(gameTracker, unit, globalData, arguments);

    return 1;
}

int ma10_event00_block1(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if ((gameTracker->debugFlags2 & 0x100) != 0)
    {
        globalData->FONT_Print("ma10_event00_block1_line %d\n", 86);
    }

    ma10_proc_winston_placement(gameTracker, unit, globalData, &arguments[12]);
}

int ma10_proc_winston_placement(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (arguments[1])
    {
        winston_unit_position = globalData->EVENT_Random(1, 17);
        arguments[1] = 0;
    }

    return ma10_proc_winston_placement_block1(gameTracker, unit, globalData, arguments)
        && ma10_proc_winston_placement_block2(gameTracker, unit, globalData, arguments)
        && ma10_proc_winston_placement_block3(gameTracker, unit, globalData, arguments)
        && ma10_proc_winston_placement_block4(gameTracker, unit, globalData, arguments);
}

int ma10_proc_winston_placement_block1(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (!arguments[2])
    {
        if (winston_unit_position == 1)
        {
            arguments[2] = 1;
            arguments[12] = 0;
        }

        if (!arguments[2])
        {
            return 1;
        }
    }

    if ((gameTracker->debugFlags2 & 0x100) != 0)
    {
        globalData->FONT_Print("ma10_proc_winston_placement_block1_line %d\n", arguments[12]);
    }

    Intro* intro = globalData->INSTANCE_FindIntro(123, 4823);
    globalData->INSTANCE_EventIntroduceInstance(intro);

    if (arguments[3])
    {
        int index = gNumProcs;

        gProcList[index].proc = ma10_proc_winston_animator;
        gProcList[index].arg = &arguments[12];
        gNumProcs++;
    }

    arguments[0] = 0;
    arguments[1] = 0;
    arguments[2] = 0;
    arguments[13] = 0;
    arguments[24] = 0;
    arguments[35] = 0;

    return 0;
}

int ma10_proc_winston_placement_block2(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (!arguments[13])
    {
        if (winston_unit_position == 5)
        {
            arguments[13] = 1;
            arguments[23] = 0;
        }

        if (!arguments[13])
        {
            return 1;
        }
    }

    if ((gameTracker->debugFlags2 & 0x100) != 0)
    {
        globalData->FONT_Print("ma10_proc_winston_placement_block2_line %d\n", arguments[23]);
    }

    Intro* intro = globalData->INSTANCE_FindIntro(123, 4824);
    globalData->INSTANCE_EventIntroduceInstance(intro);

    if (arguments[14])
    {
        int index = gNumProcs;

        gProcList[index].proc = ma10_proc_winston_animator;
        gProcList[index].arg = &arguments[12];
        gNumProcs++;
    }

    arguments[0] = 0;
    arguments[1] = 0;
    arguments[2] = 0;
    arguments[13] = 0;
    arguments[24] = 0;
    arguments[35] = 0;

    return 0;
}

int ma10_proc_winston_placement_block3(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (!arguments[24])
    {
        if (winston_unit_position == 10)
        {
            arguments[24] = 1;
            arguments[34] = 0;
        }

        if (!arguments[34])
        {
            return 1;
        }
    }

    if ((gameTracker->debugFlags2 & 0x100) != 0)
    {
        globalData->FONT_Print("ma10_proc_winston_placement_block3_line %d\n", arguments[34]);
    }

    Intro* intro = globalData->INSTANCE_FindIntro(123, 4825);
    globalData->INSTANCE_EventIntroduceInstance(intro);

    if (arguments[25])
    {
        int index = gNumProcs;

        gProcList[index].proc = ma10_proc_winston_animator;
        gProcList[index].arg = &arguments[12];
        gNumProcs++;
    }

    arguments[0] = 0;
    arguments[1] = 0;
    arguments[2] = 0;
    arguments[13] = 0;
    arguments[24] = 0;
    arguments[35] = 0;

    return 0;
}

int ma10_proc_winston_placement_block4(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData, int* arguments)
{
    if (!arguments[35])
    {
        if (winston_unit_position == 15)
        {
            arguments[35] = 1;
            arguments[45] = 0;
        }

        if (!arguments[35])
        {
            return 1;
        }
    }

    if ((gameTracker->debugFlags2 & 0x100) != 0)
    {
        globalData->FONT_Print("ma10_proc_winston_placement_block4_line %d\n", arguments[12]);
    }

    Intro* intro = globalData->INSTANCE_FindIntro(123, 4826);
    globalData->INSTANCE_EventIntroduceInstance(intro);

    if (arguments[36])
    {
        int index = gNumProcs;

        gProcList[index].proc = ma10_proc_winston_animator;
        gProcList[index].arg = &arguments[12];
        gNumProcs++;
    }

    arguments[0] = 0;
    arguments[1] = 0;
    arguments[2] = 0;
    arguments[13] = 0;
    arguments[24] = 0;
    arguments[35] = 0;

    return 0;
}