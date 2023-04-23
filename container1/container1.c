#include "../event.h"

void container1_Events(GameTracker*, StreamUnit*, GlobalData*);

void EventMain(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData)
{
    container1_Events(gameTracker, unit, globalData);
}

void container1_Events(GameTracker* gameTracker, StreamUnit* unit, GlobalData* globalData)
{
    if (globalData->versionNumber != 4103)
    {
        globalData->FONT_Print("wrong event version for container1\n");
        return;
    }
}