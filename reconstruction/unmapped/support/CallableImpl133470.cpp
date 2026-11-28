// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x133470 CallableImpl133470::Copy
// Adapted bodies: none
#include "CallableImpl133470.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase133470* CallableImpl133470::Copy(void* a_where) const
{
    return new (a_where) CallableImpl133470(*this);
}
