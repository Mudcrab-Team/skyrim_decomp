// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x142120 CallableImpl142120::Copy
// Adapted bodies: none
#include "CallableImpl142120.h"

#include <new>

// Placement-copies the callable state into dst.
CallableBase142120* CallableImpl142120::Copy(void* dst) const
{
    return ::new (dst) CallableImpl142120(*this);
}
