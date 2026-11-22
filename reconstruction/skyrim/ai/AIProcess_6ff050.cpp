// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x6ff050 AIProcess::GetHeadtrackTarget
// Adapted bodies: none
#include "AIProcess_6ff050.h"

ObjectRefHandle AIProcess::GetHeadtrackTarget() const
{
    ObjectRefHandle result = g_nullHandle;
    if (high) {
        for (int i = 5; i >= 0 && result.value == g_nullHandle.value; --i) {
            if (high->headTracked[i]) {
                result = high->headTrackTarget[i];
            }
        }
    }
    return result;
}
