// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x144aa0 CallableImpl144aa0::Copy
// Adapted bodies: none
#include "CallableImpl144aa0.h"

#include <new>

// Placement-copies the callable state into dst.
CallableBase144aa0* CallableImpl144aa0::Copy(void* dst) const
{
    return ::new (dst) CallableImpl144aa0(*this);
}
