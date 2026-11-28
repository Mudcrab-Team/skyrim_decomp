// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x130780 CallableImpl130780::Copy
// Adapted bodies: none
#include "CallableImpl130780.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase130780* CallableImpl130780::Copy(void* a_where) const
{
    return new (a_where) CallableImpl130780(*this);
}
