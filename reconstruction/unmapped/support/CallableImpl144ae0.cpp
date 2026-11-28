// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x144ae0 CallableImpl144ae0::Move
// Adapted bodies: none
#include "CallableImpl144ae0.h"

#include <new>
#include <utility>

// Placement-moves the callable state into dst.
CallableBase144ae0* CallableImpl144ae0::Move(void* dst)
{
    return ::new (dst) CallableImpl144ae0(std::move(*this));
}
