// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x130740 CallableImpl130740::Copy
// Adapted bodies: none
#include "CallableImpl130740.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase130740* CallableImpl130740::Copy(void* a_where) const
{
    return new (a_where) CallableImpl130740(*this);
}
