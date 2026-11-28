// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x1307f0 CallableImpl1307f0::Copy
// Adapted bodies: none
#include "CallableImpl1307f0.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase1307f0* CallableImpl1307f0::Copy(void* a_where) const
{
    return new (a_where) CallableImpl1307f0(*this);
}
