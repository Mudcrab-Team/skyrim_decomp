// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13f2e0 CallableImpl13f2e0::Move
// Adapted bodies: none
#include "CallableImpl13f2e0.h"

#include <new>
#include <utility>

// Placement-moves the callable state into dst.
CallableBase13f2e0* CallableImpl13f2e0::Move(void* dst)
{
    return ::new (dst) CallableImpl13f2e0(std::move(*this));
}
