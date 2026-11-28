// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x194c20 QueuedTempEffect::sub_140146F20
#include "QueuedTempEffect_194c20.h"

// Finishes the queued temporary effect unless the task is already in state 6.
bool QueuedTempEffect::sub_140146F20()
{
    if (state == 6)
    {
        return false;
    }
    target->FinishEffect();
    return true;
}
