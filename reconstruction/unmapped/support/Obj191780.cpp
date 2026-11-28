// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x191780 Obj191780::Obj191780
// Adapted bodies: none.
#include "Obj191780.h"

// Initializes the handle to invalid, clears the trailing flag, and sets six float bounds to sentinel max.
Obj191780::Obj191780() :
    handle()
{
    const float kSentinelMax = 3.4028135280045828e+38f;
    unk1C = 0;
    unk04 = kSentinelMax;
    unk08 = kSentinelMax;
    unk0C = kSentinelMax;
    unk10 = kSentinelMax;
    unk14 = kSentinelMax;
    unk18 = kSentinelMax;
}
