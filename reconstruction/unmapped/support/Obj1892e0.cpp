// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1892e0 Obj1892e0::IsNotEqual
// Adapted bodies: none.
#include "Obj1892e0.h"

#include <cstring>

// Compares the 20-byte payload at offset 0x10 against another instance for inequality.
bool Obj1892e0::IsNotEqual(const Obj1892e0* a_other) const
{
    return std::memcmp(&payload, &a_other->payload, 20) != 0;
}
