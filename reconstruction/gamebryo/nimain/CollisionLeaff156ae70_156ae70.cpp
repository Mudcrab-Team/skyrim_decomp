// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x156ae70 CollisionLeaff156ae70::IsEqual
#include "CollisionLeaff156ae70_156ae70.h"

bool CollisionLeaff156ae70::IsEqual(CollisionBase* other)
{
    if (!CollisionBase::IsEqual(other)) {
        return false;
    }
    if (scene && !other) {
        return false;
    }
    if (!scene && other) {
        return false;
    }
    return true;
}
