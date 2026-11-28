// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// Adapted bodies: none
// 0x117dc80 ScaleformContext117dc80::SetTargetField
#include "ScaleformContext117dc80_117dc80.h"

// Updates the target pointer field while holding the object critical section.
void ScaleformContext117dc80::SetTargetField(void* value)
{
    ScopedLock117dc80 guard(lock);
    target->field748 = value;
}
