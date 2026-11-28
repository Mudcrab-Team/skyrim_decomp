// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x130830 CallableImpl130830::Copy
// Adapted bodies: none
#include "CallableImpl130830.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase130830* CallableImpl130830::Copy(void* a_where) const
{
    return new (a_where) CallableImpl130830(*this);
}
