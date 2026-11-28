// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0x9623d0 DirectionHandler::UpdateRepeat
#include "DirectionHandler_9623d0.h"

// Advances the repeat timer using a clamped linear blend between min and max repeat delays.
bool DirectionHandler::UpdateRepeat(float time)
{
    if (time > nextRepeatTime)
    {
        float ratio = static_cast<float>(repeatCount) / static_cast<float>(maxRepeats);
        if (ratio > 1.0f)
        {
            ratio = 1.0f;
        }
        nextRepeatTime += (maxDelay - minDelay) * ratio + minDelay;
        return true;
    }

    return false;
}
