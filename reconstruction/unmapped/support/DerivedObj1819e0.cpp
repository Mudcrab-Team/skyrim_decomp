// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1819e0 DerivedObj1819e0::DerivedObj1819e0
// Adapted bodies: none.
#include "DerivedObj1819e0.h"

// Initializes the object with default invalid handle, sentinel 16-bit field, and cleared flags.
DerivedObj1819e0::DerivedObj1819e0() :
    unk10(0),
    handle()
{
    unk1C = 0xFFFF;
    flag0 = 0;
    flag1 = 0;
    flag2 = 0;
}
