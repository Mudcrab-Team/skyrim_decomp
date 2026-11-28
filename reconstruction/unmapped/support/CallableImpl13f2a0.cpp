// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13f2a0 CallableImpl13f2a0::Copy
// Adapted bodies: none
#include "CallableImpl13f2a0.h"

#include <new>

// Placement-copies the callable state into dst.
CallableBase13f2a0* CallableImpl13f2a0::Copy(void* dst) const
{
    return ::new (dst) CallableImpl13f2a0(*this);
}
