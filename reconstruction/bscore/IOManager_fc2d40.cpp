// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xfc2d40 IOManager::sub_140D29580
#include "IOManager_fc2d40.h"

// Removes the task from the manager and decrements its bucket and total counters on success.
bool IOManager::sub_140D29580(IOTaskEntry* entry)
{
    std::uint32_t index = GetTaskIndex(entry->task);
    if (RemoveTask(entry->task))
    {
        taskCounts[index].Decrement();
        totalTaskCount.Decrement();
        return true;
    }
    return false;
}
