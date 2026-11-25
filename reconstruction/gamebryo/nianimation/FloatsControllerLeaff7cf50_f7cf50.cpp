// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf7cf50 FloatsControllerLeaff7cf50::IsEqual
#include "FloatsControllerLeaff7cf50_f7cf50.h"

bool FloatsControllerLeaff7cf50::IsEqual(ControllerObjectf7cf50* other)
{
    if (FloatsControllerBasef7cf50::IsEqual(other) &&
        index == static_cast<FloatsControllerLeaff7cf50*>(other)->index) {
        return true;
    }
    return false;
}
