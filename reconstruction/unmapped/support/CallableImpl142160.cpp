// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x142160 CallableImpl142160::Move
// Adapted bodies: none
#include "CallableImpl142160.h"

#include <new>
#include <utility>

// Placement-moves the callable state into dst.
CallableBase142160* CallableImpl142160::Move(void* dst)
{
    return ::new (dst) CallableImpl142160(std::move(*this));
}
