// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x133430 CallableImpl133430::Copy
// Adapted bodies: none
#include "CallableImpl133430.h"

// Placement-copies the callable implementation into caller-supplied storage.
CallableBase133430* CallableImpl133430::Copy(void* a_where) const
{
    return new (a_where) CallableImpl133430(*this);
}
