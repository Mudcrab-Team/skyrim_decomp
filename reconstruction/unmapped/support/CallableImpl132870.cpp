// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x132870 CallableImpl132870::Copy
// Adapted bodies: none
#include "CallableImpl132870.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase132870* CallableImpl132870::Copy(void* a_where) const
{
    return new (a_where) CallableImpl132870(*this);
}
